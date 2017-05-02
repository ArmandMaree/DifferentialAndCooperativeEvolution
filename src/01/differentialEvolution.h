#ifndef DIFFERENTIALEVOLUTION_H
#define DIFFERENTIALEVOLUTION_H

#include <vector>
#include "crossover.h"
#include "individual.h"
#include "mutation.h"
#include "optimizationFunction.h"

using namespace std;

class DifferentialEvolution {
public:
	DifferentialEvolution(Crossover* crossover, Mutation* mutation, OptimizationFunction* optimizationFunction, int numDimensions);
	~DifferentialEvolution();
	Individual* optimize();
	float createNextGeneration();
private:
	vector<Individual> individuals;
	size_t populationSize = 20;
	Crossover* crossover;
	Mutation* mutation;
	OptimizationFunction* optimizationFunction;
};

#endif