#ifndef __SRC_PARSER_MATH_HANDLER_H_
#define __SRC_PARSER_MATH_HANDLER_H_


#include <vector>
#include <string>

class ParserMathHandler
{
private:

	double sum(double num1, double num2);
	double sub(double num1, double num2);

	double mul(double num1, double num2);
	double div(double num1, double num2);

	int mod(int num1, int num2);
	double pow(double num1, int num2);

	

	int getSignPriority(std::string sign);

public:
	ParserMathHandler() {}
	~ParserMathHandler() {}
	
	double opHandler(double num1, double num2, std::string sign);

	double exprHandler(std::vector<double> nums, std::vector<std::string> signs);
};

#endif // __SRC_PARSER_MATH_HANDLER_H_