/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : TIMER1		************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER1_register.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"
#include "TIMER1_interface.h"

void TIMER1_voidInit(void)
{
	/* Set Waveform Generation Mode */
	#if TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_NORMAL
		CLR_BIT(TCCR1A, TCCR1A_WGM10);
		CLR_BIT(TCCR1A, TCCR1A_WGM11);
		CLR_BIT(TCCR1B, TCCR1B_WGM12);
		CLR_BIT(TCCR1B, TCCR1B_WGM13);

	#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_CTC_ICR1
		CLR_BIT(TCCR1A, TCCR1A_WGM10);
		CLR_BIT(TCCR1A, TCCR1A_WGM11);
		SET_BIT(TCCR1B, TCCR1B_WGM12);
		SET_BIT(TCCR1B, TCCR1B_WGM13);

	#elif TIMER1_WAVEFORM_GENERATION_MODE == TIMER1_FAST_PWM_ICR1
		/* Fast PWM, Top = ICR1 (Mode 14) */
		CLR_BIT(TCCR1A, TCCR1A_WGM10);
		SET_BIT(TCCR1A, TCCR1A_WGM11);
		SET_BIT(TCCR1B, TCCR1B_WGM12);
		SET_BIT(TCCR1B, TCCR1B_WGM13);
	#endif

	/* Set Compare Output Mode for Channel A */
	#if TIMER1_OC1A_MODE == TIMER1_OC_DISCONNECTED
		CLR_BIT(TCCR1A, TCCR1A_COM1A0);
		CLR_BIT(TCCR1A, TCCR1A_COM1A1);
	#elif TIMER1_OC1A_MODE == TIMER1_OC_TOGGLE
		SET_BIT(TCCR1A, TCCR1A_COM1A0);
		CLR_BIT(TCCR1A, TCCR1A_COM1A1);
	#elif TIMER1_OC1A_MODE == TIMER1_OC_NON_INVERTING
		CLR_BIT(TCCR1A, TCCR1A_COM1A0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
	#elif TIMER1_OC1A_MODE == TIMER1_OC_INVERTING
		SET_BIT(TCCR1A, TCCR1A_COM1A0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
	#endif

	/* Set Compare Output Mode for Channel B */
	#if TIMER1_OC1B_MODE == TIMER1_OC_DISCONNECTED
		CLR_BIT(TCCR1A, TCCR1A_COM1B0);
		CLR_BIT(TCCR1A, TCCR1A_COM1B1);
	#elif TIMER1_OC1B_MODE == TIMER1_OC_TOGGLE
		SET_BIT(TCCR1A, TCCR1A_COM1B0);
		CLR_BIT(TCCR1A, TCCR1A_COM1B1);
	#elif TIMER1_OC1B_MODE == TIMER1_OC_NON_INVERTING
		CLR_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);
	#elif TIMER1_OC1B_MODE == TIMER1_OC_INVERTING
		SET_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);
	#endif

	/* Set Prescaler */
	TCCR1B &= 0xF8; // Clear CS10, CS11, CS12
	TCCR1B |= TIMER1_PRESCALER;
}

void TIMER1_voidSetChannelACompValue(u16 Copy_u16Value)
{
	OCR1A = Copy_u16Value;
}

void TIMER1_voidSetChannelBCompValue(u16 Copy_u16Value)
{
	OCR1B = Copy_u16Value;
}

void TIMER1_voidSetICR(u16 Copy_u16Value)
{
	ICR1 = Copy_u16Value;
}

void TIMER1_voidSetTimerValue(u16 Copy_u16Value)
{
	TCNT1 = Copy_u16Value;
}

u16 TIMER1_u16ReadTimerValue(void)
{
	return TCNT1;
}