/*
 * DIO.h
 *
 *  Created on: Mar 24, 2023
 *      Author: Moham
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_



/* Group A Registers */
#define PORTA_Register  *((volatile u8*)0x3B)
#define DDRA_Register   *((volatile u8*)0x3A)
#define PINA_Register   *((volatile u8*)0x39)

/* Group B Registers */
#define PORTB_Register  *((volatile u8*)0x38)
#define DDRB_Register   *((volatile u8*)0x37)
#define PINB_Register   *((volatile u8*)0x36)

/* Group C Registers */
#define PORTC_Register  *((volatile u8*)0x35)
#define DDRC_Register   *((volatile u8*)0x34)
#define PINC_Register   *((volatile u8*)0x33)

/* Group D Registers */
#define PORTD_Register  *((volatile u8*)0x32)
#define DDRD_Register   *((volatile u8*)0x31)
#define PIND_Register   *((volatile u8*)0x30)

//PORT Status
#define PORT_LOW  	0x00
#define PORT_HIGH 	0xFF
#define PORT_INPUT	0x00
#define PORT_OUTPUT 0xFF

//PIN Status
#define PIN_LOW		0
#define PIN_HIGH	1
#define PIN_INPUT	0
#define PIN_OUTPUT	1

//PIN Name

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//Port Name

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
//PINs APIs
void DIO_SetPinDirection(u8 PortCopy,u8 PinCopy,u8 PinDirCopy);
void DIO_SetPinValue(u8 PortCopy,u8 PinCopy,u8 PinValCopy);
void DIO_TogPinValue(u8 PortCopy,u8 PinCopy);
u8 DIO_GetPinValue(u8 PortCopy,u8 PinCopy);

//PORTs APIs
void DIO_SetPortDirection(u8 PortCopy,u8 PortDirCopy);
void DIO_SetPortValue(u8 PortCopy,u8 PortValCopy);
void DIO_TogPortValue(u8 PortCopy);
u8 DIO_GetPortValue(u8 PortCopy);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
