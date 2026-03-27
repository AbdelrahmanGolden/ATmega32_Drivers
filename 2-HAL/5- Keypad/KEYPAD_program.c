/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : Keypad		************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include <util/delay.h>

#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include "KEYPAD_interface.h"

void KEYPAD_voidInit(void)
{
	/* 1. Set Columns as OUTPUT */
	DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_COLUMN0_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_COLUMN1_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_COLUMN2_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_COLUMN3_PIN, DIO_u8PIN_OUTPUT);

	/* 2. Set Rows as INPUT */
	DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_ROW0_PIN, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_ROW1_PIN, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_ROW2_PIN, DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(KEYPAD_PORT, KEYPAD_ROW3_PIN, DIO_u8PIN_INPUT);

	/* 3. Set Columns to HIGH (Idle State) */
	DIO_u8SetPinValue(KEYPAD_PORT, KEYPAD_COLUMN0_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KEYPAD_PORT, KEYPAD_COLUMN1_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KEYPAD_PORT, KEYPAD_COLUMN2_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KEYPAD_PORT, KEYPAD_COLUMN3_PIN, DIO_u8PIN_HIGH);

	/* 4. Enable Internal Pull-up on Rows (Write High to Input pins) */
	DIO_u8SetPinValue(KEYPAD_PORT, KEYPAD_ROW0_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KEYPAD_PORT, KEYPAD_ROW1_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KEYPAD_PORT, KEYPAD_ROW2_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(KEYPAD_PORT, KEYPAD_ROW3_PIN, DIO_u8PIN_HIGH);
}

u8 KEYPAD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey = KEYPAD_NO_PRESSED_KEY;
	
	/* Arrays to map loop index to physical pin definitions */
	u8 Local_u8ColumnArr[COLUMN_NUM] = {KEYPAD_COLUMN0_PIN, KEYPAD_COLUMN1_PIN, KEYPAD_COLUMN2_PIN, KEYPAD_COLUMN3_PIN};
	u8 Local_u8RowArr[ROW_NUM]       = {KEYPAD_ROW0_PIN, KEYPAD_ROW1_PIN, KEYPAD_ROW2_PIN, KEYPAD_ROW3_PIN};
	
	/* The actual character map */
	u8 Local_u8KeypadArr[ROW_NUM][COLUMN_NUM] = KEYPAD_ARR_VAL;

	u8 Local_u8ColumnIdx, Local_u8RowIdx, Local_u8PinState;

	/* Loop through Columns */
	for(Local_u8ColumnIdx = 0; Local_u8ColumnIdx < COLUMN_NUM; Local_u8ColumnIdx++)
	{
		/* Activate current column (Set LOW) */
		DIO_u8SetPinValue(KEYPAD_PORT, Local_u8ColumnArr[Local_u8ColumnIdx], DIO_u8PIN_LOW);

		/* Check Rows */
		for(Local_u8RowIdx = 0; Local_u8RowIdx < ROW_NUM; Local_u8RowIdx++)
		{
			/* Read the Row Pin */
			DIO_u8GetPinValue(KEYPAD_PORT, Local_u8RowArr[Local_u8RowIdx], &Local_u8PinState);

			/* If Row is LOW, button is pressed */
			if(Local_u8PinState == DIO_u8PIN_LOW)
			{
				/* Get the character from the map */
				Local_u8PressedKey = Local_u8KeypadArr[Local_u8RowIdx][Local_u8ColumnIdx];

				/* Wait for key release (Polling / Busy Wait) */
				while(Local_u8PinState == DIO_u8PIN_LOW)
				{
					DIO_u8GetPinValue(KEYPAD_PORT, Local_u8RowArr[Local_u8RowIdx], &Local_u8PinState);
				}

				/* Deactivate Column and Return immediately */
				DIO_u8SetPinValue(KEYPAD_PORT, Local_u8ColumnArr[Local_u8ColumnIdx], DIO_u8PIN_HIGH);
				return Local_u8PressedKey;
			}
		}

		/* Deactivate Column (Set HIGH) before moving to the next one */
		DIO_u8SetPinValue(KEYPAD_PORT, Local_u8ColumnArr[Local_u8ColumnIdx], DIO_u8PIN_HIGH);
	}

	return Local_u8PressedKey;
}