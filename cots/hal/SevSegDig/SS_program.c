/*
 * SS_program.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Sa3eed
 */
#include "../../lib/STD_TYPES.h"
#include "../../lib/BitMath.h"
#include "../../mcal/DIO/DIO_interface.h"
#include "SS_interface.h"
#include "SS_private.h"
#include "SS_config.h"

u8 num[] = {
		0b00111111, // 0
		0b00000110, // 1
		0b01011011, // 2
		0b01001111, // 3
		0b01100110, // 4
		0b01101101, // 5
		0b01111101, // 6
		0b00000111, // 7
		0b01111111, // 8
		0b01101111, // 9
};

void SS_init(){
	Dio_SetPortDirection(Dio_PortC, 0xff);
}

void SS_PrintNum(u8 n){
	if (n < 10){
		Dio_SetPortValue(Dio_PortC, num[n]);
	}
}
