#include "schaffer6Function.h"

#include <cfloat>
#include <cmath>

using namespace std;

Schaffer6Function::Schaffer6Function() {

}

Schaffer6Function::~Schaffer6Function() {

}

float Schaffer6Function::getFitness(Individual* individual) {
	float sum = 0;
	float numerator = 0;
	float denomenator = 0;
	float iValue = 0;
	float iPlusOneValue = 0;

	for (int i = 0; i < individual->getNumCells() - 1; i++) {
		iValue = (*individual)[i].getValue();
		iPlusOneValue = (*individual)[i + 1].getValue();
		numerator = pow(sin(iValue * iValue + iPlusOneValue * iPlusOneValue), 2);
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

ostream& operator<<(ostream& os, const Schaffer6Function& cell) {
	os << "Schaffer6";
	return os;
}