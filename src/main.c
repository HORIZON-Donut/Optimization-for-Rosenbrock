#include <stdio.h>

#include "util.h"
#include "rosenbrock.h"
#include "powell.h"

// function use to implement Powell Method
void PowellMethodImp(Point* points, int num);

int main()
{
	// Initial starting point
	Point point1;
	Point point2;
	Point point3;
	Point point4;

	// Set starting point
	InitialPoint(&point1, 2, 2);
	InitialPoint(&point2, 2, -2);
	InitialPoint(&point3, -2, 1);
	InitialPoint(&point4, 2, 1);

	// Set point array for easy access
	Point points[4] = {point1, point2, point3, point4};

	PowellMethodImp(points, 4);
	
	return 0;
}

void PowellMethodImp(Point* points, int num)
{
	Point result;

	for (int i = 0; i < num; i++)
	{
		PowellMethod(Rosenbrock, &points[i], &result);

		printf("Point %d:\n", i + 1);
		printf("Start point: x = %lf, y = %lf\n", points[i].x, points[i].y);
		printf("Final position:\n");
		printPoint(result);
	}
}
