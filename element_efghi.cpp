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

#include "standard.h"
#include "element.h"
#include "page.h"
#include "attribute_classes.h"

void element::examine_embed ()
{   if (node_.version ().major () < 5) return;
    no_anchor_daddy ();
    if (a_.known (a_itemprop) && ! a_.known (a_src))
        pick (nit_bad_embed, ed_July2020, "4.8.6 The embed element", es_error, ec_attribute, "SRC is required when ITEMPROP is used on <EMBED>"); }

void element::examine_fecolourmatrix ()
{   e_matrix_type mt = mt_matrix;
    if (a_.known (a_type)) mt = static_cast < e_matrix_type > (a_.get_int (a_type));
    bool vals = a_.known (a_values);
    if (mt == mt_luminance_alpha)
    {   if (vals) pick (nit_colour_matrix, ed_svg_1_1, "15.10 Filter primitive feColorMatrix", es_warning, ec_attribute, "when TYPE is luminance-alpha, VALUES should be omitted");
        return; }
    if (! vals)
    {   pick (nit_colour_matrix, ed_svg_1_1, "15.10 Filter primitive feColorMatrix", es_error, ec_attribute, "unless TYPE is luminance-alpha, VALUES is required");
        return; }
    switch (mt)
    {   case mt_matrix :
            test_value < t_matrix_values > (node_.nits (), page_.version (), a_.get_string (a_values));
            break;
        case mt_saturate :
            test_value < t_normalised > (node_.nits (), page_.version (), a_.get_string (a_values));
            break;
        case mt_hue_rotate :
            test_value < t_angle > (node_.nits (), page_.version (), a_.get_string (a_values));
            break;
        default :
            assert (false);
            break; } }

void element::examine_felighting ()
{   int cc = 0;
    if (has_child ())
        for (element* c = child_.get (); c != nullptr; c = c -> sibling_.get ())
            switch (c -> tag ())
            {   case elem_fedistantlight :
                case elem_fepointlight :
                case elem_fespotlight : ++cc; break;
                default : break; }
    if (cc == 0) pick (nit_lighting, ed_svg_1_1, "15.14 / 15.22 Filter primitive lighting", es_error, ec_element, "Both <FEDIFFUSELIGHTING> and <FESPECULARLIGHTING> must have a child light source element");
    else if (cc > 1) pick (nit_lighting, ed_svg_1_1, "15.14 / 15.22 Filter primitive lighting", es_error, ec_element, "Both <FEDIFFUSELIGHTING> and <FESPECULARLIGHTING> can only have ONE child light source element"); }

void element::examine_fieldset ()
{   bool first = true;
    if (has_child ())
        for (element* c = child_.get (); c != nullptr; c = c -> sibling_.get ())
            if (is_standard_element (c -> tag ()) && (! c -> node_.is_closure ()))
                if (first) first = false;
                else if (c -> tag () == elem_legend)
                {   pick (nit_fieldset_legend, ed_50, "4.10.16 The fieldset element", es_error, ec_element, "<LEGEND> can only be the first child of <FIELDSET>");
                    break; } };

void element::examine_figcaption ()
{   if ((node_.version ().major () >= 5) && (w3_minor_5 (node_.version ()) == 0))
        if (node_.has_previous () && node_.has_next ())
            pick (nit_figcaption_middle, ed_50, "4.4.12 The figcaption element", es_error, ec_element, "<FIGCAPTION> must be the first or last child of <FIGURE>"); }

void element::examine_figure ()
{   bool had_figcaption = false, first = true, last_was_fig = false;
    if (has_child () && (node_.version ().major () >= 5))
        if ((w3_minor_5 (node_.version ()) == 0) || (w3_minor_5 (node_.version ()) == 4))
            for (element* c = child_.get (); c != nullptr; c = c -> sibling_.get ())
            {   e_element tag = c -> node_.tag ();
                if (is_standard_element (tag) && ! c -> node_.is_closure ())
                {   if (tag != elem_figcaption)
                    {   if (last_was_fig)
                            pick (nit_figcaption_first_last, ed_50, "4.4.11 The figure element", es_error, ec_element, "<FIGCAPTION> must be the first or last child of <FIGURE>");
                        last_was_fig = false; }
                    else if (had_figcaption)
                        pick (nit_too_many_figcaption, ed_50, "4.4.11 The figure element", es_error, ec_element, "<FIGURE> can only have one child <FIGCAPTION>");
                    else
                    {   had_figcaption = true;
                        if (! first) last_was_fig = true;  }
                    first = false; } } }

void element::examine_filter ()
{   if (node_.version ().svg () >= sv_1_1)
        examine_descendant_in (this); }

void element::examine_fontymacfontface ()
{   bool had = false;
    if (has_child ())
        for (element* c = child_.get (); c != nullptr; c = c -> sibling_.get ())
            if (c -> tag () == elem_fontfacesrc)
                if (! had) had = true;
                else
                {   pick (nit_animatemotion, ed_svg_1_1, "20.8.3 The font-face element", es_error, ec_element, "<FONTY-MacFONT-FACE> can only have ONE child <FONT-FACE-SRC>");
                    return; } }

