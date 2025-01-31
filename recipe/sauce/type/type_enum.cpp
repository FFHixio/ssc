/*
ssc (static site checker)
Copyright (c) 2020,2021 Dylan Harris
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

#include "main/standard.h"
#include "type/type.h"

struct symbol_entry < html_version, e_action > action_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "sell", av_sell },
    { { HTML_UNDEF }, { HTML_UNDEF }, "rent", av_rent },
    { { HTML_UNDEF }, { HTML_UNDEF }, "trade", av_trade },
    { { HTML_UNDEF }, { HTML_UNDEF }, "meet", av_meet },
    { { HTML_UNDEF }, { HTML_UNDEF }, "announce", av_announce },
    { { HTML_UNDEF }, { HTML_UNDEF }, "offer", av_offer },
    { { HTML_UNDEF }, { HTML_UNDEF }, "wanted", av_wanted },
    { { HTML_UNDEF }, { HTML_UNDEF }, "event", av_event },
    { { HTML_UNDEF }, { HTML_UNDEF }, "service", av_service } };

struct symbol_entry < html_version, e_align3 > align3_symbol_table [] =
{   { { HTML_3_0 }, { HTML_UNDEF }, "top", a3_top },
    { { HTML_3_0 }, { HTML_UNDEF }, "middle", a3_middle },
    { { HTML_3_0 }, { HTML_UNDEF }, "bottom", a3_bottom },
    { { HTML_3_0 }, { HTML_UNDEF }, "left", a3_left },
    { { HTML_3_0 }, { HTML_UNDEF }, "right", a3_right } };

struct symbol_entry < html_version, e_alignmentbaseline > alignmentbaseline_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG_10_11 }, { HTML_UNDEF }, "after-edge", ab_afteredge },
    { { HTML_SVG11, 0, HE_SVG_11_20 }, { HTML_UNDEF }, "alphabetic", ab_alphabetic },
    { { HTML_SVG11, 0, HE_SVG_11 }, { HTML_UNDEF }, "auto",  ab_auto },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "baseline", ab_baseline },
    { { HTML_SVG10, 0, HE_SVG_10_11 }, { HTML_UNDEF }, "before-edge", ab_beforeedge },
    { { HTML_SVG10, 0, HE_SVG_10 }, { HTML_UNDEF }, "bottom", ab_bottom },
    { { HTML_SVG11, 0, HE_SVG_11_20 }, { HTML_UNDEF }, "central", ab_central },
    { { HTML_SVG10, 0, HE_SVG_10_11 }, { HTML_UNDEF }, "hanging", ab_hanging },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "ideographic", ab_ideographic },
    { { HTML_SVG10, 0, HE_SVG_10 }, { HTML_UNDEF }, "inherit", ab_inherit },
    { { HTML_SVG10, 0, HE_SVG_10 }, { HTML_UNDEF }, "lower", ab_lower },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "mathematical", ab_mathematical },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "middle", ab_middle },
    { { HTML_SVG10, 0, HE_SVG_10_11 }, { HTML_UNDEF }, "text-after-edge", ab_textafteredge },
    { { HTML_SVG10, 0, HE_SVG_10_11 }, { HTML_UNDEF }, "text-before-edge", ab_textbeforeedge },
    { { HTML_SVG10, 0, HE_SVG_10_20 }, { HTML_UNDEF }, "text-bottom", ab_textbottom },
    { { HTML_SVG10, 0, HE_SVG_10_20 }, { HTML_UNDEF }, "text-top", ab_texttop },
    { { HTML_SVG10, 0, HE_SVG_10 }, { HTML_UNDEF }, "top", ab_top } };

struct symbol_entry < html_version, e_alignplus > alignplus_symbol_table [] =
{   { { HTML_PLUS }, { HTML_PLUS }, "center", ap_centre },
    { { HTML_PLUS }, { HTML_PLUS }, "indent", ap_indent },
    { { HTML_PLUS }, { HTML_PLUS }, "justify", ap_justify },
    { { HTML_PLUS }, { HTML_PLUS }, "left", ap_left },
    { { HTML_PLUS }, { HTML_PLUS }, "right", ap_right } };

struct symbol_entry < html_version, e_as > as_symbol_table [] =
{   { { HTML_JAN05 }, { HTML_UNDEF }, "audio", as_audio },
    { { HTML_JAN05 }, { HTML_UNDEF }, "document", as_document },
    { { HTML_JAN05 }, { HTML_UNDEF }, "embed", as_embed },
    { { HTML_JAN05 }, { HTML_UNDEF }, "fetch", as_fetch },
    { { HTML_JAN05 }, { HTML_UNDEF }, "font", as_font },
    { { HTML_JAN05 }, { HTML_UNDEF }, "image", as_image },
    { { HTML_JAN05 }, { HTML_UNDEF }, "object", as_object },
    { { HTML_JAN05 }, { HTML_UNDEF }, "script", as_script },
    { { HTML_JAN05 }, { HTML_UNDEF }, "style", as_style },
    { { HTML_JAN05 }, { HTML_UNDEF }, "track", as_track },
    { { HTML_JAN05 }, { HTML_UNDEF }, "video", as_video },
    { { HTML_JAN05 }, { HTML_UNDEF }, "worker", as_worker } };

struct symbol_entry < html_version, e_autocapitalise > autocapitalise_symbol_table [] =
{   { { HTML_5_3 }, { HTML_UNDEF }, "characters", ac4_characters },
    { { HTML_JUL20 }, { HTML_UNDEF }, "default", ec4_default },
    { { HTML_JUL20 }, { HTML_UNDEF }, "none", ac4_none },
    { { HTML_5_3 }, { HTML_UNDEF }, "sentences", ac4_sentences },
    { { HTML_5_3 }, { HTML_UNDEF }, "words", ac4_words } };

struct symbol_entry < html_version, e_autocomplete > autocomplete_symbol_table [] =
{   { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "additional-name", aco_additional_name },
    { { HTML_JAN15, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "address-level1", aco_address_level1 },
    { { HTML_JAN15, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "address-level2", aco_address_level2 },
    { { HTML_JAN15, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "address-level3", aco_address_level3 },
    { { HTML_JAN15, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "address-level4", aco_address_level4 },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "address-line1", aco_address_line1 },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "address-line2", aco_address_line2 },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "address-line3", aco_address_line3 },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "bday", aco_bday },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "bday-day", aco_bday_day },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "bday-month", aco_bday_month },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "bday-year", aco_bday_year },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "billing", aco_billing },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "cc-additional-name", aco_cc_additional_name },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "cc-csc", aco_cc_csc },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "cc-exp", aco_cc_exp },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "cc-exp-month", aco_cc_exp_month },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "cc-exp-year", aco_cc_exp_year },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "cc-family-name", aco_cc_family_name },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "cc-given-name", aco_cc_given_name },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "cc-name", aco_cc_name },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "cc-number", aco_cc_number },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "cc-type", aco_cc_type },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "country", aco_country },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "country-name", aco_country_name },
    { { HTML_JAN15, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "current-password", aco_current_password },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "email", aco_email },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "family-name", aco_family_name },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "fax", aco_fax },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "given-name", aco_given_name },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "home", aco_home },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "honorific-prefix", aco_honorific_prefix },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "honorific-suffix", aco_honorific_suffix },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "impp", aco_impp },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "language", aco_language },
    { { HTML_JAN13 }, { HTML_DEC14 }, "locality", aco_locality },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "mobile", aco_mobile },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "name", aco_name },
    { { HTML_JAN15, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "new-password", aco_new_password },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "nickname", aco_nickname },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "off", aco_off },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "on", aco_on },
    { { HTML_JAN20 }, { HTML_UNDEF }, "one-time-code", aco_one_time_code },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "organization", aco_organization },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "organization-title", aco_organization_title },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "pager", aco_pager },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "photo", aco_photo },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "postal-code", aco_postal_code },
    { { HTML_JAN13 }, { HTML_DEC14 }, "region", aco_region },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "sex", aco_sex },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "shipping", aco_shipping },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "street-address", aco_street_address },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "tel", aco_tel },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "tel-area-code", aco_tel_area_code },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "tel-country-code", aco_tel_country_code },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "tel-extension", aco_tel_extension },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "tel-local", aco_tel_local },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "tel-local-prefix", aco_tel_local_prefix },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "tel-local-suffix", aco_tel_local_suffix },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "tel-national", aco_tel_national },
    { { HTML_JAN15, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "transaction-amount", aco_transaction_amount },
    { { HTML_JAN15, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "transaction-currency", aco_transaction_currency },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "url", aco_url },
    { { HTML_JAN15, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "username", aco_username },
    { { HTML_JAN13, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "work", aco_work } };

struct symbol_entry < html_version, e_beginfn > beginfn_symbol_table [] =
{   { { HTML_SVG11, 0, HE_SVG_11_12 }, { HTML_UNDEF }, "offset-value", ebf_offset_value },
    { { HTML_SVG11, 0, HE_SVG_11_12 }, { HTML_UNDEF }, "syncbase-value", ebf_syncbase_value },
    { { HTML_SVG11, 0, HE_SVG_11_12 }, { HTML_UNDEF }, "event-value", ebf_event_value },
    { { HTML_SVG11, 0, HE_SVG_11_12 }, { HTML_UNDEF }, "repeat-value", ebf_repeat_value },
    { { HTML_SVG11, 0, HE_SVG_11_12 }, { HTML_UNDEF }, "accesskey-value", ebf_accesskey_value },
    { { HTML_SVG11, 0, HE_SVG_11 }, { HTML_UNDEF }, "wallclock-sync-value", ebf_wallclock_sync_value } };

struct symbol_entry < html_version, e_cachekey > cachekey_symbol_table [] =
{   { { HTML_JAN15 }, { HTML_UNDEF }, "max-age", ck_maxage },
    { { HTML_JAN15 }, { HTML_UNDEF }, "max-stale", ck_maxstale },
    { { HTML_JAN15 }, { HTML_UNDEF }, "min-fresh", ck_minfresh },
    { { HTML_JAN15 }, { HTML_UNDEF }, "no-cache", ck_nocache },
    { { HTML_JAN15 }, { HTML_UNDEF }, "no-store", ck_nostore },
    { { HTML_JAN15 }, { HTML_UNDEF }, "no-transform", ck_notransform },
    { { HTML_JAN15 }, { HTML_UNDEF }, "only-if-cached", ck_onlyifcached } };

struct symbol_entry < html_version, e_citype > citype_symbol_table [] =
{   { { XHTML_1_0 }, { HTML_UNDEF }, "integer", ci_integer },
    { { XHTML_1_0 }, { HTML_UNDEF }, "rational", ci_rational },
    { { XHTML_1_0 }, { HTML_UNDEF }, "real", ci_real },
    { { XHTML_1_0 }, { HTML_UNDEF }, "complex-polar", ci_complexpolar },
    { { XHTML_1_0 }, { HTML_UNDEF }, "complex-cartesian", ci_complexcartesian },
    { { XHTML_1_0 }, { HTML_UNDEF }, "constant", ci_constant },
    { { HTML_5_2 }, { HTML_UNDEF }, "complex", ci_complex },
    { { HTML_5_2 }, { HTML_UNDEF }, "function", ci_function },
    { { HTML_5_2 }, { HTML_UNDEF }, "vector", ci_vector },
    { { HTML_5_2 }, { HTML_UNDEF }, "list", ci_list },
    { { HTML_5_2 }, { HTML_UNDEF }, "set", ci_set },
    { { HTML_5_2 }, { HTML_UNDEF }, "matrix", ci_matrix } };

struct symbol_entry < html_version, e_cntype > cntype_symbol_table [] =
{   { { HTML_5_2 }, { HTML_UNDEF }, "double", cn_double },
    { { XHTML_1_0 }, { HTML_UNDEF }, "e-notation", cn_enotation },
    { { HTML_5_2 }, { HTML_UNDEF }, "hexdouble", cn_hexdouble },
    { { XHTML_1_0 }, { HTML_UNDEF }, "integer", cn_integer },
    { { XHTML_1_0 }, { HTML_UNDEF }, "rational", cn_rational },
    { { XHTML_1_0 }, { HTML_UNDEF }, "real", cn_real },
    { { XHTML_1_0 }, { HTML_UNDEF }, "complex-polar", cn_complexpolar },
    { { XHTML_1_0 }, { HTML_UNDEF }, "complex-cartesian", cn_complexcartesian },
    { { XHTML_1_0 }, { HTML_UNDEF }, "constant", cn_constant } };

struct symbol_entry < html_version, e_composite_operator > composite_operator_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "arithmetic",  co_arithmetic },
    { { HTML_4_0 }, { HTML_UNDEF }, "atop", co_atop },
    { { HTML_4_0 }, { HTML_UNDEF }, "in", co_in },
    { { HTML_4_0 }, { HTML_UNDEF }, "out", co_out },
    { { HTML_4_0 }, { HTML_UNDEF }, "over", co_over },
    { { HTML_4_0 }, { HTML_UNDEF }, "xor", co_xor } };

struct symbol_entry < html_version, e_cookieid > cookieid_symbol_table [] =
{   { { HTML_JAN15 }, { HTML_UNDEF }, "expires", coo_expires },
    { { HTML_JAN15 }, { HTML_UNDEF }, "max-age", coo_maxage },
    { { HTML_JAN15 }, { HTML_UNDEF }, "domain", coo_domain },
    { { HTML_JAN15 }, { HTML_UNDEF }, "path", coo_path },
    { { HTML_JAN15 }, { HTML_UNDEF }, "secure", coo_secure },
    { { HTML_JAN15 }, { HTML_UNDEF }, "httponly", coo_httponly } };

struct symbol_entry < html_version, e_crossout > crossout_symbol_table [] =
{   { { HTML_5_2 }, { HTML_UNDEF }, "none", co_none },
    { { HTML_5_2 }, { HTML_UNDEF }, "updiagonalstrike", co_updiagonalstrike },
    { { HTML_5_2 }, { HTML_UNDEF }, "downdiagonalstrike", co_downdiagonalstrike },
    { { HTML_5_2 }, { HTML_UNDEF }, "verticalstrike", co_verticalstrike },
    { { HTML_5_2 }, { HTML_UNDEF }, "horizontalstrike", co_horizontalstrike } };

struct symbol_entry < html_version, e_cursor > cursor_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "auto",  cu_auto },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "crosshair", cu_crosshair },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "default", cu_default },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "pointer", cu_pointer },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "move", cu_move },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "e-resize", cu_eresize },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "ne-resize", cu_neresize },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "nw-resize", cu_nwresize },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "n-resize", cu_nresize },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "se-resize", cu_seresize },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "sw-resize", cu_swresize },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "s-resize", cu_sresize },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "w-resize", cu_wresize },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "text", cu_text },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "wait", cu_wait },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "help", cu_help },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "inherit", cu_inherit } };

struct symbol_entry < html_version, e_decalign > decalign_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "left", dec_left },
    { { HTML_2_0 }, { HTML_UNDEF }, "center", dec_center },
    { { HTML_2_0 }, { HTML_UNDEF }, "right", dec_right },
    { { HTML_2_0 }, { HTML_UNDEF }, "justify", dec_justify },
    { { HTML_2_0 }, { HTML_UNDEF }, "decimal", dec_decimal } };

struct symbol_entry < html_version, e_dingbat > dingbat_symbol_table [] =
{   { { HTML_3_0 }, { HTML_3_0 }, "ftp", db_ftp },
    { { HTML_3_0 }, { HTML_3_0 }, "gopher", db_gopher },
    { { HTML_3_0 }, { HTML_3_0 }, "telnet", db_telnet },
    { { HTML_3_0 }, { HTML_3_0 }, "archive", db_archive },
    { { HTML_3_0 }, { HTML_3_0 }, "filing.cabinet", db_filing_cabinet },
    { { HTML_3_0 }, { HTML_3_0 }, "folder", db_folder },
    { { HTML_3_0 }, { HTML_3_0 }, "fixed.disk", db_fixed_disk },
    { { HTML_3_0 }, { HTML_3_0 }, "disk.drive", db_disk_drive },
    { { HTML_3_0 }, { HTML_3_0 }, "document", db_document },
    { { HTML_3_0 }, { HTML_3_0 }, "unknown.document", db_unknown_document },
    { { HTML_3_0 }, { HTML_3_0 }, "text.document", db_text_document },
    { { HTML_3_0 }, { HTML_3_0 }, "binary.document", db_binary_document },
    { { HTML_3_0 }, { HTML_3_0 }, "binhex.document", db_binhex_document },
    { { HTML_3_0 }, { HTML_3_0 }, "audio", db_audio },
    { { HTML_3_0 }, { HTML_3_0 }, "film", db_film },
    { { HTML_3_0 }, { HTML_3_0 }, "image", db_image },
    { { HTML_3_0 }, { HTML_3_0 }, "map", db_map },
    { { HTML_3_0 }, { HTML_3_0 }, "form", db_form },
    { { HTML_3_0 }, { HTML_3_0 }, "mail", db_mail },
    { { HTML_3_0 }, { HTML_3_0 }, "parent", db_parent },
    { { HTML_3_0 }, { HTML_3_0 }, "next", db_next },
    { { HTML_3_0 }, { HTML_3_0 }, "previous", db_previous },
    { { HTML_3_0 }, { HTML_3_0 }, "home", db_home },
    { { HTML_3_0 }, { HTML_3_0 }, "toc", db_toc },
    { { HTML_3_0 }, { HTML_3_0 }, "glossary", db_glossary },
    { { HTML_3_0 }, { HTML_3_0 }, "index", db_index },
    { { HTML_3_0 }, { HTML_3_0 }, "summary", db_summary },
    { { HTML_3_0 }, { HTML_3_0 }, "calculator", db_calculator },
    { { HTML_3_0 }, { HTML_3_0 }, "caution", db_caution },
    { { HTML_3_0 }, { HTML_3_0 }, "clock", db_clock },
    { { HTML_3_0 }, { HTML_3_0 }, "compressed.document", db_compressed_document },
    { { HTML_3_0 }, { HTML_3_0 }, "diskette", db_diskette },
    { { HTML_3_0 }, { HTML_3_0 }, "display", db_display },
    { { HTML_3_0 }, { HTML_3_0 }, "fax", db_fax },
    { { HTML_3_0 }, { HTML_3_0 }, "mail.in", db_mail_in },
    { { HTML_3_0 }, { HTML_3_0 }, "mail.out", db_mail_out },
    { { HTML_3_0 }, { HTML_3_0 }, "mouse", db_mouse },
    { { HTML_3_0 }, { HTML_3_0 }, "printer", db_printer },
    { { HTML_3_0 }, { HTML_3_0 }, "tn3270", db_tn3270 },
    { { HTML_3_0 }, { HTML_3_0 }, "trash", db_trash } };

struct symbol_entry < html_version, e_dir > dir_symbol_table [] =
{   { { HTML_JAN05 }, { HTML_UNDEF }, "auto",  di_auto },
    { { XHTML_2_0 }, { XHTML_2_0 }, "lro", di_lro },
    { { XHTML_2_0 }, { XHTML_2_0 }, "rlo", di_rlo },
    { { HTML_2_0 }, { HTML_UNDEF }, "ltr", di_ltr },
    { { HTML_2_0 }, { HTML_UNDEF }, "rtl", di_rtl } };

struct symbol_entry < html_version, e_display_align > display_align_symbol_table [] =
{   { { HTML_SVG12, 0, HE_SVG_12 }, { HTML_UNDEF }, "auto",  da_auto },
    { { HTML_SVG12, 0, HE_SVG_12 }, { HTML_UNDEF }, "before", da_before },
    { { HTML_SVG12, 0, HE_SVG_12 }, { HTML_UNDEF }, "center", da_centre },
    { { HTML_SVG12, 0, HE_SVG_12 }, { HTML_UNDEF }, "after", da_after },
    { { HTML_SVG12, 0, HE_SVG_12 }, { HTML_UNDEF }, "inherit", da_inherit } };

struct symbol_entry < html_version, e_dominantbaseline > dominantbaseline_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "auto",  db_auto },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "use-script", db_usescript },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "no-change", db_nochange },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "reset-size", db_resetsize },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "ideographic", db_ideographic },
    { { HTML_SVG11, 0, HE_SVG_11_20 }, { HTML_UNDEF }, "alphabetic", db_alphabetic },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "hanging", db_hanging },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "mathematical", db_mathematical },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "central", db_central },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "middle", db_middle },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "text-after-edge", db_textafteredge },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "text-before-edge", db_textbeforeedge },
    { { HTML_SVG10, 0, HE_SVG_10_11 }, { HTML_UNDEF }, "inherit", db_inherit } };

struct symbol_entry < html_version, e_enterkeyhint > enterkeyhint_symbol_table [] =
{   { { HTML_JUL20 }, { HTML_UNDEF }, "done", ekh_done },
    { { HTML_JUL20 }, { HTML_UNDEF }, "enter", ekh_enter },
    { { HTML_JUL20 }, { HTML_UNDEF }, "go", ekh_go },
    { { HTML_JUL20 }, { HTML_UNDEF }, "next", ekh_next },
    { { HTML_JUL20 }, { HTML_UNDEF }, "previous", ekh_previous },
    { { HTML_JUL20 }, { HTML_UNDEF }, "search", ekh_search },
    { { HTML_JUL20 }, { HTML_UNDEF }, "send", ekh_send } };

struct symbol_entry < html_version, e_figalign > figalign_symbol_table [] =
{   { { HTML_3_0 }, { HTML_3_0 }, "bleedleft", fa_bleedleft },
    { { HTML_3_0 }, { HTML_3_0 }, "left", fa_left },
    { { HTML_3_0 }, { HTML_3_0 }, "center", fa_centre },
    { { HTML_3_0 }, { HTML_3_0 }, "right", fa_right },
    { { HTML_3_0 }, { HTML_3_0 }, "bleedright", fa_bleedright },
    { { HTML_3_0 }, { HTML_3_0 }, "justify", fa_justify } };

struct symbol_entry < html_version, e_filter_in > filter_in_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "SourceGraphic", fi_sourcegraphic },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "SourceAlpha", fi_sourcealpha },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "BackgroundImage", fi_backgroundimage },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "BackgroundAlpha", fi_backgroundalpha },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "FillPaint", fi_fillpaint },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "StrokePaint", fi_strokepaint } };

struct symbol_entry < html_version, e_fontname > fontname_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "serif", fn_serif },
    { { HTML_2_0 }, { HTML_UNDEF }, "sans-serif", fn_sans_serif },
    { { HTML_2_0 }, { HTML_UNDEF }, "cursive", fn_cursive },
    { { HTML_2_0 }, { HTML_UNDEF }, "fantasy", fn_fantasy },
    { { HTML_2_0 }, { HTML_UNDEF }, "monospace", fn_monospace },
    { { HTML_2_0 }, { HTML_UNDEF }, "Arial", fn_arial },
    { { HTML_2_0 }, { HTML_UNDEF }, "Courier New", fn_courier_new },
    { { HTML_2_0 }, { HTML_UNDEF }, "Courier", fn_courier_new },
    { { HTML_2_0 }, { HTML_UNDEF }, "Georgia", fn_georgia },
    { { HTML_2_0 }, { HTML_UNDEF }, "Times New Roman", fn_times_new_roman },
    { { HTML_2_0 }, { HTML_UNDEF }, "Times", fn_times_new_roman },
    { { HTML_2_0 }, { HTML_UNDEF }, "Verdana", fn_verdana } };

struct symbol_entry < html_version, e_halign > halign_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "left", al_left },
    { { HTML_2_0 }, { HTML_UNDEF }, "center", al_center },
    { { HTML_2_0 }, { HTML_UNDEF }, "right", al_right },
    { { HTML_2_0 }, { HTML_UNDEF }, "justify", al_justify },
    { { HTML_2_0 }, { HTML_UNDEF }, "char", al_char } };

struct symbol_entry < html_version, e_indentalign > indentalign_symbol_table [] =
{   { { HTML_5_2 }, { HTML_UNDEF }, "left", ia_left },
    { { HTML_5_2 }, { HTML_UNDEF }, "center", ia_centre },
    { { HTML_5_2 }, { HTML_UNDEF }, "right", ia_right },
    { { HTML_5_2 }, { HTML_UNDEF }, "auto", ia_auto },
    { { HTML_5_2 }, { HTML_UNDEF }, "id", ia_id } };

struct symbol_entry < html_version, e_inky > inky_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "sourcegraphic", ink_sourcegraphic },
    { { HTML_2_0 }, { HTML_UNDEF }, "sourcealpha", ink_sourcealpha },
    { { HTML_2_0 }, { HTML_UNDEF }, "backgroundimage", ink_backgroundimage },
    { { HTML_2_0 }, { HTML_UNDEF }, "backgroundalpha", ink_backgroundalpha },
    { { HTML_2_0 }, { HTML_UNDEF }, "fillpaint", ink_fillpaint },
    { { HTML_2_0 }, { HTML_UNDEF }, "strokepaint", ink_strokepaint } };

struct symbol_entry < html_version, e_inputmode > inputmode_symbol_table [] =
{   { { HTML_JAN18 }, { HTML_UNDEF }, "decimal", im_decimal },
    { { HTML_JAN13, HV_NOT52 }, { HTML_UNDEF }, "email", im_email },
    { { HTML_JAN13, HV_NOT52 }, { HTML_DEC17 }, "full-width-latin", im_fullwidthlatin },
    { { HTML_JAN13, HV_NOT52 }, { HTML_DEC17 }, "katakana", im_katakana },
    { { HTML_JAN13, HV_NOT52 }, { HTML_DEC17 }, "kana", im_kana },
    { { HTML_JAN15, HV_NOT52 }, { HTML_DEC17 }, "kana-name", im_kananame },
    { { HTML_JAN13, HV_NOT52 }, { HTML_DEC17 }, "latin", im_latin },
    { { HTML_JAN13, HV_NOT52 }, { HTML_DEC17 }, "latin-name", im_latinname },
    { { HTML_JAN13, HV_NOT52 }, { HTML_DEC17 }, "latin-prose", im_latinprose },
    { { HTML_JAN18 }, { HTML_UNDEF }, "none", im_none },
    { { HTML_JAN13 }, { HTML_UNDEF }, "numeric", im_numeric  },
    { { HTML_JAN18 }, { HTML_UNDEF }, "search", im_search },
    { { HTML_JAN13 }, { HTML_UNDEF }, "tel", im_tel },
    { { HTML_JAN18 }, { HTML_UNDEF }, "text", im_text },
    { { HTML_JAN13 }, { HTML_UNDEF }, "verbatim", im_verbatim },
    { { HTML_JAN13 }, { HTML_UNDEF }, "url", im_url } };

struct symbol_entry < html_version, e_inputplus > inputplus_symbol_table [] =
{   { { HTML_PLUS }, { HTML_PLUS }, "audio", ip_audio },
    { { HTML_PLUS }, { HTML_PLUS }, "checkbox", ip_checkbox },
    { { HTML_PLUS }, { HTML_PLUS }, "date", ip_date },
    { { HTML_PLUS }, { HTML_PLUS }, "float", ip_float },
    { { HTML_PLUS }, { HTML_PLUS }, "image", ip_image },
    { { HTML_PLUS }, { HTML_PLUS }, "int", ip_int },
    { { HTML_PLUS }, { HTML_PLUS }, "radio", ip_radio },
    { { HTML_PLUS }, { HTML_PLUS }, "range", ip_range },
    { { HTML_PLUS }, { HTML_PLUS }, "reset", ip_reset },
    { { HTML_PLUS }, { HTML_PLUS }, "scribble", ip_scribble },
    { { HTML_PLUS }, { HTML_PLUS }, "submit", ip_submit },
    { { HTML_PLUS }, { HTML_PLUS }, "text", ip_text },
    { { HTML_PLUS }, { HTML_PLUS }, "url", ip_url } };

struct symbol_entry < html_version, e_inputtype > inputtype_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "checkbox", it_checkbox },
    { { HTML_2_0 }, { HTML_UNDEF }, "file", it_file },
    { { HTML_2_0 }, { HTML_UNDEF }, "hidden", it_hidden },
    { { HTML_2_0 }, { HTML_UNDEF }, "image", it_image },
    { { HTML_2_0 }, { HTML_UNDEF }, "password", it_password },
    { { HTML_2_0 }, { HTML_UNDEF }, "radio", it_radio },
    { { HTML_2_0 }, { HTML_UNDEF }, "reset", it_reset },
    { { HTML_2_0 }, { HTML_UNDEF }, "submit", it_submit },
    { { HTML_2_0 }, { HTML_UNDEF }, "text", it_text } };

struct symbol_entry < html_version, e_inputtype3 > inputtype3_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "checkbox", i3_checkbox },
    { { HTML_2_0, HV_RFC_1867 }, { HTML_UNDEF }, "file", i3_file },
    { { HTML_2_0 }, { HTML_UNDEF }, "hidden", i3_hidden },
    { { HTML_2_0 }, { HTML_UNDEF }, "image", i3_image },
    { { HTML_2_0 }, { HTML_UNDEF }, "password", i3_password },
    { { HTML_2_0 }, { HTML_UNDEF }, "radio", i3_radio },
    { { HTML_3_0 }, { HTML_3_0 }, "range", i3_range },
    { { HTML_2_0 }, { HTML_UNDEF }, "reset", i3_reset },
    { { HTML_3_0 }, { HTML_3_0 }, "scribble", i3_scribble },
    { { HTML_2_0 }, { HTML_UNDEF }, "submit", i3_submit },
    { { HTML_2_0 }, { HTML_UNDEF }, "text", i3_text } };

struct symbol_entry < html_version, e_inputtype32 > inputtype32_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "checkbox", i2_checkbox },
    { { HTML_2_0 }, { HTML_UNDEF }, "file", i2_file },
    { { HTML_2_0 }, { HTML_UNDEF }, "hidden", i2_hidden },
    { { HTML_2_0 }, { HTML_UNDEF }, "image", i2_image },
    { { HTML_2_0 }, { HTML_UNDEF }, "password", i2_password },
    { { HTML_2_0 }, { HTML_UNDEF }, "radio", i2_radio },
    { { HTML_2_0 }, { HTML_UNDEF }, "reset", i2_reset },
    { { HTML_2_0 }, { HTML_UNDEF }, "submit", i2_submit },
    { { HTML_2_0 }, { HTML_UNDEF }, "text", i2_text } };

struct symbol_entry < html_version, e_inputtype4 > inputtype4_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "button", i4_button },
    { { HTML_2_0 }, { HTML_UNDEF }, "checkbox", i4_checkbox },
    { { HTML_2_0 }, { HTML_UNDEF }, "file", i4_file },
    { { HTML_2_0 }, { HTML_UNDEF }, "hidden", i4_hidden },
    { { HTML_2_0 }, { HTML_UNDEF }, "image", i4_image },
    { { HTML_2_0 }, { HTML_UNDEF }, "password", i4_password },
    { { HTML_2_0 }, { HTML_UNDEF }, "radio", i4_radio },
    { { HTML_2_0 }, { HTML_UNDEF }, "reset", i4_reset },
    { { HTML_2_0 }, { HTML_UNDEF }, "submit", i4_submit },
    { { HTML_2_0 }, { HTML_UNDEF }, "text", i4_text } };

struct symbol_entry < html_version, e_inputtype5 > inputtype5_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "button", i5_button },
    { { HTML_2_0 }, { HTML_UNDEF }, "checkbox", i5_checkbox },
    { { HTML_JAN05 }, { HTML_UNDEF }, "color", i5_colour },
    { { HTML_JAN05 }, { HTML_UNDEF }, "date", i5_date },
    { { HTML_JAN05, HV_NOT50 }, { HTML_UNDEF }, "datetime", i5_datetime },
    { { HTML_JAN05, HV_NOT50 }, { HTML_UNDEF }, "datetime-local", i5_datetime_local },
    { { HTML_JAN05 }, { HTML_UNDEF }, "email", i5_email },
    { { 2, 1 }, { HTML_UNDEF }, "file", i5_file },
    { { HTML_2_0 }, { HTML_UNDEF }, "hidden", i5_hidden },
    { { HTML_2_0 }, { HTML_UNDEF }, "image", i5_image },
    { { HTML_JAN05, HV_NOT50 }, { HTML_UNDEF }, "month", i5_month },
    { { HTML_JAN05 }, { HTML_UNDEF }, "number", i5_number },
    { { HTML_2_0 }, { HTML_UNDEF }, "password", i5_password },
    { { HTML_2_0 }, { HTML_UNDEF }, "radio", i5_radio },
    { { HTML_2_0 }, { HTML_UNDEF }, "reset", i5_reset },
    { { HTML_3_0 }, { HTML_UNDEF }, "range", i5_range },
    { { HTML_JAN05 }, { HTML_UNDEF }, "search", i5_search },
    { { HTML_2_0 }, { HTML_UNDEF }, "submit", i5_submit },
    { { HTML_JAN05 }, { HTML_UNDEF }, "tel", i5_tel },
    { { HTML_2_0 }, { HTML_UNDEF }, "text", i5_text },
    { { HTML_JAN05 }, { HTML_UNDEF }, "time", i5_time },
    { { HTML_JAN05 }, { HTML_UNDEF }, "url", i5_url },
    { { HTML_JAN05, HV_NOT50 }, { HTML_UNDEF }, "week", i5_week } };

struct symbol_entry < html_version, e_kind > kind_symbol_table [] =
{   { { HTML_JUL10 }, { HTML_UNDEF }, "subtitles", k_subtitles },
    { { HTML_JUL10 }, { HTML_UNDEF }, "captions", k_captions },
    { { HTML_JUL10 }, { HTML_UNDEF }, "descriptions", k_descriptions },
    { { HTML_JUL10 }, { HTML_UNDEF }, "chapters", k_chapters },
    { { HTML_JUL10 }, { HTML_UNDEF }, "metadata", k_metadata } };

struct symbol_entry < html_version, e_length_absolute > length_absolute_symbol_table [] =
{   { { HTML_4_0, HL_CSS_ALL }, { HTML_UNDEF }, "cm", l_cm },
    { { HTML_4_0, HL_CSS_ALL }, { HTML_UNDEF }, "mm", l_mm },
    { { HTML_JUL19, HL_CSS_345 }, { HTML_UNDEF }, "q", l_q }, // with CSS 3
    { { HTML_4_0, HL_CSS_ALL }, { HTML_UNDEF }, "in", l_in },
    { { HTML_4_0, HL_CSS_ALL }, { HTML_UNDEF }, "pc", l_pc },
    { { HTML_4_0, HL_CSS_ALL }, { HTML_UNDEF }, "pt", l_pt },
    { { HTML_4_0, HL_CSS_ALL }, { HTML_UNDEF }, "px", l_px } };

struct symbol_entry < html_version, e_length_relative > length_relative_symbol_table [] =
{   { { HTML_3_2, HL_CSS_ALL }, { HTML_UNDEF }, "%", l_percent },
    { { HTML_4_0 }, { HTML_4_01 }, "*", l_star },
    { { HTML_4_0, HL_CSS_ALL }, { HTML_UNDEF }, "em", l_em },
    { { HTML_4_0, HL_CSS_ALL }, { HTML_UNDEF }, "ex", l_ex },
    { { HTML_JAN21, HL_CSS_45 }, { HTML_UNDEF }, "cap", l_cap },
    { { HTML_JUL19, HL_CSS_345 }, { HTML_UNDEF }, "ch", l_ch },
    { { HTML_JAN21, HL_CSS_45 }, { HTML_UNDEF }, "ic", l_ic },
    { { HTML_JUL19, HL_CSS_345 }, { HTML_UNDEF }, "rem", l_rem },
    { { HTML_JAN21, HL_CSS_45 }, { HTML_UNDEF }, "lh", l_lh },
    { { HTML_JAN21, HL_CSS_45 }, { HTML_UNDEF }, "rlh", l_rlh },
    { { HTML_JAN21, HL_CSS_45 }, { HTML_UNDEF }, "vw", l_vw },
    { { HTML_JAN21, HL_CSS_45 }, { HTML_UNDEF }, "vh", l_vh },
    { { HTML_JAN21, HL_CSS_45 }, { HTML_UNDEF }, "vi", l_vi },
    { { HTML_JAN21, HL_CSS_45 }, { HTML_UNDEF }, "vb", l_vb },
    { { HTML_JAN21, HL_CSS_45 }, { HTML_UNDEF }, "vmin", l_vmin },
    { { HTML_JAN21, HL_CSS_45 }, { HTML_UNDEF }, "vmax", l_vmax } };

struct symbol_entry < html_version, e_linebreak > linebreak_symbol_table [] =
{   { { XHTML_1_0 }, { HTML_UNDEF }, "auto", lb_auto },
    { { XHTML_1_0 }, { HTML_UNDEF }, "newline", lb_newline },
    { { XHTML_1_0 }, { HTML_UNDEF }, "indentingnewline", lb_indentingnewline },
    { { XHTML_1_0 }, { HTML_UNDEF }, "nobreak", lb_nobreak },
    { { XHTML_1_0 }, { HTML_UNDEF }, "goodbreak", lb_goodbreak },
    { { XHTML_1_0 }, { HTML_UNDEF }, "badbreak", lb_badbreak } };

struct symbol_entry < html_version, e_linkparam > linkparam_symbol_table [] =
{   { { HTML_NOV17 }, { HTML_UNDEF }, "anchor", lp_anchor },
    { { HTML_NOV17 }, { HTML_UNDEF }, "hreflang", lp_hreflang },
    { { HTML_NOV17 }, { HTML_UNDEF }, "media", lp_media },
    { { HTML_NOV17 }, { HTML_UNDEF }, "rel", lp_rel },
    { { HTML_NOV17 }, { HTML_UNDEF }, "rev", lp_rev },
    { { HTML_NOV17 }, { HTML_UNDEF }, "title", lp_title },
    { { HTML_NOV17 }, { HTML_UNDEF }, "title*", lp_titlestar },
    { { HTML_NOV17 }, { HTML_UNDEF }, "type", lp_type } };

struct symbol_entry < html_version, e_listtype > listtype_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "1", li_1 },
    { { HTML_UNDEF }, { HTML_UNDEF }, "a", li_a },
    { { HTML_UNDEF }, { HTML_UNDEF }, "A", li_A },
    { { HTML_UNDEF }, { HTML_UNDEF }, "i", li_i },
    { { HTML_UNDEF }, { HTML_UNDEF }, "I", li_I } };

struct symbol_entry < html_version, e_longdivstyle > longdivstyle_symbol_table [] =
{   { { HTML_5_2 }, { HTML_UNDEF }, "lefttop", ls_lefttop },
    { { HTML_5_2 }, { HTML_UNDEF }, "stackedrightright", ls_stackedrightright },
    { { HTML_5_2 }, { HTML_UNDEF }, "mediumstackedrightright", ls_mediumstackedrightright },
    { { HTML_5_2 }, { HTML_UNDEF }, "shortstackedrightright", ls_shortstackedrightright },
    { { HTML_5_2 }, { HTML_UNDEF }, "righttop", ls_righttop },
    { { HTML_5_2 }, { HTML_UNDEF }, "left/\\right", ls_leftslashright },
    { { HTML_5_2 }, { HTML_UNDEF }, "left)(right", ls_leftketbraright },
    { { HTML_5_2 }, { HTML_UNDEF }, ":right=right", ls_rightequalright },
    { { HTML_5_2 }, { HTML_UNDEF }, "stackedleftleft", ls_stackedleftleft },
    { { HTML_5_2 }, { HTML_UNDEF }, "stackedleftlinetop", ls_stackedleftlinetop } };

struct symbol_entry < html_version, e_mah > mah_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "go", mah_go },
    { { HTML_UNDEF }, { HTML_UNDEF }, "done", mah_done },
    { { HTML_UNDEF }, { HTML_UNDEF }, "next", mah_next },
    { { HTML_UNDEF }, { HTML_UNDEF }, "search", mah_search },
    { { HTML_UNDEF }, { HTML_UNDEF }, "send", mah_send } };

struct symbol_entry < html_version, e_mathalign > mathalign_symbol_table [] =
{   { { XHTML_1_0 }, { HTML_UNDEF }, "axis", ma_axis },
    { { XHTML_1_0 }, { HTML_UNDEF }, "baseline", ma_baseline },
    { { XHTML_1_0 }, { HTML_UNDEF }, "bottom", ma_bottom },
    { { XHTML_1_0 }, { HTML_UNDEF }, "center", ma_centre },
    { { XHTML_1_0 }, { HTML_UNDEF }, "top", ma_top } };

struct symbol_entry < html_version, e_mathlocation > mathlocation_symbol_table [] =
{   { { HTML_5_2 }, { HTML_UNDEF }, "w", ml_w },
    { { HTML_5_2 }, { HTML_UNDEF }, "nw", ml_nw },
    { { HTML_5_2 }, { HTML_UNDEF }, "n", ml_n },
    { { HTML_5_2 }, { HTML_UNDEF }, "ne", ml_ne },
    { { HTML_5_2 }, { HTML_UNDEF }, "e", ml_e },
    { { HTML_5_2 }, { HTML_UNDEF }, "se", ml_se },
    { { HTML_5_2 }, { HTML_UNDEF }, "s", ml_s },
    { { HTML_5_2 }, { HTML_UNDEF }, "sw", ml_sw } };

struct symbol_entry < html_version, e_mathoverflow > mathoverflow_symbol_table [] =
{   { { XHTML_1_0 }, { HTML_UNDEF }, "elide", ov_elide },
    { { HTML_5_2 }, { HTML_UNDEF }, "linebreak", ov_linebreak },
    { { XHTML_1_0 }, { HTML_UNDEF }, "scale", ov_scale },
    { { XHTML_1_0 }, { HTML_UNDEF }, "scroll", ov_scroll },
    { { XHTML_1_0 }, { HTML_UNDEF }, "truncate", ov_truncate } };

struct symbol_entry < html_version, e_mathnotation > mathnotation_symbol_table [] =
{   { { XHTML_1_0 }, { HTML_UNDEF }, "longdiv", mn_longdiv },
    { { XHTML_1_0 }, { HTML_UNDEF }, "actuarial", mn_actuarial },
    { { XHTML_1_0 }, { HTML_UNDEF }, "radical", mn_radical },
    { { XHTML_1_0 }, { HTML_UNDEF }, "box", mn_box },
    { { XHTML_1_0 }, { HTML_UNDEF }, "roundedbox", mn_roundedbox },
    { { XHTML_1_0 }, { HTML_UNDEF }, "circle", mn_circle },
    { { XHTML_1_0 }, { HTML_UNDEF }, "left", mn_left },
    { { XHTML_1_0 }, { HTML_UNDEF }, "right", mn_right },
    { { XHTML_1_0 }, { HTML_UNDEF }, "top", mn_top },
    { { XHTML_1_0 }, { HTML_UNDEF }, "bottom", mn_bottom },
    { { XHTML_1_0 }, { HTML_UNDEF }, "updiagonalstrike", mn_updiagonalstrike },
    { { XHTML_1_0 }, { HTML_UNDEF }, "downdiagonalstrike", mn_downdiagonalstrike },
    { { XHTML_1_0 }, { HTML_UNDEF }, "verticalstrike", mn_verticalstrike },
    { { XHTML_1_0 }, { HTML_UNDEF }, "horizontalstrike", mn_horizontalstrike },
    { { HTML_5_2 }, { HTML_UNDEF }, "phasorangle", mn_phasorangle },
    { { HTML_5_2, 0, HE_M3_NONSTAND }, { HTML_UNDEF }, "mn_uparrow", mn_uparrow },
    { { HTML_5_2, 0, HE_M3_NONSTAND }, { HTML_UNDEF }, "mn_rightarrow", mn_rightarrow },
    { { HTML_5_2, 0, HE_M3_NONSTAND }, { HTML_UNDEF }, "mn_downarrow", mn_downarrow },
    { { HTML_5_2, 0, HE_M3_NONSTAND }, { HTML_UNDEF }, "mn_leftarrow", mn_leftarrow },
    { { HTML_5_2, 0, HE_M3_NONSTAND }, { HTML_UNDEF }, "mn_northwestarrow", mn_northwestarrow },
    { { HTML_5_2, 0, HE_M3_NONSTAND }, { HTML_UNDEF }, "mn_southwestarrow", mn_southwestarrow },
    { { HTML_5_2, 0, HE_M3_NONSTAND }, { HTML_UNDEF }, "mn_southeastarrow", mn_southeastarrow },
    { { HTML_5_2 }, { HTML_UNDEF }, "northeastarrow", mn_northeastarrow },
    { { HTML_5_2, 0, HE_M3_NONSTAND }, { HTML_UNDEF }, "mn_updownarrow", mn_updownarrow },
    { { HTML_5_2, 0, HE_M3_NONSTAND }, { HTML_UNDEF }, "mn_leftrightarrow", mn_leftrightarrow },
    { { HTML_5_2, 0, HE_M3_NONSTAND }, { HTML_UNDEF }, "mn_northwestsoutheastarrow", mn_northwestsoutheastarrow },
    { { HTML_5_2, 0, HE_M3_NONSTAND }, { HTML_UNDEF }, "mn_northeastsouthwestarrow", mn_northeastsouthwestarrow },
    { { HTML_5_2 }, { HTML_UNDEF }, "madruwb", mn_madruwb } };

struct symbol_entry < html_version, e_mathvariant > mathvariant_symbol_table [] =
{   { { XHTML_1_0 }, { HTML_UNDEF }, "normal", mv_normal },
    { { XHTML_1_0 }, { HTML_UNDEF }, "bold", mv_bold },
    { { XHTML_1_0 }, { HTML_UNDEF }, "italic", mv_italic },
    { { XHTML_1_0 }, { HTML_UNDEF }, "bold-italic", mv_bolditalic },
    { { XHTML_1_0 }, { HTML_UNDEF }, "double-struck", mv_doublestruck },
    { { XHTML_1_0 }, { HTML_UNDEF }, "bold-fraktur", mv_boldfraktur },
    { { XHTML_1_0 }, { HTML_UNDEF }, "script", mv_script },
    { { XHTML_1_0 }, { HTML_UNDEF }, "bold-script", mv_boldscript },
    { { XHTML_1_0 }, { HTML_UNDEF }, "fraktur", mv_fraktur },
    { { XHTML_1_0 }, { HTML_UNDEF }, "sans-serif", mv_sansserif },
    { { XHTML_1_0 }, { HTML_UNDEF }, "bold-sans-serif", mv_boldsansserif },
    { { XHTML_1_0 }, { HTML_UNDEF }, "sans-serif-italic", mv_sansserifitalic },
    { { XHTML_1_0 }, { HTML_UNDEF }, "sans-serif-bold-italic", mv_sansserifbolditalic },
    { { XHTML_1_0 }, { HTML_UNDEF }, "monospace", mv_monospace },
    { { HTML_5_2 }, { HTML_UNDEF }, "initial", mv_initial },
    { { HTML_5_2 }, { HTML_UNDEF }, "tailed", mv_tailed },
    { { HTML_5_2 }, { HTML_UNDEF }, "looped", mv_looped },
    { { HTML_5_2 }, { HTML_UNDEF }, "stretched", mv_stretched } };

struct symbol_entry < html_version, e_matrixtype > matrixtype_symbol_table [] =
{   { { HTML_SVG10 }, { HTML_UNDEF }, "matrix", mt_matrix },
    { { HTML_SVG10 }, { HTML_UNDEF }, "saturate", mt_saturate },
    { { HTML_SVG10 }, { HTML_UNDEF }, "hueRotate", mt_hue_rotate },
    { { HTML_SVG11 }, { HTML_UNDEF }, "hue-rotate", mt_hue_rotate },
    { { HTML_SVG10 }, { HTML_UNDEF }, "luminanceToAlpha", mt_luminance_alpha },
    { { HTML_SVG11 }, { HTML_UNDEF }, "luminance-to-alpha", mt_luminance_alpha } };

struct symbol_entry < html_version, e_media > media_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "all", md_all },
    { { HTML_4_0 }, { HTML_UNDEF }, "aural", md_aural },
    { { HTML_4_0 }, { HTML_UNDEF }, "braille", md_braille },
    { { HTML_4_0 }, { HTML_UNDEF }, "embossed", md_embossed },
    { { HTML_4_0 }, { HTML_UNDEF }, "handheld", md_handheld },
    { { HTML_4_0 }, { HTML_UNDEF }, "print", md_print },
    { { HTML_4_0 }, { HTML_UNDEF }, "projection", md_projection },
    { { HTML_4_0 }, { HTML_UNDEF }, "screen", md_screen },
    { { HTML_4_0 }, { HTML_UNDEF }, "speech", md_speech },
    { { HTML_4_0 }, { HTML_UNDEF }, "tty", md_tty },
    { { HTML_4_0 }, { HTML_UNDEF }, "tv", md_tv } };

struct symbol_entry < html_version, e_mediafeature > mediafeature_symbol_table [] =
{   { { HTML_JAN05 }, { HTML_UNDEF }, "width", mef_width },
    { { HTML_JAN05 }, { HTML_UNDEF }, "min-width", mef_min_width },
    { { HTML_JAN05 }, { HTML_UNDEF }, "max-width", mef_max_width },
    { { HTML_JAN05 }, { HTML_UNDEF }, "height", mef_height },
    { { HTML_JAN05 }, { HTML_UNDEF }, "min-height", mef_min_height },
    { { HTML_JAN05 }, { HTML_UNDEF }, "max-height", mef_max_height },
    { { HTML_JAN05 }, { HTML_UNDEF }, "device-width", mef_device_width },
    { { HTML_JAN05 }, { HTML_UNDEF }, "min-device-width", mef_min_device_width },
    { { HTML_JAN05 }, { HTML_UNDEF }, "max-device-width", mef_max_device_width },
    { { HTML_JAN05 }, { HTML_UNDEF }, "device-height", mef_device_height },
    { { HTML_JAN05 }, { HTML_UNDEF }, "min-device-height", mef_min_device_height },
    { { HTML_JAN05 }, { HTML_UNDEF }, "max-device-height", mef_max_device_height },
    { { HTML_JAN05 }, { HTML_UNDEF }, "orientation", mef_orientation },
    { { HTML_JAN05 }, { HTML_UNDEF }, "aspect-ration", mef_aspect_ration },
    { { HTML_JAN05 }, { HTML_UNDEF }, "min-aspect-ration", mef_min_aspect_ration },
    { { HTML_JAN05 }, { HTML_UNDEF }, "max-aspect-ration", mef_max_aspect_ration },
    { { HTML_JAN05 }, { HTML_UNDEF }, "device-aspect-ratio", mef_device_aspect_ratio },
    { { HTML_JAN05 }, { HTML_UNDEF }, "min-device-aspect-ratio", mef_min_device_aspect_ratio },
    { { HTML_JAN05 }, { HTML_UNDEF }, "max-device-aspect-ratio", mef_max_device_aspect_ratio },
    { { HTML_JAN05 }, { HTML_UNDEF }, "color", mef_colour },
    { { HTML_JAN05 }, { HTML_UNDEF }, "min-color", mef_min_colour },
    { { HTML_JAN05 }, { HTML_UNDEF }, "max-color", mef_max_colour },
    { { HTML_JAN05 }, { HTML_UNDEF }, "color-index", mef_colour_index },
    { { HTML_JAN05 }, { HTML_UNDEF }, "min-color-index", mef_min_colour_index },
    { { HTML_JAN05 }, { HTML_UNDEF }, "max-color-index", mef_max_colour_index },
    { { HTML_JAN05 }, { HTML_UNDEF }, "monochrome", mef_monochrome },
    { { HTML_JAN05 }, { HTML_UNDEF }, "min-monochrome", mef_min_monochrome },
    { { HTML_JAN05 }, { HTML_UNDEF }, "max-monochrome", mef_max_monochrome },
    { { HTML_JAN05 }, { HTML_UNDEF }, "resolution", mef_resolution },
    { { HTML_JAN05 }, { HTML_UNDEF }, "min-resolution", mef_min_resolution },
    { { HTML_JAN05 }, { HTML_UNDEF }, "max-resolution", mef_max_resolution },
    { { HTML_JAN05 }, { HTML_UNDEF }, "grid", mef_grid },
    { { HTML_JAN05 }, { HTML_UNDEF }, "hover", mef_hover },
    { { HTML_JAN05 }, { HTML_UNDEF }, "pointer", mef_pointer },
    { { HTML_JAN05 }, { HTML_UNDEF }, "any-hover", mef_any_hover },
    { { HTML_JAN05 }, { HTML_UNDEF }, "any-pointer", mef_any_pointer },
    { { HTML_JAN05 }, { HTML_UNDEF }, "color-gamut", mef_colour_gamut },
    { { HTML_JAN05 }, { HTML_UNDEF }, "overflow-block", mef_overflow_block },
    { { HTML_JAN05 }, { HTML_UNDEF }, "overflow-inline", mef_overflow_inline },
    { { HTML_JAN05 }, { HTML_UNDEF }, "scan", mef_scan },
    { { HTML_JAN05 }, { HTML_UNDEF }, "update", mef_update } };

struct symbol_entry < html_version, e_mediakeyword > mediakeyword_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "and", mk_and },
    { { HTML_JAN05 }, { HTML_UNDEF }, "=", mk_eq },
    { { HTML_JAN05 }, { HTML_UNDEF }, ">=", mk_ge },
    { { HTML_JAN05 }, { HTML_UNDEF }, ">", mk_gt },
    { { HTML_4_0 }, { HTML_UNDEF }, "ident", mk_ident },
    { { HTML_JAN05 }, { HTML_UNDEF }, "<=", mk_le },
    { { HTML_JAN05 }, { HTML_UNDEF }, "<", mk_lt },
    { { HTML_JAN05 }, { HTML_UNDEF }, "or", mk_or },
    { { HTML_4_0 }, { HTML_UNDEF }, "not", mk_not },
    { { HTML_4_0 }, { HTML_UNDEF }, "only", mk_only } };

struct symbol_entry < html_version, e_method > method_symbol_table [] =
{   { { HTML_PLUS }, { HTML_PLUS }, "delete", md_delete },
    { { HTML_JUL12, HV_NOT50 | HV_NOT51 }, { HTML_UNDEF }, "dialog", md_dialogue },
    { { HTML_PLUS }, { HTML_UNDEF }, "get", md_get },
    { { HTML_PLUS }, { HTML_UNDEF }, "post", md_post },
    { { HTML_PLUS }, { HTML_PLUS }, "put", md_put } };

struct symbol_entry < html_version, e_mf_identifier > mf_identifier_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "model", mfi_model },
    { { HTML_4_0 }, { HTML_UNDEF }, "mpn", mfi_mpn },
    { { HTML_4_0 }, { HTML_UNDEF }, "upc", mfi_upc },
    { { HTML_4_0 }, { HTML_UNDEF }, "isbn", mfi_isbn },
    { { HTML_4_0 }, { HTML_UNDEF }, "issn", mfi_issn },
    { { HTML_4_0 }, { HTML_UNDEF }, "ean", mfi_ean },
    { { HTML_4_0 }, { HTML_UNDEF }, "jan", mfi_jan },
    { { HTML_4_0 }, { HTML_UNDEF }, "place", mfi_sn },
    { { HTML_4_0 }, { HTML_UNDEF }, "mvin", mfi_vin },
    { { HTML_4_0 }, { HTML_UNDEF }, "msku", mfi_sku } };

struct symbol_entry < html_version, e_mf_itemtype > mf_itemtype_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "opening", mfit_opening },
    { { HTML_4_0 }, { HTML_UNDEF }, "housing", mfit_housing },
    { { HTML_4_0 }, { HTML_UNDEF }, "product", mfit_product },
    { { HTML_4_0 }, { HTML_UNDEF }, "business", mfit_business },
    { { HTML_4_0 }, { HTML_UNDEF }, "event", mfit_event },
    { { HTML_4_0 }, { HTML_UNDEF }, "person", mfit_person },
    { { HTML_4_0 }, { HTML_UNDEF }, "place", mfit_place },
    { { HTML_4_0 }, { HTML_UNDEF }, "website", mfit_website },
    { { HTML_4_0 }, { HTML_UNDEF }, "url", mfit_url } };

struct symbol_entry < html_version, e_mf_listing_action > mf_listing_action_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "sell", mfla_sell },
    { { HTML_4_0 }, { HTML_UNDEF }, "rent", mfla_rent },
    { { HTML_4_0 }, { HTML_UNDEF }, "trade", mfla_trade },
    { { HTML_4_0 }, { HTML_UNDEF }, "meet", mfla_meet },
    { { HTML_4_0 }, { HTML_UNDEF }, "announce", mfla_announce },
    { { HTML_4_0 }, { HTML_UNDEF }, "offer", mfla_offer },
    { { HTML_4_0 }, { HTML_UNDEF }, "wanted", mfla_wanted },
    { { HTML_4_0 }, { HTML_UNDEF }, "event", mfla_event },
    { { HTML_4_0 }, { HTML_UNDEF }, "service", mfla_service } };

struct symbol_entry < html_version, e_mf_method > mf_method_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "publish", mfm_publish },
    { { HTML_4_0 }, { HTML_UNDEF }, "request", mfm_request },
    { { HTML_4_0 }, { HTML_UNDEF }, "reply", mfm_reply },
    { { HTML_4_0 }, { HTML_UNDEF }, "add", mfm_add },
    { { HTML_4_0 }, { HTML_UNDEF }, "cancel", mfm_cancel },
    { { HTML_4_0 }, { HTML_UNDEF }, "refresh", mfm_refresh },
    { { HTML_4_0 }, { HTML_UNDEF }, "counter", mfm_counter },
    { { HTML_4_0 }, { HTML_UNDEF }, "declinecounter", mfm_declinecounter } };

struct symbol_entry < html_version, e_mf_reviewtype > mf_reviewtype_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "product", mfr_product },
    { { HTML_4_0 }, { HTML_UNDEF }, "business", mfr_business },
    { { HTML_4_0 }, { HTML_UNDEF }, "event", mfr_event },
    { { HTML_4_0 }, { HTML_UNDEF }, "person", mfr_person },
    { { HTML_4_0 }, { HTML_UNDEF }, "place", mfr_place },
    { { HTML_4_0 }, { HTML_UNDEF }, "website", mfr_website },
    { { HTML_4_0 }, { HTML_UNDEF }, "url", mfr_url } };

struct symbol_entry < html_version, e_microdata_domain > microdata_domain_symbol_table [] =
{   { { HTML_4_01 }, { HTML_UNDEF }, MICROFORMATS_ORG, mdd_microformats },
    { { HTML_4_01 }, { HTML_UNDEF }, PURL_ORG, mdd_purl },
    { { HTML_4_01 }, { HTML_UNDEF }, SCHEMA_ORG, mdd_schema },
    { { HTML_JAN05 }, { HTML_UNDEF }, N_WHATWG_ORG, mdd_whatwg } };

struct symbol_entry < html_version, e_microdata_root > microdata_root_symbol_table [] =
{   { { HTML_4_01 }, { HTML_UNDEF }, "http://" MICROFORMATS_ORG "/", mdr_microformats },
    { { HTML_4_01 }, { HTML_UNDEF }, "https://" MICROFORMATS_ORG "/", mdr_microformats },
    { { HTML_4_01 }, { HTML_UNDEF }, "http://" PURL_ORG "/", mdr_purl },
    { { HTML_4_01 }, { HTML_UNDEF }, "https://" PURL_ORG "/", mdr_purl },
    { { HTML_4_01 }, { HTML_UNDEF }, "http://" SCHEMA_ORG "/", mdr_schema },
    { { HTML_4_01 }, { HTML_UNDEF }, "https://" SCHEMA_ORG "/", mdr_schema },
    { { HTML_JAN09 }, { HTML_UNDEF }, "http://" N_WHATWG_ORG "/", mdr_whatwg } /* no https */ };

