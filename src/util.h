
#ifndef INCLUDE_UTILITY_H
#define INCLUDE_UTILITY_H

#define MAX_ITR 1000

typedef struct Point
{
	double x;
	double y;

	double f;
}Point;

void InitialPoint(Point* point, double x, double y);
void printPoint(Point point);

#endif
