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

#pragma once
#include "type/type_master.h"
#include "type/type_case.h"

template < bool EMPTY > struct is_that
{    static bool beside_the_point (const ::std::string& ) { return false; } };

template < > struct is_that < true >
{    static bool beside_the_point (const ::std::string& t) { return t.empty (); } };

template < e_type TYPE, typename base_type, class OFF, class ON, bool EMPTY > class two_value : public type_base < base_type, TYPE >, public is_that < EMPTY >
{   bool true_ = false;
    static ::std::string off_, on_;
public:
    typedef true_type has_int_type;
    two_value () = default;
    ::std::string get_string () const
    {   if (! type_base < base_type, TYPE > :: unknown ())
            if (true_) return ON::sz (); else return OFF::sz ();
        return ::std::string (); }
    void shadow (::std::stringstream& ss, const html_version& , element* )
    {   ss << '=' << get_string (); }
    void set_value (nitpick& nits, const html_version& v, const ::std::string& s)
    {   ::std::string pret (trim_the_lot_off (s));
        ::std::string t (case_must_match < false >::lower (pret));
        type_base < base_type, TYPE > :: status (s_good);
        if (is_that < EMPTY > :: beside_the_point (t)) return;
        if (off_.empty ())
        {   off_ = ::boost::to_lower_copy (::std::string (OFF::sz ()));
            on_ =  ::boost::to_lower_copy (::std::string (ON::sz ())); }
        if (t == off_) true_ = false;
        else if (t == on_) true_ = true;
        else
        {   if (t.empty ()) nits.pick (nit_empty, es_error, ec_type, "attribute cannot have an empty value");
            else nits.pick (nit_unrecognised_value, es_error, ec_type, quote (pret), " is invalid; it can be \"", OFF::sz (), "\" or \"", ON::sz (), "\"");
            type_base < base_type, TYPE > :: status (s_invalid);
            return; }
        compare_validate (nits, v, get_string (), pret); }
    void swap (two_value& t) NOEXCEPT
    {   ::std::swap (true_, t.true_);
        type_base < base_type, TYPE > :: swap (t); }
    static bool default_value () { return false; }
    bool has_value (const base_type& b) const { return type_base < base_type, TYPE > :: good () && ((b != static_cast < base_type> (0)) == true_); }
    base_type get () const
    {   return static_cast < base_type > (true_); }
    int get_int () const { return true_ ? 1 : 0; }
    ::std::size_t type () const { return static_cast < ::std::size_t > (get ()); } };

template < e_type TYPE, typename base_type, class OFF, class ON, bool EMPTY >
    ::std::string two_value < TYPE, base_type, OFF, ON, EMPTY > :: off_;
template < e_type TYPE, typename base_type, class OFF, class ON, bool EMPTY >
    ::std::string two_value < TYPE, base_type, OFF, ON, EMPTY > :: on_;

