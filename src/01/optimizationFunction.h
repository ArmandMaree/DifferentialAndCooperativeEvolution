#ifndef OPTIMIZATIONFUNCTION_H
#define OPTIMIZATIONFUNCTION_H

#include "individual.h"

class OptimizationFunction {
public:
	OptimizationFunction();
	~OptimizationFunction();
	virtual float getFitness(Individual* individual) = 0;
	virtual float getMin() = 0;
	virtual float getMax() = 0;
};

#endif