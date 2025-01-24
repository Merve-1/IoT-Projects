
/*
 * UART_Register.h
 *
 * Created: 6/10/2024 3:07:38 PM
 *  Author: NotFound
 */ 



#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

/* UART REGISTERS */
// USART I/O Date Register
#define UDR_REG				(*(volatile u8*)0x2C)

//USART Control and Status Register A
 #define UCSRA_REG			(*(volatile u8*)0x2B)
 #define MPCM				0
 #define U2X				1
 #define PE					2
 #define DOR				3
 #define FE					4
 #define UDRE				5
 #define TXC				6
 #define RXC				7
 
//USART Control and Status Register B
 #define UCSRB_REG			(*(volatile u8*)0x2A)
 #define TXB8				0
 #define RXB8				1
 #define UCSZ2				2
 #define TXEN				3
 #define RXEN				4
 #define UDRIE				5
 #define TXCIE				6
 #define RXCIE				7

 //USART Control and Status Register C
 #define UCSRC_REG			(*(volatile u8*)0x40)
 #define UCPOL				0
 #define UCSZ0				1
 #define UCSZ1				2
 #define USBS				3
 #define UPM0				4
 #define UPM1				5
 #define UMSEL				6
 #define URSEL				7

//USART Baud Rate Registers
#define UBRRL_REG			(*(volatile u8*)0x29)
#define UBRRH_REG			(*(volatile u8*)0x40)
#endif /*  UART_REGISTER_H_ */