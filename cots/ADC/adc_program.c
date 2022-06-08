/*
 * adc_program.c
 *
 *  Created on: Sep 13, 2021
 *      Author: Sa3eed
 */
#include <avr/io.h>
#include "../lib/STD_TYPES.h"
#include "../lib/BitMath.h"
#include "../mcal/DIO/DIO_interface.h"
#include "../mcal/DIO/DIO_private.h"
#include "adc_interface.h"


void ADC_Init (void)
{
	// ADC Enable
	setBit(ADCSRA_Reg,7);

	// Prescaler Configuration as 128
	setBit(ADCSRA_Reg,2);
	setBit(ADCSRA_Reg,1);
	setBit(ADCSRA_Reg,0);


	// Reference Voltage as AVCC with external capacitor
	ADMUX=0x00;
//	Clr_Bit(ADMUX_Reg,7);
	setBit(ADMUX_Reg,6);

	// ADC Data Adjustment
//	Clr_Bit(ADMUX_Reg,5);
}

u16 ADC_Read (u8 channel)
{
	// ADC Channel Selection
	channel &= 0x07;
	ADMUX_Reg &= 0xF8;
	ADMUX_Reg |= channel;

	// Start Single Conversion
	setBit(ADCSRA_Reg,6);

	//wait for the conversion from analog to digital
	while((ADCSRA_Reg & (1<<6)));

	//ADC Flag Clear
	//Set_Bit(ADCSRA_Reg,4);

	return ADC;
}
