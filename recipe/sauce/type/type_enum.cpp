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

#include "main/standard.h"
#include "type/type.h"

struct symbol_entry < e_action > action_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "sell", av_sell },
    { { HTML_UNDEF }, { HTML_UNDEF }, "rent", av_rent },
    { { HTML_UNDEF }, { HTML_UNDEF }, "trade", av_trade },
    { { HTML_UNDEF }, { HTML_UNDEF }, "meet", av_meet },
    { { HTML_UNDEF }, { HTML_UNDEF }, "announce", av_announce },
    { { HTML_UNDEF }, { HTML_UNDEF }, "offer", av_offer },
    { { HTML_UNDEF }, { HTML_UNDEF }, "wanted", av_wanted },
    { { HTML_UNDEF }, { HTML_UNDEF }, "event", av_event },
    { { HTML_UNDEF }, { HTML_UNDEF }, "service", av_service } };

struct symbol_entry < e_align3 > align3_symbol_table [] =
{   { { HTML_3_0 }, { HTML_UNDEF }, "top", a3_top },
    { { HTML_3_0 }, { HTML_UNDEF }, "middle", a3_middle },
    { { HTML_3_0 }, { HTML_UNDEF }, "bottom", a3_bottom },
    { { HTML_3_0 }, { HTML_UNDEF }, "left", a3_left },
    { { HTML_3_0 }, { HTML_UNDEF }, "right", a3_right } };

struct symbol_entry < e_alignmentbaseline > alignmentbaseline_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "auto",  ab_auto },
    { { HTML_4_0 }, { HTML_UNDEF }, "baseline", ab_baseline },
    { { HTML_4_0 }, { HTML_UNDEF }, "before-edge", ab_beforeedge },
    { { HTML_4_0 }, { HTML_UNDEF }, "text-before-edge", ab_textbeforeedge },
    { { HTML_4_0 }, { HTML_UNDEF }, "middle", ab_middle },
    { { HTML_4_0 }, { HTML_UNDEF }, "central", ab_central },
    { { HTML_4_0 }, { HTML_UNDEF }, "after-edge", ab_afteredge },
    { { HTML_4_0 }, { HTML_UNDEF }, "text-after-edge", ab_textafteredge },
    { { HTML_4_0 }, { HTML_UNDEF }, "ideographic", ab_ideographic },
    { { HTML_4_0 }, { HTML_UNDEF }, "alphabetic", ab_alphabetic },
    { { HTML_4_0 }, { HTML_UNDEF }, "hanging", ab_hanging },
    { { HTML_4_0 }, { HTML_UNDEF }, "mathematical", ab_mathematical },
    { { HTML_4_0 }, { HTML_UNDEF }, "inherit", ab_inherit } };

struct symbol_entry < e_alignplus > alignplus_symbol_table [] =
{   { { HTML_PLUS }, { HTML_PLUS }, "center", ap_centre },
    { { HTML_PLUS }, { HTML_PLUS }, "indent", ap_indent },
    { { HTML_PLUS }, { HTML_PLUS }, "justify", ap_justify },
    { { HTML_PLUS }, { HTML_PLUS }, "left", ap_left },
    { { HTML_PLUS }, { HTML_PLUS }, "right", ap_right } };

struct symbol_entry < e_as > as_symbol_table [] =
{   { { HTML_5_0 }, { HTML_UNDEF }, "audio", as_audio },
    { { HTML_5_0 }, { HTML_UNDEF }, "document", as_document },
    { { HTML_5_0 }, { HTML_UNDEF }, "embed", as_embed },
    { { HTML_5_0 }, { HTML_UNDEF }, "fetch", as_fetch },
    { { HTML_5_0 }, { HTML_UNDEF }, "font", as_font },
    { { HTML_5_0 }, { HTML_UNDEF }, "image", as_image },
    { { HTML_5_0 }, { HTML_UNDEF }, "object", as_object },
    { { HTML_5_0 }, { HTML_UNDEF }, "script", as_script },
    { { HTML_5_0 }, { HTML_UNDEF }, "style", as_style },
    { { HTML_5_0 }, { HTML_UNDEF }, "track", as_track },
    { { HTML_5_0 }, { HTML_UNDEF }, "video", as_video },
    { { HTML_5_0 }, { HTML_UNDEF }, "worker", as_worker } };

struct symbol_entry < e_autocapitalise54 > autocapitalise54_symbol_table [] =
{   { { HTML_3_0 }, { HTML_UNDEF }, "characters", ac4_characters },
    { { HTML_3_0 }, { HTML_UNDEF }, "default", ec4_default },
    { { HTML_3_0 }, { HTML_UNDEF }, "none", ac4_none },
    { { HTML_3_0 }, { HTML_UNDEF }, "sentences", ac4_sentences },
    { { HTML_3_0 }, { HTML_UNDEF }, "words", ac4_words } };

struct symbol_entry < e_autocomplete > autocomplete_symbol_table [] =
{   { { HTML_5_2 }, { HTML_UNDEF }, "additional-name", aco_additional_name },
    { { HTML_5_2 }, { HTML_UNDEF }, "address-level1", aco_address_level1 },
    { { HTML_5_2 }, { HTML_UNDEF }, "address-level2", aco_address_level2 },
    { { HTML_5_2 }, { HTML_UNDEF }, "address-level3", aco_address_level3 },
    { { HTML_5_2 }, { HTML_UNDEF }, "address-level4", aco_address_level4 },
    { { HTML_5_2 }, { HTML_UNDEF }, "address-line1", aco_address_line1 },
    { { HTML_5_2 }, { HTML_UNDEF }, "address-line2", aco_address_line2 },
    { { HTML_5_2 }, { HTML_UNDEF }, "address-line3", aco_address_line3 },
    { { HTML_5_2 }, { HTML_UNDEF }, "bday", aco_bday },
    { { HTML_5_2 }, { HTML_UNDEF }, "bday-day", aco_bday_day },
    { { HTML_5_2 }, { HTML_UNDEF }, "bday-month", aco_bday_month },
    { { HTML_5_2 }, { HTML_UNDEF }, "bday-year", aco_bday_year },
    { { HTML_5_2 }, { HTML_UNDEF }, "billing", aco_billing },
    { { HTML_5_2 }, { HTML_UNDEF }, "cc-additional-name", aco_cc_additional_name },
    { { HTML_5_2 }, { HTML_UNDEF }, "cc-csc", aco_cc_csc },
    { { HTML_5_2 }, { HTML_UNDEF }, "cc-exp", aco_cc_exp },
    { { HTML_5_2 }, { HTML_UNDEF }, "cc-exp-month", aco_cc_exp_month },
    { { HTML_5_2 }, { HTML_UNDEF }, "cc-exp-year", aco_cc_exp_year },
    { { HTML_5_2 }, { HTML_UNDEF }, "cc-family-name", aco_cc_family_name },
    { { HTML_5_2 }, { HTML_UNDEF }, "cc-given-name", aco_cc_given_name },
    { { HTML_5_2 }, { HTML_UNDEF }, "cc-name", aco_cc_name },
    { { HTML_5_2 }, { HTML_UNDEF }, "cc-number", aco_cc_number },
    { { HTML_5_2 }, { HTML_UNDEF }, "cc-type", aco_cc_type },
    { { HTML_5_2 }, { HTML_UNDEF }, "country", aco_country },
    { { HTML_5_2 }, { HTML_UNDEF }, "country-name", aco_country_name },
    { { HTML_5_2 }, { HTML_UNDEF }, "current-password", aco_current_password },
    { { HTML_5_2 }, { HTML_UNDEF }, "email", aco_email },
    { { HTML_5_2 }, { HTML_UNDEF }, "family-name,", aco_family_name },
    { { HTML_5_2 }, { HTML_UNDEF }, "fax", aco_fax },
    { { HTML_5_2 }, { HTML_UNDEF }, "given-name", aco_given_name },
    { { HTML_5_2 }, { HTML_UNDEF }, "home", aco_home },
    { { HTML_5_2 }, { HTML_UNDEF }, "honorific-prefix", aco_honorific_prefix },
    { { HTML_5_2 }, { HTML_UNDEF }, "honorific-suffix", aco_honorific_suffix },
    { { HTML_5_2 }, { HTML_UNDEF }, "impp", aco_impp },
    { { HTML_5_2 }, { HTML_UNDEF }, "language", aco_language },
    { { HTML_5_2 }, { HTML_UNDEF }, "mobile", aco_mobile },
    { { HTML_5_2 }, { HTML_UNDEF }, "name", aco_name },
    { { HTML_5_2 }, { HTML_UNDEF }, "new-password", aco_new_password },
    { { HTML_5_2 }, { HTML_UNDEF }, "nickname,", aco_nickname },
    { { HTML_5_2 }, { HTML_UNDEF }, "off", aco_off },
    { { HTML_5_2 }, { HTML_UNDEF }, "on", aco_on },
    { { HTML_5_2 }, { HTML_UNDEF }, "one-time-code", aco_one_time_code },
    { { HTML_5_2 }, { HTML_UNDEF }, "organization", aco_organization },
    { { HTML_5_2 }, { HTML_UNDEF }, "organization-title", aco_organization_title },
    { { HTML_5_2 }, { HTML_UNDEF }, "pager", aco_pager },
    { { HTML_5_2 }, { HTML_UNDEF }, "photo", aco_photo },
    { { HTML_5_2 }, { HTML_UNDEF }, "postal-code", aco_postal_code },
    { { HTML_5_2 }, { HTML_UNDEF }, "sex", aco_sex },
    { { HTML_5_2 }, { HTML_UNDEF }, "shipping", aco_shipping },
    { { HTML_5_2 }, { HTML_UNDEF }, "street-address", aco_street_address },
    { { HTML_5_2 }, { HTML_UNDEF }, "tel", aco_tel },
    { { HTML_5_2 }, { HTML_UNDEF }, "tel-area-code", aco_tel_area_code },
    { { HTML_5_2 }, { HTML_UNDEF }, "tel-country-code", aco_tel_country_code },
    { { HTML_5_2 }, { HTML_UNDEF }, "tel-extension", aco_tel_extension },
    { { HTML_5_2 }, { HTML_UNDEF }, "tel-local", aco_tel_local },
    { { HTML_5_2 }, { HTML_UNDEF }, "tel-local-prefix", aco_tel_local_prefix },
    { { HTML_5_2 }, { HTML_UNDEF }, "tel-local-suffix", aco_tel_local_suffix },
    { { HTML_5_2 }, { HTML_UNDEF }, "tel-national", aco_tel_national },
    { { HTML_5_2 }, { HTML_UNDEF }, "transaction-amount", aco_transaction_amount },
    { { HTML_5_2 }, { HTML_UNDEF }, "transaction-currency", aco_transaction_currency },
    { { HTML_5_2 }, { HTML_UNDEF }, "url", aco_url },
    { { HTML_5_2 }, { HTML_UNDEF }, "username", aco_username },
    { { HTML_5_2 }, { HTML_UNDEF }, "work", aco_work } };

