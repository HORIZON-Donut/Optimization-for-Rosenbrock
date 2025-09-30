
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

def dual_sort(key, data):
    """Sort `data` based on values in `key` (bubble sort style)."""
    n = len(key)
    swap = True

    while swap:
        swap = False
        for i in range(n - 1):
            if key[i] > key[i+1]:
                key[i], key[i+1] = key[i+1], key[i]
                data[i], data[i+1] = data[i+1], data[i]
                swap = True
    return data, key
