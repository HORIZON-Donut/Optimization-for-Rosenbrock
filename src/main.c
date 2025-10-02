#include <stdio.h>

#include "util.h"
#include "rosenbrock.h"
#include "powell.h"
#include "nelder.h"
#include "genetic.h"

// function use to implement Powell Method
void PowellMethodImp(Point* points, int num);

// function use to implement Nelder mean Method
void NelderMethodImp(Point* points, int num);

// function use to implement Genertic Algorithm
void GeneticAlgo(Point* points, int num);

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

	printf("Powell method\n");
	PowellMethodImp(points, 4);

	printf("Nelder mean methos\n");
	NelderMethodImp(points, 4);

	printf("Genertic algorithm methos\n");
	GeneticAlgo(points, 4);

	return 0;
}

void GeneticAlgo(Point* points, int num)
{
	unsigned int itr = 0;
	double time;
	Point result;

	for (int i = 0; i < num; i++)
	{
		itr = 0;
		timetosolve(GeneticAlgorithm, &points[i], &result, &itr, &time);

		printf("Point %d:\n", i + 1);
		printf("Start point: x = %lf, y = %lf\n", points[i].x, points[i].y);
		printf("Iteration used to compute: %d\n", itr);
		printf("Time use to solve: %lf second\n", time);
		printf("Final position:\n");
		printPoint(result);
	}
}

void NelderMethodImp(Point* points, int num)
{
	unsigned int itr = 0;
	double time;
	Point result;

	for (int i = 0; i < num; i++)
	{
		itr = 0;
		timetosolve(NelderMeanMethod, &points[i], &result, &itr, &time);

		printf("Point %d:\n", i + 1);
		printf("Start point: x = %lf, y = %lf\n", points[i].x, points[i].y);
		printf("Iteration used to compute: %d\n", itr);
		printf("Time use to solve: %lf second\n", time);
		printf("Final position:\n");
		printPoint(result);
	}
}

void PowellMethodImp(Point* points, int num)
{
	unsigned int itr = 0;
	double time;
	Point result;

	for (int i = 0; i < num; i++)
	{
		itr = 0;
		timetosolve(PowellMethod, &points[i], &result, &itr, &time);

		printf("Point %d:\n", i + 1);
		printf("Start point: x = %lf, y = %lf\n", points[i].x, points[i].y);
		printf("Iteration used to compute: %d\n", itr);
		printf("Time use to solve: %lf second\n", time);
		printf("Final position:\n");
		printPoint(result);
	}
}
