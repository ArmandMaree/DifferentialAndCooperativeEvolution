#ifndef NORWEGIANFUNCTION_H
#define NORWEGIANFUNCTION_H

#include "optimizationFunction.h"

class NorwegianFunction: public OptimizationFunction {
public:
	NorwegianFunction();
	~NorwegianFunction();
	friend ostream& operator<<(ostream& os, const NorwegianFunction& function);
	float getFitness(Individual* individual);
	float getMin();
	float getMax();
};

#endif