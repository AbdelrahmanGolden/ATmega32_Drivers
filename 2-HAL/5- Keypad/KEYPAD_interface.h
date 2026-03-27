/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : Keypad		************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

/**
 * @brief Initialize the Keypad pins.
 * Sets Columns as Output (High) and Rows as Input (Pull-up Enabled).
 */
void KEYPAD_voidInit(void);

/**
 * @brief Scans the keypad matrix.
 * @return u8 The character pressed, or KEYPAD_NO_PRESSED_KEY if none.
 */
u8 KEYPAD_u8GetPressedKey(void);

#endif /* KEYPAD_INTERFACE_H_ */