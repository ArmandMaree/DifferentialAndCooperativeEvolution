#ifndef SALOMONFUNCTION_H
#define SALOMONFUNCTION_H

#include "optimizationFunction.h"

class SalomonFunction: public OptimizationFunction {
public:
	SalomonFunction();
	~SalomonFunction();
	long double getFitness(Individual* individual);
	float getMin();
	float getMax();
	string getName() const;
	friend ostream& operator<<(ostream& os, const SalomonFunction& function);
};

#endif