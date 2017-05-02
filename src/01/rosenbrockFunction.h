#ifndef ROSENBROCKFUNCTION_H
#define ROSENBROCKFUNCTION_H

#include "optimizationFunction.h"

class RosenbrockFunction: public OptimizationFunction {
public:
	RosenbrockFunction();
	~RosenbrockFunction();
	friend ostream& operator<<(ostream& os, const RosenbrockFunction& function);
	float getFitness(Individual* individual);
	float getMin();
	float getMax();
};

#endif