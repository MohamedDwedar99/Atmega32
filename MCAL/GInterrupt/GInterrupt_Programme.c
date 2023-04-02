/*
 * GInterrupt_Programme.c
 *
 *  Created on: Mar 25, 2023
 *      Author: Mohamed
 */

#include "../../Service/BIT_MATH.h"
#include "../../Service/STD.h"
#include "GInterrupt_Interface.h"

void GInterupt_Enable(void)
{
	SET_BIT(SREG,I);
}
void GInterupt_Disable(void)
{
	CLR_BIT(SREG,I);
}
