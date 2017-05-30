#ifndef VINCENTFUNCTION_H
#define VINCENTFUNCTION_H

#include "optimizationFunction.h"

class VincentFunction: public OptimizationFunction {
public:
	VincentFunction();
	~VincentFunction();
	long double getFitness(Individual* individual);
	float getMin();
	float getMax();
	string getName() const;
	friend ostream& operator<<(ostream& os, const VincentFunction& function);
};

#endif