struct symbol_entry < e_composite_operator > composite_operator_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "arithmetic",  co_arithmetic },
    { { HTML_4_0 }, { HTML_UNDEF }, "atop", co_atop },
    { { HTML_4_0 }, { HTML_UNDEF }, "in", co_in },
    { { HTML_4_0 }, { HTML_UNDEF }, "out", co_out },
    { { HTML_4_0 }, { HTML_UNDEF }, "over", co_over },
    { { HTML_4_0 }, { HTML_UNDEF }, "xor", co_xor } };

struct symbol_entry < e_cursor > cursor_operator_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "auto",  cu_auto },
    { { HTML_4_0 }, { HTML_UNDEF }, "crosshair", cu_crosshair },
    { { HTML_4_0 }, { HTML_UNDEF }, "default", cu_default },
    { { HTML_4_0 }, { HTML_UNDEF }, "pointer", cu_pointer },
    { { HTML_4_0 }, { HTML_UNDEF }, "move", cu_move },
    { { HTML_4_0 }, { HTML_UNDEF }, "e-resize", cu_eresize },
    { { HTML_4_0 }, { HTML_UNDEF }, "ne-resize", cu_neresize },
    { { HTML_4_0 }, { HTML_UNDEF }, "nw-resize", cu_nwresize },
    { { HTML_4_0 }, { HTML_UNDEF }, "n-resize", cu_nresize },
    { { HTML_4_0 }, { HTML_UNDEF }, "se-resize", cu_seresize },
    { { HTML_4_0 }, { HTML_UNDEF }, "sw-resize", cu_swresize },
    { { HTML_4_0 }, { HTML_UNDEF }, "s-resize", cu_sresize },
    { { HTML_4_0 }, { HTML_UNDEF }, "w-resize", cu_wresize },
    { { HTML_4_0 }, { HTML_UNDEF }, "text", cu_text },
    { { HTML_4_0 }, { HTML_UNDEF }, "wait", cu_wait },
    { { HTML_4_0 }, { HTML_UNDEF }, "help", cu_help } };

struct symbol_entry < e_decalign > decalign_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "left", dec_left },
    { { HTML_2_0 }, { HTML_UNDEF }, "center", dec_center },
    { { HTML_2_0 }, { HTML_UNDEF }, "right", dec_right },
    { { HTML_2_0 }, { HTML_UNDEF }, "justify", dec_justify },
    { { HTML_2_0 }, { HTML_UNDEF }, "decimal", dec_decimal } };

struct symbol_entry < e_dingbat > dingbat_symbol_table [] =
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

struct symbol_entry < e_display > display_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "inline",  ds_inline },
    { { HTML_4_0 }, { HTML_UNDEF }, "block", ds_block },
    { { HTML_4_0 }, { HTML_UNDEF }, "list-item", ds_listitem },
    { { HTML_4_0 }, { HTML_UNDEF }, "run-in", ds_runin },
    { { HTML_4_0 }, { HTML_UNDEF }, "compact", ds_compact },
    { { HTML_4_0 }, { HTML_UNDEF }, "marker", ds_marker },
    { { HTML_4_0 }, { HTML_UNDEF }, "table", ds_table },
    { { HTML_4_0 }, { HTML_UNDEF }, "inline-table", ds_inlinetable },
    { { HTML_4_0 }, { HTML_UNDEF }, "table-row-group", ds_tablerowgroup },
    { { HTML_4_0 }, { HTML_UNDEF }, "table-header-group", ds_tableheadergroup },
    { { HTML_4_0 }, { HTML_UNDEF }, "table-footer-group", ds_tablefootergroup },
    { { HTML_4_0 }, { HTML_UNDEF }, "table-row", ds_tablerow },
    { { HTML_4_0 }, { HTML_UNDEF }, "table-column-group", ds_tablecolumngroup },
    { { HTML_4_0 }, { HTML_UNDEF }, "table-column", ds_tablecolumn },
    { { HTML_4_0 }, { HTML_UNDEF }, "table-cell", ds_tablecell },
    { { HTML_4_0 }, { HTML_UNDEF }, "table-caption", ds_tablecaption },
    { { HTML_4_0 }, { HTML_UNDEF }, "none", ds_none },
    { { HTML_4_0 }, { HTML_UNDEF }, "inherit", ds_inherit } };

struct symbol_entry < e_dominantbaseline > dominantbaseline_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "auto",  db_auto },
    { { HTML_4_0 }, { HTML_UNDEF }, "use-script", db_usescript },
    { { HTML_4_0 }, { HTML_UNDEF }, "no-change", db_nochange },
    { { HTML_4_0 }, { HTML_UNDEF }, "reset-size", db_resetsize },
    { { HTML_4_0 }, { HTML_UNDEF }, "ideographic", db_ideographic },
    { { HTML_4_0 }, { HTML_UNDEF }, "hanging", db_hanging },
    { { HTML_4_0 }, { HTML_UNDEF }, "mathematical", db_mathematical },
    { { HTML_4_0 }, { HTML_UNDEF }, "central", db_central },
    { { HTML_4_0 }, { HTML_UNDEF }, "middle", db_middle },
    { { HTML_4_0 }, { HTML_UNDEF }, "text-after-edge", db_textafteredge },
    { { HTML_4_0 }, { HTML_UNDEF }, "text-before-edge", db_textbeforeedge },
    { { HTML_4_0 }, { HTML_UNDEF }, "inherit", db_inherit } };

