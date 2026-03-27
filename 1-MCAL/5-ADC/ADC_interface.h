/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : ADC			************************/
/***********************	Version : 1.10			************************/
/***********************	Date    : 08/01/2025	************************/
/***************************************************************************/
/***************************************************************************/

/**		File Guard		**/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/**
 * @brief Structure for configuring an ADC chain conversion.
 *
 * This structure is used to define the configuration for performing asynchronous chain conversions
 * using multiple ADC channels. It contains an array of channels, an array to store the results,
 * the size of the chain, and a notification function that is called upon completion of the chain conversion.
 */
typedef struct {
    u8*  Channel_Arr;                  /**< Pointer to an array of ADC channel numbers. */
    u16* Result_Arr;                   /**< Pointer to an array where conversion results will be stored. */
    u8   Chain_Size;                   /**< Number of channels in the chain. */
    void(*NotificationFunction)(void); /**< Pointer to a callback function to be executed after chain conversion is complete. */
} Chain_t;

/**
 * @brief Initializes the ADC peripheral.
 *
 * This function configures the ADC peripheral with predefined settings, such as reference voltage, 
 * prescaler, and resolution, as defined in the configuration file.
 */
void ADC_voidInit(void);

/**
 * @brief Starts an ADC conversion synchronously.
 *
 * This function starts a conversion on a specified ADC channel and waits for the result.
 *
 * @param Copy_u8Channel The ADC channel number to be converted.
 * @param Copy_pu8Reading Pointer to a variable where the result of the conversion will be stored.
 * @return Status of the operation:
 *         - 0: Success.
 *         - 1: Failure (e.g., invalid channel or ADC error).
 */
u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u16* Copy_pu8Reading);

/**
 * @brief Starts an ADC conversion asynchronously.
 *
 * This function starts a conversion on a specified ADC channel without blocking. 
 * The provided notification function is called when the conversion is complete.
 *
 * @param Copy_u8Channel The ADC channel number to be converted.
 * @param Copy_pu8Reading Pointer to a variable where the result of the conversion will be stored.
 * @param Copy_pvNotificationFunc Pointer to the callback function to be executed upon conversion completion.
 * @return Status of the operation:
 *         - 0: Success.
 *         - 1: Failure (e.g., invalid channel or ADC error).
 */
u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16* Copy_pu8Reading, void(*Copy_pvNotificationFunc)(void));

/**
 * @brief Starts an asynchronous ADC chain conversion.
 *
 * This function starts a chain conversion for multiple ADC channels without blocking.
 * The results of the conversions are stored in the specified result array, and a notification
 * function is called upon completion of the chain conversion.
 *
 * @param Copy_Chain Pointer to a Chain_t structure containing the configuration for the chain conversion.
 * @return Status of the operation:
 *         - 0: Success.
 *         - 1: Failure (e.g., invalid parameters or ADC error).
 */
u8 ADC_u8StartChainAsynch(Chain_t *Copy_Chain);

/**
 * @brief Sets a global callback function for the ADC.
 *
 * This function sets a global callback function to be called upon the completion of an ADC conversion.
 *
 * @param Copy_pvCallBackFunc Pointer to the callback function to be executed.
 * @return Status of the operation:
 *         - 0: Success.
 *         - 1: Failure (e.g., invalid function pointer).
 */
u8 ADC_u8SetCallBack(void(*Copy_pvCallBackFunc)(void));

/**
 * @brief ADC interrupt service routine (ISR).
 *
 * This function is automatically executed when the ADC conversion is complete, as part of the interrupt vector.
 * It is marked as a signal function to handle ADC-related interrupts.
 */
void __vector_16(void) __attribute__((signal));


#endif /* ADC_INTERFACE_H_ */