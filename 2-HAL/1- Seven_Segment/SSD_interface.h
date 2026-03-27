/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : SSD			************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 10/8/2024		************************/
/***************************************************************************/
/***************************************************************************/


/**		File Guard		**/
#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/**		Macros Definition		**/
#define SSD_u8ANODE			0
#define SSD_u8CATHODE		1

#define SSD_u8STATE_OFF		0
#define SSD_u8STATE_ON		1

#define SSD_u8NUM0			0
#define SSD_u8NUM1			1
#define SSD_u8NUM2			2
#define SSD_u8NUM3			3
#define SSD_u8NUM4			4
#define SSD_u8NUM5			5
#define SSD_u8NUM6			6
#define SSD_u8NUM7			7
#define SSD_u8NUM8			8
#define SSD_u8NUM9			9


/**		Struct		**/

/**
 * @brief Struct to configure a Seven Segment Display (SSD).
 * 
 * This struct is used to define the configuration for a Seven Segment Display (SSD),
 * including its type (common anode or common cathode), the port to which it is connected,
 * and the port and pin used to enable it.
 */
typedef struct {
    u8 Common_Type;     /*!< SSD_u8ANODE or SSD_u8CATHODE */
    u8 Port;            /*!< DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD */
    u8 Enable_Port;     /*!< DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD */
    u8 Enable_Pin;      /*!< From DIO_u8PIN0 to DIO_u8PIN7 */					  	
} SSD_t;


/**		Functions Prototype		**/


/**
 * @brief Displays a number on the Seven Segment Display.
 *
 * This function displays the specified number on the Seven Segment Display (SSD).
 * 
 * @param Copy_u8Number The number to be displayed (SSD_u8NUM0 till SSD_u8NUM9).
 * @param Seven_Segment A pointer to the SSD_t struct that defines the configuration of the SSD.
 * @return Status of the operation (0 for success, 1 for failure).
 */
u8 SSD_u8SetNumber(u8 Copy_u8Number, SSD_t* Seven_Segment);

/**
 * @brief Displays a number upside down on the Seven Segment Display.
 *
 * This function displays the specified number upside down on the Seven Segment Display (SSD).
 * 
 * @param Copy_u8Number The number to be displayed upside down (SSD_u8NUM0 till SSD_u8NUM9).
 * @param Seven_Segment A pointer to the SSD_t struct that defines the configuration of the SSD.
 * @return Status of the operation (0 for success, 1 for failure).
 */
u8 SSD_u8SetNumberUpsideDown(u8 Copy_u8Number, SSD_t* Seven_Segment);

/**
 * @brief Sets the state of the Seven Segment Display.
 *
 * This function sets the state of the Seven Segment Display (SSD) (ON or OFF).
 *
 * @param Copy_u8State Th * @return Status of the operation (0 for success, 1 for failure).
e state to set (SSD_u8STATE_OFF or SSD_u8STATE_ON).
 * @param Seven_Segment A pointer to the SSD_t struct that defines the configuration of the SSD.
 */
u8 SSD_u8SetState(u8 Copy_u8State, SSD_t* Seven_Segment);


#endif /* SSD_INTERFACE_H_ */
