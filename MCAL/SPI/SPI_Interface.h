/*
 * SPI_Interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: Moham
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#define SPCR_Register	*((volatile u8*)0x2D)
#define SPSR_Register	*((volatile u8*)0x2E)
#define SPDR_Register	*((volatile u8*)0x2F)

/*SPCR*/
#define SPR0 	0
#define SPR1 	1
#define CPHA 	2
#define CPOL 	3
#define MSTR	4
#define DORD	5
#define SPE		6
#define SPIE	7

/*SPSR*/
#define SPI2X 	0
#define WCOL	6
#define SPIF	7

/*SPDR*/
#define LSB 	0
#define MSB		7

/*PINS*/
#define MOSI 	5
#define MISO 	6
#define SCK	 	7
#define SS 		4





void SPI_MasterInit(void);
void SPI_SlaveInit(void);
void SPI_MasterSend(u8 data);
u8 SPI_MasterRecieve(void);
void SPI_SlaveSend(u8 data);
u8 SPI_SlaveRecieve(void);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
