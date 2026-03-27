/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : LED			************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 10/8/2024		************************/
/***************************************************************************/
/***************************************************************************/


/**		Libraries		**/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "LED_config.h"
#include "LED_private.h"
#include "LED_interface.h"

/**		Functions Implemntation		**/

u8 LED_u8SetState(u8 Copy_u8State, LED_t* Copy_LED)
{
	u8 Local_u8ErrorState = 0;
	
	if(Copy_LED->Connection_Type == LED_u8SOURCE)
	{
		DIO_u8SetPinValue(Copy_LED->Connection_Port,Copy_LED->Connection_Pin,DIO_u8PIN_HIGH);
	}
	else if(Copy_LED->Connection_Type == LED_u8SINK)
	{
		DIO_u8SetPinValue(Copy_LED->Connection_Port,Copy_LED->Connection_Pin,DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}