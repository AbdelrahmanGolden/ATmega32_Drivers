/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : TIMER1		************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

/* TCCR1A Bits */
#define TCCR1A_WGM10    0
#define TCCR1A_WGM11    1
#define TCCR1A_FOC1B    2
#define TCCR1A_FOC1A    3
#define TCCR1A_COM1B0   4
#define TCCR1A_COM1B1   5
#define TCCR1A_COM1A0   6
#define TCCR1A_COM1A1   7

/* TCCR1B Bits */
#define TCCR1B_CS10     0
#define TCCR1B_CS11     1
#define TCCR1B_CS12     2
#define TCCR1B_WGM12    3
#define TCCR1B_WGM13    4
#define TCCR1B_ICES1    6
#define TCCR1B_ICNC1    7

/* TIMSK Bits */
#define TIMSK_TOIE1     2
#define TIMSK_OCIE1B    3
#define TIMSK_OCIE1A    4
#define TIMSK_TICIE1    5

/* TIFR Bits */
#define TIFR_TOV1       2
#define TIFR_OCF1B      3
#define TIFR_OCF1A      4
#define TIFR_ICF1       5

/* Configuration Options for Config File */

/* Waveform Generation Modes */
#define TIMER1_NORMAL               0
#define TIMER1_CTC_ICR1             1
#define TIMER1_FAST_PWM_ICR1        2
#define TIMER1_FAST_PWM_10BIT       3
#define TIMER1_FAST_PWM_8BIT        4

/* Compare Output Mode */
#define TIMER1_OC_DISCONNECTED      0
#define TIMER1_OC_TOGGLE            1
#define TIMER1_OC_NON_INVERTING     2
#define TIMER1_OC_INVERTING         3

/* Prescaler Options */
#define TIMER1_NO_CLK               0
#define TIMER1_CLK_1                1
#define TIMER1_CLK_8                2
#define TIMER1_CLK_64               3
#define TIMER1_CLK_256              4
#define TIMER1_CLK_1024             5

#endif /* TIMER1_PRIVATE_H_ */