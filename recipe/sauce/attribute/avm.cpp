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
#include "attribute/avm.h"
#include "main/context.h"
#include "element/elem.h"
#include "type/type.h"

struct hav_t
{   html_version first_, last_;
    e_element tag_;
    e_attribute a_; };

#define HTMLPLUS_ATTRIBUTES(ELEM) \
    { { HTML_PLUS }, { HTML_PLUS }, ELEM, a_id }, \
    { { HTML_PLUS }, { HTML_PLUS }, ELEM, a_index }, \
    { { HTML_PLUS }, { HTML_PLUS }, ELEM, a_lang }

#define HTML_CID_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM, MAJOR_TO, MINOR_TO) \
    { { MAJOR_FROM, MINOR_FROM, HV_RFC_1942 | HV_RFC_2070 }, { MAJOR_TO, MINOR_TO }, ELEM, a_class }, \
    { { MAJOR_FROM, MINOR_FROM, HV_RFC_1942 | HV_RFC_2070 }, { MAJOR_TO, MINOR_TO }, ELEM, a_id }

#define HTML_LANG_ATTRIBUTES(ELEM, MAJOR_TO, MINOR_TO) \
    { { HTML_2_0, HV_RFC_1942 | HV_RFC_2070 }, { HTML_2_0 }, ELEM, a_dir }, \
    { { HTML_2_0, HV_RFC_1942 | HV_RFC_2070 }, { MAJOR_TO, MINOR_TO }, ELEM, a_lang }

#define HTML2_CLID_ATTRIBUTES(ELEM) \
    HTML_LANG_ATTRIBUTES (ELEM, MAJOR_2_0, MINOR_2_0), \
    HTML_CID_ATTRIBUTES (ELEM, MAJOR_2_0, MINOR_2_0, MAJOR_2_0, MINOR_2_0)

#define HTML3_CLID_ATTRIBUTES(ELEM) \
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, ELEM, a_lang }, \
    HTML_CID_ATTRIBUTES (ELEM, MAJOR_3_0, MINOR_3_0, MAJOR_3_0, MINOR_3_0)

#define HTML23_CLID_ATTRIBUTES(ELEM) \
    HTML_LANG_ATTRIBUTES (ELEM, MAJOR_3_0, MINOR_3_0), \
    HTML_CID_ATTRIBUTES (ELEM, MAJOR_2_0, MINOR_2_0, MAJOR_3_0, MINOR_3_0)

#define STANDARD_HTML_23_H_ATTRIBUTES(ELEM) \
    { { HTML_2_0, HV_RFC_2070 }, { HTML_3_2 }, ELEM, a_align }, \
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, ELEM, a_clear }, \
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, ELEM, a_dingbat }, \
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, ELEM, a_md }, \
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, ELEM, a_nowrap }, \
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, ELEM, a_seqnum }, \
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, ELEM, a_skip }, \
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, ELEM, a_src },  \
    HTML23_CLID_ATTRIBUTES (ELEM)

#define MICRODATA_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM, FLAG) \
    { { MAJOR_FROM, MINOR_FROM, 0, FLAG }, { HTML_UNDEF }, ELEM, a_itemid }, \
    { { MAJOR_FROM, MINOR_FROM, 0, FLAG }, { HTML_UNDEF }, ELEM, a_itemprop }, \
    { { MAJOR_FROM, MINOR_FROM, 0, FLAG }, { HTML_UNDEF }, ELEM, a_itemref }, \
    { { MAJOR_FROM, MINOR_FROM, 0, FLAG }, { HTML_UNDEF }, ELEM, a_itemscope }, \
    { { MAJOR_FROM, MINOR_FROM, 0, FLAG }, { HTML_UNDEF }, ELEM, a_itemtype }

#define HTML4_STANDARD_SCRIPT_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM) \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_onclick },\
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_ondblclick }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_onkeydown }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_onkeypress }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_onkeyup }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_onmousedown }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_onmousemove }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_onmouseout }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_onmouseover }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_onmouseup }

#define HTML4_STANDARD_LANG_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM) \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_dir }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_lang }

#define HTML4_STANDARD_CI_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM) \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_class }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_id }

#define HTML4_ARIA_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM, FLAG) \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariaactivedescendant }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariaatomic }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariaautocomplete }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariabusy }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariachecked }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariacontrols }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariadescribedby }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariadisabled }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariadropeffect }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariaexpanded }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariaflowto }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariagrabbed }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariahaspopup }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariahidden }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariainvalid }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_arialabel }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_arialabelledby }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_arialevel }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_arialive }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariamultiline }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariamultiselectable }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariaorientation }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariaowns }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariaposinset }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariapressed }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariareadonly }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariarelevant }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariarequired }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariaselected }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariasetsize }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariasort }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariavaluemax }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariavaluemin }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariavaluenow }, \
    { { MAJOR_FROM, MINOR_FROM, FLAG }, { HTML_UNDEF }, ELEM, a_ariavaluetext }

#define SVG10_XY_ATTRIBUTES(ELEM) \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG }, { HTML_UNDEF }, ELEM, a_x }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG }, { HTML_UNDEF }, ELEM, a_y }

#define SVG10_DXY_ATTRIBUTES(ELEM) \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG }, { HTML_UNDEF }, ELEM, a_dx }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG }, { HTML_UNDEF }, ELEM, a_dy }

#define SVG10_BOX_ATTRIBUTES(ELEM) \
    SVG10_XY_ATTRIBUTES (ELEM), \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, ELEM, a_fitbbox }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG }, { HTML_UNDEF }, ELEM, a_height }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG }, { HTML_UNDEF }, ELEM, a_width }

#define SVG10_COMP_ATTRIBUTES(ELEM) \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 | HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_amplitude }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 | HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_exponent }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 | HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_intercept }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 | HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_offset }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 | HE_SVG_1_1 | REQUIRED }, { HTML_UNDEF }, ELEM, a_type }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 | HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_slope }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 | HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_tablevalues }

#define SVG10_FILTER_ATTRIBUTES(ELEM) \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, ELEM, a_in }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, ELEM, a_nodeid }

#define SVG10_FIT_ATTRIBUTES(ELEM) \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, ELEM, a_fitboxtoviewport }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG }, { HTML_UNDEF }, ELEM, a_preserveaspectratio }

#define SVG10_G_ATTRIBUTES(ELEM) \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG }, { XHTML_2_0 }, ELEM, a_onload }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { XHTML_2_0 }, ELEM, a_onselect }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG }, { HTML_UNDEF }, ELEM, a_transform }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, ELEM, a_systemrequired }

#define SVG10_GRAD_ATTRIBUTES(ELEM) \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG }, { HTML_UNDEF }, ELEM, a_gradienttransform }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, ELEM, a_gradient_units }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_gradientunits }

#define SVG10_REF_XY_ATTRIBUTES(ELEM) \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG }, { HTML_UNDEF }, ELEM, a_refx }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG }, { HTML_UNDEF }, ELEM, a_refy }

#define SVG10_REPL_ATTRIBUTES(ELEM) \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, ELEM, a_actuate }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, ELEM, a_href }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, ELEM, a_show }, \
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, ELEM, a_xmllink }

#define SVG11_ANADD_ATTRIBUTES(ELEM) \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_additive }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_accumulate }

#define SVG11_ANAT_ATTRIBUTES(ELEM) \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_attributename }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_attributetype }

#define SVG11_ANEV_ATTRIBUTES(ELEM) \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_onbegin }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_onend }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_onrepeat }

#define SVG11_ANTIME_ATTRIBUTES(ELEM) \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_begin }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_dur }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_end }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_min }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_max }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_restart }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_repeatcount }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_repeatdur }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_fill }

#define SVG11_ANVAL_ATTRIBUTES(ELEM) \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_calcmode }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_values }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_keytimes }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_keysplines }

#define SVG11_FILTER_ATTRIBUTES(ELEM) \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_x }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_y }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_height }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_result }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_width }

#define SVG11_GREV_ATTRIBUTES(ELEM) \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_onactivate }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_onfocusin }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_onfocusout }

#define SVG11_XLINK_ATTRIBUTES(ELEM) \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_xlinkactuate }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_xlinkarcrole }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_xlinkhref }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_xlinkrole }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_xlinkshow }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_xlinktitle }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_xlinktype }

#define SVGx_CONDPROC_ATTRIBUTES(ELEM) \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_requiredextensions }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 | HE_SVG_1_2 }, { HTML_UNDEF }, ELEM, a_requiredfeatures }, \
    { { MAJOR_X1_1, MINOR_X1_1, 0, HE_SVG_1_2 }, { HTML_UNDEF }, ELEM, a_requiredfonts }, \
    { { MAJOR_X1_1, MINOR_X1_1, 0, HE_SVG_1_2 }, { HTML_UNDEF }, ELEM, a_requiredformats }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_systemlanguage }

// FFS, SVG 1.2 Tiny does not define WTF a core attribute is. I'll have to presume 1.1 covers it.
#define SVGx_XTRA_CORE_ATTRIBUTES(ELEM) \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_xmlspace }

#define SVGx_PRES_ATTRIBUTES(ELEM) \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_alignmentbaseline }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_baselineshift }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_clip }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_clip_path }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_clip_rule }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_colour }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_colour_interpolation }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_colour_interpolation_filters }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_colour_profile }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_colour_rendering }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_cursor }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_direction }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_display }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_dominantbaseline }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_enablebackground }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_fill }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_fill_opacity }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_fill_rule }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_filter }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_flood_colour }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_flood_opacity }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_font }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_font_family }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_font_size }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_font_size_adjust }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_font_stretch }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_font_style }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_font_variant }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_font_weight }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_glyph_orientation_vertical }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_glyphorientation_horizontal }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_2 | HE_SVG_2_0 }, { HTML_UNDEF }, ELEM, a_imagerendering }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_kerning }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_letter_spacing }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_lighting_colour }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, ELEM, a_marker }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_marker_end }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_marker_mid }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_marker_start }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_mask }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_opacity }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_overflow }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_2 | HE_SVG_2_0 }, { HTML_UNDEF }, ELEM, a_paint_order }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_2 | HE_SVG_2_0 }, { HTML_UNDEF }, ELEM, a_pointerevents }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_shaperendering }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_stop_colour }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_stop_opacity }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_stroke }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_stroke_dasharray }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_stroke_dashoffset }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_stroke_linecap }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_stroke_linejoin }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_stroke_miterlimit }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_stroke_opacity }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_stroke_width }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_textanchor }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_textdecoration }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_textrendering }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_2 | HE_SVG_2_0 }, { HTML_UNDEF }, ELEM, a_transform }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_unicodebidi }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_2 | HE_SVG_2_0 }, { HTML_UNDEF }, ELEM, a_vector_effect }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_visibility }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_word_spacing }, \
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, ELEM, a_writingmode }


#define MATH1_STANDARD_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM) \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_class }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_id }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_other }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_style }

#define MATH1_DEFS_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM) \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_definition }, \
    MATH1_STANDARD_ATTRIBUTES (ELEM, MAJOR_FROM, MINOR_FROM)

#define MATH1_FONT_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM) \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_colour }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_fontfamily }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_fontsize }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_fontstyle }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_fontweight }

#define MATH1_OPINFO_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM) \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_accent }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_form }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_fence }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_largeop }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_lspace }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_maxsize }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_minsize }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_movablelimits }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_rspace }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_separator }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_stretchy }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_symmetric }

#define MATH1_SIZEINFO_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM) \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_depth }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_height }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_width }

#define MATH1_TABLE_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM) \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_align }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_alignmentscope }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_columnalign }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_columnlines }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_columnspacing }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_displaystyle }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_equalcolumns }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_equalrows }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_frame }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_framespacing }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_groupalign }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_rowalign }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_rowlines }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_rowspacing }

#define XHTML1_STANDARD_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM) \
    { { XHTML_1_1, 0, HE_RDF_1_0 }, { HTML_UNDEF }, ELEM, a_about }, \
    { { XHTML_1_1, 0, HE_RDF_1_0 }, { HTML_UNDEF }, ELEM, a_content }, \
    { { XHTML_1_1, 0, HE_RDF_1_0 }, { HTML_UNDEF }, ELEM, a_inlist }, \
    { { XHTML_1_1, 0, HE_RDF_1_0 }, { HTML_UNDEF }, ELEM, a_prefix }, \
    { { XHTML_1_1, 0, HE_RDF_1_0 }, { HTML_UNDEF }, ELEM, a_property }, \
    { { XHTML_1_1, 0, HE_RDF_1_0 }, { HTML_UNDEF }, ELEM, a_rel }, \
    { { XHTML_1_1, 0, HE_RDF_1_0 }, { HTML_UNDEF }, ELEM, a_resource }, \
    { { XHTML_1_1, 0, HE_RDF_1_0 }, { HTML_UNDEF }, ELEM, a_rev }, \
    { { XHTML_1_1, 0, HE_RDF_1_0 }, { HTML_UNDEF }, ELEM, a_src }, \
    { { XHTML_1_1, 0, HE_RDF_1_0 }, { HTML_UNDEF }, ELEM, a_typeof }, \
    { { XHTML_1_1, 0, HE_RDF_1_0 }, { HTML_UNDEF }, ELEM, a_vocab }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_xmlns }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_xmllang }

#define XHTML2_COMMON_ATTRIBUTES(ELEM) \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_cite }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_class }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_coords }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_datatype }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_defaultaction }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_dir }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_edit }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_event }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_eventtarget }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_encoding }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_function }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_handler }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_href }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_hreflang }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_hrefmedia }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_hreftype }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_id }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_ismap }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_itstranslate }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_layout }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_media }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_nextfocus }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_observer }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_phase }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_prevfocus }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_propagate }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_role }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_shape }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_srctype }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_style }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_target }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_title }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_usemap }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_xmlbase }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_xmlid }, \
    { { XHTML_2_0 }, { XHTML_2_0 }, ELEM, a_xmllang }

#define XHTML2_STANDARD_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM) \
    XHTML2_COMMON_ATTRIBUTES(ELEM), \
    XHTML1_STANDARD_ATTRIBUTES(ELEM, MAJOR_X2_0, MINOR_X2_0)

#define XHTML2_ATTRIBUTES(ELEM) \
    XHTML2_STANDARD_ATTRIBUTES(ELEM, MAJOR_X2_0, MINOR_X2_0)

#define HTML4_STANDARD_CIS_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM) \
    HTML4_STANDARD_CI_ATTRIBUTES (ELEM, MAJOR_FROM, MINOR_FROM), \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_style }

#define HTML4_STANDARD_CIST_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM) \
    HTML4_STANDARD_CIS_ATTRIBUTES (ELEM, MAJOR_FROM, MINOR_FROM), \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_title }

#define HTML4_STANDARD_TSL_ATTRIBUTES(ELEM, MAJOR_FROM, MINOR_FROM) \
    HTML4_STANDARD_LANG_ATTRIBUTES (ELEM, MAJOR_FROM, MINOR_FROM), \
    HTML4_STANDARD_CIST_ATTRIBUTES (ELEM, MAJOR_FROM, MINOR_FROM)

#define HTML4_ATTRIBUTES_BASE(ELEM, MAJOR_FROM, MINOR_FROM) \
    HTML4_STANDARD_TSL_ATTRIBUTES (ELEM, MAJOR_FROM, MINOR_FROM), \
    HTML4_STANDARD_SCRIPT_ATTRIBUTES (ELEM, MAJOR_FROM, MINOR_FROM), \
    HTML4_ARIA_ATTRIBUTES (ELEM, MAJOR_FROM, MINOR_FROM, HV_ARIA), \
    MICRODATA_ATTRIBUTES (ELEM, MAJOR_FROM, MINOR_FROM, HE_MICRODATA)

#define COMMON_HTML4_ATTRIBUTES(ELEM) \
    HTML4_ATTRIBUTES_BASE (ELEM, MAJOR_4_0, MINOR_4_0), \
    XHTML2_STANDARD_ATTRIBUTES (ELEM, MAJOR_X1_0, MINOR_X1_0)

#define HTML4_FORM_ATTRIBUTES_V(ELEM, MAJOR_FROM, MINOR_FROM) \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_accesskey }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_tabindex }

#define HTML4_FORM_ATTRIBUTES(ELEM) \
    HTML4_FORM_ATTRIBUTES_V (ELEM, MAJOR_4_0, MINOR_4_0)

#define HTML5_STANDARDISED_HTML4_ATTRIBUTES(ELEM) \
    HTML4_FORM_ATTRIBUTES_V (ELEM, MAJOR_5_0, MINOR_5_0)

#define EXTRA_HTML50_ATTRIBUTES(ELEM) \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_acceptcharset }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_contenteditable }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_generator_unable }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_hidden }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onabort }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_oncancel }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_oncanplay }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_oncanplaythrough }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_oncuechange }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_ondurationchange }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onemptied }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onended }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onerror }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_oninput }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_oninvalid }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onloadeddata }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onloadedmetadata }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onloadstart }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onmouseenter }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onmouseleave }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onmousewheel }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onpause }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onplay }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onplaying }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onprogress }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onratechange }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onresize }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onscroll }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onseeked }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onseeking }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_5_2 }, ELEM, a_onshow }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onstalled }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onsuspend }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_ontimeupdate }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_ontoggle }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onvolumechange }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onwaiting }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_role }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_spellcheck }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_translate }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_xmlspace }

#define UNFOCUSED_HTML50_ATTRIBUTES(ELEM) \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onchange }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onload }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onreset }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onresize }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onselect }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onsubmit }

