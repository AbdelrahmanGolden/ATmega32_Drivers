/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : TIMER1		************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#ifndef TIMER1_REGISTER_H_
#define TIMER1_REGISTER_H_

/* Timer/Counter1 Control Register A */
#define TCCR1A		*((volatile u8 *)0x4F)

/* Timer/Counter1 Control Register B */
#define TCCR1B		*((volatile u8 *)0x4E)

/* Timer/Counter1 - Counter Register (16-bit) */
#define TCNT1		*((volatile u16*)0x4C)

/* Output Compare Register 1 A (16-bit) */
#define OCR1A		*((volatile u16*)0x4A)

/* Output Compare Register 1 B (16-bit) */
#define OCR1B		*((volatile u16*)0x48)

/* Input Capture Register 1 (16-bit) */
#define ICR1		*((volatile u16*)0x46)

/* Timer/Counter Interrupt Mask Register */
#define TIMSK		*((volatile u8 *)0x59)

/* Timer/Counter Interrupt Flag Register */
#define TIFR		*((volatile u8 *)0x58)

#endif /* TIMER1_REGISTER_H_ */