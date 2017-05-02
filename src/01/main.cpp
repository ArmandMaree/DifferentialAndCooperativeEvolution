#include <iostream>
#include <string>

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
#include "mutation.h"

using namespace std;

void test(float min, float max) {
	Mutation mutation(min, max, 0.5);
	BinomialCrossover crossover(0.5, min, max);

	Individual individual1(2, min, max);
	cout << "Individual1 (Original): " << individual1 << endl;
	mutation.mutate(&individual1);
	cout << "Individual1 (After Mutation): " << individual1 << endl;
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
	vector<Individual> parents = crossover.selectParents(&population);
	cout << "Parents size: " << parents.size() << endl;
	AlpineFunction function;
	cout << "Individual1 fitness: " << function.getFitness(&individual1) << endl;
	cout << "Individual2 fitness: " << function.getFitness(&individual2) << endl;
	cout << "Individual3 fitness: " << function.getFitness(&individual3) << endl;
	DifferentialEvolution de(&crossover, &mutation, &function, 2);
	de.createNextGeneration();
}

int main(int argc, char const *argv[]) {
	// AlpineFunction function;
	// EggholderFunction function;
	// GriewankFunction function;
	// NorwegianFunction function;
	// RosenbrockFunction function;
	// SalomonFunction function;
	// Schaffer6Function function;
	// Schwefel222Function function;
	// ShubertFunction function;
	// VincentFunction function;
	WeierstrassFunction function;

	int numDimensions = 5;

	Mutation mutation(function.getMin(), function.getMax(), 0.1);
	BinomialCrossover crossover(0.1, function.getMin(), function.getMax());
	cout << "\033[33mSTART HERE\033[0m" << endl;
	cout << "Function: " << function << endl;
	// test(function.getMin(), function.getMax());

	DifferentialEvolution differentialEvolution(&crossover, &mutation, &function, numDimensions);

	Individual* bestIndividual = differentialEvolution.optimize();

	if (bestIndividual != NULL) {
		cout << "\r\033[32mBest Individual:\033[0m                                 \n\t" << (*bestIndividual) << endl << "\033[34mFitness:\033[0m " << function.getFitness(bestIndividual) << endl;
	}
	else {
		cout << "\033[31mNo solution could be found.\033[0m" << endl;
	}

	cout << "\033[33mEND HERE\033[0m" << endl;
	return 0;
}
