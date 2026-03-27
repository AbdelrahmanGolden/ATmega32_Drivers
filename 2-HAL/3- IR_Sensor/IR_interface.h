/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : IR			************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 27/01/2025	************************/
/***************************************************************************/
/***************************************************************************/



/**		File Guard		**/
#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_


/* Macros definition */
#define OBSTACLE_DETECTED		1
#define OBSTACLE_NOT_DETECTED	2

/**		Struct		**/

/**
 * @brief Struct to configure an IR.
 * 
 * This struct defines the configuration for an IR, the port to which it is connected, 
 * and the specific pin on that port.
 */
typedef struct{
	u8 Connection_Port;		/*!< DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD */
	u8 Connection_Pin;		/*!< From DIO_u8PIN0 to DIO_u8PIN7 */
} IR_t;

/**		Functions Prototype		**/

/**
 * @brief Gets the digital reading from an IR sensor.
 *
 * This function retrieves the current digital reading from the specified IR sensor. 
 * The reading will be either OBSTACLE_DETECTED (indicating detection) or 
 * OBSTACLE_NOT_DETECTED (indicating no detection).
 *
 * @param Copy_IR A pointer to the IR_t struct that contains the configuration of the IR sensor.
 * @return The digital reading from the IR sensor:
 *         - OBSTACLE_DETECTED: Detection (object present).
 *         - OBSTACLE_NOT_DETECTED: No detection (no object present).
 */

u8 IR_u8GetDigitalReading(IR_t* Copy_IR);

#endif /* IR_INTERFACE_H_ */