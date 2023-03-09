#include "exprHandler.h"
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

	std::vector<double> other_nums = {6, 8, 10, 5, 3.14, 0.01, 12};
	std::vector<statement_t> other_signs = {PLUS_SIGN, DIVIDE_SIGN, MINUS_SIGN, POW_SIGN, MULTIPLY_SIGN, PLUS_SIGN};

	std::cout.precision(17);
	std::cout << "answer: " << math.exprHandler(other_nums, other_signs);


	return 0;
}