struct symbol_entry < html_version, e_namedspace > namedspace_symbol_table [] =
{   { { XHTML_1_0 }, { HTML_UNDEF }, "negativeveryverythinmathspace", nd_negativeveryverythinmathspace },
    { { XHTML_1_0 }, { HTML_UNDEF }, "negativeverythinmathspace", nd_negativeverythinmathspace },
    { { XHTML_1_0 }, { HTML_UNDEF }, "negativethinmathspace", nd_negativethinmathspace },
    { { XHTML_1_0 }, { HTML_UNDEF }, "negativemediummathspace", nd_negativemediummathspace },
    { { XHTML_1_0 }, { HTML_UNDEF }, "negativethickmathspace", nd_negativethickmathspace },
    { { XHTML_1_0 }, { HTML_UNDEF }, "negativeverythickmathspace", nd_negativeverythickmathspace },
    { { XHTML_1_0 }, { HTML_UNDEF }, "negativeveryverythickmathspace", nd_negativeveryverythickmathspace },
    { { XHTML_1_0 }, { HTML_UNDEF }, "veryverythinmathspace", nd_veryverythinmathspace },
    { { XHTML_1_0 }, { HTML_UNDEF }, "verythinmathspace", nd_verythinmathspace },
    { { XHTML_1_0 }, { HTML_UNDEF }, "thinmathspace", nd_thinmathspace },
    { { XHTML_1_0 }, { HTML_UNDEF }, "mediummathspace", nd_mediummathspace },
    { { XHTML_1_0 }, { HTML_UNDEF }, "thickmathspace", nd_thickmathspace },
    { { XHTML_1_0 }, { HTML_UNDEF }, "verythickmathspace", nd_verythickmathspace },
    { { XHTML_1_0 }, { HTML_UNDEF }, "veryverythickmathspace", nd_veryverythickmathspace } };

