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
#include "type/type_enum.h"

template < typename TYPE, e_type E, typename CATEGORY = e_namespace, CATEGORY INIT = ns_default >
    struct enum_vec_base : public type_base < TYPE, E >
{   typedef enum_n < E, TYPE, CATEGORY, INIT > base_t;
    typedef ::std::vector < base_t > vec_t;
    typedef TYPE base_type;
    typedef vec_t value_type;
    vec_t value_;
    ::std::string original_;
    enum_vec_base () = default;
    enum_vec_base (const enum_vec_base& s) = default;
#ifndef NO_MOVE_CONSTRUCTOR
    enum_vec_base (enum_vec_base&&) = default;
#endif
    explicit enum_vec_base (const html_version& v, const ::std::string& s);
    enum_vec_base& operator = (const enum_vec_base&) = default;
#ifndef NO_MOVE_CONSTRUCTOR
    enum_vec_base& operator = (enum_vec_base&&) = default;
#endif
    ~enum_vec_base () = default;
    static ::std::string values (const html_version& ) { return ::std::string (); }
    static ::std::size_t value_count () { return 0; }
    void swap (enum_vec_base& t) NOEXCEPT;
    ::std::string get_string () const { return ::std::string (); }
    ::std::string name () const { return ::std::string (); }
    static ::std::string name (const TYPE ) { return ::std::string (); }
    ::std::string original () const { return original_; }
    void set_value (nitpick& nits, const html_version& v, const ::std::string& s);
    static vec_t default_value () { return vec_t (); }
    ::std::size_t size () const { return value_.size (); }
    bool has_value (const base_type& b) const
    {   if (! type_base < TYPE, E > :: good ()) return false;
        return (value_.find (b) != vec_t::npos); }
    void shadow (::std::stringstream& ss, const html_version& , element* )
    {   ss << "=\""; bool first = true;
        for (auto e : value_)
        {   if (! first) ss << ' ';
            first = false;
            ss << e.get_string (); }
        ss << '"'; }
    vec_t get () const { return value_; } };

template < typename TYPE, e_type E, typename CATEGORY, CATEGORY INIT >
    enum_vec_base < TYPE, E, CATEGORY, INIT > :: enum_vec_base (const html_version& v, const ::std::string& s)
{   enum_vec_base < TYPE, E > e;
    e.set_value (v, s);
    if (e.good ()) swap (e); }

template < typename TYPE, e_type E, typename CATEGORY, CATEGORY INIT >
    void enum_vec_base < TYPE, E, CATEGORY, INIT > :: swap (enum_vec_base& t) NOEXCEPT
{   ::std::swap (value_, t.value_);
    original_.swap (t.original_);
    type_base < TYPE, E >::swap (t); }

template < typename TYPE, e_type E, typename CATEGORY, CATEGORY INIT >
    void enum_vec_base < TYPE, E, CATEGORY, INIT > :: set_value (nitpick& nits, const html_version& , const ::std::string& s)
{   original_ = s;
    nits.pick (nit_missing_set_value, es_error, ec_type, "Internal error: an enum vector is missing setvalue");
    type_base < TYPE, E > :: status (s_invalid); }

