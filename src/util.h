
#ifndef INCLUDE_UTILITY_H
#define INCLUDE_UTILITY_H

#define MAX_ITR 1000

typedef struct Point
{
	double x;
	double y;

	double f;
}Point;

typedef struct Vertice
{
	double x;
    double y;
    double z;
}Vertice;

void InitialPoint(Point* point, double x, double y);
void printPoint(Point point);
void sortPoint(Point* point, int num);
void swapPoint(Point* point1, Point* point2);

#endif