struct symbol_entry < e_enterkeyhint > enterkeyhint_symbol_table [] =
{   { { HTML_JUL20 }, { HTML_UNDEF }, "done", ekh_done },
    { { HTML_JUL20 }, { HTML_UNDEF }, "enter", ekh_enter },
    { { HTML_JUL20 }, { HTML_UNDEF }, "go", ekh_go },
    { { HTML_JUL20 }, { HTML_UNDEF }, "next", ekh_next },
    { { HTML_JUL20 }, { HTML_UNDEF }, "previous", ekh_previous },
    { { HTML_JUL20 }, { HTML_UNDEF }, "search", ekh_search },
    { { HTML_JUL20 }, { HTML_UNDEF }, "send", ekh_send } };

struct symbol_entry < e_figalign > figalign_symbol_table [] =
{   { { HTML_3_0 }, { HTML_3_0 }, "bleedleft", fa_bleedleft },
    { { HTML_3_0 }, { HTML_3_0 }, "left", fa_left },
    { { HTML_3_0 }, { HTML_3_0 }, "center", fa_centre },
    { { HTML_3_0 }, { HTML_3_0 }, "right", fa_right },
    { { HTML_3_0 }, { HTML_3_0 }, "bleedright", fa_bleedright },
    { { HTML_3_0 }, { HTML_3_0 }, "justify", fa_justify } };

struct symbol_entry < e_halign > halign_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "left", al_left },
    { { HTML_2_0 }, { HTML_UNDEF }, "center", al_center },
    { { HTML_2_0 }, { HTML_UNDEF }, "right", al_right },
    { { HTML_2_0 }, { HTML_UNDEF }, "justify", al_justify },
    { { HTML_2_0 }, { HTML_UNDEF }, "char", al_char } };

struct symbol_entry < e_inky > inky_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "sourcegraphic", ink_sourcegraphic },
    { { HTML_2_0 }, { HTML_UNDEF }, "sourcealpha", ink_sourcealpha },
    { { HTML_2_0 }, { HTML_UNDEF }, "backgroundimage", ink_backgroundimage },
    { { HTML_2_0 }, { HTML_UNDEF }, "backgroundalpha", ink_backgroundalpha },
    { { HTML_2_0 }, { HTML_UNDEF }, "fillpaint", ink_fillpaint },
    { { HTML_2_0 }, { HTML_UNDEF }, "strokepaint", ink_strokepaint } };

struct symbol_entry < e_inputmode51 > inputmode51_symbol_table [] =
{   { { HTML_5_1 }, { HTML_5_1 }, "email", i1_email },
    { { HTML_5_1 }, { HTML_5_1 }, "full-width-latin", i1_fullwidthlatin },
    { { HTML_5_1 }, { HTML_5_1 }, "katakana", i1_katakana },
    { { HTML_5_1 }, { HTML_5_1 }, "kana", i1_kana },
    { { HTML_5_1 }, { HTML_5_1 }, "kana-name", i1_kananame },
    { { HTML_5_1 }, { HTML_5_1 }, "latin", i1_latin },
    { { HTML_5_1 }, { HTML_5_1 }, "latin-name", i1_latinname },
    { { HTML_5_1 }, { HTML_5_1 }, "latin-prose", i1_latinprose },
    { { HTML_5_1 }, { HTML_5_1 }, "numeric",i1_numeric },
    { { HTML_5_1 }, { HTML_5_1 }, "tel", i1_tel },
    { { HTML_5_1 }, { HTML_5_1 }, "url", i1_url },
    { { HTML_5_1 }, { HTML_5_1 }, "verbatim", i1_verbatim } };

struct symbol_entry < e_inputmode54 > inputmode54_symbol_table [] =
{   { { HTML_JUL20 }, { HTML_UNDEF }, "decimal", im_decimal },
    { { HTML_JUL20 }, { HTML_UNDEF }, "email", im_email },
    { { HTML_JUL20 }, { HTML_UNDEF }, "none", im_none },
    { { HTML_JUL20 }, { HTML_UNDEF }, "numeric", im_numeric  },
    { { HTML_JUL20 }, { HTML_UNDEF }, "search", im_search },
    { { HTML_JUL20 }, { HTML_UNDEF }, "tel", im_tel },
    { { HTML_JUL20 }, { HTML_UNDEF }, "text", im_text },
    { { HTML_JUL20 }, { HTML_UNDEF }, "url", im_url } };

struct symbol_entry < e_inputplus > inputplus_symbol_table [] =
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

struct symbol_entry < e_inputtype > inputtype_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "checkbox", it_checkbox },
    { { HTML_2_0 }, { HTML_UNDEF }, "file", it_file },
    { { HTML_2_0 }, { HTML_UNDEF }, "hidden", it_hidden },
    { { HTML_2_0 }, { HTML_UNDEF }, "image", it_image },
    { { HTML_2_0 }, { HTML_UNDEF }, "password", it_password },
    { { HTML_2_0 }, { HTML_UNDEF }, "radio", it_radio },
    { { HTML_2_0 }, { HTML_UNDEF }, "reset", it_reset },
    { { HTML_2_0 }, { HTML_UNDEF }, "submit", it_submit },
    { { HTML_2_0 }, { HTML_UNDEF }, "text", it_text } };

struct symbol_entry < e_inputtype3 > inputtype3_symbol_table [] =
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

struct symbol_entry < e_inputtype32 > inputtype32_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "checkbox", i2_checkbox },
    { { HTML_2_0 }, { HTML_UNDEF }, "file", i2_file },
    { { HTML_2_0 }, { HTML_UNDEF }, "hidden", i2_hidden },
    { { HTML_2_0 }, { HTML_UNDEF }, "image", i2_image },
    { { HTML_2_0 }, { HTML_UNDEF }, "password", i2_password },
    { { HTML_2_0 }, { HTML_UNDEF }, "radio", i2_radio },
    { { HTML_2_0 }, { HTML_UNDEF }, "reset", i2_reset },
    { { HTML_2_0 }, { HTML_UNDEF }, "submit", i2_submit },
    { { HTML_2_0 }, { HTML_UNDEF }, "text", i2_text } };

struct symbol_entry < e_inputtype4 > inputtype4_symbol_table [] =
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

struct symbol_entry < e_inputtype5 > inputtype5_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "button", i5_button },
    { { HTML_2_0 }, { HTML_UNDEF }, "checkbox", i5_checkbox },
    { { HTML_5_0 }, { HTML_UNDEF }, "color", i5_colour },
    { { HTML_5_0 }, { HTML_UNDEF }, "date", i5_date },
    { { HTML_5_1 }, { HTML_UNDEF }, "datetime-local", i5_datetime_local },
    { { HTML_5_0 }, { HTML_UNDEF }, "email", i5_email },
    { { 2, 1 }, { HTML_UNDEF }, "file", i5_file },
    { { HTML_2_0 }, { HTML_UNDEF }, "hidden", i5_hidden },
    { { HTML_2_0 }, { HTML_UNDEF }, "image", i5_image },
    { { HTML_5_1 }, { HTML_UNDEF }, "month", i5_month },
    { { HTML_5_0 }, { HTML_UNDEF }, "number", i5_number },
    { { HTML_2_0 }, { HTML_UNDEF }, "password", i5_password },
    { { HTML_2_0 }, { HTML_UNDEF }, "radio", i5_radio },
    { { HTML_2_0 }, { HTML_UNDEF }, "reset", i5_reset },
    { { HTML_3_0 }, { HTML_UNDEF }, "range", i5_range },
    { { HTML_5_0 }, { HTML_UNDEF }, "search", i5_search },
    { { HTML_2_0 }, { HTML_UNDEF }, "submit", i5_submit },
    { { HTML_5_0 }, { HTML_UNDEF }, "tel", i5_tel },
    { { HTML_2_0 }, { HTML_UNDEF }, "text", i5_text },
    { { HTML_5_0 }, { HTML_UNDEF }, "time", i5_time },
    { { HTML_5_0 }, { HTML_UNDEF }, "url", i5_url },
    { { HTML_5_1 }, { HTML_UNDEF }, "week", i5_week } };

