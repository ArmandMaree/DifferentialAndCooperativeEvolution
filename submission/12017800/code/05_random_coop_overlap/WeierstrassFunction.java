public class WeierstrassFunction implements OptimizationFunction {
	public double getFitness(Individual individual) {
		double sumPart = 0;
		double innerSumPart = 0;
		double iValue;
		double a = 0.5;
		double b = 3.0;

		for (int i = 0; i < individual.getNumCells(); i++) {
			innerSumPart = 0;
			iValue = individual.getCell(i).getValue();

			for (int j = 1; j <= 20; j++) {
				innerSumPart += Math.pow(a, j) * Math.cos(2 * Math.PI * Math.pow(b, j) * (iValue + 0.5));
			}

			sumPart += innerSumPart;
		}

		innerSumPart = 0;

		for (int j = 1; j <= 20; j++) {
			innerSumPart += Math.pow(a, j) * Math.cos(Math.PI * Math.pow(b, j));
		}

		innerSumPart *= individual.getNumCells();
		return sumPart - innerSumPart;
	}

	public double getMin() {
		return -0.5;
	}
	
	public double getMax() {
		return 0.5;
	}

	@Override
	public String toString() {
		return "Weierstrass [" + getMin() + "," + getMax() + "]";
	}
}