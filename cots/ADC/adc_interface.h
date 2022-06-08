/*
 * adc_interface.h
 *
 *  Created on: Sep 13, 2021
 *      Author: Sa3eed
 */

#ifndef COTS_ADC_ADC_INTERFACE_H_
#define COTS_ADC_ADC_INTERFACE_H_

#define ADMUX_Reg 	*((volatile u8*)0x27) 	// ADC Multiplexer Register
#define ADCSRA_Reg 	*((volatile u8*)0x26) 	// ADC Control And Status Register
#define ADCH_Reg 	*((volatile u8*)0x25) 		// ADC High Register
#define ADCL_Reg 	*((volatile u8*)0x24) 		// ADC Low Register


void ADC_Init (void); // ADC Initialization And Enable
//u16 ADC_Read (u8 channel); // Read From The ADC Channel
u16 ADC_Read (u8 channel);

#endif /* COTS_ADC_ADC_INTERFACE_H_ */
