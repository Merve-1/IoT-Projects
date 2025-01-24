/*
 * DIO_program.c
 *
 * Created: 4/8/2024 6:25:36 PM
 * Author: NotFound
 */ 

/* #include "../UTILES_LIB/STD_TYPES.h" */
/*DIO right click => properties => Toolchain => Directories => + */
//#include <avr/io.h> => replaced with DIO_register.h

/*UTILES LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "DIO_register.h"

/*
 * DIO_program.c
 * 
 * Actual implementations of DIO functions
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"


void DIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection) {
    	// constant values use switch (Faster)
    	switch (copy_u8PortId)
    	{
	    	/*Port A*/
	    	case DIO_PORTA:
	    	switch(copy_u8PinDirection){
		    	case DIO_PIN_OUTPUT:
		    	SET_BIT(DDRA_REG,copy_u8PinId);
		    	break;
		    	
		    	case DIO_PIN_INPUT:
		    	CLR_BIT(DDRA_REG,copy_u8PinId);
		    	break;
	    	}
	    	break;
	    	/*Port B*/
	    	case DIO_PORTB:
	    	switch(copy_u8PinDirection){
		    	case DIO_PIN_OUTPUT:
		    	SET_BIT(DDRB_REG,copy_u8PinId);
		    	break;
		    	
		    	case DIO_PIN_INPUT:
		    	CLR_BIT(DDRB_REG,copy_u8PinId);
		    	break;
	    	}
	    	break;
	    	/*Port C*/
	    	case DIO_PORTC:
	    	switch(copy_u8PinDirection){
		    	case DIO_PIN_OUTPUT:
		    	SET_BIT(DDRC_REG,copy_u8PinId);
		    	break;
		    	
		    	case DIO_PIN_INPUT:
		    	CLR_BIT(DDRC_REG,copy_u8PinId);
		    	break;
	    	}
	    	break;
	    	/*Port D*/
	    	case DIO_PORTD:
	    	switch(copy_u8PinDirection){
		    	case DIO_PIN_OUTPUT:
		    	SET_BIT(DDRD_REG,copy_u8PinId);
		    	break;
		    	
		    	case DIO_PIN_INPUT:
		    	CLR_BIT(DDRD_REG,copy_u8PinId);
		    	break;
	    	}
	    	break;
    	}
}

void DIO_voidSetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue) {
    //u8 local_u8ErrorState = true;
    // clean code "MISRA C"
    if ((copy_u8PortId<4) && (copy_u8PortId<8) && (copy_u8PinValue<3)){
	    switch(copy_u8PortId){
		    case DIO_PORTA:
		    switch(copy_u8PinValue){
			    case DIO_PIN_HIGH:
			    SET_BIT(PORTA_REG, copy_u8PinId);
			    break;
			    case DIO_PIN_LOW:
			    CLR_BIT(PORTA_REG, copy_u8PinId);
			    break;
		    }
		    break;
		    case DIO_PORTB:
		    switch(copy_u8PinValue){
			    case DIO_PIN_HIGH:
			    SET_BIT(PORTB_REG, copy_u8PinId);
			    break;
			    case DIO_PIN_LOW:
			    CLR_BIT(PORTB_REG, copy_u8PinId);
			    break;
		    }
		    break;
		    case DIO_PORTC:
		    switch(copy_u8PinValue){
			    case DIO_PIN_HIGH:
			    SET_BIT(PORTC_REG, copy_u8PinId);
			    break;
			    case DIO_PIN_LOW:
			    CLR_BIT(PORTC_REG, copy_u8PinId);
			    break;
		    }
		    break;
		    case DIO_PORTD:
		    switch(copy_u8PinValue){
			    case DIO_PIN_HIGH:
			    SET_BIT(PORTD_REG, copy_u8PinId);
			    break;
			    case DIO_PIN_LOW:
			    CLR_BIT(PORTD_REG, copy_u8PinId);
			    break;
		    }
		    break;
	    }
	    
    }
    else{
	    //	Do Nothing
	    //Unit testing
	    //local_u8ErrorState = false;
    }
    //return local_u8ErrorState;
}

// Implement other DIO functions similarly




/*Pin Apis*/



void DIO_voidGetPinValue					(u8 copy_u8PortId, u8 copy_u8PinId,u8* copy_pu8PinValue){
	// NULL is not keyword 
	if((copy_u8PortId < 4) && (copy_u8PinId < 8) && (copy_pu8PinValue != NULL)){
		switch(copy_u8PortId){
			case DIO_PORTA:
			//	return GET_BIT(PINA, copy_u8PinId);
				*copy_pu8PinValue = GET_BIT(PINA_REG,copy_u8PinId); 
			break;
			case DIO_PORTB:
			//	return GET_BIT(PINB, copy_u8PinId);
			*copy_pu8PinValue = GET_BIT(PINB_REG,copy_u8PinId);
			break;
			case DIO_PORTC:
			//	return GET_BIT(PINC, copy_u8PinId);
			*copy_pu8PinValue = GET_BIT(PINC_REG,copy_u8PinId);
			break;
			case DIO_PORTD:
			//	return GET_BIT(PIND, copy_u8PinId);
			*copy_pu8PinValue = GET_BIT(PIND_REG,copy_u8PinId);
			break;
			
				
		}
	}
	else{
		// Do Nothing
		// return Error State
	}
}
	void DIO_voidTogglePinValue					(u8 copy_u8PortId, u8 copy_u8PinId){
		if((copy_u8PortId < 4) && (copy_u8PinId < 8)){
			switch(copy_u8PortId){
				case DIO_PORTA:
					TOG_BIT(PORTA_REG, copy_u8PinId);
				break;
				case DIO_PORTB:
					TOG_BIT(PORTB_REG, copy_u8PinId);
				break;
				case DIO_PORTC:
					TOG_BIT(PORTC_REG, copy_u8PinId);
				break;
				case DIO_PORTD:
					TOG_BIT(PORTD_REG, copy_u8PinId);
				break;
			}
		}
		else{
			
		}

		
}

