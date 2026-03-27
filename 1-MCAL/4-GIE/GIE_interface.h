/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : GIE			************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 30/9/2024		************************/
/***************************************************************************/
/***************************************************************************/

/**		File Guard		**/
#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

/**		Macros Definition		**/



/**
 * @brief Enables the Global Interrupt enable.
 *
 * @param void.
 * @return void.
 */
void GIE_voidEnable(void);


/**
 * @brief disables the Global Interrupt enable.
 *
 * @param void.
 * @return void.
 */
void GIE_voidDisable(void);


/**
 * @brief Checks if the global interrupt flag (I bit in SREG) is enabled.
 *
 * @param void
 * @return u8 Returns:
 *         - TRUE if the global interrupt is enabled.
 *         - FALSE if the global interrupt is disabled.
 */
u8 GIE_u8IsEnabled(void);

#endif /* GIE_INTERFACE_H_ */