/*
 * Segment7_Programe.c
 *
 *  Created on: Mar 25, 2023
 *      Author: Moham
 */

#include "../../Service/BIT_MATH.h"
#include "../../Service/STD.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "Segment7_interface.h"

u8 NUM[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

void Segment7_Init(u8 PortCopy)
{
	DIO_SetPortDirection(PortCopy,PORT_OUTPUT);
}
void Segment7_SetValue(u8 PortCopy,u8 ValCopy)
{
	DIO_SetPortValue(PortCopy,ValCopy);
}
void Segment7_DisplayON(u8 PortCopy)
{
	DIO_SetPinValue(PortCopy,PIN7,PIN_LOW);
}
void Segment7_DisplayOFF(u8 PortCopy)
{
	DIO_SetPinValue(PortCopy,PIN7,PIN_HIGH);
}
