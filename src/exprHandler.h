#ifndef __SRC_EXPR_HANDLER_H_
#define __SRC_EXPR_HANDLER_H_


#include "math.h"

#include <vector>
#include <string>


class ExprHandler
{
private:
	double opHandler(double x1, double x2, std::string sign);

	int getSignPriority(std::string sign);

public:
	ExprHandler() {}
	~ExprHandler() {}
	
	
	double exprHandler(std::vector<double> nums, std::vector<std::string> signs);
};


#endif // __SRC_EXPR_HANDLER_H_