/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : EXTI			************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 30/9/2024		************************/
/***************************************************************************/
/***************************************************************************/

/**		File Guard		**/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/**		Macros Definition		**/

#define LOW_LEVEL		0x01
#define ON_CHANGE		0x02
#define FALLING_EDGE	0x03
#define RISING_EDGE		0x04

#define EXTI_INT0		0x0A
#define EXTI_INT1		0x0B
#define EXTI_INT2		0x0C



/**		Functions Prototype		**/

/**
 * @brief  Initializes External Interrupt 0 (INT0).
 * 
 * This function configures the sense control and the initial state for INT0 
 * based on the macros defined in the EXTI_config.h file.
 *
 * - INT0_SENSE options:
 *   - LOW_LEVEL: Trigger on low level.
 *   - ON_CHANGE: Trigger on any logical change.
 *   - FALLING_EDGE: Trigger on falling edge.
 *   - RISING_EDGE: Trigger on rising edge.
 *
 * - INT0_INITIAL_STATE options:
 *   - INT_ENABLED: Enable the INT0 interrupt.
 *   - INT_DISABLED: Disable the INT0 interrupt.
 * 
 * @note Make sure the INT0_SENSE and INT0_INITIAL_STATE macros are correctly
 *       defined in EXTI_config.h.
 */
void EXTI_voidInt0Init(void);


/**
 * @brief  Initializes External Interrupt 1 (INT1).
 * 
 * This function configures the sense control and the initial state for INT1 
 * based on the macros defined in the EXTI_config.h file.
 *
 * - INT1_SENSE options:
 *   - LOW_LEVEL: Trigger on low level.
 *   - ON_CHANGE: Trigger on any logical change.
 *   - FALLING_EDGE: Trigger on falling edge.
 *   - RISING_EDGE: Trigger on rising edge.
 *
 * - INT1_INITIAL_STATE options:
 *   - INT_ENABLED: Enable the INT1 interrupt.
 *   - INT_DISABLED: Disable the INT1 interrupt.
 * 
 * @note Make sure the INT1_SENSE and INT1_INITIAL_STATE macros are correctly
 *       defined in EXTI_config.h.
 */
void EXTI_voidInt1Init(void);

/**
 * @brief  Initializes External Interrupt 2 (INT2).
 * 
 * This function configures the sense control and the initial state for INT2 
 * based on the macros defined in the EXTI_config.h file.
 *
 * - INT2_SENSE options:
 *   - FALLING_EDGE: Trigger on falling edge.
 *   - RISING_EDGE: Trigger on rising edge.
 *
 * - INT2_INITIAL_STATE options:
 *   - INT_ENABLED: Enable the INT2 interrupt.
 *   - INT_DISABLED: Disable the INT2 interrupt.
 * 
 * @note Make sure the INT2_SENSE and INT2_INITIAL_STATE macros are correctly
 *       defined in EXTI_config.h.
 */
void EXTI_voidInt2Init(void);


/**
 * @brief  Sets the sense control for External Interrupt 0 (INT0) post-build.
 * 
 * This function allows the user to dynamically configure the sense control for INT0 
 * at runtime after the build. The sense control defines how the interrupt is triggered.
 *
 * - Copy_u8Sense options:
 *   - LOW_LEVEL: Trigger on low level.
 *   - ON_CHANGE: Trigger on any logical change.
 *   - FALLING_EDGE: Trigger on falling edge.
 *   - RISING_EDGE: Trigger on rising edge.
 * 
 * @param  Copy_u8Sense The sense control option for INT0 (use the defined macros).
 * @return u8 Returns OK if the operation was successful, or NOT_OK if the input was invalid.
 * 
 * @note  This function allows you to modify the sense control dynamically 
 *        rather than at compile time. Make sure to pass a valid sense control option.
 */
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);


/**
 * @brief  Sets the sense control for External Interrupt 1 (INT1) post-build.
 * 
 * This function allows dynamic configuration of the sense control for INT1 
 * at runtime after the build. The sense control defines how the interrupt is triggered.
 *
 * - Copy_u8Sense options:
 *   - LOW_LEVEL: Trigger on low level.
 *   - ON_CHANGE: Trigger on any logical change.
 *   - FALLING_EDGE: Trigger on falling edge.
 *   - RISING_EDGE: Trigger on rising edge.
 * 
 * @param  Copy_u8Sense The sense control option for INT1 (use the defined macros).
 * @return u8 Returns OK if the operation was successful, or NOT_OK if the input was invalid.
 * 
 * @note  This function allows you to modify the sense control for INT1 dynamically 
 *        rather than at compile time. Ensure to pass a valid sense control option.
 */
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense);


