#include "binomialCrossover.h"

#include <random>

using namespace std;

BinomialCrossover::BinomialCrossover(float crossoverProbability, float min, float max) {
	this->crossoverProbability = crossoverProbability;
	this->min;
	this->max;
}

BinomialCrossover::~BinomialCrossover() {

}
	
bool* BinomialCrossover::getCrossoverSet(size_t numCells) {
	bool* crossoverSet = new bool[numCells];
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> tmpDistribution(0, numCells - 1);
	int indexOfForceChange = tmpDistribution(generator);
	crossoverSet[indexOfForceChange] = true;

	uniform_real_distribution<float> distribution(0.0, 1.0);


	for (size_t i = 0; i < numCells; i++) {
		if (i == indexOfForceChange) {
			continue;
		}

		if (distribution(generator) < crossoverProbability) {
			crossoverSet[i] = true;
		}
		else {
			crossoverSet[i] = false;
		}
	}

	return crossoverSet;
}

Individual BinomialCrossover::performCrossover(vector<Individual>* parents) {
	Individual offspring((*parents)[0].getNumCells(), min, max);
	bool* crossoverSet = getCrossoverSet((*parents)[0].getNumCells());

	for (size_t i = 0; i < (*parents)[0].getNumCells(); i++) {

		if (crossoverSet[i]) {
			offspring[i] = (*parents)[1][i];
		}
		else {
			offspring[i] = (*parents)[0][i];
		}
	}

	delete [] crossoverSet;
	return offspring;
}

vector<Individual> BinomialCrossover::selectParents(vector<Individual>* population) {
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> distribution(0, population->size() - 1);
	int numCells = (*population)[0].getNumCells();
	int target = distribution(generator);
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

	vector<Individual> parents;
	parents.push_back((*population)[target]);
	parents.push_back(trial);
	return parents;
}