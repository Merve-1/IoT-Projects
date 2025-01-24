
/*
 * PWM_program.c
 *
 * Created: 5/25/2024 11:55:05 PM
 *  Author: NotFound
 */ 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "PWM_interface.h"
#include "PWM_register.h"


void PWM_voidInitChannel_0(void)
{
	// Select Mode = fast PWM Mode
	SET_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);
	
	// Select Non Inverting PWM
	CLR_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
}


void PWM_voidInitChannel_1A(void)
{
	// Select Mode = Fast PWM Mode(14)
	CLR_BIT(TCCR1A_REG,WGM10);
	SET_BIT(TCCR1A_REG,WGM11);
	SET_BIT(TCCR1B_REG,WGM12);
	SET_BIT(TCCR1B_REG,WGM13);
	
	// Select Non Inverting Mode
	CLR_BIT(TCCR1A_REG,COM1A0);
	SET_BIT(TCCR1A_REG,COM1A1);
}


void PWM_voidGenerate_PWM_Channel_0(u8 copy_u8DutyCycle)
{
	if(copy_u8DutyCycle<=100)
	{
		// under condition non inverting fast PWM
		OCR0_REG = ((copy_u8DutyCycle*256)/100)-1;
		
		// Select Prescaler Value = 64
		SET_BIT(TCCR0_REG,CS00);
		SET_BIT(TCCR0_REG,CS01);
		CLR_BIT(TCCR0_REG,CS02);
	}
	else
	{
		// return Error state
	}
}


void PWM_voidGenerate_PWM_Channel_1A(u16 copy_u16Frequency_hz,f32 copy_f32DutyCycle)
{
	if(copy_f32DutyCycle<=100)
	{
		// under condition tick time 4 MS by setting prescaller 64
		ICR1_u16_REG = ((1000000UL/copy_u16Frequency_hz)/4)-1;
		
		// under condition non inverting fast PWM
		OCR1A_u16_REG = ((copy_f32DutyCycle*(ICR1_u16_REG+1))/100)-1;
		
		// Select Prescaler Value = 64
		SET_BIT(TCCR1B_REG,CS10);
		SET_BIT(TCCR1B_REG,CS11);
		CLR_BIT(TCCR1B_REG,CS12);
	}
	else
	{
		// return Error state
	}
}

void PWM_voidStopChannel_1A(void)
{
	// Clear the prescaler bits to stop the timer
	CLR_BIT(TCCR1B_REG, CS10);
	CLR_BIT(TCCR1B_REG, CS11);
	CLR_BIT(TCCR1B_REG, CS12);

	// Optionally, reset the counter and output compare registers
	TCNT1_u16_REG = 0;
	OCR1A_u16_REG = 0;
}