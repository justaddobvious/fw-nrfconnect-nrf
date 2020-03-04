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
//         -+nMMMMMMMMNNNmmNmmmdmmmmmmmmmmdhhhhddmmddhhhhhdmmNm+:
//         .sMMMMMMNMMNNmmmmmmmdddddddhhhhyyyyyyyyyyyyyyyyydmmm/`
//          yMMMMMMNNNNmmmmmmddddhhhhhhhhhhssssso+syyyhhhddhddm+  
//         .dMMMMMMNNNNmmNmdmddhddddhhhhhhhhysyyys+oyyhhddmdddms`  
//        -/NMMMMMMMMNNNmdhhddhhhhdddhhhhhhyyssyyyyosyyhdmmmddmm:       
//        `/MMMMMMMMNNNNmhyshyyhhdmmdoshdhyyyssyyyhyyhhddddddddds.    
//
///////////////////////////////////////////////////////////////////////


#include "ocelot_feature.h"

#include <device.h>
#include <dk_buttons_and_leds.h>
#include <flash.h>
#include <limits.h>
#include <lte_lc.h>
#include <sandcat.h> // Obvious header.
#include <secure_services.h>
#include <stdio.h>
#include <string.h>
#include <uart.h>
#include <zephyr.h>


#define MAIN_OBVIOUS_DELAY                  2000            // A delay for starting the first execution of obvious in milliseconds.
#define MAIN_OBVIOUS_PERIOD                 30000           // The period at which obvious should connect to its servers and perform updates in milliseconds. LTE must be live.
#define MAIN_MAX_OBVIOUS_RETRIES            5               // The max number of tries for executing obvious immediatly after a failure. After retrying, give up until next interval.
#define MAIN_LED_BLINK_PERIOD               50              // The period for an LED blinking "feature" that obvious can enable/disable.


// TODO: Fill in your product ID from the obvious portal here:
static const uint32_t main_product_id = // ENTER PRODUCT ID HERE //                   // The product ID that corresponds to and obvious product.
// TODO: Fill in your application version here:
static const struct SANDCAT_VERSION main_application_version =    // Application version for obvious. This helps obvious determine when firmware updates are needed.
{
   .release = // ENTER RELEASE VERSION NUMBER HERE //
   .major = // ENTER MAJOR VERSION NUMBER HERE //
   .minor = // ENTER MINOR VERSION NUMBER HERE //
};
struct k_timer main_obvious_timer;                          // Timer structure for running obvious at regular intervals.
static uint8_t main_obvious_retries;                        // A retry counter to track the number of times obvious execution is attempted immediately after a failure.
static struct device* main_flash_device;                    // Flash device to provide flash read/write functionality for obvious.
struct k_timer main_led_timer;                              // Timer structure for the LED blinking feature.
struct k_work main_led_work;                                // Work structure for the LED blinking feature.
static uint8_t main_led_pattern;                            // Holds the current pattern of the LED blink feature.
static uint8_t main_led_blink_state;                        // Holds the current state of the LED blink feature.


///////////////////////////////////////////////////////////////////////
// The timer handler for running obvious at regualr intervals.
///////////////////////////////////////////////////////////////////////
static void main_obvious_timer_handler(struct k_timer* timer);

///////////////////////////////////////////////////////////////////////
// The timer handler for submitting the blink LED feature work to the
// system workqueue.
///////////////////////////////////////////////////////////////////////
static void main_led_timer_handler(struct k_timer* timer);

///////////////////////////////////////////////////////////////////////
// The work handler for running the LED blink feature.
///////////////////////////////////////////////////////////////////////
static void main_led_work_handler(struct k_work* work);

///////////////////////////////////////////////////////////////////////
// Flash implimentation for erasing a compelte page of flash. This is
// needed for obvious to erase flash within its flash region.
///////////////////////////////////////////////////////////////////////
static bool main_flash_erase_page(uint32_t address);

///////////////////////////////////////////////////////////////////////
// Flash implimentation for writing to flash. This is needed for
// obvious to write to flash within its flash region.
///////////////////////////////////////////////////////////////////////
static uint32_t main_flash_write(void const* data, uint32_t address, uint32_t size);

///////////////////////////////////////////////////////////////////////
// The event handler for obvious. Requests for flash operations,
// restart warnings, and error reporting will come through here.
///////////////////////////////////////////////////////////////////////
static uint32_t main_sandcat_evt_handler(enum SANDCAT_EVT evt, union SANDCAT_EVT_ARGS* args);

