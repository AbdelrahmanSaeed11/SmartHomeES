#include "../../lib/STD_TYPES.h"
#include "../../lib/BitMath.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void Dio_SetPinDirection(u8 Port, u8 Pin, u8 Direction)
{
	if(Direction == Dio_directionOut)
	{
		switch(Port)
		{
		  case Dio_PortA: setBit(DDRA,Pin); break;
		  case Dio_PortB: setBit(DDRB,Pin); break;
		  case Dio_PortC: setBit(DDRC,Pin); break;
		  case Dio_PortD: setBit(DDRD,Pin); break;
		}
	}
	else if(Direction == Dio_directionIn)
	{
		switch(Port)
		{
		  case Dio_PortA: clrBit(DDRA,Pin); break;
	      case Dio_PortB: clrBit(DDRB,Pin); break;
   	      case Dio_PortC: clrBit(DDRC,Pin); break;
	      case Dio_PortD: clrBit(DDRD,Pin); break;
		}
	}
}

void Dio_SetPortDirection(u8 Port, u8 Direction)
{
	switch(Port)
	{
	  case Dio_PortA: DDRA = Direction; break;
	  case Dio_PortB: DDRB = Direction; break;
	  case Dio_PortC: DDRC = Direction; break;
	  case Dio_PortD: DDRD = Direction; break;
	}
}

void Dio_SetPinValue(u8 Port,u8 Pin,u8 Value)
{
	if(Value == Dio_High)
		{
			switch(Port)
			{
			  case Dio_PortA: setBit(PortA,Pin); break;
			  case Dio_PortB: setBit(PortB,Pin); break;
			  case Dio_PortC: setBit(PortC,Pin); break;
			  case Dio_PortD: setBit(PortD,Pin); break;
			}
		}
		else if(Value == Dio_Low)
		{
			switch(Port)
			{
		   	  case Dio_PortA: clrBit(PortA,Pin); break;
		      case Dio_PortB: clrBit(PortB,Pin); break;
	   	      case Dio_PortC: clrBit(PortC,Pin); break;
		      case Dio_PortD: clrBit(PortD,Pin); break;
			}
		}
}

void Dio_SetPortValue(u8 Port,u8 Value)
{
	switch(Port)
		{
		  case Dio_PortA: PortA = Value; break;
		  case Dio_PortB: PortB = Value; break;
		  case Dio_PortC: PortC = Value; break;
		  case Dio_PortD: PortD = Value; break;
		}
}

u8 Dio_GetPinValue(u8 Port,u8 Pin)
{
	u8 ret = 0;
	switch(Port)
	{
	  case Dio_PortA: ret = getBit(PinA,Pin); break;
	  case Dio_PortB: ret = getBit(PinB,Pin); break;
	  case Dio_PortC: ret = getBit(PinC,Pin); break;
	  case Dio_PortD: ret = getBit(PinD,Pin); break;
	}
	return ret;

}

u8 Dio_GetPortValue(u8 Port)
{
	u8 ret = 0;
	switch(Port)
			{
	            case Dio_PortA: ret = PinA ; break;
	            case Dio_PortB: ret = PinB ; break;
	            case Dio_PortC: ret = PinC ; break;
	            case Dio_PortD: ret = PinD ; break;
			}
	return ret;
}