struct symbol_entry < html_version, e_namespace > namespace_symbol_table [] =
{   { { XHTML_1_0 }, { HTML_UNDEF }, "bibo", ns_bibo },
    { { XHTML_1_0 }, { HTML_UNDEF }, "cc", ns_cc },
    { { XHTML_1_0 }, { HTML_UNDEF }, "crs", ns_crs },
    { { XHTML_1_0 }, { HTML_UNDEF }, "dbp", ns_dbp },
    { { XHTML_1_0 }, { HTML_UNDEF }, "dbp-owl", ns_dbp_owl },
    { { XHTML_1_0 }, { HTML_UNDEF }, "dbr", ns_dbr },
    { { XHTML_1_0 }, { HTML_UNDEF }, "dc", ns_dc },
    { { XHTML_1_0 }, { HTML_UNDEF }, "dcterms", ns_dcterms },
    { { HTML_SVG12, 0, HE_SVG_12 }, { HTML_UNDEF }, "ev", ns_ev },
    { { XHTML_1_0 }, { HTML_UNDEF }, "ex", ns_ex },
    { { XHTML_1_0 }, { HTML_UNDEF }, "foaf", ns_foaf },
    { { XHTML_1_0 }, { HTML_UNDEF }, "its", ns_its },
    { { XHTML_1_0 }, { HTML_UNDEF }, "math", ns_math },
    { { XHTML_1_0 }, { HTML_UNDEF }, "owl", ns_owl },
    { { XHTML_1_0 }, { HTML_UNDEF }, "rdf", ns_rdf },
    { { XHTML_1_0 }, { HTML_UNDEF }, "rdfa", ns_rdfa },
    { { XHTML_1_0 }, { HTML_UNDEF }, "rdfs", ns_rdfs },
    { { XHTML_1_0 }, { HTML_UNDEF }, "svg", ns_svg },
    { { XHTML_1_0 }, { HTML_UNDEF }, "xhv", ns_xhv },
    { { XHTML_1_0 }, { HTML_UNDEF }, "xlink", ns_xlink },
    { { XHTML_1_0 }, { HTML_UNDEF }, "xml", ns_xhtml },
    { { XHTML_1_0 }, { HTML_UNDEF }, XMLNS, ns_xmlns },
    { { XHTML_1_0 }, { HTML_UNDEF }, "xsd", ns_xsd },
    { { XHTML_1_0 }, { HTML_UNDEF }, "xsi", ns_xsi } };

