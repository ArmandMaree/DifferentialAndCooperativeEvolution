import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class CooperativeDE {
	private Crossover crossover;
	private List<DifferentialEvolution> des = new ArrayList<>();
	private List<BestIndividual> mainPopulation = new ArrayList<>();
	private Mutation mutation;
	private int numDimensions;
	private int numInstances;
	private OptimizationFunction optimizationFunction;
	private int populationSize = 30;
	private Random randomGenerator = new Random();

	public CooperativeDE(Crossover crossover, Mutation mutation, OptimizationFunction optimizationFunction, int numInstances, int numDimensions) {
		this.crossover = crossover;
		this.mutation = mutation;
		this.optimizationFunction = optimizationFunction;
		this.numInstances = numInstances;
		this.numDimensions = numDimensions;

		for (int i = 0; i < populationSize; i++) {
			mainPopulation.add(new BestIndividual(numDimensions, optimizationFunction));
		}

		for (int i = 0; i < numInstances; i++) {
			des.add(new DifferentialEvolution(crossover, mutation, optimizationFunction, mainPopulation));
		}
	}

	public int optimize(boolean showProgress) {
		int currentIteration = 0;
		int maxIteration = 5000;
		int noImprovementIteration = 0;
		int maxNoImprovementIteration = 500;
		int numDimensionsPerInstance = numDimensions / numInstances;
		double bestFitness = Double.MAX_VALUE;
		List<Thread> deThreads = new ArrayList<>();

		while (currentIteration < maxIteration && !Double.isInfinite(bestFitness)) { // && noImprovementIteration < maxNoImprovementIteration
			List<Integer> indices = new ArrayList<>();

			for (int i = 0; i < numDimensions; i++) {
				indices.add(i);
			}

			for (int i = 0; i < numInstances; i++) {
				List<Integer> indicesForDe = new ArrayList<>();

				for (int j = 0; j < numDimensionsPerInstance; j++) {
					int index = randomGenerator.nextInt(indices.size());
					indicesForDe.add(indices.remove(index));
				}

				des.get(i).setIndices(indicesForDe);
				Thread t = new Thread(des.get(i));
				deThreads.add(t);
				t.start();
			}

			for (int i = 0; i < deThreads.size(); i++) {
				try {
					deThreads.get(i).join();
				}
				catch (InterruptedException e) {
					System.exit(1);
				}
			}

			float bestInIteration = (float)optimizationFunction.getFitness(getBestIndividual());

			if (bestInIteration < bestFitness) {
				noImprovementIteration = 0;
				bestFitness = bestInIteration;
			}
			else {
				noImprovementIteration++;
			}

			currentIteration++;

			if (showProgress && currentIteration % 100 == 0) {
				System.out.print("\rAfter " + currentIteration + " the best fitness is: " + bestFitness + ".              ");
			}
		}

		return currentIteration;
	}

	public Individual getBestIndividual() {
		int bestIndex = 0;
		double bestFitness = optimizationFunction.getFitness(mainPopulation.get(0));

		for (int i = 1; i < mainPopulation.size(); i++) {
			double canidateBest = optimizationFunction.getFitness(mainPopulation.get(i));

			if (canidateBest < bestFitness) {
				bestFitness = canidateBest;
				bestIndex = i;
			}
		}

		return mainPopulation.get(bestIndex);
	}
}