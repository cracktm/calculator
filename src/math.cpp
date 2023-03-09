#include "math.h"


double calc::sum(double a, double b) { return a + b; }

double calc::sub(double a, double b) { return a - b; }


double calc::mul(double a, double b) { return a * b; }

double calc::div(double a, double b) { return a / b; }


int calc::mod(int a, int b) { return a % b; }


double calc::exp(double x, double epsilon) // default accuraty - 10 decimal places
{
	if (x < 0.0) return 1.0 / exp(-x, epsilon);

	double result = 1.0; // x^0 / 0! - first member of the series
	double current = x;  // x^1 / 1! - second
	double n = 2.0; 

	while (current > epsilon)
	{
		result += current;
		current *= x / n++;
	}

	return result;
}

double calc::ln(double x, double epsilon) // x > 0, default accuraty - 10 decimal places
{
	double result = 0.0;
	double currentTerm = 1.0;
	double n = 1.0;

	while (currentTerm > epsilon)
	{
		currentTerm *= (x - 1.0) / x;


		result += currentTerm / n++;
	}

	return result;
}


double calc::pow(double x, int e)
{
	if (e < 0) return 1.0 / pow(x, -e);

	double result = 1.0;
	for (int i = 0; i < e; i++)
		result *= x;

	return result;
}

double calc::pow(double x, double e, double epsilon) // default accuraty - 10 decimal places
{
	if (e == 2.0) return x * x;		// base cases
	if (e == -1.0) return 1.0 / x;	//

	if (x <= 0.0) return pow(x, (int)e);

	return exp(e * ln(x, epsilon), epsilon);
}