/*
 * SPI_Program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: Moham
 */
#include "../../Service/BIT_MATH.h"
#include "../../Service/STD.h"
#include "../DIO/DIO_interface.h"
#include "SPI_Interface.h"

void SPI_MasterInit(void)
{
	//set pins
	DIO_SetPinDirection(PORTB,MOSI,PIN_OUTPUT);
	DIO_SetPinDirection(PORTB,MISO,PIN_INPUT);
	DIO_SetPinDirection(PORTB,SS,PIN_OUTPUT);
	DIO_SetPinDirection(PORTB,SCK,PIN_OUTPUT);
	//set ss high
	DIO_SetPinValue(PORTB,SS,PIN_HIGH);
	//Select master
	SET_BIT(SPCR_Register,SPE);
	SET_BIT(SPCR_Register,MSTR);
	//Set Prescaller
	SPCR_Register = SET_BIT(SPCR_Register,SPR0);

}
void SPI_MasterSend(u8 data)
{
	//set ss low
	DIO_SetPinValue(PORTB,SS,PIN_LOW);
	//put data in data
	SPDR_Register = data;
	//wait till transmitiom
	while(!GET_BIT(SPSR_Register,SPIF));
	//Flush Data
	data = SPDR_Register;
	//set ss high
	DIO_SetPinValue(PORTB,SS,PIN_HIGH);
}
u8 SPI_MasterRecieve(void)
{
	SPDR_Register = 0XFF;
	while(!GET_BIT(SPSR_Register,SPIF));
	return SPDR_Register;
}
void SPI_SlaveInit(void)
{
	//set pins
	DIO_SetPinDirection(PORTB,MOSI,PIN_INPUT);
	DIO_SetPinDirection(PORTB,MISO,PIN_OUTPUT);
	DIO_SetPinDirection(PORTB,SS,PIN_INPUT);
	DIO_SetPinDirection(PORTB,SCK,PIN_INPUT);
	//Enable SPI
	SET_BIT(SPCR_Register,SPE);
}
void SPI_SlaveSend(u8 data)
{
	//Set output to pin messege master
	//DIO_SetPinValue(PORTB,PIN0,PIN_HIGH);
	//DIO_SetPinValue(PORTB,PIN0,PIN_HIGH);
	//put data in data
	SPDR_Register = data;
	//wait till transmitiom
	while(!GET_BIT(SPSR_Register,SPIF));
	//Flush Data
	data = SPDR_Register;
	//DIO_SetPinValue(PORTB,PIN0,PIN_LOW);

}
u8 SPI_SlaveRecieve(void)
{
	SPDR_Register = 0XFF;
	while(!GET_BIT(SPSR_Register,SPIF));
	return SPDR_Register;
}

