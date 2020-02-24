//////////////////////////////////////////////////////////////////////
//
//            @@@
//            @@@
//   @@@@@@@  @@@@@@@@  @@   @@@ @@   @@@@@@@  @@@   @@  @@@@@@@
//  @@    @@@ @@@   @@@  @@  @@  @@  @@    @@@ @@@   @@  @@@@
//  @@    @@@ @@@   @@@  @@@@@   @@  @@    @@@ @@@   @@      @@@
//   @@@@@@@  @@@@@@@@    @@@    @@   @@@@@@@   @@@@@@@  @@@@@@@  @@
//
//                                                      -smMMm/         
//    `odmhs.                                         :hMMMMMNN/        
//   `hMMMMMNy/`                                    +mMMMMMMNmdy        
//   -NMMMMMMMNms.                                oNMMMMMMMMNdyh-       
//   +MNMMMMMMMMMMd/`                          -sNMNMMMMMNNNmhsds       
//   yNmMMMMMMMMMMNmmy-                      -sNNmNMMMNNNmhyo+sdy       
//   sMNNMMMMMMMMMNNmmNh/-....//::./+oooossydmmsodmmmNMMNNmdyoydh       
//   /MNdmmMMMMMMNNmdyyhdmdmNNNNNNNMNNNMNMNdmm++oyddmNNNNmdyso+yh.      
//   `Nmmhhddddmmmmdhs++ydmhhdmNMNNMNMmMdNmdddhdhydmmmddmNmdyssmd.      
//   `NmhhmNMMMNmNNmdyyshmNddmmddNmNNNmNdhmhhhmNmdhyyyyoo/:+syddo-
//   `mMMmdmdhyyyyyyhmNNNNmmmddhhNdNmmMNNmdhddmmNmyo+///-.-:++dNmo
//   :NMMdss+::/:.`-oymMMMNmdhhdmMNNNNMNMMmmmmdmNMMNdhhs/::++ohmMd-    
//   :MMNyyoo/:soooydMMMMNmddhmMNNMMMNMMNNMNdhdmmmNMMMMNdhs+/ohddmy    
//  .mMMNdyo++ohNNMMMMMNmmddhdNMMNNMNNMMNMMMmmNMNdmNmNNMMMmhyddhhhh-    
//  :NNNmmmhydMMMMMMNNNNNNMMNNMMMMNNddNNMMMMNNMMMMNNmddmNMMMMNmhhys
//  :NNNNNNMMMMMMMNNNNNMMMMMMNMMMNNNdydmNmNNmmhyhmMMNmdhhdmNNdhysy/
//  .mmdmNMMMMMNNNNNMMMNhyo++shddhyyssyhhyyy/`  ``.+yddyyyyhdmmhsy:
//   yNmmNMMMNNNNmNNmy+`-.    .syhysyosyydd/-`  `. -+/+shhyhhddys+.
//   -ddhmNMMNNNNmhsydm/--`  `.`yNmdhyyhhms ::.`.:odmmds:+hddhhy/
//    .odmNMMMNmdsdNMMMMmysooso:-ymmmmNmhs`-hddmNNNNNmmdo.:shhyo.
//     `oNNMNmhh/smNMMMMMMMMMMMm++hdMMMNh+-odNNNNNmNNNNNmy-+syy:
//      `sNNmhs+/dMMMMMNNNNNNNNdyo/dMMMMh::shhhhdmmmmddmdh::oo+
//       `/ddo-:omMMNmmmddNNNmmmmhoo+yy+:-ydddhhdddddhhdmds:oy.
//        -mMNmdmNMMNmddmNMmddNNNNh-  ` `+NNmdyydNNmmdddmmmmmh-
//        -mMMMMMMMMNmmNNMMNNMMNMMMMh:`:dNNNNNNNMMNNNNNNNNNNNy.
//        .yMMMMMMMMMMNNNNMMMMMMNNmhs:`:ohmmNNNMMMNNNNNMMMMNNo-
//         .sNMMMMMMMMMMNNNMMMMMNdyo-.`.:+shmNNNNNNNNNNNNNNNNd:.
//         .:dMMMMMMMMMNNNNNNNNNmdhhhysyhddmmmmmmmmNNNNmdddmmNy:
//         -+NMMMMMMMMNNNmmNmmmdmmmmmmmmmmdhhhhddmmddhhhhhdmmNm+:
//         .sMMMMMMNMMNNmmmmmmmdddddddhhhhyyyyyyyyyyyyyyyyydmmm/`
//          yMMMMMMNNNNmmmmmmddddhhhhhhhhhhssssso+syyyhhhddhddm+  
//         .dMMMMMMNNNNmmNmdmddhddddhhhhhhhhysyyys+oyyhhddmdddms`  
//        -/NMMMMMMMMNNNmdhhddhhhhdddhhhhhhyyssyyyyosyyhdmmmddmm:       
//        `/MMMMMMMMNNNNmhyshyyhhdmmdoshdhyyyssyyyhyyhhddddddddds.    
//
// Copyright © 2019,
// 4iiii Innovations Inc.,
// Cochrane, Alberta, Canada.
// All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are not permitted without express written approval of
// 4iiii Innovations Inc.
///////////////////////////////////////////////////////////////////////

