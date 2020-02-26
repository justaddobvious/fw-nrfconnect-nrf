.. _obvious_example_app:

nRF9160: Obvious Example
########################


Overview
*********
This example shows how to integrate and use obvious for managing embedded device features and performing 
firmware upgrades over the air.

Requirements
************

* The following development board:

  * nRF9160 DK board (PCA10090)

* An obvious portal account which can be signed up for at obvious.xyz.
  
* obviousutil which can be downlaoded via the obvious portal at tools->cli. Use this CLI to flash your product key onto your device.

* nRF Connect Desktop

  * LTE Link Monitor app. Use this app to flash your certificate-privateKey pair onto the nRF9160 modem. Contact obvious for certificates.

Building and running
********************

1. First, create a new product after logging into your account on the obvous portal. Note the product ID; this ID must be manually entered in
   src/main.c of this example as the main_product_id variable before building.

2. Create a new feature for your new product then download your product file via the product file generator in the tools section 
   of the portal. Add this file to the 'inc' directory of this example project.

3. Flash your certificates onto the nRF9160 modem.

  3.1 Build and flash the at_client example onto your board. Use the LTE Link Monitor App in nRF Connect Desktop to flash your certificate-privateKey
      pair onto the modem with the certificate manager.

4 Build and run the obvious example next:

.. |sample path| replace:: :file:`samples/nrf9160/obvious`

.. include:: /includes/build_and_run_nrf9160.txt

5 Using obviousutil, flash you product key, found on the obvious portal, onto your device.

Testing
=======

* Using the obvious portal, enable the feature you created for your product. On the next connection interval the embedded device
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
