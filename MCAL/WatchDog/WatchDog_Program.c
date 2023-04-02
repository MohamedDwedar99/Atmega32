/*
 * WatchDog_Program.c
 *
 *  Created on: Mar 27, 2023
 *      Author: Moham
 */

#include "../../Service/BIT_MATH.h"
#include "../../Service/STD.h"
#include "WatchDog_Interface.h"

void WatchDog_Init(void)
{
	WDTCR_Register |= WatchDog_Prescaller;
}
void WatchDog_Enable(void)
{
	SET_BIT(WDTCR_Register,WDE);
}
void WatchDog_TurnOff(void)
{
	u8 clearant = 0;
	clearant = clearant | WatchDog_Prescaller;
	WDTCR_Register &= clearant;
}