void DIO_voidActivePinInPullUpResistance	(u8 copy_u8PortId,u8 copy_u8PinId){
	if ((copy_u8PortId < 4) && (copy_u8PinId < 8)){
		switch(copy_u8PortId){
			case DIO_PORTA:
				SET_BIT(PORTA_REG, copy_u8PinId);
			break;
			case DIO_PORTB:
				SET_BIT(PORTB_REG, copy_u8PinId);
			break;
			case DIO_PORTC:
				SET_BIT(PORTC_REG, copy_u8PinId);
			break;
			case DIO_PORTD:
				SET_BIT(PORTD_REG, copy_u8PinId);
			break;
		}
	}
	else{
		// Do Nothing 
	}
}

//=================================================================================================================
//=================================================================================================================
//=================================================================================================================
//=================================================================================================================
//Port implementation

void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection) {
	switch (copy_u8PortId) {
		case DIO_PORTA:
			// Set the direction of PORTA pins according to the specified direction
            DDRA_REG = copy_u8PortDirection;
		break;
		case DIO_PORTB:
			DDRB_REG = copy_u8PortDirection;
		break;
		case DIO_PORTC:
			DDRC_REG = copy_u8PortDirection;
		break;
		case DIO_PORTD:
			DDRD_REG = copy_u8PortDirection;
		break;
		default:
		// Invalid port ID
		break;
	}
}


void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue) {
	switch (copy_u8PortId) {
		case DIO_PORTA:
            // Set the value of PORTA to the specified value
			PORTA_REG = copy_u8PortValue;
		break;
		case DIO_PORTB:
			PORTB_REG  = copy_u8PortValue;
		break;
		case DIO_PORTC:
			PORTC_REG  = copy_u8PortValue;
		break;
		case DIO_PORTD:
			PORTD_REG  = copy_u8PortValue;
		break;
		default:
		// Invalid port ID
		break;
	}
}

void DIO_voidGetPortValue(u8 copy_u8PortId, u8* copy_Pu8PortValue) {
	switch (copy_u8PortId) {
		case DIO_PORTA:
            // Read the value of PORTA and store it at the address pointed to by copy_Pu8PortValue
			*copy_Pu8PortValue = PINA_REG ;
		break;
		case DIO_PORTB:
			*copy_Pu8PortValue = PINB_REG ;
		break;
		case DIO_PORTC:
			*copy_Pu8PortValue = PINC_REG ;
		break;
		case DIO_PORTD:
			*copy_Pu8PortValue = PIND_REG ;
		break;
		default:
		// Invalid port ID
		break;
	}
}

/*
	// Read the current value of PORTA and store it in the portValue variable
    portValue = PORTA;
    // Toggle the value of PORTA by performing a bitwise NOT operation on portValue and write the result back to PORTA
    PORTA = ~portValue;
*/

void DIO_voidTogglePortValue(u8 copy_u8PortId) {
    switch (copy_u8PortId) {
        case DIO_PORTA:
		    // Toggle the state of all pins of PORTA by performing a bitwise XOR (^) operation with DIO_PORT_OUTPUT
            PORTA_REG  ^= DIO_PORT_OUTPUT;
            break;
        case DIO_PORTB:
            PORTB_REG  ^= DIO_PORT_OUTPUT;
            break;
        case DIO_PORTC:
            PORTC_REG  ^= DIO_PORT_OUTPUT;
            break;
        case DIO_PORTD:
            PORTD_REG  ^= DIO_PORT_OUTPUT;
            break;
        default:
            // Invalid port ID
            break;
    }
}


void DIO_voidActivePortInPullUpResistance(u8 copy_u8PortId) {
	switch (copy_u8PortId) {
		case DIO_PORTA:
			// Activate internal pull-up resistors for all pins of PORTA by setting PORTA to DIO_PORT_INPUT
            PORTA_REG  = DIO_PORT_INPUT;		
		break;
		case DIO_PORTB:
			PORTB_REG  = DIO_PORT_INPUT;
		break;
		case DIO_PORTC:
			PORTC_REG  = DIO_PORT_INPUT;
		break;
		case DIO_PORTD:
			PORTD_REG  = DIO_PORT_INPUT;
		break;
		default:
		// Invalid port ID
		break;
	}
}

