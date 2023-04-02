/*
 * GInterrupt_Interface.h
 *
 *  Created on: Mar 25, 2023
 *      Author: Moham
 */

#ifndef MCAL_GINTERRUPT_GINTERRUPT_INTERFACE_H_
#define MCAL_GINTERRUPT_GINTERRUPT_INTERFACE_H_

#define SREG *((volatile u8*)0x5F)
#define I	 7


void GInterupt_Enable(void);
void GInterupt_Disable(void);


#endif /* MCAL_GINTERRUPT_GINTERRUPT_INTERFACE_H_ */
