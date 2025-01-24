/*
 * LCD_program.c
 *
 * Created: 5/5/2024 9:56:07 PM
 *  Author: NotFound
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h" 

void LCD_voidInit (void){
	//Initialize LCD Pins As Output Pins
	DIO_voidSetPinDirection(LCD_RS_PORT, LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_RW_PORT, LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_E_PORT , LCD_E_PIN ,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D4_PORT, LCD_D4_PIN,DIO_PIN_OUTPUT);	
	DIO_voidSetPinDirection(LCD_D5_PORT, LCD_D5_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D6_PORT, LCD_D6_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D7_PORT, LCD_D7_PIN,DIO_PIN_OUTPUT);
	
	

	
	
	_delay_ms(35);
	// Function set command  
	// Set RS pin = 0 (command)
	DIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN , DIO_PIN_LOW);
	
	// Set RS pin = 0 (write)
	DIO_voidSetPinValue(LCD_RW_PORT, LCD_RW_PIN , DIO_PIN_LOW);
	
	PRV_voidWriteHalfPort(0b0010);
	
	//Enable Pulse // High => Low
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_LOW);
	
	LCD_voidSendCommand(0b00101000);
	_delay_us(45);	
	
	//Display on off Control (DisplayOn, Cursor on, Blink on)
	LCD_voidSendCommand(0b00001111);
	_delay_us(45);
		
	//Display clear 
	LCD_voidSendCommand(0b00000001);
	_delay_ms(2);
	
	//set Entry Mode (Increment on, Shift off)
	LCD_voidSendCommand(0b00000110);
	
	

}
void LCD_voidSendCommand(u8 copy_u8Cmnd){
	// Set RS pin = 0 (data/command)
	DIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN , DIO_PIN_LOW);
	
	// Set RW pin = 0 (write)
	DIO_voidSetPinValue(LCD_RW_PORT, LCD_RW_PIN , DIO_PIN_LOW);
	 
	//Write The Most 4 bits of data on Data Pins
	PRV_voidWriteHalfPort(copy_u8Cmnd>>4);
	
	//Enable Pulse // High => Low 
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_LOW);
	
	//Write The Least 4 bits of data on Data Pins 
	PRV_voidWriteHalfPort(copy_u8Cmnd);
	
	//Enable Pulse // High => Low
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_LOW);
	 
}

void LCD_voidDisplayChar(u8 copy_u8Data){
	// Set RS pin = 0 (data/command)
	DIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN , DIO_PIN_HIGH);
	
	// Set RW pin = 0 (write)
	DIO_voidSetPinValue(LCD_RW_PORT, LCD_RW_PIN , DIO_PIN_LOW);
	
	//Write The Most 4 bits of data on Data Pins
	PRV_voidWriteHalfPort(copy_u8Data>>4);
	
	//Enable Pulse // High => Low
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_LOW);
	
	//Write The Least 4 bits of data on Data Pins
	PRV_voidWriteHalfPort(copy_u8Data);
	
	//Enable Pulse // High => Low
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN, DIO_PIN_LOW);
}

void LCD_voidDisplayString(u8* copy_pu8String)
{
	if(copy_pu8String!=NULL)
	{
		u8 local_u8Counter=0;
		while(copy_pu8String[local_u8Counter]!='\0')
		{
			LCD_voidDisplayChar(copy_pu8String[local_u8Counter]);
			local_u8Counter++;
		}
	}
	else
	{
		// return Error state
	}
}

//void LCD_voidDisplayeNumber(u32 copy_u32Number);




// LCD_clear function
void LCD_voidClear(void) {
	// Set RS pin to command mode
	DIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_LOW);

	// Set RW pin to write mode
	DIO_voidSetPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);

	// Send clear command (0x01)
	LCD_voidSendCommand(0x01);

	// Short delay after sending the command
	_delay_ms(2); // Adjust delay as per LCD specifications
}



//void LCD_voidShift(u8 copy_u8shifttingDirection);

//void LCD_voidGoToSpecificPosition(u8 copy_u8LineNumber,u8 copy_u8Position);

static void PRV_voidWriteHalfPort(u8 copy_u8Value){
	if (1 == GET_BIT(copy_u8Value,0)){
		DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN, DIO_PIN_HIGH);
	}
	else{
		DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN, DIO_PIN_LOW);
	}
	if (1 == GET_BIT(copy_u8Value,1)){
		DIO_voidSetPinValue(LCD_D5_PORT,LCD_D5_PIN, DIO_PIN_HIGH);
	}
	else{
		DIO_voidSetPinValue(LCD_D5_PORT,LCD_D5_PIN, DIO_PIN_LOW);
	}
	if (1 == GET_BIT(copy_u8Value,2)){
		DIO_voidSetPinValue(LCD_D6_PORT,LCD_D6_PIN, DIO_PIN_HIGH);
	}
	else{
		DIO_voidSetPinValue(LCD_D6_PORT,LCD_D6_PIN, DIO_PIN_LOW);
	}
	if (1 == GET_BIT(copy_u8Value,3)){
		DIO_voidSetPinValue(LCD_D7_PORT,LCD_D7_PIN, DIO_PIN_HIGH);
	}
	else{
		DIO_voidSetPinValue(LCD_D7_PORT,LCD_D7_PIN, DIO_PIN_LOW);
	}
}
