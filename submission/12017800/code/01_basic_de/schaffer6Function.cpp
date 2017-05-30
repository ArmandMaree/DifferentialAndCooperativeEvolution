#include "schaffer6Function.h"

#include <cfloat>
#include <cmath>

using namespace std;

Schaffer6Function::Schaffer6Function() {

}

Schaffer6Function::~Schaffer6Function() {

}

long double Schaffer6Function::getFitness(Individual* individual) {
	long double sum = 0;
	long double numerator = 0;
	long double denomenator = 0;
	long double iValue = 0;
	long double iPlusOneValue = 0;

	for (int i = 0; i < individual->getNumCells() - 1; i++) {
		iValue = (*individual)[i].getValue();
		iPlusOneValue = (*individual)[i + 1].getValue();
		numerator = pow(sin(iValue * iValue + iPlusOneValue * iPlusOneValue), 2) - 0.5;
		denomenator = pow(1.0 + 0.001 * (iValue * iValue + iPlusOneValue * iPlusOneValue), 2);

		if (denomenator == 0 ) {
			return FLT_MAX;
		}

		sum += 0.5 + numerator / denomenator;
	}

	return sum;
}

float Schaffer6Function::getMin() {
	return -100;
}

float Schaffer6Function::getMax() {
	return 100;
}

string Schaffer6Function::getName() const {
	return "Schaffer6";
}

ostream& operator<<(ostream& os, const Schaffer6Function& function) {
	os << function.getName();
	return os;
}