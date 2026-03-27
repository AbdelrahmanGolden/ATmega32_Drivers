/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : SERVO			************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Includes */
#include "DIO_interface.h"
#include "TIMER1_interface.h"

/* HAL Includes */
#include "SERVO_config.h"
#include "SERVO_private.h"
#include "SERVO_interface.h"

void SERVO_voidInit(void)
{
	/* 1. Set PWM Pin Direction (OC1A = PortD Pin5) */
	DIO_u8SetPinDirection(DIO_u8PORTD, DIO_u8PIN5, DIO_u8PIN_OUTPUT);

	/* 2. Initialize Timer1 (Fast PWM, ICR1 Top) */
	TIMER1_voidInit();

	/* 3. Set PWM Period to 20ms (50Hz) */
	/* 8MHz / 64 Prescaler = 125kHz ticks (8us per tick) */
	/* 20ms / 8us = 2500 ticks */
	TIMER1_voidSetICR(2500); 
}

void SERVO_voidSetAngle(u8 Copy_u8Angle)
{
	u32 Local_u32MappingValue;

	if(Copy_u8Angle > SERVO_MAX_ANGLE_DEG)
	{
		Copy_u8Angle = SERVO_MAX_ANGLE_DEG;
	}

	/* Linear Mapping:
	 * PWM = Min + ( (Angle * (Max - Min)) / 180 )
	 */
	Local_u32MappingValue = (u32)Copy_u8Angle * (SERVO_MAX_ANGLE_TICKS - SERVO_MIN_ANGLE_TICKS);
	Local_u32MappingValue = (Local_u32MappingValue / SERVO_MAX_ANGLE_DEG) + SERVO_MIN_ANGLE_TICKS;

	/* Write to OCR1A (Channel A) */
	TIMER1_voidSetChannelACompValue((u16)Local_u32MappingValue);
}