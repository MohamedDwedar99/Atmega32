/*
 * Segment7_interface.h
 *
 *  Created on: Mar 25, 2023
 *      Author: Moham
 */

#ifndef HAL_SEGMENT7_SEGMENT7_INTERFACE_H_
#define HAL_SEGMENT7_SEGMENT7_INTERFACE_H_

#define ZERO 	0x3F
#define ONE		0x06
#define TWO 	0x5B
#define THREE 	0x4F
#define FOUR 	0x66
#define FIVE 	0x6D
#define SIX 	0x7D
#define SEVEN 	0x07
#define EIGHT 	0x7F
#define NINE 	0x6F

void Segment7_Init(u8 PortCopy);
void Segment7_SetValue(u8 PortCopy,u8 ValCopy);
void Segment7_DisplayON(u8 PortCopy);
void Segment7_DisplayOFF(u8 PortCopy);
#endif /* HAL_SEGMENT7_SEGMENT7_INTERFACE_H_ */
