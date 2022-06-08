/*
 * LCD_program.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Sa3eed
 */
#include "../../lib/STD_TYPES.h"
#include "../../lib/BitMath.h"
#include "../../mcal/DIO/DIO_interface.h"
#include "../../mcal/DIO/DIO_private.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "avr/delay.h"

void LCD_cmd(u8 cmd){
//	Dio_SetPortValue(LCD_DATA_PORT, cmd);
	PortC = cmd;
	Dio_SetPinValue(LCD_CTRl_PORT, LCD_RS_PIN, Dio_Low);
	Dio_SetPinValue(LCD_CTRl_PORT, LCD_RW_PIN, Dio_Low);
	Dio_SetPinValue(LCD_CTRl_PORT, LCD_E_PIN, Dio_High);
	_delay_us(2);
	Dio_SetPinValue(LCD_CTRl_PORT, LCD_E_PIN, Dio_Low);
}

void LCD_printchar(u8 ch){
	Dio_SetPortValue(LCD_DATA_PORT, ch);
//	LCD_DATA_PORT = ch;
	Dio_SetPinValue(LCD_CTRl_PORT, LCD_RS_PIN, Dio_High);
	Dio_SetPinValue(LCD_CTRl_PORT, LCD_RW_PIN, Dio_Low);
	Dio_SetPinValue(LCD_CTRl_PORT, LCD_E_PIN, Dio_High);
	_delay_us(2);
	Dio_SetPinValue(LCD_CTRl_PORT, LCD_E_PIN, Dio_Low);
}

void LCD_init(void){
	Dio_SetPortDirection(LCD_DATA_PORT, 0xff);
	Dio_SetPortDirection(LCD_CTRl_PORT, 0xff);
	LCD_cmd(0x38);   // init lcd in 8bit mode
	_delay_ms(1);
	LCD_cmd(0x0C);   // init lcd in 8bit mode
	_delay_ms(1);
	LCD_cmd(0x06);   // clear lcd screen
	_delay_ms(1);
//	LCD_sendCommand(0x02);   // return home
//	_delay_ms(1);
	LCD_cmd(0x01);   // make inc in cursor
	_delay_ms(1);
	LCD_cmd(0x80);   // go to line 1 pos 1
	_delay_ms(1);
}

void LCD_printstring(u8 * x){
	u8 i = 0;
	while (x[i] != '\0') {
		LCD_printchar(x[i]);
		_delay_ms(1);
		++i;
	}
}

void LCD_moveto(u8 xpos, u8 ypos) {
	u8 add = 0;
	if (xpos == 0) add = 0x80;
	else if (xpos == 1) add = 0xC0;

	if (ypos < 16) add += ypos;
	LCD_cmd(add);
}


void LCD_PRINT_number(u32 copy_number)
{
	u32 tmp;
	u8 digit_count;
	tmp=copy_number;
	digit_count=1;
	while(tmp>=10)
	{
		digit_count++;
		tmp/=10;
	}
	--digit_count;

	while(digit_count)
	{
		LCD_cmd(0x14);//shift cursor right
		digit_count--;
	}
	LCD_cmd(0x04);//cursor direction right to left
	tmp=copy_number;
	while(tmp>0)
	{
		LCD_printchar('0'+tmp%10);
		tmp/=10;
	}

}


void LCD_PRINT_number_2(u32 copy_number)
{
	u8 number[10];
	u8 local_loop_iterator;
	ltoa(copy_number,number,10);
	for(local_loop_iterator=0;local_loop_iterator<10;local_loop_iterator++)
	{
		if(number[local_loop_iterator]>='0' && number[local_loop_iterator]<='9'){
			LCD_printchar(number[local_loop_iterator]);
		}
		else {break;}
	}

}


void LCD_printfloat(f32 copy_number,u8 copy_precision){

	u16 number_prepoint=copy_number,number_postpoint;
	u8 prepoint[5],postpoint[5];
	u8 local_loop_iterator;
	copy_number-=number_prepoint;
	while(copy_precision--)
	{
		copy_number*=10;
	}
	copy_number+=0.5;
	number_postpoint=copy_number;
	itoa(number_prepoint,prepoint,10);
	itoa(number_postpoint,postpoint,10);
	for(local_loop_iterator=0;local_loop_iterator<5;local_loop_iterator++)
	{
		if(prepoint[local_loop_iterator]>='0' && prepoint[local_loop_iterator]<='9'){
			LCD_printchar(prepoint[local_loop_iterator]);
		}
		else {break;}
	}

	LCD_printchar('.');

	for(local_loop_iterator=0;local_loop_iterator<5;local_loop_iterator++)
	{
		if(postpoint[local_loop_iterator]>='0' && postpoint[local_loop_iterator]<='9'){
			LCD_printchar(postpoint[local_loop_iterator]);
		}
		else {break;}
	}

}






