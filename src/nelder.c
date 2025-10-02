
#include "nelder.h"

#include <stdio.h>
#include <math.h>

#include "util.h"
#include "rosenbrock.h"

#define EPS_F 1e-10
#define EPS_X 1e-8

#define ALPHA 1.0
#define GAMMA 2.0
#define RHO 0.5
#define SIGMA 0.5

// reflection step function
static void reflection(Point xc, Point xw, Point* xr)
{
	xr->x = xc.x + ALPHA * (xc.x - xw.x);
	xr->y = xc.y + ALPHA * (xc.y - xw.y);
	xr->f = Rosenbrock(xr->x, xr->y);
}

// expansion step function
static void expansion(Point xc, Point xr, Point* xe)
{
	xe->x = xc.x + GAMMA * (xc.x - xr.x);
	xe->y = xc.y + GAMMA * (xc.y - xr.y);
	xe->f = Rosenbrock(xe->x, xe->y);
}

// outside contraction step function
static void outcont(Point xc, Point xr, Point* xoc)
{
	xoc->x = xc.x + RHO * (xr.x - xc.x);
	xoc->y = xc.y + RHO * (xr.y - xc.y);
	xoc->f = Rosenbrock(xoc->x, xoc->y);
}

// inside contraction step function
static void inscont(Point xc, Point xw, Point* xic)
{
	xic->x = xc.x - RHO * (xc.x - xw.x);
	xic->y = xc.y - RHO * (xc.y - xw.y);
	xic->f = Rosenbrock(xic->x, xic->y);
}

// shrink step function
static void shrink(Point* points, int n) {
    Point best = points[0];
    for (int i = 1; i < n; i++) {
        points[i].x = best.x + SIGMA * (points[i].x - best.x);
        points[i].y = best.y + SIGMA * (points[i].y - best.y);
        points[i].f = Rosenbrock(points[i].x, points[i].y);
    }
}
// centroid compute function
static void centroid(Point* points, int num, Point* result)
{
	result->x = 0;
	result->y = 0;
	result->f = 0;

	for(int i = 0; i < num - 1; i++)
	{
		result->x += points[i].x;
		result->y += points[i].y;
	}

	result->x = result->x / (num - 1);
	result->y = result->y / (num - 1);
	result->f = Rosenbrock(result->x, result->y);
}

// Function for generate vertic point
static void InitialSimplex(Point* simplex, Point start, double step)
{
	simplex[0] = start;
	simplex[0].f = Rosenbrock(start.x, start.y);

	simplex[1].x = start.x += step;
	simplex[1].y = start.y;
	simplex[1].f = Rosenbrock(simplex[1].x, simplex[1].y);

	simplex[2].x = start.x;
	simplex[2].y = start.y += step;
	simplex[2].f = Rosenbrock(simplex[2].x, simplex[2].y);
}

// Convergence check
static int convergence(Point* simplex, int num, double eps_f, double eps_x)
{
	Point best = simplex[0];
	Point wors = simplex[ num - 1];

	double f_range = fabs(wors.f - best.f);
	double dx = fabs(wors.x - best.x);
	double dy = fabs(wors.y - best.y);
	double dist = sqrt(dx*dx + dy*dy);

	if (f_range < eps_f && dist < eps_x) return 1;
	return 0;
}

// Main nelder mean method function
void NelderMeanMethod(double (*f)(double, double), Point* start, Point* result)
{
	int n = 3;
	Point simplex[n];

	InitialSimplex(simplex, *start, 0.05);
}

/*
def Nelder_Mead_simplex_method(points, errors, x, y):
    """Main Nelder-Mead step selection."""
    best, worst = points[0], points[-1]
    second_best = points[-2]
    Xc = Centroid(points[:-1])  # centroid without worst
    Xr = Reflection(Xc, worst)
    mseXr = MSE(Xr, x, y)

    if mseXr < errors[0]:
        # Expansion
        new_point, new_error = Expansion(Xc, Xr, mseXr, x, y)
        points[-1], errors[-1] = new_point, new_error

    elif errors[0] <= mseXr < errors[-2]:
        # Accept reflection
        points[-1], errors[-1] = Xr, mseXr

    elif errors[-2] <= mseXr < errors[-1]:
        # Outside contraction
        new_point, new_error = Outside_Cont(Xc, Xr, x, y)
        if new_error <= mseXr:
            points[-1], errors[-1] = new_point, new_error
        else:
            points, errors = Shrinks(points, best, x, y)

    else:
        # Inside contraction or shrink
        new_point, new_error = Inside_Cont(Xc, worst, x, y)
        if new_error < errors[-1]:
            points[-1], errors[-1] = new_point, new_error
        else:
            points, errors = Shrinks(points, best, x, y)

    # Re-sort
    points, errors = dual_sort(errors, points)
    return points, errors
*/

/*
def Iteration(x=[0, 1, 2, 3], y=[1, 3, 7, 13], itr=20):
    """Run Nelder-Mead for a fixed number of iterations."""
    points = Initial_Simplex_Point(3, 0.05)
    points, errors = Evaluate_and_Order_Point(points, x, y)

    for _ in range(itr):
        points, errors = Nelder_Mead_simplex_method(points, errors, x, y)

    return points[0], errors[0]


# -----------------------------
# Main
# -----------------------------
def main():
    x = [0, 1, 2, 3]
    y = [1, 3, 7, 13]

    best_point, best_error = Iteration(x, y, itr=50)
    print("Best parameters:", best_point)
    print("Best error (MSE):", best_error)


main()
*/
