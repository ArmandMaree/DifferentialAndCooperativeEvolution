#include "alpineFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

AlpineFunction::AlpineFunction() {

}

AlpineFunction::~AlpineFunction() {

}

float AlpineFunction::getFitness(Individual* individual) {
	float sinPart = 1;
	float prodPart = 1;

	for (int i = 0; i < individual->getNumCells(); i++) {
		sinPart *= sin((*individual)[i].getValue());
		prodPart *= (*individual)[i].getValue();
	}

	if (prodPart < 0) {
		return FLT_MAX;
	}
	else {
		return sinPart * sqrt(prodPart);
	}
}

float AlpineFunction::getMin() {
	return -10;
}

float AlpineFunction::getMax() {
	return 10;
}

ostream& operator<<(ostream& os, const AlpineFunction& cell) {
	os << "Alpine";
	return os;
}