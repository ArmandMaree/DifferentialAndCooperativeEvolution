#ifndef BINOMIALCROSSOVER_H
#define BINOMIALCROSSOVER_H

#include <cstddef>
#include <vector>
#include "crossover.h"
#include "individual.h"

class BinomialCrossover: public Crossover {
public:
	BinomialCrossover(float crossoverProbability, float min, float max);
	~BinomialCrossover();
	Individual performCrossover(vector<Individual>* parents);
	Individual getTrial(vector<Individual>* population, int target);

private:
	float crossoverProbability;
	float scaleVector = 0.5; // beta
	float min;
	float max;
};

#endif