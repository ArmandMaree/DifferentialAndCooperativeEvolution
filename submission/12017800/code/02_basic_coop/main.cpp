#include <cmath>
#include <iostream>
#include <string>
#include <pthread.h>

#include "optimizationFunction.h"
#include "alpineFunction.h"
#include "eggholderFunction.h"
#include "griewankFunction.h"
#include "norwegianFunction.h"
#include "rosenbrockFunction.h"
#include "salomonFunction.h"
#include "schaffer6Function.h"
#include "schwefel222Function.h"
#include "shubertFunction.h"
#include "vincentFunction.h"
#include "weierstrassFunction.h"

#include "binomialCrossover.h"
#include "differentialEvolution.h"
#include "individual.h"

using namespace std;

int optimizeFunction(OptimizationFunction* function, int numDimensions);
long double calculateAverage(vector<long double>& values);
long double calculateStandardDeviation(vector<long double>& values);

void test() {
	AlpineFunction function;
	float min = function.getMin();
	float max = function.getMax();
	BinomialCrossover crossover(0.5, min, max);

	Individual individual1(2, min, max);
	cout << "Individual1 (Original): " << individual1 << endl;
	Individual individual2(2, min, max);
	cout << "Individual2 (Original): " << individual2 << endl;
	vector<Individual> population;
	population.push_back(individual1);
	population.push_back(individual2);
	Individual individual3 = crossover.performCrossover(&population);
	cout << "Individual3 (Due To Crossover): " << individual3 << endl;
	population.push_back(Individual(2, min, max));
	population.push_back(Individual(2, min, max));
	population.push_back(Individual(2, min, max));
	population.push_back(Individual(2, min, max));
	population.push_back(Individual(2, min, max));
	population.push_back(Individual(2, min, max));
	population.push_back(Individual(2, min, max));
	population.push_back(Individual(2, min, max));
	cout << "Population size: " << population.size() << endl;
	Individual trial = crossover.getTrial(&population, 0);
	cout << "Trial: " << trial << endl;
	cout << "Individual1 fitness: " << function.getFitness(&individual1) << endl;
	cout << "Individual2 fitness: " << function.getFitness(&individual2) << endl;
	cout << "Individual3 fitness: " << function.getFitness(&individual3) << endl;
	DifferentialEvolution de(&crossover, &function, 2, 0, 2);
	de.createNextGeneration();
}

bool showProgress = true;

int main(int argc, char const *argv[]) {
	int numDimensions = atoi(argv[1]);
	
	// test();
	vector<OptimizationFunction*> functions;
	functions.push_back(new AlpineFunction());
	functions.push_back(new EggholderFunction());
	functions.push_back(new GriewankFunction());
	functions.push_back(new NorwegianFunction());
	functions.push_back(new RosenbrockFunction());
	functions.push_back(new SalomonFunction());
	functions.push_back(new Schaffer6Function());
	functions.push_back(new Schwefel222Function());
	functions.push_back(new ShubertFunction());
	functions.push_back(new VincentFunction());
	functions.push_back(new WeierstrassFunction());

	while(functions.size() != 0) {
		cout << "\033[33mSTART HERE\033[0m" << endl;
		cout << "Function: " << functions[0]->getName() << endl;
		
		if (optimizeFunction(functions[0], numDimensions) == 1) {
			return 1;
		}

		delete functions[0];
		functions.erase(functions.begin());
		cout << "\033[33mEND HERE\033[0m" << endl;
	}

	return 0;
}

vector<DifferentialEvolution*> differentialEvolutions;
volatile int threadId = 0;

void* solveInThread(void*) {
	static mutex lock;
	int myId = -1;
	
	lock.lock();
	myId = threadId++;
	lock.unlock();

	differentialEvolutions[myId]->optimize(showProgress);
}

int optimizeFunction(OptimizationFunction* function, int numDimensions) {
	vector<long double> bestValues;
	int numRunsPerFunction = 30;
	float mutationProbability = 0.1;
	float crossoverProbability = 0.5;
	int numInstances = numDimensions * 0.2;
	int numDimensionsPerInstance = numDimensions / numInstances;

	BinomialCrossover crossover(0.5, function->getMin(), function->getMax());

	for (int j = 0; j < numInstances; j++) {
		cout << "DE #" << j << " will solve dimension " << j * numDimensionsPerInstance << " to " << (j + 1) * numDimensionsPerInstance - 1 << " (inclusive)."<< endl << flush;
	}

	for (int i = 0; i < numRunsPerFunction; i++) { // execute function 30 times.
		cout << "\033[32mRun #" << i << "\033[0m" << endl << flush;
		threadId = 0;

		for (int j = 0; j < numInstances; j++) {
			DifferentialEvolution* de = new DifferentialEvolution(&crossover, function, numDimensions, j * numDimensionsPerInstance, (j + 1) * numDimensionsPerInstance);
			differentialEvolutions.push_back(de);
		}

		vector<pthread_t> threads;

		for (int j = 0; j < numInstances; j++) {
			pthread_t t;
			pthread_create(&t, NULL, &solveInThread, NULL);
			threads.push_back(t);
		}

		for (int j = 0; j < numInstances; j++) {
			pthread_join(threads[j], NULL);
		}

		volatile Individual* bestIndividual = DifferentialEvolution::bestIndividual;

		if (bestIndividual != NULL) {
			if (showProgress) {
				cout << "\r                                                                                   \r";
			}
	
			cout << "\tBest Individual: " << ((Individual*)bestIndividual)->toString() << endl << flush;
			long double fitness = function->getFitness(((Individual*)bestIndividual));
			cout << "\tFitness: " << fitness << endl << flush;
			cout << "\tNumber of Iterations: " << DifferentialEvolution::numIterations << endl << flush;
			bestValues.push_back(fitness);
		}
		else {
			cout << "\r\033[31mNo solution could be found.\033[0m                                                  " << endl << flush;
			return 1;
		}

		while (differentialEvolutions.size() > 0) {
			delete differentialEvolutions[0];
			differentialEvolutions.erase(differentialEvolutions.begin());
		}

	}

	cout << "\033[34mStatistics:\033[0m" << endl;
	cout << "\tAverage:            " << calculateAverage(bestValues) << endl;
	cout << "\tStandard Deviation: " << calculateStandardDeviation(bestValues) << endl;
	return 0;
}

long double calculateAverage(vector<long double>& values) {
	long double sum = 0;

	for (int i = 0; i < values.size(); i++) {
		sum += values[i];
	}

	return sum / values.size();
}

long double calculateStandardDeviation(vector<long double>& values) {
	long double sum = 0;
	long double average = calculateAverage(values);

	for (int i = 0; i < values.size(); i++) {
		sum += pow(values[i] - average, 2);
	}

	return sqrt(sum / (values.size() - 1));
}
