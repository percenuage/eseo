package fr.eseo.game.model;

import fr.eseo.game.command.CommandEnum;
import fr.eseo.game.network.Communication;
import fr.eseo.game.network.MonkeyIsland;

import java.util.List;
import java.util.Observable;
import java.util.Observer;

/**
 * Class Pirate.
 *
 * @author Kim Belassen
 *
 */
public class Pirate implements Character, Observer {

	/* ATTRIBUTES */

	/**
	 * Cell of Character.
	 */
	private Cell cell;

	/**
	 * Id of pirate.
	 */
	private Integer id;

	/**
	 * Energy of pirate.
	 */
	private Integer energy;

	/**
	 * Min energy of pirate.
	 */
	public static final Integer MIN_ENERGY = 0;

	/**
	 * Max energy of pirate.
	 */
	public static final Integer MAX_ENERGY =
			Integer.valueOf(MonkeyIsland.CONFIGURATION.getString("PIRATE_MAX_ENERGY"));

	/* CONSTRUCTORS */

	/**
	 * Constructor 2 params.
	 *
	 * @param id
	 *            is the id of pirate.
	 * @param cell
	 *            is the cell of pirate.
	 */
	public Pirate(Integer id, Cell cell) {
		this.id = id;
		this.cell = cell;
		this.energy = MAX_ENERGY;
	}

	/* METHODS */

	/**
	 * Check if the pirate is dead or not.
	 *
	 * @return true or false.
	 */
	public Boolean isDead() {
		return this.energy <= MIN_ENERGY;
	}

	/**
	 * Check if a pirate found an element.
	 *
	 * @param element
	 *            can be a rhum or a treasure.
	 */
	public void foundElement(Element element) {
		if (element != null) {
			if (element instanceof Rhum) {
				element.setHidden(true);
				this.setEnergy(this.energy + Rhum.ENERGY_RECOVER);
				this.cell.getIsland().notifyClients(CommandEnum.RHUM, element);
			} else if (element instanceof Treasure) {
				element.setHidden(false);
				this.cell.getIsland().notifyClients(CommandEnum.TREASURE, element);
				this.cell.getIsland().newGame();
			}
			element.setFound(true);
		}
	}

	@Override
	public Boolean canMove(Cell cell) {
		return cell != null && cell.canAccess()
				&& (cell.getCharacter() == null || cell.getCharacter() instanceof Monkey)
				&& cell.getColumn() < cell.getIsland().getColumns();
	}

	@Override
	public void moveTo(Cell cell) {
		this.energy--;
		this.foundElement(cell.getElement());
		this.meetCharacter(cell.getCharacter());
		this.cell.setCharacter(null);
		this.cell = cell;
		this.cell.setCharacter(this);
		if (this.isDead()) {
			this.getCell().getIsland().removePirate(this.id);
		}
	}

	@Override
	public void meetCharacter(Character character) {
		if (character != null) {
			this.setEnergy(Pirate.MIN_ENERGY);
			this.getCell().getIsland().removePirate(this.id);
		}
	}

	@Override
	public void update(Observable o, Object arg) {
		String message = null;
		List<Monkey> monkeys = null;
		Pirate pirate = null;

		switch (Communication.pendingCommand) {
			case NEW_PIRATE_SERVER:
				pirate = (Pirate) arg;
				if (!this.equals(pirate)) {
					message = pirate.toString();
				}
				break;
			case MOVE_PIRATE_SERVER:
				pirate = (Pirate) arg;
				if (!this.equals(pirate)) {
					message = pirate.toString();
				}
				break;
			case REMOVE_PIRATE:
				pirate = (Pirate) arg;
				message = pirate.getId().toString();
				break;
			case CRAZY_MONKEYS:
				monkeys = this.getCell().getIsland().getCrazyMonkeys();
				break;
			case HUNTER_MONKEYS:
				monkeys = this.getCell().getIsland().getHunterMonkeys();
				break;
			case RHUM:
				Rhum rhum = (Rhum) arg;
				message = rhum.toStringWithId();
				break;
			case TREASURE:
				Treasure treasure = (Treasure) arg;
				message = treasure.toString();
				break;
			case NEW_GAME:
				message = "";
				break;
			default:
				break;
		}

		Communication com = MonkeyIsland.coms.get(this.id);

		if (com != null && message != null) {
			com.sendMessage(Communication.pendingCommand, message);
		} else if (com != null && monkeys != null) {
			com.sendMessage(Communication.pendingCommand, monkeys);
		}
	}

	@Override
	public String toString() {
		return this.id + "-" + this.cell.getColumn() + "-" + this.cell.getRow();
	}

	/**
	 * ToString with pirate's energy.
	 * @return string
     */
	public String toStringWithEnergy() {
		return this.cell.getColumn() + "-" + this.cell.getRow() + "-" + this.getEnergy();
	}

	/**
	 * ToString with pirate's energy and pirate's id.
	 * @return string
	 */
	public String toStringWithEnergyAndId() {
		return this.toString() + "-" + this.getEnergy();
	}

	/* ACCESSORS */

	/**
	 * Getter cell.
	 * @return cell
	 */
	public Cell getCell() {
		return this.cell;
	}

	/**
	 * Setter cell.
	 * @param cell Cell of the pirate.
	 */
	public void setCell(Cell cell) {
		this.cell = cell;
	}

	/**
	 * getEnergy of a pirate.
	 * @return an integer.
	 */
	public Integer getEnergy() {
		return this.energy;
	}

	/**
	 * setEnergy of a pirate.
	 * @param energy
	 *            new energy of a pirate
	 */
	public void setEnergy(Integer energy) {
		if (energy >= MAX_ENERGY) {
			this.energy = MAX_ENERGY;
		} else {
			this.energy = energy;
		}
	}

	/**
	 * getId of a pirate.
	 * @return the id of the pirate
	 */
	public Integer getId() {
		return this.id;
	}

	/**
	 * setId of a pirate.
	 * @param id the id of a pirate.
	 */
	public void setId(Integer id) {
		this.id = id;
	}

}
