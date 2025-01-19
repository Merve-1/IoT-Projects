/*
 * switch_interface.h
 *
 * Created: 4/10/2024 10:14:26 AM
 *  Author: NotFound
 */ 



#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_



/* SWITCH Macros */
/*
#define SWITCH_0_PORT DIO_PORTB
#define SWITCH_0_PIN DIO_PIN0

#define SWITCH_1_PORT DIO_PORTD
#define SWITCH_1_PIN DIO_PIN6

#define SWITCH_2_PORT DIO_PORTD
#define SWITCH_2_PIN DIO_PIN2
*/
/* SWITCH APIs */
void SWITCH_voidInit(u8 copy_u8switchPortId, u8 copy_u8switchPinId);
u8 SWITCH_u8GetState(u8 copy_u8switchPortId, u8 copy_u8switchPinId);




#endif /* SWITCH_INTERFACE_H_ */