struct symbol_entry < html_version, e_ogtype > ogtype_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "music.song", og_musicsong },
    { { HTML_UNDEF }, { HTML_UNDEF }, "music.album", og_musicalbum },
    { { HTML_UNDEF }, { HTML_UNDEF }, "music.playlist", og_musicplaylist },
    { { HTML_UNDEF }, { HTML_UNDEF }, "music.radio_station", og_musicradiostation },
    { { HTML_UNDEF }, { HTML_UNDEF }, "video.movie", og_videomovie },
    { { HTML_UNDEF }, { HTML_UNDEF }, "video.episode", og_videoepisode },
    { { HTML_UNDEF }, { HTML_UNDEF }, "video.tv_show", og_videotvshow },
    { { HTML_UNDEF }, { HTML_UNDEF }, "video.other", og_videoother },
    { { HTML_UNDEF }, { HTML_UNDEF }, "article", og_article },
    { { HTML_UNDEF }, { HTML_UNDEF }, "book", og_book },
    { { HTML_UNDEF }, { HTML_UNDEF }, "profile", og_profile },
    { { HTML_UNDEF }, { HTML_UNDEF }, "website", og_website } };

struct symbol_entry < html_version, e_paintkeyword > paintkeyword_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "none", pk_none },
    { { HTML_SVG20, 0, HE_SVG_20 }, { HTML_UNDEF }, "child", pk_child },
    { { HTML_SVG20, 0, HE_SVG_20 }, { HTML_UNDEF }, "context-fill", pk_contextfill  },
    { { HTML_SVG20, 0, HE_SVG_20 }, { HTML_UNDEF }, "context-stroke", pk_contextstroke },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "currentColor", pk_currentcolour },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "inherit", pk_inherit },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "icc-colour", pk_icccolour },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "url", pk_url } };

