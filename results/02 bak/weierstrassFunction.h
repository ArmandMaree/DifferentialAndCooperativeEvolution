#ifndef WEIERSTRASSFUNCTION_H
#define WEIERSTRASSFUNCTION_H

#include "optimizationFunction.h"

class WeierstrassFunction: public OptimizationFunction {
public:
	WeierstrassFunction();
	~WeierstrassFunction();
	long double getFitness(Individual* individual);
	float getMin();
	float getMax();
	string getName() const;
	friend ostream& operator<<(ostream& os, const WeierstrassFunction& function);
};

#endif