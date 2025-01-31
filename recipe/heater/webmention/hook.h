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
#include "url/url.h"

class hook
{   url source_, target_;
    bool deleted_ = false, valid_ = false;
    bool parse (nitpick& nits, const html_version& v, const ::std::string& filename);
    void check ();
    bool update_mention (nitpick& nits, const ::std::string& s);
public:
    hook () : deleted_ (false), valid_ (false) { }
    hook (const hook& h) : source_ (h.source_), target_ (h.target_), deleted_ (h.deleted_), valid_ (h.valid_) { }
    hook (nitpick& nits, const html_version& v, const ::std::string& filename);
    hook (nitpick& nits, const html_version& v, const ::std::string& source, const ::std::string& target);
    void swap (hook& h) NOEXCEPT
    {   source_.swap (h.source_);
        target_.swap (h.target_);
        ::std::swap (deleted_, h.deleted_);
        ::std::swap (valid_, h.valid_); }
    url source () const { return source_; }
    url target () const { return target_; }
    bool deleted () const { return deleted_; }
    bool invalid () const { return ! valid_; }
    bool process (nitpick& nits, const html_version& v); };

class hooks
{   ::std::vector < hook > hooks_;
public:
    hooks () {}
    void swap (hooks& h) NOEXCEPT { hooks_.swap (h.hooks_); }
    bool empty () const { return hooks_.empty (); }
    bool process (nitpick& nits, const html_version& v); };
