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

#pragma once
#include "type/type_master.h"
#include "type/sz.h"

template < e_type TYPE, typename base_type, class SZ0, class SZ1, class SZ2, class SZ3 > class four_value : public type_base < base_type, TYPE >
{   base_type value_ = static_cast < base_type > (0);
public:
    typedef true_type has_int_type;
    ::std::string get_string () const;
    void shadow (::std::stringstream& ss, const html_version& )
    {   ss << '=' << get_string (); }
    void set_value (nitpick& nits, const html_version& v, const ::std::string& s);
    void swap (four_value& t) NOEXCEPT { ::std::swap (value_, t.value_); type_base < base_type, TYPE >::swap (t); }
    static base_type default_value () { return static_cast <base_type> (0); }
    base_type get () const { return value_; }
    int get_int () const { return static_cast < int > (value_); }
    ::std::size_t type () const { return static_cast < ::std::size_t > (get ()); }
    bool has_value (const base_type& b) const { return type_base < base_type, TYPE > :: good () && (value_ == b); } };

// typedef enum { at_toggle, at_statusline, at_tooltip, at_highlight } e_actiontype;
template < > class type_master < t_actiontype2 > : public four_value < t_actiontype2, e_actiontype, sz_toggle, sz_statusline, sz_tooltip, sz_highlight > { };
template < > class type_master < t_align2070 > : public four_value < t_align2070, e_align2070, sz_centre, sz_justify, sz_left, sz_right > { };
template < > class type_master < t_aligndec > : public four_value < t_aligndec, e_aligndec, sz_centre, sz_decimal, sz_left, sz_right > { };
template < > class type_master < t_alignfig > : public four_value < t_alignfig, e_alignfig, sz_centre, sz_float, sz_left, sz_right > { };
template < > class type_master < t_arabicform > : public four_value < t_arabicform, e_arabicform, sz_initial, sz_medial, sz_terminal, sz_isolated > { };
template < > class type_master < t_aria_autocomplete > : public four_value < t_aria_autocomplete, e_aria_autocomplete, sz_both, sz_inline, sz_list, sz_none > { };
template < > class type_master < t_aria_invalidity > : public four_value < t_aria_invalidity, e_aria_invalidity, sz_false, sz_grammar, sz_spelling, sz_true > { };
template < > class type_master < t_baselineshift > : public four_value < t_baselineshift, e_baselineshift, sz_baseline, sz_sub, sz_super, sz_inherit > { };
template < > class type_master < t_calcmode > : public four_value < t_calcmode, e_calcmode, sz_discrete, sz_linear, sz_paced, sz_spline > { };
template < > class type_master < t_captionalign > : public four_value < t_captionalign, e_captionalign, sz_bottom, sz_left, sz_right, sz_top > { };
template < > class type_master < t_channel_selector > : public four_value < t_channel_selector, e_channel_selector, sz_a, sz_b, sz_g, sz_r > { };
template < > class type_master < t_colourinterpolation > : public four_value < t_colourinterpolation, e_colourinterpolation, sz_auto, sz_srgb, sz_linearrgb, sz_inherit > { };
template < > class type_master < t_colourrendering > : public four_value < t_colourrendering, e_colourrendering, sz_auto, sz_optimisespeed, sz_optimisequality, sz_inherit > { };
template < > class type_master < t_content_encoding > : public four_value < t_content_encoding, e_content_encoding, sz_gzip, sz_compress, sz_deflate, sz_identity > { };
template < > class type_master < t_uplr > : public four_value < t_uplr, e_uplr, sz_down, sz_left, sz_right, sz_up > { };
template < > class type_master < t_dsctv > : public four_value < t_dsctv, e_dsctv, sz_disc, sz_square, sz_circle, sz_triangle > { };
template < > class type_master < t_edit > : public four_value < t_edit, e_edit, sz_changed, sz_deleted, sz_inserted, sz_moved > { };
template < > class type_master < t_effect > : public four_value < t_effect, e_effect, sz_embed, sz_overlay, sz_replace, sz_new > { };
template < > class type_master < t_frame4 > : public four_value < t_frame4, e_frame4, sz__blank, sz__parent, sz__self, sz__top > { };
template < > class type_master < t_imagerendering > : public four_value < t_imagerendering, e_imagerendering, sz_auto, sz_optimisespeed, sz_optimisequality, sz_inherit > { };
template < > class type_master < t_larnalign > : public four_value < t_larnalign, e_larnalign, sz_left, sz_all, sz_right, sz_none > { };
template < > class type_master < t_lcrnalign > : public four_value < t_lcrnalign, e_lcrnalign, sz_left, sz_centre, sz_right, sz_none > { };
template < > class type_master < t_lcrd > : public four_value < t_lcrd, e_lcrd, sz_left, sz_centre, sz_right, sz_decimalpoint > { };
template < > class type_master < t_linebreakstyle > : public four_value < t_linebreakstyle, e_linebreakstyle, sz_before, sz_after, sz_duplicate, sz_infixlinebreakstyle > { };
template < > class type_master < t_linecap > : public four_value < t_linecap, e_linecap, sz_butt, sz_round, sz_square, sz_inherit > { };
template < > class type_master < t_linejoin > : public four_value < t_linejoin, e_linejoin, sz_miter, sz_round, sz_bevel, sz_inherit > { };
template < > class type_master < t_mathclosure > : public four_value < t_mathclosure, e_mathclosure, sz_open, sz_closed, sz_openclosed, sz_closedopen > { };
template < > class type_master < t_phase > : public four_value < t_phase, e_phase, sz_bubble, sz_capture, sz_default, sz_target > { };
template < > class type_master < t_rsvp > : public four_value < t_rsvp, e_rsvp, sz_yes, sz_no, sz_maybe, sz_interested > { };
template < > class type_master < t_tdscope > : public four_value < t_tdscope, e_tdscope, sz_row, sz_col, sz_rowgroup, sz_colgroup > { };
template < > class type_master < t_shape4 > : public four_value < t_shape4, e_shape4, sz_circle, sz_default, sz_poly, sz_rect > { };
template < > class type_master < t_size3 > : public four_value < t_size3, e_size3, sz_normal, sz_medium, sz_large, sz_huge > { };
template < > class type_master < t_side > : public four_value < t_side, e_side, sz_left, sz_right, sz_leftoverlap, sz_rightoverlap > { };
template < > class type_master < t_smei > : public four_value < t_smei, e_smei, sz_start, sz_middle, sz_end, sz_inherit > { };
template < > class type_master < t_ssi_config > : public four_value < t_ssi_config, e_ssi_config, sz_echomsg, sz_errmsg, sz_sizefmt, sz_timefmt > { };
template < > class type_master < t_ssi_set > : public four_value < t_ssi_set, e_ssi_set, sz_decoding, sz_encoding, sz_value, sz_var > { };
template < > class type_master < t_svg_baseprofile > : public four_value < t_svg_baseprofile, e_svg_baseprofile, sz_basic, sz_full, sz_none, sz_tiny > { };
template < > class type_master < t_svg_fontstyle > : public four_value < t_svg_fontstyle, e_svg_fontstyle, sz_normal, sz_italic, sz_oblique, sz_inherit > { };
template < > class type_master < t_svg_type > : public four_value < t_svg_type, e_svg_type, sz_gamma, sz_identity, sz_linear, sz_table > { };
template < > class type_master < t_tfmu > : public four_value < t_tfmu, e_tfmu, sz_false, sz_mixed, sz_true, sz_undefined > { };
template < > class type_master < t_unicodebidi > : public four_value < t_unicodebidi, e_unicodebidi, sz_normal, sz_embed, sz_bidioverride, sz_inherit > { };
template < > class type_master < t_valign3 > : public four_value < t_valign3, e_valign3, sz_top, sz_middle, sz_bottom, sz_baseline > { };
template < > class type_master < t_visibility > : public four_value < t_visibility, e_visibility, sz_visible, sz_hidden, sz_collapse, sz_inherit > { };