struct symbol_entry < e_kind > kind_symbol_table [] =
{   { { HTML_5_0 }, { HTML_UNDEF }, "subtitles", k_subtitles },
    { { HTML_5_0 }, { HTML_UNDEF }, "captions", k_captions },
    { { HTML_5_0 }, { HTML_UNDEF }, "descriptions", k_descriptions },
    { { HTML_5_0 }, { HTML_UNDEF }, "chapters", k_chapters },
    { { HTML_5_0 }, { HTML_UNDEF }, "metadata", k_metadata } };

struct symbol_entry < e_linebreak > linebreak_symbol_table [] =
{   { { XHTML_1_0 }, { HTML_UNDEF }, "auto", lb_auto },
    { { XHTML_1_0 }, { HTML_UNDEF }, "newline", lb_newline },
    { { XHTML_1_0 }, { HTML_UNDEF }, "indentingnewline", lb_indentingnewline },
    { { XHTML_1_0 }, { HTML_UNDEF }, "nobreak", lb_nobreak },
    { { XHTML_1_0 }, { HTML_UNDEF }, "goodbreak", lb_goodbreak },
    { { XHTML_1_0 }, { HTML_UNDEF }, "badbreak", lb_badbreak } };

struct symbol_entry < e_listtype > listtype_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "1", li_1 },
    { { HTML_UNDEF }, { HTML_UNDEF }, "a", li_a },
    { { HTML_UNDEF }, { HTML_UNDEF }, "A", li_A },
    { { HTML_UNDEF }, { HTML_UNDEF }, "i", li_i },
    { { HTML_UNDEF }, { HTML_UNDEF }, "I", li_I } };

struct symbol_entry < e_mah > mah_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "go", mah_go },
    { { HTML_UNDEF }, { HTML_UNDEF }, "done", mah_done },
    { { HTML_UNDEF }, { HTML_UNDEF }, "next", mah_next },
    { { HTML_UNDEF }, { HTML_UNDEF }, "search", mah_search },
    { { HTML_UNDEF }, { HTML_UNDEF }, "send", mah_send } };

struct symbol_entry < e_mathvariant > mathvariant_symbol_table [] =
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
    { { XHTML_1_0 }, { HTML_UNDEF }, "monospace", mv_monospace } };

struct symbol_entry < e_matrix_type > matrix_type_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "matrix", mt_matrix },
    { { HTML_4_0 }, { HTML_UNDEF }, "saturate", mt_saturate },
    { { HTML_4_0 }, { HTML_UNDEF }, "huerotate", mt_hue_rotate },
    { { HTML_4_0 }, { HTML_UNDEF }, "hue-rotate", mt_hue_rotate },
    { { HTML_4_0 }, { HTML_UNDEF }, "luminancetoalpha", mt_luminance_alpha },
    { { HTML_4_0 }, { HTML_UNDEF }, "luminance-to-alpha", mt_luminance_alpha } };

struct symbol_entry < e_media > media_symbol_table [] =
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

struct symbol_entry < e_media_feature > media_feature_symbol_table [] =
{   { { HTML_5_0 }, { HTML_UNDEF }, "width", mef_width },
    { { HTML_5_0 }, { HTML_UNDEF }, "min-width", mef_min_width },
    { { HTML_5_0 }, { HTML_UNDEF }, "max-width", mef_max_width },
    { { HTML_5_0 }, { HTML_UNDEF }, "height", mef_height },
    { { HTML_5_0 }, { HTML_UNDEF }, "min-height", mef_min_height },
    { { HTML_5_0 }, { HTML_UNDEF }, "max-height", mef_max_height },
    { { HTML_5_0 }, { HTML_UNDEF }, "device-width", mef_device_width },
    { { HTML_5_0 }, { HTML_UNDEF }, "min-device-width", mef_min_device_width },
    { { HTML_5_0 }, { HTML_UNDEF }, "max-device-width", mef_max_device_width },
    { { HTML_5_0 }, { HTML_UNDEF }, "device-height", mef_device_height },
    { { HTML_5_0 }, { HTML_UNDEF }, "min-device-height", mef_min_device_height },
    { { HTML_5_0 }, { HTML_UNDEF }, "max-device-height", mef_max_device_height },
    { { HTML_5_0 }, { HTML_UNDEF }, "orientation", mef_orientation },
    { { HTML_5_0 }, { HTML_UNDEF }, "aspect-ration", mef_aspect_ration },
    { { HTML_5_0 }, { HTML_UNDEF }, "min-aspect-ration", mef_min_aspect_ration },
    { { HTML_5_0 }, { HTML_UNDEF }, "max-aspect-ration", mef_max_aspect_ration },
    { { HTML_5_0 }, { HTML_UNDEF }, "device-aspect-ratio", mef_device_aspect_ratio },
    { { HTML_5_0 }, { HTML_UNDEF }, "min-device-aspect-ratio", mef_min_device_aspect_ratio },
    { { HTML_5_0 }, { HTML_UNDEF }, "max-device-aspect-ratio", mef_max_device_aspect_ratio },
    { { HTML_5_0 }, { HTML_UNDEF }, "color", mef_colour },
    { { HTML_5_0 }, { HTML_UNDEF }, "min-color", mef_min_colour },
    { { HTML_5_0 }, { HTML_UNDEF }, "max-color", mef_max_colour },
    { { HTML_5_0 }, { HTML_UNDEF }, "color-index", mef_colour_index },
    { { HTML_5_0 }, { HTML_UNDEF }, "min-color-index", mef_min_colour_index },
    { { HTML_5_0 }, { HTML_UNDEF }, "max-color-index", mef_max_colour_index },
    { { HTML_5_0 }, { HTML_UNDEF }, "monochrome", mef_monochrome },
    { { HTML_5_0 }, { HTML_UNDEF }, "min-monochrome", mef_min_monochrome },
    { { HTML_5_0 }, { HTML_UNDEF }, "max-monochrome", mef_max_monochrome },
    { { HTML_5_0 }, { HTML_UNDEF }, "resolution", mef_resolution },
    { { HTML_5_0 }, { HTML_UNDEF }, "min-resolution", mef_min_resolution },
    { { HTML_5_0 }, { HTML_UNDEF }, "max-resolution", mef_max_resolution },
    { { HTML_5_0 }, { HTML_UNDEF }, "grid", mef_grid },
    { { HTML_5_0 }, { HTML_UNDEF }, "hover", mef_hover },
    { { HTML_5_0 }, { HTML_UNDEF }, "pointer", mef_pointer },
    { { HTML_5_0 }, { HTML_UNDEF }, "any-hover", mef_any_hover },
    { { HTML_5_0 }, { HTML_UNDEF }, "any-pointer", mef_any_pointer },
    { { HTML_5_0 }, { HTML_UNDEF }, "color-gamut", mef_colour_gamut },
    { { HTML_5_0 }, { HTML_UNDEF }, "overflow-block", mef_overflow_block },
    { { HTML_5_0 }, { HTML_UNDEF }, "overflow-inline", mef_overflow_inline },
    { { HTML_5_0 }, { HTML_UNDEF }, "scan", mef_scan },
    { { HTML_5_0 }, { HTML_UNDEF }, "update", mef_update } };

