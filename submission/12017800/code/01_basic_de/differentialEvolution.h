#ifndef DIFFERENTIALEVOLUTION_H
#define DIFFERENTIALEVOLUTION_H

#include <vector>
#include "crossover.h"
#include "individual.h"
#include "optimizationFunction.h"

using namespace std;

class DifferentialEvolution {
public:
	DifferentialEvolution(Crossover* crossover, OptimizationFunction* optimizationFunction, int numDimensions);
	~DifferentialEvolution();
	Individual* optimize(bool showProgress);
	int createNextGeneration();
private:
	vector<Individual> individuals;
	size_t populationSize = 30;
	Crossover* crossover;
	OptimizationFunction* optimizationFunction;
};

#endif