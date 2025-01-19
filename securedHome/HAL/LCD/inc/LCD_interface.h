/*
 * LCD_interface.h
 *
 * Created: 5/5/2024 9:55:21 PM
 *  Author: NotFound
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidInit					(void);
void LCD_voidSendCommand			(u8 copy_u8Cmnd);
void LCD_voidDisplayChar			(u8 copy_u8Data);
void LCD_voidDisplayString			(u8* copy_pu8String);
void LCD_voidDisplayeNumber			(u32 copy_u32Number);
void LCD_voidClear					(void);
void LCD_voidShift					(u8 copy_u8shifttingDirection);
void LCD_voidGoToSpecificPosition	(u8 copy_u8LineNumber,u8 copy_u8Position);

#endif /* LCD_INTERFACE_H_ */