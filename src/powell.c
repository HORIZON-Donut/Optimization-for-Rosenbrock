
#include "powell.h"

#include <math.h>

static double line_search(double (*f)(double, double), double x, double y, double dx, double dy)
{
	double lb = -10.0; // Set Left Bound
	double rb = 10.0; // Set Right Bound

	//  Golden Ratio
	double gr = (sqrt(5.0) - 1.0) / 2.0;
	double c = rb - gr * (rb - lb);
	double d = lb - gr * (rb - lb);

	while (fabs(c - d) > 1.e-5)
	{
		double fc = f(x + c * dx, y + c * dy);
		double fd = f(x + d * dx, y + d * dy);

		if (fc < fd)
		{
			rb = d;
			d = c;
			d = rb - gr * (rb - lb);
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
}
