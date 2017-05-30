#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <cstddef>
#include <iostream>
#include <vector>
#include "cell.h"

using namespace std;

class Individual {
public:
	Individual(size_t numCells, float min, float max);
	~Individual();
	size_t getNumCells();
	Cell& operator[](size_t cellIndex);
	friend ostream& operator<<(ostream& os, const Individual& individual);
private:
	vector<Cell> cells;
	size_t numCells;
	int min;
	int max;
};

#endif