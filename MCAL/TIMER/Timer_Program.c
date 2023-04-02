/*
 * Timer_Program.c
 *
 *  Created on: Mar 27, 2023
 *      Author: Moham
 */

#include "../../Service/BIT_MATH.h"
#include "../../Service/STD.h"
#include "../DIO/DIO_interface.h"
#include "Timer_Interface.h"

void TIMER0Normal_Init(void)
{
	//Set Mode
	CLR_BIT(TCCR0_Register,WGM00);
	CLR_BIT(TCCR0_Register,WGM01);
	//Set Starting Value
	TCNT0_Register = Initial_Count;
	//Enable Interrupt
	SET_BIT(TIMSK_Register,TOIE0);
	//Set Prescaler
	TCCR0_Register = (TCCR0_Register & !7) | Timer_Prescaler;
}
/*void TIMER0PwmPhaseCorrect_Init(void)
{
	//Set Mode
	SET_BIT(TCCR0_Register,WGM00);
	CLR_BIT(TCCR0_Register,WGM01);
	//Set Starting Value
	TCNT0_Register = Initial_Count;
	//Enable Interrupt
	SET_BIT(TIFR_Register,TOV0);
	//Set Prescaler
	TCCR0_Register = (TCCR0_Register & 7) | Timer_Prescaler;
}*/
void TIMER0CTC_Init(void)
{
	//Set Mode
	CLR_BIT(TCCR0_Register,WGM00);
	SET_BIT(TCCR0_Register,WGM01);
	//Set Starting Value
	OCR0_Register = Compare_Count;
	//Enable Interrupt
	SET_BIT(TIMSK_Register,OCIE0);
	//Set Prescaler
	TCCR0_Register = (TCCR0_Register & !7) | Timer_Prescaler;
}
void TIMER0PwmFast_Init(void)
{
	//Set Mode
	SET_BIT(TCCR0_Register,WGM00);
	SET_BIT(TCCR0_Register,WGM01);
	//Set Starting Value
	TCNT0_Register = 0;
	//Enable Interrupt
	SET_BIT(TIMSK_Register,OCIE0);
	SET_BIT(TIMSK_Register,TOIE0);
}

void TIMER0PwmFast_Duty(f32 Duty)
{
	OCR0_Register = (u8)(Duty * 256 -1);
	//Set Prescaler
	TCCR0_Register = (TCCR0_Register & 0b11111000) | Timer_Prescaler;
}

void __vector_10(void)
{
	DIO_TogPinValue(PORTA,PIN0);
}
void __vector_11(void)
{
	DIO_TogPinValue(PORTA,PIN0);
}
