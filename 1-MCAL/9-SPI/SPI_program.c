/***************************************************************************/
/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : SPI   		************************/
/***********************	Version : 1.00			************************/
/***********************	Date    : 04/02/2025	************************/
/***************************************************************************/
/***************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_register.h"

void SPI_voidInitMaster(void)
{
	/* Master Initialize */
	SET_BIT(SPCR,SPCR_MSTR);
	
	/* Clock Prescaler: Divide by 16 */
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPSR,SPSR_SPI2X);
	
	/* SPI Enable */
	SET_BIT(SPCR_SPE);
}

void SPI_voidInitSlave(void)
{
	/* Slave Initialize */
	CLR_BIT(SPCR,SPCR_MSTR);	
	
	/* SPI Enable */
	SET_BIT(SPCR_SPE);
}

u8 SPI_u8TransceiveData(u8 Copy_u8Data)
{
	/* Send the Data */
	SPDR = Copy_u8Data;
	
	/* Busy Waiting until transfer complete */
	while(GET_BIT(SPSR,SPSR_SPIF) == 0);
	
	/* Get the exchanged data */
	return SPDR;
}
