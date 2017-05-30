#ifndef CELL_H
#define CELL_H

#include <iostream>

using namespace std;

class Cell {
public:
	Cell(int min, int max);
	Cell(int min, int max, float value);
	Cell(const Cell& other);
	~Cell();
	float getValue() const;
	void setValue(float value);
	Cell& operator=(float value);
	Cell& operator=(Cell other);
	Cell operator+(Cell other);
	Cell operator+(float other);
	Cell operator-(Cell other);
	Cell operator-(float other);
	Cell operator*(Cell other);
	Cell operator*(float other);
	Cell operator/(Cell other);
	Cell operator/(float other);
	friend ostream& operator<<(ostream& os, const Cell& cell);
private:
	float value;
	int min;
	int max;
};

#endif