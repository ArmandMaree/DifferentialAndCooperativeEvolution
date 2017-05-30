import java.util.ArrayList;
import java.util.List;

public class Individual {
	List<Cell> cells = new ArrayList<>();

	public Individual(List<Cell> cells) {
		this.cells = cells;
	}

	public Individual(int numCells, double min, double max) {
		for (int i = 0; i < numCells; i++) {
			cells.add(new Cell(min, max));
		}
	}

	public Individual(Individual other) {
		for (int i = 0; i < other.getNumCells(); i++) {
			cells.add(other.getCell(i).clone());
		}
	}

	public Cell getCell(int index) {
		return cells.get(index);
	}

	public int getNumCells() {
		return cells.size();
	}

	public Individual clone() {
		return new Individual(this);
	}

	@Override
	public String toString() {
		String s = "";

		for (int i = 0; i < cells.size(); i ++) {
			if (i == 0) {
				s += "[" + cells.get(i);
			}
			else {
				s += "," + cells.get(i);
			}
		}

		return s;
	}
}