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
#include "utility/common.h"

struct wotsit_t
{   html_version first_, last_;
    const char* wotsit_;
    wotsit_t () = default;
    wotsit_t (html_version first, html_version last, const char* wotsit)
        :   first_ (first), last_ (last), wotsit_ (wotsit) { }
    wotsit_t (const wotsit_t& w) = default;
#ifndef NO_MOVE_CONSTRUCTOR
    wotsit_t (wotsit_t&& w) = default;
    wotsit_t& operator = (wotsit_t&& w) = default;
#endif // NO_MOVE_CONSTRUCTOR
    ~wotsit_t () = default;
    wotsit_t& operator = (const wotsit_t& w) = default; };

struct extra_t
{   const char* symbol_ = nullptr;
    const char* code_ = nullptr;
    const bool suggest_ = true;
    extra_t (const char* symbol, const char* code, const bool suggest = true) : symbol_ (symbol), code_ (code), suggest_ (suggest) { } };

extern wotsit_t wotsit_table [];
extern extra_t xtra [], known_symbols [];