#if !defined(SANDCAT_H_)
#define SANDCAT_H_

#include <stdbool.h>
#include <stdint.h>

#if defined(__cplusplus)
   extern "C"
   {
#endif

enum SANDCAT_ERROR
{
   SANDCAT_SUCCESS,                          //  0  //< Operation completed successfully.
   SANDCAT_ERROR_INTERNAL,                   //  1  //< An internal error has occured.
   SANDCAT_ERROR_NO_INIT,                    //  2  //< sandcat_exeute() was called before sandcat_init() and sandcat_lte_init() were called.
   SANDCAT_ERROR_NULL,                       //  3  //< A pointer parameter is set to NULL that should be set to a valid memory location.
   SANDCAT_ERROR_ALIGN,                      //  4  //< A pointer parameter is set to a location that is not memory alligned as it should be.
   SANDCAT_ERROR_RANGE,                      //  5  //< A pointer parameter is set to a value outside the appropriate range.
   SANDCAT_ERROR_WRITE,                      //  6  //< A flash write error has occured. 
   SANDCAT_ERROR_FILE_OPEN,                  //  7  //< Failed to open internal obvious file for writing.
   SANDCAT_ERROR_EXECUTION_CONFLICT,         //  8  //< sandcat_execute() was called while sandcat was already executing.
   SANDCAT_ERROR_MQTT_CLIENT_INIT,           //  9  //< Failed to initialize the sandcat MQTT client.
   SANDCAT_ERROR_MQTT_CONNECT,               //  10 //< Failed to connect to the obvious MQTT broker.
   SANDCAT_ERROR_MQTT_INPUT,                 //  11 //< Failed to recieve incoming MQTT packet.
   SANDCAT_ERROR_MQTT_LIVE,                  //  12 //< Failed to keep MQTT connection with obvious broker alive.
   SANDCAT_ERROR_MQTT_CONNECTION_DROPPED,    //  13 //< MQTT connection to obvious broker unexpectadly dropped.
   SANDCAT_ERROR_MQTT_TIMEOUT,               //  14 //< Sandcat timed out after sending MQTT message without receiving response.
   SANDCAT_ERROR_MQTT_PUBLISH,               //  15 //< Failed to publish MQTT message, either device details or provisioning response.
   SANDCAT_ERROR_MQTT_SUBSCRIBE,             //  16 //< Failed to subscribe to unique MQTT device topic with obvious broker.
   SANDCAT_ERROR_MQTT_UNSUBSCRIBE,           //  17 //< Failedd to unsbscribe from unique MQTT device topic with obvious broker.
   SANDCAT_ERROR_FDS_POLL,                   //  18 //< Failed to poll FDS.
   SANDCAT_ERROR_FDS_POLLNVAL,               //  19 //< FDS poll is invalid.
   SANDCAT_ERROR_ENCODE_DEVICE_DETAILS,      //  20 //< Failed to encode device details into MQTT message.
   SANDCAT_ERROR_PROVISIONING_CMAC,          //  21 //< Failed to get the device provisioning CMAC.
   SANDCAT_ERROR_PRIVATE_CERT_INVALID,       //  22 //< The incoming private certificate is invalid.
   SANDCAT_ERROR_PUBLIC_CERT_INVALID,        //  23 //< The incoming public certificate is invalid.
   SANDCAT_ERROR_PROVISIONING_FILE_INVALID,  //  24 //< The incoming provisioning file is invalid.
   SANDCAT_ERROR_FEATURE_FILE_INVALID,       //  25 //< The incoming feature file is invalid.
   SANDCAT_ERROR_NO_UPDATE_INVALID,          //  26 //< The incoming no update packet is invalid.
   SANDCAT_ERROR_MSG_HEADER_INVALID,         //  27 //< The header of the incoming message is invalid.
   SANDCAT_ERROR_PROVISION_CERTS,            //  28 //< Failed to provision the LTE modem with sandcat certificates.
   SANDCAT_ERROR_AES,                        //  29 //< Failed to perform AES operation.
   SANDCAT_ERROR_AWS_FOTA_INIT,              //  30 //< Failed to initialize AWS FOTA services.
   SANDCAT_ERROR_AWS_FOTA,                   //  31 //< AWS FOTA library failed during operation.
   SANDCAT_ERRORS
};

// The events triggered by the sandcat module during operation. These event must be handled by the main application.
enum SANDCAT_EVT
{
   SANDCAT_EVT_RESET_PREPARE,
   SANDCAT_EVT_FLASH_ERASE_PAGE,
   SANDCAT_EVT_FLASH_WRITE,
   SANDCAT_EVT_DONE,
   SANDCAT_EVT
};

// The arguments that get passed to the sandcat event handler during the above events.
union SANDCAT_EVT_ARGS
{
   struct
   {
      uint32_t address;
   } flash_erase_page_args;
   struct
   {
      const void* data;
      uint32_t address;
      uint32_t size;
   } flash_write_args;
   struct
   {
      uint8_t error_code;
   } done_args;
};

// Version structure to be used to identify the version of the main application.
struct SANDCAT_VERSION
{
   uint16_t release;
   uint16_t major;
   uint16_t minor;
};

// Initialization structure to be populated and used to initialize sandcat by the main applicaiotn.
struct SANDCAT_INIT
{
   struct SANDCAT_VERSION application_version;
   uint32_t product_id;
   uint32_t (*evt_handler)(enum SANDCAT_EVT evt, union SANDCAT_EVT_ARGS* args);
};

/// Initialize the sandcat library. Must be called before and other sandcat functions.
/// Feature states like 'purchased', 'toggles', and 'enabled' can be checked immediatly
/// after calling sandcat_init(). Only needs to be called once per power-cycle.
/// @param [init] pointer to an SANDCAT_INIT structure.
/// @return SANDCAT_ERROR code with the results of the initialization.
enum SANDCAT_ERROR sandcat_init(struct SANDCAT_INIT* init);

/// Initialize the LTE services within the sandcat library. Must be called after sandcat_init()
/// and before sandcat_execute(). A live LTE connection must be present
/// before calling sandcat_lte_init(). Only needs to be called once per power-cycle.
/// @return SANDCAT_ERROR code with the result of the initialization.
enum SANDCAT_ERROR sandcat_lte_init(void);

/// Performs obvious server communications, provisioning and feature updating. sandcat_init()
/// and sandcat_lte_init() must be called before sandcat_execute() is called. sancat_execute()
/// only adds work to its internal work queue and so it IS safe to call sandcat_execute() at
/// interrupt level priority.
/// @return SANDCAT_ERROR code with the results of the execution.
enum SANDCAT_ERROR sandcat_execute(void);

/// Check to see whether or not sandcat is currently executing. sandcat_execute() should not
/// be called while an execution is already takikng place.
/// @return true if sandcat is currently executing, false otherwise.
bool sandcat_executing(void);

/// Check to see whether a feature is purchased or not.
/// @param [feature] The feature ID representing the feature to check. Same ID as in the obvious portal.
/// @return true if the feature is purchased, false otherwise.
bool sandcat_is_feature_purchased(int feature);

/// Check to see whether a feature is toggled or not.
/// @param [feature] The feature ID representing the feature to check. Same ID as in the obvious portal.
/// @return true if the feature is toggled ON, false otherwise.
bool sandcat_is_feature_toggled(int feature);

/// Check to see whether a feature is enabled or not.
/// @param [feature] The feature ID representing the feature to check. Same ID as in the obvious portal.
/// @return true if the feature is enabled, false otherwise.
bool sandcat_is_feature_enabled(int feature);

/// Inform the sandcat library that its requested flash operation is complete. The sandcat will request
/// operations during execution via the sandcat event handler that the main application must perform.
/// Call sandcat_flash_operation_complete() after the reqeusted flash operation is complete with the
/// success or failure of the operation.
/// @param [success] Should be boolean true is the flash operation was successfull, false otherwise.
void sandcat_flash_operation_complete(bool success);

#if defined(__cplusplus)
   }
#endif

#endif // !defined(SANDCAT_H_)

