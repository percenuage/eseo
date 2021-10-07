package fr.eseo.game.model;

import fr.eseo.game.network.MonkeyIsland;


/**
 * Rhum class.
 *
 * @author Valentin Cosson
 */
public class Rhum extends Element {

	/* ATTRIBUTES */
	/**
	 * id of rhum.
	 */
	private Integer id;
	/**
	 * Time to reappear after the rhum is found.
	 */
	public static final Integer REAPPEAR_TIME = Integer
			.valueOf(MonkeyIsland.CONFIGURATION.getString("RHUM_REAPPEAR_TIME"));

	/**
	 * Amount of energy give by the rhum.
	 */
	public static final Integer ENERGY_RECOVER = Integer
			.valueOf(MonkeyIsland.CONFIGURATION.getString("RHUM_ENERGY_RECOVER"));

	/* CONSTRUCTORS */
	/**
	 * Constructor for rhum, id is a hashcode.
	 * 
	 * @param cell
	 *            cell where the rhum is.
	 */
	public Rhum(Cell cell) {
		super(true, false, cell);
	}

	/* METHODS */

	@Override
	public String toString() {
		return this.getCell().getColumn() + "-" + this.getCell().getRow() + "-" + this.getVisibility();
	}

	/**
	 * Tostring method.
	 * 
	 * @return the id and the visibility.
	 */
	public String toStringWithId() {
		return this.id + "-" + this.getVisibility();
	}

	/* ACCESSORS */
	/**
	 * getId of the rhum.
	 * 
	 * @return the id.
	 */
	public Integer getId() {
		return this.id;
	}

	/**
	 * setId.
	 * 
	 * @param id
	 *            the id of the rhum.
	 */
	public void setId(Integer id) {
		this.id = id;
	}

}
