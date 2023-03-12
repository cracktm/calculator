#ifndef __SRC_EXPR_HANDLER_H_
#define __SRC_EXPR_HANDLER_H_


#include "math.h"
#include "../operators.h"

#include <vector>


class ExprHandler
{
private:
	double binaryOpHandler(double a, double b, statement_t sign);
	double unaryOpHandler(double x, statement_t sign);

	int getSignPriority(statement_t sign);
	bool isUnaryOp(statement_t sign);


public:
	ExprHandler() {}
	~ExprHandler() {}
	
	
	double exprHandler(std::vector<double> nums, std::vector<statement_t> signs);
};


#endif // __SRC_EXPR_HANDLER_H_