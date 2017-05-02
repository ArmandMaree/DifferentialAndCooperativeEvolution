#ifndef SCHWEFEL222FUNCTION_H
#define SCHWEFEL222FUNCTION_H

#include "optimizationFunction.h"

class Schwefel222Function: public OptimizationFunction {
public:
	Schwefel222Function();
	~Schwefel222Function();
	friend ostream& operator<<(ostream& os, const Schwefel222Function& function);
	float getFitness(Individual* individual);
	float getMin();
	float getMax();
};

#endif