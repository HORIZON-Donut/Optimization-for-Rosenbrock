#include <stdio.h>

#include "util.h"
#include "rosenbrock.h"
#include "powell.h"

// function to test util function
void testEditPointData(Point* point);

// function use to implement Powell Method
void PowellMethodImp(Point* point, int num);

int main()
{
	// Initial starting point
	Point point0;
	Point start;

	testEditPointData(&start);
	PowellMethod(Rosenbrock, &start, &point0);
	printPoint(point0);
	
	return 0;
}

void PowellMethodImp(Point* point, int num)
{
	for (int i = 0; i < num; i++)
	{
	}
}

void testEditPointData(Point* point)
{
	point->x = 1;
	point->y = 2;

	point->f = 10;
}
