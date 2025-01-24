
/*
 * EEPROM_private.h
 *
 * Created: 5/28/2024 11:19:39 AM
 *  Author: NotFound
 */ 


#ifndef EEPROM_REGISTER_H
#define EEPROM_REGISTER_H

#include <avr/io.h>

// EEPROM Control Register
#ifndef EECR
#define EECR   _SFR_IO8(0x3F)
#endif

#ifndef EERE
#define EERE   0
#endif

#ifndef EEWE
#define EEWE   1
#endif

#ifndef EEMWE
#define EEMWE  2
#endif

// EEPROM Data Register
#ifndef EEDR
#define EEDR   _SFR_IO8(0x3D)
#endif

// EEPROM Address Register
#ifndef EEAR
#define EEAR   _SFR_IO16(0x3E)
#endif

#ifndef EEARL
#define EEARL  _SFR_IO8(0x3E)
#endif

#ifndef EEARH
#define EEARH  _SFR_IO8(0x3F)
#endif

#endif // EEPROM_REGISTER_H


