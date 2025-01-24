/*
 * LED_interface.h
 *
 * Created: 4/10/2024 10:15:49 AM
 *  Author: NotFound
 */ 



#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


/* LED0 Macros */
/*
#define LED_0_PORT DIO_PORTC
#define LED_0_PIN  DIO_PIN2

#define LED_1_PORT DIO_PORTC
#define LED_1_PIN  DIO_PIN7*/

#define LED_2_PORT DIO_PORTD
#define LED_2_PIN  DIO_PIN7




/* LED APIs */
void LED_voidInit(u8 copy_u8ledPortId, u8 copy_u8ledPinId);
void LED_voidTurnOn(u8 copy_u8ledPortId, u8 copy_u8ledPinId);
void LED_voidTurnOff(u8 copy_u8ledPortId, u8 copy_u8ledPinId);



#endif /* LED_INTERFACE_H_ */