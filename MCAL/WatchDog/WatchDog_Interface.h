/*
 * WatchDog_Interface.h
 *
 *  Created on: Mar 27, 2023
 *      Author: Moham
 */

#ifndef WATCHDOG_WATCHDOG_INTERFACE_H_
#define WATCHDOG_WATCHDOG_INTERFACE_H_

#define MCUCSR_Register	*((volatile u8*)0x54)
#define WDTCR_Register 	*((volatile u8*)0x41)

/*MCUCSR*/
#define WDRF 3
/*WDTCR*/
#define WDP0	0
#define WDP1	1
#define WDP2	2
#define WDE		3
#define WDTOE	4

#define WatchDog_Prescaller 0b110 // 1sec

void WatchDog_Init(void);
void WatchDog_Enable(void);
void WatchDog_TurnOff(void);
#endif /* WATCHDOG_WATCHDOG_INTERFACE_H_ */
