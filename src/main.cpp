#include "parser.h"

int main(void)
{
	Parser parser;

	parser.parse("-25102020 + -(1042021) / 26122021");

	auto nums = parser.getConvetedNumbersVector();
	auto signs = parser.getConvetedSignsVector();

	for (auto i : nums)
		printf_s("<%.2f> ", i);
	printf_s("\n");
	
	for (auto i : signs)
		printf_s("<%c> ", i);
	printf_s("\n");

	return 0;
}