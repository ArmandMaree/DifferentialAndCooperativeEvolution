#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include "cell.h"

using namespace std;

class Individual {
public:
	Individual();
	Individual(const Individual& other);
	Individual(size_t numCells, float min, float max);
	~Individual();
	size_t getNumCells();
	Cell& operator[](size_t cellIndex);
	Individual clone();
	void deepCopy(Individual* other);
	string toString() const;
	friend ostream& operator<<(ostream& os, const Individual& individual);
protected:
	vector<Cell> cells;
	size_t numCells;
	int min;
	int max;
};

#endif