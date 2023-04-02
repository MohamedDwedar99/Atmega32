/*
 * BIT_MATH.h
 *
 *  Created on: Mar 24, 2023
 *      Author: Moham
 */

#ifndef SERVICE_BIT_MATH_H_
#define SERVICE_BIT_MATH_H_

#define SET_BIT(VAR,BITNO) (VAR) = (VAR)|(1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) = (VAR) & ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) = (VAR) ^ (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)
#endif /* SERVICE_BIT_MATH_H_ */
