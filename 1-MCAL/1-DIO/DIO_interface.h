/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : DIO			************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 1/8/2024		************************/
/***************************************************************************/
/***************************************************************************/

/**		File Guard		**/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/**		Macros Definition		**/
#define DIO_u8PIN_OUTPUT	1
#define DIO_u8PIN_INPUT		0

#define DIO_u8PIN_HIGH		1
#define DIO_u8PIN_LOW		0

#define DIO_u8PORT_OUTPUT	0xff
#define DIO_u8PORT_INPUT	0

#define DIO_u8PORT_HIGH		0xff
#define DIO_u8PORT_LOW		0

#define DIO_u8PORTA			0
#define DIO_u8PORTB			1
#define DIO_u8PORTC			2
#define DIO_u8PORTD			3

#define DIO_u8PIN0			0
#define DIO_u8PIN1			1
#define DIO_u8PIN2			2
#define DIO_u8PIN3			3
#define DIO_u8PIN4			4
#define DIO_u8PIN5			5
#define DIO_u8PIN6			6
#define DIO_u8PIN7			7

/**
 * @brief Sets the direction of a specific pin.
 *
 * This function sets the direction (input or output) of a specific pin in a port.
 *
 * @param Copy_u8Port The port number (From DIO_u8PORTA till DIO_u8PORTD).
 * @param Copy_u8Pin The pin number within the port (From DIO_u8PIN0 till DIO_u8PIN7).
 * @param Copy_u8Direction The direction to set (DIO_u8PIN_INPUT or DIO_u8PIN_OUTPUT).
 * @return Status of the operation (OK for success, NOK for failure).
 */
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

/**
 * @brief Sets the direction of all pins in a port.
 *
 * This function sets the direction (input or output) of all pins in a specific port.
 *
 * @param Copy_u8Port The port number (From DIO_u8PORTA till DIO_u8PORTD).
 * @param Copy_u8Direction The direction to set (input or output) for all pins (A number from 0x00 till 0xff).
 * @return Status of the operation (OK for success, NOK for failure).
 */
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

/**
 * @brief Sets the value of a specific pin.
 *
 * This function sets the value (high or low) of a specific pin in a port.
 *
 * @param Copy_u8Port The port number (DIO_u8PORTA till DIO_u8PORTD).
 * @param Copy_u8Pin The pin number within the port (From DIO_u8PIN0 till DIO_u8PIN7).
 * @param Copy_u8Value The value to set (DIO_u8PIN_HIGH or DIO_u8PIN_LOW).
 * @return Status of the operation (OK for success, NOK for failure).
 */
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

/**
 * @brief Sets the value of all pins in a port.
 *
 * This function sets the value (high or low) of all pins in a specific port.
 *
 * @param Copy_u8Port The port number (From DIO_u8PORTA till DIO_u8PORTD).
 * @param Copy_u8Value The value to set (high or low) for all pins (A number from 0x00 till 0xff).
 * @return Status of the operation (OK for success, NOK for failure).
 */
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

/**
 * @brief Gets the value of a specific pin.
 *
 * This function reads the value (high or low) of a specific pin in a port and stores it in the provided pointer.
 *
 * @param Copy_u8Port The port number (From DIO_u8PORTA till DIO_u8PORTD).
 * @param Copy_u8Pin The pin number within the port (From DIO_u8PIN0 till DIO_u8PIN7).
 * @param Copy_pu8Value Pointer to store the pin value (high or low).
 * @return Status of the operation (OK for success, NOK for failure).
 */
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8Value);

/**
 * @brief Gets the value of all pins in a port.
 *
 * This function reads the value (high or low) of all pins in a specific port and stores it in the provided pointer.
 *
 * @param Copy_u8Port The port number (From DIO_u8PORTA till DIO_u8PORTD).
 * @param Copy_pu8Value Pointer to store the port value.
 * @return Status of the operation (OK for success, NOK for failure).
 */
u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8* Copy_pu8Value);


#endif /* DIO_INTERFACE_H_ */