
#include "powell.h"

static double line_search(double (*f)(double, double), double x, double y)
{
	return f(x, y);
}
