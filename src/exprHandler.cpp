#include "exprHandler.h"




double ExprHandler::opHandler(double a, double b, statement_t sign)
{
	switch(sign)
	{
		case PLUS_SIGN:     return calc::sum(a, b);
		case MINUS_SIGN:    return calc::sub(a, b);
		case MULTIPLY_SIGN: return calc::mul(a, b);
		case DIVIDE_SIGN:   return calc::div(a, b);
		case POW_SIGN:      return calc::pow(a, b);
		case MOD_SIGN:      return (double) calc::mod((int)a, (int)b);
		
		default: return CALC_ERROR;
	}
}




int ExprHandler::getSignPriority(statement_t sign)
{
	switch(sign)
	{
		case PLUS_SIGN:     return P_1;
		case MINUS_SIGN:    return P_1;

		case MULTIPLY_SIGN: return P_2;
		case DIVIDE_SIGN:   return P_2;

		case POW_SIGN:      return P_3;
		case MOD_SIGN:      return P_3;

		default: return P_ERROR;
	}
}





double ExprHandler::exprHandler(std::vector<double> nums, std::vector<statement_t> signs)
{
	if (signs.empty()) return nums.front();


	//finding of minimum priority sign index
	int minPrioritySignIndex = 0;
	for (size_t i = 1; i < signs.size(); i++)
		if (getSignPriority(signs[i]) <= getSignPriority(signs[minPrioritySignIndex])) // "<=" not "<" because there are noncommutative signs
			minPrioritySignIndex = i;



	double leftExpr = exprHandler
	(
		std::vector<double>(nums.begin(), nums.begin() + minPrioritySignIndex + 1), // left side of numbers
		std::vector<statement_t>(signs.begin(), signs.begin() + minPrioritySignIndex) // left side of signs
	);

	// dividing an expression by the minimum priority sign

	double rightExpr = exprHandler
	(
		std::vector<double>(nums.begin() + minPrioritySignIndex + 1, nums.end()), // right side of numbers
		std::vector<statement_t>(signs.begin() + minPrioritySignIndex + 1, signs.end()) // right side of signs
	);


	return opHandler(leftExpr, rightExpr, signs[minPrioritySignIndex]); // minimum priority sign;
}