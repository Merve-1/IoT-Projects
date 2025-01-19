/*
 * LED_program.c
 *
 * Created: 4/10/2024 10:15:20 AM
 *  Author: NotFo
 */ 


/*UTILES LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "LED_interface.h"
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//LED Drivers




void LED_voidInit(u8 led_port, u8 led_pin) {
	// Set the direction of the LED pin as output
	DIO_voidSetPinDirection(led_port, led_pin, DIO_PIN_OUTPUT);
}

void LED_voidTurnOn(u8 led_port, u8 led_pin) {
	// Set the value of the LED pin to high to turn it on
	DIO_voidSetPinValue(led_port, led_pin, DIO_PIN_HIGH);
}

void LED_voidTurnOff(u8 led_port, u8 led_pin) {
	// Set the value of the LED pin to low to turn it off
	DIO_voidSetPinValue(led_port, led_pin, DIO_PIN_LOW);
}

void LED_voidToggle(u8 led_port, u8 led_pin) {
	// Toggle the state of the LED pin
	DIO_voidTogglePinValue(led_port, led_pin);
}
