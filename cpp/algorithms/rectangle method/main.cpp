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


int main()
{
	printf("Expected: ~8.86545\tGot: %lf\n", RectangleIntegration(parabola, 0.0, 3.0, 100));
	printf("Expected: ~1607.61\tGot: %lf\n", RectangleIntegration(cube, 0.0, 9.0, 100));
	printf("Expected: ~242.636\tGot: %lf\n", RectangleIntegration(parabola, 0.0, 9.0, 1000));
	printf("Expected: 18\tGot: %lf\n", RectangleIntegration(parabola, -3.0, 3.0, 1000));
	return 0;
}
