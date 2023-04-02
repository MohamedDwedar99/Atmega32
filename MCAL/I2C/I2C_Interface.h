/*
 * I2C_Interface.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Moham
 */

#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_

#define TWBR_Register	*((volatile u8*)0x20)
#define TWCR_Register   *((volatile u8*)0x56)
#define TWSR_Register   *((volatile u8*)0x21)
#define TWDR_Register   *((volatile u8*)0x23)
#define TWAR_Register   *((volatile u8*)0x22)


#define BIT_RATE(TWSR_Register)

/*TWBR*/ // BIT Rate

/*TWCR*/	//control
#define TWINT 	7
#define TWEA	6
#define TWSTA	5
#define TWSTO	4
#define TWWC	3
#define TWEN 	2
#define TWIE	0

/*TWSR*/
#define TWPS1	1
#define TWPS0	0

/*TWDR*/ //Data

/*TWAR*/ // 7->1 Address

#define TWGCE	0

/*Errors Handling*/
#define OK 						0
#define START_ERROR 			1
#define SEND_ADDRESS_ERROR 		2
#define SEND_DATA_ERROR			3
#define RSTART_ERROR			4
#define Read_DATA_ERROR			5

/*MT States */
#define MT_START				0x08
#define MT_REPEATED_START 		0x10
#define MT_SLA_W_ACK 			0x18
#define MT_SLA_W_NACK			0x20
#define MT_DATA_WRITE_ACK 		0x28
#define MT_DATA_WRITE_NACK 		0x30
#define MT_ARBITRATION_LOST 	0x38

/*MR_States */
#define MR_START				0x08
#define MR_REPEATED_START		0x10
#define MR_ARBITRATION_LOST 	0x38
#define MR_NACK					0x38
#define MR_SLA_R_ACK			0x40
#define MR_SLA_R_NACK			0x48
#define MR_DATA_READ_ACK		0x50
#define MR_DATA_READ_NACK		0x58








u8 StartCondition(void);
u8 SendAddressW(u8 address);
u8 SendAddressR(u8 address);
u8 SendData(u8 data);
u8 ReadDataACK(void);
u8 ReadDataNACK(void);
void StopCondition(void);
u8 RStartCondition(void);

void I2C_MasterInit(u8 address);
u8 I2C_MasterSendData(u8 address,u8 data);
u8 I2C_MasterRecieveData(u8 address,u8* data);
u8 I2C_MasterSendRecieve(u8 address,u8 senddata,u8 * data);

void I2C_SlaveInit(u8 address);
void I2C_SlaveSendData(u8 data);
u8 I2C_SlaveRecieveData(void);


#endif /* MCAL_I2C_I2C_INTERFACE_H_ */
