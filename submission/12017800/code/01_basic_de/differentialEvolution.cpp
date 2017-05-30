#include "differentialEvolution.h"

#include <cfloat>
#include <cstddef>
#include <cmath>
#include <unistd.h>

using namespace std;

DifferentialEvolution::DifferentialEvolution(Crossover* crossover, OptimizationFunction* optimizationFunction, int numDimensions) {
	this->crossover = crossover;
	this->optimizationFunction = optimizationFunction;

	for (int i = 0; i < populationSize; i++) {
		Individual individual(numDimensions, optimizationFunction->getMin(), optimizationFunction->getMax());
		individuals.push_back(individual);
	}
}

DifferentialEvolution::~DifferentialEvolution() {

}

Individual* DifferentialEvolution::optimize(bool showProgress) {
	int iterationCounter = 0;
	int maxIterations = 5000;
	int noImprovementIterationCounter = 0;
	int maxNoImprovementIterations = 500;
	long double bestFitness = FLT_MAX;
	int bestIndividualIndex = -1;

	while (iterationCounter < maxIterations && !isinf(bestFitness)) { // && noImprovementIterationCounter < maxNoImprovementIterations
		int bestInCurrPopulation = createNextGeneration();
		long double newBest = optimizationFunction->getFitness(&individuals[bestInCurrPopulation]);

		if (newBest >= bestFitness) {
			noImprovementIterationCounter++;
		}
		else {
			noImprovementIterationCounter = 0;
			bestFitness = newBest;
			bestIndividualIndex = bestInCurrPopulation;
		}

		iterationCounter++;
		
		if (showProgress && iterationCounter % 1 == 0) {
			cout << "\rAfter " << iterationCounter << " iterations, the best individual's fitness is: " << bestFitness << "                     " << flush;
			// usleep(100000); // sleep 1 sec: 1 * 1000 * 1000
		}
	}

	return &individuals[bestIndividualIndex];
}

int DifferentialEvolution::createNextGeneration() {
	vector<Individual> newGeneration;
	long double bestFitness = FLT_MAX;
	int bestIndividualIndex = -1;

	for (size_t i = 0; i < populationSize; i++) {
		vector<Individual> parents;
		parents.push_back(individuals[i]); // target
		parents.push_back(crossover->getTrial(&individuals, i)); // trial
		Individual child = crossover->performCrossover(&parents);
		long double childFitness = optimizationFunction->getFitness(&child);
		long double parentFitness = optimizationFunction->getFitness(&parents[0]);

		if (childFitness < parentFitness) {
			newGeneration.push_back(child);

			if (childFitness < bestFitness) {
				bestFitness = childFitness;
				bestIndividualIndex = i;
			}
		}
		else {
			newGeneration.push_back(parents[0]);

			if (parentFitness < bestFitness) {
				bestFitness = parentFitness;
				bestIndividualIndex = i;
			}
		}
	}

	individuals = newGeneration;
	return bestIndividualIndex;
}