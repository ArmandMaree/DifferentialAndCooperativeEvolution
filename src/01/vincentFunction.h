#ifndef VINCENTFUNCTION_H
#define VINCENTFUNCTION_H

#include "optimizationFunction.h"

class VincentFunction: public OptimizationFunction {
public:
	VincentFunction();
	~VincentFunction();
	friend ostream& operator<<(ostream& os, const VincentFunction& function);
	float getFitness(Individual* individual);
	float getMin();
	float getMax();
};

#endif