///////////////////////////////////////////////////////////////////////
// Function for configuring the LTE modem and connecting to the LTE
// network;
///////////////////////////////////////////////////////////////////////
static void main_modem_configure(void);


void main(void)
{
   enum SANDCAT_ERROR sandcat_error;
   struct SANDCAT_INIT sandcat_init_struct;

   printk("MAIN: Obvious LTE Example Started\n");

   // Start main flash device.
   printk("MAIN: Binding main_flash_device... ");
   main_flash_device = device_get_binding(DT_FLASH_DEV_NAME);
   
   if (!main_flash_device)
   {
      printk("Unable to find flash device.\n");
      return;
   }

   printk("COMPLETE\n");

   // Initialize sandcat.
   printk("MAIN: Initializing sandcat... ");
   sandcat_init_struct.application_version = main_application_version;
   sandcat_init_struct.product_id = main_product_id;
   sandcat_init_struct.evt_handler = main_sandcat_evt_handler;
   sandcat_error = sandcat_init(&sandcat_init_struct);

   if (sandcat_error != SANDCAT_SUCCESS)
   {
      printk("ERROR: %d\n", sandcat_error);
      return;
   }

   printk("COMPLETE\n");

   // Initialize the LEDs for the LED blink feature and set them to an initial state.
   dk_leds_init();
   dk_set_leds_state(0x00, DK_ALL_LEDS_MSK);
   k_work_init(&main_led_work, main_led_work_handler);
   k_timer_init(&main_led_timer, main_led_timer_handler, NULL);

   if (sandcat_is_feature_enabled(16))
   {
      printk("MAIN: Starting LED blink feature...\n");
      k_timer_start(&main_led_timer, K_MSEC(MAIN_LED_BLINK_PERIOD), K_MSEC(MAIN_LED_BLINK_PERIOD));
   }
   
   // Configure modem and connect to LTE network. 
   main_modem_configure();

   // Initialize sandcat LTE services. MUST be connected to LTE network before calling this.
   printk("MAIN: Initializing sandcat LTE services... ");
   sandcat_error = sandcat_lte_init();

   if (sandcat_error != SANDCAT_SUCCESS)
   {
      printk("ERROR: %d\n", sandcat_error);
      return;
   }

   printk("COMPLETE\n");

   // Initialize and start the timer for obvious operations.
   k_timer_init(&main_obvious_timer, main_obvious_timer_handler, NULL);
   k_timer_start(&main_obvious_timer, K_MSEC(MAIN_OBVIOUS_DELAY), K_MSEC(MAIN_OBVIOUS_PERIOD));

   // Everything is running off timers or in threads from here so return from main thread. 
   return;
}

///////////////////////////////////////////////////////////////////////
// An error handler for the sockets module. Needed for LTE operation.
// Left blank for this example.
///////////////////////////////////////////////////////////////////////
void bsd_recoverable_error_handler(uint32_t err)
{
   printk("bsdlib recoverable error: %u\n", err);
}

///////////////////////////////////////////////////////////////////////
// An error handler for the sockets module. Needed for LTE operation.
// Left blank for this example.
///////////////////////////////////////////////////////////////////////
void bsd_irrecoverable_error_handler(uint32_t err)
{
   printk("bsdlib irrecoverable error: %u\n", err);

   __ASSERT_NO_MSG(false);
}

static void main_led_timer_handler(struct k_timer* timer)
{
   k_work_submit(&main_led_work);
}

static void main_led_work_handler(struct k_work* work)
{
   switch (main_led_blink_state)
   {
      case 0x00:
         main_led_pattern = DK_LED1_MSK;
         main_led_blink_state++;
         break;
         
      case 0x01:
         main_led_pattern = DK_LED1_MSK | DK_LED2_MSK;
         main_led_blink_state++;
         break;
         
      case 0x02:
         main_led_pattern = DK_LED1_MSK | DK_LED2_MSK | DK_LED4_MSK;
         main_led_blink_state++;
         break;
         
      case 0x03:
         main_led_pattern = DK_LED1_MSK | DK_LED2_MSK | DK_LED4_MSK | DK_LED3_MSK;
         main_led_blink_state++;
         break;

      case 0x04:
         main_led_pattern = DK_LED2_MSK | DK_LED4_MSK | DK_LED3_MSK;
         main_led_blink_state++;
         break;

      case 0x05:
         main_led_pattern = DK_LED4_MSK | DK_LED3_MSK;
         main_led_blink_state++;
         break;

      case 0x06:
         main_led_pattern = DK_LED3_MSK;
         main_led_blink_state++;
         break;

      case 0x07:
         main_led_pattern = 0;
         main_led_blink_state = 0x00;
         break;

      default:
         // Should not happen.
         break;
   }

   dk_set_leds(main_led_pattern & 0x0F);
}

