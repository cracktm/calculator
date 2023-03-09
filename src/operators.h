#ifndef __SRC_OPERATOS_H
#define __SRC_OPERATOS_H

#include <cstdint>

typedef uint8_t statement_t;
typedef uint8_t priority;

enum StatementsID
{
	ERROR_SIGN = 0, 
	PLUS_SIGN, MINUS_SIGN,
	MULT_SIGN, DIV_SIGN, 
	MOD_SIGN, POW_SIGN, 
	SIN_SIGN, ASIN_SIGN,
	COS_SIGN, ACOS_SIGN, 
	TAN_SIGN, ATAN_SIGN, 
	CTG_SIGN, ACTG_SIGN,
	EXP_SIGN, LN_SIGN, 
	LOG_SIGN, SQRT_SIGN, 
	FACTOR_SIGN, RAD_SIGN, 
	DEG_SIGN,
	OP_PARENTHESIS_SIGN,
	CL_PARENTHESIS_SIGN
};

/*	( ͡° ͜ʖ ͡°) 
#define ERROR_SIGN 0 // error

// operators

// binary
#define PLUS_SIGN     1
#define MINUS_SIGN    2
#define MULTIPLY_SIGN 3
#define DIVIDE_SIGN   4
#define MOD_SIGN      5
#define POW_SIGN      6
// unary (functions)
#define SIN_SIGN       16 // 6-16 - place for possible additions
#define ASIN_SIGN      17
#define COS_SIGN       18
#define ACOS_SIGN      19
#define TAN_SIGN       20
#define ATAN_SIGN      21
#define CTG_SIGN       22
#define ACTG_SIGN      23
#define EXP_SIGN       24
#define LN_SIGN        25
#define LOG_SIGN       26
#define SQRT_SIGN      27
#define FACTORIAL_SIGN 28
#define RAD_SIGN       29
#define DEG_SIGN       30
// group
#define OPEN_PARENTHESIS_SIGN  40
#define CLOSE_PARENTHESIS_SIGN 41

// max possible value is 255
// because operators use the uint8_t
*/

#define P_ERROR 0 // error

// priorities

#define P_1 1
#define P_2 2
#define P_3 3
#define P_4 4
#define p_5 5


#endif // __SRC_OPERATOS_H