/*
ssc (static site checker)
Copyright (c) 2020,2021 Dylan Harris
https://dylanharris.org/

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public Licence as published by
the Free Software Foundation, either version 3 of the Licence, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public Licence for more details.

You should have received a copy of the GNU General Public
Licence along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include "main/standard.h"
#include "parser/html_version.h"
#include "utility/common.h"
#include "main/context.h"
#include "type/type.h"

const char* doctype = "DOCTYPE";
const ::std::size_t doctype_len = 7;
const char* docdot = "<!DOCTYPE ...>";

html_version::html_version (const boost::gregorian::date& d, const uint64_t flags, const uint64_t extensions)
        :   version (0, 0, flags | HV_WHATWG), ext_ (extensions)
{   if (d.is_not_a_date ()) { reset (html_1); return; }
    int y = d.year ();
    if ((y > 100) && (y < 2000)) { reset (html_1); return; }
    int m = d.month ();
    if (y > 2000) y -= 2000;
    if ((y < HTML_5_EARLIEST_YEAR) || ((y == HTML_5_EARLIEST_YEAR) && (m < HTML_5_EARLIEST_MONTH)))
    {   y = HTML_5_EARLIEST_YEAR; m = HTML_5_EARLIEST_MONTH; }
    else if ((y > HTML_LATEST_YEAR) || ((y == HTML_LATEST_YEAR) && (m > HTML_LATEST_MONTH)))
    {   y = HTML_LATEST_YEAR; m = HTML_LATEST_MONTH; }
    DBG_ASSERT ((m > 0) && (m < 13));
    set_mjr (static_cast <unsigned char> (y), static_cast <unsigned char> (m * 16));
    if (no_ext (MATH_MASK))
        if (mjr () <= HTML_2010) set_ext (HE_MATH_1);
        if (mjr () <= HTML_2019) set_ext (HE_MATH_2);
        else set_ext (HE_MATH_4);
    if (no_ext (SVG_MASK))
        if (*this >= html_5_3) set_ext (HE_SVG_20);
        else if (mjr () > HTML_2008) set_ext (HE_SVG_12_TINY);
        else set_ext (HE_SVG_11); }

void html_version::init (const unsigned char mjr)
{   switch (mjr)
    {   case 0 :
            reset (html_tags); break;
        case 1 :
            reset (html_1); break;
        case 2 :
            reset (html_2); break;
        case 3 :
            reset (html_3_2); break;
        case 4 :
            reset (html_4_1); break;
        case 5 :
            reset (html_current); break;
        default :
            DBG_ASSERT (false); reset (html_current); break; } }

::std::string minor_to_date (const html_version& v)
{   DBG_ASSERT (v.is_5 ());
    if (v == html_5_0) return "5.0";
    if (v == html_5_1) return "5.1";
    if (v == html_5_2) return "5.2";
    if (v == html_5_3) return "5.3";
    ::std::string res ("5/20");
    if (v.mjr () < 10)
    {   res += "0";
        res += static_cast <char> (v.mjr () + '0'); }
    else res += ::boost::lexical_cast < ::std::string > (static_cast < int > (v.mjr ()));
    int mon = v.mnr () / 16;
    if (mon <= 9)
    {   res += "0";
        res += static_cast <char> (mon + '0'); }
    else res += ::boost::lexical_cast < ::std::string > (mon);
    int day = v.mnr () % 16;
    day *= 2;
    day += 1;
    if (day <= 9)
    {   res += "0";
        res += static_cast <char> (day + '0'); }
    else res += ::boost::lexical_cast < ::std::string > (day);
    return res; }

::std::string html_version::name () const
{   ::std::ostringstream res;
    if (known () && xhtml ())
    {   res << "XHTML";
        switch (mnr ())
        {   case 2 : res << "1.0"; break;
            case 3 : res << "1.1"; break;
            case 4 : res << "2.0"; break;
            default : res << "5"; } }
    else
    {   res << "HTML";
        if (known ())
            switch (mjr ())
            {   case 0 :
                    if (mnr () == 1) res << "Tags";
                    break;
                case 1 :
                    if (mnr () == 0) res << "1";
                    else if (mnr () == 1) res << "+";
                    break;
                case 2 :
                    res << "2";
                    if (level () > 0) res << "/" << level ();
                    break;
                case 3 :
                    res << "3." << static_cast <char> (mnr () + '0');
                    break;
                case 4 :
                    res << "4.0";
                    if (mnr () == 1) res << "1";
                    break;
                default:
                    res << minor_to_date (*this);
                    break; } }
    return res.str (); }

::std::string html_version::report () const
{   ::std::ostringstream res;
    res << name ();
    if (any_level ()) res << "." << level ();
    if (strict ()) res << "/strict";
    if (frameset ()) res << "/frameset";
    if (transitional ()) res << "/transitional";
    if (has_svg ()) res << "/SVG-" << type_master < t_svg_version > :: name (svg_version ());
    if (has_math ()) res << "/MathML-" << math_version ();
    if (has_xlink ()) res << "/xLink"; // << xlink ();
    if (has_rdf ()) res << "/rdf"; // << rdf ();
    if (chrome ()) res << "/Chrome";
    if (ie ()) res << "/IE";
    if (mozilla ()) res << "/Mozilla";
    if (netscape ()) res << "/Netscape";
    if (opera ()) res << "/Opera";
    if (safari ()) res << "/Safari";
    if (w3 ()) res << "/W3";
    if (webcomponents ()) res << "/WebComponents";
    if (whatwg ()) res << "/WhatWG";
    if (experimental ()) res << "/Experimental";
    if (bespoke ()) res << "/obscure";
    if (any_flags (HV_DEPRECATED_MASK)) res << "/deprecated";  // not the deprecated function here
    return res.str (); }

bool html_version::note_parsed_version (nitpick& nits, const e_nit n, const html_version& got, const ::std::string& gen)
{   if (is_not (got))
    {   if (got > *this)
        {   bool minor = false;
            switch (this -> mjr ())
            {   case 2 :
                    minor = ((*this == html_2) && ((got == html_2_level_1) || (got == html_2_level_2)));
                    break;
                case 4 :
                    minor = (((*this == xhtml_1_0) && (got == xhtml_1_1)) || ((*this == html_4_0) && (got == html_4_1)));
                    break;
                case 5 :
                    minor = (got.mjr () == this -> mjr ());
                    break;
                default : break; }
            if (minor) nits.pick (nit_html_contradictory, es_comment, ec_parser, report (), " changed to ", got.report ());
            else nits.pick (nit_html_contradictory, es_warning, ec_parser, report (), " changed to ", got.report ());
            reset (got);
            return true; }
        if (got.has_svg ())
            if (! has_svg () || (got.svg_version () >= svg_version ()))
            {   nits.pick (nit_svg, es_comment, ec_parser, "SVG recognised");
                math_version (got.math_version ());
                return true; }
        if (got.has_math ())
            if (! has_math ())
            {   nits.pick (nit_svg, es_comment, ec_parser, "MathML recognised");
                svg_version (got.svg_version ());
                return true; }
        nits.pick (nit_html_contradictory, es_warning, ec_parser, "contradictory ", gen, " statement encountered");
        return true; }
    if (unknown ())
    {   nits.pick (n, es_comment, ec_parser, gen, " recognised");
        reset (got); }
    return true; }

bool html_version::invalid_addendum (const html_version& v) const
{   if (microdata ())
        if (context.microdata ()) return false;
        else return v.w3 ();
    if (rdf ())
        if (context.rdf ()) return false;
        else return (v != xhtml_2);
    return (frameset () && ! v.frameset ()); }

bool html_version::parse_doctype (nitpick& nits, const::std::string& content)
{   nits.set_context (0, trim_the_lot_off (content));
    if (! compare_no_case (doctype, content.substr (0, doctype_len)))
    {   nits.pick (nit_html_unknown_sgml, es_error, ec_parser, content.substr (0, doctype_len), " is not understood by " PROG);
        return true; }
    bool found_html = false;
    bool found_public = false;
    bool found_system = false;
    bool found_unknown = false;
    bool sq_bra_ket = false;
    ::std::string::size_type pos = doctype_len;
    ::std::string wtf;
    vstr_t keywords = split_quoted_by_space (trim_the_lot_off (content.substr (pos)));
    if (keywords.empty ())
    {   nits.pick (nit_html_unrecognised, es_error, ec_parser, "Document type not specified. This is not an HTML file. Abandoning verification");
        return false; }
    for (auto s : keywords)
        if (! s.empty ())  // should never happen, but ...
        {   if (sq_bra_ket)
            {   if (s != "]") continue;  // broken by nesting, if it's permitted
                sq_bra_ket = false; }
            if (s.at (0) == '"') s = s.substr (1);  // crude way to remove excess "
            pos = s.length ();
            if (pos == 0) continue;
            if (s.at (pos - 1) == '"') s = s.substr (0, pos - 1);
            e_sgml d = symbol < html_version, e_sgml > :: find (html_0, s); // crude way to handle case
            if (d == doc_unknown) d = symbol < html_version, e_sgml > :: find (html_0, ::boost::algorithm::to_lower_copy (s));
            switch (d)
            {   case doc_unknown : found_unknown = true; wtf = s; break;
                case doc_html : found_html = true; break;
                case doc_public: found_public = true; break;
                case doc_system: found_system = true; break;
                case doc_context :
                    nits.pick (nit_html_unrecognised, es_info, ec_parser, "bespoke SGML specification encountered; am pretending it's HTML 5");
                    note_parsed_version (nits, nit_html_5_0, html_5_0, "HTML 5");
                    break;
                case doc_htmlplus :
                    if (note_parsed_version (nits, nit_html_plus, html_plus, "HTML+"))
                        found_html = true;
                    break;
                case doc_math :
                case doc_svg :
                case doc_rdf :
                    break;
                case doc_math1 :
                    if (note_parsed_version (nits, nit_math, html_4_0, "HTML 4.0 with MathML 1"))
                    {   set_ext (HE_MATH_1); found_html = true; }
                    break;
                case doc_math2 :
                    if (note_parsed_version (nits, nit_math, xhtml_1_0, "XHTML 1.0 with MathML 2"))
                    {   set_ext (HE_MATH_2); found_html = true; }
                    break;
                case doc_math3 :
                    if (note_parsed_version (nits, nit_math, html_5_0, "HTML 5.0 with MathML 3"))
                    {   set_ext (HE_MATH_3); found_html = true; }
                    break;
                case doc_math4 :
                    if (note_parsed_version (nits, nit_math, html_apr21, "Living Standard (April 2021) with MathML 4"))
                    {   set_ext (HE_MATH_4); found_html = true; }
                    break;
                case doc_svg1 :
                    if (note_parsed_version (nits, nit_svg, xhtml_svg_1_0, "HTML 4.00 with SVG 1.0"))
                    {   svg_version (sv_1_0); found_html = true; }
                    break;
                case doc_svg11 :
                    if (note_parsed_version (nits, nit_svg, xhtml_svg_1_1, "XHTML 1.1 with SVG 1.1"))
                    {   svg_version (sv_1_1); found_html = true; }
                    break;
                case doc_svg2 :
                    if (note_parsed_version (nits, nit_svg, html_svg_2_0, "Living Standard (October 2018) with SVG 2.0"))
                    {   svg_version (sv_2_0); found_html = true; }
                    break;
                case doc_compound :
                    if (note_parsed_version (nits, nit_math, html_version (HTML_5_0, 0, HE_SVG_10 | HE_MATH_1), "HTML 5.0 with SVG 1.0 & MathML 1"))
                    {   set_ext (HE_MATH_1); svg_version (sv_1_0); found_html = true; }
                    break;
                case doc_xhtml10_basic :
                    if (note_parsed_version (nits, nit_xhtml_1_0, xhtml_1_0, "XHTML 1.0 Basic")) set_flags (HV_BASIC);
                    break;
                case doc_xhtml10_strict_superseded :
                    nits.pick (nit_xhtml_superseded, ed_x1, "W3C Recommendation 26 January 2000, revised 1 August 2002", es_warning, ec_parser, "that strict XHTML 1.0 declaration was withdrawn before XHTML 1.0 was published");
                    // drop thru'
                case doc_xhtml10_strict :
                    if (note_parsed_version (nits, nit_xhtml_1_0, xhtml_1_0, "XHTML 1.0 Strict")) set_flags (HV_STRICT);
                    break;
                case doc_xhtml10_loose_superseded :
                    nits.pick (nit_xhtml_superseded, ed_x1, "W3C Recommendation 26 January 2000, revised 1 August 2002", es_warning, ec_parser, "that transitional XHTML 1.0 declaration was withdrawn before XHTML 1.0 was published");
                    // drop thru'
                case doc_xhtml10_loose :
                    if (note_parsed_version (nits, nit_xhtml_1_0, xhtml_1_0, "XHTML 1.0 Transitional")) set_flags (HV_TRANSITIONAL);
                    break;
                case doc_xhtml10_frameset_superseded :
                    nits.pick (nit_xhtml_superseded, ed_x1, "W3C Recommendation 26 January 2000, revised 1 August 2002", es_warning, ec_parser, "that XHTML 1.0 frameset declaration was withdrawn before XHTML 1.0 was published");
                    // drop thru'
                case doc_xhtml10_frameset :
                    if (note_parsed_version (nits, nit_xhtml_1_0, xhtml_1_0, "XHTML 1.0 Frameset")) set_flags (HV_FRAMESET);
                    break;
                case doc_xhtml10_mobile :
                    if (note_parsed_version (nits, nit_xhtml_1_0, xhtml_1_0, "XHTML 1.0 Mobile")) set_flags (HV_BASIC);
                    break;
                case doc_xhtml11 :
                    note_parsed_version (nits, nit_xhtml_1_1, xhtml_1_1, "XHTML 1.1");
                    break;
                case doc_xhtml2 :
                    note_parsed_version (nits, nit_xhtml_2_0, xhtml_2, "XHTML 2.0");
                    break;
                case doc_jan05 :
                    nits.pick (hit_draft_html_5, ed_jan05, "", es_warning, ec_parser, PROG " cannot properly process pre-draft HTML 5");
                    note_parsed_version (nits, hit_draft_html_5, html_jan05, "Web Apps Jan 2005");
                    break;
                case doc_html5 :
                    note_parsed_version (nits, nit_html_5_0, html_5_0, "HTML 5");
                    break;
                case doc_html400_strict :
                    if (note_parsed_version (nits, nit_html_4_00s, html_4_0, "HTML 4.00 Strict")) set_flags (HV_STRICT);
                    break;
                case doc_html400_loose :
                    note_parsed_version (nits, nit_html_4_00, html_4_0, "HTML 4.00");
                    break;
                case doc_html400_frameset :
                    if (note_parsed_version (nits, nit_html_4_00f, html_4_0, "HTML 4.00 Frameset")) set_flags (HV_FRAMESET);
                    break;
                case doc_latin :
                case doc_special :
                case doc_symbols :
                    break;
                case doc_html401_strict_superseded :
                    nits.pick (nit_html_superseded, ed_41, "21 Document Type Definition", es_warning, ec_parser, "that strict HTML .dtd was withdrawn");
                    // drop thru'
                case doc_html401_strict :
                    if (note_parsed_version (nits, nit_html_4_01s, html_4_1, "HTML 4.01 Strict")) set_flags (HV_STRICT);
                    break;
                case doc_html401_loose_superseded :
                    nits.pick (nit_html_superseded, ed_41, "21 Document Type Definition", es_warning, ec_parser, "that transitional HTML .dtd was withdrawn");
                    // drop thru'
                case doc_html401_loose :
                    if (note_parsed_version (nits, nit_html_4_01, html_4_1, "HTML 4.01 Transitional")) set_flags (HV_TRANSITIONAL);
                    break;
                case doc_html401_frameset_superseded :
                    nits.pick (nit_html_superseded, ed_41, "21 Document Type Definition", es_warning, ec_parser, "that HTML frameset .dtd was withdrawn");
                    // drop thru'
                case doc_html401_frameset :
                    if (note_parsed_version (nits, nit_html_4_01f, html_4_1, "HTML 4.01 Frameset")) set_flags (HV_FRAMESET);
                    break;
                case doc_html30 :
                    note_parsed_version (nits, nit_html_3_0, html_3_0, "HTML 3.0");
                    break;
                case doc_html32 :
                    note_parsed_version (nits, nit_html_3_2, html_3_2, "HTML 3.2");
                    break;
                case doc_html20 :
                    note_parsed_version (nits, nit_html_2_0, html_2, "HTML 2.0");
                    break;
                case doc_html20_strict :
                    if (note_parsed_version (nits, nit_html_2_0s, html_2, "HTML 2.0 Strict")) set_flags (HV_STRICT);
                    break;
                case doc_html20_int :
                    if (! context.rfc_2070 ())
                    {   nits.pick (nit_rfc_2070, es_error, ec_parser, "HTML 2.0 International (RFC 2070), which is disabled: abandoning verification");
                        return false; }
                    if (note_parsed_version (nits, nit_html_2_0i, html_2, "HTML 2.0 International")) set_flags (HV_INT);
                    break;
                case doc_html21 :
                    if (note_parsed_version (nits, nit_html_2_0l1, html_2_level_1, "HTML 2.0 Level 1")) set_flags (HV_LEVEL1);
                    break;
                case doc_html21_strict :
                    if (note_parsed_version (nits, nit_html_2_0l1s, html_2, "HTML 2.0 Level 1 Strict")) set_flags (HV_STRICT | HV_LEVEL1);
                    break;
                case doc_html22 :
                    if (note_parsed_version (nits, nit_html_2_0l2, html_2_level_2, "HTML 2.0 Level 2")) set_flags (HV_LEVEL2);
                    break;
                case doc_html1 :
                    note_parsed_version (nits, nit_html_tags, html_tags, "HTML 1.0");
                case doc_sqclose :
                    break;
                case doc_sqopen :
                    nits.pick (nit_sq_bra_ket, es_info, ec_parser, "ignoring [ ... ] details in <!DOCTYPE ... >");
                    sq_bra_ket = true;
                    break;
               default :
                    nits.pick (nit_internal_parsing_error, es_catastrophic, ec_parser, "bork! bork! bork! when parsing html_version. Abandoning hope");
                    return false; } }
    if (found_html)
    {   if (unknown ())
        {   if (found_unknown)
            {   nits.pick (nit_html_unknown_sgml, es_warning, ec_parser, "The HTML declaration in <!DOCTYPE ...> contains unrecognised content (", quote (wtf), "). Abandoning verification");
                return false; }
            html_version vvv;
            ::std::string ver;
            e_nit wit = nit_free;
            e_math_version ev = context.math_version ();
            e_svg_version sv = context.svg_version ();
            if (context.versioned ())
            {   vvv = context.html_ver ();
                wit = nit_overriding_html;
                ver = vvv.name (); }
            else
            {   vvv = html_default;
                if (vvv == html_5_0) wit = nit_html_5_0;
                else if (vvv == html_5_1) wit = nit_html_5_1;
                else if (vvv == html_5_2) wit = nit_html_5_2;
                else if (vvv == html_5_3) wit = nit_html_5_3;
                else wit = nit_html_5_living;
                ver = "HTML ";
                ver += minor_to_date (vvv); }
            if (ev > math_none) vvv.math_version (ev);
            if (sv > sv_none) vvv.svg_version (sv);
            note_parsed_version (nits, wit, vvv, ver);
            if (found_public)
                nits.pick (nit_public_unexpected, es_warning, ec_parser, "PUBLIC is unexpected"); }
        else
        {   if (! found_public && ! found_system)
                if ((mjr () > 1) || ((mjr () == 1) && (mnr ()== 1)))
                    nits.pick (nit_public_missing, es_info, ec_parser, "Either PUBLIC or SYSTEM expected");
            if (found_unknown) if (context.tell (e_warning))
                nits.pick (nit_unexpected_doctype_content, es_warning, ec_parser, "Ignoring unexpected content (", quote (wtf), ") found in <!DOCTYPE>"); }
        return true; }
    nits.pick (nit_doctype_incomprehensible, es_catastrophic, ec_parser, PROG " does not understand the <!DOCTYPE> so is abandoning verification");
    return false; }

bool html_version::deprecated (const html_version& current) const
{   switch (context.math_version ())
    {   case math_2 :
            if (current.all_ext (HE_M2_DEPRECAT))
                return true;
            break;
        case math_3 :
            if (current.all_ext (HE_M3_DEPRECAT))
                return true;
            break;
        case math_4 :
            if (current.all_ext (HE_M4_DEPRECAT))
                return true;
            break;
        default : break; }
    switch (current.mjr ())
    {   case 1 : return (current.any_flags (HV_DEPRECATED1));
        case 2 : return (current.any_flags (HV_DEPRECATED2));
        case 3 :
            switch (current.mnr ())
            {   case 0 : return any_flags (HV_DEPRECATED30);
                case 2 : return any_flags (HV_DEPRECATED32); }
            DBG_ASSERT (false); break;
        case 4:
            switch (current.mnr ())
            {   case 0 :
                case 1 : return any_flags (HV_DEPRECATED4);
                case 2 : return any_flags (HV_DEPRECATEDX1);
                case 3 : return any_flags (HV_DEPRECATEDX11);
                case 4 : return any_flags (HV_DEPRECATEDX2); }
            DBG_ASSERT (false); break;
        default :
            if (current.any_flags (HV_WHATWG))
                if (any_flags (HV_DEPRECATEDWWG))
                    return true;
            switch (w3_minor_5 (current))
            {   case 0 : return any_flags (HV_DEPRECATED50);
                case 1 : return any_flags (HV_DEPRECATED51);
                case 2 : return any_flags (HV_DEPRECATED52);
                case 3 : return any_flags (HV_DEPRECATED53);
                case 4 : return any_flags (HV_DEPRECATED54); } }
    return false; }

bool html_version::lazy () const
{   if (is_2_or_more ()) return true;
    if (is_0 ()) return false;
    return (mnr () > 0); }

e_emi extension_conflict (const html_version& lhs, const html_version& rhs)
{   if (lhs.is_b4_4 ()) return emi_good;
    if (! lhs.has_math () && rhs.has_math ()) return emi_math;
    if (! lhs.has_svg () && rhs.has_svg ())
    {   if (rhs.rdf () && lhs.has_rdf ()) return emi_good;
        if (lhs.is_4 ())
        {   if (rhs.svg_x1 () && (lhs.mnr () >= 2) && (lhs.mnr () <= 3)) return emi_good;
            if (rhs.svg_x2 () && (lhs.mnr () == 4)) return emi_good;
            if (rhs.svg_old_html ()) return emi_good; }
        else if (lhs.is_5 () && (lhs < html_jul08)) return emi_good;
        return emi_svg; }
    else if (lhs.has_svg () && rhs.not_svg ()) return emi_not_svg;
    if (! context.rdf () && ! lhs.has_rdf () && rhs.has_rdf ()) return emi_rdf;
    return emi_good; }

bool html_version::check_math_svg (nitpick& nits, const html_version& a, const ::std::string& x) const
{   switch (extension_conflict (*this, a))
    {   case emi_math :
            nits.pick (nit_math, es_error, ec_attribute, quote (x), " requires MathML"); return false;
        case emi_not_svg :
            nits.pick (nit_svg, es_error, ec_attribute, quote (x), " cannot be applied to SVG elements"); return false;
        case emi_svg :
            nits.pick (nit_svg, es_error, ec_attribute, quote (x), " requires SVG"); return false;
        case emi_rdf :
            nits.pick (nit_rdf, es_error, ec_attribute, quote (x), " requires RDFa"); return false;
        default : break; }
    return true; }

e_svg_version html_version::svg_version () const
{   if (all_ext (HE_SVG_20)) return sv_2_0;
    if (all_ext (HE_SVG_12_FULL)) return sv_1_2_full;
    if (all_ext (HE_SVG_12_TINY)) return sv_1_2_tiny;
    if (all_ext (HE_SVG_11)) return sv_1_1;
    if (all_ext (HE_SVG_10)) return sv_1_0;
    return sv_none; }

void html_version::svg_version (const e_svg_version v)
{   reset_ext (SVG_MASK);
    switch (v)
    {   case sv_1_0 : set_ext (HE_SVG_10); break;
        case sv_1_1 : set_ext (HE_SVG_11); break;
        case sv_1_2_tiny : set_ext (HE_SVG_12_TINY); break;
        case sv_1_2_full : set_ext (HE_SVG_12_FULL); break;
        case sv_2_0 : set_ext (HE_SVG_20); break;
        default : break; } }

e_math_version html_version::math_version () const
{   if (all_ext (HE_MATH_4)) return math_4;
    if (all_ext (HE_MATH_3)) return math_3;
    if (all_ext (HE_MATH_2)) return math_2;
    if (all_ext (HE_MATH_1)) return math_1;
    return math_none; }

void html_version::math_version (const e_math_version v)
{   reset_ext (MATH_MASK);
    switch (v)
    {   case math_1 : set_ext (HE_MATH_1); break;
        case math_2 : set_ext (HE_MATH_2); break;
        case math_3 : set_ext (HE_MATH_3); break;
        case math_4 : set_ext (HE_MATH_4); break;
        default : break; } }

::std::string html_version::get_doctype () const
{   switch (mjr ())
    {   case 0 : break;
        case 1 :
            switch (mnr ())
            {   case 0 : return "HTML PUBLIC \"-//IETF//DTD HTML//EN\"";
                case 1 : return "htmlplus PUBLIC \"-//Internet/RFC xxxx//EN\""; }
            break;
        case 2 :
            switch (level ())
            {   case 1 : return "HTML PUBLIC \"-//IETF//DTD HTML 2.0 Level 1//EN\"";
                case 2 : return "HTML PUBLIC \"-//IETF//DTD HTML 2.0 Level 2//EN\"";
                default : return "HTML PUBLIC \"-//IETF//DTD HTML 2.0//EN\""; }
        case 3 :
            switch (mnr ())
            {   case 0 : return "HTML PUBLIC \"-//IETF//DTD HTML 3.0//EN\"";
                case 2 : return "HTML PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\""; }
            break;
        case 4 :
            switch (mnr ())
            {   case 0 : return "HTML PUBLIC \"-//IETF//DTD HTML 4.0 Transitional//EN\" \"" HTTP_W3 "/TR/REC-html40/loose.dtd\"";
                case 1 : return "HTML PUBLIC \"-//IETF//DTD HTML 4.01 Transitional//EN\" \"" HTTP_W3 "/TR/html40/loose.dtd\"";
                case 2 : return "html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"" HTTP_W3 "/TR/xhtml1/DTD/xhtml1-transitional.dtd\"";
                case 3 : return "html PUBLIC \"-//W3C//DTD XHTML Basic 1.1//EN\" \"" HTTP_W3 "/TR/xhtml-basic/xhtml-basic11.dtd\"";
                case 4 : return "html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\" \"" HTTP_W3 "/MarkUp/DTD/xhtml2.dtd\""; }
            break;
        default : return "HTML"; }
    return ::std::string (); }

bool html_version::restricted_charset () const
{   return (is_5 ()); }

bool html_version::valid_charset (const ::std::string& charset) const
{   if (is_5 ()) return compare_no_case (charset, UTF_8);
    if (is_b4_1 ()) return compare_no_case (charset, US_ASCII);
    return true; }

const char *html_version::default_charset () const
{ return ::default_charset (*this); }

const char *html_version::alternative_charset () const
{ return ::alternative_charset (*this); }

bool html_version::is_plain_html () const
{   if (is_b4_4 ()) return true;
    if (xhtml () || has_svg () || has_math () || has_rdf ()) return false;
    return true; }


bool parse_doctype (nitpick& nits, html_version& version, const ::std::string::const_iterator b, const ::std::string::const_iterator e)
{   bool res = version.parse_doctype (nits, ::std::string (b, e));
    if (! res) version.reset (html_0);
    return res; }

bool does_html_apply (const html_version& v, const html_version& from, const html_version& to)
{   if (! from.unknown () && (v < from)) return false;
    if (context.microformats () && from.is_mf ()) return true;
    if (! to.unknown () && (v > to)) return false;
    switch (v.mjr ())
    {   case 0 :    break;
        case 1 :    if (v.mnr () == 0) return ! from.not10 ();
                    DBG_ASSERT (v.mnr () == 1);
                    return ! from.notplus ();
        case 2 :    if (from.not2 ()) return false;
                    if (from.not2l1 () && (v.level () == 1)) return false;
                    if (! context.rfc_1867 () && from.rfc_1867 ()) return false;
                    if (! context.rfc_1942 () && from.rfc_1942 ()) return false;
                    if (! context.rfc_1980 () && from.rfc_1980 ()) return false;
                    if (! context.rfc_2070 () && from.rfc_2070 ()) return false;
                    break;
        case 3 :    if (v.mnr () == 2) return ! from.not32 ();
                    DBG_ASSERT (v.mnr () == 0);
                    return ! from.not30 ();
        case 4 :    //if (extension_conflict (v, from) != emi_good) return false;
                    switch (v.mnr ())
                    {   case 0 :
                        case 1 : return ! from.not4 ();
                        case 2 :
                        case 3 : return ! from.notx1 ();
                        case 4 : return ! from.notx2 (); }
                    DBG_ASSERT (false);
                    break;
        default :   if (from.xhtml () && from.notx5 ()) return false;
                    if (context.html_ver ().whatwg () && from.w3 ()) return false;
                    switch (w3_5_minor (v))
                    {   case 0 : return ! from.not50 ();
                        case 1 : return ! from.not51 ();
                        case 2 : return ! from.not52 ();
                        case 3 : return ! from.not53 ();
                        default : break; }
                    break; }
    return true; }

int w3_minor_5 (const html_version& v)
{   if (! v.is_5 ()) return v.mnr ();
    if (v.mjr () < MAJOR_5_0) return 0;
    if ((v.mjr () == MAJOR_5_0) && (v.mnr () <= MINOR_5_0)) return 0;
    if (v.mjr () < MAJOR_5_1) return 1;
    if ((v.mjr () == MAJOR_5_1) && (v.mnr () <= MINOR_5_1)) return 1;
    if (v.mjr () < MAJOR_5_2) return 2;
    if ((v.mjr () == MAJOR_5_2) && (v.mnr () <= MINOR_5_2)) return 2;
    if (v.mjr () < MAJOR_5_3) return 3;
    if ((v.mjr () == MAJOR_5_3) && (v.mnr () <= MINOR_5_3)) return 3;
    return 4; }

int w3_5_minor (const html_version& v)
{   if (! v.is_5 ()) return v.mnr ();
    if ((v.mjr () == MAJOR_5_0) && (v.mnr () == MINOR_5_0)) return 0;
    if ((v.mjr () == MAJOR_5_1) && (v.mnr () == MINOR_5_1)) return 1;
    if ((v.mjr () == MAJOR_5_2) && (v.mnr () == MINOR_5_2)) return 2;
    if ((v.mjr () == MAJOR_5_3) && (v.mnr () == MINOR_5_3)) return 3;
    return -1; }

const char *default_charset (const html_version& v)
{   switch (v.mjr ())
    {   case 0 :
        case 1 : return US_ASCII;
        case 2 :
        case 3 :
        case 4 : return LATIN_1;
        case 5 : return LATIN_1;
        default : return UTF_8; } }

const char *alternative_charset (const html_version& v)
{   if (v.is_b4_2 () || v.is_4_or_more ()) return "";
    return US_ASCII; }

html_version get_min_version (const e_svg_version e)
{   switch (e)
    {   case sv_1_0 : return xhtml_svg_1_0;
        case sv_1_1 : return xhtml_svg_1_1;
        case sv_1_2_full : return xhtml_svg_1_2_tiny;
        case sv_1_2_tiny : return xhtml_svg_1_2_full;
        case sv_2_0 : return html_svg_2_0;
        default : return html_0; } }

html_version get_min_version (const e_math_version e)
{   switch (e)
    {   case math_1 : return html_math_1;
        case math_2 : return xhtml_math_2;
        case math_3 : return html_math_3;
        case math_4 : return html_math_4;
        default : return html_0; } }
