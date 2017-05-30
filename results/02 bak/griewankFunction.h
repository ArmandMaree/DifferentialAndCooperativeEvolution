#ifndef GRIEWANKFUNCTION_H
#define GRIEWANKFUNCTION_H

#include "optimizationFunction.h"

class GriewankFunction: public OptimizationFunction {
public:
	GriewankFunction();
	~GriewankFunction();
	long double getFitness(Individual* individual);
	float getMin();
	float getMax();
	string getName() const;
	friend ostream& operator<<(ostream& os, const GriewankFunction& function);
};

#endif