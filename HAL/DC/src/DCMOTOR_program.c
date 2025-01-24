
/*
 * DCMOTOR_program.c
 *
 * Created: 5/24/2024 12:09:51 PM
 *  Author: NotFound
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "PWM_interface.h"
/* HAL */
#include "DCMOTOR_interface.h"
#include "DCMOTOR_config.h"


void DCMOTOR_voidInit(u8 copy_u8MotorId) {
	/* Initialize H-Bridge As Output Pins depending on motor id */
	switch(copy_u8MotorId) {
		case DCMOTOR_A:
		DIO_voidSetPinDirection(DCMOTOR_A_IN1_PORT, DCMOTOR_A_IN1_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCMOTOR_A_IN2_PORT, DCMOTOR_A_IN2_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCMOTOR_A_ENABLE_PORT, DCMOTOR_A_ENABLE_PIN, DIO_PIN_OUTPUT);
		break;
	}
}

void DCMOTOR_voidOn(u8 copy_u8MotorId, u8 copy_u8MotorDirection) {
	switch(copy_u8MotorId) {
		case DCMOTOR_A:
		switch(copy_u8MotorDirection) {
			case DCMOTOR_CLOCK_WISE:
			DIO_voidSetPinValue(DCMOTOR_A_IN1_PORT, DCMOTOR_A_IN1_PIN, DIO_PIN_HIGH);
			DIO_voidSetPinValue(DCMOTOR_A_IN2_PORT, DCMOTOR_A_IN2_PIN, DIO_PIN_LOW);
			break;
			case DCMOTOR_COUNTER_CLOCK_WISE:
			DIO_voidSetPinValue(DCMOTOR_A_IN1_PORT, DCMOTOR_A_IN1_PIN, DIO_PIN_LOW);
			DIO_voidSetPinValue(DCMOTOR_A_IN2_PORT, DCMOTOR_A_IN2_PIN, DIO_PIN_HIGH);
			break;
		}
		DIO_voidSetPinValue(DCMOTOR_A_ENABLE_PORT, DCMOTOR_A_ENABLE_PIN, DIO_PIN_HIGH);
		break;
	}
}

void DCMOTOR_voidOff(u8 copy_u8MotorId) {
	switch(copy_u8MotorId) {
		case DCMOTOR_A:
		DIO_voidSetPinValue(DCMOTOR_A_ENABLE_PORT, DCMOTOR_A_ENABLE_PIN, DIO_PIN_LOW);
		break;
	}
}
