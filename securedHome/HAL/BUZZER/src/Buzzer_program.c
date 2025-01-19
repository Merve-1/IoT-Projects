
/*
 * Buzzer_program.c
 *
 * Created: 4/10/2024 1:46:29 PM
 *  Author: NotFound
 */ 



/*UTILES LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "BUZZER_interface.h"

void BUZZER_voidInit(u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId) {
	// Set the direction of the buzzer pin as output
	DIO_voidSetPinDirection(copy_u8BuzzerPortId, copy_u8BuzzerPinId, DIO_PIN_OUTPUT);
}

void BUZZER_voidTurnOn(u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId) {
	// Set the value of the buzzer pin to high to turn it on
	DIO_voidSetPinValue(copy_u8BuzzerPortId, copy_u8BuzzerPinId, DIO_PIN_HIGH);
}

void BUZZER_voidTurnOff(u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId) {
	// Set the value of the buzzer pin to low to turn it off
	DIO_voidSetPinValue(copy_u8BuzzerPortId, copy_u8BuzzerPinId, DIO_PIN_LOW);
}

void BUZZER_voidToggle(u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId) {
	// Toggle the state of the buzzer pin
	DIO_voidTogglePinValue(copy_u8BuzzerPortId, copy_u8BuzzerPinId);
}