struct symbol_entry < e_media_keyword > media_keyword_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "and", mk_and },
    { { HTML_5_0 }, { HTML_UNDEF }, "=", mk_eq },
    { { HTML_5_0 }, { HTML_UNDEF }, ">=", mk_ge },
    { { HTML_5_0 }, { HTML_UNDEF }, ">", mk_gt },
    { { HTML_4_0 }, { HTML_UNDEF }, "ident", mk_ident },
    { { HTML_5_0 }, { HTML_UNDEF }, "<=", mk_le },
    { { HTML_5_0 }, { HTML_UNDEF }, "<", mk_lt },
    { { HTML_5_0 }, { HTML_UNDEF }, "or", mk_or },
    { { HTML_4_0 }, { HTML_UNDEF }, "not", mk_not },
    { { HTML_4_0 }, { HTML_UNDEF }, "only", mk_only } };

struct symbol_entry < e_method > method_symbol_table [] =
{   { { HTML_PLUS }, { HTML_PLUS }, "delete", md_delete },
    { { HTML_5_2 }, { HTML_UNDEF }, "dialog", md_dialogue },
    { { HTML_PLUS }, { HTML_UNDEF }, "get", md_get },
    { { HTML_PLUS }, { HTML_UNDEF }, "post", md_post },
    { { HTML_PLUS }, { HTML_PLUS }, "put", md_put } };

struct symbol_entry < e_microdata_domain > microdata_domain_symbol_table [] =
{   { { HTML_4_01 }, { HTML_UNDEF }, "http://microformats.org/", mdd_microformats },
    { { HTML_4_01 }, { HTML_UNDEF }, "https://microformats.org/", mdd_microformats },
    { { HTML_4_01 }, { HTML_UNDEF }, "http://purl.org/", mdd_purl },
    { { HTML_4_01 }, { HTML_UNDEF }, "https://purl.org/", mdd_purl },
    { { HTML_4_01 }, { HTML_UNDEF }, "http://schema.org/", mdd_schema },
    { { HTML_4_01 }, { HTML_UNDEF }, "https://schema.org/", mdd_schema } };

struct symbol_entry < e_namedspace > namedspace_symbol_table [] =
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

struct symbol_entry < e_namespace > namespace_symbol_table [] =
{   { { XHTML_1_0 }, { HTML_UNDEF }, "cc", ns_cc },
    { { XHTML_1_0 }, { HTML_UNDEF }, "crs", ns_crs },
    { { XHTML_1_0 }, { HTML_UNDEF }, "dc", ns_dc },
    { { XHTML_1_0 }, { HTML_UNDEF }, "dcterms", ns_dcterms },
    { { XHTML_1_0 }, { HTML_UNDEF }, "its", ns_its },
    { { XHTML_1_0 }, { HTML_UNDEF }, "math", ns_math },
    { { XHTML_1_0 }, { HTML_UNDEF }, "rdf", ns_rdf },
    { { XHTML_1_0 }, { HTML_UNDEF }, "svg", ns_svg },
    { { XHTML_1_0 }, { HTML_UNDEF }, "xlink", ns_xlink },
    { { XHTML_1_0 }, { HTML_UNDEF }, "xml", ns_xhtml },
    { { XHTML_1_0 }, { HTML_UNDEF }, "xmlns", ns_xmlns },
    { { XHTML_1_0 }, { HTML_UNDEF }, "xsi", ns_xsi } };

struct symbol_entry < e_paintkeyword > paintkeyword_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "none", pk_none },
    { { HTML_UNDEF }, { HTML_UNDEF }, "currentcolour", pk_currentcolour },
    { { HTML_UNDEF }, { HTML_UNDEF }, "inherit", pk_inherit },
    { { HTML_UNDEF }, { HTML_UNDEF }, "icc-colour", pk_icccolour },
    { { HTML_UNDEF }, { HTML_UNDEF }, "url", pk_url } };

struct symbol_entry < e_plusstyle > plusstyle_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "b", ps_b },
    { { HTML_UNDEF }, { HTML_UNDEF }, "i", ps_i },
    { { HTML_UNDEF }, { HTML_UNDEF }, "p", ps_p },
    { { HTML_UNDEF }, { HTML_UNDEF }, "s", ps_s },
    { { HTML_UNDEF }, { HTML_UNDEF }, "sub", ps_sub },
    { { HTML_UNDEF }, { HTML_UNDEF }, "sup", ps_sup },
    { { HTML_UNDEF }, { HTML_UNDEF }, "tt", ps_tt },
    { { HTML_UNDEF }, { HTML_UNDEF }, "u", ps_u } };

struct symbol_entry < e_pointerevents > pointerevents_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "visiblepainted", pe_visiblepainted },
    { { HTML_4_0 }, { HTML_UNDEF }, "visiblefill", pe_visiblefill },
    { { HTML_4_0 }, { HTML_UNDEF }, "visiblestroke", pe_visiblestroke },
    { { HTML_4_0 }, { HTML_UNDEF }, "visible", pe_visible },
    { { HTML_4_0 }, { HTML_UNDEF }, "painted", pe_painted },
    { { HTML_4_0 }, { HTML_UNDEF }, "fill", pe_fill },
    { { HTML_4_0 }, { HTML_UNDEF }, "stroke", pe_stroke },
    { { HTML_4_0 }, { HTML_UNDEF }, "all", pe_all },
    { { HTML_4_0 }, { HTML_UNDEF }, "none", pe_none },
    { { HTML_4_0 }, { HTML_UNDEF }, "inherit", pe_inherit } };

// a couple of these are only defined in the HTML+ text, not the DTD
struct symbol_entry < e_print > print_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "footnote", pt_footnote },
    { { HTML_UNDEF }, { HTML_UNDEF }, "reference", pt_reference },
    { { HTML_UNDEF }, { HTML_UNDEF }, "section", pt_section },
    { { HTML_UNDEF }, { HTML_UNDEF }, "sidebar", pt_sidebar },
    { { HTML_UNDEF }, { HTML_UNDEF }, "silent", pt_silent } };

struct symbol_entry < e_referrer > referrer_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "no-referrer", rf_no },
    { { HTML_UNDEF }, { HTML_UNDEF }, "no-referrer-when-downgrade", rf_downgrade },
    { { HTML_UNDEF }, { HTML_UNDEF }, "same-origin", rf_same },
    { { HTML_UNDEF }, { HTML_UNDEF }, "origin", rf_origin },
    { { HTML_UNDEF }, { HTML_UNDEF }, "strict-origin", rf_strict },
    { { HTML_UNDEF }, { HTML_UNDEF }, "strict-origin-when-cross-origin", rf_strictcross },
    { { HTML_UNDEF }, { HTML_UNDEF }, "origin-when-cross-origin", rf_cross },
    { { HTML_UNDEF }, { HTML_UNDEF }, "unsafe-url", rf_unsafe } };

struct symbol_entry < e_renderingintent > renderingintent_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "auto", ri_auto },
    { { HTML_4_0 }, { HTML_UNDEF }, "perceptual", ri_perceptual },
    { { HTML_4_0 }, { HTML_UNDEF }, "relative-colorimetric", ri_relativecolourimetric },
    { { HTML_4_0 }, { HTML_UNDEF }, "saturation", ri_saturation },
    { { HTML_4_0 }, { HTML_UNDEF }, "absolute-colorimetric", ri_absolutecolourimetric } };

struct symbol_entry < e_rules > rules_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "none", ru_none },
    { { HTML_2_0 }, { HTML_UNDEF }, "groups", ru_groups },
    { { HTML_2_0 }, { HTML_UNDEF }, "rows", ru_rows },
    { { HTML_2_0 }, { HTML_UNDEF }, "cols", ru_cols },
    { { HTML_2_0 }, { HTML_UNDEF }, "all", ru_all } };

