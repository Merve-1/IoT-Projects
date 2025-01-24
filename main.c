/*		Documentation								*
 *		Software component : STD_TYPES.h			*
 *		Created: 4/8/2024 7:48:21 PM				*
 *		Author: NotFound							*
 *		Version : 1.0								* 
 *		VersionDescription: no description yet		*
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

// UTILES_LIB
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// MCAL
#include "MCAL/DIO/inc/DIO_interface.h"
#include "HAL/LED/inc/LED_interface.h"
#include "HAL/LCD/inc/LCD_interface.h"
#include "HAL/KEYPAD/inc/KPD_interface.h"
#include "HAL/DC/inc/DCMOTOR_interface.h"
#include "HAL/Servo/inc/SRVM_interface.h"
#include "HAL/BUZZER/inc/BUZZER_interface.h"
#include "MCAL/UART/inc/UART_interface.h" // Include UART for testing

#include "HAL/EEPROM/INC/EEPROM_interface.h" // Include EEPROM interface

#define PASSWORD_LENGTH 4 // Assuming the password length is 4 digits
#define MAX_TRIALS      3   // Maximum number of password entry trials


void setPassword(){
	char password[PASSWORD_LENGTH + 1]; // Array to store the password (+1 for null terminator)
	char input_password[PASSWORD_LENGTH + 1]; // Array to store the user input password
	int i, trials = 0, trailNumber = 0;
	BOOL password_set = false;
	UART_voidTxChar(password);
	// Check if the initializations are successful
	LCD_voidSendCommand(0x01); // Clear Display
	LCD_voidDisplayString("Init Done");
	_delay_ms(2000);

	// Ask the user to set the password
	LCD_voidSendCommand(0x01); // Clear Display
	LCD_voidDisplayString("Set password:");
	
	UART_voidRxString(password);
	
	UART_voidTxString((u8 *)"Password set successfully");
	password_set = true;

	// Save password to EEPROM
	EEPROM_writeString(0x00, password);
	
	while (1) {
		// Clear display
		LCD_voidSendCommand(0x01); // Clear Display

		if (password_set) {
			// Ask the user to enter the password to unlock the door
			LCD_voidDisplayString("Enter password:");

			// Getting the password from the user
			for (i = 0; i < PASSWORD_LENGTH; ++i) {
				char key;
				do {
					KPD_voidGetValue(&key);
				} while (key == KPD_NOT_PRESSED); // Wait until a key is pressed

				input_password[i] = key;
				LCD_voidDisplayChar('*'); // Display '*' instead of actual digits
			}
			input_password[PASSWORD_LENGTH] = '\0'; // Null terminate the input password

			// Check if the entered password matches the stored password
			if (strcmp(password, input_password) == 0) {
				// Correct password entered, display "Door opened!" and exit the loop
				LCD_voidSendCommand(0x01); // Clear Display
				LCD_voidDisplayString("Door opened!");

				// Turn on the LED
				LED_voidTurnOn(DIO_PORTD, DIO_PIN7);
				_delay_ms(5000);

				// Turn off the LED
				LED_voidTurnOff(DIO_PORTD, DIO_PIN7);

				// Turn the servo motor to open the door
				SRVM_voidOn(90); // Adjust the angle as needed to represent door opening
				_delay_ms(5000); // Keep the servo in the open position for 5 seconds
				SRVM_voidOff();
				
				// Turn on the motor
				DCMOTOR_voidOn(DCMOTOR_A, DCMOTOR_CLOCK_WISE);
				_delay_ms(5000); // Keep the motor running for 5 seconds

				// Turn off the motor
				DCMOTOR_voidOff(DCMOTOR_A);
				// Reset EEPROM after the door is locked
				EEPROM_clear();

				break;
				} else {
				// Incorrect password entered
				trials++;

				if (trials >= MAX_TRIALS) {
					// Maximum trials reached, display "Locked!" and exit the loop
					LCD_voidSendCommand(0x01); // Clear Display
					LCD_voidDisplayString("Locked!");

					//Buzzer (Speaker) on
					BUZZER_voidTurnOn(DIO_PORTA, DIO_PIN3);
					_delay_ms(5000);
					//turn off buzzer
					BUZZER_voidTurnOff(DIO_PORTA, DIO_PIN3);

					// Turn on the LED
					LED_voidTurnOn(DIO_PORTB, DIO_PIN0);
					_delay_ms(5000);

					// Turn off the LED
					LED_voidTurnOff(DIO_PORTB, DIO_PIN0);
					setPassword();
					break;
					} else {
					// Display trial number passed and wait for a while before clearing the display
					LCD_voidSendCommand(0x01); // Clear Display
					trailNumber++;
					if (trailNumber == 1) {
						LCD_voidDisplayString("One trial passed");
						} else if (trailNumber == 2) {
						LCD_voidDisplayString("Second trial passed");
					}
					_delay_ms(2000); // Delay to read the message

					// Ask the user to re-enter the password
					continue;
				}
			}
			} else {
			// Inform the user to set the password first
			LCD_voidDisplayString("Set password first");
			
			break; // Exit the loop as the password needs to be set first
		}
	}
	
}
	
int main(void) {
	char password[PASSWORD_LENGTH + 1]; // Array to store the password (+1 for null terminator)
	char input_password[PASSWORD_LENGTH + 1]; // Array to store the user input password
	int i, trials = 0, trailNumber = 0;
	BOOL password_set = false;

	// Initialize peripherals
	LCD_voidInit(); // Initialize LCD
	KPD_voidInit(); // Initialize Keypad
	DCMOTOR_voidInit(DCMOTOR_A); // Initialize DC motor
	SRVM_voidInit(); // Initialize Servo motor
	LED_voidInit(DIO_PORTD, DIO_PIN7); // Initialize LED
	LED_voidInit(DIO_PORTB, DIO_PIN0); // Initialize LED
	BUZZER_voidInit(DIO_PORTA, DIO_PIN3);
	// Initialize UART
	UART_voidInit();

	// Check if the initializations are successful
	LCD_voidSendCommand(0x01); // Clear Display
	LCD_voidDisplayString("Init Done");
	_delay_ms(2000);

	// Ask the user to set the password
	LCD_voidSendCommand(0x01); // Clear Display
	LCD_voidDisplayString("Set password:");
	UART_voidRxString(password);
	UART_voidTxString((u8 *)"Password set successfully");
	password_set = true;



	// Save password to EEPROM
	EEPROM_writeString(0x00, password);

	while (1) {
		// Clear display
		LCD_voidSendCommand(0x01); // Clear Display

		if (password_set) {
			// Ask the user to enter the password to unlock the door
			LCD_voidDisplayString("Enter password:");

			// Getting the password from the user
			for (i = 0; i < PASSWORD_LENGTH; ++i) {
				char key;
				do {
					KPD_voidGetValue(&key);
				} while (key == KPD_NOT_PRESSED); // Wait until a key is pressed

				input_password[i] = key;
				LCD_voidDisplayChar('*'); // Display '*' instead of actual digits
			}
			input_password[PASSWORD_LENGTH] = '\0'; // Null terminate the input password

			// Check if the entered password matches the stored password
			if (strcmp(password, input_password) == 0) {
				// Correct password entered, display "Door opened!" and exit the loop
				LCD_voidSendCommand(0x01); // Clear Display
				LCD_voidDisplayString("Door opened!");

				// Turn on the LED
				LED_voidTurnOn(DIO_PORTD, DIO_PIN7);
				_delay_ms(5000);

				// Turn off the LED
				LED_voidTurnOff(DIO_PORTD, DIO_PIN7);

				// Turn the servo motor to open the door
				SRVM_voidOn(90); // Adjust the angle as needed to represent door opening
				_delay_ms(5000); // Keep the servo in the open position for 5 seconds
				SRVM_voidOff();
				
				// Turn on the motor
				DCMOTOR_voidOn(DCMOTOR_A, DCMOTOR_CLOCK_WISE);
				_delay_ms(5000); // Keep the motor running for 5 seconds

				// Turn off the motor
				DCMOTOR_voidOff(DCMOTOR_A);

				// Reset EEPROM after the door is locked
				EEPROM_clear();

				break;
				} else {
				// Incorrect password entered
				trials++;

				if (trials >= MAX_TRIALS) {
					// Maximum trials reached, display "Locked!" and exit the loop
					LCD_voidSendCommand(0x01); // Clear Display
					LCD_voidDisplayString("Locked!");

					//Buzzer (Speaker) on
					BUZZER_voidTurnOn(DIO_PORTA, DIO_PIN3);
					_delay_ms(5000);
					//turn off buzzer
					BUZZER_voidTurnOff(DIO_PORTA, DIO_PIN3);

					// Turn on the LED
					LED_voidTurnOn(DIO_PORTB, DIO_PIN0);
					_delay_ms(5000);

					// Turn off the LED
					LED_voidTurnOff(DIO_PORTB, DIO_PIN0);
					setPassword();
					break;
					} else {
					// Display trial number passed and wait for a while before clearing the display
					LCD_voidSendCommand(0x01); // Clear Display
					trailNumber++;
					if (trailNumber == 1) {
						LCD_voidDisplayString("One trial passed");
						} else if (trailNumber == 2) {
						LCD_voidDisplayString("Second trial passed");
					}
					_delay_ms(2000); // Delay to read the message

					// Ask the user to re-enter the password
					continue;
				}
			}
			} else {
			// Inform the user to set the password first
				LCD_voidDisplayString("Set password first");
		
				break; // Exit the loop as the password needs to be set first
		}
	}

	return 0;
}
