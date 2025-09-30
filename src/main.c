#include <stdio.h>

#include "util.h"
#include "rosenbrock.h"

void RosenbrockFirstCase();
void RosenbrockSecondCase();
void RosenbrockThirdCase();

void testEditPointData(Point point);

int main()
{
	printf("Static Rosenbrock Test\n");


	RosenbrockFirstCase();
	RosenbrockSecondCase();
	RosenbrockThirdCase();

	printf("testing point data carrier\n");

	Point point0;

	testEditPointData(point0);
	
	return 0;
}

void testEditPointData(Point point)
{
}

void RosenbrockFirstCase()
{
	printf("Rosenbrock test case 1: x = 1, y =1\n");
	printf("Result = %lf\n", Rosenbrock(1, 1));
}
void RosenbrockSecondCase()
{
	printf("Rosenbrock test case 2: x = 2, y =2\n");
	printf("Result = %lf\n", Rosenbrock(2, 2));
}
void RosenbrockThirdCase()
{
	printf("Rosenbrock test case 3: x = 3, y =3\n");
	printf("Result = %lf\n", Rosenbrock(3, 3));
}
