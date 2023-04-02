/*
 * Programe.c
 *
 *  Created on: Mar 24, 2023
 *      Author: Moham
 */

#include "../../Service/BIT_MATH.h"
#include "../../Service/STD.h"
#include "DIO_interface.h"

void DIO_SetPinDirection(u8 PortCopy,u8 PinCopy,u8 PinDirCopy)
{
	switch (PinDirCopy)
	{
	case PIN_OUTPUT:
		switch (PortCopy)
		{
		case PORTA: SET_BIT(DDRA_Register,PinCopy);break;
		case PORTB: SET_BIT(DDRB_Register,PinCopy);break;
		case PORTC: SET_BIT(DDRC_Register,PinCopy);break;
		case PORTD: SET_BIT(DDRD_Register,PinCopy);break;
		}
		break;
	case PIN_INPUT:
		switch (PortCopy)
		{
		case PORTA: CLR_BIT(DDRA_Register,PinCopy);break;
		case PORTB: CLR_BIT(DDRB_Register,PinCopy);break;
		case PORTC: CLR_BIT(DDRC_Register,PinCopy);break;
		case PORTD: CLR_BIT(DDRD_Register,PinCopy);break;
		}
		break;
	}
}
void DIO_SetPinValue(u8 PortCopy,u8 PinCopy,u8 PinValCopy)
{
	switch (PinValCopy)
	{
	case PIN_HIGH:
		switch (PortCopy)
		{
		case PORTA: SET_BIT(PORTA_Register,PinCopy);break;
		case PORTB: SET_BIT(PORTB_Register,PinCopy);break;
		case PORTC: SET_BIT(PORTC_Register,PinCopy);break;
		case PORTD: SET_BIT(PORTD_Register,PinCopy);break;
		}
		break;
	case PIN_LOW:
		switch (PortCopy)
		{
		case PORTA: CLR_BIT(PORTA_Register,PinCopy);break;
		case PORTB: CLR_BIT(PORTB_Register,PinCopy);break;
		case PORTC: CLR_BIT(PORTC_Register,PinCopy);break;
		case PORTD: CLR_BIT(PORTD_Register,PinCopy);break;
		}
		break;
	}
}
void DIO_TogPinValue(u8 PortCopy,u8 PinCopy)
{
	switch (PortCopy)
	{
	case PORTA: TOG_BIT(PORTA_Register,PinCopy);break;
	case PORTB: TOG_BIT(PORTB_Register,PinCopy);break;
	case PORTC: TOG_BIT(PORTC_Register,PinCopy);break;
	case PORTD: TOG_BIT(PORTD_Register,PinCopy);break;
	}
}
u8 DIO_GetPinValue(u8 PortCopy,u8 PinCopy)
{
	u8 BIT;
	switch (PortCopy)
	{
	case PORTA: BIT = GET_BIT(PINA_Register,PinCopy);break;
	case PORTB: BIT = GET_BIT(PINB_Register,PinCopy);break;
	case PORTC: BIT = GET_BIT(PINC_Register,PinCopy);break;
	case PORTD: BIT = GET_BIT(PIND_Register,PinCopy);break;
	}
	return BIT;
}




void DIO_SetPortDirection(u8 PortCopy,u8 PortDirCopy)
{

	switch (PortCopy)
	{
	case PORTA:DDRA_Register = PortDirCopy; break;
	case PORTB:DDRB_Register = PortDirCopy; break;
	case PORTC:DDRC_Register = PortDirCopy; break;
	case PORTD:DDRD_Register = PortDirCopy; break;
	}
}
void DIO_SetPortValue(u8 PortCopy,u8 PortValCopy)
{
	switch (PortCopy)
	{
	case PORTA:PORTA_Register = PortValCopy; break;
	case PORTB:PORTB_Register = PortValCopy; break;
	case PORTC:PORTC_Register = PortValCopy; break;
	case PORTD:PORTD_Register = PortValCopy; break;
	}

}
void DIO_TogPortValue(u8 PortCopy)
{
	switch (PortCopy)
	{
	case PORTA:PORTA_Register ^= 0xFF; break;
	case PORTB:PORTB_Register ^= 0xFF; break;
	case PORTC:PORTC_Register ^= 0xFF; break;
	case PORTD:PORTD_Register ^= 0xFF; break;
	}
}
u8 DIO_GetPortValue(u8 PortCopy)
{
	switch (PortCopy)
	{
	case PORTA:return(PINA_Register); break;
	case PORTB:return(PINB_Register); break;
	case PORTC:return(PINC_Register); break;
	case PORTD:return(PIND_Register); break;
	}
	return 0;
}
