/*
ssc (static site checker)
Copyright (c) 2020 Dylan Harris
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
#include "attribute/attribute_classes.h"
#include "webpage/page.h"

void element::examine_address ()
{   if (node_.version ().mjr () >= 5)
    {   check_ancestors (elem_address, empty_element_bitset | elem_address);
        check_descendants (elem_address, header_bitset | sectioning_bitset | elem_address | elem_header | elem_footer); } }

void element::examine_anchor ()
{   const bool href_known = a_.known (a_href);
    const bool five = node_.version ().mjr () >= 5;
    if (href_known) no_anchor_daddy ();
    else if (a_.known (a_rel) || a_.known (a_rev))
        pick (nit_rel_requires_href, ed_1, "Anchors", es_error, ec_element, "REL and REV both require HREF");
    else if (five) pick (nit_chocolate_teapot, es_warning, ec_element, "An <A> with no HREF is not useful");
    else if (! a_.known (a_name))
        pick (nit_chocolate_teapot, ed_tags, "Anchors", es_warning, ec_element, "An <A> with neither an HREF nor a NAME is not useful");
    if (a_.known (a_urn))
        pick (nit_urn_undefined, ed_1, "Anchors", es_info, ec_element, PROG " cannot verify URN values");
    if (a_.known (a_methods))
        pick (nit_methods_undefined, ed_1, "Anchors", es_info, ec_element, PROG " cannot verify METHOD values here");
    if (five)
    {   if (! href_known)
        {   if (a_.known (a_target) || a_.known (a_download) || a_.known (a_ping) ||  a_.known (a_referrerpolicy) ||  a_.known (a_rel) ||  a_.known (a_rev) ||  a_.known (a_hreflang) ||  a_.known (a_type))
                pick (nit_chocolate_teapot, ed_50, "4.5.1 The a element", es_error, ec_element, "An <A> with no HREF can have no DOWNLOAD, HREFLANG, REL, REV, REFERRERPOLICY, PING, TARGET or TYPE attributes.");
            if (a_.known (a_itemprop))
                pick (nit_chocolate_teapot, ed_July2020, "4.5.1 The a element", es_error, ec_element, "An <A> with an ITEMPROP requires an HREF."); }
        if (w3_minor_5 (node_.version ()) >= 4)
        {   attribute_bitset as (descendant_attributes_);
            if (as.test (a_tabindex))
                pick (nit_tabindex, ed_July2020, "4.5.1 The a element", es_error, ec_element, "An <A> cannot have a descendant with TABINDEX."); } } }

void element::examine_animatemotion ()
{   bool had = false;
    if (has_child ())
        for (element* c = child_.get (); c != nullptr; c = c -> sibling_.get ())
            if (c -> tag () == elem_mpath)
                if (! had) had = true;
                else
                {   pick (nit_animatemotion, ed_svg_1_1, "19.2.14 The animateMotion element", es_error, ec_element, "<ANIMATEMOTION> can only have ONE child <MPATH>");
                    return; } }

void element::examine_annotation ()
{   if (node_.version ().math () < math_2) return;
    if (has_child ())
        pick (nit_annotation, es_info, ec_element, "apologies, but " PROG " makes to effort to analyse the content of <ANNOTATION>"); }

void element::examine_annotation_xml ()
{   if (node_.version ().math () < math_2) return;
    if (has_child ())
        pick (nit_annotation, es_info, ec_element, "apologies, but " PROG " makes to effort to analyse the content of <ANNOTATION-XML>"); }

void element::examine_area ()
{   if (node_.version ().mjr () >= 5)
    {   if (! any (ancestral_elements_, empty_element_bitset | elem_map | elem_template))
            pick (nit_area_map_template, ed_50, "4.7.12 The area element", es_error, ec_element, "<AREA> requires a <MAP> or a <TEMPLATE> ancestor");
        if (a_.known (a_href))
        {    if (! a_.known (a_alt))
                pick (nit_requires_href, ed_50, "4.7.12 The area element", es_warning, ec_element, "The HREF requires an ALT"); }
        else
        {   if (a_.known (a_alt))
                pick (nit_requires_href, ed_50, "4.7.12 The area element", es_warning, ec_element, "ALT requires an HREF");
            if (a_.known (a_target) || a_.known (a_download) || a_.known (a_rel) || a_.known (a_hreflang) || a_.known (a_type))
                pick (nit_requires_href, ed_50, "4.7.12 The area element", es_warning, ec_element, "DOWNLOAD, HREFLANG, REL, TARGET and TYPE all require an HREF"); } }
    if (a_.good (a_shape))
    {   type_master < t_shape7 > s7;
        nitpick knots;
        s7.set_value (knots, node_.version (), a_.get_string (a_shape));
        if (s7.good ())
        {   if ((s7.get () != s7_default) && ! a_.known (a_coords))
            {   pick (nit_need_coords, ed_50, "4.7.12 The area element", es_warning, ec_element, "Unless SHAPE is present and set to 'default', COORDS must be specified");
                return; }
            if (! a_.good (a_coords)) return;
            vint_t c = a_.get_x < attr_coords > ();
            switch (s7.get ())
            {   case s7_circ :
                    if (c.size () != 3) pick (nit_bad_coords, ed_rfc_1980, "2.1 Syntax", es_error, ec_attribute, "When SHAPE is circle, COORDS should contain three values.");
                    break;
                case s7_poly :
                    if (c.size () % 2 != 0) pick (nit_bad_coords, ed_rfc_1980, "2.1 Syntax", es_error, ec_attribute, "When SHAPE is polygon, COORDS should contain a sequence of coordinates (an even number of values).");
                    break;
                case s7_rect :
                    if (c.size () != 4) pick (nit_bad_coords, ed_rfc_1980, "2.1 Syntax", es_error, ec_attribute, "When SHAPE is rectangle (the default value), COORDS should contain two coordinates.");
                    break;
                default : break; } } } }

void element::examine_article ()
{   if (has_this_descendant (elem_main))
        pick (nit_no_main_kids, ed_50, "4.3.2 The article element", es_warning, ec_element, "<ARTICLE> can have no <MAIN> descendants"); }

void element::examine_aside ()
{   if (w3_minor_5 (node_.version ()) < 4)
        if (has_this_descendant (elem_main))
            pick (nit_no_main_kids, ed_50, "4.3.5 The aside element", es_warning, ec_element, "<ASIDE> can have no <MAIN> descendants"); }

void element::examine_audio ()
{   examine_media_element (elem_audio, "4.7.7 The audio element", "<AUDIO>");
    if (a_.known (a_autoplay)) pick (nit_autoplay, es_warning, ec_rudeness, "AUTOPLAY on <AUDIO> is rude"); }

void element::examine_base ()
{   if (node_.version () == html_tags)
    {   pick (nit_base_undefined, ed_tags, "Page 1, Base Address", es_error, ec_element, "<BASE> is reserved but undefined in HTML Tags");
        return; }
    if (! only_one_of (elem_base)) return;
    if (sibling_attributes_.test (a_href) != 0)
        switch (node_.version ().mjr ())
        {   case 0 :
            case 1 :
            case 2 :
            case 3 :
                break;
            case 4 :
                pick (nit_base_b4_lynx, ed_4, "12.4 Path information: the BASE element", es_error, ec_element, "<BASE> must appear before any element with a link");
                break;
            default :
                if (a_.known (a_href) || a_.known (a_target))
                    pick (nit_base_b4_lynx, ed_50, "4.2.3 The base element", es_error, ec_element, "a <BASE> with TARGET or HREF must appear before any element with a link"); }
    url u (nits (), node_.version (), a_.get_string (a_href));
    if (! u.empty ())
        if (! u.is_local ())
        {   pick (nit_element_offsite_base, es_warning, ec_element, context.filename (), " has offsite base ", quote (u.original ()), ", " PROG " is abandoning link checks");
            return; }
        else if (u.has_component (es_fragment) || u.has_component (es_query))
        {  pick (nit_element_bizarre_base, es_error, ec_element, context.filename (), " ignoring bizarre base ", quote (u.original ())); }
        else context.base (u.original ()); }

void element::examine_button ()
{   if (node_.version ().mjr () >= 5)
    {   no_anchor_daddy ();
        if (has_child ())
        {   element_bitset bs (descendant_elements_);
            bs &= interactive_bitset;
            if (bs.any ())
                pick (nit_interactive, ed_50, "4.10.6 The Button element", es_warning, ec_element, "An <BUTTON> element cannot have interactive descendant elements.");
            if (descendant_attributes_.test (a_tabindex))
                pick (nit_interactive, ed_50, "4.10.6 The Button element", es_warning, ec_element, "An <BUTTON> element cannot have a descendant element with a TABINDEX."); }
        e_button bu = static_cast < e_button > (a_.get_int (a_type));
        if (bu != bu_submit)
            if (a_.known (a_formaction) || a_.known (a_formenctype) || a_.known (a_formmethod) ||
                a_.known (a_formnovalidate) || a_.known (a_formtarget))
                pick (nit_bad_form, ed_50, "", es_error, ec_attribute, "FORM... attributes require <BUTTON> TYPE='submit'"); } }

void element::examine_col ()
{   if (node_.version ().mjr () >= 5)
        if (a_.known (a_span))
            if (a_.get_int (a_span) > 1000) pick (nit_1000, ed_50, "4.9.4 The col element", es_error, ec_element, "SPAN cannot exceed 1000"); }

void element::examine_colgroup ()
{   if (node_.version ().mjr () >= 5)
        if (a_.known (a_span))
        {   element_bitset bs (descendant_elements_);
            bs &= empty_element_bitset | elem_col | elem_template;
            if (bs.any ()) pick (nit_colgroup_children, ed_50, "4.9.3 The colgroup element", es_error, ec_element, "<COLGROUP> with SPAN cannot have child elements.");
            if (a_.get_int (a_span) > 1000) pick (nit_1000, ed_50, "4.9.3 The colgroup element", es_error, ec_element, "SPAN cannot exceed 1000"); } }

void element::examine_caption ()
{   if (node_.version ().mjr () >= 5) check_descendants (elem_caption, element_bit_set (elem_table)); }

void element::examine_datalist ()
{   if (! has_child ()) pick (nit_bad_datalist, ed_50, "4.10.8 The datalist element", es_warning, ec_element, "is the empty <DATALIST> intentional");
    else
    {   bool had_option = false, had_other = false;
        for (element_ptr p = child_; p != nullptr; p = p -> sibling_)
            if (is_standard_element (p -> tag ()) && ! p -> node_.is_closure ())
                switch (p -> tag ())
                {   case elem_option :
                        had_option = true;
                    case elem_script :
                    case elem_template :
                        break;
                    default :
                        had_other = true;
                        break; }
        if (had_other)
            if (had_option)
            {   pick (nit_bad_datalist, ed_50, "4.10.8 The datalist element", es_error, ec_element, "a <DATALIST> can have <OPTION> children, or other children, but not both"); }
            else if (! descendant_elements_.test (elem_select))
                pick (nit_bad_datalist, ed_50, "4.10.8 The datalist element", es_warning, ec_element, "a <DATALIST> without <OPTION> children should contain a <SELECT>"); } }

void element::examine_dialogue ()
{   if (a_.known (a_tabindex))
        pick (nit_bad_dialogue, ed_52, "4.11.4 The dialog element", es_error, ec_element, "<DAILOG> cannot have TABINDEX"); }

void element::examine_details ()
{   no_anchor_daddy ();
    bool first = true;
    if (has_child ())
        for (element* c = child_.get (); c != nullptr; c = c -> sibling_.get ())
            if (is_standard_element (c -> tag ()) && (! c -> node_.is_closure ()))
                if (first) first = false;
                else if (c -> tag () == elem_summary)
                {   pick (nit_details_summary, ed_51, "4.11.1. The details element", es_error, ec_element, "<SUMMARY> can only be the first child of <DETAILS>");
                    break; } }

void element::examine_dd ()
{   if (node_.version ().mjr () >= 5)
    {   element_bitset bs (ancestral_elements_);
        bs &= elem_dl;
        if (! bs.any ()) pick (nit_dl_ancestor, ed_52, "4.4.11. The dd element", es_error, ec_element, "<DD> must have a <DL> ancestor."); } }

void element::examine_dfn ()
{   if (node_.version ().mjr () >= 5) check_ancestors (elem_dfn, element_bit_set (elem_dfn)); }

void element::examine_div ()
{   if (has_child () && (node_.version ().mjr () >= 5) && (w3_minor_5 (node_.version ()) >= 2))
    {   bool dt = false;
        if (parent_ -> tag () == elem_dl)
            for (element* c = child_.get (); c != nullptr; c = c -> sibling_.get ())
                if (is_standard_element (c -> tag ()) && ! c -> node_.is_closure ())
                    switch (c -> tag ())
                    {   case elem_dt :
                            dt = true;
                            break;
                        case elem_dd :
                            if (! dt) pick (nit_no_dd, ed_50, "4.4.8. The dl element", es_error, ec_element, "<DD> element must be preceded by <DT>");
                            break;
                        case elem_script :
                        case elem_template :
                            break;
                        default :
                            pick (nit_dt_dd, ed_52, "4.4.15. The div element", es_error, ec_element, "when a <DIV> is a child of <DL>, it can only have <DD> and <DT> children");
                            break; } } }

void element::examine_dl ()
{   bool dtdd = false, dt = false, div = false;
    if (has_child () && (node_.version ().mjr () >= 5))
        for (element* c = child_.get (); c != nullptr; c = c -> sibling_.get ())
            switch (c -> tag ())
            {   case elem_div :
                    if (w3_minor_5 (node_.version ()) < 2) break;
                    if (dtdd) pick (nit_dl_div, ed_52, "4.4.9. The dl element", es_error, ec_element, "<DL> can have <DT>/<DD> children, or <DIV> children, but not both");
                    else div = true;
                    break;
                case elem_dt :
                    dt = true;
                    if (w3_minor_5 (node_.version ()) < 2) break;
                    if (div) pick (nit_dl_div, ed_52, "4.4.9. The dl element", es_error, ec_element, "<DL> can have <DT>/<DD> children, or <DIV> children, but not both");
                    else dtdd = true;
                    break;
                case elem_dd :
                    if (! dt) pick (nit_no_dd, ed_50, "4.4.8. The dl element", es_error, ec_element, "<DD> must be preceded by <DT>");
                    if (w3_minor_5 (node_.version ()) < 2) break;
                    if (div) pick (nit_dl_div, ed_52, "4.4.9. The dl element", es_error, ec_element, "<DL> can have <DT>/<DD> children, or <DIV> children, but not both");
                    else dtdd = true;
                    break;
                default :
                    break; } }

void element::examine_dt ()
{   if (node_.version ().mjr () >= 5)
    {   element_bitset bs (ancestral_elements_);
        bs &= elem_dl;
        if (! bs.any ()) pick (nit_dl_ancestor, ed_52, "4.4.10. The dt element", es_error, ec_element, "<DT> must have a <DL> ancestor.");
        check_descendants (elem_dt, header_bitset | sectioning_bitset | elem_header | elem_footer); } }