struct symbol_entry < html_version, e_plusstyle > plusstyle_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "b", ps_b },
    { { HTML_UNDEF }, { HTML_UNDEF }, "i", ps_i },
    { { HTML_UNDEF }, { HTML_UNDEF }, "p", ps_p },
    { { HTML_UNDEF }, { HTML_UNDEF }, "s", ps_s },
    { { HTML_UNDEF }, { HTML_UNDEF }, "sub", ps_sub },
    { { HTML_UNDEF }, { HTML_UNDEF }, "sup", ps_sup },
    { { HTML_UNDEF }, { HTML_UNDEF }, "tt", ps_tt },
    { { HTML_UNDEF }, { HTML_UNDEF }, "u", ps_u } };

struct symbol_entry < html_version, e_pointer_events > pointer_events_symbol_table [] =
{   { { HTML_SVG20, 0, HE_SVG_20 }, { HTML_UNDEF }, "bounding-box", pe_boundingbox },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "visiblePainted", pe_visiblepainted },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "visibleFill", pe_visiblefill },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "visibleStroke", pe_visiblestroke },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "visible", pe_visible },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "painted", pe_painted },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "fill", pe_fill },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "stroke", pe_stroke },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "all", pe_all },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "none", pe_none },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "inherit", pe_inherit } };

