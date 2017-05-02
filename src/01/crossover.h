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
	virtual vector<Individual> selectParents(vector<Individual>* population) = 0;
};

#endif