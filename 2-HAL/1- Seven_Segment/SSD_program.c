/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : SSD			************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 10/8/2024		************************/
/***************************************************************************/
/***************************************************************************/

/**		Libraries		**/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"
#include "SSD_interface.h"
	

/**		Numbers assuming Common Cathode		**/	
// for common Anode reverse the number using '~'
const u8 SSD_Numbers[10] =
{
	0b00111111, // 0: a, b, c, d, e, f
	0b00000110, // 1: b, c
	0b01011011, // 2: a, b, d, e, g
	0b01001111, // 3: a, b, c, d, g
	0b01100110, // 4: b, c, f, g
	0b01101101, // 5: a, c, d, f, g
	0b01111101, // 6: a, c, d, e, f, g
	0b00000111, // 7: a, b, c
	0b01111111, // 8: a, b, c, d, e, f, g
	0b01101111  // 9: a, b, c, d, f, g
};

/**		Numbers Upsidedown assuming Common Cathode		**/
// for common Anode reverse the number using '~'


/** Replacements:
 *  a -> d
 *  b -> e
 *  c -> f
 *  d -> a
 *  e -> b
 *  f -> c
 *  g -> g
 */
const u8 SSD_NumbersUpsideDown[10] =
{
	0b00111111, // 0: a, b, c, d, e, f
	0b00110110, // 1: e, f
	0b01011011, // 2: a, b, d, e, g
	0b01111001, // 3: a, d, e, f, g
	0b01110100, // 4: c, e, f, g
	0b01101101, // 5: a, c, d, f, g
	0b01101111, // 6: a, b, c, d, f, g
	0b00111000, // 7: d, e, f
	0b01111111, // 8: a, b, c, d, e, f, g
	0b01111101  // 9: a, c, d, e, f, g
};


/**		Functions Implemntation		**/

u8 SSD_u8SetNumber(u8 Copy_u8Number, SSD_t* Seven_Segment)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_u8Number<SSD_u8NUM0 || Copy_u8Number>SSD_u8NUM9)
	{
		Local_u8ErrorState = 1;
	}
	else
	{
		if(Seven_Segment->Common_Type == SSD_u8CATHODE)
		{
			DIO_u8SetPortValue(Seven_Segment->Port, SSD_Numbers[Copy_u8Number]);
		}
		else if(Seven_Segment->Common_Type == SSD_u8ANODE)
		{
			DIO_u8SetPortValue(Seven_Segment->Port, ~(SSD_Numbers[Copy_u8Number]));
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	}
	
	return Local_u8ErrorState;
}


u8 SSD_u8SetNumberUpsideDown(u8 Copy_u8Number, SSD_t* Seven_Segment)
{
	u8 Local_u8ErrorState = 0;
	if(Copy_u8Number<SSD_u8NUM0 || Copy_u8Number>SSD_u8NUM9)
	{
		Local_u8ErrorState = 1;
	}
	else
	{
		if(Seven_Segment->Common_Type == SSD_u8CATHODE)
		{
			DIO_u8SetPortValue(Seven_Segment->Port, SSD_NumbersUpsideDown[Copy_u8Number]);
		}
		else if(Seven_Segment->Common_Type == SSD_u8ANODE)
		{
			DIO_u8SetPortValue(Seven_Segment->Port, ~SSD_NumbersUpsideDown[Copy_u8Number]);
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	}
	
	return Local_u8ErrorState;
}


u8 SSD_u8SetState(u8 Copy_u8State, SSD_t* Seven_Segment)
{
	u8 Local_u8ErrorState = 0;
	
	if(Copy_u8State == SSD_u8STATE_OFF)
	{
		if(Seven_Segment->Common_Type == SSD_u8CATHODE)
		{
			DIO_u8SetPinValue(Seven_Segment->Enable_Port, Seven_Segment->Enable_Pin, DIO_u8PIN_HIGH);
		}
		else if(Seven_Segment->Common_Type == SSD_u8ANODE)
		{
			DIO_u8SetPinValue(Seven_Segment->Enable_Port, Seven_Segment->Enable_Pin, DIO_u8PIN_LOW);
		}
		else
		{
			Local_u8ErrorState = 1;
		}
		
	}
	else if(Copy_u8State == SSD_u8STATE_ON)
	{
		if(Seven_Segment->Common_Type == SSD_u8CATHODE)
		{
			DIO_u8SetPinValue(Seven_Segment->Enable_Port, Seven_Segment->Enable_Pin, DIO_u8PIN_LOW);
		}
		else if(Seven_Segment->Common_Type == SSD_u8ANODE)
		{
			DIO_u8SetPinValue(Seven_Segment->Enable_Port, Seven_Segment->Enable_Pin, DIO_u8PIN_HIGH);
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	
	return Local_u8ErrorState;
}