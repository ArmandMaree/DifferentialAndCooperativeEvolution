#include "rosenbrockFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

RosenbrockFunction::RosenbrockFunction() {

}

RosenbrockFunction::~RosenbrockFunction() {

}

long double RosenbrockFunction::getFitness(Individual* individual) {
	long double sum = 0;
	long double iValue = 0;
	long double iPlusOneValue = 0;

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

string RosenbrockFunction::getName() const {
	return "Rosenbrock";
}

ostream& operator<<(ostream& os, const RosenbrockFunction& function) {
	os << function.getName();
	return os;
}