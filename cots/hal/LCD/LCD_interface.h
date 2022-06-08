/*
 * LCD_interface.h
 *
 *  Created on: Sep 5, 2021
 *      Author: Sa3eed
 */

#ifndef COTS_HAL_LCD_LCD_INTERFACE_H_
#define COTS_HAL_LCD_LCD_INTERFACE_H_

#define lcdclear LCD_cmd(0x01); LCD_cmd(0x80);

void LCD_init(void);
void LCD_cmd(u8 cmd);
void LCD_printchar(u8 ch);
void LCD_printstring(u8 * x);
void LCD_moveto(u8 xpos, u8 ypos);
void LCD_PRINT_number(u32 copy_number);
void LCD_PRINT_number_2(u32 copy_number);
void LCD_printfloat(f32 copy_number,u8 copy_precision);

#endif /* COTS_HAL_LCD_LCD_INTERFACE_H_ */
