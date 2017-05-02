#ifndef SCHAFFER6FUNCTION_H
#define SCHAFFER6FUNCTION_H

#include "optimizationFunction.h"

class Schaffer6Function: public OptimizationFunction {
public:
	Schaffer6Function();
	~Schaffer6Function();
	friend ostream& operator<<(ostream& os, const Schaffer6Function& function);
	float getFitness(Individual* individual);
	float getMin();
	float getMax();
};

#endif