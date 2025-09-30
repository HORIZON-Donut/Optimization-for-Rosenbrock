
#include "util.h"

#include <stdio.h>

void printPoint(Point point)
{
	printf("----------\nX = %lf\nY = %lf\nF = %lf\n----------\n", point.x, point.y, point.f);
}

void InitialPoint(Point* point, double x, double y)
{
	point->x = x;
	point->y = y;

	point->f = 0;
}

void norm(Point point, Point* target)
{
	double norm = sqrt((point.x * point.x) + (point.y * point.y));
	if (norm == 0) setPoint(target, 1, 1, 0);

	setPoint(target, point.x/norm, point.y/norm);
}

