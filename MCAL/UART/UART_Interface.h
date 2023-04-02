/*
 * UART_Interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: Moham
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

#define UDR_Register	*((volatile u16*)0x2C)
/*#define UDR_R           *((volatile u8*)0x)
#define UDR_W           *((volatile u8*)0x)*/
#define UCSRA_Register  *((volatile u8*)0x2B)
#define UCSRB_Register  *((volatile u8*)0x2A)
#define UCSRC_Register  *((volatile u8*)0x40)
#define UBRRL_Register  *((volatile u8*)0x29)
#define UBRRH_Register  *((volatile u8*)0x40)

#define BAUD_2400	207
#define BAUD_4800	103
#define BAUD_9600	51
#define BAUD_14400	34
#define BAUD_19200	25


/*UCSRA*/
#define MPCM	0
#define U2x		1
#define PE		2
#define DOR		3
#define FE		4
#define UDRE	5
#define TXC		6
#define RXC		7

/*UCSRB*/
#define TXB8	0
#define RXB8	1
#define UCSZ2	2
#define TXEN	3
#define RXEN	4
#define UDRIE	5
#define TXCIE	6
#define RXCIE	7

/*UCSRC*/
#define UCPOL	0
#define UCSZ0	1
#define UCSZ1	2
#define USBS	3
#define UPM0	4
#define UPMM1	5
#define UMSEL	6
#define URSEL	7




void UART_Init(u16 baud);
void UART_Transmit(u8 data );
u8 UART_Receive( void );

#endif /* MCAL_UART_UART_INTERFACE_H_ */
