#ifndef __parser_hpp
#define __parser_hpp

#include <string_view>
#include <string>
#include <sstream>
#include <stack>
#include <any>


std::any popFromStack(std::stack<std::any>& target)
{
	std::any tmp = target.top();
	target.pop();

	return tmp;
}


class Parser
{
public:
	Parser(std::string& expression);

	int64_t parse(void);

	int64_t doPriorityOp(char op);

	// int64_t doOperationInBrackets();


private:
	//std::stack<int64_t> stackOfNumbers;
	//std::stack<char> stackOfOperations;
	std::stack<std::any> commonStack;

	void calculate(int64_t& accumulator);

	std::stringstream sourceExpr;

};

#endif