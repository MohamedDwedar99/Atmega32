/*
 * I2C_Program.c
 *
 *  Created on: Mar 30, 2023
 *      Author: Moham
 */

#include "../../Service/BIT_MATH.h"
#include "../../Service/STD.h"
#include "../DIO/DIO_interface.h"
#include "I2C_Interface.h"

void I2C_Init(u8 address)
{
	//Set Bit Rate
	TWBR_Register = 0;
	//ClearStatus Register Prescaler 0
	TWSR_Register = 0;
	//Set Address
	TWAR_Register = address;
}

u8 StartCondition(void)
{
	//Send START condition
	TWCR_Register = (1<<TWINT)|(1<<TWSTA)| (1<<TWEN);
	//Wait for TWINT Flag set. This indicates that the START condition has been transmitted
	while (!(TWCR_Register & (1<<TWINT)));
	//Check value of TWI Status Register. Mask prescaler bits. If status different from START go to ERROR
	if ((TWSR_Register & 0xF8) != MR_START)
	{
		return START_ERROR;
	}
	return OK;
}

u8 SendAddressW(u8 address)
{
	//Load SLA_W into TWDR Register. Clear TWINT bit in TWCR to start transmission of address
	TWDR_Register = address + 0;
	TWCR_Register = (1<<TWINT) | (1<<TWEN);
	//Wait for TWINT Flag set. This indicates that the SLA+W has been transmitted, and ACK/NACK has been received.
	while (!(TWCR_Register & (1<<TWINT)));
	//Check value of TWI Status Register. Mask prescaler bits. If status different from MT_SLA_ACK go to ERROR
	if ((TWSR_Register & 0xF8) != MT_SLA_W_ACK )
	{
		return SEND_ADDRESS_ERROR;
	}
	return OK;
}

u8 SendAddressR(u8 address)
{
	//Load SLA_E into TWDR Register. Clear TWINT bit in TWCR to start transmission of address
	TWDR_Register = address + 1;
	TWCR_Register = (1<<TWINT) | (1<<TWEN);
	//Wait for TWINT Flag set. This indicates that the SLA+W has been transmitted, and ACK/NACK has been received.
	while (!(TWCR_Register & (1<<TWINT)));
	//Check value of TWI Status Register. Mask prescaler bits. If status different from MT_SLA_ACK go to ERROR
	if ((TWSR_Register & 0xF8) != MR_SLA_R_ACK )
	{
		DIO_SetPortDirection(PORTA,TWSR_Register & 0xF8);
		return SEND_ADDRESS_ERROR;
	}
	return OK;
}

u8 SendData(u8 data)
{
	//Load DATA into TWDR Register. Clear TWINT bit in TWCR to start transmission of data
	TWDR_Register = data;
	TWCR_Register = (1<<TWINT) | (1<<TWEN);
	//Wait for TWINT Flag set. This indicates that the DATA has been transmitted, and ACK/NACK has been received.
	while (!(TWCR_Register & (1<<TWINT)));
	//Check value of TWI Status Register. Mask prescaler bits. If status different from MT_DATA_ACK go to ERROR
	if ((TWSR_Register & 0xF8) != MT_DATA_WRITE_ACK)
	{
		return SEND_DATA_ERROR;
	}
	return OK;
}

u8 ReadDataACK(void)
{
	//Load DATA into TWDR Register. Clear TWINT bit in TWCR to start transmission of data
	TWCR_Register = (1<<TWINT) | (1<<TWEN);
	//Wait for TWINT Flag set. This indicates that the DATA has been transmitted, and ACK/NACK has been received.
	while (!(TWCR_Register & (1<<TWINT)));
	//Check value of TWI Status Register. Mask prescaler bits. If status different from MT_DATA_ACK go to ERROR
	if ((TWSR_Register & 0xF8) != MT_DATA_WRITE_NACK)
	{
		return SEND_DATA_ERROR;
	}
	return OK;
}