/**
 * @brief  Sets the sense control for External Interrupt 2 (INT2) post-build.
 * 
 * This function allows dynamic configuration of the sense control for INT2 
 * at runtime after the build. INT2 only supports edge-triggered interrupts.
 *
 * - Copy_u8Sense options:
 *   - FALLING_EDGE: Trigger on falling edge.
 *   - RISING_EDGE: Trigger on rising edge.
 * 
 * @param  Copy_u8Sense The sense control option for INT2 (use the defined macros).
 * @return u8 Returns OK if the operation was successful, or NOT_OK if the input was invalid.
 * 
 * @note  This function allows you to modify the sense control for INT2 dynamically.
 *        Ensure to pass a valid sense control option.
 */
u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense);


/**
 * @brief  Enables the specified external interrupt.
 * 
 * This function enables the external interrupt (INT0, INT1, or INT2) 
 *
 * based on the value of Copy_u8Int. The valid values for Copy_u8Int are:
 * - EXTI_INT0: Enable INT0
 * - EXTI_INT1: Enable INT1
 * - EXTI_INT2: Enable INT2
 * 
 * @param  Copy_u8Int The interrupt number (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 * @return u8 Returns OK if the operation was successful, or NOT_OK if the input was invalid.
 */
u8 EXTI_u8IntEnable(u8 Copy_u8Int);


/**
 * @brief  Disables the specified external interrupt.
 * 
 * This function disables the external interrupt (INT0, INT1, or INT2) 
 *
 * based on the value of Copy_u8Int. The valid values for Copy_u8Int are:
 * - EXTI_INT0: Disable INT0
 * - EXTI_INT1: Disable INT1
 * - EXTI_INT2: Disable INT2
 * 
 * @param  Copy_u8Int The interrupt number (EXTI_INT0, EXTI_INT1, or EXTI_INT2).
 * @return u8 Returns OK if the operation was successful, or NOT_OK if the input was invalid.
 */
u8 EXTI_u8IntDisable(u8 Copy_u8Int);


/**
 * @brief Sets the callback function for the INT0 interrupt.
 * 
 * This function registers a callback function that will be executed 
 * when the INT0 interrupt occurs. The registered function is called 
 * inside the ISR.
 * 
 * @param  Copy_pvInt0Func Pointer to the function to be called when the INT0 interrupt occurs.
 * @return u8 Returns:
 *         - OK if the function pointer is valid.
 *         - NULL_POINTER if the provided function pointer is NULL.
 */
u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func) (void));


/**
 * @brief Sets the callback function for the INT1 interrupt.
 * 
 * This function registers a callback function that will be executed 
 * when the INT1 interrupt occurs. The registered function is called 
 * inside the ISR.
 * 
 * @param  Copy_pvInt1Func Pointer to the function to be called when the INT1 interrupt occurs.
 * @return u8 Returns:
 *         - OK if the function pointer is valid.
 *         - NULL_POINTER if the provided function pointer is NULL.
 */
u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1Func) (void));


/**
 * @brief Sets the callback function for the INT2 interrupt.
 * 
 * This function registers a callback function that will be executed 
 * when the INT2 interrupt occurs. The registered function is called 
 * inside the ISR.
 * 
 * @param  Copy_pvInt2Func Pointer to the function to be called when the INT2 interrupt occurs.
 * @return u8 Returns:
 *         - OK if the function pointer is valid.
 *         - NULL_POINTER if the provided function pointer is NULL.
 */
u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2Func) (void));


/**
 * @brief ISR for the INT0 external interrupt.
 * 
 * This ISR is triggered when the INT0 interrupt occurs. If a valid 
 * callback function was registered using `EXTI_u8Int0SetCallBack`, 
 * that function is executed. Otherwise, the ISR does nothing.
 * 
 * @note This function must be implemented with the `signal` attribute 
 *       to be used as an interrupt service routine.
 */
void __vector_1(void) __attribute__((signal));


/**
 * @brief ISR for the INT1 external interrupt.
 * 
 * This ISR is triggered when the INT1 interrupt occurs. If a valid 
 * callback function was registered using `EXTI_u8Int1SetCallBack`, 
 * that function is executed. Otherwise, the ISR does nothing.
 * 
 * @note This function must be implemented with the `signal` attribute 
 *       to be used as an interrupt service routine.
 */
void __vector_2(void) __attribute__((signal));


/**
 * @brief ISR for the INT2 external interrupt.
 * 
 * This ISR is triggered when the INT2 interrupt occurs. If a valid 
 * callback function was registered using `EXTI_u8Int2SetCallBack`, 
 * that function is executed. Otherwise, the ISR does nothing.
 * 
 * @note This function must be implemented with the `signal` attribute 
 *       to be used as an interrupt service routine.
 */
void __vector_3(void) __attribute__((signal));



#endif /* EXTI_INTERFACE_H_ */