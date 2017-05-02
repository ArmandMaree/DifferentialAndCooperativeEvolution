#include "cell.h"

#include <random>

using namespace std;

Cell::Cell(int min, int max) {
	random_device rd;
	mt19937 generator(rd());
	uniform_real_distribution<float> distribution(min, max);
	value = distribution(generator);
}

Cell::Cell(float value) {
	this->value = value;
}

Cell::~Cell() {

}

float Cell::getValue() {
	return value;
}

void Cell::setValue(float value) {
	this->value = value;
}

Cell& Cell::operator=(float value) {
	setValue(value);
	return *this;
}

Cell& Cell::operator=(Cell other) {
	this->value = other.value;
	return *this;
}

Cell& Cell::operator+(Cell other) {
	Cell* cell = new Cell(this->value + other.value);
	return *cell;
}

Cell& Cell::operator+(float other) {
	Cell* cell = new Cell(this->value + other);
	return *cell;
}

Cell& Cell::operator-(Cell other) {
	Cell* cell = new Cell(this->value - other.value);
	return *cell;
}

Cell& Cell::operator-(float other) {
	Cell* cell = new Cell(this->value - other);
	return *cell;
}

Cell& Cell::operator*(Cell other) {
	Cell* cell = new Cell(this->value * other.value);
	return *cell;
}

Cell& Cell::operator*(float other) {
	Cell* cell = new Cell(this->value * other);
	return *cell;
}

Cell& Cell::operator/(Cell other) {
	Cell* cell = new Cell(this->value / other.value);
	return *cell;
}

Cell& Cell::operator/(float other) {
	Cell* cell = new Cell(this->value / other);
	return *cell;
}

ostream& operator<<(ostream& os, const Cell& cell) {
	os << cell.value;
	return os;
}