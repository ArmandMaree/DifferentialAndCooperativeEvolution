#ifndef ALPINEFUNCTION_H
#define ALPINEFUNCTION_H

#include "optimizationFunction.h"

class AlpineFunction: public OptimizationFunction {
public:
	AlpineFunction();
	~AlpineFunction();
	long double getFitness(Individual* individual);
	float getMin();
	float getMax();
	string getName() const;
	friend ostream& operator<<(ostream& os, const AlpineFunction& function);
};

#endif