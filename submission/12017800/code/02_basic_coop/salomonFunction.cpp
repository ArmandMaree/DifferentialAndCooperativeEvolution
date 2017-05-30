#include "salomonFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

SalomonFunction::SalomonFunction() {

}

SalomonFunction::~SalomonFunction() {

}

long double SalomonFunction::getFitness(Individual* individual) {
	long double sum = 0;
	long double iValue = 0;

	for (int i = 0; i < individual->getNumCells(); i++) {
		iValue = (*individual)[i].getValue() * (*individual)[i].getValue();
		sum += iValue * iValue;
	}

	if (sum < 0) {
		return FLT_MAX;
	}
	else {
		return -cos(2.0 * M_PI * sum) + 0.1 * sqrt(sum) + 1;
	}
}

float SalomonFunction::getMin() {
	return -100;
}

float SalomonFunction::getMax() {
	return 100;
}

string SalomonFunction::getName() const {
	return "Salomon";
}

ostream& operator<<(ostream& os, const SalomonFunction& function) {
	os << function.getName();
	return os;
}