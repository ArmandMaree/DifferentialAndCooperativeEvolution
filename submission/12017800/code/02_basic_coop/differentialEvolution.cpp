#include "differentialEvolution.h"

#include <cfloat>
#include <cstddef>
#include <cmath>
#include <thread>
#include <unistd.h>

using namespace std;

volatile BestIndividual* DifferentialEvolution::bestIndividual = NULL;
volatile int DifferentialEvolution::numIterations = 0;

DifferentialEvolution::DifferentialEvolution(Crossover* crossover, OptimizationFunction* optimizationFunction, int numDimensions, int startCellIndex, int endCellIndex) {

	if (bestIndividual == NULL) {
		lock.lock();
		if (bestIndividual == NULL) {
			bestIndividual = new BestIndividual(numDimensions, optimizationFunction);
		}
		lock.unlock();
	}

	this->startCellIndex = startCellIndex;
	this->endCellIndex = endCellIndex;
	this->crossover = crossover;
	this->optimizationFunction = optimizationFunction;

	for (int i = 0; i < populationSize; i++) {
		Individual individual(endCellIndex - startCellIndex, optimizationFunction->getMin(), optimizationFunction->getMax());
		individuals.push_back(individual);
	}
}

DifferentialEvolution::~DifferentialEvolution() {
	if (bestIndividual != NULL) {
		lock.lock();
		if (bestIndividual != NULL) {
			delete bestIndividual;
			bestIndividual = NULL;
		}
		lock.unlock();
	}
}

Individual* DifferentialEvolution::optimize(bool showProgress) {
	int iterationCounter = 0;
	int maxIterations = 5000;
	int noImprovementIterationCounter = 0;
	int maxNoImprovementIterations = 500;
	long double bestFitness = FLT_MAX;

	while (iterationCounter < maxIterations && !isinf(bestFitness)) { // && noImprovementIterationCounter < maxNoImprovementIterations
		long double newBest = createNextGeneration();

		if (newBest >= bestFitness) {
			noImprovementIterationCounter++;
		}
		else {
			noImprovementIterationCounter = 0;
			bestFitness = newBest;
		}

		iterationCounter++;
		
		if (showProgress && iterationCounter % 100 == 0) {
			cout << "\rAfter " << iterationCounter << " iterations, the best individual's fitness is: " << bestFitness << "                    " << flush;
			// usleep(100000); // sleep 1 sec: 1 * 1000 * 1000
		}
	}

	numIterations = iterationCounter;

	return (Individual*)bestIndividual;
}

float DifferentialEvolution::createNextGeneration() {
	vector<Individual> newGeneration;
	long double bestFitness = FLT_MAX;

	for (size_t i = 0; i < populationSize; i++) {
		vector<Individual> parents;
		parents.push_back(individuals[i]); // target
		parents.push_back(crossover->getTrial(&individuals, i)); // trial
		Individual child = crossover->performCrossover(&parents);
		long double childFitness = ((BestIndividual*)bestIndividual)->compareAndSet(&child, startCellIndex, endCellIndex);
		long double parentFitness = ((BestIndividual*)bestIndividual)->compareAndSet(&parents[0], startCellIndex, endCellIndex);

		if (childFitness < parentFitness) {
			newGeneration.push_back(child);

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