#ifndef ROSENBROCKFUNCTION_H
#define ROSENBROCKFUNCTION_H

#include "optimizationFunction.h"

class RosenbrockFunction: public OptimizationFunction {
public:
	RosenbrockFunction();
	~RosenbrockFunction();
	long double getFitness(Individual* individual);
	float getMin();
	float getMax();
	string getName() const;
	friend ostream& operator<<(ostream& os, const RosenbrockFunction& function);
};

#endif