#include "eggholderFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

EggholderFunction::EggholderFunction() {

}

EggholderFunction::~EggholderFunction() {

}

long double EggholderFunction::getFitness(Individual* individual) {
	long double sum = 0;
	long double part1 = 0;
	long double part2 = 0;

	for (int i = 0; i < individual->getNumCells() - 1; i++) {
		long double iValue = (*individual)[i].getValue();
		long double iPlusOneValue = (*individual)[i + 1].getValue();
		part1 = -1.0 * (iPlusOneValue + 47.0) * sin(sqrt(abs(iPlusOneValue + iValue / 2.0 + 47.0)));
		part2 = sin(sqrt(abs(iValue - (iPlusOneValue + 47.0))) * (-1.0 * iValue));
		sum += part1 + part2;
	}

	return sum;
}

float EggholderFunction::getMin() {
	return -512;
}

float EggholderFunction::getMax() {
	return 512;
}

string EggholderFunction::getName() const {
	return "Eggholder";
}

ostream& operator<<(ostream& os, const EggholderFunction& function) {
	os << function.getName();
	return os;
}