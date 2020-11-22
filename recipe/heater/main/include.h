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

#ifdef __clang__
#pragma clang diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#define CONSTEXPR constexpr
#define NOEXCEPT noexcept
#endif // __clang__

#ifdef __GNUC__
#define CONSTEXPR constexpr
#define NOEXCEPT noexcept
#endif // __GNUC__

#ifdef _MSC_VER
#pragma warning (push,3)
#pragma warning ( disable : 4244 ) // boost
#if defined (VS2019)
#define _WIN32_WINNT 0x0A00 // 10
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS // thanks, boost
#define _CRT_SECURE_NO_WARNINGS // thanks, boost
#define CONSTEXPR constexpr
#define NOEXCEPT noexcept
#define VS 19
#elif defined (VS2017)
#define _WIN32_WINNT 0x0603 // 8.1
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS // thanks, boost
#define _CRT_SECURE_NO_WARNINGS // thanks, boost
#define CONSTEXPR constexpr
#define NOEXCEPT noexcept
#define VS 17
#elif defined (VS2015)
#define BOOVAR 1
#define ORDERED
#define _WIN32_WINNT 0x0601 // 7 SP1
#define _SCL_SECURE_NO_WARNINGS // thanks, boost
#define _CRT_SECURE_NO_WARNINGS
#define CONSTEXPR
#define NOEXCEPT
#define FS_THROWS
#define REQUIRE_CONSTRUCTOR
#define NO_PCF_STR
#define VS 15
#elif defined (VS2013)
#define BOOVAR 1
#define ORDERED
#define _WIN32_WINNT 0x0501 // XP
#define _SCL_SECURE_NO_WARNINGS // thanks, boost
#define _CRT_SECURE_NO_WARNINGS
#define CONSTEXPR
#define NOEXCEPT
#define FS_THROWS
#define REQUIRE_CONSTRUCTOR
#define NO_PCF_STR
#define VS 13
#define NO_PROCESS
#define NO_MOVE_CONSTRUCTOR
#else // VS...
#error unsupported version of visual C++
#endif // VS...
#endif // _MSC_VER

#ifdef FUDDYDUDDY
#define BOOVAR 2
#define ORDERED
#endif // FUDDYDUDDY

#include <iostream>
#include <vector>
#include <set>
#include <assert.h>
#include <map>

#ifndef SSC_TEST
#include <string>
#include <sstream>
#include <algorithm>
#include <tuple>
#include <memory>
#include <cstddef>
#include <utility>
#include <type_traits>
#include <stdexcept>
#include <chrono>
#include <ctime>
#include <functional>
#include <array>
#include <bitset>
#include <set>
#include <array>
#endif // SSC_TEST

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

#ifndef SSC_TEST

#if BOOVAR == 1
#include <boost/variant.hpp>
#define ssc_variant ::boost::variant
#define ssc_get ::boost::variant::get
#elif BOOVAR == 2
#include <boost/variant2/variant.hpp>
#define ssc_variant ::boost::variant2::variant
#define ssc_get ::boost::variant2::get
#else // BOOVAR
#include <variant>
#define ssc_variant ::std::variant
#define ssc_get ::std::get
#endif // BOOVAR

#ifdef ORDERED
#define ssc_set ::std::set
#define ssc_map ::std::map
#define ssc_mm ::std::multimap
#else // ORDERED
#include <unordered_set>
#include <unordered_map>
#define ssc_set ::std::unordered_set
#define ssc_map ::std::unordered_map
#define ssc_mm ::std::unordered_multimap
#endif // ORDERED

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/format.hpp>
#ifndef NO_PROCESS
#include <boost/process.hpp>
#endif // NO_PROCESS
#include <boost/program_options.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/string_path.hpp>
#endif // SSC_TEST

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#ifdef _MSC_VER
#pragma warning (pop)
#endif

#include "main/version.h"

#ifndef SCC_TEST

#define PR_FILE "file"
#define PR_FTP "ftp"
#define PR_FTPS "ftps"
#define PR_GEO "geo"
#define PR_HTTP "http"
#define PR_HTTPS "https"
#define PR_LDAP "ldap"
#define PR_MAILTO "mailto"
#define PR_NEWS "news"
#define PR_SFTP "sftp"
#define PR_SSH "ssh"
#define PR_TELNET "telnet"
#define PR_TEL "tel"
#define PR_URN "urn"

#define WEBMENTION "webmention"
#define SEP "."

#define CSS "://"
#define HTTP PR_HTTP CSS
#define HTTPS PR_HTTPS CSS
#define SPACE ' '
#define COLON ':'
#define DOT '.'
#define SLASH '/'
#define HASH '#'
#define HASHES "#"
#define QUESTION '?'
#define AT '@'
#define EQUAL '='
#define PERCENT '%'
#define BRCLOSE ')'
#define BROPEN '('
#define SQCLOSE ']'
#define SQOPEN '['
#define CUCLOSE '}'
#define CUOPEN '{'
#define DENARY "0123456789"
#define DDD DENARY "-."
#define DECIMAL DDD "+"
#define OCTAL "01234567"
#define HEX DENARY "abcdefABCDEF"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define ALPHABET UPPERCASE LOWERCASE
#define IDS ALPHABET DDD "_:"
#define TEL HEX "+*()-.#*_!~'[]/ "
#define REAL DECIMAL "Ee"

#define DEFAULT_DOMAIN "example.org"
#define CSS_TYPE "text/css"

#define NOFLAGS 0

#define EXPORT_EXTENSION ".json"

#endif // SCC_TEST
