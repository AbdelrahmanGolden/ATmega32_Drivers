/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : TWI			************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_register.h"
#include "TWI_private.h"
#include "TWI_interface.h"

void TWI_voidInitMaster(u8 Copy_u8Address)
{
	/* Set Bit Rate: 400kHz @ 8MHz Crystal
	 * SCL Freq = CPU Clock / (16 + 2(TWBR) * 4^TWPS)
	 * 400000 = 8000000 / (16 + 2(TWBR) * 1) -> TWBR = 2
	 * Note: Standard is usually 2 or higher. Let's set a safe 100kHz logic
	 * 100000 = 8000000 / (16 + 2(TWBR) * 1) -> 2(TWBR) = 64 -> TWBR = 32
	 */
	TWBR = 32; /* 100kHz standard mode */
	
	/* Clear Prescaler bits (TWPS0, TWPS1) = 1 */
	CLR_BIT(TWSR, TWSR_TWPS0);
	CLR_BIT(TWSR, TWSR_TWPS1);

	/* Set My Address if provided (Address in bits 7-1, GCE in bit 0) */
	if(Copy_u8Address != 0)
	{
		TWAR = (Copy_u8Address << 1);
	}

	/* Enable TWI and Acknowledge bit */
	SET_BIT(TWCR, TWCR_TWEN);
	SET_BIT(TWCR, TWCR_TWEA);
}

void TWI_voidInitSlave(u8 Copy_u8Address)
{
	/* Set Slave Address */
	TWAR = (Copy_u8Address << 1);

	/* Enable TWI and Acknowledge */
	SET_BIT(TWCR, TWCR_TWEN);
	SET_BIT(TWCR, TWCR_TWEA);
}

TWI_ErrorStatus TWI_SendStartCondition(void)
{
	TWI_ErrorStatus Local_Error = TWI_OK;

	/* Send Start Condition:
	 * Clear Interrupt Flag (TWINT)
	 * Set Start Bit (TWSTA)
	 * Enable TWI (TWEN)
	 */
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWSTA) | (1 << TWCR_TWEN);

	/* Wait for Flag to be set (operation complete) */
	while(GET_BIT(TWCR, TWCR_TWINT) == 0);

	/* Check Status Code */
	if((TWSR & 0xF8) != TWI_START)
	{
		Local_Error = TWI_SC_ERROR;
	}

	return Local_Error;
}

TWI_ErrorStatus TWI_SendRepeatedStart(void)
{
	TWI_ErrorStatus Local_Error = TWI_OK;

	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWSTA) | (1 << TWCR_TWEN);

	while(GET_BIT(TWCR, TWCR_TWINT) == 0);

	if((TWSR & 0xF8) != TWI_REP_START)
	{
		Local_Error = TWI_RSC_ERROR;
	}

	return Local_Error;
}

void TWI_voidSendStopCondition(void)
{
	/* Send Stop Condition */
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWSTO) | (1 << TWCR_TWEN);
	
	/* Note: We do NOT wait for the flag here, as Stop clears the flag automatically */
}

TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8Address)
{
	TWI_ErrorStatus Local_Error = TWI_OK;

	/* Load Address + Write Bit (0) into Data Register */
	TWDR = (Copy_u8Address << 1); // Bit 0 is 0 for Write
	
	/* Clear Flag and Enable */
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEN);

	while(GET_BIT(TWCR, TWCR_TWINT) == 0);

	/* Check Status: MT_SLA_ACK means Slave Acknowledged */
	if((TWSR & 0xF8) != TWI_MT_SLA_ACK)
	{
		Local_Error = TWI_MT_SLA_W_ERROR;
	}

	return Local_Error;
}

TWI_ErrorStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8Address)
{
	TWI_ErrorStatus Local_Error = TWI_OK;

	/* Load Address + Read Bit (1) into Data Register */
	TWDR = (Copy_u8Address << 1) | 1; 
	
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEN);

	while(GET_BIT(TWCR, TWCR_TWINT) == 0);

	/* Check Status: MR_SLA_ACK means Slave Acknowledged read request */
	if((TWSR & 0xF8) != TWI_MR_SLA_ACK)
	{
		Local_Error = TWI_MT_SLA_R_ERROR;
	}

	return Local_Error;
}

TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Copy_u8Data)
{
	TWI_ErrorStatus Local_Error = TWI_OK;

	TWDR = Copy_u8Data;

	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEN);

	while(GET_BIT(TWCR, TWCR_TWINT) == 0);

	/* Check Status: Data Transmitted + ACK received */
	if((TWSR & 0xF8) != TWI_MT_DATA_ACK)
	{
		Local_Error = TWI_MT_DATA_ERROR;
	}

	return Local_Error;
}

TWI_ErrorStatus TWI_MasterReadDataByte(u8* Copy_pu8Data)
{
	TWI_ErrorStatus Local_Error = TWI_OK;

	/* Clear Flag, Enable TWI, Enable ACK (TWEA) to request more data 
	 * Or clear TWEA if this is the last byte (NACK). 
	 * For simplicity, let's assume we ACK if we want to read.
	 */
	TWCR = (1 << TWCR_TWINT) | (1 << TWCR_TWEN); // NACK (Single Byte Read) usually

	while(GET_BIT(TWCR, TWCR_TWINT) == 0);

	if((TWSR & 0xF8) != TWI_MR_DATA_NACK) // Expect NACK if single byte
	{
		Local_Error = TWI_MR_DATA_ERROR;
	}
	else
	{
		*Copy_pu8Data = TWDR;
	}

	return Local_Error;
}