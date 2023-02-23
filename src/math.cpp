#include "math.h"



double Math::sum(double x1, double x2) { return x1 + x2; }

double Math::sub(double x1, double x2) { return x1 - x2; }


double Math::mul(double x1, double x2) { return x1 * x2; }

double Math::div(double x1, double x2) { return x1 / x2; }


int Math::mod(int x1, int x2) { return x1 % x2; }


double Math::exp(double x, double epsilon) // default accuraty - 10 decimal places
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

double Math::ln(double x, double epsilon) // x > 0, default accuraty - 10 decimal places
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


double Math::pow(double x, int e)
{
	if (e < 0) return 1.0 / pow(x, -e);

	double result = 1.0;
	for (int i = 0; i < e; i++)
		result *= x;

	return result;
}

double Math::pow(double x, double e, double epsilon) // default accuraty - 10 decimal places
{
	if (e == 2.0) return x * x;		// base cases
	if (e == -1.0) return 1.0 / x;	//

	if (x <= 0.0) return pow(x, (int)e);

	return exp(e * ln(x, epsilon), epsilon);
}