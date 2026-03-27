/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : STEPPER		************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include <util/delay.h>

#include "STEPPER_config.h"
#include "STEPPER_private.h"
#include "STEPPER_interface.h"

void STEPPER_voidInit(void)
{
	DIO_u8SetPinDirection(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_PORT, STEPPER_PINK_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_u8PIN_OUTPUT);
}

void STEPPER_voidRotate(u8 Copy_u8Direction, u16 Copy_u16Angle)
{
	/* Calculate Steps:
	 * Assuming 2048 steps per revolution (Full Step Mode 28BYJ-48)
	 * Steps per degree = 2048 / 360 = ~5.69
	 * Let's approximate to 6 for simplicity, or 5.
	 * Better: (Angle * 2048) / 360
	 */
	u32 Local_u32Steps = ((u32)Copy_u16Angle * 2048UL) / 360UL;
	
	/* Full Step Sequence? No, 28BYJ-48 works best with Half Step usually, 
     * but here is a Standard 4-step sequence logic simplified:
     */
    
    u32 Local_u32Counter;
    
	for(Local_u32Counter = 0; Local_u32Counter < Local_u32Steps / 4; Local_u32Counter++)
	{
		if(Copy_u8Direction == STEPPER_CW)
		{
			/* Step 1 */
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_u8PIN_LOW);
			_delay_ms(2);

			/* Step 2 */
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_u8PIN_LOW);
			_delay_ms(2);

			/* Step 3 */
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_u8PIN_LOW);
			_delay_ms(2);

			/* Step 4 */
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_u8PIN_HIGH);
			_delay_ms(2);
		}
		else if(Copy_u8Direction == STEPPER_CCW)
		{
			/* Reverse Order */
			/* Step 1 */
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_u8PIN_LOW);
			_delay_ms(2);

			/* Step 2 */
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_u8PIN_LOW);
			_delay_ms(2);

			/* Step 3 */
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_u8PIN_LOW);
			_delay_ms(2);

			/* Step 4 */
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_ORANGE_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_YELLOW_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_PINK_PIN, DIO_u8PIN_LOW);
			DIO_u8SetPinValue(STEPPER_PORT, STEPPER_BLUE_PIN, DIO_u8PIN_HIGH);
			_delay_ms(2);
		}
	}
}