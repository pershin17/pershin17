#include <stdio.h>
#include <math.h>

double linear(double x)
{
	return x;
}

double parabola(double x)
{
	return x*x;
}

double cube(double x)
{
	return x*x*x;
}

double MonteCarloIntegration(double(&func)(double), double bottomEdge, double topEdge, int pointCount)
{
	double dx = (topEdge - bottomEdge) / (pointCount - 1);
	double min = bottomEdge;
	double s = 0;
	while (min <= topEdge)
	{
		double y = func(min);
		if(y >= 0)
			s += y;

		min += dx;
	}
	return ((topEdge - bottomEdge) / pointCount)*s;
}

int main()
{
	printf("Expected: ~12.5\tGot: %lf\n", MonteCarloIntegration(linear, -5, 5, 10000));
	return 0;
}
