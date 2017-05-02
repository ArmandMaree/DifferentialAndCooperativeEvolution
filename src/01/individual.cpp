#include "individual.h"

Individual::Individual(size_t numCells, float min, float max) {
	this->numCells = numCells;

	for (int i = 0; i < numCells; i++) {
		Cell cell(min, max);
		cells.push_back(cell);
	}
}

Individual::~Individual() {
	
}

size_t Individual::getNumCells() {
	return numCells;
}

Cell& Individual::operator[](size_t cellIndex) {
	return cells[cellIndex];
}

ostream& operator<<(ostream& os, const Individual& individual) {
	for (size_t i = 0; i < individual.numCells; i++) {
		if (i == 0) {
			os << "[";
		}
		else {
			os << ",";
		}

		os << individual.cells[i];
	}

	os << "]";

	return os;
}