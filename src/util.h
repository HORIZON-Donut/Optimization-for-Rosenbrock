
#ifndef INCLUDE_UTILITY_H
#define INCLUDE_UTILITY_H

#define MAX_ITR 0xFFFF
#define EPS_F 1e-10
#define EPS_X 1e-8

typedef struct Point
{
	double x;
	double y;

	double f;
}Point;

void InitialPoint(Point* point, double x, double y);
void printPoint(Point point);
void sortPoint(Point* point, int num);
void swapPoint(Point* point1, Point* point2);

#endif
