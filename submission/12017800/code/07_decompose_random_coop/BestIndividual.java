import java.util.concurrent.locks.ReentrantLock;
import java.util.ArrayList;
import java.util.List;

public class BestIndividual extends Individual {
	private Individual backup;
	private double fitness;
	private OptimizationFunction function;
	private final ReentrantLock mutex = new ReentrantLock();

	public BestIndividual(int numCells, OptimizationFunction function) {
		super(numCells, function.getMin(), function.getMax());
		this.backup = super.clone();
		this.function = function;
		this.fitness = function.getFitness(this);
	}

	public BestIndividual(BestIndividual other) {
		super((Individual)other);
		this.backup = super.clone();
		this.function = other.function;
		this.fitness = other.fitness;
	}

	public double compareAndSet(Individual individual, List<Integer> indices) {
		mutex.lock();
		Individual tmpIndividual = new Individual(this);

		for (int i = 0; i < indices.size(); i++) {
			int index = indices.get(i);
			tmpIndividual.getCell(index).setValue(individual.getCell(i).getValue());
		}

		double tmpFitness = function.getFitness(tmpIndividual);

		if (tmpFitness < this.fitness) {

			for (int i = 0; i < indices.size(); i++) {
				int index = indices.get(i);
				super.getCell(index).setValue(individual.getCell(i).getValue());
			}

			tmpFitness = function.getFitness(tmpIndividual);

			if (tmpFitness < this.fitness) {
				fitness = tmpFitness;
				backup = super.clone();
			}
			else {
				restore(backup);
			}

		}

		mutex.unlock();
		return tmpFitness;
	}

	public void restore(Individual individual) {
		cells = new ArrayList<>();

		for (int i = 0; i < individual.getNumCells(); i++) {
			cells.add(individual.getCell(i).clone());
		}
	}
}