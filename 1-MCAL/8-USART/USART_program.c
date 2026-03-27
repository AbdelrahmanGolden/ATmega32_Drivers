/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : USART   		************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 29/01/2025	************************/
/***************************************************************************/
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"
#include "USART_register.h"


void USART_voidSendData(u8 Copy_u8Data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE) == 0); /* wait until transmit data is empty */
	UDR = Copy_u8Data;
}

u8 USART_u8ReceiveData(void)
{
	while(GET_BIT(UCSRA,UCSRA_RXC) == 0); /* wait until Receive Complete */
	return UDR;
}

void USART_voidTransmitDisable(void)
{
	CLR_BIT(UCSRB,UCSRB_TXEN);
}

void USART_voidTransmitEnable(void)
{
	SET_BIT(UCSRB,UCSRB_TXEN);
}

void USART_voidReceiveEnable(void)
{
	SET_BIT(UCSRB,UCSRB_RXEN);
}

void USART_voidReceiveDisable(void)
{
	CLR_BIT(UCSRB,UCSRB_RXEN);
}

void USART_voidInit(void)
{
	u8 Local_u8UCSRCValue = 0;
	
	/* To enable using the UCSRC Register */
	SET_BIT(Local_u8UCSRCValue,UCSRC_URSEL);
	
	/* Make Character size 8 Bit */
	SET_BIT(UCSRC,UCSRC_UCSZ1);
	SET_BIT(UCSRC,UCSRC_UCSZ0);
	
	UCSRC = Local_u8UCSRCValue;
	
	/* Set Baud Rate to 9600 Baud/sec */
	UBRRL = 51;
	
	/* Enabling both Receiving and Transmitting */
	USART_voidReceiveEnable();
	USART_voidTransmitEnable();
}