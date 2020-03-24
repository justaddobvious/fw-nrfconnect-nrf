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

/**@brief Sandcat error types. */
enum SANDCAT_ERROR
{
   SANDCAT_SUCCESS,                          //  0  /**< Operation completed successfully. */
   SANDCAT_ERROR_INTERNAL,                   //  1  /**< An internal error has occured. */
   SANDCAT_ERROR_NO_INIT,                    //  2  /**< sandcat_exeute() was called before sandcat_init() and sandcat_lte_init() were called. */
   SANDCAT_ERROR_NULL,                       //  3  /**< A pointer parameter is set to NULL that should be set to a valid memory location. */
   SANDCAT_ERROR_ALIGN,                      //  4  /**< A pointer parameter is set to a location that is not memory alligned as it should be. */
   SANDCAT_ERROR_RANGE,                      //  5  /**< A pointer parameter is set to a value outside the appropriate range. */
   SANDCAT_ERROR_WRITE,                      //  6  /**< A flash write error has occured. */ 
   SANDCAT_ERROR_FILE_OPEN,                  //  7  /**< Failed to open internal obvious file for writing. */
   SANDCAT_ERROR_EXECUTION_CONFLICT,         //  8  /**< sandcat_execute() was called while sandcat was already executing. */
   SANDCAT_ERROR_MQTT_CLIENT_INIT,           //  9  /**< Failed to initialize the sandcat MQTT client. */
   SANDCAT_ERROR_MQTT_CONNECT,               //  10 /**< Failed to connect to the obvious MQTT broker. */
   SANDCAT_ERROR_MQTT_INPUT,                 //  11 /**< Failed to recieve incoming MQTT packet. */
   SANDCAT_ERROR_MQTT_LIVE,                  //  12 /**< Failed to keep MQTT connection with obvious broker alive. */
   SANDCAT_ERROR_MQTT_CONNECTION_DROPPED,    //  13 /**< MQTT connection to obvious broker unexpectadly dropped. */
   SANDCAT_ERROR_MQTT_TIMEOUT,               //  14 /**< Sandcat timed out after sending MQTT message without receiving response. */
   SANDCAT_ERROR_MQTT_PUBLISH,               //  15 /**< Failed to publish MQTT message, either device details or provisioning response. */
   SANDCAT_ERROR_MQTT_SUBSCRIBE,             //  16 /**< Failed to subscribe to unique MQTT device topic with obvious broker. */
   SANDCAT_ERROR_MQTT_UNSUBSCRIBE,           //  17 /**< Failed to unsbscribe from unique MQTT device topic with obvious broker. */
   SANDCAT_ERROR_FDS_POLL,                   //  18 /**< Failed to poll FDS. */
   SANDCAT_ERROR_FDS_POLLNVAL,               //  19 /**< FDS poll is invalid. */
   SANDCAT_ERROR_FDS_POLLHUP,                //  20 /**< FDS poll hang up. */
   SANDCAT_ERROR_FDS_POLLERR,                //  21 /**< FDS poll error. */
   SANDCAT_ERROR_ENCODE_DEVICE_DETAILS,      //  22 /**< Failed to encode device details into MQTT message. */
   SANDCAT_ERROR_PROVISIONING_CMAC,          //  23 /**< Failed to get the device provisioning CMAC. */
   SANDCAT_ERROR_PRIVATE_CERT_INVALID,       //  24 /**< The incoming private certificate is invalid. */
   SANDCAT_ERROR_PUBLIC_CERT_INVALID,        //  25 /**< The incoming public certificate is invalid. */
   SANDCAT_ERROR_PROVISIONING_FILE_INVALID,  //  26 /**< The incoming provisioning file is invalid. */
   SANDCAT_ERROR_FEATURE_FILE_INVALID,       //  27 /**< The incoming feature file is invalid. */
   SANDCAT_ERROR_NO_UPDATE_INVALID,          //  28 /**< The incoming no update packet is invalid. */
   SANDCAT_ERROR_MSG_HEADER_INVALID,         //  29 /**< The header of the incoming message is invalid. */
   SANDCAT_ERROR_MISSING_CERTIFICATES,       //  30 /**< Failed to verify whether or not certificates are stored in modem. */
   SANDCAT_ERROR_STORE_CERTIFICATES,         //  31 /**< Failed to store a certificate in the modem. */
   SANDCAT_ERROR_DELETE_CERTIFICATES,        //  32 /**< Failed to delete a certificate in the modem. */
   SANDCAT_ERROR_AES,                        //  33 /**< Failed to perform AES operation. */
   SANDCAT_ERROR_AWS_FOTA_INIT,              //  34 /**< Failed to initialize AWS FOTA services. */
   SANDCAT_ERROR_AWS_FOTA,                   //  35 /**< AWS FOTA library failed during operation. */
   SANDCAT_ERRORS
};

