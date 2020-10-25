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
#include "type_aria.h"

struct symbol_entry < e_aria_role > role_symbol_table [] =
{   { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "alert", role_alert },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "alertdialog", role_alertdialogue },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "application", role_application },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "article", role_article },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "banner", role_banner },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "button", role_button },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "cell", role_cell },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "checkbox", role_checkbox },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "columnheader", role_columnheader },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "combobox", role_combobox },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "command", role_command },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "complementary", role_complementary },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "contentinfo", role_contentinfo },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "definition", role_definition },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "dialog", role_dialogue },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "directory", role_directory },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "document", role_document },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "feed", role_feed },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "figure", role_figure },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "form", role_form },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "grid", role_grid },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "gridcell", role_gridcell },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "group", role_group },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "heading", role_heading },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "img", role_img },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "landmark", role_landmark },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "link", role_link },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "list", role_list },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "listbox", role_listbox },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "listitem", role_listitem },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "log", role_log },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "main", role_main },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "marquee", role_marquee },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "math", role_math },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "menu", role_menu },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "menubar", role_menubar },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "menuitem", role_menuitem },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "menuitemcheckbox", role_menuitemcheckbox },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "menuitemradio", role_menuitemradio },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "navigation", role_navigation },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "none", role_none },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "note", role_note },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "option", role_option },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "presentation", role_presentation },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "progressbar", role_progressbar },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "radio", role_radio },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "radiogroup", role_radiogroup },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "range", role_range },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "region", role_region },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "roletype", role_roletype },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "row", role_row },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "rowgroup", role_rowgroup },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "rowheader", role_rowheader },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "scrollbar", role_scrollbar },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "search", role_search },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "searchbox", role_searchbox },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "section", role_section },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "sectionhead", role_sectionhead },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "select", role_select },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "separator", role_separator },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "slider", role_slider },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "spinbutton", role_spinbutton },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "status", role_status },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "structure", role_structure },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "switch", role_switch },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "tab", role_tab },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "table", role_table },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "tablist", role_tablist },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "tabpanel", role_tabpanel },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "term", role_term },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "textbox", role_textbox },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "timer", role_timer },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "toolbar", role_toolbar },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "tooltip", role_tooltip },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "tree", role_tree },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "treegrid", role_treegrid },
    { { HTML_4_01, HV_ARIA }, { HTML_UNDEF }, "treeitem", role_treeitem },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "widget", role_widget },
    { { HTML_4_01, HV_ARIA }, { HTML_5_0 }, "window", role_window } };

struct elem_role {
    html_version from_, to_;
    e_element elem_;
    e_aria_role role_;
    elem_role (const html_version& from, const html_version& to, const e_element elem, const e_aria_role role)
        : from_ (from), to_ (to), elem_ (elem), role_ (role) { } };

struct role_key {
    e_element elem_;
    e_aria_role role_;
    role_key (const e_element elem, const e_aria_role role)
        : elem_ (elem), role_ (role) { } };

elem_role default_role [] =
{   { { HTML_5_0 }, { HTML_UNDEF }, elem_a, role_link },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_article, role_article },
    { { HTML_5_0 }, { HTML_5_3 }, elem_area, role_link },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_aside, role_complementary },
    { { HTML_5_2 }, { HTML_5_2 }, elem_address, role_group },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_body, role_document },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_button, role_button },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_datalist, role_listbox },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_dd, role_definition },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_details, role_group },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_dialogue, role_dialogue },
    { { HTML_5_1 }, { HTML_5_2 }, elem_dl, role_list },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_dt, role_term },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_fieldset, role_group },
    { { HTML_5_2 }, { HTML_5_3 }, elem_figure, role_figure },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_footer, role_contentinfo },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h1, role_heading },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h2, role_heading },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h3, role_heading },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h4, role_heading },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h5, role_heading },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h6, role_heading },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_header, role_banner },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_hr, role_separator },
    { { HTML_5_0 }, { 0, 3 }, elem_img, role_presentation },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, role_img },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_li, role_listitem },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_link, role_link },
    { { HTML_5_0 }, { HTML_5_3 }, elem_main, role_main },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_map, role_link },
    { { HTML_5_1 }, { HTML_5_1 }, elem_menuitem, role_menuitem },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_nav, role_navigation },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ol, role_list },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_optgroup, role_group },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_option, role_option },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_output, role_status },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_progress, role_progressbar },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_section, role_region },
    { { HTML_5_0 }, { HTML_5_1 }, elem_select, role_listbox },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_table, role_table },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_tbody, role_rowgroup },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_td, role_cell },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_tfoot, role_rowgroup },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_th, role_columnheader },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_th, role_rowheader },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_thead, role_rowgroup },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_tr, role_row },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ul, role_list },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_textarea, role_textbox },
    { { HTML_UNDEF }, { HTML_UNDEF }, elem_undefined, role_any } };

