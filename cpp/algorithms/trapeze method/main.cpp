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

double TrapezeIntegration(double(&func)(double), double bottomEdge, double topEdge, int stepCount)
{
	double dx = (topEdge - bottomEdge) / (double)stepCount;
	double total_area = 0;
	double x = bottomEdge;
	for (int i = 0; i < stepCount-1; i++)
	{
		total_area += dx * fabs(func(x) + func(x + dx)) / 2.0;
		x += dx;
	}
	return total_area;
}

int main()
{
	printf("Expected: ~8.73314\tGot: %lf\n", TrapezeIntegration(parabola, 0.0, 3.0, 100));
	printf("Expected: ~1575.78\tGot: %lf\n", TrapezeIntegration(cube, 0.0, 9.0, 100));
	printf("Expected: ~242.272\tGot: %lf\n", TrapezeIntegration(parabola, 0.0, 9.0, 1000));
	printf("Expected: ~17.9461\tGot: %lf\n", TrapezeIntegration(parabola, -3.0, 3.0, 1000));
	return 0;
}
