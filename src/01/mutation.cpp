#include "mutation.h"

#include <cstddef>
#include <random>

using namespace std;

Mutation::Mutation(float min, float max, float mutationProbability) {
	this->min = min;
	this->max = max;
	this->mutationProbability = mutationProbability;
}

Mutation::~Mutation() {
	
}

void Mutation::mutate(Individual* individual) {
	random_device rd;
	mt19937 generator(rd());
	uniform_real_distribution<float> probability(0.0, 1.0);
	uniform_real_distribution<float> distribution(min, max);

	for (size_t i = 0; i < individual->getNumCells(); i++) {
		if (probability(generator) < mutationProbability) {
			(*individual)[i] = distribution(generator);
		}
	}
}