template < e_type E, typename ENUM, typename CATEGORY = e_namespace, CATEGORY INIT = ns_default >
    struct enum_vec : public enum_vec_base < ENUM, E, CATEGORY, INIT >
{   enum_vec () = default;
    enum_vec (const enum_vec& ) = default;
#ifndef NO_MOVE_CONSTRUCTOR
    enum_vec (enum_vec&& ) = default;
#endif
    ~enum_vec () = default;
    enum_vec& operator = (const enum_vec& ) = default;
#ifndef NO_MOVE_CONSTRUCTOR
    enum_vec& operator = (enum_vec&& ) = default;
#endif
    void swap (enum_vec& n)
    {   enum_vec_base < ENUM, E, CATEGORY, INIT > :: swap (n); }
    void reset ()
    {   enum_vec tmp;
        swap (tmp); }
    void reset (const enum_vec& n)
    {   enum_vec tmp (n);
        swap (tmp); }
    static void init (nitpick& nits, const symbol_entry < html_version, ENUM, CATEGORY, INIT > table [], const ::std::size_t size, const bool wildcards = false)
    {   symbol < html_version, ENUM, CATEGORY, INIT > :: init (nits, table, size, wildcards); }
    static void extend (const vstr_t& extension, const std::size_t s = 0)
    {   for (auto e : extension)
            symbol < html_version, ENUM, CATEGORY, INIT > :: extend (e, static_cast < ENUM > (s)); }
    ::std::string values (const html_version& v) const
    {   return symbol < html_version, ENUM, CATEGORY, INIT > :: value_list (v); }
    ::std::string get_string () const
    {   ::std::string res;
        for (auto e : enum_vec_base < ENUM, E, CATEGORY, INIT > :: value_)
        {   if (! res.empty ()) res += " ";
            if (e.good ())
            {   ::std::string s (e.get_string ());
                if (s.empty ()) s = e.original ();
                res += s; } }
        return res; }
    void set_value (nitpick& nits, const html_version& v, const ::std::string& ss);
    ::std::string name () const
    {   return get_string (); }
    static ::std::string name (const ENUM e)
    {   return symbol < html_version, ENUM, CATEGORY, INIT > :: name (e); }
    void shadow (::std::stringstream& ss, const html_version& , element* )
    {   bool bitten = false;
        ss << "=\"";
        for (auto e : enum_vec_base < ENUM, E, CATEGORY, INIT > :: value_)
            if (! e.empty ())
            {   ::std::string s (e.get_string ());
                if (s.empty ()) s = e.original ();
                if (! s.empty ())
                {   if (bitten) ss << " ";
                    ss << s;
                    bitten = true; } }
        ss << "\""; }
    static ::std::size_t value_count ()
    {   return symbol < html_version, ENUM, CATEGORY, INIT > :: value_count (); } };

template < e_type E, typename ENUM, typename CATEGORY, CATEGORY INIT >
    void enum_vec < E, ENUM, CATEGORY, INIT > :: set_value (nitpick& nits, const html_version& v, const ::std::string& ss)
{   enum_vec_base < ENUM, E > :: original_ = ss;
    bool res = true;
    vstr_t strs;
    ::std::string sss (trim_the_lot_off (ss));
    ::boost::algorithm::split (strs, sss, ::boost::algorithm::is_any_of (" "), ::boost::algorithm::token_compress_on);
    for (auto s : strs)
    {   typename enum_vec_base < ENUM, E > :: base_t t;
        t.set_value (nits, v, s);
        enum_vec_base < ENUM, E > :: value_.push_back (t);
        if (t.invalid ())
        {   res = false;
            nits.pick (nit_unrecognised_value, es_error, ec_type, quote (s), " is not a valid value"); }
        else if (t.first ().dinosaur ())
            nits.pick (nit_dinosaur, es_info, ec_type, "been dancing with the dinosaurs, have we? (", quote (s), " is archaic)"); }
    if (strs.size () == 0) enum_vec_base < ENUM, E > :: status (s_empty);
    else if (res) enum_vec_base < ENUM, E > :: status (s_good);
    else enum_vec_base < ENUM, E > :: status (s_invalid); }

template < > class type_master < t_charsets > : public enum_vec < t_charsets, e_charset > { };
template < > class type_master < t_class > : public enum_vec < t_class, e_class > { };
template < > class type_master < t_content_encodings > : public enum_vec < t_content_encodings, e_content_encoding > { };
template < > class type_master < t_plusstyle > : public enum_vec < t_plusstyle, e_plusstyle > { };
template < > class type_master < t_rel > : public enum_vec < t_rel, e_rel > { };
template < > class type_master < t_svg_features > : public enum_vec < t_svg_features, e_svg_feature > { };
