
/*
 * EEPROM_program.c
 *
 * Created: 5/28/2024 11:20:06 AM
 *  Author: NotFound
 */ 


/* UTILES LEB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL  */

/* HAL   */
#include "EEPROM_interface.h"
#include "EEPROM_register.h"


#include <avr/io.h>

void EEPROM_writeByte(u16 address, u8 data) {
	// Wait for completion of previous write
	while (EECR & (1 << EEWE));
	
	// Set up address and data registers
	EEAR = address;
	EEDR = data;
	
	// Write logical one to EEMWE
	EECR |= (1 << EEMWE);
	
	// Start eeprom write by setting EEWE
	EECR |= (1 << EEWE);
}

u8 EEPROM_readByte(u16 address) {
	// Wait for completion of previous write
	while (EECR & (1 << EEWE));
	
	// Set up address register
	EEAR = address;
	
	// Start eeprom read by writing EERE
	EECR |= (1 << EERE);
	
	// Return data from data register
	return EEDR;
}

void EEPROM_writeString(u16 address, const char* data) {
	while (*data) {
		EEPROM_writeByte(address++, *data++);
	}
	EEPROM_writeByte(address, '\0'); // Null terminate the string in EEPROM
}

void EEPROM_readString(u16 address, char* buffer, u8 length) {
	u8 i;
	for (i = 0; i < length; i++) {
		buffer[i] = EEPROM_readByte(address++);
		if (buffer[i] == '\0') {
			break;
		}
	}
	buffer[length - 1] = '\0'; // Ensure buffer is null-terminated
}

void EEPROM_clear(void) {
	for (u16 address = 0; address < 1024; ++address) {
		EEPROM_writeByte(address, 0xFF); // Set each byte to 0xFF (commonly used to denote cleared EEPROM)
	}
}