struct symbol_entry < e_sandbox > sandbox_symbol_table [] =
{   { { HTML_JUL20, 0, HE_EXPERIMENTAL }, { HTML_UNDEF }, "allow-downloads-without-user-activation", s_adwua },
    { { HTML_5_0 }, { HTML_UNDEF }, "allow-forms", s_forms },
    { { HTML_5_0 }, { HTML_UNDEF }, "allow-modals", s_modals },
    { { HTML_5_0 }, { HTML_UNDEF }, "allow-orientation-lock", s_orientation },
    { { HTML_5_0 }, { HTML_UNDEF }, "allow-pointer-lock", s_pointer },
    { { HTML_5_0 }, { HTML_UNDEF }, "allow-popups", s_popups },
    { { HTML_5_0 }, { HTML_UNDEF }, "allow-popups-to-escape-sandbox", s_popupescape },
    { { HTML_5_0 }, { HTML_UNDEF }, "allow-presentation", s_presentation },
    { { HTML_5_0 }, { HTML_UNDEF }, "allow-same-origin", s_origin },
    { { HTML_5_0 }, { HTML_UNDEF }, "allow-scripts", s_scripts },
    { { HTML_JUL20, 0, HE_EXPERIMENTAL }, { HTML_UNDEF }, "allow-storage-access-by-user-activation", s_asabua },
    { { HTML_5_0 }, { HTML_UNDEF }, "allow-top-navigation", s_navigation },
    { { HTML_5_0 }, { HTML_UNDEF }, "allow-top-navigation-by-user-activation", s_atnbua },
    { { HTML_JUL20 }, { HTML_UNDEF }, "allow-downloads", s_ad } };

struct symbol_entry < e_shape7 > shape7_symbol_table [] =
{   { { HTML_5_0 }, { HTML_UNDEF }, "circle", s7_circ },
    { { HTML_5_0 }, { HTML_UNDEF }, "circ", s7_circ },
    { { HTML_5_0 }, { HTML_UNDEF }, "default", s7_default },
    { { HTML_5_0 }, { HTML_UNDEF }, "poly", s7_poly },
    { { HTML_5_0 }, { HTML_UNDEF }, "polygon", s7_poly },
    { { HTML_5_0 }, { HTML_UNDEF }, "rect", s7_rect },
    { { HTML_5_0 }, { HTML_UNDEF }, "rectangle", s7_rect } };

struct symbol_entry < e_shaperendering > shaperendering_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "auto", sr_auto },
    { { HTML_4_0 }, { HTML_UNDEF }, "optimizespeed", sr_optimisespeed },
    { { HTML_4_0 }, { HTML_UNDEF }, "crispedges", sr_crispedges },
    { { HTML_4_0 }, { HTML_UNDEF }, "geometricprecision", sr_geometricprecision },
    { { HTML_4_0 }, { HTML_UNDEF }, "inherit", sr_inherit } };

struct symbol_entry < e_ssi > ssi_symbol_table [] =
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

struct symbol_entry < e_ssi_comparison > ssi_comparison_symbol_table [] =
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

struct symbol_entry < e_ssi_encoding > ssi_encoding_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "base64", ssi_encoding_base64 },
    { { HTML_UNDEF }, { HTML_UNDEF }, "entity", ssi_encoding_entity },
    { { HTML_UNDEF }, { HTML_UNDEF }, "none", ssi_encoding_none },
    { { HTML_UNDEF }, { HTML_UNDEF }, "url", ssi_encoding_url },
    { { HTML_UNDEF }, { HTML_UNDEF }, "urlencoded", ssi_encoding_urlencoded } };

struct symbol_entry < e_ssi_env > ssi_env_symbol_table [] =
{   { { HTML_UNDEF }, { HTML_UNDEF }, "date_gmt", ssi_DATE_GMT },
    { { HTML_UNDEF }, { HTML_UNDEF }, "date_local", ssi_DATE_LOCAL },
    { { HTML_UNDEF }, { HTML_UNDEF }, "document_args", ssi_DOCUMENT_ARGS },
    { { HTML_UNDEF }, { HTML_UNDEF }, "document_name", ssi_DOCUMENT_NAME },
    { { HTML_UNDEF }, { HTML_UNDEF }, "document_path_info", ssi_DOCUMENT_PATH_INFO },
    { { HTML_UNDEF }, { HTML_UNDEF }, "document_uri", ssi_DOCUMENT_URI },
    { { HTML_UNDEF }, { HTML_UNDEF }, "last_modified", ssi_LAST_MODIFIED },
    { { HTML_UNDEF }, { HTML_UNDEF }, "query_string_unescaped", ssi_QUERY_STRING_UNESCAPED },
    { { HTML_UNDEF }, { HTML_UNDEF }, "user_name", ssi_USER_NAME } };

struct symbol_entry < e_svg_align > svg_align_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "none", sa_none },
    { { HTML_4_0 }, { HTML_UNDEF }, "xminymin", sa_xmin_ymin },
    { { HTML_4_0 }, { HTML_UNDEF }, "xmin_ymin", sa_xmin_ymin },
    { { HTML_4_0 }, { HTML_UNDEF }, "xmidymin", sa_xmid_ymin },
    { { HTML_4_0 }, { HTML_UNDEF }, "xmid_ymin", sa_xmid_ymin },
    { { HTML_4_0 }, { HTML_UNDEF }, "xmaxymin", sa_xmax_ymin },
    { { HTML_4_0 }, { HTML_UNDEF }, "xmax_ymin", sa_xmax_ymin },
    { { HTML_4_0 }, { HTML_UNDEF }, "xminymid", sa_xmin_ymid },
    { { HTML_4_0 }, { HTML_UNDEF }, "xmin_ymid", sa_xmin_ymid },
    { { HTML_4_0 }, { HTML_UNDEF }, "xmidymid", sa_xmid_ymid },
    { { HTML_4_0 }, { HTML_UNDEF }, "xmid_ymid", sa_xmid_ymid },
    { { HTML_4_0 }, { HTML_UNDEF }, "xmaxymid", sa_xmax_ymid },
    { { HTML_4_0 }, { HTML_UNDEF }, "xmax_ymid", sa_xmax_ymid },
    { { HTML_4_0 }, { HTML_UNDEF }, "xminymax", sa_xmin_ymax },
    { { HTML_4_0 }, { HTML_UNDEF }, "xmin_ymax", sa_xmin_ymax },
    { { HTML_4_0 }, { HTML_UNDEF }, "xmidymax", sa_xmid_ymax },
    { { HTML_4_0 }, { HTML_UNDEF }, "xmid_ymax", sa_xmid_ymax },
    { { HTML_4_0 }, { HTML_UNDEF }, "xmaxymax", sa_xmax_ymax },
    { { HTML_4_0 }, { HTML_UNDEF }, "xmax_ymax", sa_xmax_ymax } };

struct symbol_entry < e_svg_fontstretch > svg_fontstretch_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "normal",  fst_normal },
    { { HTML_4_0 }, { HTML_UNDEF }, "wider",  fst_wider },
    { { HTML_4_0 }, { HTML_UNDEF }, "narrower",  fst_narrower },
    { { HTML_4_0 }, { HTML_UNDEF }, "extra-condensed", fst_extracondensed },
    { { HTML_4_0 }, { HTML_UNDEF }, "condensed", fst_condensed },
    { { HTML_4_0 }, { HTML_UNDEF }, "semi-condensed", fst_semicondensed },
    { { HTML_4_0 }, { HTML_UNDEF }, "semi-expanded", fst_semiexpanded },
    { { HTML_4_0 }, { HTML_UNDEF }, "expanded", fst_expanded },
    { { HTML_4_0 }, { HTML_UNDEF }, "extra-expanded", fst_extraexpanded },
    { { HTML_4_0 }, { HTML_UNDEF }, "ultra-expanded", fst_ultraexpanded },
    { { HTML_4_0 }, { HTML_UNDEF }, "inherit", fst_inherit } };

struct symbol_entry < e_svg_fontstretch_ff > svg_fontstretch_ff_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "normal",  fff_normal },
    { { HTML_4_0 }, { HTML_UNDEF }, "ultra-condensed",  fff_ultracondensed },
    { { HTML_4_0 }, { HTML_UNDEF }, "extra-condensed", fff_extracondensed },
    { { HTML_4_0 }, { HTML_UNDEF }, "condensed", fff_condensed },
    { { HTML_4_0 }, { HTML_UNDEF }, "semi-condensed", fff_semicondensed },
    { { HTML_4_0 }, { HTML_UNDEF }, "semi-expanded", fff_semiexpanded },
    { { HTML_4_0 }, { HTML_UNDEF }, "expanded", fff_expanded },
    { { HTML_4_0 }, { HTML_UNDEF }, "extra-expanded", fff_extraexpanded },
    { { HTML_4_0 }, { HTML_UNDEF }, "ultra-expanded", fff_ultraexpanded } };

