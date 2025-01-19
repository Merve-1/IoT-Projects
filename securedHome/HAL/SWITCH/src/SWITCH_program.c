/*
 * switch_program.c
 *
 * Created: 4/10/2024 10:14:05 AM
 *  Author: NotFound
 */ 

/*UTILES LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "SWITCH_interface.h"


// no need to use this 
void SWITCH_voidInit(u8 copy_u8switchPortId, u8 copy_u8switchPinId) {
    // Set the direction of the switch pin as input
    DIO_voidSetPinDirection(copy_u8switchPortId, copy_u8switchPinId, DIO_PIN_INPUT);
}

u8 SWITCH_u8GetState(u8 copy_u8switchPortId, u8 copy_u8switchPinId) {
    u8 switch_state;
    // Get the state of the switch pin
    DIO_voidGetPinValue(copy_u8switchPortId, copy_u8switchPinId, &switch_state);
    return switch_state;
}
