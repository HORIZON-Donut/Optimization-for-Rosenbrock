#include <stdio.h>

#include "rosenbrock.h"

void RosenbrockFirstCase();
void RosenbrockSecondCase();
void RosenbrockThirdCase();

int main()
{
	printf("Static Rosenbrock Test\n");


	RosenbrockFirstCase();
	RosenbrockSecondCase();
	RosenbrockThirdCase();
	
	return 0;
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
