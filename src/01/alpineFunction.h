#ifndef ALPINEFUNCTION_H
#define ALPINEFUNCTION_H

#include "optimizationFunction.h"

class AlpineFunction: public OptimizationFunction {
public:
	AlpineFunction();
	~AlpineFunction();
	friend ostream& operator<<(ostream& os, const AlpineFunction& function);
	float getFitness(Individual* individual);
	float getMin();
	float getMax();
};

#endif