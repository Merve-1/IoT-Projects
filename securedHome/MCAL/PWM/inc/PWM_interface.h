
/*
 * PWM_interface.h
 *
 * Created: 5/25/2024 11:54:15 PM
 *  Author: NotFound
 */ 


#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_


void PWM_voidInitChannel_0          (void);
void PWM_voidInitChannel_1A         (void);
void PWM_voidGenerate_PWM_Channel_0 (u8 copy_u8DutyCycle);
void PWM_voidGenerate_PWM_Channel_1A(u16 copy_u16Frequency_hz,f32 copy_f32DutyCycle);
void PWM_voidStopChannel_1A(void); 



#endif /* PWM_INTERFACE_H_ */