elem_role permitted_role [] =
{   { { HTML_5_0 }, { HTML_UNDEF }, elem_a, role_button },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_a, role_checkbox },
    { { HTML_5_0 }, { HTML_5_1 }, elem_a, role_menuitem },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_a, role_menuitem },
    { { HTML_5_0 }, { HTML_5_1 }, elem_a, role_menuitemcheckbox },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_a, role_menuitemcheckbox },
    { { HTML_5_0 }, { HTML_5_1 }, elem_a, role_menuitemradio },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_a, role_menuitemradio },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_a, role_option },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_a, role_radio },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_a, role_switch },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_a, role_tab },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_a, role_treeitem },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_abbr, role_any },
    { { HTML_5_0 }, { HTML_5_1 }, elem_address, role_contentinfo },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_address, role_any },
    { { HTML_5_0 }, { HTML_5_3 }, elem_article, role_application },
    { { HTML_5_0 }, { HTML_5_3 }, elem_article, role_document },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_article, role_feed },
    { { HTML_5_0 }, { HTML_5_3 }, elem_article, role_main },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_article, role_none },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_article, role_note },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_article, role_presentation },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_article, role_region },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_article, role_search },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_aside, role_feed },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_aside, role_none },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_aside, role_note },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_aside, role_presentation },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_aside, role_region },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_aside, role_search },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_audio, role_application },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_b, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_bdi, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_bdo, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_blockquote, role_any },
    { { HTML_5_0 }, { HTML_5_1 }, elem_body, role_application },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_br, role_any },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_button, role_checkbox },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_button, role_link },
    { { HTML_5_0 }, { HTML_5_1 }, elem_button, role_menuitem },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_button, role_menuitem },
    { { HTML_5_0 }, { HTML_5_1 }, elem_button, role_menuitemcheckbox },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_button, role_menuitemcheckbox },
    { { HTML_5_0 }, { HTML_5_1 }, elem_button, role_menuitemradio },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_button, role_menuitemradio },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_button, role_option },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_button, role_radio },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_button, role_switch },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_button, role_tab },
    { { HTML_5_0 }, { HTML_5_1 }, elem_caption, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_cite, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_code, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_data, role_any },
    { { HTML_5_0 }, { HTML_5_0 }, elem_dd, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_dfn, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_del, role_any },
    { { HTML_5_1 }, { HTML_5_1 }, elem_details, role_any },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_dialogue, role_alertdialogue },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_div, role_any },
    { { HTML_5_0 }, { HTML_5_0 }, elem_dl, role_any },
    { { HTML_5_1 }, { HTML_5_1 }, elem_dl, role_directory},
    { { HTML_5_1 }, { HTML_UNDEF }, elem_dl, role_group },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_dl, role_list },
    { { HTML_5_1 }, { HTML_5_1 }, elem_dl, role_listbox },
    { { HTML_5_1 }, { HTML_5_1 }, elem_dl, role_menu },
    { { HTML_5_1 }, { HTML_5_1 }, elem_dl, role_menubar },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_dl, role_none },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_dl, role_presentation },
    { { HTML_5_1 }, { HTML_5_1 }, elem_dl, role_radiogroup },
    { { HTML_5_1 }, { HTML_5_1 }, elem_dl, role_tablist },
    { { HTML_5_1 }, { HTML_5_1 }, elem_dl, role_toolbar },
    { { HTML_5_1 }, { HTML_5_1 }, elem_dl, role_tree },
    { { HTML_5_0 }, { HTML_5_0 }, elem_dt, role_any },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_dt, role_listitem },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_em, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_embed, role_application },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_embed, role_document },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_embed, role_img },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_embed, role_none },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_embed, role_presentation },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_fieldset, role_none },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_fieldset, role_presentation },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_fieldset, role_radiogroup },
    { { HTML_5_0 }, { HTML_5_1 }, elem_figcaption, role_any },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_figcaption, role_group },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_figcaption, role_none },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_figcaption, role_presentation },
    { { HTML_5_0 }, { HTML_5_1 }, elem_figure, role_any },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_figure, role_any },
    { { HTML_5_2 }, { HTML_5_3 }, elem_figure, role_group },
    { { HTML_5_3 }, { HTML_5_3 }, elem_figure, role_none },
    { { HTML_5_2 }, { HTML_5_3 }, elem_figure, role_presentation },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_footer, role_group },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_footer, role_none },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_footer, role_presentation },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_footer, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_form, role_any },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_h1, role_none },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h1, role_presentation },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h1, role_tab },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_h2, role_none },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h2, role_presentation },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h2, role_tab },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_h3, role_none },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h3, role_presentation },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h3, role_tab },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_h4, role_none },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h4, role_presentation },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h4, role_tab },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_h5, role_none },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h5, role_presentation },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h5, role_tab },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_h6, role_none },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h6, role_presentation },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_h6, role_tab },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_header, role_group },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_header, role_none },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_header, role_presentation },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_hgroup, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_hr, role_presentation },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_hr, role_none },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_i, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_iframe, role_application },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_iframe, role_document },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_iframe, role_img },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_iframe, role_none },
    { { HTML_5_0 }, { HTML_5_0 }, elem_iframe, role_presentation },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_iframe, role_presentation },
    { { HTML_5_0 }, { HTML_5_3 }, elem_img, role_any },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, role_button },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, role_checkbox },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, role_link },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, role_menuitem },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, role_menuitemcheckbox },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, role_menuitemradio },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, role_option },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, role_progressbar },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, role_scrollbar },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, role_separator },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, role_slider },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, role_switch },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, role_tab },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, role_treeitem },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_input, role_button },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_input, role_checkbox },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_input, role_combobox },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_input, role_link },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_input, role_menuitem },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_input, role_menuitemcheckbox },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_input, role_menuitemradio },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_input, role_option },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_input, role_none },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_input, role_presentation },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_input, role_progressbar },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_input, role_radio },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_input, role_scrollbar },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_input, role_separator },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_input, role_slider },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_input, role_spinbutton },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_input, role_switch },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_input, role_tab },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_input, role_textbox },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_input, role_treeitem },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ins, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_kbd, role_any },
    { { HTML_5_0 }, { HTML_5_1 }, elem_legend, role_any },
    { { HTML_5_0 }, { HTML_5_1 }, elem_li, role_menuitem },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_li, role_menuitem },
    { { HTML_5_0 }, { HTML_5_1 }, elem_li, role_menuitemcheckbox },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_li, role_menuitemcheckbox },
    { { HTML_5_0 }, { HTML_5_1 }, elem_li, role_menuitemradio },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_li, role_menuitemradio },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_li, role_option },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_li, role_none },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_li, role_presentation },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_li, role_radio },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_li, role_separator },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_li, role_tab },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_li, role_treeitem },
    { { HTML_5_0 }, { HTML_5_2 }, elem_main, role_presentation },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_mark, role_any },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_menu, role_directory },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_menu, role_group },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_menu, role_list },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_menu, role_listbox },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_menu, role_menu },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_menu, role_menubar },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_menu, role_none },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_menu, role_presentation },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_menu, role_radiogroup },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_menu, role_tablist },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_menu, role_tabpanel },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_menu, role_tree },
    { { HTML_5_0 }, { HTML_5_1 }, elem_nav, role_presentation },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_object, role_application },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_object, role_document },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_object, role_img },
    { { HTML_5_0 }, { HTML_5_2 }, elem_object, role_presentation },
    { { HTML_5_0 }, { HTML_5_1 }, elem_option, role_menuitem },
    { { HTML_5_0 }, { HTML_5_1 }, elem_option, role_menuitemradio },
    { { HTML_5_0 }, { HTML_5_2 }, elem_option, role_separator },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ol, role_directory },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_ol, role_group },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ol, role_listbox },
    { { HTML_5_0 }, { HTML_5_1 }, elem_ol, role_menu },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_ol, role_menu },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ol, role_menubar },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_ol, role_none },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ol, role_presentation },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_ol, role_radiogroup },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ol, role_tablist },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ol, role_toolbar },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ol, role_tree },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_output, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_p, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_pre, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_q, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_rb, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_rp, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_rt, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_rtc, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ruby, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_s, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_samp, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_section, role_alert },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_section, role_alertdialogue },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_section, role_application },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_section, role_banner },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_section, role_complementary },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_section, role_contentinfo },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_section, role_dialogue },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_section, role_document },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_section, role_feed },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_section, role_log },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_section, role_main },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_section, role_marquee },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_section, role_navigation },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_section, role_none },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_section, role_note },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_section, role_presentation },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_section, role_search },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_section, role_status },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_section, role_tabpanel },
    { { HTML_5_0 }, { HTML_5_1 }, elem_select, role_menu },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_select, role_menu },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_small, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_span, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_strong, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_sub, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_sup, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_table, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_tbody, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_td, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_tfoot, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_thead, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_th, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_time, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_tr, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_u, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ul, role_directory },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_ul, role_group },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ul, role_listbox },
    { { HTML_5_0 }, { HTML_5_1 }, elem_ul, role_menu },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_ul, role_menu },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ul, role_menubar },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_ul, role_none },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ul, role_presentation },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_ul, role_radiogroup },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ul, role_tablist },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ul, role_toolbar },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_ul, role_tree },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_var, role_any },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_video, role_application },
    { { HTML_5_0 }, { HTML_UNDEF }, elem_wbr, role_any },
    { { HTML_UNDEF }, { HTML_UNDEF }, elem_undefined, role_any } };

