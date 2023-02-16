#include "ParserMathHandler.h"






int ParserMathHandler::sum(int num1, int num2)
{
	return num1 + num2;
}

int ParserMathHandler::sub(int num1, int num2)
{
	return num1 - num2;
}





float ParserMathHandler::mul(int num1, int num2)
{
	return (float)num1 * (float)num2;
}

float ParserMathHandler::div(int num1, int num2)
{
	return (float)num1 / (float)num2;
}





int ParserMathHandler::mod(int num1, int num2)
{
	return num1 % num2;
}

int ParserMathHandler::pow(int num1, int num2)
{
	if (num2 == 2.0) return num1 * num1;
	if (num2 == -1.0) return 1.0 / num1;
	if (num2 < 0) return 1.0 / ParserMathHandler::pow(num1, -num2);


	float result = 1.0;
	for (int i = 0; i < num2; i++)
		result *= num1;


	return result;
}












float ParserMathHandler::operation(int num1, int num2, char sign)
{
	if (sign == '+') return (float) ParserMathHandler::sum(num1, num2);
	if (sign == '-') return (float)	ParserMathHandler::sub(num1, num2);
	if (sign == '*') return 		ParserMathHandler::mul(num1, num2);
	if (sign == '/') return 		ParserMathHandler::div(num1, num2);
	if (sign == '%') return (float) ParserMathHandler::mod(num1, num2);
	if (sign == '^') return (float) ParserMathHandler::pow(num1, num2);

	return 0; // default
}