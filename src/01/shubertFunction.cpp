#include "shubertFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

ShubertFunction::ShubertFunction() {

}

ShubertFunction::~ShubertFunction() {

}

float ShubertFunction::getFitness(Individual* individual) {
	float sum = 0;
	float prod = 1;
	float iValue = 0;

	for (int i = 0; i < individual->getNumCells(); i++) {
		iValue = (*individual)[i].getValue();
		sum = 0;

		for (int j = 0; j < 5; j++) {
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

ostream& operator<<(ostream& os, const ShubertFunction& cell) {
	os << "Shubert";
	return os;
}