struct symbol_entry < e_svg_fontweight > svg_fontweight_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "normal",  fsw_normal },
    { { HTML_4_0 }, { HTML_UNDEF }, "bold", fsw_bold },
    { { HTML_4_0 }, { HTML_UNDEF }, "bolder", fsw_bolder },
    { { HTML_4_0 }, { HTML_UNDEF }, "lighter", fsw_lighter },
    { { HTML_4_0 }, { HTML_UNDEF }, "100", fsw_100 },
    { { HTML_4_0 }, { HTML_UNDEF }, "200", fsw_200 },
    { { HTML_4_0 }, { HTML_UNDEF }, "300", fsw_300 },
    { { HTML_4_0 }, { HTML_UNDEF }, "400", fsw_400 },
    { { HTML_4_0 }, { HTML_UNDEF }, "500", fsw_500 },
    { { HTML_4_0 }, { HTML_UNDEF }, "600", fsw_600 },
    { { HTML_4_0 }, { HTML_UNDEF }, "700", fsw_700 },
    { { HTML_4_0 }, { HTML_UNDEF }, "800", fsw_800 },
    { { HTML_4_0 }, { HTML_UNDEF }, "900", fsw_900 },
    { { HTML_4_0 }, { HTML_UNDEF }, "inherit", fsw_inherit } };

struct symbol_entry < e_svg_fontweight_ff > svg_fontweight_ff_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "normal",  fsf_normal },
    { { HTML_4_0 }, { HTML_UNDEF }, "bold", fsf_bold },
    { { HTML_4_0 }, { HTML_UNDEF }, "100", fsf_100 },
    { { HTML_4_0 }, { HTML_UNDEF }, "200", fsf_200 },
    { { HTML_4_0 }, { HTML_UNDEF }, "300", fsf_300 },
    { { HTML_4_0 }, { HTML_UNDEF }, "400", fsf_400 },
    { { HTML_4_0 }, { HTML_UNDEF }, "500", fsf_500 },
    { { HTML_4_0 }, { HTML_UNDEF }, "600", fsf_600 },
    { { HTML_4_0 }, { HTML_UNDEF }, "700", fsf_700 },
    { { HTML_4_0 }, { HTML_UNDEF }, "800", fsf_800 },
    { { HTML_4_0 }, { HTML_UNDEF }, "900", fsf_900 } };

struct symbol_entry < e_svg_mode > svg_mode_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "darken", sm_darken },
    { { HTML_4_0 }, { HTML_UNDEF }, "lighten", sm_lighten },
    { { HTML_4_0 }, { HTML_UNDEF }, "multiple", sm_multiple },
    { { HTML_4_0 }, { HTML_UNDEF }, "normal", sm_normal },
    { { HTML_4_0 }, { HTML_UNDEF }, "screen", sm_screen } };

struct symbol_entry < e_svg_overflow > svg_overflow_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "visible", sov_visible },
    { { HTML_4_0 }, { HTML_UNDEF }, "hidden", sov_hidden },
    { { HTML_4_0 }, { HTML_UNDEF }, "scroll", sov_scroll },
    { { HTML_4_0 }, { HTML_UNDEF }, "auto", sov_auto },
    { { HTML_4_0 }, { HTML_UNDEF }, "inherit", sov_inherit } };

struct symbol_entry < e_svg_type_11 > svg_type_11_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "discrete", tsz_discrete },
    { { HTML_4_0 }, { HTML_UNDEF }, "gamma", tsz_gamma },
    { { HTML_4_0 }, { HTML_UNDEF }, "identity", tsz_identity },
    { { HTML_4_0 }, { HTML_UNDEF }, "linear", tsz_linear },
    { { HTML_4_0 }, { HTML_UNDEF }, "table", tsz_table } };

struct symbol_entry < e_svg_version > svg_version_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "1.0", sv_1_0 },
    { { XHTML_1_0 }, { HTML_UNDEF }, "1.1", sv_1_1 },
    { { XHTML_1_1 }, { HTML_UNDEF }, "1.2", sv_1_2_tiny } };

struct symbol_entry < e_tableframe > tableframe_symbol_table [] =
{   { { HTML_2_0 }, { HTML_UNDEF }, "void", fr_void },
    { { HTML_2_0 }, { HTML_UNDEF }, "above", fr_above },
    { { HTML_2_0 }, { HTML_UNDEF }, "below", fr_below },
    { { HTML_2_0 }, { HTML_UNDEF }, "hsides", fr_hsides },
    { { HTML_2_0 }, { HTML_UNDEF }, "lhs", fr_lhs },
    { { HTML_2_0 }, { HTML_UNDEF }, "rhs", fr_rhs },
    { { HTML_2_0 }, { HTML_UNDEF }, "vsides", fr_vsides },
    { { HTML_2_0 }, { HTML_UNDEF }, "box", fr_box },
    { { HTML_2_0 }, { HTML_UNDEF }, "border", fr_border } };

struct symbol_entry < e_textdecoration > textdecoration_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "none", td_none },
    { { HTML_4_0 }, { HTML_UNDEF }, "underline", td_underline },
    { { HTML_4_0 }, { HTML_UNDEF }, "overline", td_overline },
    { { HTML_4_0 }, { HTML_UNDEF }, "line-through", td_linethrough },
    { { HTML_4_0 }, { HTML_UNDEF }, "blink", td_blink },
    { { HTML_4_0 }, { HTML_UNDEF }, "inherit", td_inherit } };

struct symbol_entry < e_textrendering > textrendering_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "auto", tr_auto },
    { { HTML_4_0 }, { HTML_UNDEF }, "optimizespeed", tr_optimisespeed },
    { { HTML_4_0 }, { HTML_UNDEF }, "optimizelegibility", tr_optimiselegibility },
    { { HTML_4_0 }, { HTML_UNDEF }, "geometricprecision", tr_geometricprecision },
    { { HTML_4_0 }, { HTML_UNDEF }, "inherit", tr_inherit } };

struct symbol_entry < e_transform_anim > transform_anim_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "translate", ta_translate },
    { { HTML_4_0 }, { HTML_UNDEF }, "scale", ta_scale },
    { { HTML_4_0 }, { HTML_UNDEF }, "rotate", ta_rotate },
    { { HTML_4_0 }, { HTML_UNDEF }, "skewx", ta_skewx },
    { { HTML_4_0 }, { HTML_UNDEF }, "skewy", ta_skewy } };

struct symbol_entry < e_transform_fn > transform_fn_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "matrix", tr_matrix },
    { { HTML_4_0 }, { HTML_UNDEF }, "translate", tr_translate },
    { { HTML_4_0 }, { HTML_UNDEF }, "scale", tr_scale },
    { { HTML_4_0 }, { HTML_UNDEF }, "rotate", tr_rotate },
    { { HTML_4_0 }, { HTML_UNDEF }, "skew-x", tr_skewx },
    { { HTML_4_0 }, { HTML_UNDEF }, "skewx", tr_skewx },
    { { HTML_4_0 }, { HTML_UNDEF }, "skew-y", tr_skewy },
    { { HTML_4_0 }, { HTML_UNDEF }, "skewy", tr_skewy } };

struct symbol_entry < e_turbulence_type > turbulence_type_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "fractalnoise", tu_fractal_noise },
    { { HTML_4_0 }, { HTML_UNDEF }, "fractal-noise", tu_fractal_noise },
    { { HTML_4_0 }, { HTML_UNDEF }, "turbulence", tu_turbulence } };

struct symbol_entry < e_vectoreffect_2 > vectoreffect_2_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "fixed-position", v2_fixedposition },
    { { HTML_4_0 }, { HTML_UNDEF }, "none", v2_none },
    { { HTML_4_0 }, { HTML_UNDEF }, "non-rotation", v2_nonrotation },
    { { HTML_4_0 }, { HTML_UNDEF }, "non-scaling-stroke", v2_nonscalingstroke },
    { { HTML_4_0 }, { HTML_UNDEF }, "non-scaling-size", v2_nonscalingsize } };

