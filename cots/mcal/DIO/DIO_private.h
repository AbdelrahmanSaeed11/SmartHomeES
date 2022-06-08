/*
 * DIO_private.h
 *
 *  Created on: Sep 2, 2021
 *      Author: Sa3eed
 */

#ifndef COTS_MCAL_DIO_DIO_PRIVATE_H_
#define COTS_MCAL_DIO_DIO_PRIVATE_H_

#define PortA *((volatile u8*) 0x3B)
#define DDRA  *((volatile u8*) 0x3A)
#define PinA  *((volatile u8*) 0x39)

#define PortB *((volatile u8*) 0x38)
#define DDRB  *((volatile u8*) 0x37)
#define PinB  *((volatile u8*) 0x36)

#define PortC *((volatile u8*) 0x35)
#define DDRC  *((volatile u8*) 0x34)
#define PinC  *((volatile u8*) 0x33)

#define PortD *((volatile u8*) 0x32)
#define DDRD  *((volatile u8*) 0x31)
#define PinD  *((volatile u8*) 0x30)

#endif /* COTS_MCAL_DIO_DIO_PRIVATE_H_ */
