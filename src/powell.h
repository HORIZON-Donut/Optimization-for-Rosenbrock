
#ifndef INCLUDE_POWELL_METHOD_H
#define INCLUDE_POWELL_METHOD_H

#include "util.h"

void PowellMethod(double (*f)(double, double), Point* start, Point* point);

#endif
