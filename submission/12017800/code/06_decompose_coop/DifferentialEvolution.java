import java.util.ArrayList;
import java.util.List;

public class DifferentialEvolution implements Runnable {
	private Crossover crossover;
	private Mutation mutation;
	private OptimizationFunction optimizationFunction;
	private List<BestIndividual> mainPopulation;
	private List<Integer> indices = null;
	private int iterationCounter = 0;

	public DifferentialEvolution(Crossover crossover, Mutation mutation, OptimizationFunction optimizationFunction, List<BestIndividual> mainPopulation) {
		this.crossover = crossover;
		this.mutation = mutation;
		this.optimizationFunction = optimizationFunction;
		this.mainPopulation = mainPopulation;
	}

	public void setIndices(List<Integer> indices) {
		this.indices = indices;
	}

	public void setIterationCounter(int iterationCounter) {
		this.iterationCounter = iterationCounter;
	}

	public void run() {
		try {
			double bestFitness = Double.MAX_VALUE;
			List<Individual> population = new ArrayList<>();

			for(; iterationCounter >= 0; iterationCounter--) {
				for (int i = 0; i < mainPopulation.size(); i++) {
					List<Cell> cells = new ArrayList<>();

					for (int j = 0; j < indices.size(); j++) {
						int index = indices.get(j);
						cells.add(mainPopulation.get(i).getCell(index).clone());
					}

					population.add(new Individual(cells));
				}
				
				createNextGeneration(population);
			}
			// indices = null;
		}
		catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public void createNextGeneration(List<Individual> population) {
		for (int i = 0; i < mainPopulation.size(); i++) {
			List<Individual> parents = new ArrayList<>();
			parents.add(population.get(i)); // target
			parents.add(mutation.getTrial(population, i)); // trial
			Individual child = crossover.performCrossover(parents);
			mainPopulation.get(i).compareAndSet(child, indices);
		}
	}

}