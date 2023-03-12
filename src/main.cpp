#include "exprHandler/exprHandler.h"
#include "operators.h"
#include "parser/parser.h"
#include <iostream>
#include <vector>
#include <string>


// FOR DEBUG
void showResults(Parser& parser, size_t TestNo)
{
	printf_s("[TEST %llu]: <%s>\n\n", TestNo, parser.expression.c_str());

	auto nums = parser.digits();
	auto signs = parser.statements();

	for (auto i : nums)
		printf_s("<%.2f> ", i);
	printf_s("\n");

	for (auto i : signs)
		printf_s("<%u> ", i);
	printf_s("\n");

	parser.clear();
}



int main(void)
{
	// parser usage example
	std::cout << "parser example:\n";
	Parser parser;

	parser.parse("cot(PI / 2) - (-(+(-(2)))");
	showResults(parser, 1);

	auto nums = parser.digits();
	auto signs = parser.statements();

	for (auto i : nums)
		printf_s("<%.2f> ", i);
	printf_s("\n");
	
	for (auto i : signs)
		printf_s("<%u> ", i);
	printf_s("\n");

	// std::cout << '\n'; // sep

	// expr handler usage example
	std::cout << "expr handler example:\n";
	ExprHandler math;

	std::vector<double> other_nums = {6, 8, 10, 5, 3.14, 0.01, 10, 12, 0};
	std::vector<statement_t> other_signs = {
		PLUS_SIGN, DIV_SIGN, MINUS_SIGN, POW_SIGN, MULT_SIGN,
		MINUS_SIGN, LN_SIGN, PLUS_SIGN, PLUS_SIGN, EXP_SIGN
	};

	std::cout.precision(17);
	std::cout << "6 + 8 / 10 - 5 ^ 3.14 * 0.01 - ln10 + 12 + exp0" << " = " << math.exprHandler(other_nums, other_signs) << '\n';


	return 0;
}