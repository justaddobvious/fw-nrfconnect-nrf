/*
 * `
 * Copyright (c) 2018 Nordic Semiconductor ASA.
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

#include <spm.h>
#include <zephyr.h>
#include <cipher.h>
#include <cmac.h>
#include <mbedtls/error.h>

/*
 * Example code for a Secure Partition Manager application.
 * The application uses the SPM to set the security attributions of
 * the MCU resources (Flash, SRAM and Peripherals). It uses the core
 * TrustZone-M API to prepare the MCU to jump into Non-Secure firmware
 * execution.
 *
 * The following security configuration for Flash and SRAM is applied:
 *
 *                FLASH
 *  1 MB  |---------------------|
 *        |                     |
 *        |                     |
 *        |                     |
 *        |                     |
 *        |                     |
 *        |     Non-Secure      |
 *        |       Flash         |
 *        |                     |
 * 256 kB |---------------------|
 *        |                     |
 *        |     Secure          |
 *        |      Flash          |
 *  0 kB  |---------------------|
 *
 *
 *                SRAM
 * 256 kB |---------------------|
 *        |                     |
 *        |                     |
 *        |                     |
 *        |     Non-Secure      |
 *        |    SRAM (image)     |
 *        |                     |
 * 128 kB |.................... |
 *        |     Non-Secure      |
 *        |  SRAM (BSD Library) |
 *  64 kB |---------------------|
 *        |      Secure         |
 *        |       SRAM          |
 *  0 kB  |---------------------|
 */


void print_hex(unsigned char* buf, uint16_t len)
{
   for (int i = 0; i < len; i++)
      if (buf[i] > 0x0F)
         printk("%X ", buf[i]);
      else
         printk("0%X ", buf[i]);
}


void main(void)
{
   int err;
   char err_str[512];
   mbedtls_cipher_context_t ctx;
   const mbedtls_cipher_info_t* cipher_info;
   unsigned char key[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
   unsigned char input[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
   unsigned char output[16] = {0};

   printk("Key: ");
   print_hex(key, sizeof(key));
   printk("\nInput: ");
   print_hex(input, sizeof(input));
   printk("\nOutput: ");
   print_hex(output, sizeof(output));
   printk("\n");
   
   cipher_info = mbedtls_cipher_info_from_type(MBEDTLS_CIPHER_AES_128_ECB);
   if (cipher_info == NULL)
      printk("cipher_info == NULL\n");
   else
      printk("Successfully got cipher info\n");

   printk("cipher type: %d, cipher mode: %d, key bitlen: %d, iv size: %d, blocksize: %d\n", cipher_info->type, cipher_info->mode, cipher_info->key_bitlen, cipher_info->iv_size, cipher_info->block_size);
   
   //mbedtls_cipher_init(&ctx);
   //err = mbedtls_cipher_setup(&ctx, cipher_info);


   err = mbedtls_cipher_cmac(cipher_info, key, 16, input, 16, output);

   if (err)
      printk("Error with mbedtls_cipher_cmac: %d\n", err);
   else
      printk("Successfully got cmac\n");

   printk("Output: ");
   print_hex(output, sizeof(output));
   printk("\n");

   k_sleep(1000000);

	spm_config();
	spm_jump();
}
