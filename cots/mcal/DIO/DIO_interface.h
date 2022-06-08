/*
 * DIO_interface.h
 *
 *  Created on: Sep 2, 2021
 *      Author: Sa3eed
 */

#ifndef COTS_MCAL_DIO_DIO_INTERFACE_H_
#define COTS_MCAL_DIO_DIO_INTERFACE_H_
// Ports
#define Dio_PortA 0
#define Dio_PortB 1
#define Dio_PortC 2
#define Dio_PortD 3
// Pins
#define Dio_Pin0 0
#define Dio_Pin1 1
#define Dio_Pin2 2
#define Dio_Pin3 3
#define Dio_Pin4 4
#define Dio_Pin5 5
#define Dio_Pin6 6
#define Dio_Pin7 7
// Values
#define Dio_High 1
#define Dio_Low 0
// Directions
#define Dio_directionIn 0
#define Dio_directionOut 1
// Functions
void Dio_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void Dio_SetPortDirection(u8 Port, u8 Direction);
void Dio_SetPinValue(u8 Port, u8 Pin, u8 Value);
void Dio_SetPortValue(u8 Port, u8 Value);
u8 Dio_GetPinValue(u8 Port, u8 Pin);
u8 Dio_GetPortValue(u8 Port);


#endif /* COTS_MCAL_DIO_DIO_INTERFACE_H_ */
