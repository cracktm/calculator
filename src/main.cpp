#include "parser.h"
#include "exprHandler.h"

#include <iostream>
#include <vector>
#include <string>



int main(void)
{
	std::cout << "parser example:\n";
	// parser usage example
	Parser parser;

	parser.parse("-25102020 + -(1042021) / 26122021");

	auto nums = parser.getConvertedNumbersVector();
	auto signs = parser.getConvertedSignsVector();

	for (auto i : nums)
		printf_s("<%.2f> ", i);
	printf_s("\n");
	
	for (auto i : signs)
		printf_s("<%c> ", i);
	printf_s("\n");


	std::cout << '\n'; // sep


	std::cout << "expr handler example:\n";
	// expr handler usage example
	ExprHandler math;

	std::vector<double> other_nums = {6, 8, 10, 5, 3.14, 0.01, 12};
	std::vector<std::string> other_signs = {"+", "/", "-", "^", "*", "+"};

	std::cout.precision(17);
	std::cout << "answer: " << math.exprHandler(other_nums, other_signs);


	return 0;
}