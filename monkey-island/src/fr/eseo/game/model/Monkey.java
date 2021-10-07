package fr.eseo.game.model;

/**
 * Class Monkey.
 *
 * @author Kim Belassen
 */
public abstract class Monkey extends Thread implements Character {

	/* ATTRIBUTES */

	/**
	 * Cell of Character.
	 */
	private Cell cell;

	/**
	 * Speed of monkey.
	 */
	private Integer speed;

	/* CONSTRUCTORS */

	/**
	 * Constructor.
	 *
	 * @param speed
	 *            Speed of a monkey.
	 * @param cell
	 *            cell of the monkey
	 */
	public Monkey(Integer speed, Cell cell) {
		this.speed = speed;
		this.cell = cell;
	}

	/* METHODS */
	/**
	 * Method canMove.
	 * 
	 * @param cell
	 *            the cell where it goes.
	 * @return a boolean
	 */
	@Override
	public Boolean canMove(Cell cell) {
		return cell != null && cell.canAccess()
				&& (cell.getCharacter() == null || cell.getCharacter() instanceof Pirate)
				&& cell.getColumn() < cell.getIsland().getColumns();
	}

	@Override
	public void moveTo(Cell cell) {
		this.meetCharacter(cell.getCharacter());
		this.cell.setCharacter(null);
		this.cell = cell;
		this.cell.setCharacter(this);
	}

	@Override
	public void meetCharacter(Character character) {
		if (character != null && character instanceof Pirate) {
			Pirate pirate = (Pirate) character;
			pirate.setEnergy(Pirate.MIN_ENERGY);
			this.getCell().getIsland().removePirate(pirate.getId());

		}
	}

	@Override
	public String toString() {
		return this.cell.getColumn() + "-" + this.getCell().getRow();
	}

	/* ACCESSORS */

	/**
	 * Getter cell.
	 *
	 * @return cell
	 */
	public Cell getCell() {
		return this.cell;
	}

	/**
	 * Setter cell.
	 *
	 * @param cell
	 *            Cell of the monkey.
	 */
	public void setCell(Cell cell) {
		this.cell = cell;
	}

	/**
	 * Getter speed.
	 *
	 * @return speed
	 */
	public Integer getSpeed() {
		return this.speed;
	}

	/**
	 * Setter speed.
	 *
	 * @param speed
	 *            is the speed of a monkey.
	 */
	public void setSpeed(Integer speed) {
		this.speed = speed;
	}

}
