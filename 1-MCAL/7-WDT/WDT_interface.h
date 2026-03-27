/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : WDT   		************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 28/01/2025	************************/
/***************************************************************************/
/***************************************************************************/
/**		File Guard		**/
#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

/**    Macros definitions    **/
#define SLEEP_16_3_MS			0
#define SLEEP_32_5_MS			1
#define SLEEP_65_MS				2
#define SLEEP_130_MS			3
#define SLEEP_260_MS			4
#define SLEEP_520_MS			5
#define SLEEP_1000_MS			6
#define SLEEP_2100_MS			7

/**    Functions Prototype    **/


/**
 * @brief Sets the sleep time for the Watchdog Timer (WDT).
 *
 * This function configures the WDT prescaler to set the sleep time. The sleep time determines 
 * how long the WDT will wait before triggering a reset. The prescaler is cleared and then set 
 * according to the provided sleep time value.
 *
 * @param Copy_u8SleepTime The desired sleep time. Valid values are:
 * - `SLEEP_16_3_MS`  : 16.3 milliseconds
 * - `SLEEP_32_5_MS`  : 32.5 milliseconds
 * - `SLEEP_65_MS`    : 65 milliseconds
 * - `SLEEP_130_MS`   : 130 milliseconds
 * - `SLEEP_260_MS`   : 260 milliseconds
 * - `SLEEP_520_MS`   : 520 milliseconds
 * - `SLEEP_1000_MS`  : 1000 milliseconds
 * - `SLEEP_2100_MS`  : 2100 milliseconds
 *
 * @note The input value should be one of the predefined macros for sleep time. 
 *       Invalid values may result in undefined behavior.
 */
void WDT_voidSleep(u8 Copy_u8SleepTime);



/**
 * @brief Enables the Watchdog Timer (WDT).
 *
 * This function enables the WDT by setting the Watchdog Enable (WDE) bit in the WDT Control Register (WDTCR).
 * Once enabled, the WDT will start counting down based on the configured sleep time. If the WDT is not 
 * reset before the sleep time elapses, it will trigger a system reset.
 *
 * @note Ensure the sleep time is configured using `WDT_voidSleep()` before enabling the WDT.
 */
void WDT_voidEnable(void);




/**
 * @brief Disables the Watchdog Timer (WDT).
 *
 * This function disables the WDT by following the required sequence:
 * 1. Set the WDTOE (Watchdog Turn-Off Enable) and WDE (Watchdog Enable) bits.
 * 2. Clear the WDE bit within 4 clock cycles to disable the WDT.
 *
 * @note Disabling the WDT requires a specific sequence to prevent accidental changes. 
 *       This function handles the sequence internally.
 */
void WDT_voidDisable(void);



/**
 * @brief Checks if the Watchdog Timer (WDT) is enabled.
 *
 * @return u8 Returns 1 if the WDT is enabled, 0 if it is disabled.
 */
u8 WDT_u8IsEnabled(void);


#endif /* WDT_INTERFACE_H_ */