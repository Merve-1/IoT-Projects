
/*
 * EEPROM_interface.h
 *
 * Created: 5/28/2024 11:19:19 AM
 *  Author: NotFound
 */ 



#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

#include "STD_TYPES.h"

void EEPROM_writeByte(u16 address, u8 data);
u8 EEPROM_readByte(u16 address);

void EEPROM_writeString(u16 address, const char* data);
void EEPROM_readString(u16 address, char* buffer, u8 length);
void EEPROM_clear(void); 


#endif // EEPROM_INTERFACE_H

