
#include "powell.h"

#include "rosenbrock.h"

static double line_search(double (*f)(double, double), double x, double y)
{
	return f(x, y);
}

void PowellMethod(Point* point)
{
	point->f = line_search(Rosenbrock, point->x, point->y);
}
