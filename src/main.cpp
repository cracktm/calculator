#include <iostream>
#include "ParserMathHandler.h"

int main() {
	ParserMathHandler math = ParserMathHandler();

	std::cout << "answer: " << math.operation(1, 1, '+');

	return 0;
}