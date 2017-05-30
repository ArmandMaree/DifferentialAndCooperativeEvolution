#include "schwefel222Function.h"

#include <cfloat>
#include <cmath>

using namespace std;

Schwefel222Function::Schwefel222Function() {

}

Schwefel222Function::~Schwefel222Function() {

}

long double Schwefel222Function::getFitness(Individual* individual) {
	long double sum = 0;
	long double prod = 1;
	long double iValue = 0;

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

string Schwefel222Function::getName() const {
	return "Schwefel222";
}

ostream& operator<<(ostream& os, const Schwefel222Function& function) {
	os << function.getName();
	return os;
}