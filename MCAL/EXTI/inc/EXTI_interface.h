
/*
 * EXTI_interface.h
 *
 * Created: 5/10/2024 5:23:57 PM
 *  Author: NotFound
 */ 
  
  #ifndef EXTI_INTERFACE_H_
  #define EXTI_INTERFACE_H_
  
  
  // Macros for Interrupt Source
  #define EXTI_INT0			0
  #define EXTI_INT1			2
  #define EXTI_INT2			3
  
  
  // Macros for Interrupt Trigger Edge 
  #define EXTI_RISING_EDGE				0
  #define EXTI_FALLING_EDGE				1
  #define EXTI_LOW_LEVEL				2
  #define EXTI_ANY_LOGIACAL_CHANGE		3
  
  //APIS Prototypes
  void EXTI_voidEnable(u8 copy_u8InterruptSource, u8 copy_u8TriggerEdge);
  void EXTI_VoidDisable(u8 copy_u8InterruptSource);
  
  
 #endif  /* EXTI_INTERFACE_H_ */