// a couple of these are only defined in the HTML+ text, not the DTD
struct symbol_entry < html_version, e_print > print_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "footnote", pt_footnote },
    { { HTML_UNDEF }, { HTML_UNDEF }, "reference", pt_reference },
    { { HTML_UNDEF }, { HTML_UNDEF }, "section", pt_section },
    { { HTML_UNDEF }, { HTML_UNDEF }, "sidebar", pt_sidebar },
    { { HTML_UNDEF }, { HTML_UNDEF }, "silent", pt_silent } };

struct symbol_entry < html_version, e_referrer > referrer_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "no-referrer", rf_no },
    { { HTML_UNDEF }, { HTML_UNDEF }, "no-referrer-when-downgrade", rf_downgrade },
    { { HTML_UNDEF }, { HTML_UNDEF }, "same-origin", rf_same },
    { { HTML_UNDEF }, { HTML_UNDEF }, "origin", rf_origin },
    { { HTML_UNDEF }, { HTML_UNDEF }, "strict-origin", rf_strict },
    { { HTML_UNDEF }, { HTML_UNDEF }, "strict-origin-when-cross-origin", rf_strictcross },
    { { HTML_UNDEF }, { HTML_UNDEF }, "origin-when-cross-origin", rf_cross },
    { { HTML_UNDEF }, { HTML_UNDEF }, "unsafe-url", rf_unsafe } };

struct symbol_entry < html_version, e_renderingintent > renderingintent_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG_10_11 }, { HTML_UNDEF }, "auto", ri_auto },
    { { HTML_SVG10, 0, HE_SVG_10_11 }, { HTML_UNDEF }, "perceptual", ri_perceptual },
    { { HTML_SVG10, 0, HE_SVG_10_11 }, { HTML_UNDEF }, "relative-colorimetric", ri_relativecolourimetric },
    { { HTML_SVG10, 0, HE_SVG_10_11 }, { HTML_UNDEF }, "saturation", ri_saturation },
    { { HTML_SVG10, 0, HE_SVG_10_11 }, { HTML_UNDEF }, "absolute-colorimetric", ri_absolutecolourimetric } };

struct symbol_entry < html_version, e_rules > rules_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "none", ru_none },
    { { HTML_2_0 }, { HTML_UNDEF }, "groups", ru_groups },
    { { HTML_2_0 }, { HTML_UNDEF }, "rows", ru_rows },
    { { HTML_2_0 }, { HTML_UNDEF }, "cols", ru_cols },
    { { HTML_2_0 }, { HTML_UNDEF }, "all", ru_all } };

struct symbol_entry < html_version, e_sandbox > sandbox_symbol_table [] =
{   { { HTML_JUL20, 0, HE_EXPERIMENTAL }, { HTML_UNDEF }, "allow-downloads-without-user-activation", s_adwua },
    { { HTML_JUL08, 0, HV_CSP_1 }, { HTML_UNDEF }, "allow-forms", s_forms },
    { { HTML_JAN16, 0, HV_CSP_1 }, { HTML_UNDEF }, "allow-modals", s_modals },
    { { HTML_JUL16, 0, HV_CSP_1 }, { HTML_UNDEF }, "allow-orientation-lock", s_orientation },
    { { HTML_JAN13, 0, HV_CSP_1 }, { HTML_UNDEF }, "allow-pointer-lock", s_pointer },
    { { HTML_JUL12, 0, HV_CSP_1 }, { HTML_UNDEF }, "allow-popups", s_popups },
    { { HTML_JAN16, 0, HV_CSP_1 }, { HTML_UNDEF }, "allow-popups-to-escape-sandbox", s_popupescape },
    { { HTML_JUL16, 0, HV_CSP_1 }, { HTML_UNDEF }, "allow-presentation", s_presentation },
    { { HTML_JUL08, 0, HV_CSP_1 }, { HTML_UNDEF }, "allow-same-origin", s_origin },
    { { HTML_JUL08, 0, HV_CSP_1 }, { HTML_UNDEF }, "allow-scripts", s_scripts },
    { { HTML_JUL20, 0, HV_CSP_1 }, { HTML_UNDEF }, "allow-storage-access-by-user-activation", s_asabua },
    { { HTML_JAN11, 0, HV_CSP_1 }, { HTML_UNDEF }, "allow-top-navigation", s_navigation },
    { { HTML_JUL17, 0, HV_CSP_1 }, { HTML_UNDEF }, "allow-top-navigation-by-user-activation", s_atnbua },
    { { HTML_JUL20 }, { HTML_UNDEF }, "allow-downloads", s_ad } };

struct symbol_entry < html_version, e_shape7 > shape7_symbol_table [] =
{   { { HTML_JAN05 }, { HTML_UNDEF }, "circle", s7_circ },
    { { HTML_JAN05 }, { HTML_UNDEF }, "circ", s7_circ },
    { { HTML_JAN05 }, { HTML_UNDEF }, "default", s7_default },
    { { HTML_JAN05 }, { HTML_UNDEF }, "poly", s7_poly },
    { { HTML_JAN05 }, { HTML_UNDEF }, "polygon", s7_poly },
    { { HTML_JAN05 }, { HTML_UNDEF }, "rect", s7_rect },
    { { HTML_JAN05 }, { HTML_UNDEF }, "rectangle", s7_rect } };

struct symbol_entry < html_version, e_shape_rendering > shape_rendering_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "auto", sr_auto },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "optimizeSpeed", sr_optimisespeed },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "crispEdges", sr_crispedges },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "geometricPrecision", sr_geometricprecision },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "inherit", sr_inherit } };

struct symbol_entry < html_version, e_ssi > ssi_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "comment", ssi_comment },
    { { HTML_UNDEF }, { HTML_UNDEF }, "config", ssi_config },
    { { HTML_UNDEF }, { HTML_UNDEF }, "echo", ssi_echo },
    { { HTML_UNDEF }, { HTML_UNDEF }, "elif", ssi_elif },
    { { HTML_UNDEF }, { HTML_UNDEF }, "else", ssi_else },
    { { HTML_UNDEF }, { HTML_UNDEF }, "endif", ssi_endif },
    { { HTML_UNDEF }, { HTML_UNDEF }, "exec", ssi_exec },
    { { HTML_UNDEF }, { HTML_UNDEF }, "fsize", ssi_fsize },
    { { HTML_UNDEF }, { HTML_UNDEF }, "flastmod", ssi_flastmod },
    { { HTML_UNDEF }, { HTML_UNDEF }, "if", ssi_if },
    { { HTML_UNDEF }, { HTML_UNDEF }, "include", ssi_include },
    { { HTML_UNDEF }, { HTML_UNDEF }, "printenv", ssi_printenv },
    { { HTML_UNDEF }, { HTML_UNDEF }, "set", ssi_set } };

struct symbol_entry < html_version, e_ssi_comparison > ssi_comparison_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "&&", ssi_comparison_and },
    { { HTML_UNDEF }, { HTML_UNDEF }, "=", ssi_comparison_eq },
    { { HTML_UNDEF }, { HTML_UNDEF }, "==", ssi_comparison_eq },
    { { HTML_UNDEF }, { HTML_UNDEF }, ">=", ssi_comparison_ge },
    { { HTML_UNDEF }, { HTML_UNDEF }, ">", ssi_comparison_gt },
    { { HTML_UNDEF }, { HTML_UNDEF }, "<=", ssi_comparison_le },
    { { HTML_UNDEF }, { HTML_UNDEF }, "<", ssi_comparison_lt },
    { { HTML_UNDEF }, { HTML_UNDEF }, "!=", ssi_comparison_ne },
    { { HTML_UNDEF }, { HTML_UNDEF }, "<>", ssi_comparison_ne },
    { { HTML_UNDEF }, { HTML_UNDEF }, "||", ssi_comparison_or } };

struct symbol_entry < html_version, e_ssi_encoding > ssi_encoding_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "base64", ssi_encoding_base64 },
    { { HTML_UNDEF }, { HTML_UNDEF }, "entity", ssi_encoding_entity },
    { { HTML_UNDEF }, { HTML_UNDEF }, "none", ssi_encoding_none },
    { { HTML_UNDEF }, { HTML_UNDEF }, "url", ssi_encoding_url },
    { { HTML_UNDEF }, { HTML_UNDEF }, "urlencoded", ssi_encoding_urlencoded } };

