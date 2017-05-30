#include "individual.h"

Individual::Individual() {

}

Individual::Individual(const Individual& other) {
	numCells = other.numCells;
	min = other.min;
	max = other.max;

	for (int i = 0; i < numCells; i++) {
		cells.push_back(Cell(other.cells[i]));
	}
}

Individual::Individual(size_t numCells, float min, float max) {
	this->numCells = numCells;
	this->min = min;
	this->max = max;

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

Individual Individual::clone() {
	Individual myClone(numCells, min, max);

	for (int i = 0; i < numCells; i++) {
		myClone[i] = cells[i];
	}

	return myClone;
}

void Individual::deepCopy(Individual* other) {
	for (int i = 0; i < numCells; i++) {
		cells[i] = other->cells[i];
	}
}

string Individual::toString() const {
	string strRep = "";

	for (size_t i = 0; i < numCells; i++) {
		if (i == 0) {
			strRep += "[";
		}
		else {
			strRep += ",";
		}

		strRep += to_string(cells[i].getValue());
	}

	strRep += "]";
	return strRep;
}

ostream& operator<<(ostream& os, const Individual& individual) {
	os << individual.toString();
	return os;
}