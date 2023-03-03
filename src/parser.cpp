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
		printf("VICH'KA\n");
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
			if (iter != ch)
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

		ch = extractNumber(ch, num);		
		numbers.push_back(std::stod(num));
	}
}


std::vector<double> Parser::getConvetedNumbersVector(void) const noexcept
{
	return numbers;
}


std::vector<char> Parser::getConvetedSignsVector(void) const noexcept
{
	return signs;
}


Parser::cIterator Parser::checkForNegativeNumber(cIterator it, std::string& target) noexcept
{
	// <it + N> - jump on N symbols, beginning from minus
	if (*(it + 1) == '(' || std::isdigit(*(it + 1)))
	{
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
		if (!std::isdigit(*it) && *it != '.')
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
	auto itCopy = it - 2;	// making a copy of iterator (beggining from minus) 
						    // on case if expr. inside brackets not is single-standing digit

	for (it; *it != ')'; it++)
	{
		if (!std::isdigit(*it) && *it != '.')	// brackets-in expression is not single-standing digit (f.e. (13 - 42))
			return itCopy;
		target.push_back(*it);
	}

	_Iltg_LOL(target);

	return it;
}