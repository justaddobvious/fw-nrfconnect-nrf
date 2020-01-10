/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */
#include <zephyr.h>
#include <errno.h>
#include <cortex_m/tz.h>
#include <misc/reboot.h>
#include <misc/util.h>
#include <autoconf.h>
#include <secure_services.h>
#include <string.h>

#if USE_PARTITION_MANAGER
#include <pm_config.h>
#endif
#ifdef CONFIG_SPM_SERVICE_FIND_FIRMWARE_INFO
#include <fw_info.h>
#endif

/*
 * Secure Entry functions to allow access to secure services from non-secure
 * firmware.
 *
 * Note: the function will be located in a Non-Secure
 * Callable region of the Secure Firmware Image.
 */

#ifdef CONFIG_SPM_SERVICE_RNG
#ifdef MBEDTLS_CONFIG_FILE
#include MBEDTLS_CONFIG_FILE
#else
#include "mbedtls/config.h"
#endif /* MBEDTLS_CONFIG_FILE */

#include <mbedtls/platform.h>
#include <mbedtls/entropy_poll.h>
#endif /* CONFIG_SPM_SERVICE_RNG */

// TODO: Add define check for spm aes here
#include <mbedtls/aes.h>

int spm_secure_services_init(void)
{
	int err = 0;

#ifdef CONFIG_SPM_SERVICE_RNG
	mbedtls_platform_context platform_ctx = {0};
	err = mbedtls_platform_setup(&platform_ctx);
#endif
	return err;
}

#ifdef CONFIG_SPM_SERVICE_READ

#define FICR_BASE               NRF_FICR_S_BASE
#define FICR_PUBLIC_ADDR        (FICR_BASE + 0x204)
#define FICR_PUBLIC_SIZE        0xA1C
#define FICR_RESTRICTED_ADDR    (FICR_BASE + 0x130)
#define FICR_RESTRICTED_SIZE    0x8

struct read_range {
	u32_t start;
	size_t size;
};

__TZ_NONSECURE_ENTRY_FUNC
int spm_request_read(void *destination, u32_t addr, size_t len)
{
	static const struct read_range ranges[] = {
#ifdef PM_MCUBOOT_ADDRESS
		/* Allow reads of mcuboot metadata */
		{.start = PM_MCUBOOT_PAD_ADDRESS,
		 .size = PM_MCUBOOT_PAD_SIZE},
#endif
		{.start = FICR_PUBLIC_ADDR,
		 .size = FICR_PUBLIC_SIZE},
		{.start = FICR_RESTRICTED_ADDR,
		 .size = FICR_RESTRICTED_SIZE},
	};

	if (destination == NULL || len <= 0) {
		return -EINVAL;
	}

	for (size_t i = 0; i < ARRAY_SIZE(ranges); i++) {
		u32_t start = ranges[i].start;
		u32_t size = ranges[i].size;

		if (addr >= start && addr + len <= start + size) {
			memcpy(destination, (const void *)addr, len);
			return 0;
		}
	}

	return -EPERM;
}
#endif /* CONFIG_SPM_SERVICE_READ */

#ifdef CONFIG_SPM_SERVICE_REBOOT
__TZ_NONSECURE_ENTRY_FUNC
void spm_request_system_reboot(void)
{
	sys_reboot(SYS_REBOOT_COLD);
}
#endif /* CONFIG_SPM_SERVICE_REBOOT */


#ifdef CONFIG_SPM_SERVICE_RNG
__TZ_NONSECURE_ENTRY_FUNC
int spm_request_random_number(u8_t *output, size_t len, size_t *olen)
{
	int err;

	if (len != MBEDTLS_ENTROPY_MAX_GATHER) {
		return -EINVAL;
	}

	err = mbedtls_hardware_poll(NULL, output, len, olen);
	return err;
}
#endif /* CONFIG_SPM_SERVICE_RNG */

#ifdef CONFIG_SPM_SERVICE_FIND_FIRMWARE_INFO
__TZ_NONSECURE_ENTRY_FUNC
int spm_firmware_info(u32_t fw_address, struct fw_info *info)
{
	const struct fw_info *tmp_info;

	if (info == NULL) {
		return -EINVAL;
	}

	tmp_info = fw_info_find(fw_address);

	if (tmp_info != NULL) {
		memcpy(info, tmp_info, sizeof(*tmp_info));
		return 0;
	}

	return -EFAULT;
}
#endif

// TODO: Add define check for spm aes here
__TZ_NONSECURE_ENTRY_FUNC
void spm_aes_init(spm_aes_context *ctx)
{
   if (ctx == NULL) {
      // TODO: report error
   }

   mbedtls_aes_init((mbedtls_aes_context*)ctx);
}

