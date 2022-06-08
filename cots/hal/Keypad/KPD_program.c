/*
 * kpd_program.c
 *
 *  Created on: Sep 13, 2021
 *      Author: Sa3eed
 */
#include "../../lib/STD_TYPES.h"
#include "../../lib/BitMath.h"
#include "../../mcal/DIO/DIO_interface.h"
#include "../../mcal/DIO/DIO_private.h"
#include "avr/delay.h"
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

u8 keypad(void){
	u8 local_u8PressedKey = KPD_NO_PRESSED_KEY;
	static u8 local_u8KPDArr[4][4] = KPD_ARR_VAL;
	static u8 local_u8ColumnsArr[4]= {KPD_Column0_PIN,KPD_Column1_PIN,KPD_Column2_PIN,KPD_Column3_PIN};
	static u8 local_u8RowsArr[4]= {KPD_Row0_PIN,KPD_Row1_PIN,KPD_Row2_PIN,KPD_Row3_PIN};
	u8 local_u8PinState;
	u8 local_u8ColumnsIdx,
	local_u8RowsIdx;
	/**/
	for (local_u8ColumnsIdx = 0; local_u8ColumnsIdx < 4; ++local_u8ColumnsIdx) {
		Dio_SetPinValue(KPD_PORT, local_u8ColumnsArr[local_u8ColumnsIdx], Dio_High);

		for (local_u8RowsIdx = 0; local_u8RowsIdx < 4; ++local_u8RowsIdx) {
			local_u8PinState = Dio_GetPinValue(KPD_PORT, local_u8RowsArr[local_u8RowsIdx]);
			if (local_u8PinState == Dio_High) //pressed
			{
				local_u8PressedKey = local_u8KPDArr[local_u8RowsIdx][local_u8ColumnsIdx];
				while (local_u8PinState == Dio_High) {
					local_u8PinState = Dio_GetPinValue(KPD_PORT, local_u8RowsArr[local_u8RowsIdx]);
				}

				_delay_ms(10);

			}
		}
		Dio_SetPinValue(KPD_PORT, local_u8ColumnsArr[local_u8ColumnsIdx], Dio_Low);
	}
	return local_u8PressedKey;
}
