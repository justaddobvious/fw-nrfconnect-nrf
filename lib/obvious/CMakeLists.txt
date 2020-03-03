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
## Copyright © 2019,
## 4iiii Innovations Inc.,
## Cochrane, Alberta, Canada.
## All rights reserved.
## Redistribution and use in source and binary forms, with or without
## modification, are not permitted without express written approval of
## 4iiii Innovations Inc.
#######################################################################

set(OBVIOUS_EMBEDDED_SDK_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(OBVIOUS_EMBEDDED_SDK_TARGET obvious_embedded_sdk)

if(DEFINED CONFIG_OBVIOUS_LOG_LEVEL_DBG)
   zephyr_library_import(${OBVIOUS_EMBEDDED_SDK_TARGET} ${OBVIOUS_EMBEDDED_SDK_LIB_PATH}/bin/libobvious_embedded_sdk_LOG_LVL_DBG.a)
elseif(DEFINED CONFIG_OBVIOUS_LOG_LEVEL_WRN)
   zephyr_library_import(${OBVIOUS_EMBEDDED_SDK_TARGET} ${OBVIOUS_EMBEDDED_SDK_LIB_PATH}/bin/libobvious_embedded_sdk_LOG_LVL_WRN.a)
elseif(DEFINED CONFIG_OBVIOUS_LOG_LEVEL_INF)
   zephyr_library_import(${OBVIOUS_EMBEDDED_SDK_TARGET} ${OBVIOUS_EMBEDDED_SDK_LIB_PATH}/bin/libobvious_embedded_sdk_LOG_LVL_INF.a)
elseif(DEFINED CONFIG_OBVIOUS_LOG_LEVEL_ERR)
   zephyr_library_import(${OBVIOUS_EMBEDDED_SDK_TARGET} ${OBVIOUS_EMBEDDED_SDK_LIB_PATH}/bin/libobvious_embedded_sdk_LOG_LVL_ERR.a)
else(DEFINED CONFIG_OBVIOUS_LOG_LEVEL_DBG)
   zephyr_library_import(${OBVIOUS_EMBEDDED_SDK_TARGET} ${OBVIOUS_EMBEDDED_SDK_LIB_PATH}/bin/libobvious_embedded_sdk_LOG_LVL_NONE.a)
endif(DEFINED CONFIG_OBVIOUS_LOG_LEVEL_DBG)

zephyr_include_directories(inc)
zephyr_library()
zephyr_library_sources(src/obvious_embedded_sdk.c)
