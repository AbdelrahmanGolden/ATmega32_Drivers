/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : STEPPER		************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#ifndef STEPPER_CONFIG_H_
#define STEPPER_CONFIG_H_

/* Define the Port where the Stepper is connected */
#define STEPPER_PORT		DIO_u8PORTC

/* Define the 4 control pins */
#define STEPPER_BLUE_PIN	DIO_u8PIN2
#define STEPPER_PINK_PIN	DIO_u8PIN3
#define STEPPER_YELLOW_PIN	DIO_u8PIN4
#define STEPPER_ORANGE_PIN	DIO_u8PIN5

#endif /* STEPPER_CONFIG_H_ */