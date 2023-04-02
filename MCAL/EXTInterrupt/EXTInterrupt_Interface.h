/*
 * EXTInterrupt_Interface.h
 *
 *  Created on: Mar 25, 2023
 *      Author: Moham
 */

#ifndef MCAL_EXTINTERRUPT_EXTINTERRUPT_INTERFACE_H_
#define MCAL_EXTINTERRUPT_EXTINTERRUPT_INTERFACE_H_

#define MCUCR_Register	*((volatile u8*)0x55)
#define	MCUCSR_Register *((volatile u8*)0x54)
#define GICR_Register   *((volatile u8*)0x5B)
#define GIFR_Register   *((volatile u8*)0x5A)

//MCUCR
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

//MCUCSR
#define ISC2 6

//GICR
#define INT0 6
#define INT1 7
#define INT2 5

//GIFR
#define INTF0 6
#define INTF1 7
#define INTF2 5

/*Interrupt Library*/
#define EXTI0 __vector_1
#define EXTI1 __vector_2
#define EXTI2 __vector_3



/*Initialization*/
				//INT0
void EXTI0_LowLevelInit(void);
void EXTI0_FailingEdgeInit(void);
void EXTI0_RisingEdgeInit(void);
void EXTI0_AnyChangeInit(void);

				//INT1
void EXTI1_LowLevelInit(void);
void EXTI1_FailingEdgeInit(void);
void EXTI1_RisingEdgeInit(void);
void EXTI1_AnyChangeInit(void);

				//INT2
void EXTI1_FailingEdge(void);
void EXTI1_RisingEdge(void);

/*Enable*/
void EXTI0_Enable(void);
void EXTI1_Enable(void);
void EXTI2_Enable(void);

/*Disable*/
void EXTI0_Disable(void);
void EXTI1_Disable(void);
void EXTI2_Disable(void);

/*Clear Flag By Adding Logical 1*/
void EXTI0_ClearFlag(void);
void EXTI1_ClearFlag(void);
void EXTI2_ClearFlag(void);

void __vector_1 (void) __attribute__((signal,used));
void __vector_2 (void) __attribute__((signal,used));
void __vector_3 (void) __attribute__((signal,used));

#endif /* MCAL_EXTINTERRUPT_EXTINTERRUPT_INTERFACE_H_ */
