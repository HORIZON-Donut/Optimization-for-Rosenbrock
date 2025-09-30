#include <stdio.h>

#include "util.h"
#include "rosenbrock.h"
#include "powell.h"

// function to test util function
void testEditPointData(Point* point);

int main()
{
	printf("testing point data carrier\n");

	Point point0;
	Point start;
	testEditPointData(&start);
	PowellMethod(Rosenbrock, &start, &point0);
	printPoint(point0);
	
	return 0;
}

void testEditPointData(Point* point)
{
	point->x = 1;
	point->y = 2;

	point->f = 10;
}
