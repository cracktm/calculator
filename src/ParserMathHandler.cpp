#include "ParserMathHandler.h"





double ParserMathHandler::sum(double num1, double num2) { return num1 + num2; }

double ParserMathHandler::sub(double num1, double num2) { return num1 - num2; }





double ParserMathHandler::mul(double num1, double num2) { return num1 * num2; }

double ParserMathHandler::div(double num1, double num2) { return num1 / num2; }





int ParserMathHandler::mod(int num1, int num2) { return num1 % num2; }





double ParserMathHandler::pow(double num1, int num2)
{
	if (num2 == 2.0) return num1 * num1;
	if (num2 == -1.0) return 1.0 / num1;
	if (num2 < 0) return 1.0 / pow(num1, -num2);


	double result = 1.0;
	for (int i = 0; i < num2; i++)
		result *= num1;


	return result;
}












double ParserMathHandler::opHandler(double num1, double num2, std::string sign)
{
	if (sign == "+") return sum(num1, num2);
	if (sign == "-") return sub(num1, num2);
	if (sign == "*") return mul(num1, num2);
	if (sign == "/") return div(num1, num2);
	if (sign == "%") return (double) mod((int)num1, (int)num2);
	if (sign == "^") return pow(num1, (int)num2);

	return 0; // default
}





int ParserMathHandler::getSignPriority(std::string sign)
{
	if (sign == "+") return 1;
	if (sign == "-") return 1;

	if (sign == "*") return 2;
	if (sign == "/") return 2;

	if (sign == "%") return 3;
	if (sign == "^") return 3;

	return 0; // default
}




double ParserMathHandler::exprHandler(std::vector<double> nums, std::vector<std::string> signs)
{
	if (signs.empty()) return nums.front();


	int minPrioritySignIndex = 0;
	for (int i = 1; i < signs.size(); i++)												//finding of minimum priority sign index
		if (getSignPriority(signs[i]) < getSignPriority(signs[minPrioritySignIndex]))
			minPrioritySignIndex = i;



	return opHandler(
		exprHandler(
			std::vector<double>(nums.begin(), nums.begin() + minPrioritySignIndex + 1), 			// left side of numbers	|
																									// 						| left side of expression
			std::vector<std::string>(signs.begin(), signs.begin() + minPrioritySignIndex)			// left side of signs	|
		),

																									// dividing an expression by the minimum priority sign

		exprHandler(
			std::vector<double>(nums.begin() + minPrioritySignIndex + 1, nums.end()),				// right side of numbers |
																									// 						 | right side of expression
			std::vector<std::string>(signs.begin() + minPrioritySignIndex + 1, signs.end())			// right side of signs	 |
		),

		signs[minPrioritySignIndex] 																// minimum priority sign
	);
}