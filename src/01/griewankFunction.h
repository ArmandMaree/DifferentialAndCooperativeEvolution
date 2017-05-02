#ifndef GRIEWANKFUNCTION_H
#define GRIEWANKFUNCTION_H

#include "optimizationFunction.h"

class GriewankFunction: public OptimizationFunction {
public:
	GriewankFunction();
	~GriewankFunction();
	friend ostream& operator<<(ostream& os, const GriewankFunction& function);
	float getFitness(Individual* individual);
	float getMin();
	float getMax();
};

#endif