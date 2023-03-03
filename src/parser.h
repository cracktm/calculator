#ifndef __parser_h
#define __parser_h

#include <vector>
#include <string>
#include <cstdio>


constexpr bool isOperator(char ch) noexcept;

void _Iltg_LOL(const std::string& lol) noexcept;


class Parser
{
public:
	Parser(void) noexcept = default;

	void parse(const std::string& _src) noexcept;

	std::vector<double> getConvetedNumbersVector(void) const noexcept;
	
	std::vector<char> getConvetedSignsVector(void) const noexcept;

private:
	using cIterator = std::string::const_iterator;

	std::vector<double> numbers;
	std::vector<char> signs;
	std::string expression;

	cIterator checkForNegativeNumber(cIterator it, std::string& target) noexcept;

	cIterator extractNumber(cIterator it, std::string& target) noexcept;

	cIterator extractNumberUntilCloseBracket(cIterator it, std::string& target) noexcept;
};

#endif