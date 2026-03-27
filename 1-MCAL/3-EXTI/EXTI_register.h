/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : EXTI			************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 30/9/2024		************************/
/***************************************************************************/
/***************************************************************************/


/**		File Guard		**/
#ifndef EXTI_REGISTSER_H_ 
#define EXTI_REGISTSER_H_ 

/**			Registers Definition		**/

#define GICR			 *((volatile u8*) 0x5B)
#define GICR_INT1		 7
#define GICR_INT0		 6
#define GICR_INT2		 5


#define GIFR			 *((volatile u8*) 0x5A)


/* What event happens to trigger interrupt on pins INT0 and INT1
 *
 *  ISC11	ISC10
 *	0		0		The low level of INT1 generates an interrupt request.
 *	0		1		Any logical change on INT1 generates an interrupt request.
 *	1		0		The falling edge of INT1 generates an interrupt request.
 *	1		1		The rising edge of INT1 generates an interrupt request.
 *
 *
 *	ISC01	ISC00
 *	0		0		The low level of INT0 generates an interrupt request.
 *	0		1		Any logical change on INT0 generates an interrupt request.
 *	1		0		The falling edge of INT0 generates an interrupt request.
 *	1		1		The rising edge of INT0 generates an interrupt request.
 *
*/
#define MCUCR			 *((volatile u8*) 0x55)
#define MCUCR_ISC11		 3
#define MCUCR_ISC10		 2
#define MCUCR_ISC01		 1
#define MCUCR_ISC00		 0

/*  If MCUCSR_INT2 is written to zero, a falling edge on
INT2 activates the interrupt. If MCUCSR_INT2 is written to one, a rising edge on INT2 activates the interrupt.*/
#define MCUCSR		     *((volatile u8*) 0x54)
#define MCUCSR_INT2      6


#endif /* EXTI_REGISTSER_H_ */