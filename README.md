# Optimization-for-Rosenbrock

## Overview

This repository provides C implementations of three optimization methods:
- **Genetic Algorithm**
- **Nelder-Mead Simplex**
- **Powell’s Method**

All methods are applied to the classic Rosenbrock function:

```
f(x, y) = (1 - x)^2 + 100 * (y - x^2)^2
```

The code is organized into modules for each algorithm, the objective function, and utility functions.

## Modules

- **genetic/**  
  Implements a genetic algorithm for optimizing the Rosenbrock function using population-based search, selection, crossover, mutation, and elitism.

- **nelder/**  
  Implements the Nelder-Mead simplex method, which iteratively transforms a simplex in search space using reflection, expansion, contraction, and shrinking.

- **powell/**  
  Powell’s method: a derivative-free approach using line searches along coordinate directions.

- **rosenbrock/**  
  Contains the Rosenbrock function definition.

- **util/**  
  Utility functions and data structures for points, initialization, sorting, timing, and printing.

## Usage

Each algorithm can be invoked on a set of initial points. The main file runs all methods and prints the progression and results.

**Example output:**
```
Powell method
Point 1:
Start point: x = 2.000000, y = 2.000000
Iteration used to compute: 10
Time use to solve: 0.000012 second
Final position:
----------
X = 1.000000
Y = 1.000000
F = 0.000000
----------
...
```

## Build and Run
Make sure you have gcc compiler and make installed on your system.
1. Clone the repository:
   ```
   git clone https://github.com/HORIZON-Donut/Optimization-for-Rosenbrock.git
   cd Optimization-for-Rosenbrock
   ```

2. Build the project (requires GCC):
   ```
   make
   ```

3. Run the binary:
   ```
   ./bin/run
   ```
   or
   ```
   make run
   ```
If you're using windows, You may build and run using WSL or attempt manual compile on your own.
