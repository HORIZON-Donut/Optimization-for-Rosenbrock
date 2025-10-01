
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

void sortPoint(Point* point, int num)
{
	int i = 0;
	int swap = 0;

	while (swap == 0)
	{
		swap = 1;
		for(i = 0; i < num - 1; i++)
		{
			if (point[i].f > point[i+1].f)
			{
				swapPoint(&point[i], &point[i+1]);
				swap = 0;
			}
		}
	}
}

void swapPoint(Point* point1, Point* point2)
{
	Point tmp = *point1;
	*point1 = *point2;
	*point2 = tmp;
}

