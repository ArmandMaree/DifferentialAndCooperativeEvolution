#ifndef BESTINDIVIDUAL_H
#define BESTINDIVIDUAL_H

#include <cfloat>
#include <mutex>
#include "individual.h"
#include "optimizationFunction.h"

using namespace std;

class BestIndividual: public Individual {
public:
	BestIndividual(size_t numCells, OptimizationFunction* function);
	~BestIndividual();
	long double compareAndSet(Individual* individual, int startCellIndex, int endCellIndex);

private:
	mutex lock;
	long double fitness = FLT_MAX;
	Individual backUp;
	OptimizationFunction* function;
};

#endif