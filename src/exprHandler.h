#ifndef __SRC_EXPR_HANDLER_H_
#define __SRC_EXPR_HANDLER_H_


#include "math.h"
#include "operators.h"

#include <vector>


class ExprHandler
{
private:
	double opHandler(double a, double b, Sign sign);

	int getSignPriority(Sign sign);

public:
	ExprHandler() {}
	~ExprHandler() {}
	
	
	double exprHandler(std::vector<double> nums, std::vector<Sign> signs);
};


#endif // __SRC_EXPR_HANDLER_H_