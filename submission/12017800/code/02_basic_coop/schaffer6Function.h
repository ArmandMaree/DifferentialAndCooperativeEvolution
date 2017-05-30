#ifndef SCHAFFER6FUNCTION_H
#define SCHAFFER6FUNCTION_H

#include "optimizationFunction.h"

class Schaffer6Function: public OptimizationFunction {
public:
	Schaffer6Function();
	~Schaffer6Function();
	long double getFitness(Individual* individual);
	float getMin();
	float getMax();
	string getName() const;
	friend ostream& operator<<(ostream& os, const Schaffer6Function& function);
};

#endif