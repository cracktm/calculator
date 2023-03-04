#include "exprHandler.h"




double ExprHandler::opHandler(double x1, double x2, std::string sign)
{
	if (sign == "+") return calc::sum(x1, x2);
	if (sign == "-") return calc::sub(x1, x2);
	if (sign == "*") return calc::mul(x1, x2);
	if (sign == "/") return calc::div(x1, x2);
	if (sign == "^") return calc::pow(x1, x2);
	if (sign == "%") return (double) calc::mod((int)x1, (int)x2);
	

	return 0; // default
}




int ExprHandler::getSignPriority(std::string sign)
{
	if (sign == "+") return 1;
	if (sign == "-") return 1;

	if (sign == "*") return 2;
	if (sign == "/") return 2;

	//functions
	if (sign == "^") return 3;
	if (sign == "%") return 3;
	

	return 0; // default
}





double ExprHandler::exprHandler(std::vector<double> nums, std::vector<std::string> signs)
{
	if (signs.empty()) return nums.front();


	//finding of minimum priority sign index
	int minPrioritySignIndex = 0;
	for (int i = 1; i < signs.size(); i++)
		if (getSignPriority(signs[i]) <= getSignPriority(signs[minPrioritySignIndex])) // "<=" not "<" because there are noncommutative signs
			minPrioritySignIndex = i;



	double leftExpr = exprHandler
	(
		std::vector<double>(nums.begin(), nums.begin() + minPrioritySignIndex + 1), // left side of numbers
		std::vector<std::string>(signs.begin(), signs.begin() + minPrioritySignIndex) // left side of signs
	);

	// dividing an expression by the minimum priority sign

	double rightExpr = exprHandler
	(
		std::vector<double>(nums.begin() + minPrioritySignIndex + 1, nums.end()), // right side of numbers
		std::vector<std::string>(signs.begin() + minPrioritySignIndex + 1, signs.end()) // right side of signs
	);


	return opHandler(leftExpr, rightExpr, signs[minPrioritySignIndex]); // minimum priority sign;
}