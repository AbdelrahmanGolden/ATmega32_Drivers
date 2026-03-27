/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : MCAL			************************/
/***********************	SWC     : TIMER1		************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

/* Options for Waveform Generation Mode:
 * 1. TIMER1_NORMAL
 * 2. TIMER1_CTC_ICR1        (Clear Timer on Compare Match, Top = ICR1)
 * 3. TIMER1_FAST_PWM_ICR1   (Fast PWM, Top = ICR1) -> BEST FOR SERVO
 * 4. TIMER1_FAST_PWM_10BIT
 * 5. TIMER1_FAST_PWM_8BIT
 */
#define TIMER1_WAVEFORM_GENERATION_MODE   TIMER1_FAST_PWM_ICR1

/* Options for Compare Output Mode (Channel A and B):
 * 1. TIMER1_OC_DISCONNECTED
 * 2. TIMER1_OC_TOGGLE
 * 3. TIMER1_OC_NON_INVERTING (Clear on Compare Match, Set at TOP) -> STANDARD PWM
 * 4. TIMER1_OC_INVERTING     (Set on Compare Match, Clear at TOP)
 */
#define TIMER1_OC1A_MODE    TIMER1_OC_NON_INVERTING
#define TIMER1_OC1B_MODE    TIMER1_OC_NON_INVERTING

/* Options for Prescaler:
 * 1. TIMER1_NO_CLK
 * 2. TIMER1_CLK_1
 * 3. TIMER1_CLK_8    -> Good for high frequency
 * 4. TIMER1_CLK_64   -> Good for Servo (50Hz) with 16MHz or 8MHz clock
 * 5. TIMER1_CLK_256
 * 6. TIMER1_CLK_1024
 */
#define TIMER1_PRESCALER    TIMER1_CLK_64

#endif /* TIMER1_CONFIG_H_ */