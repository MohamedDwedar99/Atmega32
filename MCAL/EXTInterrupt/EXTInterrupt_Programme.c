/*
 * EXTInterrupt_Programme.c
 *
 *  Created on: Mar 25, 2023
 *      Author: Moham
 */
#include "../../Service/BIT_MATH.h"
#include "../../Service/STD.h"
#include "EXTInterrupt_Interface.h"
#include "../DIO/DIO_interface.h"

/*Interrupt_0 Initialization & program*/
void EXTI0_LowLevelInit(void)
{
	CLR_BIT(MCUCR_Register,ISC00);
	CLR_BIT(MCUCR_Register,ISC01);
	EXTI0_Enable();
	DIO_SetPinDirection(PORTD,PIN2,PIN_INPUT);
	DIO_SetPinValue(PORTD,PIN2,PIN_HIGH);
}
void EXTI0_FailingEdgeInit(void)
{
	CLR_BIT(MCUCR_Register,ISC00);
	SET_BIT(MCUCR_Register,ISC01);
	EXTI0_Enable();
	DIO_SetPinDirection(PORTD,PIN2,PIN_INPUT);
	DIO_SetPinValue(PORTD,PIN2,PIN_HIGH);
}
void EXTI0_RisingEdgeInit(void)
{
	SET_BIT(MCUCR_Register,ISC00);
	SET_BIT(MCUCR_Register,ISC01);
	EXTI0_Enable();
	DIO_SetPinDirection(PORTD,PIN2,PIN_INPUT);
	DIO_SetPinValue(PORTD,PIN2,PIN_HIGH);
}
void EXTI0_AnyChangeInit(void)
{
	SET_BIT(MCUCR_Register,ISC00);
	CLR_BIT(MCUCR_Register,ISC01);
	EXTI0_Enable();
	DIO_SetPinDirection(PORTD,PIN2,PIN_INPUT);
	DIO_SetPinValue(PORTD,PIN2,PIN_HIGH);
}

void EXTI0_Enable(void)
{
	SET_BIT(GICR_Register,INT0);
}

void EXTI0_Disable(void)
{
	CLR_BIT(GICR_Register,INT0);
}

void EXTI0_ClearFlag(void)
{
	SET_BIT(GICR_Register,INTF0);
}
/*Interrupt_1 Initialization & program*/
void EXTI1_LowLevelInit(void)
{
	CLR_BIT(MCUCR_Register,ISC10);
	CLR_BIT(MCUCR_Register,ISC11);
	EXTI1_Enable();
	DIO_SetPinDirection(PORTD,PIN3,PIN_INPUT);
	DIO_SetPinValue(PORTD,PIN3,PIN_HIGH);
}
void EXTI1_FailingEdgeInit(void)
{
	CLR_BIT(MCUCR_Register,ISC10);
	SET_BIT(MCUCR_Register,ISC11);
	EXTI1_Enable();
	DIO_SetPinDirection(PORTD,PIN3,PIN_INPUT);
	DIO_SetPinValue(PORTD,PIN3,PIN_HIGH);
}
void EXTI1_RisingEdgeInit(void)
{
	SET_BIT(MCUCR_Register,ISC10);
	SET_BIT(MCUCR_Register,ISC11);
	EXTI1_Enable();
	DIO_SetPinDirection(PORTD,PIN3,PIN_INPUT);
	DIO_SetPinValue(PORTD,PIN3,PIN_HIGH);
}
void EXTI1_AnyChangeInit(void)
{
	SET_BIT(MCUCR_Register,ISC10);
	CLR_BIT(MCUCR_Register,ISC11);
	EXTI1_Enable();
	DIO_SetPinDirection(PORTD,PIN3,PIN_INPUT);
	DIO_SetPinValue(PORTD,PIN3,PIN_HIGH);
}

void EXTI1_Enable(void)
{
	SET_BIT(GICR_Register,INT1);
}

void EXTI1_Disable(void)
{
	CLR_BIT(GICR_Register,INT1);
}

void EXTI1_ClearFlag(void)
{
	SET_BIT(GICR_Register,INTF1);
}

/*Interrupt_2 Initialization & program*/
void EXTI2_FailingEdgeInit(void)
{
	CLR_BIT(MCUCSR_Register,ISC2);
	EXTI2_Enable();
	DIO_SetPinDirection(PORTB,PIN2,PIN_INPUT);
	DIO_SetPinValue(PORTB,PIN2,PIN_HIGH);
}
void EXTI2_RisingEdgeInit(void)
{
	SET_BIT(MCUCSR_Register,ISC2);
	EXTI2_Enable();
	DIO_SetPinDirection(PORTB,PIN2,PIN_INPUT);
	DIO_SetPinValue(PORTB,PIN2,PIN_HIGH);
}
void EXTI2_Enable(void)
{
	SET_BIT(GICR_Register,INT2);
}

void EXTI2_Disable(void)
{
	CLR_BIT(GICR_Register,INT2);
}

void EXTI2_ClearFlag(void)
{
	SET_BIT(GICR_Register,INTF2);
}

void __vector_1 (void)
{
	DIO_TogPinValue(PORTA,PIN0);
}

void __vector_2 (void)
{

}

void __vector_3 (void)
{

}
