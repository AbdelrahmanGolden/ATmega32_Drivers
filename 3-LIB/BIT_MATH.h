#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/**** Bit Manipulation Macros ****/

/* Get the value of the k-th bit in a number */
#define GET_BIT(number, k)      (1 & (number >> k))

/* Set the k-th bit in a number to 1 */
#define SET_BIT(number, k)      (number |= (1 << k))

/* Clear the k-th bit in a number to 0 */
#define CLR_BIT(number, k)      (number &= (~(1 << k)))

/* Toggle the k-th bit in a number */
#define TOGGLE_BIT(number, k)   (number ^= (1 << k))

/* Create a bit mask for the k-th bit */
#define BIT_MASK(k)             (1 << k)

/* Check if the k-th bit is set */
#define IS_BIT_SET(number, k)   (GET_BIT(number, k) == 1)

/* Check if the k-th bit is clear */
#define IS_BIT_CLEAR(number, k) (GET_BIT(number, k) == 0)

#endif /* BIT_MATH_H_ */