
/*
 * SRVM_program.c
 *
 * Created: 5/26/2024 12:05:16 PM
 *  Author: NotFound
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "PWM_interface.h"

/* HAL */
#include "SRVM_interface.h"


void SRVM_voidInit(void)
{
	// set OC1A as Output pin
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);

	/* PWM init ch1 at pwm mode 14 */
	PWM_voidInitChannel_1A();
}


void SRVM_voidOn(u8 copy_u8Angle)
{
	f32 local_f32Duty = (((copy_u8Angle + 90)/180.0)*5) + 5;

	/* Set pwm fre. = 50, duty cycle between 5 : 10 depend on desired angle[0 : 180] */
	PWM_voidGenerate_PWM_Channel_1A(local_f32Duty, SRVM_DESIRED_FREQUENCY);
}


void SRVM_voidOff(void)
{
	/* PWM ch1 stop */
	PWM_voidStopChannel_1A();
}

