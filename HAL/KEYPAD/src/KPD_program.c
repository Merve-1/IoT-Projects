
/*
 * KPD_program.c
 *
 * Created: 5/6/2024 11:17:42 PM
 *  Author: NotFound
 */ 

//UTILES_LIB
#include "STD_TYPES.h"
#include "BIT_MATH.h"

//MCAL
#include "DIO_interface.h"

//HAL
#include "KPD_interface.h"
#include "KPD_config.h"



void KPD_voidInit(void){
	
	//Initialize KPD COLS pins As Output Pins
	DIO_voidSetPinDirection(KPD_COL0_PORT, KPD_COL0_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_COL1_PORT, KPD_COL1_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_COL2_PORT, KPD_COL2_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_COL3_PORT, KPD_COL3_PIN, DIO_PIN_OUTPUT);
	
	
	//Initialize KPD ROWS pins As Input Pins
	DIO_voidSetPinDirection(KPD_ROW0_PORT, KPD_ROW0_PIN, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KPD_ROW1_PORT, KPD_ROW1_PIN, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KPD_ROW2_PORT, KPD_ROW2_PIN, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KPD_ROW3_PORT, KPD_ROW3_PIN, DIO_PIN_INPUT);
	
	//Active KDP ROWS Pins Internal Pull Up 
	DIO_voidActivePinInPullUpResistance(KPD_ROW0_PORT, KPD_ROW0_PIN);
	DIO_voidActivePinInPullUpResistance(KPD_ROW1_PORT, KPD_ROW1_PIN);
	DIO_voidActivePinInPullUpResistance(KPD_ROW2_PORT, KPD_ROW2_PIN);
	DIO_voidActivePinInPullUpResistance(KPD_ROW3_PORT, KPD_ROW3_PIN); 


}
void KPD_voidGetValue(u8* copy_pu8ReturnedValue){
	if(copy_pu8ReturnedValue != NULL){
		
		u8 local_u8ColsPorts[4] = {KPD_COL0_PORT,KPD_COL1_PORT,KPD_COL2_PORT,KPD_COL3_PORT};
		u8 local_u8ColsPins [4] = {KPD_COL0_PIN ,KPD_COL1_PIN ,KPD_COL2_PIN ,KPD_COL3_PIN };
		u8 local_u8RowsPorts[4] = {KPD_ROW0_PORT,KPD_ROW1_PORT,KPD_ROW2_PORT,KPD_ROW3_PORT};
		u8 local_u8RowsPins [4] = {KPD_ROW0_PIN ,KPD_ROW1_PIN ,KPD_ROW2_PIN ,KPD_ROW3_PIN };
			
		u8 local_u8Keys[4][4] = KPD_KEYS;
		
		u8 local_u8ColsCounter, local_u8RowsCounter;
		u8 local_u8RowValue;
		*copy_pu8ReturnedValue = KPD_NOT_PRESSED;
			
		for(local_u8ColsCounter= 0 ; local_u8ColsCounter<4; local_u8ColsCounter++){
			// Activate Each Columns
			DIO_voidSetPinValue(local_u8ColsPorts[local_u8ColsCounter], local_u8ColsPins[local_u8ColsCounter], DIO_PIN_LOW);
			
			//Read Each Row 
			for(local_u8RowsCounter=0;local_u8RowsCounter<4;local_u8RowsCounter++)
			{
				//Read Each Row
				DIO_voidGetPinValue(local_u8RowsPorts[local_u8RowsCounter], local_u8RowsPins[local_u8RowsCounter],
				&local_u8RowValue);
				
				//Is pressed?
				if(0 == local_u8RowValue)
				{
					while(0 == local_u8RowValue)
					{
						DIO_voidGetPinValue(local_u8RowsPorts[local_u8RowsCounter], local_u8RowsPins[local_u8RowsCounter],&local_u8RowValue);
					}
					*copy_pu8ReturnedValue = local_u8Keys[local_u8RowsCounter][local_u8ColsCounter];
					return;
				}
			}

			// Deactivate current Columns
			DIO_voidSetPinValue(local_u8ColsPorts[local_u8ColsCounter], local_u8ColsPins[local_u8ColsCounter], DIO_PIN_HIGH);
			
		}
	}
	else{
		//return Error State
	}
}