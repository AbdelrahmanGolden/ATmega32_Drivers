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
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_



/***		INT0 Configurations		***/
/**
 * Options:
 *		  1- LOW_LEVEL
 *		  2- ON_CHANGE
 *		  3- FALLING_EDGE
 *		  4- RISING_EDGE
**/
#define INT0_SENSE			FALLING_EDGE

/**
 * Options:
 *		  1- INT_ENABLED
 *		  2- INT_DISABLED
**/
#define INT0_INITIAL_STATE	INT_ENABLED




/***		INT1 Configurations		***/
/**
 * Options:
 *		  1- LOW_LEVEL
 *		  2- ON_CHANGE
 *		  3- FALLING_EDGE
 *		  4- RISING_EDGE
**/
#define INT1_SENSE			FALLING_EDGE

/**
 * Options:
 *		  1- INT_ENABLED
 *		  2- INT_DISABLED
**/
#define INT1_INITIAL_STATE	INT_ENABLED




/***		INT2 Configurations		***/
/**
 * Options:
 *		  1- FALLING_EDGE
 *		  2- RISING_EDGE
**/
#define INT2_SENSE			FALLING_EDGE

/**
 * Options:
 *		  1- INT_ENABLED
 *		  2- INT_DISABLED
**/
#define INT2_INITIAL_STATE	INT_ENABLED



#endif /* EXTI_CONFIG_H_ */