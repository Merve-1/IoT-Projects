/*
 * DIO_register.h
 *
 * Created: 5/5/2024 12:11:52 AM
 *
 *  Author: NotFound
 */

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

// DATA DIRECTION REGISTERS 
#define DDRA_REG		(*(volatile u8*) 0x3A)
#define DDRB_REG		(*(volatile u8*) 0x37)
#define DDRC_REG		(*(volatile u8*) 0x34)
#define DDRD_REG		(*(volatile u8*) 0x31)

//OUTPUT MEMORY REGISTERS
#define PORTA_REG		(*(volatile u8*) 0x3B)
#define PORTB_REG		(*(volatile u8*) 0x38)
#define PORTC_REG		(*(volatile u8*) 0x35)
#define PORTD_REG		(*(volatile u8*) 0x32)

//INPUT MEMORY REGISTERS
#define PINA_REG		(*(volatile u8*) 0x39)
#define PINB_REG		(*(volatile u8*) 0x36)
#define PINC_REG		(*(volatile u8*) 0x33)
#define PIND_REG		(*(volatile u8*) 0x30)


#endif /* DIO_REGISTER_H_ */