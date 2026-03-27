/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : SERVO			************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

/**
 * @brief Initialize the Servo Driver.
 * Sets the direction of the PWM pin (OC1A/OC1B) and initializes Timer1.
 */
void SERVO_voidInit(void);

/**
 * @brief Set the servo angle.
 * @param Copy_u8Angle: Angle from 0 to 180 degrees.
 */
void SERVO_voidSetAngle(u8 Copy_u8Angle);

#endif /* SERVO_INTERFACE_H_ */