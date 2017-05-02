#ifndef SALOMONFUNCTION_H
#define SALOMONFUNCTION_H

#include "optimizationFunction.h"

class SalomonFunction: public OptimizationFunction {
public:
	SalomonFunction();
	~SalomonFunction();
	friend ostream& operator<<(ostream& os, const SalomonFunction& function);
	float getFitness(Individual* individual);
	float getMin();
	float getMax();
};

#endif