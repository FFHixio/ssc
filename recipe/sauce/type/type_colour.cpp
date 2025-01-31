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
#include "type/type_colour.h"

struct symbol_entry < html_version, e_fixedcolour > fixedcolour_symbol_table [] =
{   { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "aliceblue", fc_aliceblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "antiquewhite", fc_antiquewhite },
    { { HTML_3_2 }, { HTML_UNDEF }, "aqua", fc_aqua },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "aquamarine", fc_aquamarine },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "azure", fc_azure },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "beige", fc_beige },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "bisque", fc_bisque },
    { { HTML_3_2 }, { HTML_UNDEF }, "black", fc_black },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "blanchedalmond", fc_blanchedalmond },
    { { HTML_3_2 }, { HTML_UNDEF }, "blue", fc_blue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "blueviolet", fc_blueviolet },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "brown", fc_brown },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "burlywood", fc_burlywood },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "cadetblue", fc_cadetblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "chartreuse", fc_chartreuse },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "chocolate", fc_chocolate },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "coral", fc_coral },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "cornflowerblue", fc_cornflowerblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "cornsilk", fc_cornsilk },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "crimson", fc_crimson },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "cyan", fc_cyan },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkblue", fc_darkblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkcyan", fc_darkcyan },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkgoldenrod", fc_darkgoldenrod },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkgray", fc_darkgray },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkgreen", fc_darkgreen },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkgrey", fc_darkgrey },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkkhaki", fc_darkkhaki },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkmagenta", fc_darkmagenta },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkolivegreen", fc_darkolivegreen },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkorange", fc_darkorange },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkorchid", fc_darkorchid },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkred", fc_darkred },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darksalmon", fc_darksalmon },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkseagreen", fc_darkseagreen },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkslateblue", fc_darkslateblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkslategray", fc_darkslategray },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkslategrey", fc_darkslategrey },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkturquoise", fc_darkturquoise },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "darkviolet", fc_darkviolet },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "deeppink", fc_deeppink },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "deepskyblue", fc_deepskyblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "dimgray", fc_dimgray },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "dimgrey", fc_dimgrey },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "dodgerblue", fc_dodgerblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "firebrick", fc_firebrick },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "floralwhite", fc_floralwhite },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "forestgreen", fc_forestgreen },
    { { HTML_3_2 }, { HTML_UNDEF }, "fuchsia", fc_fuchsia },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "gainsboro", fc_gainsboro },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "ghostwhite", fc_ghostwhite },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "gold", fc_gold },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "goldenrod", fc_goldenrod },
    { { HTML_3_2 }, { HTML_UNDEF }, "gray", fc_grey },
    { { HTML_3_2 }, { HTML_UNDEF }, "green", fc_green },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "greenyellow", fc_greenyellow },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "honeydew", fc_honeydew },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "hotpink", fc_hotpink },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "indianred", fc_indianred },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "indigo", fc_indigo },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "ivory", fc_ivory },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "khaki", fc_khaki },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lavender", fc_lavender },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lavenderblush", fc_lavenderblush },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lawngreen", fc_lawngreen },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lemonchiffon", fc_lemonchiffon },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lightblue", fc_lightblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lightcoral", fc_lightcoral },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lightcyan", fc_lightcyan },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lightgoldenrodyellow", fc_lightgoldenrodyellow },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lightgray", fc_lightgray },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lightgreen", fc_lightgreen },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lightgrey", fc_lightgrey },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lightpink", fc_lightpink },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lightsalmon", fc_lightsalmon },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lightseagreen", fc_lightseagreen },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lightskyblue", fc_lightskyblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lightslategray", fc_lightslategray },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lightslategrey", fc_lightslategrey },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lightsteelblue", fc_lightsteelblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "lightyellow", fc_lightyellow },
    { { HTML_3_2 }, { HTML_UNDEF }, "lime", fc_lime },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "limegreen", fc_limegreen },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "linen", fc_linen },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "magenta", fc_magenta },
    { { HTML_3_2 }, { HTML_UNDEF }, "maroon", fc_maroon },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "mediumaquamarine", fc_mediumaquamarine },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "mediumblue", fc_mediumblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "mediumorchid", fc_mediumorchid },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "mediumpurple", fc_mediumpurple },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "mediumseagreen", fc_mediumseagreen },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "mediumslateblue", fc_mediumslateblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "mediumspringgreen", fc_mediumspringgreen },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "mediumturquoise", fc_mediumturquoise },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "mediumvioletred", fc_mediumvioletred },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "midnightblue", fc_midnightblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "mintcream", fc_mintcream },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "mistyrose", fc_mistyrose },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "moccasin", fc_moccasin },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "navajowhite", fc_navajowhite },
    { { HTML_3_2 }, { HTML_UNDEF }, "navy", fc_navy },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "oldlace", fc_oldlace },
    { { HTML_3_2 }, { HTML_UNDEF }, "olive", fc_olive },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "olivedrab", fc_olivedrab },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "orange", fc_orange },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "orangered", fc_orangered },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "orchid", fc_orchid },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "palegoldenrod", fc_palegoldenrod },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "palegreen", fc_palegreen },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "paleturquoise", fc_paleturquoise },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "palevioletred", fc_palevioletred },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "papayawhip", fc_papayawhip },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "peachpuff", fc_peachpuff },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "peru", fc_peru },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "pink", fc_pink },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "plum", fc_plum },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "powderblue", fc_powderblue },
    { { HTML_3_2 }, { HTML_UNDEF }, "purple", fc_purple },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "rebeccapurple ", fc_rebeccapurple  },
    { { HTML_3_2 }, { HTML_UNDEF }, "red", fc_red },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "rosybrown", fc_rosybrown },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "royalblue", fc_royalblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "saddlebrown", fc_saddlebrown },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "salmon", fc_salmon },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "sandybrown", fc_sandybrown },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "seagreen", fc_seagreen },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "seashell", fc_seashell },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "sienna", fc_sienna },
    { { HTML_3_2 }, { HTML_UNDEF }, "silver", fc_silver },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "skyblue", fc_skyblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "slateblue", fc_slateblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "slategray", fc_slategray },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "slategrey", fc_slategrey },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "snow", fc_snow },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "springgreen", fc_springgreen },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "steelblue", fc_steelblue },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "tan", fc_tan },
    { { HTML_3_2 }, { HTML_UNDEF }, "teal", fc_teal },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "thistle", fc_thistle },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "tomato", fc_tomato },
    { { HTML_MATH2, 0, HE_MATH_2 }, { HTML_UNDEF }, "transparent", fc_transparent },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "turquoise", fc_turquoise },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "violet", fc_violet },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "wheat", fc_wheat },
    { { HTML_3_2 }, { HTML_UNDEF }, "white", fc_white },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "whitesmoke", fc_whitesmoke },
    { { HTML_3_2 }, { HTML_UNDEF }, "yellow", fc_yellow },
    { { HTML_SVG10, 0, HE_SVG }, { HTML_UNDEF }, "yellowgreen", fc_yellowgreen } };

void fixedcolour_init (nitpick& nits)
{   type_master < t_fixedcolour > :: init (nits, fixedcolour_symbol_table, sizeof (fixedcolour_symbol_table) / sizeof (symbol_entry < html_version, e_fixedcolour >)); }