static void main_obvious_timer_handler(struct k_timer* timer)
{
   if (!sandcat_executing())
      sandcat_execute();
}

static bool main_flash_erase_page(uint32_t address)
{
   int err;

   err = flash_write_protection_set(main_flash_device, false);
   if (err)
   {
      printk("ERROR: in main_flash_write_erase_page. Unable to disable flash write protection. Error %d\n", err);
      sandcat_flash_operation_complete(false);
      return false;
   }

   err = flash_erase(main_flash_device, address, DT_FLASH_ERASE_BLOCK_SIZE);
   if (err)
   {
      printk("ERROR: in main_flash_erase_page. Unable to erase page at address %x. Error %d\n", address, err);
      sandcat_flash_operation_complete(false);
      return false;
   }

   err = flash_write_protection_set(main_flash_device, true);
   if (err)
   {
      printk("ERROR: in main_flash_erase_page. Unable to enable flash write protection. Error %d\n", err);
      sandcat_flash_operation_complete(false);
      return false;
   }

   sandcat_flash_operation_complete(true);
   return true;
}

static uint32_t main_flash_write(void const* data, uint32_t address, uint32_t size)
{
   int err;

   err = flash_write_protection_set(main_flash_device, false);
   if (err)
   {
      printk("ERROR: in main_flash_write. Unable to disable flash write protection. Error %d\n", err);
      sandcat_flash_operation_complete(false);
      return 0;
   }

   err = flash_write(main_flash_device, address, data, (size_t)size);
   if (err)
   {
      printk("ERROR: in main_flash_write. Unable to write flash data. Error %d\n", err);
      sandcat_flash_operation_complete(false);
      return 0;
   }

   err = flash_write_protection_set(main_flash_device, true);
   if (err)
   {
      printk("ERROR: in main_flash_device. Unable to enable flash write protection. Error %d\n", err);
      sandcat_flash_operation_complete(false);
      return 0;
   }

   sandcat_flash_operation_complete(true);
   return size;
}

static uint32_t main_sandcat_evt_handler(enum SANDCAT_EVT evt, union SANDCAT_EVT_ARGS* args)
{
   switch (evt)
   {
      case SANDCAT_EVT_RESET_PREPARE:
         return 0;

      case SANDCAT_EVT_FLASH_ERASE_PAGE:
         return main_flash_erase_page(args->flash_erase_page_args.address);

      case SANDCAT_EVT_FLASH_WRITE:
         return main_flash_write(args->flash_write_args.data, args->flash_write_args.address, args->flash_write_args.size);

      case SANDCAT_EVT_DONE:
         if (args->done_args.error_code == SANDCAT_SUCCESS)
         {
            // Sandcat executed successfully.
            printk("MAIN: Sandcat finished executing successfully\n");

            main_obvious_retries = 0;
         }
         else
         {
            // Sandcat FAILED to execute.
            printk("MAIN: Sandcat finished executing UNsuccessfully. Sandcat Error Code: %d\n", args->done_args.error_code);

            main_obvious_retries++;

            if (main_obvious_retries < MAIN_MAX_OBVIOUS_RETRIES)
            {
               printk("MAIN: Sandcat execution failed. Retrying. Current retry count: %d\n", main_obvious_retries);

               sandcat_execute();
            }
            else
            {
               printk("MAIN: Sandcat execution failed after %d retries. Try again later :(\n", main_obvious_retries);

               main_obvious_retries = 0;
            }
         }

         break;

      default:
         // Better not happen!
         break;
   }

   return 0;
}

static void main_modem_configure(void)
{
   if (IS_ENABLED(CONFIG_LTE_AUTO_INIT_AND_CONNECT))
   {
      /* Do nothing, modem is already turned on
       * and connected.
       */
   }
   else
   {
      int err;

      printk("LTE Link Connecting ...");
      err = lte_lc_init_and_connect();
      __ASSERT(err == 0, "LTE link could not be established.");
      printk("CONNECTED\n");
   }
}
