package fr.eseo.game.model;

import java.util.Map;
import java.util.Collections;
import java.util.HashMap;

import fr.eseo.game.command.CommandEnum;
import fr.eseo.game.network.MonkeyIsland;

/**
 * HunterMonkey class.
 *
 * @author kim Belassen
 * @author axel gendillard
 */
public class HunterMonkey extends Monkey {

	/* ATTRIBUTES */

	/**
	 * Attribute target.
	 */
	private Pirate target;

	/**
	 * Attribute static final SPEED.
	 */
	public static final Integer SPEED = Integer.valueOf(MonkeyIsland.CONFIGURATION.getString("HUNTER_MONKEY_SPEED"));

	/* CONSTRUCTORS */

	/**
	 * Constructor of the hunter.
	 * 
	 * @param target
	 *            Target pirate.
	 * @param cell
	 *            Cell of hunter.
	 */
	public HunterMonkey(Pirate target, Cell cell) {
		super(SPEED, cell);
		this.target = target;
	}

	/* METHODS */

	@Override
	public void run() {
		Island island = Island.getInstance();
		Cell adjacentCell = null;
		while (adjacentCell == null) {
			if (this.getCell().getIsland().getPirates().size() > 0) {
				this.target = this.getCloserTarget();
				adjacentCell = this.getCellToTarget();
				adjacentCell = this.canMove(adjacentCell) ? adjacentCell : null;
			}
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		this.moveTo(adjacentCell);
		island.notifyClients(CommandEnum.HUNTER_MONKEYS, null);

	}

	/**
	 * Method which return the cell the hunter monkey will go to for joining his
	 * target.
	 *
	 * @return a cell
	 */
	private Cell getCellToTarget() {
		Integer monkeyX = this.getCell().getColumn();
		Integer monkeyY = this.getCell().getRow();
		Integer pirateX = this.target.getCell().getColumn();
		Integer pirateY = this.target.getCell().getRow();
		if (monkeyX > pirateX) {
			monkeyX--;
		} else if (monkeyX < pirateX) {
			monkeyX++;
		} else if (monkeyY > pirateY) {
			monkeyY--;
		} else if (monkeyY < pirateY) {
			monkeyY++;
		} else {
			return null;
		}
		return this.getCell().getIsland().getCell(monkeyY, monkeyX);
	}

	/**
	 * getCloserTarget for a hunterMonkey.
	 * 
	 * @return target the closest pirate to the hunter monkey
	 */
	private Pirate getCloserTarget() {
		Island island = Island.getInstance();
		Map<Integer, Pirate> distances = new HashMap<Integer, Pirate>();
		for (Pirate pirate : island.getPirates().values()) {
			distances.put(this.getDistance(pirate), pirate);
		}

		if (!distances.isEmpty()) {
			Integer key = Collections.min(distances.keySet());
			return distances.get(key);
		} else {
			return null;
		}
	}

	/**
	 * getDistance from pirate to a hunter Monkey.
	 * 
	 * @param pirate
	 *            calculate the distance between a pirate and the hunterMonkey
	 * @return a distance
	 */
	private Integer getDistance(Pirate pirate) {
		Integer distance = (this.getCell().getColumn() - pirate.getCell().getColumn())
				+ (this.getCell().getRow() - pirate.getCell().getRow());
		return Math.abs(distance);
	}

	/* ACCESSORS */

	/**
	 * Getter target.
	 * 
	 * @return pirate
	 */
	public Pirate getTarget() {
		return this.target;
	}

	/**
	 * Setter target.
	 * 
	 * @param target
	 *            Target.
	 */
	public void setTarget(Pirate target) {
		this.target = target;
	}
}
