
#ifndef INCLUDE_NELDER_MEAN_H
#define INCLUDE_NELDER_MEAN_H

#include "util.h"

void NelderMeanMethod(double (*f)(double, double), Point* start, Point* result);

#endif
