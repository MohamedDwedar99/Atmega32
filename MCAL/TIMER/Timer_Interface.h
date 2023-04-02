/*
 * Timer_Interface.h
 *
 *  Created on: Mar 27, 2023
 *      Author: Moham
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

#define TCCR0_Register		*((volatile u8*)0x53)
#define TCNT0_Register      *((volatile u8*)0x52)
#define OCR0_Register       *((volatile u8*)0x5C)
#define TIMSK_Register     	*((volatile u8*)0x59)
#define TIFR_Register       *((volatile u8*)0x58)

/*TCCR0*/
#define CS00	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00	4
#define COM01	5
#define WGM00	6
#define FOC0	7
/*TIMSK*/
#define TOIE0 0
#define OCIE0 1
/*TIFR*/
#define TOV0 0
#define OCF0 1

#define Initial_Count 0
#define Timer_Prescaler 3
#define Compare_Count 200

void TIMER0Normal_Init(void);
void TIMER0PwmPhaseCorrect_Init(void);
void TIMER0CTC_Init(void);
void TIMER0PwmFast_Init(void);
void TIMER0PwmFast_Duty(f32 Duty);

void __vector_10 (void) __attribute__((signal,used));
void __vector_11 (void) __attribute__((signal,used));


#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
