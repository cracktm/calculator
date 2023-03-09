#include "parser.h"


void Parser::parse(const std::string& src) noexcept
{
	expression = src;
	auto exprEnd = std::cend(expression);

	for (auto ch = expression.cbegin(); ch != exprEnd; ch++)
	{
		std::string extractTarget;	// using for extract digits, functions or constants

		if (std::isspace(*ch))
			continue;

		if (std::isdigit(*ch))
		{
			ch = extractUntil(ch, exprEnd, extractTarget, [](char sym)
				{
					return (!std::isdigit(sym) && sym != '.') ? false : true;
				});

			(isPreviousSymbolIs(ch, '-')) ? numbers.push_back(std::stod(extractTarget) * -1) : numbers.push_back(std::stod(extractTarget));
			continue;
		}
	

		if (std::isalpha(*ch))
		{
			ch = extractUntil(ch, exprEnd, extractTarget, [](char sym)
				{
					return (!isalpha(sym)) ? false : true;
				});

			(isItConstante(extractTarget)) ? (numbers.push_back(getConstValue(extractTarget))) : (operations.push_back(convertToStatementID(extractTarget)));
			continue;
		}

		// as default (operators)
		operations.push_back(convertToStatementID(&(*ch)));
	}
}


void Parser::clear(void) noexcept
{
	numbers.clear();
	operations.clear();
	expression.clear();
}


std::vector<double> Parser::digits(void) const noexcept
{
	return numbers;
}


std::vector<statement_t> Parser::statements(void) const noexcept
{
	return operations;
}


bool Parser::isPreviousSymbolIs(std::string::const_iterator it, char ch) noexcept
{
	return (it != std::begin(expression) && (*(--it) == ch));
}


statement_t Parser::convertToStatementID(const std::string& rawStatement) const noexcept
{
	// FIX THIS SHT

	switch (rawStatement.at(0))
	{
		case '+':
			return 1;
		case '-':
			return 2;
		case '*':
			return 3;
		case '/':
			return 4;
		case '%':
			return 5;
		case '^':
			return 6;
		case '(':
			return 7;
		case ')':
			return 8;
	}

	if (rawStatement == "sin")
		return 9;
	else if (rawStatement == "cos")
		return 10;
	else if (rawStatement == "tan")
		return 11;
	else if (rawStatement == "cot")
		return 12;
	else if (rawStatement == "asin")
		return 13;
	else if (rawStatement == "acos")
		return 14;
	else if (rawStatement == "atan")
		return 15;
	else	// acot
		return 16;

}
