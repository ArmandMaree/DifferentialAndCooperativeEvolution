#ifndef SHUBERTFUNCTION_H
#define SHUBERTFUNCTION_H

#include "optimizationFunction.h"

class ShubertFunction: public OptimizationFunction {
public:
	ShubertFunction();
	~ShubertFunction();
	friend ostream& operator<<(ostream& os, const ShubertFunction& function);
	float getFitness(Individual* individual);
	float getMin();
	float getMax();
};

#endif