__TZ_NONSECURE_ENTRY_FUNC
void spm_aes_free(spm_aes_context *ctx)
{
   if (ctx == NULL) {
      // TODO: report error
   }

   mbedtls_aes_free((mbedtls_aes_context*)ctx);
}

__TZ_NONSECURE_ENTRY_FUNC
int spm_aes_setkey_enc(spm_aes_context *ctx, const unsigned char *key, unsigned int keybits)
{
   //printk("spm_aes_setkey_enc()\n"); //!!

   int err;

   if (key == NULL) {
      // TODO: report error
   }

   if (keybits != 128 || keybits != 192 || keybits != 256) {
      // TODO: report error
   }

   //printk("spm_aes_setkey_enc(): before calling mbedtls_aes_setkey_enc\n"); //!!

   err = mbedtls_aes_setkey_enc((mbedtls_aes_context*)ctx, key, keybits);
   return err;
}

__TZ_NONSECURE_ENTRY_FUNC
int spm_aes_setkey_dec(spm_aes_context *ctx, const unsigned char *key, unsigned int keybits)
{
   int err;

   if (key == NULL) {
      // TODO: report error
   }

   if (keybits != 128 || keybits != 192 || keybits != 256) {
      // TODO: report error
   }

   err = mbedtls_aes_setkey_enc((mbedtls_aes_context*)ctx, key, keybits);
   return err;
}

__TZ_NONSECURE_ENTRY_FUNC
int spm_aes_crypt_ecb(spm_aes_crypt_ecb_args *args)
{
   int err;

   if (args->ctx == NULL) {
      // TODO: report error
   }

   err = mbedtls_aes_crypt_ecb((mbedtls_aes_context*)args->ctx, args->mode, args->input, args->output);
   return err;
}

// TODO: Add define check for spm aes cipher mode CBC here
__TZ_NONSECURE_ENTRY_FUNC
int spm_aes_crypt_cbc(spm_aes_crypt_cbc_args *args)
{
   int err;

   if (args->ctx == NULL || args->input == NULL || args->output == NULL) {
      // TODO: report error
   }

   err = mbedtls_aes_crypt_cbc((mbedtls_aes_context*)args->ctx, args->mode, args->length, args->iv, args->input, args->output);
   return err;
}

// TODO: Add define check for spm aes cipher mode CFB here
__TZ_NONSECURE_ENTRY_FUNC
int spm_aes_crypt_cfb128(spm_aes_crypt_cfb128_args *args)
{
   int err;

   if (args->ctx == NULL || args->input == NULL || args->output == NULL) {
      // TODO: report error
   }

   err = mbedtls_aes_crypt_cfb128((mbedtls_aes_context*)args->ctx, args->mode, args->length, args->iv_off, args->iv, args->input, args->output);
   return err;
}

__TZ_NONSECURE_ENTRY_FUNC
int spm_aes_crypt_cfb8(spm_aes_crypt_cfb8_args *args)
{
   int err;

   if (args->ctx == NULL || args->input == NULL || args->output == NULL) {
      // TODO: report error
   }

   err = mbedtls_aes_crypt_cfb8((mbedtls_aes_context*)args->ctx, args->mode, args->length, args->iv, args->input, args->output);
   return err;
}

// TODO: Add define check for cipher mode CTR here
__TZ_NONSECURE_ENTRY_FUNC
int spm_aes_crypt_ctr(spm_aes_crypt_ctr_args *args)
{
   int err;

   if (args->ctx == NULL || args->input == NULL || args->output == NULL) {
      // TODO: report error
   }

   err = mbedtls_aes_crypt_ctr((mbedtls_aes_context*)args->ctx, args->length, args->nc_off, args->nonce_counter, args->stream_block, args->input, args->output);
   return err;
}

__TZ_NONSECURE_ENTRY_FUNC
void spm_aes_encrypt(spm_aes_context *ctx, const unsigned char input[16], unsigned char output[16])
{
   if (ctx == NULL) {
      // TODO: report error
   }

   mbedtls_aes_encrypt((mbedtls_aes_context*)ctx, input, output);
}

__TZ_NONSECURE_ENTRY_FUNC
void spm_aes_decrypt(spm_aes_context *ctx, const unsigned char input[16], unsigned char output[16])
{
   if (ctx == NULL) {
      // TODO: report error
   }

   mbedtls_aes_decrypt((mbedtls_aes_context*)ctx, input, output);
}
