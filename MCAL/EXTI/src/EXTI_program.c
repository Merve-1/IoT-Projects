
/*
 * EXTI_program.c
 *
 * Created: 5/10/2024 5:24:47 PM
 *  Author: NotFound
 */ 

/* UTILES LIG */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "EXTI_interface.h"
#include "EXTI_register.h"


void EXTI_voidEnable(u8 copy_u8InterruptSource, u8 copy_u8TriggerEdge){
	//interrupt implementation for Port D Pin 2
	switch(copy_u8InterruptSource){
		case EXTI_INT0:
		switch(copy_u8TriggerEdge){
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR_REG, ISC00);
			SET_BIT(MCUCR_REG, ISC01);
			break;
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR_REG, ISC00);
			SET_BIT(MCUCR_REG, ISC01);
			break;
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_REG, ISC00);
			CLR_BIT(MCUCR_REG, ISC01);
			break;
			case EXTI_ANY_LOGIACAL_CHANGE:
			SET_BIT(MCUCR_REG, ISC00);
			CLR_BIT(MCUCR_REG, ISC01);
			break;
		}
		//Enable EXTI_0
		SET_BIT(GICR_REG, INT0);
		break;
		
		
	}
}
void EXTI_VoidDisable(u8 copy_u8InterruptSource){
	switch (copy_u8InterruptSource)
	{
		case EXTI_INT0:
		//Disable EXTI 0
		CLR_BIT(GICR_REG, INT0);
		break;
	}
}