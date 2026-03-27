/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : ADC			************************/
/***********************	Version : 1.10			************************/
/***********************	Date    : 08/01/2025	************************/
/***************************************************************************/
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_register.h"

static u16* ADC_pu16Reading = NULL;
static void (*ADC_pvCallBackNotificationFunc)(void) = NULL;

static u8* ADC_pu8ChainChannelArr = NULL;		/* Global variable to carry chain array */
static u16* ADC_pu16ChainResult_Arr = NULL;		/* Global variable to carry chain results */
static u8 ADC_u8ChainSize = NULL;				/* Global variable to carry number of channels in chain */
static u8 ADC_u8ChainConversionIndex = 0;		/* Global Variable to carry the current Channel index in chain conversion */

u8 ADC_u8BusyState = ADC_IDLE;

static u8 ADC_u8ISRSource = 0;

void ADC_voidInit(void)
{
	/*	 AVCC as reference Voltage	*/
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);
	
	/*	Activate Left Adjust Result	 */
	SET_BIT(ADMUX, ADMUX_ADLAR);
	
	/*Enable Peripheral*/
	SET_BIT(ADCSRA, ADCSRA_ADEN);
}

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u16* Copy_pu8Reading) 
{
	u32 Local_u32Counter = 0;
	u8 Local_u8ErrorState = OK;
	
	/*	Clear the MUX bits in ADMUX register	 */
	ADMUX &= 0b11100000;
	
	/*	Write the Channel in the ADMUX register	 */
	ADMUX |= Copy_u8Channel;
	
	/*	Start Conversion	 */
	SET_BIT(ADCSRA, ADCSRA_ADSC);
	
	/*	Polling (busy waiting) until the conversion flag is set or Timeout reached  */
	while( (GET_BIT(ADCSRA, ADCSRA_ADIF) == 0) && (Local_u32Counter != ADC_u32_TIMEOUT) )
	{
		Local_u32Counter++;
	}
	
	if( Local_u32Counter == ADC_u32_TIMEOUT)
	{
		/*	 Loop is broken because timeout is reached 	*/
		Local_u8ErrorState = NOK;
	}
	else
	{
		/*	Clear the Conversion Flag  */
		SET_BIT(ADCSRA, ADCSRA_ADIF);
		
		/*	Return Reading  */
		*Copy_pu8Reading = ADCH;
	}
	return Local_u8ErrorState;
}

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16* Copy_pu8Reading, void(*Copy_pvNotificationFunc)(void) )
{
	if( ADC_u8BusyState == ADC_BUSY)
	{
		return NOK;
	}
	u8 Local_u8ErrorState = OK;
	if( (Copy_pvNotificationFunc == NULL) || (Copy_pu8Reading == NULL)  )
	{
		Local_u8ErrorState == NULL_POINTER;
	}
	else
	{
		ADC_u8BusyState = ADC_BUSY;								/* Making the state busy */
		ADC_u8ISRSource = SINGLE_CHANNEL_ASYNCH;
		
		ADC_pu16Reading = Copy_pu8Reading;
		ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc;
		
		/*	Clear the MUX bits in ADMUX register	 */
		ADMUX &= 0b11100000;
		
		/*	Write the Channel in the ADMUX register	 */
		ADMUX |= Copy_u8Channel;
		
		/*	Start Conversion	 */
		SET_BIT(ADCSRA, ADCSRA_ADSC);
		
		/*	 ADC Interrupt enable	*/
		SET_BIT(ADCSRA, ADCSRA_ADIE);
	}
}

u8 ADC_u8StartChainAsynch(Chain_t *Copy_Chain){
	u8 Local_u8ErrorState = OK;
	
	if(Copy_Chain == NULL)					/* Check NULL Pointer */
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	else if(ADC_u8BusyState == ADC_BUSY)	/* Check ADC State */
	{
		Local_u8ErrorState = NOK;
	}
	else                                    /* If all good */
	{
		ADC_u8BusyState = ADC_BUSY;											/* Making the state busy */
		ADC_u8ISRSource = CHAIN_CHANNEL_ASYNCH;
		
		ADC_pu8ChainChannelArr			= Copy_Chain->Channel_Arr;			/* Initialize Chain Channel Array and making it Global */
		ADC_pu16ChainResult_Arr			= Copy_Chain->Result_Arr;			/* Initialize Chain Result Array and making it Global */
		ADC_u8ChainSize					= Copy_Chain->Result_Arr;			/* Initialize Chain size and making it Global */
		ADC_pvCallBackNotificationFunc  = Copy_Chain->NotificationFunction;	/* Initialize Chain Notification function and making it Global */
		
		ADC_u8ChainConversionIndex = 0;		/* Initializing current conversion Index with 0 */
		
		/* Set required Channel to first one */
		ADMUX &= 0b11100000; //Masking
		ADMUX |= ADC_pu8ChainChannelArr[ADC_u8ChainConversionIndex];
		
		/* Start Conversion */
		SET_BIT(ADCSRA,ADCSRA_ADSC);
		
		/* Enable Conversion Interrupt enable */
		SET_BIT(ADCSRA, ADCSRA_ADIE);
		
			
	}
	
	return Local_u8ErrorState;
}

u8 ADC_u8SetCallBack(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvCallBackFunc != NULL)
	{
		ADC_pvCallBackNotificationFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
	
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	if(ADC_u8ISRSource == SINGLE_CHANNEL_ASYNCH) /* If we are coming from the Single channel function */
	{
		/*	 Read ADC Result	*/
		*ADC_pu16Reading = ADCH;
		
		ADC_u8BusyState = ADC_IDLE;
		
		/*	 Invoke the Call back notification function 	*/
		ADC_pvCallBackNotificationFunc();
		
		/*	  Disable ADC conversion complete interrupt		*/
		CLR_BIT(ADCSRA, ADCSRA_ADIE);
	}
	else if(ADC_u8ISRSource == CHAIN_CHANNEL_ASYNCH) /* If we are coming from the chain channel function */
	{
		/* Read Current ADC conversion Result */
		ADC_pu16ChainResult_Arr[ADC_u8ChainConversionIndex] = ADCH;
		
		/* Increment chain Index */
		ADC_u8ChainConversionIndex++;
		
		/* Check Chain is finished or not */
		if(ADC_u8ChainConversionIndex == ADC_u8ChainSize)
		{
			/* Chain is finished */
			ADC_u8BusyState = ADC_IDLE;
			
			/* Invoke the Call back notification function */
			ADC_pvCallBackNotificationFunc();
			
			/* Disable ADC conversion complete interrupt */
			CLR_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			/* Chain is not finished */
			
			/* Set required New Required Channel*/
			ADMUX &= 0b11100000; //Masking
			ADMUX |= ADC_pu8ChainChannelArr[ADC_u8ChainConversionIndex];
			
			/* Start Conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			
		}
	}
}