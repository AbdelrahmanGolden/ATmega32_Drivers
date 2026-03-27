/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : WDT   		************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 28/01/2025	************************/
/***************************************************************************/
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WDT_interface.h"
#include "WDT_config.h"
#include "WDT_private.h"
#include "WDT_register.h"


void WDT_voidSleep(u8 Copy_u8SleepTime)
{
	/* Clear Prescalar bits */
	WDTCR &= 0b11111000;
	
	/* Set Required Prescalar */
	WDTCR |= Copy_u8SleepTime;
}

void WDT_voidEnable(void)
{
	SET_BIT(WDTCR,WDTCR_WDE);
}

void WDT_voidDisable(void)
{
	WDTCR |= 0b00011000;  /* Set WDTOE and WDE bits */
	WDTCR = 0;            /* Clear WDE bit to disable WDT */
}


u8 WDT_u8IsEnabled(void)
{
    return (WDTCR & (1 << WDTCR_WDE)) ? 1 : 0;
}
