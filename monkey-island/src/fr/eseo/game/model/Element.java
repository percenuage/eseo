package fr.eseo.game.model;

/**
 * Element abstract class.
 *
 * @author Kim Belassen
 */
public abstract class Element {

	/* ATTRIBUTES */
	/**
	 * Boolean to know if hidden or not.
	 */
	private Boolean hidden;
	/**
	 * Boolean to know if found or not.
	 */
	private Boolean found;
	/**
	 * Attribute cell.
	 */
	private Cell cell;

	/* CONSTRUCTORS */
	/**
	 * Constructor of Element.
	 * 
	 * @param hidden
	 *            hidden or not.
	 * @param found
	 *            found or not.
	 * @param cell
	 *            cell where is the element.
	 */
	public Element(Boolean hidden, Boolean found, Cell cell) {
		this.hidden = hidden;
		this.found = found;
		this.cell = cell;
	}

	/* METHODS */
	/**
	 * Know if the element is visible or not.
	 * 
	 * @return 1 or 0.
	 */
	public Integer getVisibility() {
		return this.isHidden() ? 0 : 1;
	}

	/* ACCESSORS */
	/**
	 * Know if the element is hidden.
	 * 
	 * @return a boolean.
	 */
	public Boolean isHidden() {
		return this.hidden;
	}

	/**
	 * SetHidden of an element.
	 * 
	 * @param hidden
	 *            hidden or not.
	 */
	public void setHidden(Boolean hidden) {
		this.hidden = hidden;
	}

	/**
	 * Know if the element is found.
	 * 
	 * @return a boolean
	 */
	public Boolean isFound() {
		return this.found;
	}

	/**
	 * SetFound.
	 * 
	 * @param found
	 *            found or not.
	 */
	public void setFound(Boolean found) {
		this.found = found;
	}

	/**
	 * getCell.
	 * 
	 * @return a cell.
	 */
	public Cell getCell() {
		return this.cell;
	}
	/**
	 * setCell.
	 * @param cell the cell of an element.
	 */
	public void setCell(Cell cell) {
		this.cell = cell;
	}
}
