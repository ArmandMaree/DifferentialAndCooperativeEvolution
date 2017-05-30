import java.util.List;
import java.util.Random;

public class Mutation {
	private Random randomGenerator = new Random();
	private double scaleVector;

	public Mutation(double scaleVector) {
		this.scaleVector = scaleVector;
	}

	public Individual getTrial(List<Individual> population, int target) {
		double max = population.get(0).getCell(0).getMax();
		double min = population.get(0).getCell(0).getMin();
		Individual trial = new Individual(population.get(0).getNumCells(), min, max);
		
		int p1 = target;
		int p2 = target;

		while (p1 == target) {
			p1 = randomGenerator.nextInt(population.size());
		}

		while (p2 == target || p2 == p1) {
			p2 = randomGenerator.nextInt(population.size());
		}

		for (int i = 0; i < population.get(0).getNumCells(); i++) {
			double targetCell = population.get(target).getCell(i).getValue();
			double p1Cell = population.get(p1).getCell(i).getValue();
			double p2Cell = population.get(p2).getCell(i).getValue();
			trial.getCell(i).setValue(targetCell + (p1Cell - p2Cell) * scaleVector);
		}

		return trial;
	}
}