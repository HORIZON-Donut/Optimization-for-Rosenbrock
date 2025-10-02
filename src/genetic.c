#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "rosenbrock.h"
#include "util.h"

#define POP_SIZE 50     // number of individuals
#define MAX_GEN  500    // max generations
#define CROSS_RATE 0.7  // probability of crossover
#define MUT_RATE  0.2   // probability of mutation
#define MUT_STEP  0.1   // mutation step size

// Random double in [min, max]
static double randDouble(double min, double max) {
    return min + (max - min) * ((double) rand() / RAND_MAX);
}

// Initialize population randomly
static void initPopulation(Point *pop, int size, Point start, double spread) {
    for (int i = 0; i < size; i++) {
        pop[i].x = start.x + randDouble(-spread, spread);
        pop[i].y = start.y + randDouble(-spread, spread);
        pop[i].f = Rosenbrock(pop[i].x, pop[i].y);
    }
}

// Evaluate fitness (lower is better -> invert for selection)
static double fitness(Point p) {
    return 1.0 / (1.0 + p.f); // smaller f → larger fitness
}

// Tournament selection
static Point tournamentSelect(Point *pop, int size) {
    int a = rand() % size;
    int b = rand() % size;
    return (fitness(pop[a]) > fitness(pop[b])) ? pop[a] : pop[b];
}

// Crossover (blend two parents)
static Point crossover(Point p1, Point p2) {
    Point child;
    if ((double)rand()/RAND_MAX < CROSS_RATE) {
        double alpha = randDouble(0, 1);
        child.x = alpha * p1.x + (1 - alpha) * p2.x;
        child.y = alpha * p1.y + (1 - alpha) * p2.y;
    } else {
        child = p1; // no crossover, copy parent
    }
    child.f = Rosenbrock(child.x, child.y);
    return child;
}

// Mutation
static void mutate(Point *p) {
    if ((double)rand()/RAND_MAX < MUT_RATE) {
        p->x += randDouble(-MUT_STEP, MUT_STEP);
        p->y += randDouble(-MUT_STEP, MUT_STEP);
    }
    p->f = Rosenbrock(p->x, p->y);
}

// Genetic Algorithm main function
void GeneticAlgorithm(Point *bestResult, Point start, double spread) {
    srand(time(NULL));

    Point population[POP_SIZE];
    Point newPop[POP_SIZE];
    initPopulation(population, POP_SIZE, start, spread);

    *bestResult = population[0];

    for (int gen = 0; gen < MAX_GEN; gen++) {
        // Find best in population
        for (int i = 0; i < POP_SIZE; i++) {
            if (population[i].f < bestResult->f) {
                *bestResult = population[i];
            }
        }

        // Elitism: keep best
        newPop[0] = *bestResult;

        // Generate rest of population
        for (int i = 1; i < POP_SIZE; i++) {
            Point parent1 = tournamentSelect(population, POP_SIZE);
            Point parent2 = tournamentSelect(population, POP_SIZE);
            Point child = crossover(parent1, parent2);
            mutate(&child);
            newPop[i] = child;
        }

        // Replace old population
        for (int i = 0; i < POP_SIZE; i++) {
            population[i] = newPop[i];
        }

        // Optional debug
        if (gen % 50 == 0) {
            printf("Gen %d: Best = (%.6f, %.6f), f = %.6f\n",
                   gen, bestResult->x, bestResult->y, bestResult->f);
        }
    }
}

