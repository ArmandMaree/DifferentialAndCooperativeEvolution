#include "eggholderFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

EggholderFunction::EggholderFunction() {

}

EggholderFunction::~EggholderFunction() {

}

float EggholderFunction::getFitness(Individual* individual) {
	float sum = 0;
	float part1 = 0;
	float part2 = 0;

	for (int i = 0; i < individual->getNumCells() - 1; i++) {
		float iValue = (*individual)[i].getValue();
		float iPlusOneValue = (*individual)[i + 1].getValue();
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

ostream& operator<<(ostream& os, const EggholderFunction& cell) {
	os << "Eggholder";
	return os;
}