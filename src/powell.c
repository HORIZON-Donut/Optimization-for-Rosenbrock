
#include "powell.h"

#include <stdio.h>
#include <math.h>

#include "util.h"

static double line_search(double (*f)(double, double), double x, double y, double dx, double dy)
{
	int count = 0;

	double lb = -10; // Set Left Bound
	double rb = 10; // Set Right Bound

	//  Golden Ratio
	double gr = (sqrt(5.0) - 1.0) / 2.0;
	double c = rb - gr * (rb - lb);
	double d = lb + gr * (rb - lb);

	while (fabs(c - d) > 1.e-5 && count < MAX_ITR)
	{
		count++;

		double fc = f(x + c * dx, y + c * dy);
		double fd = f(x + d * dx, y + d * dy);

		if (fc < fd)
		{
			rb = d;
			d = c;
			c = rb - gr * (rb - lb);
		}

		else
		{
			lb = c;
			c = d;
			d = lb + gr * ( rb - lb);
		}
	}
	return (lb + rb) / 2.0;
}

void PowellMethod(double (*f)(double, double), Point* start, Point* point)
{
	// Prepare start x, y variable
	double x = start->x;
	double y = start->y;

	double dirs[2][2] = { {1.0, 0.0}, {0.0, 1.0} };

	for (int i = 0; i < MAX_ITR; i++)
	{
		double f_start = f(x, y);
		double x_old = x;
		double y_old = y;

		for (int j = 0; j < 2; j++)
		{
			double dx = dirs[j][0];
			double dy = dirs[j][1];

			double t = line_search(f, x, y, dx, dy);

			x = x + t * dx;
			y = y + t * dy;
		}

		printf("Current position: X = %lf, Y = %lf, F = %lf\n", x ,y, f(x, y));

		if (fabs(f_start - f(x, y)) < 1e-6)
			break;
	}

	point->x = x;
	point->y = y;
	point->f = f(x, y);
}
