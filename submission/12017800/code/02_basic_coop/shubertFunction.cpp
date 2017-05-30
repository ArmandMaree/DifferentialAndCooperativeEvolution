#include "shubertFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

ShubertFunction::ShubertFunction() {

}

ShubertFunction::~ShubertFunction() {

}

long double ShubertFunction::getFitness(Individual* individual) {
	long double sum = 0;
	long double prod = 1;
	long double iValue = 0;

	for (int i = 0; i < individual->getNumCells(); i++) {
		iValue = (*individual)[i].getValue();
		sum = 0;

		for (int j = 1; j <= 5; j++) {
			sum += j * cos((j + 1.0) * iValue + j);
		}

		prod *= sum;
	}

	return prod;
}

float ShubertFunction::getMin() {
	return -10;
}

float ShubertFunction::getMax() {
	return 10;
}

string ShubertFunction::getName() const {
	return "Shubert";
}

ostream& operator<<(ostream& os, const ShubertFunction& function) {
	os << function.getName();
	return os;
}