void element::examine_footer ()
{   if (node_.version ().major () >= 5)
    {   check_ancestors (elem_footer, empty_element_bitset | elem_address | elem_footer | elem_header | elem_dt);
        check_descendants (elem_footer, empty_element_bitset | elem_main);
        if (w3_minor_5 (node_.version ()) == 0)
            check_descendants (elem_footer, empty_element_bitset | elem_header | elem_footer); } }

void element::examine_form ()
{   switch (node_.version ().major ())
    {   case 0 :
        case 1 :
        case 3 :
        case 4 : break;
        case 2 :
            if (node_.version ().strict ())
                pick (nit_no_form, es_error, ec_element, "<FORM> should not appear in ", node_.version ().report (), " documents");
            break;
        default :
        {   check_ancestors (elem_form, element_bit_set (elem_form));
            if ((w3_minor_5 (node_.version ()) > 3) && a_.good (a_acceptcharset))
            {   auto v = a_.get_x < attr_acceptcharset > ();
                if (v.size () != 1) pick (nit_form_charset, ed_July2020, "4.10.3 The form element", es_error, ec_attribute, "CHARSET, if supplied, must be the single value 'utf-8'");
                else
                {   auto cs = v.at (0);
                    if (cs != cs_utf_8) pick (nit_form_charset, ed_July2020, "4.10.3 The form element", es_error, ec_attribute, "CHARSET, if supplied, must be set to 'utf-8'"); } }
            if (! radio_kids_.empty ())
            {   msid_t names;
                for (auto rk : radio_kids_)
                {   ::std::string n (rk -> a_.get_string (a_name));
                    auto i = names.find (n);
                    if (i == names.cend ()) names.emplace (msid_t::value_type (n, 1));
                    else i -> second += 1; }
                for (auto rk : radio_kids_)
                {   ::std::string n (rk -> a_.get_string (a_name));
                    auto i = names.find (n);
                    assert (i != names.cend ());
                    if (i -> second == 1)
                        if (n.empty ())
                            rk -> pick (nit_lonely_radio, ed_50, "4.10.5.1.13 Radio Button state", es_error, ec_element, "radio buttons require company; there should be multiple unnamed <INPUT> TYPE=radio");
                        else
                            rk -> pick (nit_lonely_radio, ed_50, "4.10.5.1.13 Radio Button state", es_error, ec_element, "radio buttons require company; there must be multiple <INPUT> TYPE=radio with NAME ", quote (n)); } } } } }

void element::examine_h123456 ()
{   if (node_.version ().major () >= 5)
        check_ancestors (tag (), empty_element_bitset | elem_address | elem_dt); }

void element::examine_header ()
{   if (node_.version ().major () >= 5)
    {   check_ancestors (elem_header, empty_element_bitset | elem_address | elem_footer | elem_header | elem_dt);
        check_descendants (elem_header, empty_element_bitset | elem_main);
        if (w3_minor_5 (node_.version ()) == 0)
            check_descendants (elem_header, empty_element_bitset | elem_header | elem_footer); } }

void element::examine_html ()
{   if (node_.version () == html_plus)
        pick (nit_use_htmlplus, es_error, ec_element, "HTML+ uses the <HTMLPLUS> element, not <HTML>");
    else
    {   only_one_of (elem_html);
        if (node_.version ().major () >= 5)
        {   if (! a_.known (a_lang) && ! a_.known (a_xmllang))
                pick (nit_naughty_lang, ed_50, "4.1.1 The html element", es_warning, ec_attribute, "use LANG to specify a default language");
            if (w3_minor_5 (node_.version ()) >= 2)
                if (a_.known (a_manifest))
                    pick (nit_avoid_manifest, ed_52, "4.1.1 The html element", es_warning, ec_attribute, "MANIFEST is deprecated & should be avoided because application caches are doomed"); } } }

void element::examine_iframe ()
{   if (node_.version ().major () < 5) return;
    no_anchor_daddy ();
    if (a_.known (a_itemprop) && ! a_.known (a_src))
        pick (nit_bad_iframe, ed_July2020, "4.8.5 The iframe element", es_error, ec_attribute, "SRC is required when ITEMPROP is used with <IFRAME>");
    if (! a_.known (a_srcdoc) && ! a_.known (a_src))
        pick (nit_chocolate_teapot, es_info, ec_attribute, "Not sure what use <IFRAME> is without SRC or SRCDOC"); }

void element::examine_img ()
{   check_required_type (elem_img);
    if (a_.known (a_usemap)) no_anchor_daddy ();
    if ((node_.version ().major () >= 5) && (w3_minor_5 (node_.version ()) > 0))
        if (! ancestral_elements_.test (elem_figure))
            if (! a_.known (a_alt) || a_.get_string (a_alt).empty ())
                if (! a_.known (a_title))
                    pick (nit_naughty_alt, ed_51, "4.7.5.1.2. General guidelines", es_warning, ec_element, "generally, ALT should not be empty");
    if ((node_.version ().major () >= 4) && a_.known (a_alt) && a_.known (a_title))
        if (compare_no_case (a_.get_string (a_alt), a_.get_string (a_title)))
            pick (nit_alt_title, ed_51, "4.7.5.1.2. General guidelines", es_warning, ec_element, "ALT and TITLE must have different values"); }
