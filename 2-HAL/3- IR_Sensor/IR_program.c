/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : IR			************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 27/01/2025	************************/
/***************************************************************************/
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "IR_config.h"
#include "IR_private.h"
#include "IR_interface.h"

/**		Functions Implemntation		**/

u8 IR_u8GetDigitalReading(IR_t* Copy_IR)
{
	u8 Local_IR_Pin_Value;
	DIO_u8GetPinValue(Copy_IR->Connection_Port,Copy_IR->Connection_Pin,&Local_IR_Pin_Value);
	
	if(Local_IR_Pin_Value == OBSTACLE_DETECTED_DIGITAL_VALUE)
	{
		return OBSTACLE_DETECTED;
	} 
	else
	{
		return OBSTACLE_NOT_DETECTED;
	}
}