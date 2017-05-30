public class SalomonFunction implements OptimizationFunction {
	public double getFitness(Individual individual) {
		double sumPart = 0;
		double iValue;

		for (int i = 0; i < individual.getNumCells(); i++) {
			iValue = individual.getCell(i).getValue();
			sumPart += Math.pow(iValue, 2);
		}

		return -1.0 * Math.cos(2 * Math.PI * sumPart) + 0.1 * Math.sqrt(sumPart) + 1;
	}

	public double getMin() {
		return -100.0;
	}
	
	public double getMax() {
		return 100.0;
	}

	@Override
	public String toString() {
		return "Salomon [" + getMin() + "," + getMax() + "]";
	}
}