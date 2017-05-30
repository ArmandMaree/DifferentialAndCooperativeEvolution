#include "weierstrassFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

WeierstrassFunction::WeierstrassFunction() {

}

WeierstrassFunction::~WeierstrassFunction() {

}

long double WeierstrassFunction::getFitness(Individual* individual) {
	long double sum1 = 0;
	long double sum2 = 0;
	long double iValue = 0;
	long double a = 0.5;
	long double b = 3.0;

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

	return sum1 - individual->getNumCells() * sum2;
}

float WeierstrassFunction::getMin() {
	return -0.5;
}

float WeierstrassFunction::getMax() {
	return 0.5;
}

string WeierstrassFunction::getName() const {
	return "Weierstrass";
}

ostream& operator<<(ostream& os, const WeierstrassFunction& function) {
	os << function.getName();
	return os;
}