#define FOCUSED_HTML50_ATTRIBUTES(ELEM) \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onblur }, \
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, ELEM, a_onfocus }

#define HTML_FORM(ELEM, MAJOR_FROM, MINOR_FROM) \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_form }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_formaction }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_formenctype }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_formmethod }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_formnovalidate }, \
    { { MAJOR_FROM, MINOR_FROM }, { HTML_UNDEF }, ELEM, a_formtarget }

#define HTML50_FORM(ELEM) HTML_FORM(ELEM, MAJOR_5_0, MINOR_5_0)

#define NEW_HTML50_ATTRIBUTES(ELEM) \
    EXTRA_HTML50_ATTRIBUTES (ELEM), \
    UNFOCUSED_HTML50_ATTRIBUTES (ELEM), \
    FOCUSED_HTML50_ATTRIBUTES (ELEM)

#define STANDARD_HTML50_ATTRIBUTES(ELEM) \
    NEW_HTML50_ATTRIBUTES (ELEM), \
    HTML4_ATTRIBUTES_BASE (ELEM, MAJOR_5_0, MINOR_5_0), \
    HTML5_STANDARDISED_HTML4_ATTRIBUTES (ELEM)

#define STANDARD_HTML_4_50_ATTRIBUTES(ELEM) \
    COMMON_HTML4_ATTRIBUTES (ELEM), \
    HTML5_STANDARDISED_HTML4_ATTRIBUTES (ELEM), \
    NEW_HTML50_ATTRIBUTES (ELEM)

#define EXTRA_HTML51_ATTRIBUTES(ELEM) \
    { { HTML_5_1, HV_NOT52 | HV_NOT53 }, { HTML_UNDEF }, ELEM, a_contextmenu }, \
    { { HTML_5_1 }, { HTML_UNDEF }, ELEM, a_draggable }, \
    { { HTML_5_1 }, { HTML_5_1 }, ELEM, a_dropzone }, \
    { { HTML_5_1 }, { HTML_UNDEF }, ELEM, a_onclose }, \
    { { HTML_5_1, HV_NOT52 | HV_NOT53 }, { HTML_UNDEF }, ELEM, a_oncontextmenu }, \
    { { HTML_5_1, HV_NOT52 | HV_NOT53 }, { HTML_UNDEF }, ELEM, a_oncopy }, \
    { { HTML_5_1, HV_NOT52 | HV_NOT53 }, { HTML_UNDEF }, ELEM, a_oncut }, \
    { { HTML_5_1 }, { HTML_UNDEF }, ELEM, a_ondrag }, \
    { { HTML_5_1 }, { HTML_UNDEF }, ELEM, a_ondragend }, \
    { { HTML_5_1 }, { HTML_UNDEF }, ELEM, a_ondragenter }, \
    { { HTML_5_1 }, { HTML_UNDEF }, ELEM, a_ondragexit }, \
    { { HTML_5_1 }, { HTML_UNDEF }, ELEM, a_ondragleave }, \
    { { HTML_5_1 }, { HTML_UNDEF }, ELEM, a_ondragover }, \
    { { HTML_5_1 }, { HTML_UNDEF }, ELEM, a_ondragstart }, \
    { { HTML_5_1 }, { HTML_UNDEF }, ELEM, a_ondrop }, \
    { { HTML_5_1 }, { HTML_UNDEF }, ELEM, a_onfocus }, \
    { { HTML_5_1 }, { HTML_UNDEF }, ELEM, a_onwheel }, \
    { { HTML_5_1, HV_NOT52 | HV_NOT53 }, { HTML_UNDEF }, ELEM, a_onpaste }

#define NEW_HTML51_ATTRIBUTES(ELEM) \
    EXTRA_HTML51_ATTRIBUTES (ELEM), \
    NEW_HTML50_ATTRIBUTES (ELEM)

#define STANDARD_HTML51_ATTRIBUTES(ELEM) \
    NEW_HTML51_ATTRIBUTES (ELEM), \
    HTML4_ATTRIBUTES_BASE (ELEM, MAJOR_4_0, MINOR_4_0), \
    HTML5_STANDARDISED_HTML4_ATTRIBUTES (ELEM)

#define STANDARD_HTML_4_51_ATTRIBUTES(ELEM) \
    COMMON_HTML4_ATTRIBUTES (ELEM), \
    HTML5_STANDARDISED_HTML4_ATTRIBUTES (ELEM), \
    NEW_HTML51_ATTRIBUTES (ELEM)

#define EXTRA_HTML52_ATTRIBUTES(ELEM) \
    { { HTML_5_2 }, { HTML_UNDEF }, ELEM, a_onauxclick }, \
    { { HTML_5_2 }, { HTML_5_3 }, ELEM, a_onloadend }

#define NEW_HTML52_ATTRIBUTES(ELEM) \
    EXTRA_HTML52_ATTRIBUTES (ELEM), \
    NEW_HTML51_ATTRIBUTES (ELEM)

#define STANDARD_HTML52_ATTRIBUTES(ELEM) \
    NEW_HTML52_ATTRIBUTES (ELEM), \
    HTML4_ATTRIBUTES_BASE (ELEM, MAJOR_4_0, MINOR_4_0), \
    HTML5_STANDARDISED_HTML4_ATTRIBUTES (ELEM)

#define STANDARD_HTML_4_52_ATTRIBUTES(ELEM) \
    COMMON_HTML4_ATTRIBUTES (ELEM), \
    HTML5_STANDARDISED_HTML4_ATTRIBUTES (ELEM), \
    NEW_HTML52_ATTRIBUTES (ELEM)

#define EXTRA_HTML53_ATTRIBUTES(ELEM) \
    { { HTML_5_3 }, { HTML_UNDEF }, ELEM, a_datawild }, \
    { { HTML_5_3 }, { HTML_UNDEF }, ELEM, a_is }, \
    { { HTML_5_3 }, { HTML_5_3 }, ELEM, a_numberonce }, \
    { { HTML_5_3 }, { HTML_5_3 }, ELEM, a_xmlns }

#define NEW_HTML53_ATTRIBUTES(ELEM) \
    EXTRA_HTML53_ATTRIBUTES (ELEM), \
    NEW_HTML52_ATTRIBUTES (ELEM)

#define STANDARD_HTML53_ATTRIBUTES(ELEM) \
    NEW_HTML53_ATTRIBUTES (ELEM), \
    HTML4_ATTRIBUTES_BASE (ELEM, MAJOR_4_0, MINOR_4_0), \
    HTML5_STANDARDISED_HTML4_ATTRIBUTES (ELEM)

#define STANDARD_HTML_4_53_ATTRIBUTES(ELEM) \
    COMMON_HTML4_ATTRIBUTES (ELEM), \
    HTML5_STANDARDISED_HTML4_ATTRIBUTES (ELEM), \
    NEW_HTML53_ATTRIBUTES (ELEM)

#define EXTRA_HTML54_ATTRIBUTES(ELEM) \
    { { HTML_JUL20 }, { HTML_UNDEF }, ELEM, a_autocapitalise }, \
    { { HTML_JUL20 }, { HTML_UNDEF }, ELEM, a_autofocus }, \
    { { HTML_JUL20 }, { HTML_UNDEF }, ELEM, a_enterkeyhint }, \
    { { HTML_JUL20 }, { HTML_UNDEF }, ELEM, a_inputmode }, \
    { { HTML_JUL20 }, { HTML_UNDEF }, ELEM, a_is }, \
    { { HTML_JUL20 }, { HTML_UNDEF }, ELEM, a_onformdata }, \
    { { HTML_JUL20 }, { HTML_UNDEF }, ELEM, a_onsecuritypolicyviolation }, \
    { { HTML_JUL20 }, { HTML_UNDEF }, ELEM, a_onslotchange }, \
    { { HTML_JUL20 }, { HTML_UNDEF }, ELEM, a_onvolumechange }, \
    { { HTML_JUL20 }, { HTML_UNDEF }, ELEM, a_slot }, \
    MICRODATA_ATTRIBUTES (ELEM, MAJOR_J20, MINOR_J20, HE_NOT_SVG)

#define NEW_HTML54_ATTRIBUTES(ELEM) \
    EXTRA_HTML54_ATTRIBUTES (ELEM), \
    NEW_HTML53_ATTRIBUTES (ELEM)

#define STANDARD_HTML54_ATTRIBUTES(ELEM) \
    NEW_HTML54_ATTRIBUTES (ELEM), \
    HTML4_ATTRIBUTES_BASE (ELEM, MAJOR_4_0, MINOR_4_0), \
    HTML5_STANDARDISED_HTML4_ATTRIBUTES (ELEM)

#define STANDARD_HTML_4_54_ATTRIBUTES(ELEM) \
    COMMON_HTML4_ATTRIBUTES (ELEM), \
    HTML5_STANDARDISED_HTML4_ATTRIBUTES (ELEM), \
    NEW_HTML54_ATTRIBUTES (ELEM)

#define STANDARD_H_ATTRIBUTES(ELEM) \
    HTMLPLUS_ATTRIBUTES (ELEM), \
    STANDARD_HTML_23_H_ATTRIBUTES (ELEM), \
    STANDARD_HTML_4_54_ATTRIBUTES (ELEM)


