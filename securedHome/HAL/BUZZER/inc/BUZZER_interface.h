
/*
 * BUZZER_interface.h
 *
 * Created: 4/10/2024 1:46:09 PM
 *  Author: NotFound
 */ 

#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_


/* BUZZER Macros */
#define BUZZER_PORT DIO_PORTA
#define BUZZER_PIN  DIO_PIN3


/* BUZZER APIs */
void BUZZER_voidInit(u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId);
void BUZZER_voidTurnOn(u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId);
void BUZZER_voidTurnOff(u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId);
void BUZZER_voidToggle(u8 copy_u8BuzzerPortId, u8 copy_u8BuzzerPinId);




#endif /* BUZZER_INTERFACE_H_ */