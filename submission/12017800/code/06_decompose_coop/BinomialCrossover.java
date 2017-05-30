import java.util.List;
import java.util.Random;

public class BinomialCrossover implements Crossover {
	private double crossoverProbability;
	private Random randomGenerator = new Random();

	public BinomialCrossover(double crossoverProbability) {
		this.crossoverProbability = crossoverProbability;
	}

	public Individual performCrossover(List<Individual> parents) {
		double max = parents.get(0).getCell(0).getMax();
		double min = parents.get(0).getCell(0).getMin();
		int indexOfForceChange = randomGenerator.nextInt(parents.get(0).getNumCells());

		Individual offspring = new Individual(parents.get(0).getNumCells(), min, max);

		for (int i = 0; i < parents.get(0).getNumCells(); i++) {
			if (i == indexOfForceChange) {
				offspring.getCell(i).setValue(parents.get(1).getCell(i).getValue());
			}
			else if (randomGenerator.nextDouble() < crossoverProbability) {
				offspring.getCell(i).setValue(parents.get(1).getCell(i).getValue());
			}
			else {
				offspring.getCell(i).setValue(parents.get(0).getCell(i).getValue());
			}
		}

		return offspring;
	}
}