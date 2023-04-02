/*
 * ADC_Interface.h
 *
 *  Created on: Mar 26, 2023
 *      Author: Moham
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#define ADMUX_Register    *((volatile u8*)0x27)
#define ADCSRA_Register   *((volatile u8*)0x26)
#define SFIOR_Register    *((volatile u8*)0x50)
#define ADCH_Register     *((volatile u8*)0x25)
#define ADCL_Register     *((volatile u8*)0x24)
#define ADC_Register	  *((volatile u16*)0x24)

#define PRESCALER_2 	  0b000
#define PRESCALER_4       0b010
#define PRESCALER_8       0b011
#define PRESCALER_16      0b100
#define PRESCALER_32      0b101
#define PRESCALER_64      0b110
#define PRESCALER_128     0b111

/*ADMUX*/
#define MUX0	0
#define MUX1	1
#define MUX2	2
#define MUX3	3
#define MUX4	4
#define ADLAR	5
#define REFS0	6
#define REFS1	7

#define ADC0 0b000
#define ADC1 0b001
#define ADC2 0b010
#define ADC3 0b011
#define ADC4 0b100
#define ADC5 0b101
#define ADC6 0b110
#define ADC7 0b111

/*ADCSRA*/
#define ADPS0	0
#define ADPS1   1
#define ADPS2   2
#define ADIE 	3
#define ADIF 	4
#define ADATE  	5
#define ADSC   	6
#define ADEN   	7

/*SFIOR*/

#define BIT4	4
#define ADTS0	5
#define ADTS1	6
#define ADTS2	7

void ADC_Init(void);

void ADC_TurnON(void);
void ADC_TurnOFF(void);

u16 ADC0_Read(void);
u16 ADC1_Read(void);
u16 ADC2_Read(void);
u16 ADC3_Read(void);
u16 ADC4_Read(void);
u16 ADC5_Read(void);
u16 ADC6_Read(void);
u16 ADC7_Read(void);




#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
