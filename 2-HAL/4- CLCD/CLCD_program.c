/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : CLCD			************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include <util/delay.h>

#include "CLCD_config.h"
#include "CLCD_private.h"
#include "CLCD_interface.h"

/* Helper function to latch data in 4-bit mode (Sends High Nibble then Low Nibble) */
static void CLCD_voidLatch(u8 Copy_u8Byte)
{
	/* 1. Send High Nibble */
	DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_D4_PIN, GET_BIT(Copy_u8Byte, 4));
	DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_D5_PIN, GET_BIT(Copy_u8Byte, 5));
	DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_D6_PIN, GET_BIT(Copy_u8Byte, 6));
	DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_D7_PIN, GET_BIT(Copy_u8Byte, 7));

	/* Enable Pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
	_delay_us(200);

	/* 2. Send Low Nibble */
	DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_D4_PIN, GET_BIT(Copy_u8Byte, 0));
	DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_D5_PIN, GET_BIT(Copy_u8Byte, 1));
	DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_D6_PIN, GET_BIT(Copy_u8Byte, 2));
	DIO_u8SetPinValue(CLCD_DATA_PORT, CLCD_D7_PIN, GET_BIT(Copy_u8Byte, 3));

	/* Enable Pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
	_delay_ms(2);
}

void CLCD_voidInit(void)
{
	/* Initialize Pins */
	DIO_u8SetPinDirection(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_OUTPUT);

	DIO_u8SetPinDirection(CLCD_DATA_PORT, CLCD_D4_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_DATA_PORT, CLCD_D5_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_DATA_PORT, CLCD_D6_PIN, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_DATA_PORT, CLCD_D7_PIN, DIO_u8PIN_OUTPUT);

	_delay_ms(40);

	/* Initialization Sequence for 4-bit mode */
	// 1. Function Set 
	CLCD_voidSendCommand(0x33);
	// 2. Function Set
	CLCD_voidSendCommand(0x32);
	// 3. Function Set (Lines=2, Font=5x8)
	CLCD_voidSendCommand(CLCD_CMD_FUNCTION_SET_4BIT);

	CLCD_voidSendCommand(CLCD_CMD_DISPLAY_ON_OFF);
	CLCD_voidSendCommand(CLCD_CMD_CLEAR_DISPLAY);
	CLCD_voidSendCommand(CLCD_CMD_ENTRY_MODE_SET);
}

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
	CLCD_voidLatch(Copy_u8Command);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
	CLCD_voidLatch(Copy_u8Data);
}

void CLCD_voidSendString(const char* Copy_pcString)
{
	u8 i = 0;
	while(Copy_pcString[i] != '\0')
	{
		CLCD_voidSendData(Copy_pcString[i]);
		i++;
	}
}

void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8Address;
	if(Copy_u8YPos == 0) Local_u8Address = Copy_u8XPos;
	else Local_u8Address = Copy_u8XPos + 0x40;
	
	CLCD_voidSendCommand(Local_u8Address + 128); 
}

void CLCD_voidClearScreen(void)
{
	CLCD_voidSendCommand(CLCD_CMD_CLEAR_DISPLAY);
}

void CLCD_voidWriteNumber(s32 Copy_s32Number)
{
	u8 str[12];
	u8 i = 0;
	u8 j = 0;
	
	if(Copy_s32Number == 0)
	{
		CLCD_voidSendData('0');
		return;
	}
	
	if(Copy_s32Number < 0)
	{
		CLCD_voidSendData('-');
		Copy_s32Number *= -1;
	}
	
	while(Copy_s32Number > 0)
	{
		str[i] = (Copy_s32Number % 10) + '0';
		Copy_s32Number /= 10;
		i++;
	}
	
	for(j = 0; j < i; j++)
	{
		CLCD_voidSendData(str[i - j - 1]);
	}
}

void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8BlockNumber, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8CGRAM_Address = Copy_u8BlockNumber * 8;
	CLCD_voidSendCommand(Local_u8CGRAM_Address + 64);
	for(u8 Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Counter]);
	}
	CLCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos);
	CLCD_voidSendData(Copy_u8BlockNumber);
}