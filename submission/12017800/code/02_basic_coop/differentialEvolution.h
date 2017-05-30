#ifndef DIFFERENTIALEVOLUTION_H
#define DIFFERENTIALEVOLUTION_H

#include <mutex>
#include <vector>
#include "crossover.h"
#include "bestIndividual.h"
#include "optimizationFunction.h"

using namespace std;

class DifferentialEvolution {
public:
	DifferentialEvolution(Crossover* crossover, OptimizationFunction* optimizationFunction, int numDimensions, int startCellIndex, int endCellIndex);
	~DifferentialEvolution();
	Individual* optimize(bool showProgress);
	float createNextGeneration();
	static volatile BestIndividual* bestIndividual;
	static volatile int numIterations;
private:
	vector<Individual> individuals;
	size_t populationSize = 30;
	int startCellIndex;
	int endCellIndex;
	Crossover* crossover;
	OptimizationFunction* optimizationFunction;
	mutex lock;
};

#endif