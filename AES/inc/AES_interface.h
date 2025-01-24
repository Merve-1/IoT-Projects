
/*
 * AES_interface.h
 *
 * Created: 5/29/2024 10:50:10 AM
 *  Author: NotFound
 */ 

#ifndef AES_INTERFACE_H
#define AES_INTERFACE_H

#include <stdint.h>

#define AES_BLOCK_SIZE 16

void AES_init(const u8 *key);
void AES_encrypt(const u8 *input, u8 *output);
void AES_decrypt(const u8 *input, u8 *output)

#endif // AES_INTERFACE_H
