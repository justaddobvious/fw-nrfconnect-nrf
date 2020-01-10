/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

/** @file
 * @brief Secure Services header.
 */

#ifndef SECURE_SERVICES_H__
#define SECURE_SERVICES_H__

/**
 * @defgroup secure_services Secure Services
 * @{
 * @brief Secure services available to the Non-Secure Firmware.
 *
 * The Secure Services provide access to functionality controlled by the
 * Secure Firmware.
 */

#include <stddef.h>
#include <zephyr/types.h>
#include <fw_info.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Request a system reboot from the Secure Firmware.
 *
 * Rebooting is not available from the Non-Secure Firmware.
 */
void spm_request_system_reboot(void);


/** Request a random number from the Secure Firmware.
 *
 * This provides a True Random Number from the on-board random number generator.
 *
 * @note Currently, the RNG hardware is run each time this is called. This
 *       spends significant time and power.
 *
 * @param[out] output  The random number. Must be at least @c len long.
 * @param[in]  len     The length of the output array. Currently, @c len must be
 *                     144.
 * @param[out] olen    The length of the random number provided.
 *
 * @retval 0        If successful.
 * @retval -EINVAL  If @c len is invalid. Currently, @c len must be 144.
 */
int spm_request_random_number(u8_t *output, size_t len, size_t *olen);


/** Request a read operation to be executed from Secure Firmware.
 *
 * @param[out] destination Pointer to destination array where the content is
 *                         to be copied.
 * @param[in]  addr        Address to be copied from.
 * @param[in]  len         Number of bytes to copy.
 *
 * @retval 0        If successful.
 * @retval -EINVAL  If destination is NULL, or if len is <= 0.
 * @retval -EPERM   If source is outside of allowed ranges.
 */
int spm_request_read(void *destination, u32_t addr, size_t len);

/** Search for the firmware_info structure in firmware image located at address.
 *
 * @param[in]   firmware_address Address where firmware image is stored.
 * @param[out]  info		 Pointer to where found info is stored.
 *
 * @retval 0        If successful.
 * @retval -EINVAL  If info is NULL.
 * @retval -EFAULT  If no info is found.
 */
int spm_firmware_info(u32_t fw_address, struct fw_info *info);

#define SPM_AES_ENCRYPT 1 // TODO: Pull the define for MBEDTLS_AES_ENCRYPT from mbedtls/aes.h
#define SPM_AES_DECRYPT 0 // TODO: Pull the define for MBEDTLS_AES_DECRYPT from mbedtls/aes.h

typedef struct
{
   int nr;              /*!<  number of rounds  */
   uint32_t *rk;        /*!<  AES round keys    */
   uint32_t buf[68];    /*!<  unaligned data    */
}
spm_aes_context;

typedef struct
{
   spm_aes_context *ctx;
   int mode;
   const unsigned char input[16];
   unsigned char output[16];
}
spm_aes_crypt_ecb_args;

typedef struct
{
   spm_aes_context *ctx;
   int mode;
   size_t length;
   unsigned char iv[16];
   const unsigned char *input;
   unsigned char *output;
}
spm_aes_crypt_cbc_args;

typedef struct
{
   spm_aes_context *ctx;
   int mode;
   size_t length;
   size_t *iv_off;
   unsigned char iv[16];
   const unsigned char *input;
   unsigned char *output;
}
spm_aes_crypt_cfb128_args;

typedef struct
{
   spm_aes_context *ctx;
   int mode;
   size_t length;
   unsigned char iv[16];
   const unsigned char *input;
   unsigned char *output;
}
spm_aes_crypt_cfb8_args;

typedef struct
{
   spm_aes_context *ctx;
   size_t length;
   size_t *nc_off;
   unsigned char nonce_counter[16];
   unsigned char stream_block[16];
   const unsigned char *input;
   unsigned char *output;
}
spm_aes_crypt_ctr_args;

void spm_aes_init(spm_aes_context *aes);

void spm_aes_free(spm_aes_context *aes);

int spm_aes_setkey_enc(spm_aes_context *aes, const unsigned char *key, unsigned int keybits);

int spm_aes_setkey_dec(spm_aes_context *aes, const unsigned char *key, unsigned int keybits);

int spm_aes_crypt_ecb(spm_aes_crypt_ecb_args *args);

int spm_aes_crypt_cbc(spm_aes_crypt_cbc_args *args);

int spm_aes_crypt_cfb128(spm_aes_crypt_cfb128_args *args);

int spm_aes_crypt_cfb8(spm_aes_crypt_cfb8_args *args);

int spm_aes_crypt_ctr(spm_aes_crypt_ctr_args *args);

void spm_aes_encrypt(spm_aes_context *ctx, const unsigned char input[16], unsigned char output[16]);

void spm_aes_decrypt(spm_aes_context *ctx, const unsigned char input[16], unsigned char output[16]);

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* SECURE_SERVICES_H__ */