template < > struct type_master < t_10 > : two_value < t_10, e_10, sz_0, sz_1, false > { };
template < > struct type_master < t_accumulate > : two_value < t_accumulate, e_accumulate, sz_none, sz_sum, false > { };
template < > struct type_master < t_actuate > : two_value < t_actuate, e_actuate, sz_auto, sz_user, false > { };
template < > struct type_master < t_additive > : two_value < t_additive, e_additive, sz_replace, sz_sum, false > { };
template < > struct type_master < t_bool > : two_value < t_bool, e_bool, sz_false, sz_true, false > { };
template < > struct type_master < t_capture > : two_value < t_capture, ev_capture, sz_user, sz_environment, false > { };
template < > struct type_master < t_coordinatesystem > : two_value < t_coordinatesystem, e_gradientunits, sz_userspaceonuse, sz_objectboundingbox, false > { };
template < > struct type_master < t_cors > : two_value < t_cors, ev_cors, sz_anonymous, sz_use_credentials, false > { };
template < > struct type_master < t_dataformatas > : two_value < t_dataformatas, e_dataformatas, sz_html, sz_plaintext, false > { };
template < > struct type_master < t_defaultaction > : two_value < t_defaultaction, e_defaultaction, sz_cancel, sz_perform, false > { };
template < > struct type_master < t_editable > : two_value < t_editable, e_editable, sz_none, sz_simple, false > { };
template < > struct type_master < t_fillanim > : two_value < t_fillanim, e_fillanim, sz_freeze, sz_remove, false > { };
template < > struct type_master < t_focushighlight > : two_value < t_focushighlight, e_focushighlight, sz_auto, sz_none, false > { };
template < > struct type_master < t_hv > : two_value < t_hv, e_hv, sz_horizontal, sz_vertical, false > { };
template < > struct type_master < t_initialvisibility > : two_value < t_initialvisibility, e_initialvisibility, sz_whenstarted, sz_always, false > { };
template < > struct type_master < t_layout > : two_value < t_layout, e_layout, sz_irrelevant, sz_relevant, false > { };
template < > struct type_master < t_lengthadjust > : two_value < t_lengthadjust, e_lengthadjust, sz_spacing, sz_spacingandglyphs, false > { };
template < > struct type_master < t_loading > : two_value < t_loading, e_loading, sz_eager, sz_lazy, false > { };
template < > struct type_master < t_lralign > : two_value < t_lralign, e_lralign, sz_left, sz_right, false > { };
template < > struct type_master < t_meetslice > : two_value < t_meetslice, e_meetslice, sz_meet, sz_slice, false > { };
template < > struct type_master < t_markerunits > : two_value < t_markerunits, e_markerunits, sz_strokewidth, sz_userspaceonuse, false > { };
template < > struct type_master < t_mathfontstyle > : two_value < t_mathfontstyle, e_fontstyle, sz_italic, sz_normal, false > { };
template < > struct type_master < t_mathfontweight > : two_value < t_mathfontweight, e_math_fontweight, sz_bold, sz_normal, false > { };
template < > struct type_master < t_morphology_operator > : two_value < t_morphology_operator, e_morphology_operator, sz_dilate, sz_erode, false > { };
template < > struct type_master < t_mathdisplay > : two_value < t_mathdisplay, e_mathdisplay, sz_block, sz_inline, false > { };
template < > struct type_master < t_mathmode > : two_value < t_mathmode, e_mode, sz_display, sz_inline, false > { };
template < > struct type_master < t_mathorder > : two_value < t_mathorder, m_mathorder, sz_numeric, sz_lexicographic, false > { };
template < > struct type_master < t_mathscope > : two_value < t_mathscope, e_mathscope, sz_global, sz_local, false > { };
template < > struct type_master < t_notations > : two_value < t_notations, e_notations, sz_dsssl, sz_w3c, false > { };
template < > struct type_master < t_onoff > : two_value < t_onoff, e_onoff, sz_off, sz_on, false > { };
template < > struct type_master < t_orientation > : two_value < t_orientation, e_orientation, sz_h, sz_v, false > { };
template < > struct type_master < t_overlay > : two_value < t_overlay, e_overlay, sz_none, sz_top, false > { };
template < > struct type_master < t_propagate > : two_value < t_propagate, e_propagate, sz_stop, sz_continue, false > { };
template < > struct type_master < t_settype > : two_value < t_settype, e_settype, sz_normal, sz_multiset, false > { };
template < > struct type_master < t_show > : two_value < t_show, e_show, sz_embed, sz_replace, false > { };
template < > struct type_master < t_spacing > : two_value < t_spacing, e_spacing, sz_auto, sz_exact, false > { };
template < > struct type_master < t_ssi_sizefmt > : two_value < t_ssi_sizefmt, e_ssi_sizefmt, sz_abbrev, sz_bytes, false > { };
template < > struct type_master < t_ssi_f > : two_value < t_ssi_f, e_ssi_f, sz_file, sz_virtual, false > { };
template < > struct type_master < t_stitchtiles > : two_value < t_stitchtiles, e_stitchtiles, sz_stitch, sz_nostitch, false > { };
template < > struct type_master < t_svg_direction2 > : two_value < t_svg_direction2, e_svg_direction2, sz_ltr, sz_rtl, false > { };
template < > struct type_master < t_svg_fontvariant_ff > : two_value < t_svg_fontvariant_ff, e_svg_fontvariant_ff, sz_normal, sz_smallcaps, false > { };
template < > struct type_master < t_svg_method > : two_value < t_svg_method, e_svg_method, sz_align, sz_stretch, false > { };
template < > struct type_master < t_svg_phase > : two_value < t_svg_phase, e_svg_phase, sz_default, sz_capture, false > { };
template < > struct type_master < t_svg_playbackorder > : two_value < t_svg_playbackorder, e_svg_playbackorder, sz_all, sz_forwardonly, false > { };
template < > struct type_master < t_svg_side > : two_value < t_svg_side, e_svg_side, sz_left, sz_right, false > { };
template < > struct type_master < t_svg_timelinebegin > : two_value < t_svg_timelinebegin, e_svg_timelinebegin, sz_onload, sz_onstart, false > { };
template < > struct type_master < t_svg_units > : two_value < t_svg_units, e_svg_units, sz_object_bbox, sz_userspace, false > { };
template < > struct type_master < t_tbalign > : two_value < t_tbalign, e_tbalign, sz_bottom, sz_top, false > { };
template < > struct type_master < t_transp > : two_value < t_transp, e_transp, sz_opaque, sz_transparent, false > { };
template < > struct type_master < t_truefalseempty > : two_value < t_truefalseempty, e_bool, sz_false, sz_true, true > { };
template < > struct type_master < t_workertype > : two_value < t_workertype, e_workertype, sz_classic, sz_module, false > { };
template < > struct type_master < t_wrap > : two_value < t_wrap, e_wrap, sz_soft, sz_hard, false > { };
template < > struct type_master < t_wrap3 > : two_value < t_wrap3, e_wrap3, sz_horiz, sz_vert, false > { };
template < > struct type_master < t_xlinkshow_a > : two_value < t_xlinkshow_a, e_xlinkshow_a, sz_new, sz_replace, false > { };
template < > struct type_master < t_xmlspace > : two_value < t_xmlspace, e_xmlspace, sz_default, sz_preserve, false > { };
template < > struct type_master < t_xorder > : two_value < t_xorder, e_xorder, sz_document, sz_list, false > { };
template < > struct type_master < t_yesno > : two_value < t_yesno, e_yesno, sz_no, sz_yes, false > { };
template < > struct type_master < t_yesnoempty > : two_value < t_yesnoempty, e_yesno, sz_no, sz_yes, true > { };
template < > struct type_master < t_zoompan > : two_value < t_zoompan, e_zoompan, sz_disable, sz_magnify, false > { };
