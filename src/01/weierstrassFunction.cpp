#include "weierstrassFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

WeierstrassFunction::WeierstrassFunction() {

}

WeierstrassFunction::~WeierstrassFunction() {

}

float WeierstrassFunction::getFitness(Individual* individual) {
	float sum1 = 0;
	float sum2 = 0;
	float iValue = 0;
	float a = 0.5;
	float b = 3.0;

	for (int i = 0; i < individual->getNumCells(); i++) {
		iValue = (*individual)[i].getValue();
		sum2 = 0;

		for (int j = 1; j <= 20; j++) {
			sum2 += pow(a, j) * cos(2 * M_PI * pow(b, j) * (iValue + 0.5));
		}

		sum1 += sum2;
	}

	sum2 = 0;

	for (int j = 1; j <= 20; j++) {
		sum2 += pow(a, j) * cos(2 * M_PI * pow(b, j));
	}

	sum1 += individual->getNumCells() * sum2;

	return -1.0 * (1.0 + sum1);
}

float WeierstrassFunction::getMin() {
	return -0.5;
}

float WeierstrassFunction::getMax() {
	return 0.5;
}

ostream& operator<<(ostream& os, const WeierstrassFunction& cell) {
	os << "Weierstrass";
	return os;
}