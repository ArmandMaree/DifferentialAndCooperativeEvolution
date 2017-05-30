#ifndef SHUBERTFUNCTION_H
#define SHUBERTFUNCTION_H

#include "optimizationFunction.h"

class ShubertFunction: public OptimizationFunction {
public:
	ShubertFunction();
	~ShubertFunction();
	long double getFitness(Individual* individual);
	float getMin();
	float getMax();
	string getName() const;
	friend ostream& operator<<(ostream& os, const ShubertFunction& function);
};

#endif