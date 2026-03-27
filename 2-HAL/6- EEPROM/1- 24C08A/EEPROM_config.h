/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : EEPROM		************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#ifndef EEPROM_CONFIG_H_
#define EEPROM_CONFIG_H_

/* * AT24C08A Device Address Structure:
 * 1 0 1 0  A2  P1  P0  R/W
 * P1, P0 are memory page bits (A9, A8).
 * A2 is a hardware pin.
 * * Assuming A2 is grounded -> Fixed part is 10100000 -> 0xA0
 */
#define EEPROM_FIXED_ADDRESS    0xA0

#endif /* EEPROM_CONFIG_H_ */