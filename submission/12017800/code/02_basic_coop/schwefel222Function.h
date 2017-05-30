#ifndef SCHWEFEL222FUNCTION_H
#define SCHWEFEL222FUNCTION_H

#include "optimizationFunction.h"

class Schwefel222Function: public OptimizationFunction {
public:
	Schwefel222Function();
	~Schwefel222Function();
	long double getFitness(Individual* individual);
	float getMin();
	float getMax();
	string getName() const;
	friend ostream& operator<<(ostream& os, const Schwefel222Function& function);
};

#endif