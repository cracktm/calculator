#ifndef __SRC_PARSER_MATH_HANDLER_H_
#define __SRC_PARSER_MATH_HANDLER_H_

class ParserMathHandler
{
private:

	int sum(int num1, int num2);
	int sub(int num1, int num2);
	float mul(int num1, int num2);
	float div(int num1, int num2);
	int mod(int num1, int num2);
	int pow(int num1, int num2);



public:
	ParserMathHandler() {}
	~ParserMathHandler() {}
	
	float operation(int num1, int num2, char sign);

};

#endif // __SRC_PARSER_MATH_HANDLER_H_