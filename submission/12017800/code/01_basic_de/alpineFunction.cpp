#include "alpineFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

AlpineFunction::AlpineFunction() {

}

AlpineFunction::~AlpineFunction() {

}

long double AlpineFunction::getFitness(Individual* individual) {
	long double sinPart = 1;
	long double prodPart = 1;

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

string AlpineFunction::getName() const {
	return "Alpine";
}

ostream& operator<<(ostream& os, const AlpineFunction& function) {
	os << function.getName();
	return os;
}