u8 ReadDataNACK(void)
{
	//Load DATA into TWDR Register. Clear TWINT bit in TWCR to start transmission of data
	TWCR_Register = (1<<TWINT) | (1<<TWEN);
	//Wait for TWINT Flag set. This indicates that the DATA has been transmitted, and ACK/NACK has been received.
	while (!(TWCR_Register & (1<<TWINT)));
	//Check value of TWI Status Register. Mask prescaler bits. If status different from MT_DATA_ACK go to ERROR
	if ((TWSR_Register & 0xF8) != MR_DATA_READ_NACK)
	{
		return SEND_DATA_ERROR;
	}
	return TWDR_Register;
}
u8 RStartCondition(void)
{
	//Send START condition
	TWCR_Register = (1<<TWINT)|(1<<TWSTA)| (1<<TWEN);
	//Wait for TWINT Flag set. This indicates that the START condition has been transmitted
	while (!(TWCR_Register & (1<<TWINT)));
	//Check value of TWI Status Register. Mask prescaler bits. If status different from START go to ERROR
	if ((TWSR_Register & 0xF8) != MT_REPEATED_START)
	{
		return RSTART_ERROR;
	}
	return OK;
}

void StopCondition(void)
{
	//Transmit STOP condition.
	TWCR_Register = (1<<TWINT)|(1<<TWEN)| (1<<TWSTO);
}

u8 I2C_MasterSendData(u8 address,u8 data)
{
	if (StartCondition() != OK)
	{
		StopCondition();
		return START_ERROR;
	}
	if (SendAddressW(address) != OK)
	{
		StopCondition();
		return SEND_ADDRESS_ERROR;
	}
	if (SendData(data) != OK)
	{
		StopCondition();
		return SEND_DATA_ERROR;
	}
	StopCondition();
	return OK;
}

u8 I2C_MasterRecieveData(u8 address,u8 *data)
{
	u8 DATA;
	if (StartCondition() != OK)
	{
		StopCondition();
		return START_ERROR;
	}
	if (SendAddressR(address) != OK)
	{
		StopCondition();
		return SEND_ADDRESS_ERROR;
	}
	if ((DATA = ReadDataNACK()) != OK)
	{
		StopCondition();
		return Read_DATA_ERROR;
	}
	*data = DATA;
	StopCondition();
	return OK;
}

u8 I2C_MasterSendRecieve(u8 address,u8 senddata,u8 * data)
{
	u8 DATA;
	if (StartCondition() != OK)
	{
		StopCondition();
		return START_ERROR;
	}
	if (SendAddressW(address) != OK)
	{
		StopCondition();
		return SEND_ADDRESS_ERROR;
	}
	if (SendData(senddata) != OK)
	{
		StopCondition();
		return SEND_DATA_ERROR;
	}
	if (RStartCondition() != OK)
	{
		StopCondition();
		return RSTART_ERROR;
	}
	if (SendAddressR(address) != OK)
	{
		StopCondition();
		return SEND_ADDRESS_ERROR;
	}
	if ((DATA = ReadDataNACK()) != OK)
	{
		StopCondition();
		return Read_DATA_ERROR;
	}
	*data = DATA;
	StopCondition();
	return OK;

}

void I2C_SlaveInit(u8 address)
{
	//Set adress
	TWAR_Register = address;
	TWCR_Register = 1<<TWEA | 1<<TWEN;
}

void I2C_SlaveSendData(u8 data)
{
	TWCR_Register = 1<<TWEA | 1<<TWEN;
	while (!(TWCR_Register & (1<<TWINT)));
	TWCR_Register = 1<<TWEA | 1<<TWEN;
	while (!(TWCR_Register & (1<<TWINT)));
	TWDR_Register = data;
}

u8 I2C_SlaveRecieveData(void)
{
	u8 static data;
	TWCR_Register |= (1<<TWINT);
	while (!(TWCR_Register & (1<<TWINT)));
	TWCR_Register |= (1<<TWINT);
	while (!(TWCR_Register & (1<<TWINT)));
	if ((TWSR_Register & 0xF8) != MR_START)
	{
		data = TWDR_Register;
	}
	return data;
}
