#include "salomonFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

SalomonFunction::SalomonFunction() {

}

SalomonFunction::~SalomonFunction() {

}

float SalomonFunction::getFitness(Individual* individual) {
	float sum = 0;
	float iValue = 0;

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

ostream& operator<<(ostream& os, const SalomonFunction& cell) {
	os << "Salomon";
	return os;
}