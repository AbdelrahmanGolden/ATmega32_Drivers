/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : TWI			************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

/* TWI Control Register Bits */
#define TWCR_TWIE       0
#define TWCR_TWEN       2
#define TWCR_TWWC       3
#define TWCR_TWSTO      4
#define TWCR_TWSTA      5
#define TWCR_TWEA       6
#define TWCR_TWINT      7

/* TWI Status Register Bits */
#define TWSR_TWPS0      0
#define TWSR_TWPS1      1

/* TWI (Slave) Address Register Bits */
#define TWAR_TWGCE      0

/* TWI Status Codes (Masked with 0xF8) */
/* Master Start Condition */
#define TWI_START                   0x08
#define TWI_REP_START               0x10

/* Master Transmitter Mode */
#define TWI_MT_SLA_ACK              0x18
#define TWI_MT_SLA_NACK             0x20
#define TWI_MT_DATA_ACK             0x28
#define TWI_MT_DATA_NACK            0x30
#define TWI_MT_ARB_LOST             0x38

/* Master Receiver Mode */
#define TWI_MR_ARB_LOST             0x38
#define TWI_MR_SLA_ACK              0x40
#define TWI_MR_SLA_NACK             0x48
#define TWI_MR_DATA_ACK             0x50
#define TWI_MR_DATA_NACK            0x58

#endif /* TWI_PRIVATE_H_ */