struct symbol_entry < html_version, e_ssi_env > ssi_env_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "date_gmt", ssi_DATE_GMT },
    { { HTML_UNDEF }, { HTML_UNDEF }, "date_local", ssi_DATE_LOCAL },
    { { HTML_UNDEF }, { HTML_UNDEF }, "document_args", ssi_DOCUMENT_ARGS },
    { { HTML_UNDEF }, { HTML_UNDEF }, "document_name", ssi_DOCUMENT_NAME },
    { { HTML_UNDEF }, { HTML_UNDEF }, "document_path_info", ssi_DOCUMENT_PATH_INFO },
    { { HTML_UNDEF }, { HTML_UNDEF }, "document_uri", ssi_DOCUMENT_URI },
    { { HTML_UNDEF }, { HTML_UNDEF }, "last_modified", ssi_LAST_MODIFIED },
    { { HTML_UNDEF }, { HTML_UNDEF }, "query_string_unescaped", ssi_QUERY_STRING_UNESCAPED },
    { { HTML_UNDEF }, { HTML_UNDEF }, "user_name", ssi_USER_NAME } };

struct symbol_entry < html_version, e_svg_align > svg_align_symbol_table [] =
{   { { HTML_SVG10 }, { HTML_UNDEF }, "none", sa_none },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xminymin", sa_xmin_ymin },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xmin_ymin", sa_xmin_ymin },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xmidymin", sa_xmid_ymin },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xmid_ymin", sa_xmid_ymin },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xmaxymin", sa_xmax_ymin },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xmax_ymin", sa_xmax_ymin },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xminymid", sa_xmin_ymid },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xmin_ymid", sa_xmin_ymid },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xmidymid", sa_xmid_ymid },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xmid_ymid", sa_xmid_ymid },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xmaxymid", sa_xmax_ymid },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xmax_ymid", sa_xmax_ymid },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xminymax", sa_xmin_ymax },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xmin_ymax", sa_xmin_ymax },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xmidymax", sa_xmid_ymax },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xmid_ymax", sa_xmid_ymax },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xmaxymax", sa_xmax_ymax },
    { { HTML_SVG10 }, { HTML_UNDEF }, "xmax_ymax", sa_xmax_ymax } };

struct symbol_entry < html_version, e_svg_display > svg_display_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "inline",  ds_inline },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "block", ds_block },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "list-item", ds_listitem },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "run-in", ds_runin },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "compact", ds_compact },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "marker", ds_marker },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "table", ds_table },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "inline-table", ds_inlinetable },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "table-row-group", ds_tablerowgroup },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "table-header-group", ds_tableheadergroup },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "table-footer-group", ds_tablefootergroup },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "table-row", ds_tablerow },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "table-column-group", ds_tablecolumngroup },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "table-column", ds_tablecolumn },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "table-cell", ds_tablecell },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "table-caption", ds_tablecaption },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "none", ds_none },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "inherit", ds_inherit } };

struct symbol_entry < html_version, e_svg_fontstretch > svg_fontstretch_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "normal",  fst_normal },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "wider",  fst_wider },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "narrower",  fst_narrower },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "ultra-condensed", fst_ultracondensed },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "extra-condensed", fst_extracondensed },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "condensed", fst_condensed },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "semi-condensed", fst_semicondensed },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "semi-expanded", fst_semiexpanded },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "expanded", fst_expanded },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "extra-expanded", fst_extraexpanded },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "ultra-expanded", fst_ultraexpanded },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "inherit", fst_inherit } };

struct symbol_entry < html_version, e_svg_fontstretch_ff > svg_fontstretch_ff_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "normal",  fff_normal },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "ultra-condensed",  fff_ultracondensed },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "extra-condensed", fff_extracondensed },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "condensed", fff_condensed },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "semi-condensed", fff_semicondensed },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "semi-expanded", fff_semiexpanded },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "expanded", fff_expanded },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "extra-expanded", fff_extraexpanded },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "ultra-expanded", fff_ultraexpanded } };

struct symbol_entry < html_version, e_svg_fontweight > svg_fontweight_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "normal",  fsw_normal },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "bold", fsw_bold },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "bolder", fsw_bolder },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lighter", fsw_lighter },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "100", fsw_100 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "200", fsw_200 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "300", fsw_300 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "400", fsw_400 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "500", fsw_500 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "600", fsw_600 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "700", fsw_700 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "800", fsw_800 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "900", fsw_900 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "inherit", fsw_inherit } };

struct symbol_entry < html_version, e_svg_fontweight_ff > svg_fontweight_ff_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "normal",  fsf_normal },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "bold", fsf_bold },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "100", fsf_100 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "200", fsf_200 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "300", fsf_300 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "400", fsf_400 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "500", fsf_500 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "600", fsf_600 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "700", fsf_700 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "800", fsf_800 },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "900", fsf_900 } };

struct symbol_entry < html_version, e_svg_mode > svg_mode_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "darken", sm_darken },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "lighten", sm_lighten },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "multiply", sm_multiply },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "normal", sm_normal },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "screen", sm_screen } };

struct symbol_entry < html_version, e_svg_overflow > svg_overflow_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "visible", sov_visible },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "hidden", sov_hidden },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "scroll", sov_scroll },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "auto", sov_auto },
    { { HTML_SVG10, 0, HE_SVG_10_11 }, { HTML_UNDEF }, "inherit", sov_inherit } };

struct symbol_entry < html_version, e_svg_type_11 > svg_type_11_symbol_table [] =
{   { { HTML_SVG11 }, { HTML_UNDEF }, "discrete", tsz_discrete },
    { { HTML_SVG11 }, { HTML_UNDEF }, "gamma", tsz_gamma },
    { { HTML_SVG11 }, { HTML_UNDEF }, "identity", tsz_identity },
    { { HTML_SVG11 }, { HTML_UNDEF }, "linear", tsz_linear },
    { { HTML_SVG11 }, { HTML_UNDEF }, "table", tsz_table } };

struct symbol_entry < html_version, e_svg_version > svg_version_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG_1 }, { HTML_UNDEF }, "1.0", sv_1_0 },
    { { HTML_SVG11, 0, HE_SVG_1 }, { HTML_UNDEF }, "1.1", sv_1_1 },
    { { HTML_SVG12, 0, HE_SVG_1 }, { HTML_UNDEF }, "1.2", sv_1_2_tiny },
    { { HTML_SVG12, 0, HE_SVG_1 }, { HTML_UNDEF }, "1.2/tiny", sv_1_2_tiny },
    { { HTML_SVG12, 0, HE_SVG_1 }, { HTML_UNDEF }, "1.2/full", sv_1_2_full },
    { { HTML_SVG20 }, { HTML_UNDEF }, "2.0", sv_2_0 } };

struct symbol_entry < html_version, e_svg_version_grand > svg_version_grand_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, HTTP_W3 "/tr/rec-mathml-19980407", svg_1_0 }, // MathML ??
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "http:s//www.w3.org/tr/rec-mathml-19980407", svg_1_0 },
    { { HTML_SVG11, 0, HE_SVG }, { HTML_UNDEF }, HTTP_W3 "/graphics/svg/svg-19990706.dtd", svg_1_1 },
    { { HTML_SVG11, 0, HE_SVG }, { HTML_UNDEF }, HTTPS_W3 "/graphics/svg/svg-19990706.dtd", svg_1_1 },
    { { HTML_SVG12, 0, HE_SVG }, { HTML_UNDEF }, HTTP_CSS SVG_2000, svg_2_0 }, // also tiny, of course
    { { HTML_SVG12, 0, HE_SVG }, { HTML_UNDEF }, HTTPS_CSS SVG_2000, svg_2_0 },
    { { HTML_SVG12, 0, HE_SVG }, { HTML_UNDEF }, HTTP_CSS SVG_2000 "/tiny", svg_1_2_tiny },
    { { HTML_SVG12, 0, HE_SVG }, { HTML_UNDEF }, HTTPS_CSS SVG_2000 "/tiny", svg_1_2_tiny },
    { { HTML_SVG12, 0, HE_SVG }, { HTML_UNDEF }, HTTP_CSS SVG_2000 "/full", svg_1_2_full },
    { { HTML_SVG12, 0, HE_SVG }, { HTML_UNDEF }, HTTPS_CSS SVG_2000 "/full", svg_1_2_full } };

struct symbol_entry < html_version, e_tableframe > tableframe_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "void", fr_void },
    { { HTML_2_0 }, { HTML_UNDEF }, "above", fr_above },
    { { HTML_2_0 }, { HTML_UNDEF }, "below", fr_below },
    { { HTML_2_0 }, { HTML_UNDEF }, "hsides", fr_hsides },
    { { HTML_2_0 }, { HTML_UNDEF }, "lhs", fr_lhs },
    { { HTML_2_0 }, { HTML_UNDEF }, "rhs", fr_rhs },
    { { HTML_2_0 }, { HTML_UNDEF }, "vsides", fr_vsides },
    { { HTML_2_0 }, { HTML_UNDEF }, "box", fr_box },
    { { HTML_2_0 }, { HTML_UNDEF }, "border", fr_border } };

struct symbol_entry < html_version, e_textdecoration > textdecoration_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "none", td_none },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "underline", td_underline },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "overline", td_overline },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "line-through", td_linethrough },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "blink", td_blink },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "inherit", td_inherit } };

struct symbol_entry < html_version, e_textrendering > textrendering_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "auto", tr_auto },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "optimizeSpeed", tr_optimisespeed },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "optimizeLegibility", tr_optimiselegibility },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "geometricPrecision", tr_geometricprecision },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "inherit", tr_inherit } };

struct symbol_entry < html_version, e_transform_anim > transform_anim_symbol_table [] =
{   { { HTML_SVG10 }, { HTML_UNDEF }, "translate", ta_translate },
    { { HTML_SVG10 }, { HTML_UNDEF }, "scale", ta_scale },
    { { HTML_SVG10 }, { HTML_UNDEF }, "rotate", ta_rotate },
    { { HTML_SVG10 }, { HTML_UNDEF }, "skewX", ta_skewx },
    { { HTML_SVG10 }, { HTML_UNDEF }, "skewY", ta_skewy } };

struct symbol_entry < html_version, e_transformbehaviour > transformbehaviour_symbol_table [] =
{   { { HTML_SVG10 }, { HTML_UNDEF }, "geometric", tb_geometric },
    { { HTML_SVG10 }, { HTML_UNDEF }, "pinned", tb_pinned },
    { { HTML_SVG10 }, { HTML_UNDEF }, "pinned90", tb_pinned90 },
    { { HTML_SVG10 }, { HTML_UNDEF }, "pinned180", tb_pinned180 },
    { { HTML_SVG10 }, { HTML_UNDEF }, "pinned170", tb_pinned270 } };


struct symbol_entry < html_version, e_transform_fn > transform_fn_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "matrix", tr_matrix },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "translate", tr_translate },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "scale", tr_scale },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "rotate", tr_rotate },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "skewX", tr_skewx },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "skewY", tr_skewy } };

struct symbol_entry < html_version, e_turbulence_type > turbulence_type_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "fractalNoise", tu_fractal_noise },
    { { HTML_4_0 }, { HTML_UNDEF }, "fractal-noise", tu_fractal_noise },
    { { HTML_4_0 }, { HTML_UNDEF }, "turbulence", tu_turbulence } };

struct symbol_entry < html_version, e_unit > unit_symbol_table [] =
{   { { HTML_JAN21 }, { HTML_UNDEF }, "cap", eu_cap },
    { { HTML_JUN19 }, { HTML_UNDEF }, "ch", eu_ch },
    { { HTML_SVG10 }, { HTML_UNDEF }, "cm", eu_cm },
    { { HTML_SVG10 }, { HTML_UNDEF }, "em", eu_em },
    { { HTML_SVG10 }, { HTML_UNDEF }, "ex", eu_ex },
    { { HTML_JAN21 }, { HTML_UNDEF }, "ic", eu_ic },
    { { HTML_SVG10 }, { HTML_UNDEF }, "in", eu_in },
    { { HTML_JAN21 }, { HTML_UNDEF }, "lh", eu_lh },
    { { HTML_SVG10 }, { HTML_UNDEF }, "mm", eu_mm },
    { { HTML_SVG10 }, { HTML_UNDEF }, "pc", eu_pc },
    { { HTML_SVG10 }, { HTML_UNDEF }, "pt", eu_pt },
    { { HTML_SVG10 }, { HTML_UNDEF }, "px", eu_px },
    { { HTML_JUN19 }, { HTML_UNDEF }, "Q", eu_q },
    { { HTML_JUN19 }, { HTML_UNDEF }, "rem", eu_rem },
    { { HTML_JAN21 }, { HTML_UNDEF }, "rlh", eu_rlh },
    { { HTML_JAN21 }, { HTML_UNDEF }, "vb", eu_vb },
    { { HTML_JUN19 }, { HTML_UNDEF }, "vh", eu_vh },
    { { HTML_JAN21 }, { HTML_UNDEF }, "vi", eu_vi },
    { { HTML_JUN19 }, { HTML_UNDEF }, "vmin", eu_vmin },
    { { HTML_JUN19 }, { HTML_UNDEF }, "vmax", eu_vmax },
    { { HTML_JUN19 }, { HTML_UNDEF }, "vw", eu_vw } };

