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
#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_


#define UDR					*((volatile u8*)0x2C)   /* USART I/O Data Register */


#define UBRRL				*((volatile u8*)0x29)	/* Baud Rate Register Low Byte */


#define UBRRH				*((volatile u8*)0x40)	/* Baud Rate Register High Byte */


#define UCSRC				*((volatile u8*)0x40)	/* Control and Status Register A */
#define UCSRC_URSEL			7						/* Register Select Bit */	
#define UCSRC_UMSEL			6						/* USART Mode Select 'Asynchronous = 0', while 'Synchronous = 1' */	
#define UCSRC_UPM1			5						/* Parity Mode Bit 1 */	
#define UCSRC_UPM0			4						/* Parity Mode Bit 0 */
#define UCSRC_USBS			3						/* Stop Bit Select */
#define UCSRC_UCSZ1			2						/* Character Size Bit 1 */
#define UCSRC_UCSZ0			1						/* Character Size Bit 0 */
#define UCSRC_UCPOL			0						/* Clock Polarity */


#define UCSRA				*((volatile u8*)0x2B)	/* Control and Status Register A */
#define UCSRA_RXC			7						/* Receive Complete Flag */
#define UCSRA_TXC			6						/* Transmit Complete Flag */
#define UCSRA_UDRE			5						/* Data Register Empty Flag */
#define UCSRA_FE			4						/* Frame Error Flag */
#define UCSRA_DOR			3						/* Data OverRun Flag */
#define UCSRA_PE			2						/* Parity Error Flag */
#define UCSRA_U2X			1						/* Double the USART Transmission Speed when sit to 1 */
#define UCSRA_MPCM			0						/* Multi-processor Communication Mode */


#define UCSRB				*((volatile u8*)0x2A)	/* Control and Status Register B */
#define UCSRB_RXCIE			7						/* RX Complete Interrupt Enable */ 
#define UCSRB_TXCIE			6						/* TX Complete Interrupt Enable */ 
#define UCSRB_UDRIE			5						/* USART Data Register Empty Interrupt Enable */ 
#define UCSRB_RXEN			4						/* Receiver Enable */ 
#define UCSRB_TXEN			3						/* Transmitter Enable */ 
#define UCSRB_UCSZ2			2						/* Character Size Bit 2 */ 
#define UCSRB_RXB8			1						/* Receive Data Bit 8 */ 
#define UCSRB_TXB8			0						/* Transmit Data Bit 8 */ 


#endif /* USART_REGISTER_H_ */