bool operator == (const role_key& lhs, const role_key& rhs)
{   return (lhs.elem_ == rhs.elem_) && (lhs.role_ == rhs.role_); }

bool operator != (const role_key& lhs, const role_key& rhs)
{   return ! (lhs == rhs); }

bool operator < (const role_key& lhs, const role_key& rhs)
{   if (lhs.elem_ < rhs.elem_) return true;
    if (lhs.elem_ > rhs.elem_) return false;
    return (lhs.role_ < rhs.role_); }

bool operator >= (const role_key& lhs, const role_key& rhs)
{   return ! (lhs < rhs); }

bool operator <= (const role_key& lhs, const role_key& rhs)
{   return (lhs < rhs) || (lhs == rhs); }

bool operator > (const role_key& lhs, const role_key& rhs)
{   return ! (lhs <= rhs); }

typedef ::std::multimap < role_key, elem_role > rolemap;
typedef rolemap::value_type rmv;
typedef rolemap::const_iterator rmi;
rolemap default_roles, permitted_roles;

void role_init (nitpick& nits)
{   type_master < t_role > :: init (nits, role_symbol_table, sizeof (role_symbol_table) / sizeof (symbol_entry < e_aria_role >));
    for (::std::size_t i = 0; default_role [i].elem_ != elem_undefined; ++i)
        default_roles.insert (rmv (role_key (default_role [i].elem_, default_role [i].role_), default_role [i]));
    for (::std::size_t i = 0; permitted_role [i].elem_ != elem_undefined; ++i)
        permitted_roles.insert (rmv (role_key (permitted_role [i].elem_, permitted_role [i].role_), permitted_role [i])); }

bool is_role_lookup (const rolemap& rm, const html_version& v, const e_element elem, const e_aria_role role)
{   for (   rmi i = rm.find (role_key (elem, role));
            (i != rm.cend ());
            ++i)
        if (does_apply (v, i -> second.from_, i -> second.to_)) return true;
    return false; }

bool is_x_role (const rolemap& rm, const html_version& v, const e_element elem, const e_aria_role role)
{   return (is_role_lookup (rm, v, elem, role) || is_role_lookup (rm, v, elem, role_any)); }

bool is_default_role (const html_version& v, const e_element elem, const e_aria_role role)
{   return is_x_role (default_roles, v, elem, role); }

bool is_permitted_role (const html_version& v, const e_element elem, const e_aria_role role)
{   return is_x_role (permitted_roles, v, elem, role); }
