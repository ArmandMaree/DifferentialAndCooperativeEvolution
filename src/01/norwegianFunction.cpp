#include "norwegianFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

NorwegianFunction::NorwegianFunction() {

}

NorwegianFunction::~NorwegianFunction() {

}

float NorwegianFunction::getFitness(Individual* individual) {
	float prodPart = 1;
	float iValue = 0;

	for (int i = 0; i < individual->getNumCells(); i++) {
		iValue = (*individual)[i].getValue();
		prodPart *= cos(M_PI * iValue * iValue * iValue) * ((99.0 + iValue) / 100.0);
	}

	return prodPart;
}

float NorwegianFunction::getMin() {
	return -1.1;
}

float NorwegianFunction::getMax() {
	return 1.1;
}

ostream& operator<<(ostream& os, const NorwegianFunction& cell) {
	os << "Norwegian";
	return os;
}