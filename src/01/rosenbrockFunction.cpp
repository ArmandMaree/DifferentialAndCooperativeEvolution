#include "rosenbrockFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

RosenbrockFunction::RosenbrockFunction() {

}

RosenbrockFunction::~RosenbrockFunction() {

}

float RosenbrockFunction::getFitness(Individual* individual) {
	float sum = 0;
	float iValue = 0;
	float iPlusOneValue = 0;

	for (int i = 0; i < individual->getNumCells() - 1; i++) {
		iValue = (*individual)[i].getValue();
		iPlusOneValue = (*individual)[i + 1].getValue();
		sum += 100.0 * (iPlusOneValue - iValue * iValue) * (iPlusOneValue - iValue * iValue) + (iValue - 1.0) * (iValue - 1.0);
	}

	return sum;
}

float RosenbrockFunction::getMin() {
	return -30;
}

float RosenbrockFunction::getMax() {
	return 30;
}

ostream& operator<<(ostream& os, const RosenbrockFunction& cell) {
	os << "Rosenbrock";
	return os;
}