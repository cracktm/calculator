#include "parser/parser.h"
// #include "my_cuties/cuties.h"

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
	Parser parser;

	parser.parse("cot(PI / 2) - (-(+(-(2)))");
	showResults(parser, 1);

	return 0;
}