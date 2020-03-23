.. _obvious_example_app:

nRF9160: Obvious Example
########################


Overview
*********
This example shows how to integrate and use Obvious for managing embedded device features and performing 
firmware upgrades over the air. NOTE: The front-end and back-end LTE implimentation of Obvious is still 
incomplete at this time and so most of the 'Building and Running' steps cannot be done. These steps are
documented here in hopes that the intended implimentations can be completed in the future.

Requirements
************

* The following development board:

  * nRF9160 DK board (PCA10090)

* An Obvious portal account which can be signed up for at Obvious.xyz.
  
* Obviousutil which can be downlaoded via the Obvious portal at tools->cli. Use this CLI to flash your product key onto your device.

* nRF Connect Desktop

   * LTE Link Monitor app. Use this app to flash your certificate-privateKey pair onto the nRF9160 modem. Contact Obvious for certificates.

Building and running (REQUIRED FRONT-END IMPLIMENTATION INCOMPLETE)
*******************************************************************

1. First, create a new product in the Obvious portal after logging into your account on the obvous portal. Note the product ID that gets generated.
   This ID must be manually entered into the firmware source code in src/main.c of this example as the main_product_id variable before building. 
   Also note the product key that is generated with your product.

2. Next, in the Obvious portal, create a new feature for your new product then download your product file via the product file generator in the tools
   section of the portal. Add this file to the 'inc' directory of this example project.

3. Associate certificates with your device in the Obvious portal. Either:
   * Generate your own private key and certificate signing request. Then upload your certificate signing reqest to the Obvious
     portal and download the generated public certificate.
   * Have the Obvious portal generate you a certificate package including private key and public certificate.

4. Download the CA certificate from the Obvious portal.

5. Flash your certificates onto the nRF9160 modem.

  5.1 Build and flash the at_client example onto your device.
  5.2 Use the LTE Link Monitor App in nRF Connect Desktop to flash your private key, 
      public certificate, and CA certificate onto your device' modem using security tag: 3203381950. 
      pair onto the modem with the certificate manager.

6. Build and run the Obvious example next:

.. |sample path| replace:: :file:`samples/nrf9160/obvious`

.. include:: /includes/build_and_run_nrf9160.txt

7. Download obviousutil from the tools section of the Obvious portal and install it. Using obviousutil, flash you product key, found on the Obvious 
   portal, onto your device using the command: obviousutil init generate --key [your_product_key] --start-address [start_address]. For builds including
   FOTA, use 0x72000 for start_adress. For builds NOT including FOTA, use 0xFC000 for start_address.

Testing (REQUIRED BACK-END IMPLIMENTATION INCOMPLETE)
=====================================================

* Using the Obvious portal, enable the feature you created for your product. On the next connection interval the embedded device
  will recieve an updated feature file and the LEDs on the board will begin to blink.

* If you update the application version in src/main.c of this project, rebuild the project, and then upload build/zephyr/app_update.bin to the 
  portal as a new firmware, the device will update its firmware on the next connection interval.

Troubleshooting
===============


Dependencies
************

This sample uses the following libraries:

From |NCS|
   * :ref:`lib_aws_fota`
   * ``drivers/lte_link_control``
   * ``lib/obvious``
   * ``lib/modem_key_mgmt``
   * ``lib/dk_buttons_and_leds``

From nrfxlib
   * :ref:`nrfxlib:bsdlib`

From Zephyr
   * :ref:`MQTT <zephyr:networking_reference>`

In addition, it uses the following samples:

From |NCS|
   * :ref:`secure_partition_manager`
