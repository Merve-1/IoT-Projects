
/*
 * UART_program.c
 *
 * Created: 6/10/2024 3:08:08 PM
 *  Author: NotFound
 */ 

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "UART_interface.h"
#include "UART_register.h" 
 
 
 
 void UART_voidInit(void)
 {
	 // Set Buad Rate = 9600
	 CLR_BIT(UCSRA_REG, U2X);
	 UBRRL_REG = 103;
	 
	 u8 local_u8InitVar = 0x00;
	 
	 // writing on UCSRC
	 SET_BIT(local_u8InitVar, URSEL);
	 
	 // select UART MODE = Asynchronous
	 CLR_BIT(local_u8InitVar, UMSEL);
	 
	 // configure no parity
	 CLR_BIT(local_u8InitVar, UPM0);
	 CLR_BIT(local_u8InitVar, UPM1);
	 
	 // configure stop bits = 1
	 CLR_BIT(local_u8InitVar, USBS);
	 
	 // configure data bits = 8
	 SET_BIT(local_u8InitVar, UCSZ0);
	 SET_BIT(local_u8InitVar, UCSZ1);
	 CLR_BIT(UCSRB_REG, UCSZ2);
	 
	 // configure no polarity
	 CLR_BIT(local_u8InitVar, UCPOL);
	 
	 UCSRC_REG = local_u8InitVar; // UCSRC_REG = 0b10000110;
	 
	 //Enable Tx
	 SET_BIT(UCSRB_REG, TXEN);
	 
	 //Enable Rx
	 SET_BIT(UCSRB_REG, RXEN);
 }


 void UART_voidTxChar(u8 copy_u8TxData)
 {
	 UDR_REG = copy_u8TxData;
	 
	 // Busy Wait on Data Register empty flag
	 while(0 == GET_BIT(UCSRA_REG, UDRE));
 }


 void UART_voidRxChar(u8* copy_pu8RxData)
 {
	 if(copy_pu8RxData!=NULL)
	 {
		 // Busy Wait on Receive Complete flag
		 while(0 == GET_BIT(UCSRA_REG, RXC));
		 
		 *copy_pu8RxData = UDR_REG;
	 }
	 else
	 {
		 //return Error State
	 }
 }


 void UART_voidTxString(u8* copy_pu8TxString)
 {
	 if(copy_pu8TxString!=NULL)
	 {
		 u8 local_u8Counter=0;
		 while(copy_pu8TxString[local_u8Counter]!='\0')
		 {
			 UART_voidTxChar(copy_pu8TxString[local_u8Counter]);
			 local_u8Counter++;
		 }
	 }
	 else
	 {
		 // return Error state
	 }
 }


 void UART_voidRxString(u8* copy_pu8RxString)
 {
	 if(copy_pu8RxString!=NULL)
	 {
		 u8 local_u8Counter=0;
		 
		 while(1)
		 {
			 UART_voidRxChar(&copy_pu8RxString[local_u8Counter]);
			 
			 if(copy_pu8RxString[local_u8Counter] == '#')
			 {
				 break;
			 }
			 else
			 {
				 local_u8Counter++;
			 }
		 }
		 
		 copy_pu8RxString[local_u8Counter] = '\0';
	 }
	 else
	 {
		 // return Error state
	 }
 }
