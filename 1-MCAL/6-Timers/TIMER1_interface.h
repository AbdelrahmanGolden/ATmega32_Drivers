/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : TIMER1		************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void TIMER1_voidInit(void);

void TIMER1_voidSetChannelACompValue(u16 Copy_u16Value);

void TIMER1_voidSetChannelBCompValue(u16 Copy_u16Value);

void TIMER1_voidSetICR(u16 Copy_u16Value);

void TIMER1_voidSetTimerValue(u16 Copy_u16Value);

u16 TIMER1_u16ReadTimerValue(void);

#endif /* TIMER1_INTERFACE_H_ */