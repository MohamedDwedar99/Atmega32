/*
 * main.c
 *
 *  Created on: Mar 24, 2023
 *      Author: Moham
 */

#include "Service/BIT_MATH.h"
#include "Service/STD.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GInterrupt/GInterrupt_Interface.h"
#include "MCAL/EXTInterrupt/EXTInterrupt_Interface.h"
#include "MCAL/TIMER/Timer_Interface.h"
#include "MCAL/UART/UART_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"
#include "MCAL/I2C/I2C_Interface.h"
#include "util/delay.h"

void main(void)
{
	I2C_SlaveInit(0x20);
	DIO_SetPortDirection(PORTA,0xFF);
	while(1)
	{
		u8 data = 0;
		data = I2C_SlaveRecieveData();
		DIO_SetPortValue(PORTA,data);
	}

}
