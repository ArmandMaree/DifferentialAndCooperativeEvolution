import java.util.Random;

public class Cell {
	private double value;
	private final double min;
	private final double max;
	private Random randomGenerator = new Random();

	public Cell(double min, double max) {
		this.min = min;
		this.max = max;
		this.value = randomGenerator.nextDouble() * (max - min) + min;
	}

	public Cell(double min, double max, double value) {
		this.min = min;
		this.max = max;
		this.value = value;
	}

	public Cell(Cell other) {
		this.min = other.min;
		this.max = other.max;
		this.value = other.value;
	}

	public void setValue(double value) {
		if (value < min) {
			this.value = value;
		}
		else if (value > max) {
			this.value = value;
		}
		else {
			this.value = value;
		}
	}

	public double getValue() {
		return value;
	}

	public double getMin() {
		return min;
	}

	public double getMax() {
		return max;
	}

	public Cell clone() {
		return new Cell(this);
	}

	@Override
	public String toString() {
		return value + "";
	}
}