#ifndef __SRC_MATH_H_
#define __SRC_MATH_H_



class Math
{
public:
	Math() {}
	~Math() {}


	double sum(double x1, double x2);
	double sub(double x1, double x2);

	double mul(double x1, double x2);
	double div(double x1, double x2);

	int mod(int x1, int x2);

	double exp(double x = 1, double epsilon = 0.00000000001); // default accuraty - 10 decimal places
	double ln(double x, double epsilon = 0.00000000001); // x > 0, default accuraty - 10 decimal places

	double pow(double x, int e);
	double pow(double x, double e, double epsilon = 0.00000000001); // default accuraty - 10 decimal places
};



#endif // __SRC_MATH_H_