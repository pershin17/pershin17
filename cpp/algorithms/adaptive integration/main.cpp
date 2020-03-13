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

double RectangleIntegration(double(&func)(double), double bottomEdge, double topEdge, int stepCount)
{
	double dx = (topEdge - bottomEdge) / (double)stepCount;
	double total_area = 0;
	double x = bottomEdge;
	for (int i = 0; i < stepCount; i++)
	{
		total_area += dx * fabs(func(x));
		x += dx;
	}
	return total_area;
}

double AdaptiveIntegration(double (&integration)(double(&func)(double), double, double, int), double(&func)(double), double bottomEdge, double topEdge, double accuracy)
{
	int stepCount = 5;
	double a1, a2;
	
	do
	{
		a1 = integration(func, bottomEdge, topEdge, stepCount);
		a2 = integration(func, bottomEdge, topEdge, stepCount * 2);
		stepCount *= 2;
	} while (accuracy < 2 * fabs(a2 - a1));

	int power = (int)round(1.0 / accuracy);

	return round(a2 * power) / power;
}

int main()
{
	printf("Expected: ~666.667\tGot: %lf\n", AdaptiveIntegration(RectangleIntegration, parabola, -10.0, 10.0, 0.0001));
	printf("Expected: ~666666.7\tGot: %lf\n", AdaptiveIntegration(RectangleIntegration, parabola, -100.0, 100.0, 0.0001));
	printf("Expected: 44.538\tGot: %lf\n", AdaptiveIntegration(RectangleIntegration, parabola, -3.1, 4.7, 0.001));
	printf("Expected: 44.538\tGot: %lf\n", AdaptiveIntegration(RectangleIntegration, parabola, -3.1, 4.7, 0.00001));
	return 0;
}
