# Secured Home Embedded Systems Project

## Overview

This project implements a secured home embedded system designed to control access to a door using a password. The system is composed of various hardware components including a keypad, LCD display, LEDs, buzzer, motor driver, motors, EEPROM, Bluetooth module, and a servo motor. The password mechanism ensures that only authorized users can open the door, with the password being securely stored in EEPROM after encryption using the AES (Advanced Encryption Standard) technique. The project is programmed in C, utilizing modular programming principles to ensure code readability, maintainability, and scalability.

## Hardware Components

- **Keypad**: Used for entering the password.
- **LCD Display**: Provides user interface feedback.
- **LEDs**: Indicate system status (e.g., correct/incorrect password).
- **Buzzer**: Sounds an alert for specific actions (e.g., incorrect password entry).
- **Motor Driver**: Controls the DC motors responsible for operating the air conditioner's components.
- **Motors**: Drive the physical movement of parts within the air conditioner, such as adjusting the fan speed or controlling the direction of airflow.
- **EEPROM**: Stores the encrypted password.
- **Bluetooth Module**: Allows for remote control and monitoring.
- **Servo Motor**: Engages and disengages the door locking mechanism.

## Software Components

- **Programming Language**: C
- **Encryption**: AES (Advanced Encryption Standard) is used to encrypt the password before storing it in EEPROM.
- **Modular Programming**: The project is organized into modules to separate different functionalities, making the code easier to manage and extend.

## Features

1. **Password Creation**: Users can set a new password which is then encrypted and stored in EEPROM.
2. **Password Verification**: Users can enter the password to unlock the door. The system decrypts the stored password and compares it with the entered password.
3. **Status Indication**: LEDs and buzzer provide feedback on the status of the system (e.g., password correct/incorrect, door locked/unlocked).
4. **Remote Access**: The Bluetooth module allows users to interact with the system remotely.

## System Operation

1. **Set Password**:
   - User enters a new password via the keypad.
   - The system encrypts the password using AES and stores it in EEPROM.

2. **Unlock Door**:
   - User enters the password via the keypad.
   - The system retrieves and decrypts the password from EEPROM.
   - If the entered password matches the decrypted password, the motor is activated to unlock the door, and the servo motor disengages the lock.
   - LEDs and buzzer provide feedback on the success or failure of the attempt.

## Circuit Diagram

![Circuit Diagram](https://github.com/Merve-1/securedHome/blob/main/Circuit%20.png?raw=true)

## Directory Structure

```
secured-home-embedded-system/
│
├── hal/                    # Hardware Abstraction Layer
│   ├── lcd/
│   │   ├── inc/
│   │   │   ├── lcd_interface.h
│   │   │   ├── lcd_private.h
│   │   │   └── lcd_config.h
│   │   └── src/
│   │       └── lcd_program.c
│   ├── keypad/
│   │   ├── inc/
│   │   │   ├── keypad_interface.h
│   │   │   └── keypad_config.h
│   │   └── src/
│   │       └── keypad_program.c
│   ├── buzzer/
│   │   ├── inc/
│   │   │   ├── buzzer_interface.h
│   │   │   └── buzzer_config.h
│   │   └── src/
│   │       └── buzzer_program.c
│   ├── dc/
│   │   ├── inc/
│   │   │   ├── dc_interface.h
│   │   │   └── dc_config.h
│   │   └── src/
│   │       └── dc_program.c
│   ├── led/
│   │   ├── inc/
│   │   │   ├── led_interface.h
│   │   │   └── led_config.h
│   │   └── src/
│   │       └── led_program.c
│   ├── servo/
│   │   ├── inc/
│   │   │   ├── servo_interface.h
│   │   │   └── servo_config.h
│   │   └── src/
│   │       └── servo_program.c
│
├── mcal/                   # Microcontroller Abstraction Layer
│   ├── dio/
│   │   ├── inc/
│   │   │   ├── dio_interface.h
│   │   │   └── dio_register.h
│   │   └── src/
│   │       └── dio_program.c
│   ├── eeprom/
│   │   ├── inc/
│   │   │   ├── eeprom_interface.h
│   │   │   └── eeprom_config.h
│   │   └── src/
│   │       └── eeprom_program.c
│   ├── exti/
│   │   ├── inc/
│   │   │   ├── exti_interface.h
│   │   │   └── exti_register.h
│   │   └── src/
│   │       └── exti_program.c
│   ├── pwm/
│   │   ├── inc/
│   │   │   ├── pwm_interface.h
│   │   │   └── pwm_config.h
│   │   └── src/
│   │       └── pwm_program.c
│   ├── uart/
│   │   ├── inc/
│   │   │   ├── uart_interface.h
│   │   │   └── uart_config.h
│   │   └── src/
│   │       └── uart_program.c
│
├── aes/
│   ├── inc/
│   │   ├── aes.h
│   │   └── config.h
│   └── src/
│       └── aes.c
│
├── main.c
└── README.md
```

## Getting Started

### Prerequisites

- C Compiler (e.g., GCC)
- Embedded system development environment (e.g., microchip Studio)
- Necessary hardware components as listed above
