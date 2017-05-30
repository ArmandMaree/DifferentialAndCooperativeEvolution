#include "vincentFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

VincentFunction::VincentFunction() {

}

VincentFunction::~VincentFunction() {

}

long double VincentFunction::getFitness(Individual* individual) {
	long double sum = 0;
	long double iValue = 0;

	for (int i = 0; i < individual->getNumCells(); i++) {
		iValue = (*individual)[i].getValue();
		sum += sin(10.0 * sqrt(iValue));
	}

	return -1.0 * (1.0 + sum);
}

float VincentFunction::getMin() {
	return 0.25;
}

float VincentFunction::getMax() {
	return 10;
}

string VincentFunction::getName() const {
	return "Vincent";
}

ostream& operator<<(ostream& os, const VincentFunction& function) {
	os << function.getName();
	return os;
}