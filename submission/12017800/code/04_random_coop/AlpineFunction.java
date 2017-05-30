public class AlpineFunction implements OptimizationFunction {
	public double getFitness(Individual individual) {
		double sinPart = 1;
		double prodPart = 1;

		for (int i = 0; i < individual.getNumCells(); i++) {
			sinPart *= Math.sin(individual.getCell(i).getValue());
			prodPart *= individual.getCell(i).getValue();
		}

		if (prodPart < 0) {
			return Double.MAX_VALUE;
		}
		else {
			return sinPart * Math.sqrt(prodPart);
		}
	}

	public double getMin() {
		return -10.0;
	}
	
	public double getMax() {
		return 10.0;
	}

	@Override
	public String toString() {
		return "Alpine [" + getMin() + "," + getMax() + "]";
	}
}