ssc 0.0.60
Static Site Checker

(an opinionated HTML nitpicker
for hand-made websites)



see LICENCE.txt for copyright & licence notice
GPL 3 applies

https://dylanharris.org/ssc
https://github.com/devongarde/ssc



WARNING: this code is:
- incomplete
- pre-alpha
- IT WILL NOT DO WHAT YOU EXPECT :-)
- do NOT feed it untrusted data



ssc analyses static HTML sites at source:
- HTML 1.0/+/2.0/3.0/3.2/4.00/4.01/5.0/5.1/5.2/5.3/WhatWG July 2020
- SVG 1.0/1.1
- MathML 1
- XHTML 1.0/1.1/2.0, -ish
- broken links (requires curl)
- server side includes
- schema.org microdata 2.x/3.x/4.0/5.0/6.0/7.x/8.0/9.0/10.0
- microformats v1 & v2, as per microformats.org

with opinions on:
- standard english where dialect is required
- perfectly legal but miserably untidy HTML
- abhorrent HTML such as autoplay on video

It does NOT:
- do what you want or expect
- behave securely: its parser is holier than robin's cow
- analyse or understand scripts
- analyse or understand styles, beyond nicking class names from CSS
- analyse or understand XML or derivatives except as noted above



ssc -h
for a usage summary.

ssc -f config_file
analyse site using preprepared configuration

ssc directory
analyse website based in directory



To build & run:
1. Set the environment variable SSCPATH to point to the ssc root directory (the one containing recipe)
2. Build and install boost 1.71 or better (perhaps from boost.org)
3. You may need to set the environment variable BOOST to point to the BOOST home directory
4. EITHER build with CMake 3.10 or better ("cd recipe/tea" "cmake ." "make" "ctest" "make install")
5. OR open recipe\tea\ssc.sln in Visual Studio 2019 under Windows then build 64bit release
6. If necessary install curl (perhaps from curl.haxx.se)
7. Gleefully run ssc



Notes on folder name word play:
- recipe: a nod to Vernor Vinge's "A Fire Upon the Deep"
- tea: without tea, nothing works / builders' tea
- sauce: identifies people who presume / obvious
- toast: toasts code / i like burnt toast
- heater: i'm not stopping now



written by dylan harris
https://dylanharris.org/

dylan harris
ssc@dylanharris.org
October 2020
