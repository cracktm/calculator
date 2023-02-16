#include "parser.hpp"


Parser::Parser(std::string& expression)
{
	std::reverse(expression.begin(), expression.end());

	sourceExpr << expression;	
}


int64_t Parser::parse(void)
{
	for (size_t i = 0; !(sourceExpr.eof()); i++)
	{
		char ch = sourceExpr.get();

		switch (ch)
		{
		case ' ': 
		case '\t':
			continue;

		case '0': case '1':
		case '2': case '3':
		case '4': case '5':
		case '6': case '7':
		case '8': case '9':
			stackOfNumbers.push(atoi(&ch));

		case '+': 
		case '-':
			stackOfOperations.push(ch);

		case '*': case '/':
		case '%': case '^':
			stackOfNumbers.push(doPriorityOp(ch));

		case '(':
		{
			int64_t bracketsResult = parse();
		}

		}
	}

	int64_t result = 0;
	for (size_t i = 1; !(commonStack.empty()); i++)
		calculate(result);
}


int64_t Parser::doPriorityOp(char op)
{
	int64_t previousOperand = stackOfNumbers.top();
	

	stackOfNumbers.pop();
	

}


void Parser::calculate(int64_t& accumulator)
{
	char op = std::any_cast<char>(popFromStack(commonStack));
	int64_t secondOperand = std::any_cast<int64_t>(popFromStack(commonStack));

	switch (op)
	{
	case '+':
		accumulator += secondOperand;
		break;

	case '-':
		accumulator -= secondOperand;
		break;
	}
}