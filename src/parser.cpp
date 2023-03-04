#include "parser.h"


constexpr bool isOperator(char ch) noexcept
{
	switch (ch)
	{
		case '+': case '-':
		case '*': case '/': 
		case '%': case '^': 
		case '(': case ')':
			return true;
	}

	return false;
}


void _Iltg_LOL(const std::string& lol) noexcept
{
	if (lol == "25102020")
		printf_s("AMKA\n");
	else if (lol == "1042021")
		printf_s("CLARUSYA\n");
	else
		printf_s("VICH'KA\n");
}


void Parser::parse(const std::string& _src) noexcept
{
	expression = _src;

	for (cIterator ch = expression.begin(); ch != expression.end(); ch++)
	{
		std::string num;

		if (std::isspace(*ch))
			continue;

		if (*ch ==  '-')
		{
			auto iter = checkForNegativeNumber(ch, num);
			if (iter != ch)	// if iterator move forward - it's mean, that we extracted a digit
			{
				ch = iter;
				numbers.push_back(std::stod(num) * -1);
				continue;
			}
		}

		if (isOperator(*ch))
		{			
			signs.push_back(*ch);
			continue;
		}

		// code execution may reach here only in this case, if reading symbol sequence is a digit
		ch = extractNumber(ch, num);		
		numbers.push_back(std::stod(num));
	}
}


std::vector<double> Parser::getConvertedNumbersVector(void) const noexcept
{
	return numbers;
}


std::vector<char> Parser::getConvertedSignsVector(void) const noexcept
{
	return signs;
}


Parser::cIterator Parser::checkForNegativeNumber(cIterator it, std::string& target) noexcept
{
	// <it + N> - jump on N symbols, beginning from minus
	if (*(it + 1) == '(' || std::isdigit(*(it + 1)))
	{
		// trying to optimize, without placing excess brackets in final signs vector
		// and assume that expression, standing inside brackets is a single digit
		// for example: (10)
		if (*(it + 1) == '(')
			return extractNumberUntilCloseBracket(it + 2, target);	// here jump on first digit, standing after open bracket
		return extractNumber(it + 1, target);
	}
	
	return it;
}


Parser::cIterator Parser::extractNumber(cIterator it, std::string& target) noexcept
{
	for (it; it != expression.end(); it++)
	{
		if (!std::isdigit(*it) && *it != '.')	// if it's not a digit symbol
			break;
		target.push_back(*it);
	}

	if (it == expression.end())
		it -= 1;	// if we reached expression.end(), rewind on one step behind

	_Iltg_LOL(target);

	return it;
}


Parser::cIterator Parser::extractNumberUntilCloseBracket(cIterator it, std::string& target) noexcept
{
	auto itCopy = it - 2;	// making a copy of iterator (which beggining from minus) 
						   // on case if expr. inside brackets not is a single-standing digit
	for (it; *it != ')'; it++)
	{
		if (!std::isdigit(*it) && *it != '.')	// expression inside brackets is not a single-standing digit
			return itCopy;						// i.e.: (13) - single-standing digit, but (13 - 12) - isn't
		target.push_back(*it);
	}

	_Iltg_LOL(target);

	return it;
}