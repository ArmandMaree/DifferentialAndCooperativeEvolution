#include "bestIndividual.h"

BestIndividual::BestIndividual(size_t numCells, OptimizationFunction* function) { //function->getMin()
	this->numCells = numCells;
	this->min = function->getMin();
	this->max = function->getMax();
	this->function = function;

	for (int i = 0; i < numCells; i++) {
		Cell cell(min, max);
		cells.push_back(cell);
	}

	backUp = clone();
}

BestIndividual::~BestIndividual() {

}

long double BestIndividual::compareAndSet(Individual* individual, int startCellIndex, int endCellIndex) {
	Individual newIndividual(*this);
	// cout << "BEFORE: " << toString() << endl;
	for (int i = 0; i < endCellIndex - startCellIndex; i++) {
		newIndividual[startCellIndex + i] = (*individual)[i];
	}

	long double individualFitness = function->getFitness(&newIndividual);
	// cout << "DURING: " << toString() << " FITNESS: " << individualFitness << " VS " << fitness << endl;

	if (individualFitness < fitness) {
		lock.lock();

		for (int i = 0; i < endCellIndex - startCellIndex; i++) {
			(*this)[startCellIndex + i] = (*individual)[i];
		}

		individualFitness = function->getFitness(&newIndividual);
		
		if (individualFitness < fitness) {
			fitness = individualFitness;
			backUp = clone();
		}
		else {
			deepCopy(&backUp);
		}

		lock.unlock();
	}
	// cout << "AFTER: " << toString() << endl;



	return individualFitness;
}
