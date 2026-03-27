/***************************************************************************/
/***********************	Author  : Golden		************************/
/***********************	Layer   : HAL			************************/
/***********************	SWC     : STEPPER		************************/
/***********************	Version : 1.00			************************/
/***************************************************************************/

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

#define STEPPER_CW      0 // Clockwise
#define STEPPER_CCW     1 // Counter-Clockwise

/**
 * @brief Initialize Stepper Pins as Output.
 */
void STEPPER_voidInit(void);

/**
 * @brief Rotates the stepper motor.
 * @param Copy_u8Direction: STEPPER_CW or STEPPER_CCW.
 * @param Copy_u16Angle: Angle to rotate (approximate).
 */
void STEPPER_voidRotate(u8 Copy_u8Direction, u16 Copy_u16Angle);

#endif /* STEPPER_INTERFACE_H_ */