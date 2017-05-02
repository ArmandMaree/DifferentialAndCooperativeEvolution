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
	vector<Individual> selectParents(vector<Individual>* population);

private:
	float crossoverProbability;
	float scaleVector = 0.5;
	float min;
	float max;
	bool* getCrossoverSet(size_t numCells);
};

#endif