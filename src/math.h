#ifndef __SRC_MATH_H_
#define __SRC_MATH_H_

// Constants rounded for 21 decimals
#define M_E  2.71828182845904523536
#define M_PI 3.14159265358979323846

#define CALC_ERROR 0

namespace calc
{
	

	double sum(double a, double b);
	double sub(double a, double b);

	double mul(double a, double b);
	double div(double a, double b);

	int mod(int a, int b);

	double exp(double x = 1, double epsilon = 0.00000000001); // default accuraty - 10 decimal places
	double ln(double x, double epsilon = 0.00000000001); // x > 0, default accuraty - 10 decimal places

	double pow(double x, int e);
	double pow(double x, double e, double epsilon = 0.00000000001); // default accuraty - 10 decimal places
}


#endif // __SRC_MATH_H_