/*
 * UART_Program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: Moham
 */

#include "../../Service/BIT_MATH.h"
#include "../../Service/STD.h"
#include "UART_Interface.h"
#include "../DIO/DIO_interface.h"

void UART_Init(u16 baud)
{
	/*Set Baud Rate*/
	UBRRH_Register = (u8)(baud>>8);
	UBRRL_Register = (u8)baud;
	/*Enable reciever & transmitter*/
	UCSRB_Register = (1<<RXEN)|(1<<TXEN);
	/*Set frame format: 8data, 2stop bit*/
	UCSRC_Register = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}

void UART_Transmit(u8 data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA_Register & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR_Register = data;
}

u8 UART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA_Register & (1<<RXC)) );
	/* Get and return received data from buffer */
	return UDR_Register;
}
