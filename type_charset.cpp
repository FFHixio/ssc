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

#include "standard.h"
#include "type_enum.h"

struct symbol_entry < e_charset > charset_symbol_table [] =
{   { { HTML_4_0, REJECT }, { HTML_UNDEF }, "context", cs_context },

    // source: https://www.iana.org/assignments/character-sets/character-sets.xhtml
    // decorated from whatwg june 2020 encodings
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ansi_x3.110-1983", cs_ansi_x3_110_1983 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "asmo_449", cs_asmo_449 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "adobe-standard-encoding", cs_adobe_standard_encoding },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "adobe-symbol-encoding", cs_adobe_symbol_encoding },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "amiga-1251", cs_amiga_1251 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "bocu-1", cs_bocu_1 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "brf", cs_brf },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "bs_4730", cs_bs_4730 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "bs_viewdata", cs_bs_viewdata },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "big5", cs_big5 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "big5-hkscs", cs_big5 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cn-big5", cs_big5 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csbig5", cs_big5 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "x-x-big5", cs_big5 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "cesu-8", cs_cesu_8 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "cp50220", cs_cp50220 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "cp51932", cs_cp51932 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "csa_z243.4-1985-1", cs_csa_z243_4_1985_1 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "csa_z243.4-1985-2", cs_csa_z243_4_1985_2 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "csa_z243.4-1985-gr", cs_csa_z243_4_1985_gr },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "csn_369103", cs_csn_369103 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "dec-mcs", cs_dec_mcs },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "din_66003", cs_din_66003 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ds_2089", cs_ds_2089 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ebcdic-at-de", cs_ebcdic_at_de },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ebcdic-at-de-a", cs_ebcdic_at_de_a },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ebcdic-ca-fr", cs_ebcdic_ca_fr },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ebcdic-dk-no", cs_ebcdic_dk_no },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ebcdic-dk-no-a", cs_ebcdic_dk_no_a },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ebcdic-es", cs_ebcdic_es },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ebcdic-es-a", cs_ebcdic_es_a },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ebcdic-es-s", cs_ebcdic_es_s },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ebcdic-fi-se", cs_ebcdic_fi_se },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ebcdic-fi-se-a", cs_ebcdic_fi_se_a },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ebcdic-fr", cs_ebcdic_fr },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ebcdic-it", cs_ebcdic_it },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ebcdic-pt", cs_ebcdic_pt },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ebcdic-uk", cs_ebcdic_uk },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ebcdic-us", cs_ebcdic_us },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ecma-cyrillic", cs_ecma_cyrillic },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "es", cs_es },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "es2", cs_es2 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cseucpkdfmtjapanese", cs_euc_jp },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "euc-jp", cs_euc_jp },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "x-euc-jp", cs_euc_jp },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cseuckr", cs_euc_kr },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csksc5601198", cs_euc_kr },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "euc-kr", cs_euc_kr },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-ir-149", cs_euc_kr },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "korean", cs_euc_kr },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "ks_c_5601-1987", cs_euc_kr },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "ks_c_5601-1989", cs_euc_kr },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "ksc5601", cs_euc_kr },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "ksc_5601", cs_euc_kr },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "windows-949", cs_euc_kr },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "extended_unix_code_fixed_width_for_japanese", cs_extended_unix_code_fixed_width_for_japanese },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "extended_unix_code_packed_format_for_japanese", cs_extended_unix_code_packed_format_for_japanese },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "gb18030", cs_gb18030 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "gb2312", cs_gbk },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "gb_2312", cs_gbk },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "gb_2312-80", cs_gbk },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "chinese", cs_gbk },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "gb2312cs", cs_gbk },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csiso58gb231280", cs_gbk },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "gbk", cs_gbk },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-ir-58", cs_gbk },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "x-gbk", cs_gbk },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "gb_1988-80", cs_gb_1988_80 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "gost_19768-74", cs_gost_19768_74 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "hp-desktop", cs_hp_desktop },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "hp-legal", cs_hp_legal },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "hp-math8", cs_hp_math8 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "hp-pi-font", cs_hp_pi_font },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm-symbols", cs_ibm_symbols },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm-thai", cs_ibm_thai },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm00858", cs_ibm00858 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm00924", cs_ibm00924 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm01140", cs_ibm01140 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm01141", cs_ibm01141 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm01142", cs_ibm01142 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm01143", cs_ibm01143 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm01144", cs_ibm01144 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm01145", cs_ibm01145 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm01146", cs_ibm01146 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm01147", cs_ibm01147 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm01148", cs_ibm01148 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm01149", cs_ibm01149 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm037", cs_ibm037 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm038", cs_ibm038 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm1026", cs_ibm1026 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm1047", cs_ibm1047 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm273", cs_ibm273 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm274", cs_ibm274 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm275", cs_ibm275 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm277", cs_ibm277 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm278", cs_ibm278 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm280", cs_ibm280 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm281", cs_ibm281 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm284", cs_ibm284 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm285", cs_ibm285 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm290", cs_ibm290 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm297", cs_ibm297 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm420", cs_ibm420 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm423", cs_ibm423 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm424", cs_ibm424 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm437", cs_ibm437 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm500", cs_ibm500 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm775", cs_ibm775 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm850", cs_ibm850 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm851", cs_ibm851 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm852", cs_ibm852 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm855", cs_ibm855 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm857", cs_ibm857 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm860", cs_ibm860 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm861", cs_ibm861 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm862", cs_ibm862 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm863", cs_ibm863 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm864", cs_ibm864 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm865", cs_ibm865 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "866", cs_ibm866 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cp866", cs_ibm866 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csibm866", cs_ibm866 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "ibm866", cs_ibm866 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm868", cs_ibm868 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm869", cs_ibm869 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm870", cs_ibm870 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm871", cs_ibm871 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm880", cs_ibm880 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm891", cs_ibm891 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm903", cs_ibm903 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm904", cs_ibm904 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm905", cs_ibm905 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ibm918", cs_ibm918 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iec_p27-1", cs_iec_p27_1 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "inis", cs_inis },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "inis-8", cs_inis_8 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "inis-cyrillic", cs_inis_cyrillic },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "invariant", cs_invariant },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-10646-j-1", cs_iso_10646_j_1 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-10646-ucs-4", cs_iso_10646_ucs_4 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-10646-ucs-basic", cs_iso_10646_ucs_basic },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-10646-utf-1", cs_iso_10646_utf_1 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-10646-unicode-latin1", cs_iso_10646_unicode_latin1 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-11548-1", cs_iso_11548_1 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csiso2022kr", cs_iso_2022_cn },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "hz-gb-2312", cs_iso_2022_cn },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-2022-cn", cs_iso_2022_cn },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-2022-cn-ext", cs_iso_2022_cn },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-2022-kr", cs_iso_2022_cn },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "replacement", cs_iso_2022_cn },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso2022jp", cs_iso_2022_jp },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-2022-jp", cs_iso_2022_jp },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-2022-jp-2", cs_iso_2022_jp_2 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-8859-1-windows-3.0-latin-1", cs_iso_8859_1_windows_3_0_latin_1 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-8859-1-windows-3.1-latin-1", cs_iso_8859_1_windows_3_1_latin_1 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "l2", cs_iso_8859_2 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-2", cs_iso_8859_2 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-2", cs_iso_8859_2 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-2:1987", cs_iso_8859_2 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso8859-2", cs_iso_8859_2 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso88592", cs_iso_8859_2 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csisolatin2", cs_iso_8859_2 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csi-ir-101", cs_iso_8859_2 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-8859-2-windows-latin-2", cs_iso_8859_2_windows_latin_2 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "l3", cs_iso_8859_3 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-3", cs_iso_8859_3 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-ir-109", cs_iso_8859_3 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso8859-3", cs_iso_8859_3 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso88593", cs_iso_8859_3 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-3", cs_iso_8859_3 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-3:1998", cs_iso_8859_3 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "latin3", cs_iso_8859_3 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "l4", cs_iso_8859_4 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-4", cs_iso_8859_4 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-ir-110", cs_iso_8859_4 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso8859-4", cs_iso_8859_4 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso88594", cs_iso_8859_4 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-4", cs_iso_8859_4 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-4:1998", cs_iso_8859_4 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "latin4", cs_iso_8859_4 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csisolatincyrillic", cs_iso_8859_5 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cyrillic", cs_iso_8859_5 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-5", cs_iso_8859_5 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-ir-144", cs_iso_8859_5 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso8859-5", cs_iso_8859_5 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso88595", cs_iso_8859_5 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-5", cs_iso_8859_5 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-5:1988", cs_iso_8859_5 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "arabic", cs_iso_8859_6 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "asmo0708", cs_iso_8859_6 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csiso88596e", cs_iso_8859_6 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csiso88596i", cs_iso_8859_6 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csisolatinarabic", cs_iso_8859_6 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "ecma-114", cs_iso_8859_6 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-6", cs_iso_8859_6 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-6-e", cs_iso_8859_6 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-6-i", cs_iso_8859_6 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-ir-127", cs_iso_8859_6 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso8859-6", cs_iso_8859_6 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso88596", cs_iso_8859_6 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-6", cs_iso_8859_6 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-6:1987", cs_iso_8859_6 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csisolatingreek", cs_iso_8859_7 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "ecma-118", cs_iso_8859_7 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "elot_928", cs_iso_8859_7 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "greek", cs_iso_8859_7 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "greek8", cs_iso_8859_7 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-7", cs_iso_8859_7 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-ir-126", cs_iso_8859_7 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso8859-7", cs_iso_8859_7 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso88597", cs_iso_8859_7 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-7", cs_iso_8859_7 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-7:1987", cs_iso_8859_7 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csiso88598e", cs_iso_8859_8 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csisolatinhebrew", cs_iso_8859_8 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "hebrew", cs_iso_8859_8 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-8", cs_iso_8859_8 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-8-e", cs_iso_8859_8 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-ir-138", cs_iso_8859_8 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso8859-8", cs_iso_8859_8 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso88598", cs_iso_8859_8 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-8", cs_iso_8859_8 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-8:1988", cs_iso_8859_8 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "visual", cs_iso_8859_8 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csiso88598i", cs_iso_8859_8 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "logical", cs_iso_8859_8 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-8-i", cs_iso_8859_8_i },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-8859-9", cs_iso_8859_9 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-8859-9-windows-latin-5", cs_iso_8859_9_windows_latin_5 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csisolatin10", cs_iso_8859_10 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-10", cs_iso_8859_10 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-ir-157", cs_iso_8859_10 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso8859-10", cs_iso_8859_10 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso885910", cs_iso_8859_10 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "l6", cs_iso_8859_10 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "latin6", cs_iso_8859_10 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-13", cs_iso_8859_13 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso8859-13", cs_iso_8859_13 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso885913", cs_iso_8859_13 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-14", cs_iso_8859_14 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso8859-14", cs_iso_8859_14 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso885914", cs_iso_8859_14 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csisolatin9", cs_iso_8859_15 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-15", cs_iso_8859_15 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso8859-15", cs_iso_8859_15 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso885915", cs_iso_8859_15 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-15", cs_iso_8859_15 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "l9", cs_iso_8859_15 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-16", cs_iso_8859_16 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-unicode-ibm-1261", cs_iso_unicode_ibm_1261 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-unicode-ibm-1264", cs_iso_unicode_ibm_1264 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-unicode-ibm-1265", cs_iso_unicode_ibm_1265 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-unicode-ibm-1268", cs_iso_unicode_ibm_1268 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-unicode-ibm-1276", cs_iso_unicode_ibm_1276 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso_10367-box", cs_iso_10367_box },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso_2033-1983", cs_iso_2033_1983 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso_5427", cs_iso_5427 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso_5427:1981", cs_cs_iso_5427_1981 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso_5428:1980", cs_cs_iso_5428_1980 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso_646.basic:1983", cs_cs_iso_646_basic_1983 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso_646.irv:1983", cs_cs_iso_646_irv_1983 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso_6937-2-25", cs_iso_6937_2_25 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso_6937-2-add", cs_iso_6937_2_add },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso_8859-3:1988", cs_cs_iso_8859_3_1988 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso_8859-4:1988", cs_cs_iso_8859_4_1988 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso_8859-8-e", cs_iso_8859_8_e },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso_8859-8-i", cs_iso_8859_8_i },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso_8859-9:1989", cs_cs_iso_8859_9_1989 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso_8859-supp", cs_iso_8859_supp },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "it", cs_it },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jis_c6220-1969-jp", cs_jis_c6220_1969_jp },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jis_c6220-1969-ro", cs_jis_c6220_1969_ro },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jis_c6226-1978", cs_jis_c6226_1978 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jis_c6226-1983", cs_jis_c6226_1983 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jis_c6229-1984-a", cs_jis_c6229_1984_a },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jis_c6229-1984-b", cs_jis_c6229_1984_b },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jis_c6229-1984-b-add", cs_jis_c6229_1984_b_add },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jis_c6229-1984-hand", cs_jis_c6229_1984_hand },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jis_c6229-1984-hand-add", cs_jis_c6229_1984_hand_add },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jis_c6229-1984-kana", cs_jis_c6229_1984_kana },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jis_encoding", cs_jis_encoding },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jis_x0201", cs_jis_x0201 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jis_x0212-1990", cs_jis_x0212_1990 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jus_i.b1.002", cs_jus_i_b1_002 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jus_i.b1.003-mac", cs_jus_i_b1_003_mac },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "jus_i.b1.003-serb", cs_jus_i_b1_003_serb },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "koi7-switched", cs_koi7_switched },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cskoi8r", cs_koi8_r },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "koi", cs_koi8_r },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "koi8", cs_koi8_r },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "koi8-r", cs_koi8_r },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "koi8_r", cs_koi8_r },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "koi8-ru", cs_koi8_u },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "koi8-u", cs_koi8_u },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ksc5636", cs_ksc5636 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "kz-1048", cs_kz_1048 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "latin-greek-1", cs_latin_greek_1 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csmacintosh", cs_macintosh },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "mac", cs_macintosh },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "macintosh", cs_macintosh },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "x-mac-roman", cs_macintosh },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "mnem", cs_mnem },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "mnemonic", cs_mnemonic },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "msz_7795.3", cs_msz_7795_3 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "microsoft-publishing", cs_microsoft_publishing },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "nats-dano", cs_nats_dano },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "nats-dano-add", cs_nats_dano_add },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "nats-sefi", cs_nats_sefi },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "nats-sefi-add", cs_nats_sefi_add },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "nc_nc00-10:81", cs_cs_nc_nc00_10_81 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "nf_z_62-010", cs_nf_z_62_010 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "nf_z_62-010_(1973)", cs_nf_z_62_010_1973 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ns_4551-1", cs_ns_4551_1 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ns_4551-2", cs_ns_4551_2 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "osd_ebcdic_df03_irv", cs_osd_ebcdic_df03_irv },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "osd_ebcdic_df04_1", cs_osd_ebcdic_df04_1 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "osd_ebcdic_df04_15", cs_osd_ebcdic_df04_15 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "pc8-danish-norwegian", cs_pc8_danish_norwegian },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "pc8-turkish", cs_pc8_turkish },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "pt", cs_pt },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "pt2", cs_pt2 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ptcp154", cs_ptcp154 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "scsu", cs_scsu },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "sen_850200_b", cs_sen_850200_b },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "sen_850200_c", cs_sen_850200_c },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "t.101-g2", cs_t_101_g2 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "t.61-7bit", cs_t_61_7bit },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "t.61-8bit", cs_t_61_8bit },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "tscii", cs_tscii },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "unicode-1-1", cs_unicode_1_1 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "unicode-1-1-utf-7", cs_unicode_1_1_utf_7 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "unknown-8bit", cs_unknown_8bit },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "unicodefffe", cs_utf_16be },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "utf-16be", cs_utf_16be },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csunicode", cs_utf_16le },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-10646-ucs-2", cs_utf_16le },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "ucs-2", cs_utf_16le },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "unicode", cs_utf_16le },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "unicodefeff", cs_utf_16le },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "utf-16", cs_utf_16le },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "utf-16le", cs_utf_16le },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "utf-32", cs_utf_32 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "utf-32be", cs_utf_32be },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "utf-32le", cs_utf_32le },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "utf-7", cs_utf_7 },
    { { HTML_4_0 }, { HTML_UNDEF }, "unicode-1-1-utf-8", cs_utf_8 },
    { { HTML_4_0 }, { HTML_UNDEF }, "unicode11utf8", cs_utf_8 },
    { { HTML_4_0 }, { HTML_UNDEF }, "unicode20utf8", cs_utf_8 },
    { { HTML_4_0 }, { HTML_UNDEF }, "utf-8", cs_utf_8 },
    { { HTML_4_0 }, { HTML_UNDEF }, "utf8", cs_utf_8 },
    { { HTML_4_0 }, { HTML_UNDEF }, "x-unicode20utf8", cs_utf_8 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "viqr", cs_viqr },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "viscii", cs_viscii },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ventura-international", cs_ventura_international },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ventura-math", cs_ventura_math },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "ventura-us", cs_ventura_us },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csshiftjis", cs_windows_31j },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "ms932", cs_windows_31j },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "ms_kanji", cs_windows_31j },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "shift-jis", cs_windows_31j },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "shift_jis", cs_windows_31j },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "sjis", cs_windows_31j },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "windows-31j", cs_windows_31j },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "x-sjis", cs_windows_31j },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "dk-us", cs_dk_us },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "greek-ccitt", cs_greek_ccitt },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "greek7", cs_greek7 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "greek7-old", cs_greek7_old },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "hp-roman8", cs_hp_roman8 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "iso-ir-90", cs_iso_ir_90 },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "latin-greek", cs_latin_greek },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "latin-lap", cs_latin_lap },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "us-dk", cs_us_dk },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, "videotex-suppl", cs_videotex_suppl },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "dos-874", cs_windows_874 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-11", cs_windows_874 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso8859-11", cs_windows_874 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso885911", cs_windows_874 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "tis-620", cs_windows_874 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "windows-874", cs_windows_874 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "windows-1250", cs_windows_1250 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cp1250", cs_windows_1250 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "x-cp1250", cs_windows_1250 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cp1251", cs_windows_1251 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "windows-1251", cs_windows_1251 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "x-cp1251", cs_windows_1251 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "ansi_x3.4-1968", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "ascii", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cp1252", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cp819", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csisolatin1", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "ibm819", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso-8859-1", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso8859-1", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso88591", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-1", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "iso_8859-1:1987", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "l1", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "latin12", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "is-ascii", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "windows-1252", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "x-cp1252", cs_windows_1252 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cp1253", cs_windows_1253 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "windows-1253", cs_windows_1253 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "x-cp1253", cs_windows_1253 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cp1254", cs_windows_1254 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "csisolatin5", cs_windows_1254 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "is-8859-9", cs_windows_1254 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "is8859-9", cs_windows_1254 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "is88599", cs_windows_1254 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "is_8859-9", cs_windows_1254 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "is_8859-9:1989", cs_windows_1254 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "l5", cs_windows_1254 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "latin5", cs_windows_1254 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "windows-1254", cs_windows_1254 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "x-cp1254", cs_windows_1254 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cp1255", cs_windows_1255 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "windows-1255", cs_windows_1255 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "x-cp1255", cs_windows_1255 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cp1256", cs_windows_1256 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "windows-1256", cs_windows_1256 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "x-cp1256", cs_windows_1256 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cp1257", cs_windows_1257 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "windows-1257", cs_windows_1257 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "x-cp1257", cs_windows_1257 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "cp1258", cs_windows_1258 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "windows-1258", cs_windows_1258 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "x-cp1258", cs_windows_1258 },
    { { HTML_4_0, HV_DEPRECATED5 }, { HTML_UNDEF }, "x-user-defined", cs_x_user_defined },
    { { HTML_4_0, REJECT }, { HTML_UNDEF }, nullptr, cs_illegal } };

void charset_init (nitpick& nits)
{   type_master < t_charset > :: init (nits, charset_symbol_table, sizeof (charset_symbol_table) / sizeof (symbol_entry < e_charset >)); }
