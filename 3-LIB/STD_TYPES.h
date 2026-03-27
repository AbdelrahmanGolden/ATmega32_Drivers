#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/** Unsigned **/
typedef unsigned char       u8;
typedef unsigned short int  u16;
typedef unsigned long int   u32;

/** Signed **/
typedef signed char         s8;
typedef signed short int    s16;
typedef signed long int     s32;

/** Float **/
typedef float               f32;
typedef double              f64;
typedef long double         f128;

/** Boolean **/
typedef enum
{
	FALSE = 0,
	TRUE  = 1
} boolean;

/** Common Macros **/
#define NULL                ((void*)0)
#define OK                  0
#define NOT_OK              1
#define NOK                 1
#define NULL_POINTER        2  /* Used to indicate a NULL pointer error */


#endif /* STD_TYPES_H_ */