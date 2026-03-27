/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : EXTI			************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 30/9/2024		************************/
/***************************************************************************/
/***************************************************************************/

/**		Libraries		**/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "EXTI_register.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"

/**		Global Pointer to Function		**/
void (* EXTI_pvInt0Func)(void) = NULL;
void (* EXTI_pvInt1Func)(void) = NULL;
void (* EXTI_pvInt2Func)(void) = NULL;

/**		Functions Implemntation		**/

void EXTI_voidInt0Init(void)
{
	#if INT0_SENSE == LOW_LEVEL
		/*	 Set Sense Control for INT0 to Low Level  */
		CLR_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);
		
		
	#elif INT0_SENSE == ON_CHANGE
		/*	 Set Sense Control for INT0 to On Change  */
		CLR_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
	

	#elif INT0_SENSE == FALLING_EDGE
		/*	 Set Sense Control for INT0 to falling edge  */
		SET_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);
		
		
	#elif INT0_SENSE == RISING_EDGE
		/*	 Set Sense Control for INT0 to falling edge  */
		SET_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);

	
	#else 
		#error "Wrong Configuration Select for the INT0_SENSE Macro in EXTI_config.h file"
	#endif
	
	
	#if INT0_INITIAL_STATE == INT_ENABLED
	/*	 Peripheral Interrupt enable for INT0   */
	SET_BIT(GICR,GICR_INT0);
	
	
	#elif INT0_INITIAL_STATE == INT_DISABLED
	/*	 Peripheral Interrupt disable for INT0   */
	CLR_BIT(GICR,GICR_INT0);
	
	
	#else
		#error "Wrong Configuration Select for the INT0_INITIAL_STATE Macro in EXTI_config.h file"
	#endif
			
}

void EXTI_voidInt1Init(void)
{
	#if INT1_SENSE == LOW_LEVEL
	/*	 Set Sense Control for INT1 to Low Level  */
	CLR_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
	
	
	#elif INT1_SENSE == ON_CHANGE
	/*	 Set Sense Control for INT1 to On Change  */
	CLR_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);
	

	#elif INT1_SENSE == FALLING_EDGE
	/*	 Set Sense Control for INT1 to falling edge  */
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
	
	
	#elif INT1_SENSE == RISING_EDGE
	/*	 Set Sense Control for INT1 to falling edge  */
	SET_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

	
	#else
	#error "Wrong Configuration Select for the INT1_SENSE Macro in EXTI_config.h file"
	#endif
	
	
	#if INT1_INITIAL_STATE == INT_ENABLED
	/*	 Peripheral Interrupt enable for INT1   */
	SET_BIT(GICR,GICR_INT1);
	
	
	#elif INT0_INITIAL_STATE == INT_DISABLED
	/*	 Peripheral Interrupt disable for INT1   */
	CLR_BIT(GICR,GICR_INT1);
	
	
	#else
		#error "Wrong Configuration Select for the INT1_INITIAL_STATE Macro in EXTI_config.h file"
	#endif
	
}

void EXTI_voidInt2Init(void)
{
	#if INT2_SENSE == FALLING_EDGE
	/*	 Set Sense Control for INT2 to falling level  */
	CLR_BIT(MCUCSR,MCUCSR_INT2);
	
	
	#elif INT2_SENSE == RISING_EDGE
	/*	 Set Sense Control for INT2 to rising edge  */
	SET_BIT(MCUCSR,MCUCSR_INT2);

	
	#else
		#error "Wrong Configuration Select for the INT2_SENSE Macro in EXTI_config.h file"
	#endif
	
	
	#if INT2_INITIAL_STATE == INT_ENABLED
	/*	 Peripheral Interrupt enable for INT2   */
	SET_BIT(GICR,GICR_INT2);
	
	
	#elif INT2_INITIAL_STATE == INT_DISABLED
	/*	 Peripheral Interrupt disable for INT2   */
	CLR_BIT(GICR,GICR_INT2);
	
	
	#else
		#error "Wrong Configuration Select for the INT2_INITIAL_STATE Macro in EXTI_config.h file"
	#endif
	
}

