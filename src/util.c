
#include "util.h"

#include <stdio.h>

static int isSorted(Point* point, int num)
{
	double buffer = 0;

	for(int i = 0; i < num; i++)
	{
		if(point[i].f >= buffer){
			buffer = point[i].f;
			continue;
		}

		return 1;
	}

	return 0;
}
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

void sortPoint(Point* point, int num)
{
	//
}

void swapPoint(Point* point1, Point* point2)
{
	Point* tmp = point1;
	point1 = point2;
	point2 = tmp;
}

