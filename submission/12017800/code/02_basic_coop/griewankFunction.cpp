#include "griewankFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

GriewankFunction::GriewankFunction() {

}

GriewankFunction::~GriewankFunction() {

}

long double GriewankFunction::getFitness(Individual* individual) {
	long double sumPart = 0;
	long double prodPart = 1;
	long double iValue = 0;

	for (int i = 0; i < individual->getNumCells(); i++) {
		iValue = (*individual)[i].getValue();
		sumPart += iValue * iValue;
		prodPart *= cos(iValue / sqrt(i + 1.0));
	}

	return 1.0 + (1.0 / 4000.0) * sumPart - prodPart;
}

float GriewankFunction::getMin() {
	return -600;
}

float GriewankFunction::getMax() {
	return 600;
}

string GriewankFunction::getName() const {
	return "Griewank";
}

ostream& operator<<(ostream& os, const GriewankFunction& function) {
	os << function.getName();
	return os;
}