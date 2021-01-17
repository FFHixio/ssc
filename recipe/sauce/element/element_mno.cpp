/*
ssc (static site checker)
Copyright (c) 2020,2021 Dylan Harris
https://dylanharris.org/

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public Licence as published by
the Free Software Foundation, either version 3 of the Licence,  or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public Licence for more details.

You should have received a copy of the GNU General Public
Licence along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include "main/standard.h"
#include "element/element.h"
#include "webpage/page.h"
#include "attribute/attribute_classes.h"
#include "type/type_metaname.h"

void element::examine_main ()
{   only_one_of (elem_main);
    if (node_.version ().mjr () >= 5)
        if (w3_minor_5 (node_.version ()) < 3)
            check_ancestors (elem_main, empty_element_bitset | elem_article | elem_aside | elem_footer | elem_header | elem_nav);
        else
        {   element_bitset tmp (ancestral_elements_);
            tmp &= ~(non_standard_bitset | elem_html | elem_body | elem_div | elem_form);
            if (tmp.any ())
                pick (nit_bad_ancestor, ed_53, "4.4.14. The main element", es_error, ec_element, "<MAIN> can only have <HTML>, <BODY>, <DIV> or <FORM> parents."); } }

void element::examine_map ()
{   if (node_.version ().mjr () >= 5)
        if (a_.known (a_name) && a_.known (a_id))
            if (! compare_no_case (a_.get_string (a_name), a_.get_string (a_id)))
                pick (nit_name_id, ed_50, "4.7.11 The map element", es_error, ec_attribute, "If NAME and ID are both specified, they must have the same value"); }

void element::examine_math ()
{   if (! has_child ()) return;
    e_mathversion mv = node_.version ().math_version ();
    if (mv == math_none) mv = page_.version ().math_version ();
    switch (mv)
    {   case math_2 : break;
        case math_3 :
        case math_4 :
            if (a_.known (a_macros))
                pick (nit_deprecated_attribute, ed_math_3, "2.2.2 Deprecated Attributes", es_warning, ec_attribute, "the attribute MACROS is deprecated in MathML 3");
            if (a_.known (a_mode))
                pick (nit_deprecated_attribute, ed_math_3, "2.2.2 Deprecated Attributes", es_warning, ec_attribute, "the attribute MODE is deprecated in MathML 3; use DISPLAY instead");
            break;
        default :
            return; }
    bool other = false; bool content = false;
    for (element* c = child_.get (); c != nullptr; c = c -> sibling_.get ())
        if (c -> node_.id ().is_math () && ! c -> node_.is_closure ())
        {   if (c -> node_.id ().is_math ()) content = true;
            if (c -> node_.tag () != elem_declare) other = true;
            else if (other)
            {   pick (nit_declare_first, ed_math_2, "4.4.2.8 Declare (declare)", es_error, ec_element, "All <DECLARE> elements must occur at the beginning of a <MATH> element");
                break; } }
    if (! content)
        pick (nit_math_empty, ed_math_3, "3.1.3.2 Table of argument requirements", es_error, ec_element, "<MATH> should contain some math."); }

void element::examine_media_element (e_element , const char* ref, const char* name)
{   assert (ref != nullptr);
    if (a_.known (a_controls)) no_anchor_daddy ();
    bool had_track = false, had_other = false, noted_src = false, noted_track = false, noted_source = false,
        def_subcap = false, def_desc = false, def_chap = false;
    bool has_src = a_.known (a_src);
    sstr_t track_check; ::std::string tmp;
    for (element_ptr p = child_; p != nullptr; p = p -> sibling_)
        if(! p -> node_.is_closure () && is_standard_element (p -> node_.tag ()))
            switch (p -> node_.tag ())
            {   case elem_source :
                    if (has_src)
                    {   if (! noted_src) pick (nit_saucy_source, ed_50, ref, es_error, ec_element, "don't mix SRC attributes on ", name, " with <SOURCE> descendants");
                        noted_src = true;
                        p -> pick (nit_saucy_source, ed_50, ref, es_error, ec_element, "Do not use <SOURCE> when the parental ", name, " has a SRC attribute"); }
                    if (had_track)
                    {   if (! noted_track) pick (nit_out_of_order, ed_50, ref, es_error, ec_element, "<TRACK> and <SOURCE> descendants are out of order");
                        noted_track = true;
                        p -> pick (nit_source_track, ed_50, ref, es_error, ec_element, "<SOURCE> descendants of ", name, " must precede <TRACK> descendants"); }
                    if (had_other)
                    {   if (! noted_source) pick (nit_out_of_order, ed_50, ref, es_error, ec_element, "<SOURCE> descendants are out of order");
                        noted_source = true;
                        p -> pick (nit_source_track, ed_50, ref, es_error, ec_element, "<SOURCE> descendants of ", name, " must precede other descendants"); }
                    break;
                case elem_track :
                    if (had_other)
                    {   if (! noted_track) pick (nit_out_of_order, ed_50, ref, es_error, ec_element, "<TRACK> descendants are out of order");
                        noted_track = true;
                        p -> pick (nit_source_track, ed_50, ref, es_error, ec_element, "<TRACK> descendants of ", name, " must follow <SOURCE> descendants and precede other descendants"); }
                    had_track = true;
                    tmp = p -> a_.get_string (a_kind) + p -> a_.get_string (a_srclang) + p -> a_.get_string (a_label);
                    if (track_check.find (tmp) == track_check.cend ()) track_check.insert (tmp);
                    else p -> pick (nit_kind_media_srclang, ed_50, "4.7.9 The track element", es_error, ec_element, "the KIND, SRCLANG and LABEL values of <TRACK> cannot together be the same as those of another <TRAC> descendant of ", name);
                    if (p -> a_.known (a_default))
                        switch (p -> a_.get_int (a_kind))
                        {   case k_descriptions :
                                if (def_desc) p -> pick (nit_track_default, ed_50, "4.7.9 The track element", es_error, ec_element, "only one <TRACK> descendant of ", name, " may have DEFAULT and a KIND description");
                                def_desc = true; break;
                            case k_chapters :
                                if (def_chap) p -> pick (nit_track_default, ed_50, "4.7.9 The track element", es_error, ec_element, "only one <TRACK> descendant of ", name, " may have DEFAULT and KIND chapters");
                                def_chap = true; break;
                            case k_metadata : break;
                            default :
                                if (def_subcap) p -> pick (nit_track_default, ed_50, "4.7.9 The track element", es_error, ec_element, "only one <TRACK> descendant of ", name, " may have DEFAULT and a KIND caption, subtitles, or omitted");
                                def_subcap = true; break; }
                    break;
                default :
                    had_other = true;
                    break; }
    element_bitset bs (descendant_elements_);
    bs &= media_bitset;
    if (bs.any ())
        pick (nit_media_descendants, ed_50, ref, es_error, ec_element, name, " can have neither <VIDEO> nor <AUDIO> descendants" ); }

void element::examine_meta ()
{   bool in_head = ancestral_elements_.test (elem_head);
    bool md = (node_.version ().whatwg () || context.microdata ());
    bool ipk = a_.known (a_itemprop);
    bool nk = a_.known (a_name);
    bool csk = a_.known (a_charset);
    bool hek = a_.known (a_httpequiv);
    bool prp = a_.known (a_property);
    if (node_.version ().mjr () < 5)
    {   if (ipk)
            if (nk || csk || hek)
                pick (nit_itemprop_name_charset_equiv, ed_mozilla, "", es_error, ec_element, "ITEMPROP cannot be used where a <META> defines NAME, CHARSET, or HTTP-EQUIV"); }
    else
    {   int c = 0;
        if (hek) ++c;
        if (csk) ++c;
        if (nk) ++c;
        if (md && ipk) ++c;
        if ((c == 0) && prp) ++c;
        if (c != 1)
            if (md) pick (nit_nahtch, ed_jul20, "4.2.5 The meta element", es_error, ec_element, "exactly one of NAME, HTTP-EQUIV, CHARSET, or ITEMPROP must be specified");
            else pick (nit_nahtch, ed_50, "4.2.5 The meta element", es_error, ec_element, "exactly one of NAME, HTTP-EQUIV, or CHARSET must be specified"); }
    if (csk)
    {   if (! in_head)
            pick (nit_bad_meta_place, ed_50, "4.2.5 The meta element", es_error, ec_element, "CHARSET can only be used on a <META> in a <HEAD>");
        else if (a_.known (a_content))
            pick (nit_no_content, ed_50, "4.2.5 The meta element", es_error, ec_element, "CONTENT cannot be used with CHARSET");
        else if (page_.charset_defined ())
            pick (nit_charset_redefined, ed_50, "4.2.5 The meta element", es_error, ec_element, "there can be no more than one <META> with a CHARSET per document");
        else
        {   type_master < t_charset > cs;
            cs.set_value (nits (), page_.version (), a_.get_string (a_charset));
            if (cs.good ()) page_.charset (nits (), page_.version (), cs.get_string ()); } }
    else if (hek)
    {   if (! in_head)
            pick (nit_bad_meta_place, ed_50, "4.2.5 The meta element", es_error, ec_element, "HTTP-EQUIV can only be used on a <META> in a <HEAD>");
        else if (! a_.known (a_content))
            pick (nit_no_content, ed_50, "4.2.5 The meta element", es_error, ec_element, "HTTP-EQUIV requires CONTENT");
        else
        {   attr_httpequiv* he = reinterpret_cast < attr_httpequiv* > (a_.get (a_httpequiv).get ());
            if (he != nullptr)
            {   ::std::string ct (validate_httpequiv_content (nits (), node_.version (), he -> get (), trim_the_lot_off (a_.get_string (a_content)), page_));
                switch (he -> get_int ())
                {   case he_content_style_type :
                        page_.style_css (compare_no_case (CSS_TYPE, ct));
                        if (! page_.style_css ()) pick (nit_style_not_css, es_comment, ec_element, "the default style is NOT css");
                        break;
                    case he_location :
                    case he_refresh :
                        page_.verify_url (nits (), ct, ancestral_attributes_, vit_);
                    default : break; } } } }
    else if (nk)
        if (! a_.known (a_content))
            pick (nit_no_content, ed_50, "4.2.5 The meta element", es_error, ec_element, "NAME requires CONTENT");
        else if (a_.good (a_name))
        {   ::std::string con (a_.get_string (a_content));
            type_master < t_metaname > mn;
            nitpick nuts;
            mn.set_value (nuts, node_.version (), a_.get_string (a_name));
            assert (a_.good (a_name));
            e_metaname emn = mn.get ();
            validate_metaname_content (nits (), node_.version (), in_head, emn, con, page_); } }

void element::examine_meter ()
{   if (node_.version ().mjr () >= 5)
    {   check_ancestors (elem_progress, element_bit_set (elem_meter));
        double min = 0.0, max = 1.0, low = 0.0, high = 0.0, optimum = 0.0, value = 0.0;
        bool kx = a_.known (a_max);
        bool kn = a_.known (a_min);
        bool kl = a_.known (a_low);
        bool kh = a_.known (a_high);
        bool ko = a_.known (a_optimum);
        bool kv = a_.known (a_value);
        if (kn) min = lexical < double > :: cast (a_.get_string (a_min));
        if (kx) max = lexical < double > :: cast (a_.get_string (a_max));
        if (kl) low = lexical < double > :: cast (a_.get_string (a_low));
        if (kh) high = lexical < double > :: cast (a_.get_string (a_high));
        if (ko) optimum = lexical < double > :: cast (a_.get_string (a_optimum));
        if (kv) value = lexical < double > :: cast (a_.get_string (a_value));

        if (max < min) pick (nit_bad_meter, ed_50, "4.10.15 The meter element", es_error, ec_element, "MIN (", min, ") cannot exceed MAX (", max, ")");
        if (min == max) pick (nit_bad_meter, ed_50, "4.10.15 The meter element", es_warning, ec_element, "a <METER> with the same MIN and MAX seems a little pointless");
        if (value < min) pick (nit_bad_meter, ed_50, "4.10.15 The meter element", es_error, ec_element, "MIN (", min, ") cannot exceed VALUE (", value, ")");
        if (max < value) pick (nit_bad_meter, ed_50, "4.10.15 The meter element", es_error, ec_element, "VALUE (", value, ") cannot exceed MAX (", max, ")");
        if (kl)
        {   if (kh)
            {   if (low < high) pick (nit_bad_meter, ed_50, "4.10.15 The meter element", es_error, ec_element, "LOW (", low, ") cannot exceed HIGH (", high, ")");
                if (low == high) pick (nit_bad_meter, ed_50, "4.10.15 The meter element", es_info, ec_element, "a <METER> with the same LOW and HIGH seems a little dubious"); }
            if (low < min) pick (nit_bad_meter, ed_50, "4.10.15 The meter element", es_error, ec_element, "MIN (", min, ") cannot exceed LOW (", low, ")");
            if (max < low) pick (nit_bad_meter, ed_50, "4.10.15 The meter element", es_error, ec_element, "LOW (", low, ") cannot exceed MAX (", max, ")"); }
        if (kh)
        {   if (high < min) pick (nit_bad_meter, ed_50, "4.10.15 The meter element", es_error, ec_element, "MIN (", min, ") cannot exceed HIGH (", high, ")");
            if (max < high) pick (nit_bad_meter, ed_50, "4.10.15 The meter element", es_error, ec_element, "HIGH (", high, ") cannot exceed MAX (", max, ")"); }
        if (ko)
        {   if (optimum < min) pick (nit_bad_meter, ed_50, "4.10.15 The meter element", es_error, ec_element, "MIN (", min, ") cannot exceed OPTIMUM (", optimum, ")");
            if (max < optimum) pick (nit_bad_meter, ed_50, "4.10.15 The meter element", es_error, ec_element, "OPTIMUM (", optimum, ") cannot exceed MAX (", max, ")"); } } }

void element::examine_mglyph ()
{   if (page_.version ().math_version () == math_2)
    {   attribute_bitset as (own_attributes_);
        as.reset (a_fontfamily);
        as.reset (a_index);
        as.reset (a_alt);
        if (as.any ())
            pick (nit_attribute_unrecognised_here, es_error, ec_attribute, "Only ALT, FONTFAMILY and INDEX are valid on <MGLYPH> in mathML 2");
        if (! a_.known (a_fontfamily))
            pick (nit_mglyph_alt_src, ed_math_2, "3.2.9.2 Attributes", es_warning, ec_attribute, "FONTFAMILY is required for correct usage of <MGLYPH> in MathML 2");
        if ( a_.known (a_index))
            pick (nit_mglyph_alt_src, ed_math_2, "3.2.9.2 Attributes", es_warning, ec_attribute, "INDEX is required for correct usage of <MGLYPH> in MathML 2");
        if (! a_.known (a_alt))
            pick (nit_mglyph_alt_src, ed_math_2, "3.2.9.2 Attributes", es_warning, ec_attribute, "ALT, is required for correct usage of <MGLYPH> in MathML 2"); }
    else if (page_.version ().math_version () == math_3)
    {   if (! a_.known (a_src))
            pick (nit_mglyph_alt_src, ed_math_3, "3.2.1.2 Using images to represent symbols <mglyph/>", es_warning, ec_attribute, "SRC is required for correct usage of <MGLYPH> in MathML 3");
        if (! a_.known (a_alt))
            pick (nit_mglyph_alt_src, ed_math_3, "3.2.1.2 Using images to represent symbols <mglyph/>", es_warning, ec_attribute, "ALT is required for correct usage of <MGLYPH> in MathML 3");
        if (a_.known (a_mathvariant))
            pick (nit_deprecated_attribute, ed_math_3, "3.2.1.2 Using images to represent symbols <mglyph/>", es_warning, ec_attribute, "MATHVARIANT is deprecated with <MGLYPH> in MathML 3");
        if (a_.known (a_mathsize))
            pick (nit_deprecated_attribute, ed_math_3, "3.2.1.2 Using images to represent symbols <mglyph/>", es_warning, ec_attribute, "MATHSIZE is deprecated with <MGLYPH> in MathML 3");
        if (a_.known (a_fontfamily))
            pick (nit_deprecated_attribute, ed_math_3, "3.2.1.2 Using images to represent symbols <mglyph/>", es_warning, ec_attribute, "FONTFAMILY is deprecated with <MGLYPH> in MathML 3");
        if (a_.known (a_index))
            pick (nit_deprecated_attribute, ed_math_3, "3.2.1.2 Using images to represent symbols <mglyph/>", es_warning, ec_attribute, "INDEX is deprecated with <MGLYPH> in MathML 3"); } }

void element::examine_mstyle ()
{   if (page_.version ().math_version () < math_3) return;
    if (a_.known (a_background))
        pick (nit_attribute_unrecognised_here, ed_math_3, "3.3.4.2 Attributes", es_error, ec_attribute, "the BACKGROUND attribute is not associated with <MSTYLE> in MathML 3");
    attribute_bitset bs = a_verythickmathspace | a_verythinmathspace | a_veryverythickmathspace | a_veryverythinmathspace |
            a_thinmathspace | a_thickmathspace | a_mediummathspace;
    bs &= own_attributes_;
    if (bs.any ())
        pick (nit_deprecated_attribute, es_warning, ec_attribute, "the ...MATHSPACE attributes are deprecated in MathML 3"); }

void element::examine_nav ()
{   if (has_this_descendant (elem_main))
        pick (nit_no_main_kids, ed_50, "4.3.4 The nav element", es_warning, ec_element, "<NAV> can have no <MAIN> descendants"); }

void element::examine_noscript ()
{   if (node_.version ().mjr () < 5) return;
    check_ancestors (elem_noscript, element_bit_set (elem_noscript));
    if (ancestral_elements_.test (elem_head))
    {   element_bitset bs (descendant_elements_);
        bs &= ~(non_standard_bitset | elem_link | elem_style | elem_meta);
        if (bs.any ())
            pick (nit_bad_noscript, ed_50, "4.11.2 The noscript element", es_error, ec_element, "in a document's header, <NOSCRIPT> can only have <LINK>, <STYLE>, or <META> descendants"); } }

void element::examine_object ()
{   if (node_.version ().mjr () >= 5)
    {   if ((! a_.known (a_data) && ! a_.known (a_type)))
            pick (nit_data_type, ed_50, "4.7.4 The object element", es_error, ec_element, "either DATA or TYPE must be present");
        if (a_.known (a_itemprop) && ! a_.known (a_data))
            pick (nit_bad_object, ed_jul20, "4.8.7 The object element", es_error, ec_attribute, "DATA is required when <OBJECT> has ITEMPROP");
        if (a_.known (a_usemap)) no_anchor_daddy ();
        if (a_.known (a_typemustmatch))
        {    if (! a_.known (a_data) && ! a_.known (a_type))
                pick (nit_typemustmatch, ed_50, "4.7.4 The object element", es_error, ec_element, "TYPEMUSTMATCH requires both DATA and TYPE"); }
        else if (a_.known (a_data) && a_.known (a_type) && (w3_minor_5 (node_.version ()) < 4))
            if (a_.get_string (a_data).find (":") != ::std::string::npos)
                pick (nit_typemustmatch, ed_50, "4.7.4 The object element", es_info, ec_element, "consider specifying TYPEMUSTMATCH, for added security"); }
    bool had_flow = false;
    for (element_ptr p = child_; p != nullptr; p = p -> sibling_)
        if (! p -> node_.is_closure () && is_standard_element (p -> node_.tag ()))
            switch (p -> node_.tag ())
            {   case elem_param :
                    if (had_flow) pick (nit_disordered_param, ed_50, "4.7.5 The param element", es_error, ec_element, "<PARAM> should precede all other child elements of <OBJECT>");
                    break;
                case elem_standby :
                case elem_caption :
                    if (node_.version () == xhtml_2) break;
                    // drop thru'
                default :
                    if ((node_.version ().mjr () < 5) || ((node_.id ().categories () & EF_5_FLOW) == EF_5_FLOW)) had_flow = true; } }

void element::examine_option ()
{   if (node_.version ().mjr () >= 5)
        if (a_.known (a_label))
        {   if (a_.known (a_value))
                if (has_child ()) pick (nit_bad_option, ed_50, "4.10.10 The option element", es_error, ec_element, "<OPTION> with both LABEL and VALUE defined cannot have content"); }
        else if (! ancestral_elements_.test (elem_datalist))
            if (text ().empty ())
                pick (nit_bad_option, ed_50, "4.10.10 The option element", es_error, ec_element, "here, <OPTION> requires text content"); }
