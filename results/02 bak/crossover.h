#ifndef CROSSOVER_H
#define CROSSOVER_H

#include <vector>
#include "individual.h"

using namespace std;

class Crossover {
public:
	Crossover();
	~Crossover();
	virtual Individual performCrossover(vector<Individual>* parents) = 0;
	virtual Individual getTrial(vector<Individual>* population, int target) = 0;
};

#endif