hav_t havt [] =
{   { { HTML_2_0, HV_RFC_2070 | HV_NOT3 }, { XHTML_2_0 }, elem_a, a_charset },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_a, a_coords },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_a, a_download },
    { { HTML_PLUS }, { HTML_PLUS }, elem_a, a_effect },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_a, a_externalresourcesrequired },
    { { HTML_TAGS }, { HTML_UNDEF }, elem_a, a_href },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_a, a_hreflang },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_a, a_md },
    { { HTML_1_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_a, a_methods },
    { { HTML_TAGS, HV_DEPRECATED30 | HV_DEPRECATEDX1 | HV_NOTX2 }, { HTML_UNDEF }, elem_a, a_name },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_a, a_onblur },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_a, a_onfocus },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_a, a_ping },
    { { HTML_PLUS }, { HTML_PLUS }, elem_a, a_print },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_a, a_referrerpolicy },
    { { HTML_1_0 }, { HTML_UNDEF }, elem_a, a_rel },
    { { HTML_1_0, HV_NOT50 }, { HTML_5_3 }, elem_a, a_rev },
    { { HTML_2_0, 0, HE_MOZILLA | HE_NETSCAPE }, { HTML_3_2 }, elem_a, a_shape },
    { { HTML_PLUS, HV_NOT2 | HV_NOT32 }, { XHTML_2_0 }, elem_a, a_shape },
    { { HTML_PLUS }, { HTML_PLUS }, elem_a, a_size },
    { { HTML_PLUS }, { HTML_PLUS }, elem_a, a_style },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_a, a_target },
    { { HTML_1_0, HV_NOT30 }, { HTML_3_2 }, elem_a, a_title },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_a, a_transform },
    { { HTML_TAGS, HV_NOT10 | HV_NOT2 | HV_NOT3 }, { HTML_UNDEF }, elem_a, a_type },
    { { HTML_1_0 }, { HTML_2_0 }, elem_a, a_urn },
    HTMLPLUS_ATTRIBUTES (elem_a),
    HTML23_CLID_ATTRIBUTES (elem_a),
    HTML4_FORM_ATTRIBUTES (elem_a),
    SVG10_REPL_ATTRIBUTES (elem_a),
    SVG11_XLINK_ATTRIBUTES (elem_a),
    SVG11_GREV_ATTRIBUTES (elem_a),
    SVGx_CONDPROC_ATTRIBUTES (elem_a),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_a),
    SVGx_PRES_ATTRIBUTES (elem_a),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_a),

    { { XHTML_2_0 }, { XHTML_2_0 }, elem_abbr, a_full },
    STANDARD_HTML_4_54_ATTRIBUTES (elem_abbr),

    HTMLPLUS_ATTRIBUTES (elem_abbrev),
    HTML3_CLID_ATTRIBUTES (elem_abbrev),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_above, a_sym },

    MATH1_DEFS_ATTRIBUTES (elem_abs, MAJOR_X1_0, MINOR_X1_0),

    HTMLPLUS_ATTRIBUTES (elem_abstract),

    HTMLPLUS_ATTRIBUTES (elem_acronym),
    HTML3_CLID_ATTRIBUTES (elem_acronym),
    COMMON_HTML4_ATTRIBUTES (elem_acronym),

    { { XHTML_2_0 }, { XHTML_2_0 }, elem_access, a_activate },
    { { XHTML_2_0 }, { XHTML_2_0 }, elem_access, a_key },
    { { XHTML_2_0 }, { XHTML_2_0 }, elem_access, a_media },
    { { XHTML_2_0 }, { XHTML_2_0 }, elem_access, a_order },
    { { XHTML_2_0 }, { XHTML_2_0 }, elem_access, a_targetid },
    { { XHTML_2_0 }, { XHTML_2_0 }, elem_access, a_targetrole },
    XHTML2_ATTRIBUTES (elem_access),

    { { XHTML_2_0 }, { XHTML_2_0 }, elem_action, a_declare },
    { { XHTML_2_0 }, { XHTML_2_0 }, elem_action, a_if },
    { { XHTML_2_0 }, { XHTML_2_0 }, elem_action, a_while },
    XHTML2_ATTRIBUTES (elem_action),

    HTMLPLUS_ATTRIBUTES (elem_added),

    XHTML2_ATTRIBUTES (elem_addeventlistener),

    { { HTML_2_0, HV_RFC_2070 }, { HTML_2_0 }, elem_address, a_align },
    { { MAJOR_3_0, MINOR_3_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_address, a_clear },
    { { HTML_3_2 }, { XHTML_2_0 }, elem_address, a_nowrap },
    HTML23_CLID_ATTRIBUTES (elem_address),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_address),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_altglyph, a_externalresourcesrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_altglyph, a_format },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_altglyph, a_glyphref },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_altglyph, a_rotate },
    SVG10_XY_ATTRIBUTES (elem_altglyph),
    SVG10_DXY_ATTRIBUTES (elem_altglyph),
    SVG11_XLINK_ATTRIBUTES (elem_altglyph),
    SVG11_GREV_ATTRIBUTES (elem_altglyph),
    SVGx_CONDPROC_ATTRIBUTES (elem_altglyph),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_altglyph),
    SVGx_PRES_ATTRIBUTES (elem_altglyph),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_altglyph),

    SVGx_XTRA_CORE_ATTRIBUTES (elem_altglyphdef),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_altglyphdef),

    SVGx_XTRA_CORE_ATTRIBUTES (elem_altglyphitem),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_altglyphitem),

    MATH1_DEFS_ATTRIBUTES (elem_and, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_animate, a_externalresourcesrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_animate, a_from },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_animate, a_to},
    SVG11_ANADD_ATTRIBUTES (elem_animate),
    SVG11_ANAT_ATTRIBUTES (elem_animate),
    SVG11_ANEV_ATTRIBUTES (elem_animate),
    SVG11_ANTIME_ATTRIBUTES (elem_animate),
    SVG11_ANVAL_ATTRIBUTES (elem_animate),
    SVG11_XLINK_ATTRIBUTES (elem_animate),
    SVGx_CONDPROC_ATTRIBUTES (elem_animate),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_animate),
    SVGx_PRES_ATTRIBUTES (elem_animate),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_animate),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_animatecolour, a_externalresourcesrequired },
    SVG11_ANADD_ATTRIBUTES (elem_animatecolour),
    SVG11_ANAT_ATTRIBUTES (elem_animatecolour),
    SVG11_ANEV_ATTRIBUTES (elem_animatecolour),
    SVG11_ANTIME_ATTRIBUTES (elem_animatecolour),
    SVG11_ANVAL_ATTRIBUTES (elem_animatecolour),
    SVG11_XLINK_ATTRIBUTES (elem_animatecolour),
    SVGx_CONDPROC_ATTRIBUTES (elem_animatecolour),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_animatecolour),
    SVGx_PRES_ATTRIBUTES (elem_animatecolour),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_animatecolour),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_animatemotion, a_externalresourcesrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_animatemotion, a_keypoints },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_animatemotion, a_origin },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_animatemotion, a_path },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_animatemotion, a_rotate },
    SVG11_ANADD_ATTRIBUTES (elem_animatemotion),
    SVG11_ANEV_ATTRIBUTES (elem_animatemotion),
    SVG11_ANTIME_ATTRIBUTES (elem_animatemotion),
    SVG11_ANVAL_ATTRIBUTES (elem_animatemotion),
    SVG11_XLINK_ATTRIBUTES (elem_animatemotion),
    SVGx_CONDPROC_ATTRIBUTES (elem_animatemotion),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_animatemotion),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_animatemotion),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_animatetransform, a_externalresourcesrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_animatetransform, a_from },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_animatetransform, a_to },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_animatetransform, a_type },
    SVG11_ANADD_ATTRIBUTES (elem_animatetransform),
    SVG11_ANAT_ATTRIBUTES (elem_animatetransform),
    SVG11_ANEV_ATTRIBUTES (elem_animatetransform),
    SVG11_ANTIME_ATTRIBUTES (elem_animatetransform),
    SVG11_ANVAL_ATTRIBUTES (elem_animatetransform),
    SVG11_XLINK_ATTRIBUTES (elem_animatetransform),
    SVGx_CONDPROC_ATTRIBUTES (elem_animatetransform),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_animatetransform),
    SVGx_PRES_ATTRIBUTES (elem_animatetransform),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_animatetransform),

    STANDARD_HTML_4_54_ATTRIBUTES (elem_animation),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_annotation, a_encoding },
    MATH1_STANDARD_ATTRIBUTES (elem_annotation, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_annotation_xml, a_encoding },
    MATH1_STANDARD_ATTRIBUTES (elem_annotation_xml, MAJOR_X1_0, MINOR_X1_0),

    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_applet, a_align },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_applet, a_alt },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_applet, a_archive },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_applet, a_class },
    { { HTML_3_2, HV_DEPRECATED4 | REQUIRED }, { XHTML_2_0 }, elem_applet, a_code },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_applet, a_codebase },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_applet, a_height },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_applet, a_id },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_applet, a_hspace },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_applet, a_name },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_applet, a_object },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_applet, a_style },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_applet, a_title },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_applet, a_vspace },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_applet, a_width },

    MATH1_STANDARD_ATTRIBUTES (elem_apply, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_arccos, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_arcsin, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_arctan, MAJOR_X1_0, MINOR_X1_0),

    { { HTML_2_0, HV_NOT30 | HV_RFC_1980 }, { HTML_UNDEF }, elem_area, a_alt },
    { { HTML_2_0, HV_RFC_1980 | HV_NOT30 | REQUIRED }, { HTML_UNDEF }, elem_area, a_coords },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_area, a_download },
    { { HTML_2_0, HV_NOT30 | HV_RFC_1980 }, { HTML_UNDEF }, elem_area, a_href },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_5_3 }, elem_area, a_hreflang },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_area, a_name },
    { { HTML_2_0, HV_NOT30 | HV_RFC_1980 }, { XHTML_2_0 }, elem_area, a_nohref },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_area, a_onblur },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_area, a_onfocus },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_area, a_ping },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_area, a_referrerpolicy },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_area, a_rel },
    { { HTML_2_0, HV_NOT30 | HV_RFC_1980 }, { HTML_UNDEF }, elem_area, a_shape },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_area, a_target },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_5_3 }, elem_area, a_type },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_area, a_usemap },
    HTML4_FORM_ATTRIBUTES (elem_area),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_area),

    HTMLPLUS_ATTRIBUTES (elem_arg),

    { { HTML_PLUS, HV_NOT2 }, { MAJOR_3_0, MINOR_3_0 }, elem_array, a_align },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_array, a_coldef },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_array, a_labels },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_array, a_ldelim },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_array, a_rdelim },

    HTML3_CLID_ATTRIBUTES (elem_array),

    STANDARD_HTML54_ATTRIBUTES (elem_article),

    STANDARD_HTML54_ATTRIBUTES (elem_aside),

    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_audio, a_autoplay },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_audio, a_controls },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_audio, a_crossorigin },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_MOZILLA }, { HTML_UNDEF }, elem_audio, a_currenttime },
    { { HTML_5_3, HV_W3, HE_EXPERIMENTAL }, { HTML_UNDEF }, elem_audio, a_disableremoteplayback },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_audio, a_loop },
    { { MAJOR_5_0, MINOR_5_0 }, { MAJOR_5_0, MINOR_5_0 }, elem_audio, a_mediagroup },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_audio, a_muted },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_audio, a_preload },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_audio, a_src },
    STANDARD_HTML54_ATTRIBUTES(elem_audio),

    HTML3_CLID_ATTRIBUTES (elem_au),

    HTMLPLUS_ATTRIBUTES (elem_b),
    HTML23_CLID_ATTRIBUTES (elem_b),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_b),

    HTML3_CLID_ATTRIBUTES (elem_banner),

    HTML3_CLID_ATTRIBUTES (elem_bar),

    { { HTML_2_0, REQUIRED }, { HTML_UNDEF }, elem_base, a_href },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_base, a_id },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_base, a_target },
    STANDARD_HTML54_ATTRIBUTES (elem_base),

    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_basefont, a_colour },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_basefont, a_face },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_basefont, a_size },
    HTML4_STANDARD_TSL_ATTRIBUTES (elem_basefont, MAJOR_4_0, MINOR_4_0),

    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_bdi, a_dir },
    STANDARD_HTML54_ATTRIBUTES (elem_bdi),

    { { HTML_2_0, HV_RFC_2070 | REQUIRED }, { HTML_2_0 }, elem_bdo, a_dir },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_bdo, a_dir },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_bdo, a_lang },
    HTML2_CLID_ATTRIBUTES (elem_bdo),
    STANDARD_HTML54_ATTRIBUTES (elem_bdo),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_below, a_sym },

    HTML3_CLID_ATTRIBUTES (elem_big),
    COMMON_HTML4_ATTRIBUTES (elem_big),

    { { HTML_2_0 }, { HTML_UNDEF }, elem_bgsound, a_balance },
    { { HTML_2_0 }, { HTML_UNDEF }, elem_bgsound, a_loop },
    { { HTML_2_0 }, { HTML_UNDEF }, elem_bgsound, a_src },
    { { HTML_2_0 }, { HTML_UNDEF }, elem_bgsound, a_volume },

    { { HTML_2_0, HV_RFC_2070 }, { HTML_2_0 }, elem_blockquote, a_align },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_blockquote, a_cite },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_blockquote, a_clear },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_blockquote, a_nowrap },
    HTML23_CLID_ATTRIBUTES (elem_blockquote),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_blockquote),

    XHTML2_ATTRIBUTES (elem_blockcode),

    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_body, a_alink },
    { { MAJOR_3_0, MINOR_3_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_body, a_background },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_body, a_bgcolour },
    { { HTML_3_2, HV_DEPRECATED4, HE_CHROME }, { XHTML_2_0 }, elem_body, a_bottommargin },
    { { HTML_3_2, HV_DEPRECATED4, HE_CHROME }, { XHTML_2_0 }, elem_body, a_leftmargin },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_body, a_link },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_body, a_onafterprint },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_body, a_onbeforeprint },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_body, a_onbeforeunload },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_body, a_onhashchange },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_body, a_onlanguagechange },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_body, a_onload },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_body, a_onmessage },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_body, a_onmessageerror },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_body, a_onoffline },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_body, a_ononline },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_body, a_onpagehide },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_body, a_onpageshow },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_body, a_onpopstate },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_body, a_onrejectionhandled },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_body, a_onstorage },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_body, a_onunhandledrejection },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_body, a_onunload },
    { { HTML_3_2, HV_DEPRECATED4, HE_CHROME }, { HTML_3_2 }, elem_body, a_rightmargin },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_body, a_text },
    { { HTML_3_2, HV_DEPRECATED4, HE_CHROME }, { HTML_3_2 }, elem_body, a_topmargin },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_body, a_vlink },
    HTML23_CLID_ATTRIBUTES (elem_body),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_body),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_box, a_size },

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_bq, a_clear },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_bq, a_nowrap },
    HTML3_CLID_ATTRIBUTES (elem_bq),

    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_br, a_id },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_br, a_class },
    { { HTML_2_0, HV_RFC_1942 | HV_DEPRECATED4 }, { XHTML_2_0 }, elem_br, a_clear },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_br, a_title },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_br, a_style },
    HTMLPLUS_ATTRIBUTES (elem_br),
    HTML3_CLID_ATTRIBUTES (elem_br),
    HTML4_STANDARD_SCRIPT_ATTRIBUTES (elem_br, MAJOR_5_0, MINOR_5_0),
    HTML4_STANDARD_LANG_ATTRIBUTES (elem_br,MAJOR_5_0, MINOR_5_0),
    NEW_HTML50_ATTRIBUTES (elem_br),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_bt, a_class },

    { { MAJOR_5_0, MINOR_5_0, 0, HE_MOZILLA }, { HTML_UNDEF }, elem_button, a_autocomplete },
    { { MAJOR_5_0, MINOR_5_0, HV_W3 }, { HTML_5_3 }, elem_button, a_autofocus },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_button, a_datafld },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_button, a_dataformatas },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_button, a_datasrc },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_button, a_disabled },
    HTML50_FORM (elem_button),
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_5_1 }, elem_button, a_menu },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_button, a_name },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_button, a_onblur },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_button, a_onfocus },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_button, a_type },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_button, a_value },
    HTML4_FORM_ATTRIBUTES (elem_button),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_button),

    MATH1_STANDARD_ATTRIBUTES (elem_bvar, MAJOR_X1_0, MINOR_X1_0),

    HTMLPLUS_ATTRIBUTES (elem_byline),

    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_canvas, a_height },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_canvas, a_width },
    STANDARD_HTML54_ATTRIBUTES (elem_canvas),

    { { HTML_2_0, HV_DEPRECATED4 | HV_RFC_1942 }, { XHTML_2_0 }, elem_caption, a_align },
    { { HTML_3_2 }, { HTML_3_2 }, elem_caption, a_valign },
    HTMLPLUS_ATTRIBUTES (elem_caption),
    HTML23_CLID_ATTRIBUTES (elem_caption),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_caption),

    { { HTML_PLUS }, { HTML_PLUS }, elem_changed, a_idref },
    HTMLPLUS_ATTRIBUTES (elem_changed),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_ci, a_type },
    MATH1_STANDARD_ATTRIBUTES (elem_ci, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_circle, a_cx },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_circle, a_cy },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_circle, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 | REQUIRED }, { HTML_UNDEF }, elem_circle, a_r },
    SVG10_G_ATTRIBUTES(elem_circle),
    SVG11_GREV_ATTRIBUTES (elem_circle),
    SVGx_CONDPROC_ATTRIBUTES (elem_circle),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_circle),
    SVGx_PRES_ATTRIBUTES (elem_circle),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_circle),

    HTMLPLUS_ATTRIBUTES (elem_cite),
    HTML23_CLID_ATTRIBUTES (elem_cite),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_cite),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_clippath, a_clippathunits },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_clippath, a_externalresourcesrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_clippath, a_transform },
    SVGx_XTRA_CORE_ATTRIBUTES (elem_clippath),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_clippath),
    SVGx_PRES_ATTRIBUTES (elem_clippath),
    STANDARD_HTML54_ATTRIBUTES (elem_clippath),

    HTMLPLUS_ATTRIBUTES (elem_cmd),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_cn, a_base },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_cn, a_type },
    MATH1_STANDARD_ATTRIBUTES (elem_cn, MAJOR_X1_0, MINOR_X1_0),

    HTMLPLUS_ATTRIBUTES (elem_code),
    HTML23_CLID_ATTRIBUTES (elem_code),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_code),

    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 | HV_DEPRECATED4 }, { XHTML_2_0 }, elem_col, a_align },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3, HE_IE }, { XHTML_2_0 }, elem_col, a_bgcolour },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 }, { XHTML_2_0 }, elem_col, a_char },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 }, { XHTML_2_0 }, elem_col, a_charoff },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 }, { HTML_UNDEF }, elem_col, a_span },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 }, { XHTML_2_0 }, elem_col, a_valign },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 }, { XHTML_2_0 }, elem_col, a_width },
    HTML2_CLID_ATTRIBUTES (elem_col),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_col),

    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 | HV_DEPRECATED4 }, { XHTML_2_0 }, elem_colgroup, a_align },
    { { HTML_2_0, HV_NOT3, HE_IE }, { HTML_2_0 }, elem_colgroup, a_bgcolour },
    { { HTML_2_0, HV_RFC_1942 }, { HTML_2_0 }, elem_colgroup, a_char },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_colgroup, a_char },
    { { HTML_2_0, HV_RFC_1942 }, { HTML_2_0 }, elem_colgroup, a_charoff },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_IE }, { XHTML_2_0 }, elem_colgroup, a_charoff },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 }, { HTML_UNDEF }, elem_colgroup, a_span },
    { { HTML_2_0, HV_RFC_1942 }, { HTML_2_0 }, elem_colgroup, a_valign },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_colgroup, a_valign },
    { { HTML_2_0, HV_RFC_1942 }, { HTML_2_0 }, elem_colgroup, a_width },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_colgroup, a_width },
    HTML2_CLID_ATTRIBUTES (elem_colgroup),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_colgroup),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_colourprofile, a_local },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_colourprofile, a_renderingintent },
    SVG11_XLINK_ATTRIBUTES (elem_colourprofile),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_colourprofile),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_colourprofile),

    MATH1_DEFS_ATTRIBUTES (elem_compose, MAJOR_X1_0, MINOR_X1_0),

    MATH1_STANDARD_ATTRIBUTES (elem_condition, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_5_0, MINOR_5_0 }, { MAJOR_5_0, MINOR_5_0 }, elem_command, a_checked },
    { { MAJOR_5_0, MINOR_5_0 }, { MAJOR_5_0, MINOR_5_0 }, elem_command, a_disabled },
    { { MAJOR_5_0, MINOR_5_0 }, { MAJOR_5_0, MINOR_5_0 }, elem_command, a_icon },
    { { MAJOR_5_0, MINOR_5_0 }, { MAJOR_5_0, MINOR_5_0 }, elem_command, a_radiogroup },
    { { MAJOR_5_0, MINOR_5_0 }, { MAJOR_5_0, MINOR_5_0 }, elem_command, a_type },
    STANDARD_HTML50_ATTRIBUTES (elem_command),

    { { HTML_2_0 }, { HTML_4_01 }, elem_comment, a_data },
    HTML4_STANDARD_TSL_ATTRIBUTES (elem_comment, MAJOR_4_0, MINOR_4_0),

    MATH1_DEFS_ATTRIBUTES (elem_conjugate, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_content, a_select },
    STANDARD_HTML54_ATTRIBUTES (elem_content),

    MATH1_DEFS_ATTRIBUTES (elem_cos, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_cosh, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_cot, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_coth, MAJOR_X1_0, MINOR_X1_0),

    HTML3_CLID_ATTRIBUTES (elem_credit),

    MATH1_DEFS_ATTRIBUTES (elem_csc, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_csch, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_cursor, a_externalresourcesrequired },
    SVG10_XY_ATTRIBUTES (elem_cursor),
    SVG11_XLINK_ATTRIBUTES (elem_cursor),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_cursor),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_cursor),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_data, a_d },
    { { MAJOR_5_0, MINOR_5_0, REQUIRED }, { HTML_UNDEF }, elem_data, a_value },
    STANDARD_HTML_4_54_ATTRIBUTES (elem_data),

    STANDARD_HTML54_ATTRIBUTES (elem_datalist),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_dd, a_clear },
    HTML23_CLID_ATTRIBUTES (elem_dd),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_dd),

    HTML3_CLID_ATTRIBUTES (elem_ddot),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_declare, a_nargs },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_declare, a_occurrence },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_declare, a_scope },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_declare, a_type },
    MATH1_DEFS_ATTRIBUTES (elem_declare, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_defs, a_externalresourcesrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_defs, a_transform },
    SVGx_CONDPROC_ATTRIBUTES (elem_defs),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_defs),
    SVG11_GREV_ATTRIBUTES (elem_defs),
    SVGx_PRES_ATTRIBUTES (elem_defs),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_defs),

    MATH1_STANDARD_ATTRIBUTES (elem_degree, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_del, a_cite },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_del, a_datetime },
    HTML3_CLID_ATTRIBUTES (elem_del),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_del),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_desc, a_systemrequired },
    SVGx_XTRA_CORE_ATTRIBUTES (elem_desc),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_desc),

    { { HTML_5_1 }, { HTML_UNDEF }, elem_details, a_open },
    STANDARD_HTML_4_54_ATTRIBUTES (elem_details),

    MATH1_DEFS_ATTRIBUTES (elem_determinant, MAJOR_X1_0, MINOR_X1_0),

    HTMLPLUS_ATTRIBUTES (elem_dfn),
    HTML3_CLID_ATTRIBUTES (elem_dfn),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_dfn),

    XHTML2_ATTRIBUTES (elem_di),

    { { HTML_5_2 }, { HTML_UNDEF }, elem_dialogue, a_open },
    STANDARD_HTML54_ATTRIBUTES (elem_dialogue),

    MATH1_DEFS_ATTRIBUTES (elem_diff, MAJOR_X1_0, MINOR_X1_0),

    { { HTML_2_0, HV_RFC_2070 }, { HTML_2_0 }, elem_dir, a_align },
    { { HTML_3_2 }, { MAJOR_3_0, MINOR_3_0 }, elem_dir, a_clear },
    { { HTML_2_0 }, { XHTML_2_0 }, elem_dir, a_compact },
    HTMLPLUS_ATTRIBUTES (elem_dir),
    HTML2_CLID_ATTRIBUTES (elem_dir),
    COMMON_HTML4_ATTRIBUTES (elem_dir),

    STANDARD_HTML_4_54_ATTRIBUTES (elem_discard),

    { { XHTML_2_0 }, { XHTML_2_0 }, elem_dispatchevent, a_bubbles },
    { { XHTML_2_0 }, { XHTML_2_0 }, elem_dispatchevent, a_cancelable },
    XHTML2_ATTRIBUTES (elem_dispatchevent),

    { { MAJOR_3_0, MINOR_3_0 }, { XHTML_2_0 }, elem_div, a_align },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_div, a_clear },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_div, a_datafld },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_div, a_dataformatas },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_div, a_datasrc },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_div, a_nowrap },
    HTML3_CLID_ATTRIBUTES (elem_div),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_div),

    MATH1_DEFS_ATTRIBUTES (elem_divide, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_dl, a_clear },
    { { HTML_1_0 }, { HTML_3_2 }, elem_dl, a_compact },
    HTMLPLUS_ATTRIBUTES (elem_dl),
    HTML23_CLID_ATTRIBUTES (elem_dl),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_dl),

    HTML3_CLID_ATTRIBUTES (elem_dot),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_dt, a_clear },
    HTML23_CLID_ATTRIBUTES (elem_dt),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_dt),

    STANDARD_HTML54_ATTRIBUTES (elem_element),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_ellipse, a_cx },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_ellipse, a_cy },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_ellipse, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 | REQUIRED }, { HTML_UNDEF }, elem_ellipse, a_rx },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 | REQUIRED }, { HTML_UNDEF }, elem_ellipse, a_ry },
    SVG10_G_ATTRIBUTES(elem_ellipse),
    SVG11_GREV_ATTRIBUTES (elem_ellipse),
    SVGx_CONDPROC_ATTRIBUTES (elem_ellipse),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_ellipse),
    SVGx_PRES_ATTRIBUTES (elem_ellipse),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_ellipse),

    HTMLPLUS_ATTRIBUTES (elem_em),
    HTML3_CLID_ATTRIBUTES (elem_em),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_em),

    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_embed, a_height },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_embed, a_src },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_embed, a_type },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_embed, a_width },
    { { MAJOR_5_0, MINOR_5_0, REJECT }, { HTML_UNDEF }, elem_embed, a_align },
    { { MAJOR_5_0, MINOR_5_0, REJECT }, { HTML_UNDEF }, elem_embed, a_hspace },
    { { MAJOR_5_0, MINOR_5_0, REJECT }, { HTML_UNDEF }, elem_embed, a_name },
    { { MAJOR_5_0, MINOR_5_0, REJECT }, { HTML_UNDEF }, elem_embed, a_vspace },
    STANDARD_HTML54_ATTRIBUTES (elem_embed),

    MATH1_DEFS_ATTRIBUTES (elem_eq, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_exists, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_exp, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_factorial, MAJOR_X1_0, MINOR_X1_0),

    // faux_doctype and faux_xml processed before getting here,
    // so no need to add corresponding attribute information

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_feblend, a_in2 },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_feblend, a_mode },
    SVG10_FILTER_ATTRIBUTES (elem_feblend),
    SVG11_FILTER_ATTRIBUTES (elem_feblend),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_feblend),
    SVGx_PRES_ATTRIBUTES (elem_feblend),
    STANDARD_HTML54_ATTRIBUTES (elem_feblend),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fecolour, a_colour },
    SVG10_FILTER_ATTRIBUTES (elem_fecolour),
    STANDARD_HTML54_ATTRIBUTES (elem_fecolour),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 | REQUIRED }, { HTML_UNDEF }, elem_fecolourmatrix, a_type },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fecolourmatrix, a_values },
    SVG10_FILTER_ATTRIBUTES (elem_fecolourmatrix),
    SVG11_FILTER_ATTRIBUTES (elem_fecolourmatrix),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fecolourmatrix),
    SVGx_PRES_ATTRIBUTES (elem_fecolourmatrix),
    STANDARD_HTML54_ATTRIBUTES (elem_fecolourmatrix),

    SVG10_FILTER_ATTRIBUTES (elem_fecomponenttransfer),
    SVG11_FILTER_ATTRIBUTES (elem_fecomponenttransfer),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fecomponenttransfer),
    SVGx_PRES_ATTRIBUTES (elem_fecomponenttransfer),
    STANDARD_HTML54_ATTRIBUTES (elem_fecomponenttransfer),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fecomposite, a_operator },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fecomposite, a_k1 },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fecomposite, a_k2 },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fecomposite, a_k3 },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fecomposite, a_k4 },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 | REQUIRED }, { HTML_UNDEF }, elem_fecomposite, a_in2 },
    SVG10_FILTER_ATTRIBUTES (elem_fecomposite),
    SVG11_FILTER_ATTRIBUTES (elem_fecomposite),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fecomposite),
    SVGx_PRES_ATTRIBUTES (elem_fecomposite),
    STANDARD_HTML54_ATTRIBUTES (elem_fecomposite),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_feconvolvematrix, a_bias },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_feconvolvematrix, a_divisor },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_feconvolvematrix, a_edgemode },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_feconvolvematrix, a_in },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_feconvolvematrix, a_kernelmatrix },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_feconvolvematrix, a_kernelunitlength },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_feconvolvematrix, a_order },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_feconvolvematrix, a_preservealpha },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_feconvolvematrix, a_targetx },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_feconvolvematrix, a_targety },
    SVG11_FILTER_ATTRIBUTES (elem_feconvolvematrix),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_feconvolvematrix),
    SVGx_PRES_ATTRIBUTES (elem_feconvolvematrix),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_feconvolvematrix),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fediffuselighting, a_diffuseconstant },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fediffuselighting, a_lightcolour },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fediffuselighting, a_resultscale },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fediffuselighting, a_surfacescale },
    SVG10_FILTER_ATTRIBUTES (elem_fediffuselighting),
    STANDARD_HTML54_ATTRIBUTES (elem_fediffuselighting),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fedisplacementmap, a_xchannelselector },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fedisplacementmap, a_ychannelselector },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fedisplacementmap, a_in2 },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fedisplacementmap, a_scale },
    SVG10_FILTER_ATTRIBUTES (elem_fedisplacementmap),
    SVG11_FILTER_ATTRIBUTES (elem_fedisplacementmap),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fedisplacementmap),
    SVGx_PRES_ATTRIBUTES (elem_fedisplacementmap),
    STANDARD_HTML54_ATTRIBUTES (elem_fedisplacementmap),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fedistantlight, a_azimuth },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fedistantlight, a_elevation },
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fedistantlight),
    STANDARD_HTML54_ATTRIBUTES (elem_fedistantlight),

    STANDARD_HTML_4_54_ATTRIBUTES (elem_fedropshadow),

    SVG11_FILTER_ATTRIBUTES (elem_feflood),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_feflood),
    SVGx_PRES_ATTRIBUTES (elem_feflood),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_feflood),

    SVG10_COMP_ATTRIBUTES (elem_fefunca),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fefunca),
    STANDARD_HTML54_ATTRIBUTES (elem_fefunca),

    SVG10_COMP_ATTRIBUTES (elem_fefuncb),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fefuncb),
    STANDARD_HTML54_ATTRIBUTES (elem_fefuncb),

    SVG10_COMP_ATTRIBUTES (elem_fefuncg),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fefuncg),
    STANDARD_HTML54_ATTRIBUTES (elem_fefuncg),

    SVG10_COMP_ATTRIBUTES (elem_fefuncr),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fefuncr),
    STANDARD_HTML54_ATTRIBUTES (elem_fefuncr),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fegaussianblur, a_stddeviation },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 | HE_SVG_2_0 }, { HTML_UNDEF }, elem_fegaussianblur, a_std_deviation },
    SVG10_FILTER_ATTRIBUTES (elem_fegaussianblur),
    SVG11_FILTER_ATTRIBUTES (elem_fegaussianblur),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fegaussianblur),
    SVGx_PRES_ATTRIBUTES (elem_fegaussianblur),
    STANDARD_HTML54_ATTRIBUTES (elem_fegaussianblur),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_feimage, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_feimage, a_nodeid },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_feimage, a_preserveaspectratio },
    SVG10_REPL_ATTRIBUTES (elem_feimage),
    SVG11_FILTER_ATTRIBUTES (elem_feimage),
    SVG11_XLINK_ATTRIBUTES (elem_feimage),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_feimage),
    SVGx_PRES_ATTRIBUTES (elem_feimage),
    STANDARD_HTML54_ATTRIBUTES (elem_feimage),

    SVG10_FILTER_ATTRIBUTES (elem_femerge),
    SVG11_FILTER_ATTRIBUTES (elem_femerge),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_femerge),
    SVGx_PRES_ATTRIBUTES (elem_femerge),
    STANDARD_HTML54_ATTRIBUTES (elem_femerge),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_femergenode, a_in },
    SVGx_XTRA_CORE_ATTRIBUTES (elem_femergenode),
    STANDARD_HTML54_ATTRIBUTES (elem_femergenode),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_femorphology, a_operator },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_femorphology, a_radius },
    SVG10_FILTER_ATTRIBUTES (elem_femorphology),
    SVG11_FILTER_ATTRIBUTES (elem_femorphology),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_femorphology),
    SVGx_PRES_ATTRIBUTES (elem_femorphology),
    STANDARD_HTML54_ATTRIBUTES (elem_femorphology),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_feoffset, a_in },
    SVG10_DXY_ATTRIBUTES (elem_feoffset),
    SVG10_FILTER_ATTRIBUTES (elem_feoffset),
    SVG11_FILTER_ATTRIBUTES (elem_feoffset),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_feoffset),
    SVGx_PRES_ATTRIBUTES (elem_feoffset),
    STANDARD_HTML54_ATTRIBUTES (elem_feoffset),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fepointlight, a_x },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fepointlight, a_y },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fepointlight, a_z },
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fepointlight),
    STANDARD_HTML54_ATTRIBUTES (elem_fepointlight),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fespecularlighting, a_kernelunitlength },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fespecularlighting, a_lightcolour },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fespecularlighting, a_specularconstant },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fespecularlighting, a_specularexponent },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fespecularlighting, a_surfacescale },
    SVG10_FILTER_ATTRIBUTES (elem_fespecularlighting),
    SVG11_FILTER_ATTRIBUTES (elem_fespecularlighting),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fespecularlighting),
    SVGx_PRES_ATTRIBUTES (elem_fespecularlighting),
    STANDARD_HTML54_ATTRIBUTES (elem_fespecularlighting),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fespotlight, a_x },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fespotlight, a_y },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fespotlight, a_z },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_ellipse, a_limitingconeangle },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fespotlight, a_pointsatx },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fespotlight, a_pointsaty },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fespotlight, a_pointsatz },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_fespotlight, a_specularexponent },
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fespotlight),
    STANDARD_HTML54_ATTRIBUTES (elem_fespotlight),

    SVG10_FILTER_ATTRIBUTES (elem_fetile),
    SVG11_FILTER_ATTRIBUTES (elem_fetile),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fetile),
    SVGx_PRES_ATTRIBUTES (elem_fetile),
    STANDARD_HTML54_ATTRIBUTES (elem_fetile),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_feturbulence, a_basefrequency },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_feturbulence, a_numoctaves },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_feturbulence, a_seed },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_feturbulence, a_stitchtiles },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_feturbulence, a_type },
    SVG10_FILTER_ATTRIBUTES (elem_feturbulence),
    SVG11_FILTER_ATTRIBUTES (elem_feturbulence),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_feturbulence),
    SVGx_PRES_ATTRIBUTES (elem_feturbulence),
    STANDARD_HTML54_ATTRIBUTES (elem_feturbulence),

    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_fieldset, a_disabled },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_fieldset, a_form },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_fieldset, a_name },
    STANDARD_HTML_4_54_ATTRIBUTES (elem_fieldset),

    { { HTML_PLUS, HV_NOT2 }, { MAJOR_3_0, MINOR_3_0 }, elem_fig, a_align },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_fig, a_clear },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_fig, a_height },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_fig, a_imagemap },
    { { HTML_PLUS }, { HTML_PLUS }, elem_fig, a_ismap },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_fig, a_md },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_fig, a_noflow },
    { { HTML_PLUS }, { HTML_PLUS }, elem_fig, a_src },
    { { MAJOR_3_0, MINOR_3_0, REQUIRED }, { MAJOR_3_0, MINOR_3_0 }, elem_fig, a_src },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_fig, a_units },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_fig, a_width },
    HTMLPLUS_ATTRIBUTES (elem_fig),
    HTML3_CLID_ATTRIBUTES (elem_fig),

    STANDARD_HTML54_ATTRIBUTES (elem_figcaption),

    STANDARD_HTML54_ATTRIBUTES (elem_figure),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_ellipse, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_filter, a_filterres },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_filter, a_filter_units },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1x2 }, { HTML_UNDEF }, elem_filter, a_filterunits },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_filter, a_primitiveunits },
    SVG10_BOX_ATTRIBUTES (elem_filter),
    SVG11_XLINK_ATTRIBUTES (elem_filter),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_filter),
    SVGx_PRES_ATTRIBUTES (elem_filter),
    STANDARD_HTML54_ATTRIBUTES (elem_filter),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_fn, a_definition },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_fn, a_other },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_fn, a_style },
    HTML23_CLID_ATTRIBUTES (elem_fn),

    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_font, a_colour },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_font, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_font, a_face },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_font, a_horizadvx },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_font, a_horizoriginx },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_font, a_horizoriginy },
    { { HTML_3_2, HV_DEPRECATED4}, { XHTML_2_0 }, elem_font, a_size },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_font, a_vertadvy },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_font, a_vertoriginx },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_font, a_vertoriginy },
    SVGx_XTRA_CORE_ATTRIBUTES (elem_font),
    SVGx_PRES_ATTRIBUTES (elem_font),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_font),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_accentheight },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_alphabetic },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_ascent },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_accentheight },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_ascent },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_bbox },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_capheight },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_descent },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_font_family },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_font_size },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_font_stretch },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_font_style, },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_font_variant },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_font_weight },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_hanging },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_ideographic },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_mathematical },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_overlineposition },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_overlinethickness },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_panose1 },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_slope },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_stemh },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_stemv },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_strikethroughposition },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_strikethroughthickness },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_underlineposition },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_underlinethickness },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_unicoderange },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_unitsperem },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_valphabetic },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_vhanging },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_videographic },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_vmathematical },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_widths },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontface, a_xheight },
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fontface),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_fontface),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontfaceformat, a_string },
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fontfaceformat),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_fontfaceformat),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_fontfacename, a_name },
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fontfacename),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_fontfacename),

    SVGx_XTRA_CORE_ATTRIBUTES (elem_fontfacesrc),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_fontfacesrc),

    SVG11_XLINK_ATTRIBUTES (elem_fontfaceuri),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_fontfaceuri),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_fontfaceuri),

    STANDARD_HTML54_ATTRIBUTES (elem_footer),

    HTMLPLUS_ATTRIBUTES (elem_footnote),

    MATH1_DEFS_ATTRIBUTES (elem_forall, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_foreignobject, a_externalresourcesrequired },
    SVG10_BOX_ATTRIBUTES (elem_foreignobject),
    SVG10_G_ATTRIBUTES (elem_foreignobject),
    SVGx_CONDPROC_ATTRIBUTES (elem_foreignobject),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_foreignobject),
    SVGx_PRES_ATTRIBUTES (elem_foreignobject),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_foreignobject),

    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_form, a_acceptcharset },
    { { HTML_PLUS }, { HTML_2_0 }, elem_form, a_action },
    { { MAJOR_3_0, MINOR_3_0, REQUIRED }, { HTML_UNDEF }, elem_form, a_action },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_SAFARI }, { HTML_UNDEF }, elem_form, a_autocapitalise },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_form, a_autocomplete },
    { { HTML_2_0 }, { HTML_UNDEF }, elem_form, a_enctype },
    { { HTML_PLUS }, { HTML_UNDEF }, elem_form, a_method },
    { { HTML_4_01 }, { HTML_UNDEF }, elem_form, a_name },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_form, a_novalidate },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_form, a_onreset },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_form, a_onsubmit },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_form, a_rel },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_form, a_script },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_form, a_target },
    HTMLPLUS_ATTRIBUTES (elem_form),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_form),

    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_frame, a_frameborder },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_frame, a_longdesc },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_frame, a_marginheight },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_frame, a_marginwidth },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_frame, a_name },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_frame, a_noresize },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_frame, a_scrolling },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_frame, a_src },
    HTML4_STANDARD_CIST_ATTRIBUTES (elem_frame, MAJOR_4_0, MINOR_4_0),

    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_frameset, a_cols },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_frameset, a_onload },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_frameset, a_onunload },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_frameset, a_rows },
    HTML4_STANDARD_CIST_ATTRIBUTES (elem_frameset, MAJOR_4_0, MINOR_4_0),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_g, a_allow_zoom_pan },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_g, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_g, a_onzoom },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_g, a_transform },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_g, a_version },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_g, a_xmlns },
    SVG10_BOX_ATTRIBUTES (elem_g),
    SVG10_FIT_ATTRIBUTES (elem_g),
    SVG10_G_ATTRIBUTES (elem_g),
    SVG11_GREV_ATTRIBUTES (elem_g),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_g),
    SVGx_CONDPROC_ATTRIBUTES (elem_g),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_g),
    SVGx_PRES_ATTRIBUTES (elem_g),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_g),

    MATH1_DEFS_ATTRIBUTES (elem_gcd, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_geq, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_glyph, a_arabicform },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_glyph, a_d },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_glyph, a_glyphname },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_glyph, a_horizadvx },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_glyph, a_orientation },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_glyph, a_unicode },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_glyph, a_vertadvy },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_glyph, a_vertoriginx },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_glyph, a_vertoriginy },
    SVGx_XTRA_CORE_ATTRIBUTES (elem_glyph),
    SVGx_PRES_ATTRIBUTES (elem_glyph),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_glyph),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_glyphref, a_glyphref },
    SVG10_XY_ATTRIBUTES(elem_glyphref),
    SVG10_DXY_ATTRIBUTES(elem_glyphref),
    SVG11_XLINK_ATTRIBUTES(elem_glyphref),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_glyphref),
    SVGx_PRES_ATTRIBUTES (elem_glyphref),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_glyphref),

    MATH1_DEFS_ATTRIBUTES (elem_gt, MAJOR_X1_0, MINOR_X1_0),

    XHTML2_ATTRIBUTES (elem_h),
    STANDARD_H_ATTRIBUTES (elem_h1),
    STANDARD_H_ATTRIBUTES (elem_h2),
    STANDARD_H_ATTRIBUTES (elem_h3),
    STANDARD_H_ATTRIBUTES (elem_h4),
    STANDARD_H_ATTRIBUTES (elem_h5),
    STANDARD_H_ATTRIBUTES (elem_h6),

    HTML3_CLID_ATTRIBUTES (elem_hat),

    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_head, a_profile },
    HTML2_CLID_ATTRIBUTES (elem_head),
    HTML4_STANDARD_LANG_ATTRIBUTES (elem_head, MAJOR_4_0, MINOR_4_0),
    HTML4_STANDARD_SCRIPT_ATTRIBUTES (elem_head, MAJOR_5_0, MINOR_5_0),
    NEW_HTML54_ATTRIBUTES (elem_head),

    STANDARD_HTML54_ATTRIBUTES (elem_header),

    STANDARD_HTML54_ATTRIBUTES (elem_hgroup),

    STANDARD_HTML_4_54_ATTRIBUTES (elem_handler),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_hkern, a_g1 },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_hkern, a_g2 },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_hkern, a_k },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_hkern, a_u1 },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_hkern, a_u1 },
    SVGx_XTRA_CORE_ATTRIBUTES (elem_hkern),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_hkern),

    { { HTML_2_0, HV_DEPRECATED4 | HV_RFC_2070 | HV_NOT30 }, { XHTML_2_0 }, elem_hr, a_align },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_hr, a_clear },
    { { HTML_2_0, 0, HE_BESPOKE }, { XHTML_2_0 }, elem_hr, a_colour },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_hr, a_md },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_hr, a_noshade },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_hr, a_size },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_hr, a_width },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_hr, a_src },
    HTMLPLUS_ATTRIBUTES (elem_hr),
    HTML3_CLID_ATTRIBUTES (elem_hr),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_hr),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_html, a_class },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_html, a_dir },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_html, a_lang },
    { { MAJOR_5_0, MINOR_5_0, HV_DEPRECATED51x }, { HTML_5_1 }, elem_html, a_manifest },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_html, a_manifest },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_html, a_role },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_html, a_urn },
    { { MAJOR_3_0, MINOR_3_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_html, a_version },
    { { XHTML_2_0 }, { XHTML_2_0 }, elem_html, a_xsischemaloc },
    HTML2_CLID_ATTRIBUTES (elem_html),
    XHTML1_STANDARD_ATTRIBUTES (elem_html, MAJOR_X1_0, MINOR_X1_0),
    NEW_HTML54_ATTRIBUTES (elem_html),

    { { HTML_PLUS }, { HTML_PLUS }, elem_htmlplus, a_forms },
    { { HTML_PLUS }, { HTML_PLUS }, elem_htmlplus, a_version },

    HTMLPLUS_ATTRIBUTES (elem_i),
    HTML23_CLID_ATTRIBUTES (elem_i),
    STANDARD_HTML54_ATTRIBUTES (elem_i),

    MATH1_DEFS_ATTRIBUTES (elem_ident, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_iframe, a_align },
    { { HTML_JUL20, 0, HE_EXPERIMENTAL }, { HTML_UNDEF }, elem_iframe, a_allow },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_iframe, a_allowfullscreen },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_iframe, a_allowpaymentrequest },
    { { HTML_5_3 }, { HTML_5_3 }, elem_iframe, a_allowusermedia },
    { { HTML_JUL20, 0, HE_EXPERIMENTAL }, { HTML_UNDEF }, elem_iframe, a_csp },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_iframe, a_frameborder },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_iframe, a_height },
    { { HTML_JUL20, 0, HE_EXPERIMENTAL }, { HTML_UNDEF }, elem_iframe, a_importance },
    { { HTML_JUL20, 0, HE_EXPERIMENTAL }, { HTML_UNDEF }, elem_iframe, a_loading },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_iframe, a_longdesc },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_iframe, a_marginheight },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_iframe, a_marginwidth },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_MOZILLA }, { HTML_UNDEF }, elem_iframe, a_mozbrowser },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_iframe, a_name },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_iframe, a_noresize },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_iframe, a_referrerpolicy },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_iframe, a_sandbox },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_iframe, a_scrolling },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_iframe, a_src },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_iframe, a_srcdoc },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_iframe, a_width },
    STANDARD_HTML_4_54_ATTRIBUTES (elem_iframe),

    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_above },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_background },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_below },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_bgcolour },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_class },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_clip },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_height },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_id },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_left },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_name },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_pagex },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_pagey },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_src },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_style },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_top },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_visibility },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_ilayer, a_zindex },

    { { HTML_PLUS }, { HTML_PLUS }, elem_image, a_align },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_image, a_externalresourcesrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_image, a_preserveaspectratio },
    { { HTML_PLUS, REQUIRED }, { HTML_PLUS }, elem_image, a_src },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_image, a_xlinkhref },
    HTMLPLUS_ATTRIBUTES (elem_image),
    SVG10_BOX_ATTRIBUTES (elem_image),
    SVG10_G_ATTRIBUTES (elem_image),
    SVG10_REPL_ATTRIBUTES (elem_image),
    SVG11_GREV_ATTRIBUTES (elem_image),
    SVGx_CONDPROC_ATTRIBUTES (elem_image),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_image),
    SVGx_PRES_ATTRIBUTES (elem_image),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_image),

    { { HTML_1_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_img, a_align },
    { { HTML_1_0 }, { XHTML_2_0 }, elem_img, a_alt },
    { { MAJOR_5_0, MINOR_5_0, REQUIRED }, { HTML_UNDEF }, elem_img, a_alt },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_img, a_border },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_img, a_crossorigin },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_img, a_decoding },
    { { MAJOR_3_0, MINOR_3_0 }, { HTML_UNDEF }, elem_img, a_height },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_img, a_hspace },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_EXPERIMENTAL }, { HTML_UNDEF }, elem_img, a_importance },
    { { HTML_4_01, 0, HE_CHROME }, { HTML_UNDEF }, elem_img, a_intrinsicsize },
    { { HTML_PLUS }, { HTML_UNDEF }, elem_img, a_ismap },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_img, a_loading },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_img, a_longdesc },
    { { HTML_5_2, HV_W3 }, { HTML_5_3 }, elem_img, a_longdesc },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_img, a_md },
    { { HTML_4_01 }, { XHTML_2_0 }, elem_img, a_name },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_img, a_referrerpolicy },
    { { HTML_PLUS }, { HTML_PLUS }, elem_img, a_seethru },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_img, a_sizes },
    { { HTML_1_0, REQUIRED }, { HTML_UNDEF }, elem_img, a_src },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_img, a_srcset },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_img, a_units },
    { { HTML_2_0, HV_RFC_1980 | HV_NOT30 }, { HTML_UNDEF }, elem_img, a_usemap },
    { { HTML_2_0, HV_RFC_1942 }, { HTML_2_0 }, elem_img, a_valign },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_img, a_vspace },
    { { MAJOR_3_0, MINOR_3_0 }, { HTML_UNDEF }, elem_img, a_width },
    HTMLPLUS_ATTRIBUTES (elem_img),
    HTML23_CLID_ATTRIBUTES (elem_img),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_img),

    MATH1_DEFS_ATTRIBUTES (elem_implies, MAJOR_X1_0, MINOR_X1_0),

    { { HTML_2_0, HV_RFC_1867 | HV_NOT32 }, { HTML_UNDEF }, elem_input, a_accept },
    { { HTML_PLUS, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_input, a_align },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_input, a_alt },
    { { HTML_5_3 }, { HTML_5_3 }, elem_input, a_autocapitalise },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_input, a_autocomplete },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_SAFARI }, { HTML_UNDEF }, elem_input, a_autocorrect },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_5_3 }, elem_input, a_autofocus },
    { { HTML_5_3 }, { HTML_5_3 }, elem_input, a_capture },
    { { HTML_PLUS }, { HTML_UNDEF }, elem_input, a_checked },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_input, a_datafld },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_input, a_dataformatas },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_input, a_datasrc },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_input, a_dirname },
    { { HTML_PLUS, HV_NOT2 | HV_NOT32 }, { HTML_UNDEF }, elem_input, a_disabled },
    { { HTML_PLUS, HV_NOT2 }, { MAJOR_3_0, MINOR_3_0 }, elem_input, a_error },
    HTML50_FORM (elem_input),
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_input, a_height },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_SAFARI | HE_OPERA | HE_CHROME }, { HTML_UNDEF }, elem_input, a_incremental },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_5_1 }, elem_input, a_inputmode },
    { { HTML_4_01 }, { XHTML_2_0 }, elem_input, a_ismap },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_input, a_list },
    { { HTML_PLUS, HV_NOT4 | HV_NOT32 }, { HTML_UNDEF }, elem_input, a_max },
    { { HTML_PLUS }, { HTML_UNDEF }, elem_input, a_maxlength },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_input, a_md },
    { { HTML_PLUS, HV_NOT4 | HV_NOT32 }, { HTML_UNDEF }, elem_input, a_min },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_input, a_minlength },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_MOZILLA }, { HTML_UNDEF }, elem_input, a_mozactionhint },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_input, a_multiple },
    { { HTML_TAGS }, { HTML_UNDEF }, elem_input, a_name },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_input, a_onblur },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_input, a_onchange },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_input, a_onfocus },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_input, a_onselect },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_MOZILLA }, { HTML_UNDEF }, elem_input, a_orient },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_input, a_pattern },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_input, a_placeholder },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_input, a_readonly },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_input, a_required },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_SAFARI }, { HTML_UNDEF }, elem_input, a_results },
    { { HTML_PLUS }, { HTML_UNDEF }, elem_input, a_size },
    { { HTML_PLUS }, { HTML_UNDEF }, elem_input, a_src },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_input, a_step },
    { { HTML_PLUS }, { HTML_UNDEF }, elem_input, a_type },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_input, a_usemap },
    { { HTML_PLUS }, { HTML_UNDEF }, elem_input, a_value },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_BESPOKE }, { HTML_UNDEF }, elem_input, a_webkitdirectory },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_input, a_width },
    HTMLPLUS_ATTRIBUTES (elem_input),
    HTML23_CLID_ATTRIBUTES (elem_input),
    HTML4_FORM_ATTRIBUTES (elem_input),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_input),

    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_ins, a_cite },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_ins, a_class },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_ins, a_datetime },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_ins, a_id },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_ins, a_lang },
    HTML3_CLID_ATTRIBUTES (elem_ins),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_ins),

    MATH1_DEFS_ATTRIBUTES (elem_int, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_intersect, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_interval, a_closure },
    MATH1_STANDARD_ATTRIBUTES (elem_interval, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_inverse, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_isindex, a_class },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_isindex, a_dir },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_isindex, a_href },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_isindex, a_id },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_isindex, a_lang },
    { { MAJOR_3_0, MINOR_3_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_isindex, a_prompt },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_isindex, a_style },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_isindex, a_title },
    HTML2_CLID_ATTRIBUTES (elem_isindex),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_item, a_align },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_item, a_colspan },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_item, a_rowspan },

    HTMLPLUS_ATTRIBUTES (elem_kbd),
    HTML23_CLID_ATTRIBUTES (elem_kbd),
    STANDARD_HTML54_ATTRIBUTES (elem_kbd),

    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_keygen, a_autofocus },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_keygen, a_challenge },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_keygen, a_disabled },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_keygen, a_form },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_keygen, a_keytype },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_keygen, a_name },
    STANDARD_HTML51_ATTRIBUTES (elem_keygen),

    { { HTML_PLUS }, { HTML_PLUS }, elem_l, a_align },
    HTMLPLUS_ATTRIBUTES (elem_l),
    XHTML2_ATTRIBUTES (elem_l),

    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_label, a_for },
    { { MAJOR_5_0, MINOR_5_0 }, { MAJOR_5_0, MINOR_5_0 }, elem_label, a_form },
    HTML3_CLID_ATTRIBUTES (elem_label),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_label),

    MATH1_STANDARD_ATTRIBUTES (elem_lambda, MAJOR_X1_0, MINOR_X1_0),

    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_above },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_background },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_below },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_bgcolour },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_class },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_clip },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_height },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_id },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_left },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_name },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_pagex },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_pagey },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_src },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_style },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_top },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_visibility },
    { { HTML_2_0, 0, HE_NETSCAPE }, { HTML_3_2 }, elem_layer, a_zindex },

    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_legend, a_align },
    STANDARD_HTML_4_54_ATTRIBUTES (elem_legend),

    MATH1_DEFS_ATTRIBUTES (elem_leq, MAJOR_X1_0, MINOR_X1_0),

    HTML3_CLID_ATTRIBUTES (elem_lh),

    { { HTML_2_0, HV_RFC_2070 }, { HTML_2_0 }, elem_li, a_align },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_li, a_clear },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_li, a_dingbat },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_li, a_md },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_li, a_skip },
    { { HTML_PLUS, HV_NOT2 }, { MAJOR_3_0, MINOR_3_0 }, elem_li, a_src },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_li, a_type },
    { { HTML_3_2, HV_DEPRECATED4 }, { HTML_UNDEF }, elem_li, a_value },
    HTMLPLUS_ATTRIBUTES (elem_li),
    HTML23_CLID_ATTRIBUTES (elem_li),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_li),

    MATH1_DEFS_ATTRIBUTES (elem_limit, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_line, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_line, a_x1 },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_line, a_x2 },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_line, a_y1 },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_line, a_y2 },
    SVG10_G_ATTRIBUTES (elem_line),
    SVG11_GREV_ATTRIBUTES (elem_line),
    SVGx_CONDPROC_ATTRIBUTES (elem_line),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_line),
    SVGx_PRES_ATTRIBUTES (elem_line),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_line),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_lineargradient, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_lineargradient, a_spreadmethod },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_lineargradient, a_x1 },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_lineargradient, a_x2 },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_lineargradient, a_y1 },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_lineargradient, a_y2 },
    SVG10_GRAD_ATTRIBUTES (elem_lineargradient),
    SVG11_XLINK_ATTRIBUTES (elem_lineargradient),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_lineargradient),
    SVGx_PRES_ATTRIBUTES (elem_lineargradient),
    STANDARD_HTML54_ATTRIBUTES (elem_lineargradient),

    { { HTML_5_3 }, { HTML_UNDEF }, elem_link, a_as },
    { { HTML_2_0, HV_RFC_2070 | HV_NOT3 }, { XHTML_2_0 }, elem_link, a_charset },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_link, a_colour },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_link, a_crossorigin },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_MOZILLA }, { HTML_5_3 }, elem_link, a_disabled },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_link, a_disabled },
    { { HTML_PLUS, REQUIRED }, { HTML_UNDEF }, elem_link, a_href },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_link, a_hreflang },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_link, a_imagesizes },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_link, a_imagesrcset },
    { { HTML_JUL20, 0, HE_EXPERIMENTAL }, { HTML_UNDEF }, elem_link, a_importance },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_link, a_integrity },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_link, a_media },
    { { HTML_PLUS }, { MAJOR_3_0, MINOR_3_0 }, elem_link, a_methods },
    { { HTML_2_0 }, { HTML_2_0 }, elem_link, a_name },
    { { HTML_5_2 }, { HTML_5_2 }, elem_link, a_numberonce },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_link, a_ping },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_MOZILLA }, { HTML_UNDEF }, elem_link, a_prefetch },
    { { HTML_PLUS }, { XHTML_2_0 }, elem_link, a_rel },
    { { MAJOR_5_0, MINOR_5_0, REQUIRED }, { HTML_5_3 }, elem_link, a_rel },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_link, a_rel },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_link, a_referrerpolicy },
    { { HTML_PLUS, HV_NOT50 }, { HTML_5_3 }, elem_link, a_rev },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_link, a_sizes },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_link, a_target },
    { { HTML_2_0 }, { HTML_3_2 }, elem_link, a_title },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_link, a_type },
    { { HTML_2_0 }, { HTML_2_0 }, elem_link, a_urn },
    HTML23_CLID_ATTRIBUTES (elem_link),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_link),

    XHTML2_ATTRIBUTES (elem_listener),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_listener),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_list, a_order },
    MATH1_STANDARD_ATTRIBUTES (elem_list, MAJOR_X1_0, MINOR_X1_0),

    HTML23_CLID_ATTRIBUTES (elem_listing),

    HTMLPLUS_ATTRIBUTES (elem_lit),

    MATH1_DEFS_ATTRIBUTES (elem_ln, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_log, MAJOR_X1_0, MINOR_X1_0),

    MATH1_STANDARD_ATTRIBUTES (elem_logbase, MAJOR_X1_0, MINOR_X1_0),

    MATH1_STANDARD_ATTRIBUTES (elem_lowlimit, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_lt, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_maction, a_actiontype },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_maction, a_selection },
    MATH1_STANDARD_ATTRIBUTES (elem_maction, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_maligngroup, a_groupalign },
    MATH1_STANDARD_ATTRIBUTES (elem_maligngroup, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_malignmark, a_edge },
    MATH1_STANDARD_ATTRIBUTES (elem_malignmark, MAJOR_X1_0, MINOR_X1_0),

    STANDARD_HTML54_ATTRIBUTES (elem_main),

    { { HTML_2_0, REQUIRED }, { HTML_4_01 }, elem_map, a_name },
    { { MAJOR_X1_0, MINOR_X1_0, HV_DEPRECATEDX1 }, { XHTML_2_0 }, elem_map, a_name },
    { { MAJOR_5_0, MINOR_5_0, REQUIRED }, { HTML_UNDEF }, elem_map, a_name },
    STANDARD_HTML54_ATTRIBUTES (elem_map),

    HTMLPLUS_ATTRIBUTES (elem_margin),

    STANDARD_HTML54_ATTRIBUTES (elem_mark),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_line, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_marker, a_orient },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_marker, a_markerheight },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_marker, a_markerunits },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_marker, a_markerwidth },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_marker, a_preserveaspectratio },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_marker, a_viewbox },
    SVG10_BOX_ATTRIBUTES (elem_marker),
    SVG10_FIT_ATTRIBUTES (elem_marker),
    SVG10_REF_XY_ATTRIBUTES (elem_marker),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_marker),
    SVGx_PRES_ATTRIBUTES (elem_marker),
    STANDARD_HTML54_ATTRIBUTES (elem_marker),

    { { HTML_UNDEF }, { HTML_UNDEF }, elem_marquee, a_behaviour },
    { { HTML_UNDEF }, { HTML_UNDEF }, elem_marquee, a_bgcolour },
    { { HTML_UNDEF }, { HTML_UNDEF }, elem_marquee, a_direction },
    { { HTML_UNDEF }, { HTML_UNDEF }, elem_marquee, a_height },
    { { HTML_UNDEF }, { HTML_UNDEF }, elem_marquee, a_hspace },
    { { HTML_UNDEF }, { HTML_UNDEF }, elem_marquee, a_loop },
    { { HTML_UNDEF }, { HTML_UNDEF }, elem_marquee, a_scrollamount },
    { { HTML_UNDEF }, { HTML_UNDEF }, elem_marquee, a_scrolldelay },
    { { HTML_UNDEF }, { HTML_UNDEF }, elem_marquee, a_truespeed },
    { { HTML_UNDEF }, { HTML_UNDEF }, elem_marquee, a_vspace },
    { { HTML_UNDEF }, { HTML_UNDEF }, elem_marquee, a_width },

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_mask, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_mask, a_maskcontentunits },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_mask, a_mask_units },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_1 | HE_SVG_2_0 }, { HTML_UNDEF }, elem_mask, a_maskunits },
    SVG10_BOX_ATTRIBUTES (elem_mask),
    SVGx_CONDPROC_ATTRIBUTES (elem_mask),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_mask),
    SVGx_PRES_ATTRIBUTES (elem_mask),
    STANDARD_HTML54_ATTRIBUTES (elem_mask),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_math, a_altimg },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_math, a_alttext },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_math, a_baseline },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_math, a_definition },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_math, a_height },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_math, a_macros },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_math, a_mode },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_math, a_other },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_math, a_overflow },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_math, a_style },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_math, a_type },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_math, a_width },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_math, a_xmlns },
    HTML3_CLID_ATTRIBUTES (elem_math),

    MATH1_STANDARD_ATTRIBUTES (elem_matrix, MAJOR_X1_0, MINOR_X1_0),

    MATH1_STANDARD_ATTRIBUTES (elem_matrixrow, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_max, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_mean, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_median, MAJOR_X1_0, MINOR_X1_0),

    MATH1_STANDARD_ATTRIBUTES (elem_merror, MAJOR_X1_0, MINOR_X1_0),

    { { HTML_2_0, HV_RFC_2070 }, { HTML_2_0 }, elem_menu, a_align },
    { { HTML_3_2 }, { HTML_3_2 }, elem_menu, a_clear },
    { { HTML_2_0 }, { XHTML_2_0 }, elem_menu, a_compact },
    { { HTML_3_2, 0, HE_BESPOKE }, { HTML_3_2 }, elem_menu, a_label },
    { { HTML_5_1 }, { HTML_5_1 }, elem_menu, a_label },
    { { HTML_3_2, 0, HE_BESPOKE }, { HTML_3_2 }, elem_menu, a_type },
    { { HTML_5_1 }, { HTML_5_1 }, elem_menu, a_type },
    HTMLPLUS_ATTRIBUTES (elem_menu),
    HTML2_CLID_ATTRIBUTES (elem_menu),
    STANDARD_HTML_4_51_ATTRIBUTES (elem_menu),

    { { HTML_5_1 }, { HTML_5_1 }, elem_menuitem, a_checked },
    { { HTML_5_1 }, { HTML_5_1 }, elem_menuitem, a_default },
    { { HTML_5_1 }, { HTML_5_1 }, elem_menuitem, a_disabled },
    { { HTML_5_1 }, { HTML_5_1 }, elem_menuitem, a_icon },
    { { HTML_5_1 }, { HTML_5_1 }, elem_menuitem, a_label },
    { { HTML_5_1 }, { HTML_5_1 }, elem_menuitem, a_radiogroup },
    { { HTML_5_1 }, { HTML_5_1 }, elem_menuitem, a_type },
    STANDARD_HTML51_ATTRIBUTES (elem_menuitem),

    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_meta, a_charset },
    { { HTML_2_0, REQUIRED }, { XHTML_1_1 }, elem_meta, a_content },
    { { XHTML_2_0 }, { HTML_UNDEF }, elem_meta, a_content },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_meta, a_dir },
    { { HTML_2_0 }, { HTML_UNDEF }, elem_meta, a_httpequiv },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_meta, a_lang },
    { { HTML_2_0 }, { HTML_UNDEF }, elem_meta, a_name },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_meta, a_scheme },