u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;

	switch (Copy_u8Sense)
	{
		case LOW_LEVEL:
		/* Set Sense Control for INT0 to Low Level */
		CLR_BIT(MCUCR, MCUCR_ISC01);
		CLR_BIT(MCUCR, MCUCR_ISC00);
		break;

		case ON_CHANGE:
		/* Set Sense Control for INT0 to On Change */
		CLR_BIT(MCUCR, MCUCR_ISC01);
		SET_BIT(MCUCR, MCUCR_ISC00);
		break;

		case FALLING_EDGE:
		/* Set Sense Control for INT0 to Falling Edge */
		SET_BIT(MCUCR, MCUCR_ISC01);
		CLR_BIT(MCUCR, MCUCR_ISC00);
		break;

		case RISING_EDGE:
		/* Set Sense Control for INT0 to Rising Edge */
		SET_BIT(MCUCR, MCUCR_ISC01);
		SET_BIT(MCUCR, MCUCR_ISC00);
		break;

		default:
		/* Invalid input: return error */
		Local_u8ErrorState = NOT_OK;
		break;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;

	switch (Copy_u8Sense)
	{
		case LOW_LEVEL:
		/* Set Sense Control for INT1 to Low Level */
		CLR_BIT(MCUCR, MCUCR_ISC11);
		CLR_BIT(MCUCR, MCUCR_ISC10);
		break;

		case ON_CHANGE:
		/* Set Sense Control for INT1 to On Change */
		CLR_BIT(MCUCR, MCUCR_ISC11);
		SET_BIT(MCUCR, MCUCR_ISC10);
		break;

		case FALLING_EDGE:
		/* Set Sense Control for INT1 to Falling Edge */
		SET_BIT(MCUCR, MCUCR_ISC11);
		CLR_BIT(MCUCR, MCUCR_ISC10);
		break;

		case RISING_EDGE:
		/* Set Sense Control for INT1 to Rising Edge */
		SET_BIT(MCUCR, MCUCR_ISC11);
		SET_BIT(MCUCR, MCUCR_ISC10);
		break;

		default:
		/* Invalid input: return error */
		Local_u8ErrorState = NOT_OK;
		break;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;

	switch (Copy_u8Sense)
	{
		case FALLING_EDGE:
		/* Set Sense Control for INT2 to Falling Edge */
		CLR_BIT(MCUCSR, MCUCSR_INT2);
		break;

		case RISING_EDGE:
		/* Set Sense Control for INT2 to Rising Edge */
		SET_BIT(MCUCSR, MCUCSR_INT2);
		break;

		default:
		/* Invalid input: return error */
		Local_u8ErrorState = NOT_OK;
		break;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8IntEnable(u8 Copy_u8Int)
{
    u8 Local_u8ErrorState = OK;

    switch (Copy_u8Int)
    {
        case EXTI_INT0:
            /* Enable INT0 */
            SET_BIT(GICR, GICR_INT0);
            break;

        case EXTI_INT1:
            /* Enable INT1 */
            SET_BIT(GICR, GICR_INT1);
            break;

        case EXTI_INT2:
            /* Enable INT2 */
            SET_BIT(GICR, GICR_INT2);
            break;

        default:
            /* Invalid interrupt number */
            Local_u8ErrorState = NOT_OK;
            break;
    }

    return Local_u8ErrorState;
}

u8 EXTI_u8IntDisable(u8 Copy_u8Int)
{
    u8 Local_u8ErrorState = OK;

    switch (Copy_u8Int)
    {
        case EXTI_INT0:
            /* Disable INT0 */
            CLR_BIT(GICR, GICR_INT0);
            break;

        case EXTI_INT1:
            /* Disable INT1 */
            CLR_BIT(GICR, GICR_INT1);
            break;

        case EXTI_INT2:
            /* Disable INT2 */
            CLR_BIT(GICR, GICR_INT2);
            break;

        default:
            /* Invalid interrupt number */
            Local_u8ErrorState = NOT_OK;
            break;
    }

    return Local_u8ErrorState;
}

u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func) (void))
{
	u8 Local_u8ErrorState = OK;
	
	if(Copy_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func = Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	
	return Local_u8ErrorState;
}

u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1Func) (void))
{
	u8 Local_u8ErrorState = OK;
	
	if(Copy_pvInt1Func != NULL)
	{
		EXTI_pvInt1Func = Copy_pvInt1Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	
	return Local_u8ErrorState;
}

u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2Func) (void))
{
	u8 Local_u8ErrorState = OK;
	
	if(Copy_pvInt2Func != NULL)
	{
		EXTI_pvInt2Func = Copy_pvInt2Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	
	return Local_u8ErrorState;
}

/**		ISR of INT0		**/
void __vector_1(void) __attribute__((signal));
void __vector_1()
{
	if(EXTI_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		/*		Do Nothing		*/
	}
	
}

/**		ISR of INT1		**/
void __vector_2(void) __attribute__((signal));
void __vector_2()
{
	if(EXTI_pvInt1Func != NULL)
	{
		EXTI_pvInt1Func();
	}
	else
	{
		/*		Do Nothing		*/
	}
	
}

/**		ISR of INT2		**/
void __vector_3(void)  __attribute__((signal));
void __vector_3()
{
	if(EXTI_pvInt2Func != NULL)
	{
		EXTI_pvInt2Func();
	}
	else
	{
		/*		Do Nothing		*/
	}
	
}