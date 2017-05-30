#include "binomialCrossover.h"

#include <random>

using namespace std;

BinomialCrossover::BinomialCrossover(float crossoverProbability, float min, float max) {
	this->crossoverProbability = crossoverProbability;
	this->min = min;
	this->max = max;
}

BinomialCrossover::~BinomialCrossover() {

}

Individual BinomialCrossover::performCrossover(vector<Individual>* parents) {
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> tmpDistribution(0, (*parents)[0].getNumCells() - 1);
	int indexOfForceChange = tmpDistribution(generator);
	uniform_real_distribution<float> distribution(0.0, 1.0);

	Individual offspring((*parents)[0].getNumCells(), min, max);

	for (size_t i = 0; i < (*parents)[0].getNumCells(); i++) {
		if (i == indexOfForceChange) {
			offspring[i] = (*parents)[1][i];
			continue;
		}
		else if (distribution(generator) < crossoverProbability) {
			offspring[i] = (*parents)[1][i];
		}
		else {
			offspring[i] = (*parents)[0][i];
		}
	}

	return offspring;
}

Individual BinomialCrossover::getTrial(vector<Individual>* population, int target) {
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> distribution(0, population->size() - 1);
	int numCells = (*population)[0].getNumCells();
	Individual trial(numCells, min, max);
	
	int p1 = target;
	int p2 = target;

	while (p1 == target) {
		p1 = distribution(generator);
	}

	while (p2 == target || p2 == p1) {
		p2 = distribution(generator);
	}

	for (int i = 0; i < numCells; i++) {
		Cell targetCell = (*population)[target][i];
		Cell p1Cell = (*population)[p1][i];
		Cell p2Cell = (*population)[p2][i];
		trial[i] = targetCell + (p1Cell - p2Cell) * scaleVector;
	}

	return trial;
}