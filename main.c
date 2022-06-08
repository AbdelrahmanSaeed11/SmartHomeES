#include <string.h>
#include "cots/lib/STD_TYPES.h"
#include "cots/lib/BitMath.h"
#include "cots/mcal/DIO/DIO_interface.h"
#include "cots/hal/LCD/LCD_interface.h"
#include "cots/hal/Keypad/KPD_interface.h"
#include "cots/hal/Keypad/KPD_config.h"
#include "cots/ADC/adc_interface.h"
#include "avr/delay.h"

void main(){
	//	initialization
	LCD_init();
	ADC_Init();
	Dio_SetPortDirection(KPD_PORT, 0b00001111);
	// welcomeing
	LCD_printstring("WELCOME");
	for (int i = 0; i < 3; ++i){
		LCD_printchar('.');
		_delay_ms(250);
	}
	_delay_ms(500);
	LCD_init();
	LCD_moveto(0, 5);
	LCD_printstring("SmarT");
	LCD_moveto(1, 7);
	LCD_printstring("Home");
	_delay_ms(700);

	// password
	u8 is = 0;
	u8 sz = 0;
	for (u8 i = 0; i < 3; ++i){
		char pass[10] = "1652021";
		char userpass[10];
		sz = 0;
		LCD_init();
		LCD_printstring("Please enter your password");
		LCD_moveto(1, 0);
		LCD_printstring("Pass : ");
		while (sz < 7){
			u8 local_u8PressedKey = keypad();
			if (local_u8PressedKey != KPD_NO_PRESSED_KEY) {
				if (local_u8PressedKey == '=')break;
				if (local_u8PressedKey == 'C'){
					i--;
					is = 1;
					break;
				}
				userpass[sz++] = local_u8PressedKey;
				LCD_printchar('*');
			}
		}
		if (is == 1) {
			is = 0;
			continue;
		}
		int value = strcmp(pass, userpass);
		if (value == 0) {
			is = 1;
			break;
		}
		for (u8 j = 0; j < 3; j++){
			LCD_init();
			LCD_printstring("Wrong Password!!");
			_delay_ms(300);
			LCD_init();
			_delay_ms(150);
		}
	}
	if (is == 0) {
		LCD_cmd(0x08);
		return;
	}
	/**/
	u8 button_state = 0;
	/**/

	/*fan vars*/
	u8 fan_auto_state = 0;
	u8 fan_on_state = 0;
	u8 fan_Adc_temperature_celsius = 0;
	f32 fan_Adc_temperature_fahrenheit = 0;
	/**/

	/*door vars*/
	u8 door_state = 0;
	/**/

	/*curtain vars*/
	u8 curtain_state = 0;
	/**/

	/*fan pins*/
	Dio_SetPinDirection(Dio_PortA, Dio_Pin3, Dio_directionOut);
	Dio_SetPinDirection(Dio_PortA, Dio_Pin4, Dio_directionIn);
	Dio_SetPinDirection(Dio_PortA, Dio_Pin5, Dio_directionOut);
	Dio_SetPinDirection(Dio_PortA, Dio_Pin6, Dio_directionIn);
	Dio_SetPinDirection(Dio_PortA, Dio_Pin7, Dio_directionOut);

	Dio_SetPinValue(Dio_PortA, Dio_Pin3, Dio_High);
	Dio_SetPinValue(Dio_PortA, Dio_Pin5, Dio_High);
	/**/
	while (1) {
		/*read fan on/off state*/
		button_state = Dio_GetPinValue(Dio_PortA, Dio_Pin4);
		if (button_state)//fan on/off
		{
			fan_on_state = 1 - fan_on_state;
		}
		while (button_state) {
			button_state = Dio_GetPinValue(Dio_PortA, Dio_Pin4);
		}
		/**/

		/*read fan outo state*/
		button_state = Dio_GetPinValue(Dio_PortA, Dio_Pin6);
		if (button_state)//fan auto
		{
			fan_auto_state = 1 - fan_auto_state;
		}
		while (button_state) {
			button_state = Dio_GetPinValue(Dio_PortA, Dio_Pin6);
		}
		/**/

		if (fan_auto_state) {
			/*adc to celsius*/
			fan_Adc_temperature_celsius = ADC_Read(0);
			fan_Adc_temperature_celsius /= 2.01;
			/**/
			/*celsius to fahrenheit*/
			fan_Adc_temperature_fahrenheit = fan_Adc_temperature_celsius;
			fan_Adc_temperature_fahrenheit *= 1.8;
			fan_Adc_temperature_fahrenheit += 32;
			/**/
		  /*print temperature state on lcd*/
			LCD_init();
			LCD_PRINT_number_2(fan_Adc_temperature_celsius);
			LCD_printstring("C");
			LCD_printchar(223);

			LCD_printstring(" = ");

			LCD_printfloat(fan_Adc_temperature_fahrenheit, 1);
			LCD_printstring("F");
			LCD_printchar(223);

			LCD_cmd(0xC0);
			LCD_printstring("FAN AUTO ");
			/**/
			if (fan_Adc_temperature_celsius > 25)//turn fan on
			{
				/*print on lcd second line: fan on */
				LCD_printstring("ON");

				Dio_SetPinValue(Dio_PortA, Dio_Pin7, Dio_High);
			} else //turn fan on
			{
				/*print on lcd second line: fan off */
				LCD_printstring("OFF");

				Dio_SetPinValue(Dio_PortA, Dio_Pin7, Dio_Low);
			}

		} else {
			LCD_init();
			if (fan_on_state) {

				Dio_SetPinValue(Dio_PortA, Dio_Pin7, Dio_High);
				/*print on lcd : fan on */
				LCD_printstring("FAN ON");
			} else {
				Dio_SetPinValue(Dio_PortA, Dio_Pin7, Dio_Low);
				/*print on lcd : fan off */
				LCD_printstring("FAN OFF");

			}
		}

		_delay_ms(250);

	}
}