//    HTML4_STANDARD_CIST_ATTRIBUTES (elem_meta, MAJOR_5_0, MINOR_5_0),
//    HTML4_STANDARD_SCRIPT_ATTRIBUTES (elem_meta, MAJOR_5_0, MINOR_5_0),
//    XHTML2_ATTRIBUTES (elem_meta),
//    NEW_HTML50_ATTRIBUTES (elem_meta),
    HTML23_CLID_ATTRIBUTES (elem_meta),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_meta),

    SVGx_XTRA_CORE_ATTRIBUTES (elem_metadata),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_metadata),

    { { MAJOR_5_0, MINOR_5_0, 0, HE_BESPOKE }, { HTML_UNDEF }, elem_meter, a_form },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_meter, a_high },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_meter, a_low },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_meter, a_max },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_meter, a_min },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_meter, a_optimum },
    { { MAJOR_5_0, MINOR_5_0, REQUIRED }, { HTML_UNDEF }, elem_meter, a_value },
    STANDARD_HTML50_ATTRIBUTES (elem_meter),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mfenced, a_close },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mfenced, a_open },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mfenced, a_separators },
    MATH1_STANDARD_ATTRIBUTES (elem_mfenced, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mfrac, a_linethickness },
    MATH1_STANDARD_ATTRIBUTES (elem_mfrac, MAJOR_X1_0, MINOR_X1_0),

    { { HTML_PLUS }, { HTML_PLUS }, elem_mh, a_action },
    { { HTML_PLUS }, { HTML_PLUS }, elem_mh, a_hidden },
    { { HTML_PLUS }, { HTML_PLUS }, elem_mh, a_method },
    HTMLPLUS_ATTRIBUTES (elem_mh),

    MATH1_FONT_ATTRIBUTES (elem_mi, MAJOR_X1_0, MINOR_X1_0),
    MATH1_STANDARD_ATTRIBUTES (elem_mi, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_min, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_minus, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_missingglyph, a_d },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_missingglyph, a_horizadvx },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_missingglyph, a_vertadvy },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_missingglyph, a_vertoriginx },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_missingglyph, a_vertoriginy },
    SVGx_XTRA_CORE_ATTRIBUTES (elem_missingglyph),
    SVGx_PRES_ATTRIBUTES (elem_missingglyph),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_missingglyph),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mmultiscripts, a_subscriptshift },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mmultiscripts, a_superscriptshift },
    MATH1_STANDARD_ATTRIBUTES (elem_mmultiscripts, MAJOR_X1_0, MINOR_X1_0),

    MATH1_FONT_ATTRIBUTES (elem_mn, MAJOR_X1_0, MINOR_X1_0),
    MATH1_STANDARD_ATTRIBUTES (elem_mn, MAJOR_X1_0, MINOR_X1_0),

    MATH1_FONT_ATTRIBUTES (elem_mo, MAJOR_X1_0, MINOR_X1_0),
    MATH1_OPINFO_ATTRIBUTES (elem_mo, MAJOR_X1_0, MINOR_X1_0),
    MATH1_STANDARD_ATTRIBUTES (elem_mo, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_mode, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_moment, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mover, a_accent },
    MATH1_STANDARD_ATTRIBUTES (elem_mover, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mpadded, a_lspace },
    MATH1_SIZEINFO_ATTRIBUTES (elem_mpadded, MAJOR_X1_0, MINOR_X1_0),
    MATH1_STANDARD_ATTRIBUTES (elem_mpadded, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_mpath, a_externalresourcesrequired },
    SVG11_XLINK_ATTRIBUTES (elem_mpath),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_mpath),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_mpath),

    MATH1_STANDARD_ATTRIBUTES (elem_mphantom, MAJOR_X1_0, MINOR_X1_0),

    MATH1_STANDARD_ATTRIBUTES (elem_mprescripts, MAJOR_X1_0, MINOR_X1_0),

    MATH1_STANDARD_ATTRIBUTES (elem_mroot, MAJOR_X1_0, MINOR_X1_0),

    MATH1_STANDARD_ATTRIBUTES (elem_mrow, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_msub, a_subscriptshift },
    MATH1_STANDARD_ATTRIBUTES (elem_msub, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_msubsup, a_subscriptshift },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_msubsup, a_superscriptshift },
    MATH1_STANDARD_ATTRIBUTES (elem_msubsup, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_msup, a_superscriptshift },
    MATH1_STANDARD_ATTRIBUTES (elem_msup, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_accentunder },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_actiontype },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_background },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_close },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_columnspan },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_edge },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_linethickness },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_lquote },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_open },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_rowspan },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_rquote },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_selection },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_separators },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_scriptlevel },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_scriptsizemultiplier },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_scriptminsize },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_subscriptshift },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mstyle, a_superscriptshift },
    MATH1_FONT_ATTRIBUTES (elem_mstyle, MAJOR_X1_0, MINOR_X1_0),
    MATH1_OPINFO_ATTRIBUTES (elem_mstyle, MAJOR_X1_0, MINOR_X1_0),
    MATH1_TABLE_ATTRIBUTES (elem_mstyle, MAJOR_X1_0, MINOR_X1_0),
    MATH1_STANDARD_ATTRIBUTES (elem_mstyle, MAJOR_X1_0, MINOR_X1_0),

    MATH1_TABLE_ATTRIBUTES (elem_mtable, MAJOR_X1_0, MINOR_X1_0),
    MATH1_STANDARD_ATTRIBUTES (elem_mtable, MAJOR_X1_0, MINOR_X1_0),

    MATH1_FONT_ATTRIBUTES (elem_mtext, MAJOR_X1_0, MINOR_X1_0),
    MATH1_STANDARD_ATTRIBUTES (elem_mtext, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_ms, a_lquote },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_ms, a_rquote },
    MATH1_FONT_ATTRIBUTES (elem_ms, MAJOR_X1_0, MINOR_X1_0),
    MATH1_STANDARD_ATTRIBUTES (elem_ms, MAJOR_X1_0, MINOR_X1_0),

    MATH1_STANDARD_ATTRIBUTES (elem_mspace, MAJOR_X1_0, MINOR_X1_0),

    MATH1_STANDARD_ATTRIBUTES (elem_msqrt, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mtd, a_columnalign },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mtd, a_columnspan },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mtd, a_groupalign },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mtd, a_rowalign },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mtd, a_rowspan },
    MATH1_STANDARD_ATTRIBUTES (elem_mtd, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mtr, a_columnalign },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mtr, a_groupalign },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_mtr, a_rowalign },
    MATH1_STANDARD_ATTRIBUTES (elem_mtr, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_munder, a_accentunder },
    MATH1_STANDARD_ATTRIBUTES (elem_munder, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_munderover, a_accent },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_munderover, a_accentunder },
    MATH1_STANDARD_ATTRIBUTES (elem_munderover, MAJOR_X1_0, MINOR_X1_0),

    STANDARD_HTML54_ATTRIBUTES (elem_nav),

    MATH1_DEFS_ATTRIBUTES (elem_neq, MAJOR_X1_0, MINOR_X1_0),

    { { HTML_TAGS }, { HTML_1_0 }, elem_nextid, a_n },
    { { HTML_1_0, REQUIRED }, { MAJOR_3_0, MINOR_3_0 }, elem_nextid, a_n },

    XHTML2_ATTRIBUTES (elem_nl),

    COMMON_HTML4_ATTRIBUTES (elem_noframes),

    MATH1_STANDARD_ATTRIBUTES (elem_none, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_not, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_notin, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_notprsubset, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_notsubset, MAJOR_X1_0, MINOR_X1_0),

    STANDARD_HTML_4_54_ATTRIBUTES (elem_noscript),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_note, a_clear },
    { { HTML_PLUS, HV_NOT2 }, { HTML_PLUS }, elem_note, a_role },
    { { HTML_PLUS, HV_NOT2 }, { MAJOR_3_0, MINOR_3_0 }, elem_note, a_src },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_note, a_md },
    HTMLPLUS_ATTRIBUTES (elem_note),
    HTML3_CLID_ATTRIBUTES (elem_note),

    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_object, a_archive },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_object, a_align },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_object, a_border },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_object, a_classid },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_object, a_codebase },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_object, a_codetype },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_object, a_data },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_object, a_datafld },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_object, a_dataformatas },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_object, a_datasrc },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_object, a_declare },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_5_2 }, elem_object, a_form },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_object, a_form },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_object, a_height },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_object, a_hspace },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_object, a_name },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_object, a_standby },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_object, a_type },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_5_3 }, elem_object, a_typemustmatch },
    { { MAJOR_4_0, MINOR_4_0 }, { MAJOR_5_0, MINOR_5_0 }, elem_object, a_usemap },
    { { HTML_5_1, HV_WHATWG }, { HTML_UNDEF }, elem_object, a_usemap },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_object, a_vspace },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_object, a_width },
    HTML4_FORM_ATTRIBUTES (elem_object),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_object),

    { { HTML_2_0, HV_RFC_2070 }, { HTML_2_0 }, elem_ol, a_align },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_ol, a_clear },
    { { HTML_PLUS, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_ol, a_compact },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_ol, a_continue },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_ol, a_reversed },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_ol, a_seqnum },
    { { HTML_3_2, HV_DEPRECATED4 }, { HTML_UNDEF }, elem_ol, a_type },
    { { HTML_3_2, HV_DEPRECATED4 }, { HTML_UNDEF }, elem_ol, a_start },
    HTMLPLUS_ATTRIBUTES (elem_ol),
    HTML23_CLID_ATTRIBUTES (elem_ol),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_ol),

    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_optgroup, a_disabled },
    { { MAJOR_4_0, MINOR_4_0, REQUIRED }, { HTML_UNDEF }, elem_optgroup, a_label },
    STANDARD_HTML_4_54_ATTRIBUTES (elem_optgroup),

    { { HTML_PLUS, HV_NOT2 | HV_NOT32 }, { HTML_UNDEF }, elem_option, a_disabled },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_option, a_error },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_option, a_label },
    { { HTML_PLUS }, { HTML_UNDEF }, elem_option, a_selected },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_option, a_shape },
    { { HTML_2_0 }, { HTML_UNDEF }, elem_option, a_value },
    HTML23_CLID_ATTRIBUTES (elem_option),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_option),

    MATH1_DEFS_ATTRIBUTES (elem_or, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_output, a_for },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_output, a_form },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_output, a_name },
    STANDARD_HTML54_ATTRIBUTES (elem_output),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_overlay, a_height },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_overlay, a_imagemap },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_overlay, a_md },
    { { MAJOR_3_0, MINOR_3_0, REQUIRED }, { MAJOR_3_0, MINOR_3_0 }, elem_overlay, a_src },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_overlay, a_units },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_overlay, a_width },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_overlay, a_x },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_overlay, a_y },

    { { HTML_PLUS, HV_DEPRECATED4 | HV_RFC_2070 }, { XHTML_2_0 }, elem_p, a_align },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_p, a_clear },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_p, a_nowrap },
    HTMLPLUS_ATTRIBUTES (elem_p),
    HTML23_CLID_ATTRIBUTES (elem_p),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_p),

    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_param, a_id },
    { { HTML_3_2, REQUIRED }, { HTML_UNDEF }, elem_param, a_name },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_param, a_type },
    { { HTML_3_2 }, { XHTML_2_0 }, elem_param, a_value },
    { { MAJOR_5_0, MINOR_5_0, REQUIRED }, { HTML_UNDEF }, elem_param, a_value },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_param, a_valuetype },
    HTML4_ATTRIBUTES_BASE (elem_param, MAJOR_5_0, MINOR_5_0),
    NEW_HTML54_ATTRIBUTES (elem_param),

    MATH1_DEFS_ATTRIBUTES (elem_partialdiff, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_path, a_d },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_path, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_path, a_flatness },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_path, a_nominallength },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_path, a_pathlength },
    SVG10_G_ATTRIBUTES(elem_path),
    SVGx_CONDPROC_ATTRIBUTES (elem_path),
    SVG11_GREV_ATTRIBUTES (elem_path),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_path),
    SVGx_PRES_ATTRIBUTES (elem_path),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_path),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_pattern, a_externalresourcesrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_pattern, a_patterncontentunits },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_pattern, a_patterntransform },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_pattern, a_pattern_units },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_1 | HE_SVG_2_0 }, { HTML_UNDEF }, elem_pattern, a_patternunits },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_pattern, a_viewbox },
    SVG10_BOX_ATTRIBUTES (elem_pattern),
    SVG10_FIT_ATTRIBUTES (elem_pattern),
    SVG10_REF_XY_ATTRIBUTES (elem_pattern),
    SVGx_CONDPROC_ATTRIBUTES (elem_pattern),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_pattern),
    SVG11_XLINK_ATTRIBUTES (elem_pattern),
    SVGx_PRES_ATTRIBUTES (elem_pattern),
    STANDARD_HTML54_ATTRIBUTES (elem_pattern),

    HTMLPLUS_ATTRIBUTES (elem_person),
    HTML23_CLID_ATTRIBUTES (elem_person),

    STANDARD_HTML54_ATTRIBUTES (elem_picture),

    MATH1_DEFS_ATTRIBUTES (elem_plus, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_polygon, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 | REQUIRED }, { HTML_UNDEF }, elem_polygon, a_points },
    SVG10_G_ATTRIBUTES (elem_polygon),
    SVG11_GREV_ATTRIBUTES (elem_polygon),
    SVGx_CONDPROC_ATTRIBUTES (elem_polygon),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_polygon),
    SVGx_PRES_ATTRIBUTES (elem_polygon),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_polygon),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_polyline, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 | REQUIRED }, { HTML_UNDEF }, elem_polyline, a_points },
    SVG10_G_ATTRIBUTES (elem_polyline),
    SVG11_GREV_ATTRIBUTES (elem_polyline),
    SVGx_CONDPROC_ATTRIBUTES (elem_polyline),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_polyline),
    SVGx_PRES_ATTRIBUTES (elem_polyline),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_polyline),

    MATH1_DEFS_ATTRIBUTES (elem_power, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_pre, a_clear },
    { { HTML_2_0, HV_NOT30, HE_MOZILLA | HE_NETSCAPE }, { HTML_3_2 }, elem_pre, a_cols },
    { { HTML_1_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_pre, a_width },
    { { HTML_2_0, 0, HE_MOZILLA | HV_NOT30 }, { HTML_UNDEF }, elem_pre, a_wrap },
    HTMLPLUS_ATTRIBUTES (elem_pre),
    HTML23_CLID_ATTRIBUTES (elem_pre),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_pre),

    STANDARD_HTML_4_54_ATTRIBUTES (elem_prefetch),

    XHTML2_ATTRIBUTES (elem_preventdefault),

    MATH1_DEFS_ATTRIBUTES (elem_product, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_progress, a_max },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_progress, a_value },
    STANDARD_HTML54_ATTRIBUTES (elem_progress),

    MATH1_DEFS_ATTRIBUTES (elem_prsubset, MAJOR_X1_0, MINOR_X1_0),

    { { HTML_2_0, HV_RFC_2070 }, { HTML_2_0 }, elem_q, a_align },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_q, a_cite },
    HTMLPLUS_ATTRIBUTES (elem_q),
    HTML23_CLID_ATTRIBUTES (elem_q),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_q),

    HTMLPLUS_ATTRIBUTES (elem_quote),

    MATH1_DEFS_ATTRIBUTES (elem_quotient, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_radialgradient, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_radialgradient, a_cx },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_radialgradient, a_cy },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_radialgradient, a_fx },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_radialgradient, a_fy },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_radialgradient, a_r },
    SVG10_GRAD_ATTRIBUTES (elem_radialgradient),
    SVG11_XLINK_ATTRIBUTES (elem_radialgradient),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_radialgradient),
    SVGx_PRES_ATTRIBUTES (elem_radialgradient),
    STANDARD_HTML54_ATTRIBUTES (elem_radialgradient),

    { { MAJOR_3_0, MINOR_3_0, REQUIRED }, { MAJOR_3_0, MINOR_3_0 }, elem_range, a_from },
    { { MAJOR_3_0, MINOR_3_0, REQUIRED }, { MAJOR_3_0, MINOR_3_0 }, elem_range, a_until },
    HTML_CID_ATTRIBUTES (elem_range, MAJOR_3_0, MINOR_3_0, MAJOR_3_0, MINOR_3_0),

    STANDARD_HTML54_ATTRIBUTES (elem_rb),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_rect, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_rect, a_rx },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_rect, a_ry },
    SVG10_BOX_ATTRIBUTES (elem_rect),
    SVG10_G_ATTRIBUTES (elem_rect),
    SVG11_GREV_ATTRIBUTES (elem_rect),
    SVGx_CONDPROC_ATTRIBUTES (elem_rect),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_rect),
    SVGx_PRES_ATTRIBUTES (elem_rect),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_rect),

    MATH1_STANDARD_ATTRIBUTES (elem_reln, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_rem, MAJOR_X1_0, MINOR_X1_0),

    HTMLPLUS_ATTRIBUTES (elem_removed),

    XHTML2_ATTRIBUTES (elem_removeeventlistener),

    { { HTML_PLUS }, { HTML_PLUS }, elem_render, a_style },
    { { HTML_PLUS }, { HTML_PLUS }, elem_render, a_tag },
    HTMLPLUS_ATTRIBUTES (elem_render),

    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_root, a_other },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_root, a_style },
    { { MAJOR_X1_0, MINOR_X1_0 }, { HTML_UNDEF }, elem_root, a_definition },
    HTML3_CLID_ATTRIBUTES (elem_root),

    STANDARD_HTML54_ATTRIBUTES (elem_rp),

    STANDARD_HTML54_ATTRIBUTES (elem_rt),

    STANDARD_HTML54_ATTRIBUTES (elem_rtc),

    STANDARD_HTML54_ATTRIBUTES (elem_ruby),

    HTMLPLUS_ATTRIBUTES (elem_s),
    HTML3_CLID_ATTRIBUTES (elem_s),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_s),

    HTMLPLUS_ATTRIBUTES (elem_samp),
    HTML23_CLID_ATTRIBUTES (elem_samp),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_samp),

    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_script, a_async },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_5_2 }, elem_script, a_charset },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_script, a_crossorigin },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_script, a_defer },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_script, a_event },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_script, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, HV_NOTX2 }, { XHTML_2_0 }, elem_script, a_for },
    { { XHTML_2_0 }, { XHTML_2_0 }, elem_script, a_implements },
    { { HTML_5_3 }, { HTML_UNDEF }, elem_script, a_integrity },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_script, a_language },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_script, a_nomodule },
    { { HTML_5_1 }, { HTML_5_2 }, elem_script, a_numberonce },
    { { HTML_JUL20 }, { HTML_UNDEF }, elem_script, a_referrerpolicy },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_script, a_src },
    { { MAJOR_4_0, MINOR_4_0, REQUIRED }, {4, 4 }, elem_script, a_type },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_script, a_type },
    SVG10_REPL_ATTRIBUTES (elem_script),
    SVG11_XLINK_ATTRIBUTES (elem_script),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_script),
    STANDARD_HTML54_ATTRIBUTES (elem_script),

    MATH1_DEFS_ATTRIBUTES (elem_sdev, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_sec, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_sech, MAJOR_X1_0, MINOR_X1_0),

    STANDARD_HTML54_ATTRIBUTES (elem_section),

    MATH1_STANDARD_ATTRIBUTES (elem_set, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_select, a_align },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_select, a_autocomplete },
    { { MAJOR_5_0, MINOR_5_0, HV_W3 }, { HTML_5_3 }, elem_select, a_autofocus },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_select, a_datafld },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_select, a_dataformatas },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_select, a_datasrc },
    { { MAJOR_3_0, MINOR_3_0, HV_NOT32 | HV_NOT4 }, { HTML_UNDEF }, elem_select, a_disabled },
    { { HTML_PLUS }, { HTML_PLUS }, elem_select, a_error },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_select, a_error },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_select, a_form },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_select, a_height },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_select, a_md },
    { { HTML_2_0 }, { HTML_UNDEF }, elem_select, a_multiple },
    { { HTML_PLUS }, { HTML_PLUS }, elem_select, a_name },
    { { HTML_2_0, REQUIRED }, { XHTML_2_0 }, elem_select, a_name },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_select, a_name },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_select, a_required },
    { { HTML_2_0 }, { HTML_UNDEF }, elem_select, a_size },
    { { HTML_PLUS }, { HTML_PLUS }, elem_select, a_several },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_select, a_src },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_select, a_units },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_select, a_width },
    HTMLPLUS_ATTRIBUTES (elem_select),
    HTML23_CLID_ATTRIBUTES (elem_select),
    HTML4_FORM_ATTRIBUTES (elem_select),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_select),

    MATH1_DEFS_ATTRIBUTES (elem_selector, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_semantics, MAJOR_X1_0, MINOR_X1_0),

    MATH1_STANDARD_ATTRIBUTES (elem_sep, MAJOR_X1_0, MINOR_X1_0),

    XHTML2_ATTRIBUTES (elem_separator),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_set, a_externalresourcesrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_set, a_to },
    SVG11_ANAT_ATTRIBUTES (elem_set),
    SVG11_ANEV_ATTRIBUTES (elem_set),
    SVG11_ANTIME_ATTRIBUTES (elem_set),
    SVG11_XLINK_ATTRIBUTES (elem_set),
    SVGx_CONDPROC_ATTRIBUTES (elem_set),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_set),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_set),

    MATH1_DEFS_ATTRIBUTES (elem_setdiff, MAJOR_X1_0, MINOR_X1_0),

    STANDARD_HTML54_ATTRIBUTES (elem_shadow),

    MATH1_DEFS_ATTRIBUTES (elem_sin, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_sinh, MAJOR_X1_0, MINOR_X1_0),

    { { HTML_JUL20, HV_WHATWG }, { HTML_UNDEF }, elem_slot, a_name },
    STANDARD_HTML54_ATTRIBUTES (elem_slot),

    HTML3_CLID_ATTRIBUTES (elem_small),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_small),

    STANDARD_HTML_4_54_ATTRIBUTES (elem_solidcolour),

    { { HTML_5_1 }, { HTML_UNDEF }, elem_source, a_media },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_source, a_sizes },
    { { MAJOR_5_0, MINOR_5_0, REQUIRED }, { MAJOR_5_0, MINOR_5_0 }, elem_source, a_src },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_source, a_src },
    { { HTML_5_1 }, { HTML_UNDEF }, elem_source, a_srcset },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_source, a_type },
    STANDARD_HTML54_ATTRIBUTES (elem_source),

    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_span, a_align },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_span, a_datafld },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_span, a_dataformatas },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_span, a_datasrc },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_span, a_align },
    HTML2_CLID_ATTRIBUTES (elem_span),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_span),

    { { MAJOR_3_0, MINOR_3_0, REQUIRED }, { MAJOR_3_0, MINOR_3_0 }, elem_spot, a_id },

    HTML3_CLID_ATTRIBUTES (elem_sqrt),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 | REQUIRED }, { HTML_UNDEF }, elem_stop, a_offset },
    SVGx_PRES_ATTRIBUTES (elem_stop),
    STANDARD_HTML54_ATTRIBUTES (elem_stop),

    XHTML2_ATTRIBUTES (elem_stoppropagation),

    COMMON_HTML4_ATTRIBUTES (elem_strike),

    HTMLPLUS_ATTRIBUTES (elem_strong),
    HTML23_CLID_ATTRIBUTES (elem_strong),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_strong),

    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_style, a_dir },
    { { XHTML_2_0 }, { XHTML_2_0 }, elem_style, a_disabled },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_style, a_lang },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_style, a_media },
    { { HTML_5_1 }, { HTML_5_2 }, elem_style, a_numberonce },
    { { MAJOR_3_0, MINOR_3_0, REQUIRED }, { MAJOR_3_0, MINOR_3_0 }, elem_style, a_notation },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_CHROME }, { XHTML_2_0 }, elem_style, a_scoped },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_style, a_title },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_5_3 }, elem_style, a_type },
    HTML4_STANDARD_SCRIPT_ATTRIBUTES (elem_style, MAJOR_5_0, MINOR_5_0),
    HTML4_STANDARD_CIS_ATTRIBUTES (elem_style, MAJOR_5_0, MINOR_5_0),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_style),
    NEW_HTML54_ATTRIBUTES (elem_style),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_sub, a_align },
    HTMLPLUS_ATTRIBUTES (elem_sub),
    HTML23_CLID_ATTRIBUTES (elem_sub),
    STANDARD_HTML54_ATTRIBUTES (elem_sub),

    MATH1_DEFS_ATTRIBUTES (elem_subset, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_sum, MAJOR_X1_0, MINOR_X1_0),

    STANDARD_HTML_4_54_ATTRIBUTES (elem_summary),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_sup, a_align },
    HTMLPLUS_ATTRIBUTES (elem_sup),
    HTML23_CLID_ATTRIBUTES (elem_sup),
    STANDARD_HTML54_ATTRIBUTES (elem_sup),

    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_svg, a_allow_zoom_pan },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_svg, a_baseprofile },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_svg, a_externalresourcesrequired },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_svg, a_onzoom },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1 }, { HTML_UNDEF }, elem_svg, a_version },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_svg, a_viewbox },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_svg, a_xmlns },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_svg, a_zoomandpan },
    SVG10_BOX_ATTRIBUTES (elem_svg),
    SVG10_FIT_ATTRIBUTES (elem_svg),
    SVG10_G_ATTRIBUTES (elem_svg),
    SVG11_GREV_ATTRIBUTES (elem_svg),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_svg),
    SVGx_CONDPROC_ATTRIBUTES (elem_svg),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_svg),
    SVGx_PRES_ATTRIBUTES (elem_svg),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_svg),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_switch, a_externalresourcesrequired },
    SVG10_G_ATTRIBUTES (elem_switch),
    SVGx_CONDPROC_ATTRIBUTES (elem_switch),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_switch),
    SVG11_GREV_ATTRIBUTES (elem_switch),
    SVGx_PRES_ATTRIBUTES (elem_switch),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_switch),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_symbol, a_externalresourcesrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_symbol, a_preserveaspectratio },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_symbol, a_orient },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_symbol, a_markerheight },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_symbol, a_markerunits },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_symbol, a_markerwidth },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_symbol, a_viewbox },
    SVG10_BOX_ATTRIBUTES (elem_symbol),
    SVG10_FIT_ATTRIBUTES (elem_symbol),
    SVG10_REF_XY_ATTRIBUTES (elem_symbol),
    SVG11_GREV_ATTRIBUTES (elem_symbol),
    SVGx_CONDPROC_ATTRIBUTES (elem_symbol),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_symbol),
    SVGx_PRES_ATTRIBUTES (elem_symbol),
    STANDARD_HTML54_ATTRIBUTES (elem_symbol),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_t, a_class },

    { { HTML_PLUS, HV_NOT2 }, { MAJOR_3_0, MINOR_3_0 }, elem_tab, a_align },
    { { HTML_PLUS }, { HTML_PLUS }, elem_tab, a_at },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_tab, a_dp },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_tab, a_id },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_tab, a_indent },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_tab, a_to },

    { { HTML_2_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_table, a_align },
    { { HTML_3_2, 0, HE_BESPOKE }, { XHTML_2_0 }, elem_table, a_background },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_table, a_bgcolour },
    { { HTML_PLUS, HV_DEPRECATED4 | HV_RFC_2070 }, { HTML_5_3 }, elem_table, a_border },
    { { HTML_2_0, HV_NOT30 }, { XHTML_2_0 }, elem_table, a_cellspacing },
    { { HTML_2_0, HV_NOT30 }, { XHTML_2_0 }, elem_table, a_cellpadding },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_table, a_clear },
    { { HTML_2_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_table, a_cols },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_table, a_colspec },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_table, a_datafld },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_table, a_dataformatas },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_table, a_datasrc },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_table, a_dp },
    { { HTML_2_0, HV_NOT32 }, { XHTML_2_0 }, elem_table, a_frame },
    { { HTML_2_0, HV_NOT32 }, { XHTML_2_0 }, elem_table, a_height },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_table, a_noflow },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_table, a_nowrap },
    { { HTML_2_0, HV_NOT3 }, { XHTML_2_0 }, elem_table, a_rules },
    { { MAJOR_5_0, MINOR_5_0 }, { MAJOR_5_0, MINOR_5_0 }, elem_table, a_sortable },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_table, a_summary },
    { { HTML_2_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_table, a_units },
    { { HTML_2_0 }, { XHTML_2_0 }, elem_table, a_width },
    HTMLPLUS_ATTRIBUTES (elem_table),
    HTML23_CLID_ATTRIBUTES (elem_table),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_table),

    MATH1_DEFS_ATTRIBUTES (elem_tan, MAJOR_X1_0, MINOR_X1_0),

    MATH1_DEFS_ATTRIBUTES (elem_tanh, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_tbody, a_align },
    { { HTML_2_0, 0, HE_IE | HV_RFC_1942 | HV_NOT3 }, { XHTML_2_0 }, elem_tbody, a_bgcolour },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 }, { XHTML_2_0 }, elem_tbody, a_char },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3}, { XHTML_2_0 }, elem_tbody, a_charoff },
    { { HTML_5_2, HV_W3 }, { HTML_UNDEF }, elem_tbody, a_rowgroup },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3}, { XHTML_2_0 }, elem_tbody, a_valign },
    HTML2_CLID_ATTRIBUTES (elem_tbody),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_tbody),

    STANDARD_HTML_4_54_ATTRIBUTES (elem_tbreak),

    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_td, a_abbr },
    { { HTML_PLUS, HV_DEPRECATED4 | HV_RFC_1942 }, { XHTML_2_0 }, elem_td, a_align },
    { { HTML_2_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_td, a_axes },
    { { HTML_2_0, HV_NOT32 }, { XHTML_2_0 }, elem_td, a_axis },
    { { HTML_3_2, 0, HE_BESPOKE }, { XHTML_2_0 }, elem_td, a_background },
    { { HTML_2_0, 0, HE_IE }, { HTML_2_0 }, elem_td, a_bgcolour },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4, HE_IE }, { XHTML_2_0 }, elem_td, a_bgcolour },
    { { HTML_5_2, HV_W3 }, { HTML_UNDEF }, elem_td, a_cell },
    { { HTML_2_0, HV_RFC_1942 }, { HTML_2_0 }, elem_td, a_char },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_td, a_char },
    { { HTML_2_0, HV_RFC_1942 }, { HTML_2_0 }, elem_td, a_charoff },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_td, a_charoff },
    { { HTML_PLUS }, { HTML_UNDEF }, elem_td, a_colspan },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_td, a_dp },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_td, a_headers },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_td, a_height },
    { { HTML_2_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_td, a_nowrap },
    { { HTML_PLUS }, { HTML_UNDEF }, elem_td, a_rowspan },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_td, a_scope },
    { { HTML_2_0, HV_RFC_1942 }, { XHTML_2_0 }, elem_td, a_valign },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_td, a_width },
    HTML23_CLID_ATTRIBUTES (elem_td),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_td),

    STANDARD_HTML54_ATTRIBUTES (elem_template),

    MATH1_DEFS_ATTRIBUTES (elem_tendsto, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_text, a_externalresourcesrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_text, a_lengthadjust },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_text, a_rotate },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_text, a_textlength },
    HTML3_CLID_ATTRIBUTES (elem_text),
    SVG10_XY_ATTRIBUTES(elem_text),
    SVG10_DXY_ATTRIBUTES (elem_text),
    SVG10_G_ATTRIBUTES(elem_text),
    SVG11_GREV_ATTRIBUTES (elem_text),
    SVGx_CONDPROC_ATTRIBUTES (elem_text),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_text),
    SVGx_PRES_ATTRIBUTES (elem_text),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_text),

    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_textarea, a_align },
    { { HTML_5_3 }, { HTML_5_3 }, elem_textarea, a_autocapitalise },
    { { HTML_5_2 }, { HTML_UNDEF }, elem_textarea, a_autocomplete },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_5_3 }, elem_textarea, a_autofocus },
    { { HTML_PLUS }, { HTML_PLUS }, elem_textarea, a_cols },
    { { HTML_2_0, REQUIRED }, { XHTML_2_0 }, elem_textarea, a_cols },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_textarea, a_cols },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_textarea, a_datafld },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_textarea, a_dataformatas },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_textarea, a_datasrc },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_textarea, a_dirname },
    { { HTML_PLUS, HV_NOT2 | HV_NOT32 }, { HTML_UNDEF }, elem_textarea, a_disabled },
    { { HTML_PLUS, HV_NOT2 }, { MAJOR_3_0, MINOR_3_0 }, elem_textarea, a_error },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_textarea, a_form },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_5_1 }, elem_textarea, a_inputmode },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_textarea, a_maxlength },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_textarea, a_minlength },
    { { HTML_PLUS }, { HTML_PLUS }, elem_textarea, a_name },
    { { HTML_2_0, REQUIRED }, { HTML_3_2 }, elem_textarea, a_name },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_textarea, a_name },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_textarea, a_onblur },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_textarea, a_onchange },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_textarea, a_onfocus },
    { { MAJOR_4_0, MINOR_4_0 }, { XHTML_2_0 }, elem_textarea, a_onselect },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_textarea, a_placeholder },
    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_textarea, a_readonly },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_textarea, a_required },
    { { HTML_PLUS }, { HTML_PLUS }, elem_textarea, a_rows },
    { { HTML_2_0, REQUIRED }, { XHTML_2_0 }, elem_textarea, a_rows },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_textarea, a_rows },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_textarea, a_wrap },
    HTMLPLUS_ATTRIBUTES (elem_textarea),
    HTML23_CLID_ATTRIBUTES (elem_textarea),
    HTML4_FORM_ATTRIBUTES (elem_textarea),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_textarea),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_textpath, a_externalresourcesrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_textpath, a_method },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_textpath, a_spacing },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_textpath, a_spreadmethod },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_textpath, a_startoffset },
    SVG10_REPL_ATTRIBUTES(elem_textpath),
    SVG11_XLINK_ATTRIBUTES (elem_textpath),
    SVG11_GREV_ATTRIBUTES (elem_textpath),
    SVGx_CONDPROC_ATTRIBUTES (elem_textpath),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_textpath),
    SVGx_PRES_ATTRIBUTES (elem_textpath),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_textpath),


    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 | HV_DEPRECATED4 }, { XHTML_2_0 }, elem_tfoot, a_align },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3, HE_IE }, { XHTML_2_0 }, elem_tfoot, a_bgcolour },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 }, { XHTML_2_0 }, elem_tfoot, a_char },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 }, { XHTML_2_0 }, elem_tfoot, a_charoff },
    { { HTML_5_2, HV_W3 }, { HTML_UNDEF }, elem_tfoot, a_rowgroup },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 }, { XHTML_2_0 }, elem_tfoot, a_valign },
    HTML2_CLID_ATTRIBUTES (elem_tfoot),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_tfoot),

    { { MAJOR_4_0, MINOR_4_0 }, { HTML_UNDEF }, elem_th, a_abbr },
    { { HTML_PLUS, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_th, a_align },
    { { HTML_2_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_th, a_axes },
    { { HTML_2_0, HV_NOT32 }, { XHTML_2_0 }, elem_th, a_axis },
    { { HTML_2_0, 0, HE_IE }, { HTML_2_0 }, elem_th, a_bgcolour },
    { { MAJOR_4_0, MINOR_4_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_th, a_bgcolour },
    { { HTML_2_0, HV_NOT3 }, { XHTML_2_0 }, elem_th, a_char },
    { { HTML_2_0, HV_NOT3 }, { XHTML_2_0 }, elem_th, a_charoff },
    { { HTML_PLUS }, { HTML_UNDEF }, elem_th, a_colspan },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_th, a_dp },
    { { HTML_2_0, HV_NOT3 }, { HTML_UNDEF }, elem_th, a_headers },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_th, a_height },
    { { HTML_PLUS }, { HTML_PLUS }, elem_th, a_lang },
    { { HTML_2_0, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_th, a_nowrap },
    { { HTML_PLUS }, { HTML_UNDEF }, elem_th, a_rowspan },
    { { HTML_2_0, HV_NOT32 }, { HTML_UNDEF }, elem_th, a_scope },
    { { MAJOR_5_0, MINOR_5_0 }, { MAJOR_5_0, MINOR_5_0 }, elem_th, a_sorted },
    { { HTML_2_0 }, { XHTML_2_0 }, elem_th, a_valign },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_th, a_width },
    HTML23_CLID_ATTRIBUTES (elem_th),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_th),

    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 | HV_DEPRECATED4 }, { XHTML_2_0 }, elem_thead, a_align },
    { { HTML_2_0, HV_NOT3 | HV_RFC_1942, HE_IE }, { XHTML_2_0 }, elem_thead, a_bgcolour },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 }, { XHTML_2_0 }, elem_thead, a_char },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 }, { XHTML_2_0 }, elem_thead, a_charoff },
    { { HTML_5_2, HV_W3 }, { HTML_UNDEF }, elem_thead, a_rowgroup },
    { { HTML_2_0, HV_RFC_1942 }, { XHTML_2_0 }, elem_thead, a_valign },
    HTML2_CLID_ATTRIBUTES (elem_thead),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_thead),

    HTML3_CLID_ATTRIBUTES (elem_tilde),

    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_time, a_datetime },
    STANDARD_HTML54_ATTRIBUTES (elem_time),

    MATH1_DEFS_ATTRIBUTES (elem_times, MAJOR_X1_0, MINOR_X1_0),

    HTMLPLUS_ATTRIBUTES (elem_title),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_title),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_title),

    { { HTML_2_0, HV_RFC_1942 | HV_DEPRECATED4 }, { XHTML_2_0 }, elem_tr, a_align },
    { { HTML_2_0, HV_NOT3, HE_IE }, { HTML_2_0 }, elem_tr, a_bgcolour },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 }, { XHTML_2_0 }, elem_tr, a_char },
    { { HTML_2_0, HV_RFC_1942 | HV_NOT3 }, { XHTML_2_0 }, elem_tr, a_charoff },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_tr, a_dp },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_tr, a_nowrap },
    { { HTML_5_2, HV_W3 }, { HTML_UNDEF }, elem_tr, a_row },
    { { HTML_2_0, HV_RFC_1942 }, { XHTML_2_0 }, elem_tr, a_valign },
    HTML23_CLID_ATTRIBUTES (elem_tr),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_tr),

    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_track, a_default },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_track, a_kind },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_track, a_label },
    { { MAJOR_5_0, MINOR_5_0, REQUIRED }, { HTML_UNDEF }, elem_track, a_src },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_track, a_srclang },
    STANDARD_HTML54_ATTRIBUTES(elem_track),

    MATH1_DEFS_ATTRIBUTES (elem_transpose, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_tspan, a_externalresourcesrequired },
    SVG11_XLINK_ATTRIBUTES (elem_tref),
    SVG10_XY_ATTRIBUTES (elem_tref),
    SVG10_DXY_ATTRIBUTES (elem_tref),
    SVG10_REPL_ATTRIBUTES (elem_tref),
    SVG11_GREV_ATTRIBUTES (elem_tref),
    SVGx_CONDPROC_ATTRIBUTES (elem_tref),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_tref),
    SVGx_PRES_ATTRIBUTES (elem_tref),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_tref),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_tspan, a_externalresourcesrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_tspan, a_lengthadjust },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_tspan, a_rotate },
    { { MAJOR_4_0, MINOR_4_0, 0, HE_SVG_1_0 }, { HTML_UNDEF }, elem_tspan, a_systemrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_tspan, a_textlength },
    SVG10_XY_ATTRIBUTES(elem_tspan),
    SVG10_DXY_ATTRIBUTES (elem_tspan),
    SVG10_REPL_ATTRIBUTES(elem_tspan),
    SVG11_GREV_ATTRIBUTES (elem_tspan),
    SVGx_CONDPROC_ATTRIBUTES (elem_tspan),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_tspan),
    SVGx_PRES_ATTRIBUTES (elem_tspan),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_tspan),

    HTMLPLUS_ATTRIBUTES (elem_tt),
    HTML23_CLID_ATTRIBUTES (elem_tt),

    HTMLPLUS_ATTRIBUTES (elem_u),
    HTML3_CLID_ATTRIBUTES (elem_u),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_u),

    { { HTML_2_0, HV_RFC_2070 }, { HTML_2_0 }, elem_ul, a_align },
    { { MAJOR_3_0, MINOR_3_0, HV_NOT32 | HV_DEPRECATED4 }, { XHTML_2_0 }, elem_ul, a_clear },
    { { HTML_PLUS, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_ul, a_compact },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_ul, a_dingbat },
    { { HTML_PLUS, HV_NOT2 }, { MAJOR_3_0, MINOR_3_0 }, elem_ul, a_plain },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_ul, a_md },
    { { MAJOR_3_0, MINOR_3_0 }, { MAJOR_3_0, MINOR_3_0 }, elem_ul, a_src },
    { { HTML_3_2, HV_DEPRECATED4 }, { XHTML_2_0 }, elem_ul, a_type },
    { { HTML_PLUS, HV_NOT2 }, { MAJOR_3_0, MINOR_3_0 }, elem_ul, a_wrap },
    HTMLPLUS_ATTRIBUTES (elem_ul),
    HTML23_CLID_ATTRIBUTES (elem_ul),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_ul),

    MATH1_STANDARD_ATTRIBUTES (elem_uplimit, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_use, a_externalresourcesrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_use, a_xlinkhref },
    SVG10_REPL_ATTRIBUTES(elem_use),
    SVG10_BOX_ATTRIBUTES(elem_use),
    SVG10_G_ATTRIBUTES(elem_use),
    SVG11_GREV_ATTRIBUTES (elem_use),
    SVGx_CONDPROC_ATTRIBUTES (elem_use),
    SVGx_XTRA_CORE_ATTRIBUTES (elem_use),
    SVGx_PRES_ATTRIBUTES (elem_use),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_use),

    MATH1_DEFS_ATTRIBUTES (elem_union, MAJOR_X1_0, MINOR_X1_0),

    HTMLPLUS_ATTRIBUTES (elem_var),
    HTML23_CLID_ATTRIBUTES (elem_var),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_var),

    MATH1_DEFS_ATTRIBUTES (elem_variance, MAJOR_X1_0, MINOR_X1_0),

    HTML3_CLID_ATTRIBUTES (elem_vec),

    MATH1_STANDARD_ATTRIBUTES (elem_vector, MAJOR_X1_0, MINOR_X1_0),

    { { MAJOR_5_0, MINOR_5_0, 0, HE_EXPERIMENTAL }, { HTML_UNDEF }, elem_video, a_autopictureinpicture },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_video, a_autoplay },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_MOZILLA | HE_OPERA }, { HTML_UNDEF }, elem_video, a_buffered },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_video, a_controls },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_EXPERIMENTAL }, { HTML_UNDEF }, elem_video, a_controlslist },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_video, a_crossorigin },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_BESPOKE }, { HTML_UNDEF }, elem_video, a_currenttime },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_EXPERIMENTAL }, { HTML_UNDEF }, elem_video, a_disablepictureinpicture },
    { { HTML_5_3 }, { HTML_5_3 }, elem_video, a_disableremoteplayback },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_BESPOKE }, { HTML_UNDEF }, elem_video, a_duration },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_video, a_height },
    { { MAJOR_5_0, MINOR_5_0, 0, HE_CHROME | HE_OPERA }, { HTML_UNDEF }, elem_video, a_intrinsicsize },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_video, a_loop },
    { { MAJOR_5_0, MINOR_5_0 }, { MAJOR_5_0, MINOR_5_0 }, elem_video, a_mediagroup },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_video, a_muted },
    { { HTML_JUL20, HV_WHATWG }, { HTML_UNDEF }, elem_video, a_playsinline },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_video, a_poster },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_video, a_preload },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_video, a_src },
    { { MAJOR_5_0, MINOR_5_0 }, { HTML_UNDEF }, elem_video, a_width },
    STANDARD_HTML54_ATTRIBUTES(elem_video),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_view, a_externalresourcesrequired },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_view, a_preserveaspectratio },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_view, a_viewbox },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_view, a_viewtarget },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_view, a_zoomandpan },
    SVGx_XTRA_CORE_ATTRIBUTES (elem_view),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_view),

    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_vkern, a_g1 },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_vkern, a_g2 },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_vkern, a_k },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_vkern, a_u1 },
    { { MAJOR_X1_0, MINOR_X1_0, 0, HE_SVG_1_1 }, { HTML_UNDEF }, elem_vkern, a_u1 },
    SVGx_XTRA_CORE_ATTRIBUTES (elem_vkern),
    STANDARD_HTML_4_54_ATTRIBUTES (elem_vkern),

    STANDARD_HTML54_ATTRIBUTES(elem_wbr),

    HTML23_CLID_ATTRIBUTES (elem_xmp),

    MATH1_DEFS_ATTRIBUTES (elem_xor, MAJOR_X1_0, MINOR_X1_0)
};

