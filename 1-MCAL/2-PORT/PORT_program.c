/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : PORT			************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 29/8/2024		************************/
/***************************************************************************/
/***************************************************************************/

/**		Libraries		**/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "PORT_register.h"
#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_interface.h"



/**		Functions Implemntation		**/

void PORT_voidInit(void)
{
	/*	Initial directions */
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;
	
	/*	Initial values */
	PORTA = PORTA_INITIAL_VALUE;
	PORTB = PORTB_INITIAL_VALUE;
	PORTC = PORTC_INITIAL_VALUE;
	PORTD = PORTD_INITIAL_VALUE;
}