/**@brief The events triggered by the sandcat module during operation. These event must be handled by the main application. */
enum SANDCAT_EVT
{
   SANDCAT_EVT_RESET_PREPARE,          /**< Obvious needs to reset the device to perform updates. Please prepare. */
   SANDCAT_EVT_FLASH_ERASE_PAGE,       /**< Obvious needs one of its flash pages erased. Please perform the erase. */
   SANDCAT_EVT_FLASH_WRITE,            /**< Obvious needs to write to its flash. Please perform the erase. */
   SANDCAT_EVT_DONE,                   /**< Obvious operations are complete. It is now safe to discontinue network radio operation. */
   SANDCAT_EVT
};

/**@brief The arguments that get passed to the sandcat event handler during the above events. */
union SANDCAT_EVT_ARGS
{
   struct
   {
      uint32_t address;          /**< The address of the flash page to be erased. */
   } flash_erase_page_args;   /**< The argument structure for a flash page erase event. */
   struct
   {
      const void* data;          /**< A pointer to the data to be written to flash. */
      uint32_t address;          /**< The address for the data to be written to in flash. */
      uint32_t size;             /**< The size of the data to be written to flash. */
   } flash_write_args;        /**< The argument structure for a flash write event. */
   struct
   {
      uint8_t error_code;        /**< An error code to report the success/failure of sandcat_execute(). */
   } done_args;               /**< The argument structure for the completion of sandcat_execute(). */
};

/**brief Version structure to be used to identify the version of the main application. */
struct SANDCAT_VERSION
{
   uint16_t release;    /**< The release version number of your application firmware. */
   uint16_t major;      /**< The major version number of your application firmware. */
   uint16_t minor;      /**< The minor version number of your application firmware. */
};

/**@brief Initialization structure to be populated and used to initialize sandcat by the main application. */
struct SANDCAT_INIT
{
   struct SANDCAT_VERSION application_version;     /**< The full version of your application firmware. */
   uint32_t product_id;          /**< The product ID associated with this product on the Obvious portal. */
   char* broker_hostname;    /**< The broker hostname to connect to. */
   uint32_t (*evt_handler)(enum SANDCAT_EVT evt, union SANDCAT_EVT_ARGS* args); /**< The event handler for obvious events. Must handle all sandcat event types. */
};

/** @brief Initialize the sandcat library. 
 *
 * Must be called before and other sandcat functions.
 * Feature states like 'purchased', 'toggles', and 'enabled' can be checked immediatly
 * after calling sandcat_init(). Only needs to be called once per power-cycle.
 *
 * @param [init] pointer to an SANDCAT_INIT structure.
 *
 * @return SANDCAT_ERROR code with the results of the initialization.
 */
enum SANDCAT_ERROR sandcat_init(struct SANDCAT_INIT* init);

/** @brief Initialize the LTE services within the sandcat library.
 *
 * Must be called after sandcat_init() and before sandcat_execute(). A live LTE
 * connection must be present before calling sandcat_lte_init(). Only needs to
 * be called once per power-cycle.
 *
 * @return SANDCAT_ERROR code with the result of the initialization.
 */
enum SANDCAT_ERROR sandcat_lte_init(void);

/** @brief Performs obvious server communications, provisioning and feature updating.
 *
 * sandcat_init() and sandcat_lte_init() must be called before sandcat_execute() is
 * called. sancat_execute() only adds work to its internal work queue and so it IS
 * safe to call sandcat_execute() at interrupt level priority.
 *
 * @return SANDCAT_ERROR code with the results of the execution.
 */
enum SANDCAT_ERROR sandcat_execute(void);

/** @brief Check to see whether or not sandcat is currently executing.
 *
 * sandcat_execute() should not be called while an execution is already takikng place.
 * 
 * @return true if sandcat is currently executing, false otherwise.
 */
bool sandcat_executing(void);

/** @brief Check to see whether a feature is purchased or not.
 *
 * @param [feature] The feature ID representing the feature to check. Same ID as in the obvious portal.
 *
 * @return true if the feature is purchased, false otherwise.
 */
bool sandcat_is_feature_purchased(int feature);

/** @brief Check to see whether a feature is toggled or not.
 * 
 * @param [feature] The feature ID representing the feature to check. Same ID as in the obvious portal.
 *
 * @return true if the feature is toggled ON, false otherwise.
 */
bool sandcat_is_feature_toggled(int feature);

/** @brief Check to see whether a feature is enabled or not.
 *
 * @param [feature] The feature ID representing the feature to check. Same ID as in the obvious portal.
 *
 * @return true if the feature is enabled, false otherwise.
 */
bool sandcat_is_feature_enabled(int feature);

/** @brief Inform the sandcat library that its requested flash operation is complete.
 *
 * The sandcat will request operations during execution via the sandcat event handler that the main
 * application must perform. Call sandcat_flash_operation_complete() after the reqeusted flash operation
 * is complete with the success or failure of the operation.
 *
 * @param [success] Should be boolean true is the flash operation was successfull, false otherwise.
 */
void sandcat_flash_operation_complete(bool success);

#if defined(__cplusplus)
   }
#endif

#endif // !defined(SANDCAT_H_)
