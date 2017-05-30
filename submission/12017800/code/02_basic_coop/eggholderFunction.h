#ifndef EGGHOLDERFUNCTION_H
#define EGGHOLDERFUNCTION_H

#include "optimizationFunction.h"

class EggholderFunction: public OptimizationFunction {
public:
	EggholderFunction();
	~EggholderFunction();
	long double getFitness(Individual* individual);
	float getMin();
	float getMax();
	string getName() const;
	friend ostream& operator<<(ostream& os, const EggholderFunction& function);
};

#endif