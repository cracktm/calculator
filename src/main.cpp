#include <iostream>
#include "ParserMathHandler.h"
#include <vector>
#include <string>








int main() {
	ParserMathHandler math = ParserMathHandler();

	std::vector<double> nums = {6, 8, 10, 5};
	std::vector<std::string> signs = {"+", "/", "-"};

	std::cout << "answer: " << math.exprHandler(nums, signs);

	return 0;
}