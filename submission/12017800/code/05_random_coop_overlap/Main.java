import java.util.ArrayList;
import java.util.List;

class Main {
	public static void main(String[] args) {
		// test();
		List<OptimizationFunction> functions = new ArrayList<>();
		functions.add(new AlpineFunction());
		// functions.add(new EggholderFunction());
		// functions.add(new GriewankFunction());
		// functions.add(new NorwegianFunction());
		// functions.add(new RosenbrockFunction());
		functions.add(new SalomonFunction());
		// functions.add(new Schaffer6Function());
		// functions.add(new Schwefel222Function());
		// functions.add(new ShubertFunction());
		functions.add(new VincentFunction());
		// functions.add(new WeierstrassFunction());

		List<Double> kValues = new ArrayList<>();
		kValues.add(0.1);
		kValues.add(0.3);
		kValues.add(0.5);

		List<Double> overlapProbability = new ArrayList<>();
		overlapProbability.add(0.05);
		overlapProbability.add(0.1);
		overlapProbability.add(0.2);

		while(functions.size() != 0) {
			System.out.println("\033[33mSTART HERE\033[0m");
			System.out.println("Function: " + functions.get(0));
			
			for (int i = 0; i < kValues.size(); i++) {
				for (int j = 0; j < overlapProbability.size(); j++) {
					optimizeFunction(functions.get(0), new Integer(args[0]), kValues.get(i), overlapProbability.get(j), new Boolean(args[1]));
				}
			}

			functions.remove(0);
			System.out.println("\033[33mEND HERE\033[0m");
		}
	}

	public static void optimizeFunction(OptimizationFunction function, int numDimensions, double kValue, double overlapProbability, boolean showProgress) {
		List<Double> bestValues = new ArrayList<>();
		int numRunsPerFunction = 30;
		double crossoverProbability = 0.5;
		double scaleVector = 0.5;
		int numDimensionsPerInstance = (int)(1.0 * numDimensions * kValue);
		int numInstances = numDimensions / numDimensionsPerInstance;
		System.out.println("numDimensions: " + numDimensions);
		System.out.println("numDimensionsPerInstance: " + numDimensionsPerInstance);
		System.out.println("numInstances: " + numInstances);
		System.out.println("overlapProbability: " + overlapProbability);

		Crossover crossover = new BinomialCrossover(crossoverProbability);
		Mutation mutation = new Mutation(scaleVector);

		for (int i = 0; i < numRunsPerFunction; i++) { // execute function 30 times.
			System.out.println("\033[32mRun #" + i + "\033[0m");
			CooperativeDE coopDE = new CooperativeDE(crossover, mutation, function, numInstances, numDimensions, overlapProbability);
			int numIterations = coopDE.optimize(showProgress);

			Individual bestIndividual = coopDE.getBestIndividual();

			if (bestIndividual != null) {
				if (showProgress) {
					System.out.println("\r                                                                                   \r");
				}
		
				System.out.println("\tBest Individual: " + bestIndividual);
				double fitness = function.getFitness(bestIndividual);
				System.out.println("\tFitness: " + fitness);
				System.out.println("\tNumber of Iterations: " + numIterations);
				bestValues.add(fitness);
			}
			else {
				System.out.println("\r\033[31mNo solution could be found.\033[0m                                                  ");
			}
		}

		System.out.println("\033[34mStatistics:\033[0m");
		System.out.println("\tAverage:            " + calculateAverage(bestValues));
		// System.out.println("\tStandard Deviation: " + calculateStandardDeviation(bestValues));
	}

	public static double calculateAverage(List<Double> values) {
		double sum = 0;

		for (int i = 0; i < values.size(); i++) {
			sum += values.get(i);
		}

		return sum / values.size();
	}

	public static double calculateStandardDeviation(List<Double> values) {
		double sum = 0;
		double average = calculateAverage(values);

		for (int i = 0; i < values.size(); i++) {
			sum += Math.pow(values.get(i) - average, 2);
		}

		return Math.sqrt(sum / (values.size() - 1));
	}
}