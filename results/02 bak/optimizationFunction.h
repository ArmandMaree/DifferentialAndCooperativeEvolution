#ifndef OPTIMIZATIONFUNCTION_H
#define OPTIMIZATIONFUNCTION_H

#include <string>
#include "individual.h"

class OptimizationFunction {
public:
	OptimizationFunction();
	~OptimizationFunction();
	virtual long double getFitness(Individual* individual) = 0;
	virtual float getMin() = 0;
	virtual float getMax() = 0;
	virtual string getName() const = 0;
};

#endif