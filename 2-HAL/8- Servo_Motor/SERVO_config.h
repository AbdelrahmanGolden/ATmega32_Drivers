/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : SERVO			************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#ifndef SERVO_CONFIG_H_
#define SERVO_CONFIG_H_

/* Servo Pulse Limits (Based on Timer1 Prescaler 64 @ 8MHz)
 * Ticks = Time(us) / 8
 * 20ms period = 20000us / 8 = 2500 ticks (ICR1)
 */

/* Adjust these values to calibrate the servo motor */
#define SERVO_MIN_ANGLE_TICKS       125   /* Approx 1ms (1000us / 8) -> 0 Degrees */
#define SERVO_MAX_ANGLE_TICKS       250   /* Approx 2ms (2000us / 8) -> 180 Degrees */
#define SERVO_MAX_ANGLE_DEG         180

#endif /* SERVO_CONFIG_H_ */