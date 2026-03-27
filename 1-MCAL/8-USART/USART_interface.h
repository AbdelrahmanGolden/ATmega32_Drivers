/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : USART   		************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 29/01/2025	************************/
/***************************************************************************/
/***************************************************************************/


/**		File Guard		**/
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/**    Macros definitions    **/


/**    Functions Prototype    **/

void USART_voidInit(void);

void USART_voidSendData(u8 Copy_u8Data);

u8 USART_u8ReceiveData(void);

void USART_voidTransmitDisable(void);

void USART_voidTransmitEnable(void);

void USART_voidReceiveEnable(void);

void USART_voidReceiveDisable(void);

#endif /* USART_INTERFACE_H_ */