public interface OptimizationFunction {
	public double getFitness(Individual individual);
	public double getMin();
	public double getMax();

	@Override
	public String toString();
}