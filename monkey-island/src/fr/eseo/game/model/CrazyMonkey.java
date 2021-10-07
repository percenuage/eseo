package fr.eseo.game.model;

import fr.eseo.game.command.CommandEnum;
import fr.eseo.game.network.MonkeyIsland;

/**
 * CrazyMonkey class.
 *
 * @author Valentin Cosson
 */
public class CrazyMonkey extends Monkey {

	/* ATTRIBUTES */

	/**
	 * Attribute static final SPEED.
	 */
	public static final Integer SPEED =
			Integer.valueOf(MonkeyIsland.CONFIGURATION.getString("CRAZY_MONKEY_SPEED"));

	/* CONSTRUCTORS */

	/**
	 * Constructor of monkey.
	 * @param cell is a cell of the map.
	 */
	public CrazyMonkey(Cell cell) {
		super(SPEED, cell);
	}

	/* METHODS */

	/**
	 * Run method.
	 */
	@Override
	public void run() {
		Island island = Island.getInstance();
		Cell adjacentCell = null;
		while (adjacentCell == null) {
			adjacentCell = island.getRandomAdjacentCell(this.getCell());
			adjacentCell = this.canMove(adjacentCell) ? adjacentCell : null;
		}
		this.moveTo(adjacentCell);
		island.notifyClients(CommandEnum.CRAZY_MONKEYS, null);
	}

    /* ACCESSORS */
}
