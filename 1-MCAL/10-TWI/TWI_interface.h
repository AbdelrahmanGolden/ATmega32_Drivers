/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : TWI			************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

/* Error Status for TWI Operations */
typedef enum
{
	TWI_OK = 0,
	TWI_SC_ERROR,   // Start Condition Error
	TWI_RSC_ERROR,  // Repeated Start Condition Error
	TWI_MT_SLA_W_ERROR, // Master Transmit Slave Address Write Error
	TWI_MT_SLA_R_ERROR, // Master Transmit Slave Address Read Error
	TWI_MT_DATA_ERROR,  // Master Transmit Data Error
	TWI_MR_DATA_ERROR   // Master Receive Data Error
} TWI_ErrorStatus;

/**
 * @brief Initialize TWI as Master.
 * Sets the SCL frequency and enables TWI.
 * @param Copy_u8Address: Address if this node is addressed as slave (optional).
 */
void TWI_voidInitMaster(u8 Copy_u8Address);

/**
 * @brief Initialize TWI as Slave.
 * Sets the Slave Address and enables TWI.
 * @param Copy_u8Address: The address of this slave node.
 */
void TWI_voidInitSlave(u8 Copy_u8Address);

/**
 * @brief Send Start Condition.
 * @return TWI_ErrorStatus: Status of the operation.
 */
TWI_ErrorStatus TWI_SendStartCondition(void);

/**
 * @brief Send Repeated Start Condition.
 * @return TWI_ErrorStatus: Status of the operation.
 */
TWI_ErrorStatus TWI_SendRepeatedStart(void);

/**
 * @brief Send Stop Condition.
 */
void TWI_voidSendStopCondition(void);

/**
 * @brief Send Slave Address with Write Request.
 * @param Copy_u8Address: 7-bit Slave Address.
 * @return TWI_ErrorStatus: Status (ACK received or not).
 */
TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8Address);

/**
 * @brief Send Slave Address with Read Request.
 * @param Copy_u8Address: 7-bit Slave Address.
 * @return TWI_ErrorStatus: Status (ACK received or not).
 */
TWI_ErrorStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8Address);

/**
 * @brief Write Data Byte to the bus.
 * @param Copy_u8Data: Data byte to send.
 * @return TWI_ErrorStatus: Status (ACK received or not).
 */
TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Copy_u8Data);

/**
 * @brief Read Data Byte from the bus.
 * @param Copy_pu8Data: Pointer to store received data.
 * @return TWI_ErrorStatus: Status (Data received or not).
 */
TWI_ErrorStatus TWI_MasterReadDataByte(u8* Copy_pu8Data);

#endif /* TWI_INTERFACE_H_ */