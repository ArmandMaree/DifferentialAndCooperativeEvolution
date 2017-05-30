import java.util.List;

public interface Crossover {
	public Individual performCrossover(List<Individual> parents);
}