import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class CooperativeDE {
	private Crossover crossover;
	private List<BestIndividual> mainPopulation = new ArrayList<>();
	private Mutation mutation;
	private int numDimensions;
	private int tValue;
	private int numInstancePower = 0;
	private OptimizationFunction optimizationFunction;
	private int populationSize = 30;
	private Random randomGenerator = new Random();

	public CooperativeDE(Crossover crossover, Mutation mutation, OptimizationFunction optimizationFunction, int tValue, int numDimensions) {
		this.crossover = crossover;
		this.mutation = mutation;
		this.optimizationFunction = optimizationFunction;
		this.tValue = tValue;
		this.numDimensions = numDimensions;

		for (int i = 0; i < populationSize; i++) {
			mainPopulation.add(new BestIndividual(numDimensions, optimizationFunction));
		}
	}

	public int optimize(boolean showProgress) {
		int currentIteration = 0;
		int maxIteration = 5000;
		int noImprovementIteration = 0;
		int maxNoImprovementIteration = 500;
		double bestFitness = Double.MAX_VALUE;

		while (currentIteration < maxIteration && !Double.isInfinite(bestFitness)) { // && noImprovementIteration < maxNoImprovementIteration
			int numInstances = (int)Math.pow(2, numInstancePower);
			int numDimensionsPerInstance = (int)(numDimensions / numInstances);

			if (numDimensionsPerInstance == 1) {
				numInstances = numDimensions;
			}

			List<DifferentialEvolution> des = new ArrayList<>();
			List<Thread> deThreads = new ArrayList<>();
			List<Integer> indices = new ArrayList<>();

			for (int i = 0; i < numDimensions; i++) {
				indices.add(i);
			}

			for (int i = 0; i < numInstances; i++) {
				List<Integer> indicesForDe = new ArrayList<>();

				for (int j = 0; j < numDimensionsPerInstance; j++) {
					int index = 0;
					indicesForDe.add(indices.remove(index));
				}

				if (indicesForDe.size() > 0) {
					des.add(new DifferentialEvolution(crossover, mutation, optimizationFunction, mainPopulation));
					des.get(i).setIndices(indicesForDe);

					Thread t = new Thread(des.get(i));

					if (maxIteration - currentIteration < tValue) {
						des.get(i).setIterationCounter(maxIteration - currentIteration);
					}
					else {
						des.get(i).setIterationCounter(tValue);
					}
					
					deThreads.add(t);
					t.start();
				}
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

			currentIteration += tValue;
			numInstancePower++;

			if (showProgress && currentIteration % 100 == 0) {
				System.out.print("\rAfter " + currentIteration + " generations, numInstances: " + numInstances + " fitness: " + bestFitness + " numDimensionsPerInstance: " + numDimensionsPerInstance + ".           ");
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