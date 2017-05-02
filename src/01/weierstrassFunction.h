#ifndef WEIERSTRASSFUNCTION_H
#define WEIERSTRASSFUNCTION_H

#include "optimizationFunction.h"

class WeierstrassFunction: public OptimizationFunction {
public:
	WeierstrassFunction();
	~WeierstrassFunction();
	friend ostream& operator<<(ostream& os, const WeierstrassFunction& function);
	float getFitness(Individual* individual);
	float getMin();
	float getMax();
};

#endif