template < e_type TYPE, typename base_type, class SZ0, class SZ1, class SZ2, class SZ3 >
    ::std::string four_value < TYPE, base_type, SZ0, SZ1, SZ2, SZ3 > :: get_string () const
{   if (! type_base < base_type, TYPE > :: unknown ())
        switch (static_cast <int> (value_))
        {   case 0 : return SZ0::sz ();
            case 1 : return SZ1::sz ();
            case 2 : return SZ2::sz ();
            case 3 : return SZ3::sz ();
            default : break; }
    return ::std::string (); }

template < e_type TYPE, typename base_type, class SZ0, class SZ1, class SZ2, class SZ3 >
    void four_value < TYPE, base_type, SZ0, SZ1, SZ2, SZ3 > :: set_value (nitpick& nits, const html_version& v, const ::std::string& s)
{   ::std::string t (trim_the_lot_off (s));
    if (v.xhtml () && ! v.svg () && (t.find_first_of (UPPERCASE) != ::std::string::npos))
        nits.pick (nit_xhtml_enum_lc, ed_x1, "4.11. Attributes with pre-defined value sets", es_warning, ec_type, "enumerations must be lower cased in ", v.report ());
    ::boost::to_lower (t);
    type_base < base_type, TYPE > :: status (s_good);
    if (t == SZ0::sz ()) value_ = static_cast <base_type> (0);
    else if (t == SZ1::sz ()) value_ = static_cast <base_type> (1);
    else if (t == SZ2::sz ()) value_ = static_cast <base_type> (2);
    else if (t == SZ3::sz ()) value_ = static_cast <base_type> (3);
    else
    {   if (! check_spelling (nits, v, t))
            if (t.empty ()) nits.pick (nit_empty, es_error, ec_type, "attribute cannot have an empty value");
            else nits.pick (nit_unrecognised_value, es_error, ec_type, quote (t), " is invalid; it can be \"", SZ0::sz (), "\", \"", SZ1::sz (), "\", \"", SZ2::sz (), "\", or \"", SZ3::sz (), "\"");
        type_base < base_type, TYPE > :: status (s_invalid); } }
