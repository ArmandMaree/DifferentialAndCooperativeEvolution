#ifndef NORWEGIANFUNCTION_H
#define NORWEGIANFUNCTION_H

#include "optimizationFunction.h"

class NorwegianFunction: public OptimizationFunction {
public:
	NorwegianFunction();
	~NorwegianFunction();
	long double getFitness(Individual* individual);
	float getMin();
	float getMax();
	string getName() const;
	friend ostream& operator<<(ostream& os, const NorwegianFunction& function);
};

#endif