/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : EEPROM		************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

/* Initialize the EEPROM (Initializes TWI) */
void EEPROM_voidInit(void);

/* Write a byte to specific address (0 to 1023) */
void EEPROM_voidWriteByte(u16 Copy_u16Address, u8 Copy_u8Data);

/* Read a byte from specific address (0 to 1023) */
u8 EEPROM_u8ReadByte(u16 Copy_u16Address);

#endif /* EEPROM_INTERFACE_H_ */