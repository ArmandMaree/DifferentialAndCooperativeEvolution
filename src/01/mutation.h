#ifndef MUTATION_H
#define MUTATION_H

#include "individual.h"

class Mutation {
public:
	Mutation(float min, float max, float mutationProbability);
	~Mutation();
	void mutate(Individual* individual);
private:
	float min;
	float max;
	float mutationProbability;
};

#endif