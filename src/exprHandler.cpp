#include "exprHandler.h"




double ExprHandler::binaryOpHandler(double a, double b, statement_t sign)
{
	switch(sign)
	{
		case PLUS_SIGN:  return calc::sum(a, b);
		case MINUS_SIGN: return calc::sub(a, b);
		case MULT_SIGN:  return calc::mul(a, b);
		case DIV_SIGN:   return calc::div(a, b);
		case POW_SIGN:   return calc::pow(a, b);
		case MOD_SIGN:   return (double) calc::mod((int)a, (int)b);
		
		default: return CALC_ERROR;
	}
}

double ExprHandler::unaryOpHandler(double x, statement_t sign)
{
	switch(sign)
	{
		case EXP_SIGN: return calc::exp(x);
		case LN_SIGN:  return calc::ln(x);
		// other features will be added

		default: return CALC_ERROR;
	}
}




int ExprHandler::getSignPriority(statement_t sign)
{
	switch(sign)
	{
		// binary
		case PLUS_SIGN: case MINUS_SIGN: return P_1;

		case MULT_SIGN: case DIV_SIGN:   return P_2;

		case POW_SIGN:  case MOD_SIGN:   return P_3;

		// unary (functions)
		case EXP_SIGN:
		case LN_SIGN:
		return P_4;

		default: return P_ERROR;
	}
}




bool ExprHandler::isUnaryOp(statement_t sign)
{
	switch(sign)
	{
		case SIN_SIGN: case ASIN_SIGN:
		case COS_SIGN: case ACOS_SIGN:
		case TAN_SIGN: case ATAN_SIGN:
		case CTG_SIGN: case ACTG_SIGN:
		case EXP_SIGN:
		case LN_SIGN:
		case LOG_SIGN:
		case SQRT_SIGN:
		case FACTOR_SIGN:
		case RAD_SIGN:
		case DEG_SIGN:
		return true;

		default: return false;
	}
}



double ExprHandler::exprHandler(std::vector<double> nums, std::vector<statement_t> signs)
{
	if (signs.empty()) return nums.front();

	// unary operators have higher priority and stay at the very end
	// so they can be handled like this
	if (nums.size() == 1 && signs.size() == 1) return unaryOpHandler(nums.front(), signs.front());


	// finding of minimum priority sign index
	int signsSep = 0;
	int numsSep = 0;

	for (size_t i = 1, bias = 0; i < signs.size(); i++)
	{
		if (isUnaryOp(signs[i])) bias++;

		if (getSignPriority(signs[i]) <= getSignPriority(signs[signsSep])) // "<=" not "<" because there are noncommutative signs
		{
			signsSep = i;
			numsSep = signsSep - bias;
		}
	}
		



	double leftExpr = exprHandler
	(
		std::vector<double>(nums.begin(), nums.begin() + numsSep + 1), // left side of numbers
		std::vector<statement_t>(signs.begin(), signs.begin() + signsSep) // left side of signs
	);

	// dividing an expression by the minimum priority sign

	double rightExpr = exprHandler
	(
		std::vector<double>(nums.begin() + numsSep + 1, nums.end()), // right side of numbers
		std::vector<statement_t>(signs.begin() + signsSep + 1, signs.end()) // right side of signs
	);


	return binaryOpHandler(leftExpr, rightExpr, signs[signsSep]); // minimum priority sign;
}