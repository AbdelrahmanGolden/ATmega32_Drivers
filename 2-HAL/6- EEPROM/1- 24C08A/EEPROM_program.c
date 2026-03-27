/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : EEPROM		************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

/* MCAL TWI Driver */
#include "TWI_interface.h"

/* HAL EEPROM Includes */
#include "EEPROM_config.h"
#include "EEPROM_private.h"
#include "EEPROM_interface.h"

void EEPROM_voidInit(void)
{
	/* Initialize TWI as Master. Address 0 is fine for master. */
	TWI_voidInitMaster(0);
}

void EEPROM_voidWriteByte(u16 Copy_u16Address, u8 Copy_u8Data)
{
	/* 1. Calculate Address Packet for AT24C08A
	 * Fixed (1010) | A2(0) | P1(A9) | P0(A8)
	 */
	u8 Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (u8)((Copy_u16Address >> 8) & 0x03);

	/* 2. Send Start Condition */
	TWI_SendStartCondition();

	/* 3. Send Slave Address with Write Request */
	/* Note: The TWI driver expects the 7-bit address, so we shift right by 1 */
	TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket >> 1);

	/* 4. Send the Word Address (Lower 8 bits A0-A7) */
	TWI_MasterWriteDataByte((u8)Copy_u16Address);

	/* 5. Send the Data Byte */
	TWI_MasterWriteDataByte(Copy_u8Data);

	/* 6. Send Stop Condition */
	TWI_voidSendStopCondition();

	/* 7. Wait for internal write cycle (5-10ms) */
	_delay_ms(10);
}

u8 EEPROM_u8ReadByte(u16 Copy_u16Address)
{
	u8 Local_u8Data = 0;
	u8 Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (u8)((Copy_u16Address >> 8) & 0x03);

	/* 1. Send Start Condition */
	TWI_SendStartCondition();

	/* 2. Send Slave Address + Write (Dummy Write to set address pointer) */
	TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket >> 1);

	/* 3. Send Word Address */
	TWI_MasterWriteDataByte((u8)Copy_u16Address);

	/* 4. Send Repeated Start Condition */
	TWI_SendRepeatedStart();

	/* 5. Send Slave Address + Read Request */
	TWI_SendSlaveAddressWithRead(Local_u8AddressPacket >> 1);

	/* 6. Read Data (NACK because we only read 1 byte) */
	TWI_MasterReadDataByte(&Local_u8Data);

	/* 7. Send Stop Condition */
	TWI_voidSendStopCondition();

	return Local_u8Data;
}