struct symbol_entry < html_version, e_vectoreffect_2 > vectoreffect_2_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "fixed-position", v2_fixedposition },
    { { HTML_4_0 }, { HTML_UNDEF }, "none", v2_none },
    { { HTML_4_0 }, { HTML_UNDEF }, "non-rotation", v2_nonrotation },
    { { HTML_4_0 }, { HTML_UNDEF }, "non-scaling-stroke", v2_nonscalingstroke },
    { { HTML_4_0 }, { HTML_UNDEF }, "non-scaling-size", v2_nonscalingsize } };

struct symbol_entry < html_version, e_whitespace > whitespace_symbol_table [] =
{   { { HTML_JAN19 }, { HTML_UNDEF }, "normal", ws_normal },
    { { HTML_JAN19 }, { HTML_UNDEF }, "pre", ws_pre },
    { { HTML_JAN19 }, { HTML_UNDEF }, "nowrap", ws_nowrap },
    { { HTML_JAN19 }, { HTML_UNDEF }, "pre-wrap", ws_pre_wrap },
    { { HTML_JAN19 }, { HTML_UNDEF }, "break-spaces", ws_break_spaces },
    { { HTML_JAN19 }, { HTML_UNDEF }, "pre-line", ws_pre_line } };

struct symbol_entry < html_version, e_writingmode > writingmode_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "lr-tb", wm_lrtb },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "rl-tb", wm_rltb },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "tb-rl", wm_tbrl },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "lr", wm_lr },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "rl", wm_rl },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "tb", wm_tb },
    { { HTML_SVG10, 0, HE_SVG_10_11_20 }, { HTML_UNDEF }, "inherit", wm_inherit } };

struct symbol_entry < html_version, e_xmlns > xmlns_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, HTTP_CSS PURL_ORG "g/ontology/bibo/", x_bibo },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTPS_CSS PURL_ORG "/ontology/bibo/", x_bibo },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTP_W3 "/1999/xhtml", x_xhtml_1 },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTPS_W3 "/1999/xhtml", x_xhtml_1 },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTP_W3 "/TR/xhtml1/strict", x_xhtml_1_superseded },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTPS_W3 "/TR/xhtml1/strict", x_xhtml_1_superseded },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTP_W3 "/TR/xhtml1/transitional", x_xhtml_1_superseded },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTPS_W3 "/TR/xhtml1/transitional", x_xhtml_1_superseded },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTP_W3 "/TR/xhtml1/frameset", x_xhtml_1_superseded },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTPS_W3 "/TR/xhtml1/frameset", x_xhtml_1_superseded },
    { { XHTML_1_1 }, { HTML_UNDEF }, HTTP_W3 "/2000/xhtml", x_xhtml_11 },
    { { XHTML_1_1 }, { HTML_UNDEF }, HTTPS_W3 "/2000/xhtml", x_xhtml_11 },
    { { XHTML_2_0 }, { HTML_UNDEF }, HTTP_W3 "/2004/xhtml", x_xhtml_2 },
    { { XHTML_2_0 }, { HTML_UNDEF }, HTTPS_W3 "/2004/xhtml", x_xhtml_2 },
    { { HTML_4_0 }, { HTML_UNDEF }, "http://creativecommons.org/ns#", x_cc },
    { { HTML_4_0 }, { HTML_UNDEF }, "https://creativecommons.org/ns#", x_cc },
    { { XHTML_1_0 }, { HTML_UNDEF }, "http://www.ogc.org/crs", x_crs },
    { { XHTML_1_0 }, { HTML_UNDEF }, "https://www.ogc.org/crs", x_crs },
    { { HTML_4_0 }, { HTML_UNDEF }, "http://dbpedia.org/property/", x_dbp },
    { { HTML_4_0 }, { HTML_UNDEF }, "https://dbpedia.org/property/", x_dbp },
    { { HTML_4_0 }, { HTML_UNDEF }, "http://dbpedia.org/ontology/", x_dbp_owl },
    { { HTML_4_0 }, { HTML_UNDEF }, "https://dbpedia.org/ontology/", x_dbp_owl },
    { { HTML_4_0 }, { HTML_UNDEF }, "http://dbpedia.org/resource/", x_dbr },
    { { HTML_4_0 }, { HTML_UNDEF }, "https://dbpedia.org/resource/", x_dbr },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTP_CSS PURL_ORG "/dc/terms/", x_dc },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTPS_CSS PURL_ORG "g/dc/terms/", x_dc },
    { { HTML_4_0 }, { HTML_UNDEF }, "http://example.org/", x_ex },
    { { HTML_4_0 }, { HTML_UNDEF }, "https://example.org/", x_ex },
    { { HTML_4_0 }, { HTML_UNDEF }, "http://xmlns.com/foaf/0.1/", x_foaf },
    { { HTML_4_0 }, { HTML_UNDEF }, "https://xmlns.com/foaf/0.1/", x_foaf },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTP_W3 "/1998/math/mathml", x_mathml },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTPS_W3 "/1998/math/mathml", x_mathml },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTP_W3 "/2002/07/owl/#", x_owl },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTPS_W3 "/2002/07/owl/#", x_owl },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTP_W3 "/1999/02/22-rdf-syntax-ns#", x_rdf },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTPS_W3 "/1999/02/22-rdf-syntax-ns#", x_rdf },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTP_W3 "/ns/rdfa#", x_rdfa },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTPS_W3 "/ns/rdfa#", x_rdfa },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTP_W3 "/2000/01/rdf-schema#", x_rdfs },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTPS_W3 "/2000/01/rdf-schema#", x_rdfs },
    { { XHTML_1_1 }, { HTML_UNDEF }, HTTP_CSS SVG_2000, x_svg },
    { { XHTML_1_1 }, { HTML_UNDEF }, HTTPS_CSS SVG_2000, x_svg },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTP_W3 "/tr/rec-mathml-19980407", x_svg },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTPS_W3 "/tr/rec-mathml-19980407", x_svg },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTP_W3 "/graphics/svg/svg-19990706.dtd", x_svg },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTPS_W3 "/graphics/svg/svg-19990706.dtd", x_svg },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTP_W3 "/1999/xhtml/vocab#", x_xhv },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTPS_W3 "/1999/xhtml/vocab#", x_xhv },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTP_W3 "/1999/xlink", x_xlink },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTPS_W3 "/1999/xlink", x_xlink },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTP_W3 "/xml/1998/namespace", x_xml },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTPS_W3 "/xml/1998/namespace", x_xml },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTP_W3 "/2000/xmlns/", x_xmlns },
    { { XHTML_1_0 }, { HTML_UNDEF }, HTTPS_W3 "/2000/xmlns/", x_xmlns },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTP_W3 "/2001/XMLSchema#", x_xsd },
    { { HTML_4_0 }, { HTML_UNDEF }, HTTPS_W3 "/2001/XMLSchema#", x_xsd } };

#define INIT_ENUM(XX) \
    type_master < t_##XX > :: init (nits, XX##_symbol_table, sizeof (XX##_symbol_table) / sizeof (symbol_entry < html_version, e_##XX >)); \
    context.validation ().add_options () (VALIDATION #XX, ::boost::program_options::value < vstr_t > () -> composing (), "add a valid '" #XX "'; may be repeated")

void enum_init (nitpick& nits)
{   INIT_ENUM (action);
    INIT_ENUM (align3);
    INIT_ENUM (alignmentbaseline);
    INIT_ENUM (alignplus);
    INIT_ENUM (as);
    INIT_ENUM (autocapitalise);
    INIT_ENUM (autocomplete);
    INIT_ENUM (beginfn);
    INIT_ENUM (cachekey);
    INIT_ENUM (citype);
    INIT_ENUM (cookieid);
    INIT_ENUM (cntype);
    INIT_ENUM (composite_operator);
    INIT_ENUM (crossout);
    INIT_ENUM (cursor);
    INIT_ENUM (decalign);
    INIT_ENUM (dingbat);
    INIT_ENUM (dir);
    INIT_ENUM (display_align);
    INIT_ENUM (dominantbaseline);
    INIT_ENUM (enterkeyhint);
    INIT_ENUM (figalign);
    INIT_ENUM (filter_in);
    INIT_ENUM (fontname);
    INIT_ENUM (halign);
    INIT_ENUM (indentalign);
    INIT_ENUM (inky);
    INIT_ENUM (inputmode);
    INIT_ENUM (inputplus);
    INIT_ENUM (inputtype);
    INIT_ENUM (inputtype3);
    INIT_ENUM (inputtype32);
    INIT_ENUM (inputtype4);
    INIT_ENUM (inputtype5);
    INIT_ENUM (kind);
    INIT_ENUM (length_absolute);
    INIT_ENUM (length_relative);
    INIT_ENUM (linebreak);
    INIT_ENUM (linkparam);
    INIT_ENUM (listtype);
    INIT_ENUM (longdivstyle);
    INIT_ENUM (mah);
    INIT_ENUM (mathalign);
    INIT_ENUM (mathlocation);
    INIT_ENUM (mathnotation);
    INIT_ENUM (mathoverflow);
    INIT_ENUM (mathvariant);
    INIT_ENUM (matrixtype);
    INIT_ENUM (media);
    INIT_ENUM (mediafeature);
    INIT_ENUM (mediakeyword);
    INIT_ENUM (method);
    INIT_ENUM (mf_identifier);
    INIT_ENUM (mf_itemtype);
    INIT_ENUM (mf_listing_action);
    INIT_ENUM (mf_method);
    INIT_ENUM (mf_reviewtype);
    INIT_ENUM (microdata_domain);
    INIT_ENUM (microdata_root);
    INIT_ENUM (namedspace);
    INIT_ENUM (namespace);
    INIT_ENUM (ogtype);
    INIT_ENUM (paintkeyword);
    INIT_ENUM (plusstyle);
    INIT_ENUM (pointer_events);
    INIT_ENUM (print);
    INIT_ENUM (referrer);
    INIT_ENUM (renderingintent);
    INIT_ENUM (rules);
    INIT_ENUM (sandbox);
    INIT_ENUM (shape7);
    INIT_ENUM (shape_rendering);
    INIT_ENUM (ssi);
    INIT_ENUM (ssi_comparison);
    INIT_ENUM (ssi_encoding);
    INIT_ENUM (ssi_env);
    INIT_ENUM (svg_align);
    INIT_ENUM (svg_display);
    INIT_ENUM (svg_fontstretch);
    INIT_ENUM (svg_fontstretch_ff);
    INIT_ENUM (svg_fontweight);
    INIT_ENUM (svg_fontweight_ff);
    INIT_ENUM (svg_mode);
    INIT_ENUM (svg_overflow);
    INIT_ENUM (svg_type_11);
    INIT_ENUM (svg_version);
    INIT_ENUM (tableframe);
    INIT_ENUM (textdecoration);
    INIT_ENUM (textrendering);
    INIT_ENUM (transform_anim);
    INIT_ENUM (transformbehaviour);
    INIT_ENUM (transform_fn);
    INIT_ENUM (turbulence_type);
    INIT_ENUM (unit);
    INIT_ENUM (vectoreffect_2);
    INIT_ENUM (whitespace);
    INIT_ENUM (writingmode);
    INIT_ENUM (xmlns); }

e_namespace map_xmlns_to_namespace (const e_xmlns x)
{   switch (x)
    {   case x_bibo : return ns_bibo;
        case x_cc : return ns_cc;
        case x_crs : return ns_crs;
        case x_dbp : return ns_dbp;
        case x_dbp_owl : return ns_dbp_owl;
        case x_dbr : return ns_dbr;
        case x_dc : return ns_dc;
        case x_ex : return ns_ex;
        case x_foaf : return ns_foaf;
        case x_mathml : return ns_math;
        case x_owl : return ns_owl;
        case x_rdf : return ns_rdf;
        case x_rdfa : return ns_rdfa;
        case x_rdfs : return ns_rdfs;
        case x_svg : return ns_svg;
        case x_xhv : return ns_xhv;
        case x_xlink : return ns_xlink;
        case x_xsd : return ns_xsd;
        default : break; }
    return ns_default; }

   // ns_bibo
