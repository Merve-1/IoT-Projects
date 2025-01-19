
/*
 * TWI_program.c
 *
 * Created: 5/28/2024 11:31:07 AM
 *  Author: NotFound
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_register.h"


void TWI_voidInitMaster(void)
{
	// Set Prescaller = 1 >> Set Freq. = 400KHZ
	TWBR_REG = 12;
	CLR_BIT(TWSR_REG, TWPS0);
	CLR_BIT(TWSR_REG, TWPS1);
	
	// Enable TWI Peripheral
	SET_BIT(TWCR_REG, TWEN);
}


void TWI_voidSendStartCondition(void)
{
	// Request Start Condition
	SET_BIT(TWCR_REG, TWSTA);
	
	// Clear flag to start current job
	SET_BIT(TWCR_REG, TWINT);
	
	// Busy Wait for the flag
	while(0 == GET_BIT(TWCR_REG, TWINT));
	
	// Check ACK = SC ACK
	while(TWI_STATUS_VALUE != TWI_START_CONDITION_ACK);
}


void TWI_voidSendRepeatedStartCondition(void)
{
	// Request Start Condition
	SET_BIT(TWCR_REG, TWSTA);
	
	// Clear flag to start current job
	SET_BIT(TWCR_REG, TWINT);
	
	// Busy Wait for the flag
	while(0 == GET_BIT(TWCR_REG, TWINT));
	
	// Check ACK = Repeated SC ACK
	while(TWI_STATUS_VALUE != TWI_REP_START_CONDITION_ACK);
}


void TWI_voidSendStopCondition(void)
{
	// Request Stop Condition
	SET_BIT(TWCR_REG, TWSTO);
	
	// Clear flag to start current job
	SET_BIT(TWCR_REG, TWINT);
}


void TWI_voidSendSlaveAddWithWrite(u8 copy_u8SlaveAdd)
{
	if(copy_u8SlaveAdd<128)
	{
		TWDR_REG = (copy_u8SlaveAdd<<1);
		
		// Select write operation
		CLR_BIT(TWDR_REG, 0);
		
		// Clear start condition bit
		CLR_BIT(TWCR_REG, TWSTA);
		
		// Clear flag to start current job
		SET_BIT(TWCR_REG, TWINT);
		
		// Busy Wait for the flag
		while(0 == GET_BIT(TWCR_REG, TWINT));
		
		// Check ACK = Master transmit ( slave address + Write request )
		while(TWI_STATUS_VALUE != TWI_SLAVE_ADDRESS_WRITE_ACK);
	}
	else
	{
		// return Error State
	}
}


void TWI_voidSendSlaveAddWithRead(u8 copy_u8SlaveAdd)
{
	if(copy_u8SlaveAdd<128)
	{
		TWDR_REG = (copy_u8SlaveAdd<<1);
		
		// Select read operation
		SET_BIT(TWDR_REG, 0);
		
		// Clear start condition bit
		CLR_BIT(TWCR_REG, TWSTA);
		
		// Clear flag to start current job
		SET_BIT(TWCR_REG, TWINT);
		
		// Busy Wait for the flag
		while(0 == GET_BIT(TWCR_REG, TWINT));
		
		// Check ACK = Master transmit ( slave address + read request )
		while(TWI_STATUS_VALUE != TWI_SLAVE_ADDRESS_READ_ACK);
	}
	else
	{
		// return Error State
	}
}


void TWI_voidTransmitMasterDataByte(u8 copy_u8TxData)
{
	// Write Data into data register
	TWDR_REG = copy_u8TxData;
	
	// Clear flag to start current job
	SET_BIT(TWCR_REG, TWINT);
	
	// Busy Wait for the flag
	while(0 == GET_BIT(TWCR_REG, TWINT));
	
	// Check ACK = Master transmit data ACK
	while(TWI_STATUS_VALUE != TWI_MASTER_DATA_TRANSMIT_ACK);
}


void TWI_voidReceiveMasterDataByteWithAck(u8* copy_pu8RxData)
{
	if(copy_pu8RxData!=NULL)
	{
		// Enable ACK
		SET_BIT(TWCR_REG, TWEA);
		
		// Clear flag to start current job
		SET_BIT(TWCR_REG, TWINT);
		
		// Busy Wait for the flag
		while(0 == GET_BIT(TWCR_REG, TWINT));
		
		// Check ACK = Master received data with ACK
		while(TWI_STATUS_VALUE != TWI_MASTER_DATA_RECIEVE_ACK);
		
		*copy_pu8RxData = TWDR_REG;
		
		// Disable ACK
		CLR_BIT(TWCR_REG, TWEA);
	}
	else
	{
		// return Error State
	}
}


void TWI_voidReceiveMasterDataByteWithNack(u8* copy_pu8RxData)
{
	if(copy_pu8RxData!=NULL)
	{
		// Clear flag to start current job
		SET_BIT(TWCR_REG, TWINT);
		
		// Busy Wait for the flag
		while(0 == GET_BIT(TWCR_REG, TWINT));
		
		// Check ACK = Master received data with NACK
		while(TWI_STATUS_VALUE != TWI_MASTER_DATA_RECIEVE_NACK);
		
		*copy_pu8RxData = TWDR_REG;
	}
	else
	{
		// return Error State
	}
}