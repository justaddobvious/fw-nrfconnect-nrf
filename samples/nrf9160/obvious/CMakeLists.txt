#######################################################################
##
##            @@@
##            @@@
##   @@@@@@@  @@@@@@@@  @@   @@@ @@   @@@@@@@  @@@   @@  @@@@@@@
##  @@    @@@ @@@   @@@  @@  @@  @@  @@    @@@ @@@   @@  @@@@
##  @@    @@@ @@@   @@@  @@@@@   @@  @@    @@@ @@@   @@      @@@
##   @@@@@@@  @@@@@@@@    @@@    @@   @@@@@@@   @@@@@@@  @@@@@@@  @@
##
##                                                      -smMMm/         
##    `odmhs.                                         :hMMMMMNN/        
##   `hMMMMMNy/`                                    +mMMMMMMNmdy        
##   -NMMMMMMMNms.                                oNMMMMMMMMNdyh-       
##   +MNMMMMMMMMMMd/`                          -sNMNMMMMMNNNmhsds       
##   yNmMMMMMMMMMMNmmy-                      -sNNmNMMMNNNmhyo+sdy       
##   sMNNMMMMMMMMMNNmmNh/-....//::./+oooossydmmsodmmmNMMNNmdyoydh       
##   /MNdmmMMMMMMNNmdyyhdmdmNNNNNNNMNNNMNMNdmm++oyddmNNNNmdyso+yh.      
##   `Nmmhhddddmmmmdhs++ydmhhdmNMNNMNMmMdNmdddhdhydmmmddmNmdyssmd.      
##   `NmhhmNMMMNmNNmdyyshmNddmmddNmNNNmNdhmhhhmNmdhyyyyoo/:+syddo-
##   `mMMmdmdhyyyyyyhmNNNNmmmddhhNdNmmMNNmdhddmmNmyo+///-.-:++dNmo
##   :NMMdss+::/:.`-oymMMMNmdhhdmMNNNNMNMMmmmmdmNMMNdhhs/::++ohmMd-    
##   :MMNyyoo/:soooydMMMMNmddhmMNNMMMNMMNNMNdhdmmmNMMMMNdhs+/ohddmy    
##  .mMMNdyo++ohNNMMMMMNmmddhdNMMNNMNNMMNMMMmmNMNdmNmNNMMMmhyddhhhh-    
##  :NNNmmmhydMMMMMMNNNNNNMMNNMMMMNNddNNMMMMNNMMMMNNmddmNMMMMNmhhys
##  :NNNNNNMMMMMMMNNNNNMMMMMMNMMMNNNdydmNmNNmmhyhmMMNmdhhdmNNdhysy/
##  .mmdmNMMMMMNNNNNMMMNhyo++shddhyyssyhhyyy/`  ``.+yddyyyyhdmmhsy:
##   yNmmNMMMNNNNmNNmy+`-.    .syhysyosyydd/-`  `. -+/+shhyhhddys+.
##   -ddhmNMMNNNNmhsydm/--`  `.`yNmdhyyhhms ::.`.:odmmds:+hddhhy/
##    .odmNMMMNmdsdNMMMMmysooso:-ymmmmNmhs`-hddmNNNNNmmdo.:shhyo.
##     `oNNMNmhh/smNMMMMMMMMMMMm++hdMMMNh+-odNNNNNmNNNNNmy-+syy:
##      `sNNmhs+/dMMMMMNNNNNNNNdyo/dMMMMh::shhhhdmmmmddmdh::oo+
##       `/ddo-:omMMNmmmddNNNmmmmhoo+yy+:-ydddhhdddddhhdmds:oy.
##        -mMNmdmNMMNmddmNMmddNNNNh-  ` `+NNmdyydNNmmdddmmmmmh-
##        -mMMMMMMMMNmmNNMMNNMMNMMMMh:`:dNNNNNNNMMNNNNNNNNNNNy.
##        .yMMMMMMMMMMNNNNMMMMMMNNmhs:`:ohmmNNNMMMNNNNNMMMMNNo-
##         .sNMMMMMMMMMMNNNMMMMMNdyo-.`.:+shmNNNNNNNNNNNNNNNNd:.
##         .:dMMMMMMMMMNNNNNNNNNmdhhhysyhddmmmmmmmmNNNNmdddmmNy:
##         -+nMMMMMMMMNNNmmNmmmdmmmmmmmmmmdhhhhddmmddhhhhhdmmNm+:
##         .sMMMMMMNMMNNmmmmmmmdddddddhhhhyyyyyyyyyyyyyyyyydmmm/`
##          yMMMMMMNNNNmmmmmmddddhhhhhhhhhhssssso+syyyhhhddhddm+  
##         .dMMMMMMNNNNmmNmdmddhddddhhhhhhhhysyyys+oyyhhddmdddms`  
##        -/NMMMMMMMMNNNmdhhddhhhhdddhhhhhhyyssyyyyosyyhdmmmddmm:       
##        `/MMMMMMMMNNNNmhyshyyhhdmmdoshdhyyyssyyyhyyhhddddddddds.    
##
#######################################################################

cmake_minimum_required(VERSION 3.13.1)

include($ENV{NCS_BASE}/nrf/cmake/boilerplate.cmake NO_POLICY_SCOPE)
include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
project(obvious_example_app)
zephyr_compile_definitions(PROJECT_NAME=${PROJECT_NAME})

target_sources(app PRIVATE src/main.c)

zephyr_include_directories(inc)
