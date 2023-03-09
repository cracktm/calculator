#ifndef __parser_h
#define __parser_h

#include <vector>
#include <string>
#include <cstdio>
#include "../operators.h"
#include "parsing_cases.h"


class Parser
{
public:
	Parser(void) noexcept = default;

	void parse(const std::string& src) noexcept;

	void clear(void) noexcept;

	std::vector<double> digits(void) const noexcept;
	
	std::vector<statement_t> statements(void) const noexcept;

	friend void showResults(Parser&, size_t);	// -> FOR DEBUG; REMOVE THIS IN LATEST VERSIONS <-

private:
	std::vector<double> numbers;
	std::vector<statement_t> operations;
	std::string expression;

	bool isPreviousSymbolIs(std::string::const_iterator it, char ch) noexcept;

	statement_t convertToStatementID(const std::string& rawStatement) const noexcept;
};

#endif