#include "schwefel222Function.h"

#include <cfloat>
#include <cmath>

using namespace std;

Schwefel222Function::Schwefel222Function() {

}

Schwefel222Function::~Schwefel222Function() {

}

float Schwefel222Function::getFitness(Individual* individual) {
	float sum = 0;
	float prod = 1;
	float iValue = 0;

	for (int i = 0; i < individual->getNumCells(); i++) {
		iValue = (*individual)[i].getValue();
		sum += abs(iValue);
		prod *= abs(iValue);
	}

	return sum + prod;
}

float Schwefel222Function::getMin() {
	return -10;
}

float Schwefel222Function::getMax() {
	return 10;
}

ostream& operator<<(ostream& os, const Schwefel222Function& cell) {
	os << "Schwefel222";
	return os;
}