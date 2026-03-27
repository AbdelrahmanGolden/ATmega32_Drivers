/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : LED			************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 10/8/2024		************************/
/***************************************************************************/
/***************************************************************************/


/**		File Guard		**/
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/**		Macros Definition		**/
#define LED_u8OFF			0
#define LED_u8ON			1		

#define LED_u8SINK			0
#define LED_u8SOURCE		1


/**		Struct		**/

/**
 * @brief Struct to configure an LED.
 * 
 * This struct defines the configuration for an LED, including its connection type 
 * (whether it is connected as a source or a sink), the port to which it is connected, 
 * and the specific pin on that port.
 */
typedef struct{
	u8 Connection_Type;		/*!< LED_u8SINK or LED_u8SOURCE */
	u8 Connection_Port;		/*!< DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD */
	u8 Connection_Pin;		/*!< From DIO_u8PIN0 to DIO_u8PIN7 */
} LED_t;

/**		Functions Prototype		**/

/**
 * @brief Sets the state of an LED.
 *
 * This function sets the specified LED to either an on or off state.
 *
 * @param Copy_u8State The desired state of the LED (LED_u8ON or LED_u8OFF).
 * @param Copy_LED A pointer to the LED_t struct that defines the configuration of the LED.
 * @return Status of the operation (0 for success, 1 for failure).
 */
u8 LED_u8SetState(u8 Copy_u8State, LED_t* Copy_LED);

#endif /* LED_INTERFACE_H_ */