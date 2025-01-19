/*
 * DCMOTOR_test.c
 *
 * Created: 5/29/2024 11:29:55 AM
 * Author: NotFound
 */

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
/* HAL */
#include "DCMOTOR_interface.h"
#include "DCMOTOR_config.h"
/*
// Mock functions to simulate hardware interactions
void DIO_voidSetPinDirection(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8Direction) {
    printf("SetPinDirection called with port: %d, pin: %d, direction: %d\n", copy_u8PortID, copy_u8PinID, copy_u8Direction);
}

void DIO_voidSetPinValue(u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8Value) {
    printf("SetPinValue called with port: %d, pin: %d, value: %d\n", copy_u8PortID, copy_u8PinID, copy_u8Value);
}

// Test Motor Initialization
void testMotorInitialization(void) {
    printf("Running testMotorInitialization...\n");
    DCMOTOR_voidInit(DCMOTOR_A);

    // Check if the pins were configured correctly
    printf("Expected: port %d, pin %d, direction %d\n", DCMOTOR_A_IN1_PORT, DCMOTOR_A_IN1_PIN, DIO_PIN_OUTPUT);
    printf("Expected: port %d, pin %d, direction %d\n", DCMOTOR_A_IN2_PORT, DCMOTOR_A_IN2_PIN, DIO_PIN_OUTPUT);
    printf("Expected: port %d, pin %d, direction %d\n", DCMOTOR_A_ENABLE_PORT, DCMOTOR_A_ENABLE_PIN, DIO_PIN_OUTPUT);
}

// Test Motor On and Off
void testMotorOnAndOff(void) {
    printf("Running testMotorOnAndOff...\n");

    DCMOTOR_voidOn(DCMOTOR_A, DCMOTOR_CLOCK_WISE);
    printf("Expected: port %d, pin %d, value %d\n", DCMOTOR_A_IN1_PORT, DCMOTOR_A_IN1_PIN, DIO_PIN_HIGH);
    printf("Expected: port %d, pin %d, value %d\n", DCMOTOR_A_IN2_PORT, DCMOTOR_A_IN2_PIN, DIO_PIN_LOW);
    printf("Expected: port %d, pin %d, value %d\n", DCMOTOR_A_ENABLE_PORT, DCMOTOR_A_ENABLE_PIN, DIO_PIN_HIGH);

    DCMOTOR_voidOn(DCMOTOR_A, DCMOTOR_COUNTER_CLOCK_WISE);
    printf("Expected: port %d, pin %d, value %d\n", DCMOTOR_A_IN1_PORT, DCMOTOR_A_IN1_PIN, DIO_PIN_LOW);
    printf("Expected: port %d, pin %d, value %d\n", DCMOTOR_A_IN2_PORT, DCMOTOR_A_IN2_PIN, DIO_PIN_HIGH);
    printf("Expected: port %d, pin %d, value %d\n", DCMOTOR_A_ENABLE_PORT, DCMOTOR_A_ENABLE_PIN, DIO_PIN_HIGH);

    DCMOTOR_voidOff(DCMOTOR_A);
    printf("Expected: port %d, pin %d, value %d\n", DCMOTOR_A_ENABLE_PORT, DCMOTOR_A_ENABLE_PIN, DIO_PIN_LOW);
}

int main(void) {
    testMotorInitialization();
    testMotorOnAndOff();
    return 0;
}
*/