/*
 * ADC_Programme.c
 *
 *  Created on: Mar 26, 2023
 *      Author: Moham
 */

#include "../../Service/BIT_MATH.h"
#include "../../Service/STD.h"
#include "../DIO/DIO_interface.h"
#include "ADC_Interface.h"

void ADC_Init(void)
{
	/*Make ADC Channels Inputs*/
	PORTA_Register = 0xFF;
	/*Select Reference Voltage*/
	SET_BIT(ADMUX_Register,REFS0);
	CLR_BIT(ADMUX_Register,REFS1);
	/*Select Adjustment Right*/
	CLR_BIT(ADMUX_Register,ADLAR);
	/*Turn On ADC*/
	SET_BIT(ADCSRA_Register,ADEN);
	/*Select Prescaler*/
	ADCSRA_Register |= PRESCALER_2;

}

u16 ADC0_Read(void)
{
	/*Select MUX*/
	ADMUX_Register = (ADMUX_Register & 0b11100000) | ADC0;
	/*Start Conversion*/
	SET_BIT(ADCSRA_Register,ADSC);
	/*Wait Till end*/
	while(~(GET_BIT(ADCSRA_Register,ADIF)));
	/*Clear Flag*/
	SET_BIT(ADCSRA_Register,ADIF);
	/*return Reading*/
	return ADC_Register;
}
u16 ADC1_Read(void)
{
	/*Select MUX*/
	ADMUX_Register = (ADMUX_Register & 0b11100000) | ADC1;
	/*Start Conversion*/
	SET_BIT(ADCSRA_Register,ADSC);
	/*Wait Till end*/
	while(~(GET_BIT(ADCSRA_Register,ADIF)));
	/*Clear Flag*/
	SET_BIT(ADCSRA_Register,ADIF);
	/*return Reading*/
	return ADC_Register;
}
u16 ADC2_Read(void)
{
	/*Select MUX*/
	ADMUX_Register = (ADMUX_Register & 0b11100000) | ADC2;
	/*Start Conversion*/
	SET_BIT(ADCSRA_Register,ADSC);
	/*Wait Till end*/
	while(~(GET_BIT(ADCSRA_Register,ADIF)));
	/*Clear Flag*/
	SET_BIT(ADCSRA_Register,ADIF);
	/*return Reading*/
	return ADC_Register;
}
u16 ADC3_Read(void)
{
	/*Select MUX*/
	ADMUX_Register = (ADMUX_Register & 0b11100000) | ADC3;
	/*Start Conversion*/
	SET_BIT(ADCSRA_Register,ADSC);
	/*Wait Till end*/
	while(~(GET_BIT(ADCSRA_Register,ADIF)));
	/*Clear Flag*/
	SET_BIT(ADCSRA_Register,ADIF);
	/*return Reading*/
	return ADC_Register;
}
u16 ADC4_Read(void)
{
	/*Select MUX*/
	ADMUX_Register = (ADMUX_Register & 0b11100000) | ADC4;
	/*Start Conversion*/
	SET_BIT(ADCSRA_Register,ADSC);
	/*Wait Till end*/
	while(~(GET_BIT(ADCSRA_Register,ADIF)));
	/*Clear Flag*/
	SET_BIT(ADCSRA_Register,ADIF);
	/*return Reading*/
	return ADC_Register;
}
u16 ADC5_Read(void)
{
	/*Select MUX*/
	ADMUX_Register = (ADMUX_Register & 0b11100000) | ADC5;
	/*Start Conversion*/
	SET_BIT(ADCSRA_Register,ADSC);
	/*Wait Till end*/
	while(~(GET_BIT(ADCSRA_Register,ADIF)));
	/*Clear Flag*/
	SET_BIT(ADCSRA_Register,ADIF);
	/*return Reading*/
	return ADC_Register;
}
u16 ADC6_Read(void)
{
	/*Select MUX*/
	ADMUX_Register = (ADMUX_Register & 0b11100000) | ADC6;
	/*Start Conversion*/
	SET_BIT(ADCSRA_Register,ADSC);
	/*Wait Till end*/
	while(~(GET_BIT(ADCSRA_Register,ADIF)));
	/*Clear Flag*/
	SET_BIT(ADCSRA_Register,ADIF);
	/*return Reading*/
	return ADC_Register;
}
u16 ADC7_Read(void)
{
	/*Select MUX*/
	ADMUX_Register = (ADMUX_Register & 0b11100000) | ADC7;
	/*Start Conversion*/
	SET_BIT(ADCSRA_Register,ADSC);
	/*Wait Till end*/
	while(~(GET_BIT(ADCSRA_Register,ADIF)));
	/*Clear Flag*/
	SET_BIT(ADCSRA_Register,ADIF);
	/*return Reading*/
	return ADC_Register;
}

void ADC_TurnON(void)
{
	SET_BIT(ADCSRA_Register,ADIF);
}
void ADC_TurnOFF(void)
{
	CLR_BIT(ADCSRA_Register,ADIF);
}