typedef ::std::multimap < uint64_t, hav_t > avm_t;
avm_t avm;

inline uint64_t avm_key (const e_element tag, const e_attribute a)
{   return (static_cast < uint64_t > (tag) << 32) + static_cast < uint64_t > (a); }

void avm_init (nitpick& )
{   for (int index = 0; havt [index].tag_ != a_unknown; ++index)
        avm.insert (avm_t::value_type (avm_key (havt [index].tag_, havt [index].a_), havt [index])); }

bool is_invalid_attribute_version (const html_version& v, const e_element tag, const e_attribute a)
{   if (! v.known ()) return false;
    for (avm_t::const_iterator i = avm.find (avm_key (tag, a)); i != avm.cend () && (i -> second.tag_ == tag) && (i -> second.a_ == a); ++i)
        if (may_apply (v, i -> second.first_, i -> second.last_)) return false;
    for (avm_t::const_iterator i = avm.find (avm_key (elem_undefined, a)); i != avm.cend () && (i -> second.tag_ == elem_undefined) && (i -> second.a_ == a); ++i)
        if (may_apply (v, i -> second.first_, i -> second.last_)) return false;
    return true; }

bool is_deprecated_attribute_version (const html_version& v, const e_element tag, const e_attribute a)
{   if (! v.known ()) return false;
    for (avm_t::const_iterator i = avm.find (avm_key (tag, a)); i != avm.cend () && (i -> second.tag_ == tag) && (i -> second.a_ == a); ++i)
        if (may_apply (v, i -> second.first_, i -> second.last_)) return i -> second.first_.deprecated (v);
    for (avm_t::const_iterator i = avm.find (avm_key (elem_undefined, a)); i != avm.cend () && (i -> second.tag_ == elem_undefined) && (i -> second.a_ == a); ++i)
        if (may_apply (v, i -> second.first_, i -> second.last_)) return i -> second.first_.deprecated (v);
    return false; }

bool is_attribute_required (const html_version& v, const e_element tag, const e_attribute a)
{   if (v.known ())
        for (avm_t::const_iterator i = avm.find (avm_key (tag, a)); i != avm.cend () && (i -> second.tag_ == tag) && (i -> second.a_ == a); ++i)
            if (may_apply (v, i -> second.first_, i -> second.last_)) return i -> second.first_.required ();
    return false; }

bool is_attribute_rejected (const html_version& v, const e_element tag, const e_attribute a)
{   if (v.known ())
        for (avm_t::const_iterator i = avm.find (avm_key (tag, a)); i != avm.cend () && (i -> second.tag_ == tag) && (i -> second.a_ == a); ++i)
            if (may_apply (v, i -> second.first_, i -> second.last_)) return i -> second.first_.reject ();
    return false; }
