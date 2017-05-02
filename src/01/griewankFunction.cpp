#include "griewankFunction.h"

#include <cfloat>
#include <cmath>

using namespace std;

GriewankFunction::GriewankFunction() {

}

GriewankFunction::~GriewankFunction() {

}

float GriewankFunction::getFitness(Individual* individual) {
	float sumPart = 0;
	float prodPart = 1;
	float iValue = 0;

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

ostream& operator<<(ostream& os, const GriewankFunction& cell) {
	os << "Griewank";
	return os;
}