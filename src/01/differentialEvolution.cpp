#include "differentialEvolution.h"

#include <cfloat>
#include <cstddef>
#include <unistd.h>

using namespace std;

DifferentialEvolution::DifferentialEvolution(Crossover* crossover, Mutation* mutation, OptimizationFunction* optimizationFunction, int numDimensions) {
	this->crossover = crossover;
	this->mutation = mutation;
	this->optimizationFunction = optimizationFunction;

	for (int i = 0; i < populationSize; i++) {
		Individual individual(numDimensions, optimizationFunction->getMin(), optimizationFunction->getMax());
		individuals.push_back(individual);
	}
}

DifferentialEvolution::~DifferentialEvolution() {

}

Individual* DifferentialEvolution::optimize() {
	int iterationCounter = 0;
	int maxIterations = 5000;
	int noImprovementIterationCounter = 0;
	int maxNoImprovementIterations = 5000;
	float bestFitness = FLT_MAX;

	while (iterationCounter < maxIterations) { // noImprovementIterationCounter < maxNoImprovementIterations
		float newBest = createNextGeneration();

		if (newBest == bestFitness) {
			noImprovementIterationCounter++;
		}
		else {
			noImprovementIterationCounter = 0;
			bestFitness = newBest;
		}

		iterationCounter++;
		cout << "\rAfter " << iterationCounter << " best individual's fitness is: " << bestFitness << "                     " << flush;
		// usleep(1000000); // sleep 1 sec
	}


	for (int i = 0; i < populationSize; i++) {
		if (optimizationFunction->getFitness(&individuals[i]) == bestFitness) {
			return &individuals[i];
		}
	}

	return NULL;
}

float DifferentialEvolution::createNextGeneration() {
	vector<Individual> newGeneration;
	float bestFitness = FLT_MAX;

	for (size_t i = 0; i < populationSize; i++) {
		vector<Individual> parents = crossover->selectParents(&individuals);
		Individual individual = crossover->performCrossover(&parents);
		mutation->mutate(&individual);
		float childFitness = optimizationFunction->getFitness(&individual);
		float parentFitness = optimizationFunction->getFitness(&parents[0]);

		if (childFitness < parentFitness) {
			newGeneration.push_back(individual);

			if (childFitness < bestFitness) {
				bestFitness = childFitness;
			}
		}
		else {
			newGeneration.push_back(parents[0]);

			if (parentFitness < bestFitness) {
				bestFitness = parentFitness;
			}
		}
	}

	individuals = newGeneration;

	return bestFitness;
}