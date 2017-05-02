#ifndef EGGHOLDERFUNCTION_H
#define EGGHOLDERFUNCTION_H

#include "optimizationFunction.h"

class EggholderFunction: public OptimizationFunction {
public:
	EggholderFunction();
	~EggholderFunction();
	friend ostream& operator<<(ostream& os, const EggholderFunction& function);
	float getFitness(Individual* individual);
	float getMin();
	float getMax();
};

#endif