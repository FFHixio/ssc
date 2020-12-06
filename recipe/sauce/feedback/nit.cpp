/*
ssc (static site checker)
Copyright (c) 2020 Dylan Harris
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
#include "feedback/nit.h"
#include "feedback/nitnames.h"
#include "main/context.h"

nitmap quick_nit;
timmap quick_tim;

void nit::init ()
{  preload_nits (); }

e_nit nit::lookup (const ::std::string& name)
{   nitmap::const_iterator i = quick_nit.find (name);
    if (i == quick_nit.cend ()) return nit_off;
    return i -> second; }

::std::string doc_title (const e_doc doc)
{   switch (doc)
    {   case ed_mishmash : return "(no reference)";
        case ed_imaginary : return "Invalid reference";
        case ed_dict: return "Dictionary";
        case ed_tags : return "HTML Tags";
        case ed_plus : return "HTML Plus";
        case ed_1 : return "HTML 1.0";
        case ed_2 : return "HTML 2.0";
        case ed_3 : return "HTML 3.0";
        case ed_32 : return "HTML 3.2";
        case ed_4 : return "HTML 4.0";
        case ed_41 : return "HTML 4.01";
        case ed_x1 : return "XHTML 1.0";
        case ed_x11 : return "XHTML 1.1";
        case ed_x2 : return "XHTML 2.0";
        case ed_50 : return "HTML 5.0";
        case ed_51 : return "HTML 5.1";
        case ed_52 : return "HTML 5.2";
        case ed_53 : return "HTML 5.3";
        case ed_math_1 : return "MathML 1.01";
        case ed_math_2 : return "MathML 2 2nd Ed.";
        case ed_math_3 : return "MathML 3 2nd Ed.";
        case ed_math_4 : return "MathML 4";
        case ed_rdf : return "RDFa";
        case ed_rfc_1867 : return "RFC 1867";
        case ed_rfc_1980 : return "RGC 1980";
        case ed_rfc_3966 : return "RFC 3966";
        case ed_svg_1_0 : return "SVG 1.0";
        case ed_svg_1_1 : return "SVG 1.1";
        case ed_svg_1_2_tiny : return "SVG 1.2 Tiny";
        case ed_svg_1_2_full : return "SVG 1.2 Full";
        case ed_svg_2_0 : return "SVG 2.0";
        case ed_w3 : return "World Wide Web Consortium";
        case ed_apache : return "Apache";
        case ed_May2020 : return "HTML 5, WhatWG (May 2020)";
        case ed_July2020 : return "HTML 5, WhatWG (July 2020)";
        case ed_mozilla : return "mozilla.org (May 2020)";
        case ed_microdata : return "WhatWG Microdata";
        case ed_microformats : return "microformats.org (May 2020)";
        case ed_ariaAug2020 : return "Aria (August 2020)";
        case ed_so_11 : return "schema.org 11.0";
        case ed_mql : return "Media Queries"; }
    return "Unknown reference"; }

nit::nit () : code_ (nit_free), severity_ (es_undefined), category_ (ec_undefined), doc_ (ed_mishmash), ref_ (nullptr)
{   if (context.nits ()) context.out () << "adding empty nit\n"; }

nit::nit (const e_nit code, const e_doc doc, const ::std::string& ref, const e_severity severity, const e_category category, const ::std::string& msg)
    : code_ (code), severity_ (severity), category_ (category), doc_ (doc), ref_ (ref), msg_ (msg)
{   if (context.nits ()) context.out () << "adding ref nit " << severity << ", " << msg << "\n"; }

nit::nit (const e_nit code, const e_severity severity, const e_category category, const ::std::string& msg)
    : code_ (code), severity_ (severity), category_ (category), doc_ (ed_mishmash), msg_ (msg)
{   if (context.nits ()) context.out () << "adding nit " << severity << ", " << msg << "\n"; }

void nit::swap (nit& n) NOEXCEPT
{   ::std::swap (code_, n.code_);
    ::std::swap (severity_, n.severity_);
    ::std::swap (category_, n.category_);
    ::std::swap (doc_, n.doc_);
    ::std::swap (ref_, n.ref_);
    msg_.swap (n.msg_); }

void nit::reset ()
{   nit n;
    swap (n); }

void nit::reset (const nit& n)
{   nit tmp (n);
    swap (tmp); }

void nit::notify () const
{   context.mark (severity_);
    context.mark (category_);
    context.mark (doc_); }

::std::string nitcode (const e_nit code, const e_severity severity)
{   ::std::ostringstream res;
    unsigned m = 1;
    switch (severity)
    {   case es_undefined : m = 90000; res << "?"; break;
        case es_catastrophic : res << "F"; break;  // F failure
        case es_error : m = 10000; res << "E"; break;
        case es_warning : m = 20000; res << "W"; break;
        case es_info : m = 30000; res << "I"; break;
        case es_comment : m = 40000; res << "C"; break;
        case es_debug : m = 50000; res << "D"; break;
        case es_detail : m = 60000; res << ":"; break;
        case es_splurge : m = 70000; res << "."; break;
        default : m = 8000; res << " "; break; }
    res << ::std::setw (4) << (m + static_cast < unsigned > (code));
    return res.str (); }

bool ignore_this_slob_stuff (const e_nit code)
{   if (! context.slob ()) return false;
    switch (code)
    {   case nit_missing_close :
        case nit_inserted_missing_closure :
        case nit_inserted_missing_parent : return true;
        default : return false; } }

::std::string nit::review () const
{   ::std::ostringstream res;
    ::std::string info;
    if (! empty ())
        if (severity_ != es_silence)
            if (! ignore_this_slob_stuff (code ()))
            {   if (context.tell (static_cast < e_verbose > (static_cast < unsigned > (severity_))))
                {   if (code () != nit_context)
                        if (context.codes ()) res << nitcode (code_, severity_) << "  ";
                        else switch (severity_)
                        {   case es_catastrophic : res << " >>> "; break;
                            case es_error : res << " ==> "; break;
                            case es_warning : res << " --> "; break;
                            case es_info : res << " ..> "; break;
                            case es_comment : res << " . > "; break;
                            default : res << "     "; break; }
                    res << msg_;
                    if (doc_ != ed_mishmash)
                    {   res << " [" << doc_title (doc_);
                        if (! ref_.empty ())
                        {   res << ", ";
                            res << ref_; }
                        res << "]"; }
                    if (context.nids ())
                    {   timmap::const_iterator i = quick_tim.find (code_);
                        res << " (" << nitcode (code_, severity_);
                        if (i != quick_tim.end ()) res << ", " << i -> second;
                        res << ")"; }
                    res << "\n"; } }
    return res.str (); }
