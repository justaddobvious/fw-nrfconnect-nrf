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

set(OBVIOUS_EMBEDDED_SDK_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(OBVIOUS_EMBEDDED_SDK_TARGET obvious_embedded_sdk)

if (DEFINED CONFIG_BOARD_NRF9160_PCA10090NS)
   if (DEFINED CONFIG_OBVIOUS_LOG_LEVEL_DBG)
      set(OBVIOUS_EMBEDDED_SDK_BIN_PATH ${OBVIOUS_EMBEDDED_SDK_LIB_PATH}/bin/nrf9160_pca10090ns/LOG_LEVEL_DBG)
   elseif (DEFINED CONFIG_OBVIOUS_LOG_LEVEL_WRN)
      set(OBVIOUS_EMBEDDED_SDK_BIN_PATH ${OBVIOUS_EMBEDDED_SDK_LIB_PATH}/bin/nrf9160_pca10090ns/LOG_LEVEL_WRN)
   elseif (DEFINED CONFIG_OBVIOUS_LOG_LEVEL_INF)
      set(OBVIOUS_EMBEDDED_SDK_BIN_PATH ${OBVIOUS_EMBEDDED_SDK_LIB_PATH}/bin/nrf9160_pca10090ns/LOG_LEVEL_INF)
   elseif (DEFINED CONFIG_OBVIOUS_LOG_LEVEL_ERR)
      set(OBVIOUS_EMBEDDED_SDK_BIN_PATH ${OBVIOUS_EMBEDDED_SDK_LIB_PATH}/bin/nrf9160_pca10090ns/LOG_LEVEL_ERR)
   else (DEFINED CONFIG_OBVIOUS_LOG_LEVEL_DBG)
      set(OBVIOUS_EMBEDDED_SDK_BIN_PATH ${OBVIOUS_EMBEDDED_SDK_LIB_PATH}/bin/nrf9160_pca10090ns/LOG_LEVEL_NONE)
   endif(DEFINED CONFIG_OBVIOUS_LOG_LEVEL_DBG)
elseif (DEFINED CONFIG_BOARD_NRF9160_PCA20035NS)
   if (DEFINED CONFIG_OBVIOUS_LOG_LEVEL_DBG)
      set(OBVIOUS_EMBEDDED_SDK_BIN_PATH ${OBVIOUS_EMBEDDED_SDK_LIB_PATH}/bin/nrf9160_pca20035ns/LOG_LEVEL_DBG)
   elseif (DEFINED CONFIG_OBVIOUS_LOG_LEVEL_WRN)
      set(OBVIOUS_EMBEDDED_SDK_BIN_PATH ${OBVIOUS_EMBEDDED_SDK_LIB_PATH}/bin/nrf9160_pca20035ns/LOG_LEVEL_WRN)
   elseif (DEFINED CONFIG_OBVIOUS_LOG_LEVEL_INF)
      set(OBVIOUS_EMBEDDED_SDK_BIN_PATH ${OBVIOUS_EMBEDDED_SDK_LIB_PATH}/bin/nrf9160_pca20035ns/LOG_LEVEL_INF)
   elseif (DEFINED CONFIG_OBVIOUS_LOG_LEVEL_ERR)
      set(OBVIOUS_EMBEDDED_SDK_BIN_PATH ${OBVIOUS_EMBEDDED_SDK_LIB_PATH}/bin/nrf9160_pca20035ns/LOG_LEVEL_ERR)
   else (DEFINED CONFIG_OBVIOUS_LOG_LEVEL_DBG)
      set(OBVIOUS_EMBEDDED_SDK_BIN_PATH ${OBVIOUS_EMBEDDED_SDK_LIB_PATH}/bin/nrf9160_pca20035ns/LOG_LEVEL_NONE)
   endif(DEFINED CONFIG_OBVIOUS_LOG_LEVEL_DBG)
else (DEFINED CONFIG_BOARD_NRF9160_PCA10090NS)
   message(FATAL_ERROR "Board type not supported. Must select either nrf9160_pca10090ns or nrf9160_pca20035ns.")
endif(DEFINED CONFIG_BOARD_NRF9160_PCA10090NS)
   
zephyr_library_import(${OBVIOUS_EMBEDDED_SDK_TARGET} ${OBVIOUS_EMBEDDED_SDK_BIN_PATH}/libobvious_embedded_sdk.a)
zephyr_include_directories(inc)
zephyr_library()
zephyr_library_sources(src/obvious_embedded_sdk.c)
