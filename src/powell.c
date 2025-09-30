
#include "powell.h"

#include <math.h>
#include "rosenbrock.h"

static double line_search(double (*f)(double, double), double x, double y, double dx, double dy)
{
	double lb = -10.0; // Set Left Bound
	double rb = 10.0; // Set Right Bound

	//  Golden Ratio
	double gr = (sqrt(5.0) - 1.0) / 2.0;
	double c = rb - gr * (rb - lb);
	double d = lb - gr * (rb - lb);
	return f(x, y);
}

void PowellMethod(Point* point)
{
	point->f = line_search(Rosenbrock, point->x, point->y);
}