struct symbol_entry < e_writingmode > writingmode_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "lr-tb", wm_lrtb },
    { { HTML_4_0 }, { HTML_UNDEF }, "rl-tb", wm_rltb },
    { { HTML_4_0 }, { HTML_UNDEF }, "tb-rl", wm_tbrl },
    { { HTML_4_0 }, { HTML_UNDEF }, "lr", wm_lr },
    { { HTML_4_0 }, { HTML_UNDEF }, "rl", wm_rl },
    { { HTML_4_0 }, { HTML_UNDEF }, "tb", wm_tb },
    { { HTML_4_0 }, { HTML_UNDEF }, "inherit", wm_inherit } };

struct symbol_entry < e_xlinkshow > xlinkshow_symbol_table [] =
{   { { HTML_4_0 }, { HTML_UNDEF }, "new", xls_new },
    { { HTML_4_0 }, { HTML_UNDEF }, "replace", xls_replace },
    { { HTML_4_0 }, { HTML_UNDEF }, "embed", xls_embed },
    { { HTML_4_0 }, { HTML_UNDEF }, "other", xls_other },
    { { HTML_4_0 }, { HTML_UNDEF }, "none", xls_none } };

struct symbol_entry < e_xmlns > xmlns_symbol_table [] =
{   { { XHTML_1_0 }, { HTML_UNDEF }, "http://www.w3.org/1999/xhtml", x_xhtml_1 },
    { { XHTML_1_0 }, { HTML_UNDEF }, "https://www.w3.org/1999/xhtml", x_xhtml_1 },
    { { XHTML_1_1 }, { HTML_UNDEF }, "http://www.w3.org/2000/xhtml", x_xhtml_11 },
    { { XHTML_1_1 }, { HTML_UNDEF }, "https://www.w3.org/2000/xhtml", x_xhtml_11 },
    { { XHTML_2_0 }, { HTML_UNDEF }, "http://www.w3.org/2004/xhtml", x_xhtml_2 },
    { { XHTML_2_0 }, { HTML_UNDEF }, "https://www.w3.org/2004/xhtml", x_xhtml_2 },
    { { HTML_4_0 }, { HTML_UNDEF }, "http://creativecommons.org/ns#", x_cc },
    { { HTML_4_0 }, { HTML_UNDEF }, "https://creativecommons.org/ns#", x_cc },
    { { XHTML_1_0 }, { HTML_UNDEF }, "http://www.ogc.org/crs", x_crs },
    { { XHTML_1_0 }, { HTML_UNDEF }, "https://www.ogc.org/crs", x_crs },
    { { HTML_4_0 }, { HTML_UNDEF }, "http://purl.org/dc/terms/", x_dc },
    { { HTML_4_0 }, { HTML_UNDEF }, "https://purl.org/dc/terms/", x_dc },
    { { XHTML_1_0 }, { HTML_UNDEF }, "http://www.w3.org/1998/math/mathml", x_mathml },
    { { XHTML_1_0 }, { HTML_UNDEF }, "https://www.w3.org/1998/math/mathml", x_mathml },
    { { XHTML_1_0 }, { HTML_UNDEF }, "http://www.w3.org/1999/02/22-rdf-syntax-ns#", x_rdf },
    { { XHTML_1_0 }, { HTML_UNDEF }, "https://www.w3.org/1999/02/22-rdf-syntax-ns#", x_rdf },
    { { XHTML_1_0 }, { HTML_UNDEF }, "http://www.w3.org/2000/svg", x_svg },
    { { XHTML_1_0 }, { HTML_UNDEF }, "https://www.w3.org/2000/svg", x_svg },
    { { HTML_4_0 }, { HTML_UNDEF }, "http://www.w3.org/tr/rec-mathml-19980407", x_svg },
    { { HTML_4_0 }, { HTML_UNDEF }, "https://www.w3.org/tr/rec-mathml-19980407", x_svg },
    { { HTML_4_0 }, { HTML_UNDEF }, "http://www.w3.org/graphics/svg/svg-19990706.dtd", x_svg },
    { { HTML_4_0 }, { HTML_UNDEF }, "https://www.w3.org/graphics/svg/svg-19990706.dtd", x_svg },
    { { XHTML_1_0 }, { HTML_UNDEF }, "http://www.w3.org/1999/xlink", x_xlink },
    { { XHTML_1_0 }, { HTML_UNDEF }, "https://www.w3.org/1999/xlink", x_xlink },
    { { XHTML_1_0 }, { HTML_UNDEF }, "http://www.w3.org/xml/1998/namespace", x_xml },
    { { XHTML_1_0 }, { HTML_UNDEF }, "https://www.w3.org/xml/1998/namespace", x_xml },
    { { XHTML_1_0 }, { HTML_UNDEF }, "http://www.w3.org/2000/xmlns/", x_xmlns },
    { { XHTML_1_0 }, { HTML_UNDEF }, "https://www.w3.org/2000/xmlns/", x_xmlns } };

#define INIT_ENUM(XX) type_master < t_##XX > :: init (nits, XX##_symbol_table, sizeof (XX##_symbol_table) / sizeof (symbol_entry < e_##XX >))

void enum_init (nitpick& nits)
{   INIT_ENUM (action);
    INIT_ENUM (align3);
    INIT_ENUM (alignplus);
    INIT_ENUM (as);
    INIT_ENUM (autocapitalise54);
    INIT_ENUM (autocomplete);
    INIT_ENUM (decalign);
    INIT_ENUM (composite_operator);
    INIT_ENUM (dingbat);
    INIT_ENUM (display);
    INIT_ENUM (dominantbaseline);
    INIT_ENUM (enterkeyhint);
    INIT_ENUM (figalign);
    INIT_ENUM (halign);
    INIT_ENUM (inputmode51);
    INIT_ENUM (inputmode54);
    INIT_ENUM (inputplus);
    INIT_ENUM (inputtype);
    INIT_ENUM (inputtype3);
    INIT_ENUM (inputtype32);
    INIT_ENUM (inputtype4);
    INIT_ENUM (inputtype5);
    INIT_ENUM (kind);
    INIT_ENUM (linebreak);
    INIT_ENUM (listtype);
    INIT_ENUM (mah);
    INIT_ENUM (mathvariant);
    INIT_ENUM (matrix_type);
    INIT_ENUM (media);
    INIT_ENUM (media_feature);
    INIT_ENUM (media_keyword);
    INIT_ENUM (method);
    INIT_ENUM (microdata_domain);
    INIT_ENUM (namedspace);
    INIT_ENUM (namespace);
    INIT_ENUM (paintkeyword);
    INIT_ENUM (plusstyle);
    INIT_ENUM (pointerevents);
    INIT_ENUM (print);
    INIT_ENUM (referrer);
    INIT_ENUM (renderingintent);
    INIT_ENUM (rules);
    INIT_ENUM (sandbox);
    INIT_ENUM (shape7);
    INIT_ENUM (shaperendering);
    INIT_ENUM (ssi);
    INIT_ENUM (ssi_comparison);
    INIT_ENUM (ssi_encoding);
    INIT_ENUM (ssi_env);
    INIT_ENUM (svg_align);
    INIT_ENUM (svg_fontstretch);
    INIT_ENUM (svg_fontstretch_ff);
    INIT_ENUM (svg_fontweight);
    INIT_ENUM (svg_fontweight_ff);
    INIT_ENUM (svg_mode);
    INIT_ENUM (svg_overflow);
    INIT_ENUM (svg_version);
    INIT_ENUM (tableframe);
    INIT_ENUM (textdecoration);
    INIT_ENUM (textrendering);
    INIT_ENUM (transform_anim);
    INIT_ENUM (transform_fn);
    INIT_ENUM (turbulence_type);
    INIT_ENUM (vectoreffect_2);
    INIT_ENUM (xlinkshow);
    INIT_ENUM (xmlns); }
