
#include "nelder.h"


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

def Reflection(Xc, Xw, alpha=1.0):
    """Reflection step."""
    return [Xc[i] + alpha*(Xc[i] - Xw[i]) for i in range(len(Xc))]


def Expansion(Xc, Xr, mseXr, x, y, gamma=2.0):
    """Expansion step."""
    Xe = [Xc[i] + gamma*(Xr[i] - Xc[i]) for i in range(len(Xc))]
    mseXe = MSE(Xe, x, y)
    return (Xe if mseXe < mseXr else Xr), min(mseXe, mseXr)


def Outside_Cont(Xc, Xr, x, y, beta=0.5):
    """Outside contraction."""
    Xoc = [Xc[i] + beta*(Xr[i] - Xc[i]) for i in range(len(Xc))]
    return Xoc, MSE(Xoc, x, y)


def Inside_Cont(Xc, Xw, x, y, beta=0.5):
    """Inside contraction."""
    Xic = [Xc[i] - beta*(Xc[i] - Xw[i]) for i in range(len(Xc))]
    return Xic, MSE(Xic, x, y)


def Shrinks(points, best, x, y, delta=0.5):
    """Shrink step."""
    new_points = [best]  # keep best
    for pt in points[1:]:
        new_pt = [best[i] + delta*(pt[i] - best[i]) for i in range(len(best))]
        new_points.append(new_pt)
    errors = [MSE(pt, x, y) for pt in new_points]
    return new_points, errors
	

def MSE(p, x=[0, 1, 2, 3], y=[1, 3, 7, 13]):
    """Mean Squared Error for quadratic function f(x) = ax² + bx + c."""
    n = len(x)
    result = 0
    for i in range(n):
        result += ((p[0]*x[i]**2 + p[1]*x[i] + p[2]) - y[i])**2
    return result / n

def Evaluate_and_Order_Point(points, x, y):
    """Evaluate and sort simplex points by MSE."""
    errors = [MSE(pt, x, y) for pt in points]
    sorted_points, sorted_errors = dual_sort(errors, points)
    return sorted_points, sorted_errors


def Centroid(points):
    """Compute centroid of given points."""
    n = len(points)
    p_dim = len(points[0])
    result = [0] * p_dim

    for pt in points:
        for j in range(p_dim):
            result[j] += pt[j]

    return [r / n for r in result]

// Function for generate vertic point
void InitialPoint(Point point, Point* points);

def Initial_Simplex_Point(p=3, s=0.05):
    """Generate initial simplex points."""
    init_sim = []
    n = p + 1

    for i in range(n):
        tmp = [0] * p
        if i > 0:
            tmp[i - 1] = s
        init_sim.append(tmp)
    return init_sim

void NelderMeanMethod(double (*f)(double, double), Point* start, Point* result)
{
}

void InitialPoint(Point point, Point* points)
{
	//
}

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
