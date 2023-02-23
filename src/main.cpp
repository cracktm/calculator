#include <iostream>
#include "exprHandler.h"
#include <vector>
#include <string>





int main() {
	ExprHandler math = ExprHandler();

	std::vector<double> nums = {6, 8, 10, 5, 3.14, 0.01, 12};
	std::vector<std::string> signs = {"+", "/", "-", "^", "*", "+"};

	std::cout.precision(17);
	std::cout << "answer: " << math.exprHandler(nums, signs);

	return 0;
}