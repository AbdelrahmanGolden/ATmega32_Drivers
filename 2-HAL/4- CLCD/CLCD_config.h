/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : CLCD			************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/* 4-Bit Mode Configuration */

/* Control Pins */
#define CLCD_CTRL_PORT      DIO_u8PORTB
#define CLCD_RS_PIN         DIO_u8PIN0
#define CLCD_RW_PIN         DIO_u8PIN1
#define CLCD_E_PIN          DIO_u8PIN2

/* Data Pins "4 bit mode" */
#define CLCD_DATA_PORT      DIO_u8PORTB
#define CLCD_D4_PIN         DIO_u8PIN4
#define CLCD_D5_PIN         DIO_u8PIN5
#define CLCD_D6_PIN         DIO_u8PIN6
#define CLCD_D7_PIN         DIO_u8PIN7

#endif /* CLCD_CONFIG_H_ */


