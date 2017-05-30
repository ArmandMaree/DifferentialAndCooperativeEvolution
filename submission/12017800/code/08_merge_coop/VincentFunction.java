public class VincentFunction implements OptimizationFunction {
	public double getFitness(Individual individual) {
		double sumPart = 0;
		double iValue;

		for (int i = 0; i < individual.getNumCells(); i++) {
			iValue = individual.getCell(i).getValue();
			sumPart += Math.sin(10 * Math.sqrt(iValue));
		}

		return -1.0 * (1 + sumPart);
	}

	public double getMin() {
		return 0.25;
	}
	
	public double getMax() {
		return 10.0;
	}

	@Override
	public String toString() {
		return "Vincent [" + getMin() + "," + getMax() + "]";
	}
}