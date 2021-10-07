package fr.eseo.game.model;

import fr.eseo.game.command.CommandEnum;
import fr.eseo.game.network.Communication;
import fr.eseo.game.network.MonkeyIsland;

import java.util.*;

/**
 * Island singelton class.
 *
 * @author Axel Gendillard
 */
public class Island extends Observable {

	/* ATTRIBUTES */

	/**
	 * Rows of the island.
	 */
	private Integer rows;

	/**
	 * Columns of the island.
	 */
	private Integer columns;

	/**
	 * Cells of the island.
	 */
	private List<Cell> cells;

	/**
	 * Treasure on the island.
	 */
	private Treasure treasure;

	/**
	 * Map of pirates on the island.
	 */
	private Map<Integer, Pirate> pirates;

	/**
	 * List of crazy monkeys on the island.
	 */
	private List<Monkey> crazyMonkeys;

	/**
	 * List of hunter monkeys on the island.
	 */
	private List<Monkey> hunterMonkeys;

	/**
	 * List of rhum on the island.
	 */
	private List<Rhum> rhums;

	/* CONSTRUCTORS */

	/**
	 * Private constructor.
	 */
	private Island() {
		this.pirates = new HashMap<>();
		this.crazyMonkeys = new ArrayList<>();
		this.hunterMonkeys = new ArrayList<>();
		this.rhums = new ArrayList<>();
		this.initializeIsland();
	}

	/* NESTED CLASS */

	/**
	 * Private static nested class SingletonHolder.
	 */
	private static class SingletonHolder {

		/**
		 * Constructor private SingletonHolder.
		 */
		private SingletonHolder() {
		}

		/**
		 * Unique instance of Island.
		 */
		public static final Island INSTANCE = new Island();
	}

	/* METHODS */

	/**
	 * Access point to the singleton instance.
	 * 
	 * @return island Instance of the Island.
	 */
	public static Island getInstance() {
		return SingletonHolder.INSTANCE;
	}

	/**
	 * Get a cell from row and column.
	 * 
	 * @param row
	 *            Row (PosY).
	 * @param column
	 *            Column (PosX).
	 * @return cell Cell (row, column).
	 */
	public Cell getCell(Integer row, Integer column) {
		try {
			return this.cells.get(row * this.columns + column);
		} catch (IndexOutOfBoundsException e) {
			return null;
		}
	}

	/**
	 * Get random adjacent cell for crazy monkey movement.
	 * 
	 * @param cell
	 *            The adjacent of this cell.
	 * @return cell An adjacent cell.
	 */
	public Cell getRandomAdjacentCell(Cell cell) {
		Cell adjacentCell = null;
		Random r = new Random();
		int row = 0;
		int column = 0;
		while (adjacentCell == null) {
			switch (r.nextInt(4)) {
			case 0:
				row = cell.getRow() - 1;
				column = cell.getColumn();
				break;
			case 1:
				row = cell.getRow();
				column = cell.getColumn() + 1;
				break;
			case 2:
				row = cell.getRow() + 1;
				column = cell.getColumn();
				break;
			case 3:
				row = cell.getRow();
				column = cell.getColumn() - 1;
				break;
			default:
				break;
			}
			adjacentCell = this.getCell(row, column);
		}
		return adjacentCell;
	}

	/**
	 * Initialize Island.
	 */
	public void initializeIsland() {
		this.initializeCells();
		this.initializeTreasure();
		this.initializeRhums();
		this.initializeCrazyMonkeys();
		this.initializeHunterMonkeys();
	}

	/**
	 * Add new pirate to Island with its id.
	 * 
	 * @param id
	 *            Id of the new pirate.
	 * @return pirate The new pirate, otherwise null (even if it already
	 *         existed).
	 */
	public Pirate addPirate(Integer id) {
		Pirate pirate = this.pirates.get(id);
		if (pirate == null) {
			Cell cell = this.getRandomVoidEarthCell();
			pirate = new Pirate(id, cell);
			pirate.getCell().setCharacter(pirate);
			this.notifyClients(CommandEnum.NEW_PIRATE_SERVER, pirate);
			this.pirates.put(id, pirate);
			this.addObserver(pirate);
			return pirate;
		}
		return null;
	}

	/**
	 * Remove the pirate on death or on disconnection.
	 * 
	 * @param id
	 *            Id of the pirate.
	 * @return pirate The deleted pirate.
	 */
	public Pirate removePirate(Integer id) {
		Pirate pirate = this.pirates.get(id);
		if (pirate != null) {
			pirate.getCell().setCharacter(null);
			this.notifyClients(CommandEnum.REMOVE_PIRATE, pirate);
		}
		return pirate;
	}

	/**
	 * Move the pirate to the coord (X, Y).
	 * 
	 * @param id
	 *            Id of the pirate.
	 * @param moveX
	 *            Horizontal movement.
	 * @param moveY
	 *            Vertical movement.
	 * @return boolean Whether the pirate has been moved or not.
	 */
	public Pirate movePirate(Integer id, Integer moveX, Integer moveY) {
		Pirate pirate = this.pirates.get(id);
		if (pirate != null) {
			int column = pirate.getCell().getColumn() + moveX;
			int row = pirate.getCell().getRow() + moveY;
			Cell cell = this.getCell(row, column);

			if (pirate.canMove(cell) && column < this.columns) {
				pirate.moveTo(cell);
				this.notifyClients(CommandEnum.MOVE_PIRATE_SERVER, pirate);
				return pirate;
			}
		}
		return null;
	}

	/**
	 * Notify the client of a command.
	 * 
	 * @param commandEnum
	 *            the command
	 * @param arg
	 *            the argument of the command.
	 */
	public void notifyClients(CommandEnum commandEnum, Object arg) {
		Communication.pendingCommand = commandEnum;
		this.setChanged();
		this.notifyObservers(arg);
	}

	/**
	 * Launch a new game.
	 */
	public void newGame() {
		// TODO: 18/01/16 newGame

		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

		this.notifyClients(CommandEnum.NEW_GAME, null);
		this.initializeCrazyMonkeys();
		this.initializeHunterMonkeys();
		this.initializeRhums();
		this.initializeTreasure();
		this.pirates.clear();
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append(this.getColumns()).append(" ");
		sb.append(this.getRows()).append(" ");
		for (Cell cell : this.cells) {
			sb.append(cell.getType()).append("-");
		}
		sb.deleteCharAt(sb.length() - 1);
		return sb.toString();
	}

	/**
	 * Get a random void earth cell without element and character.
	 * 
	 * @return cell A void earth cell
	 */
	public Cell getRandomVoidEarthCell() {
		boolean isValid = false;
		Cell cell = null;
		while (!isValid) {
			Random r = new Random();
			int index = r.nextInt(this.cells.size());
			cell = this.getCells().get(index);
			if (cell.getType().equals(Cell.EARTH) && cell.getCharacter() == null && cell.getElement() == null) {
				isValid = true;
			}
		}
		return cell;
	}

	/**
	 * Initialize Cells.
	 */
	private void initializeCells() {
		String[] cell = MonkeyIsland.CONFIGURATION.getString("ISLAND_SHAPE").split("-");

		this.columns = Integer.valueOf(MonkeyIsland.CONFIGURATION.getString("ISLAND_COLUMNS"));
		this.rows = Integer.valueOf(MonkeyIsland.CONFIGURATION.getString("ISLAND_ROWS"));
		this.cells = new ArrayList<>();

		for (int i = 0; i < cell.length; i++) {

			int column = i % this.columns;
			int row = (i - column) / this.columns;

			if (Integer.valueOf(cell[i]).equals(Cell.WATER)) {
				this.cells.add(new Cell(row, column, Cell.WATER, this));
			} else if (Integer.valueOf(cell[i]).equals(Cell.EARTH)) {
				this.cells.add(new Cell(row, column, Cell.EARTH, this));
			}
		}
	}

	/**
	 * Initialize Treasure.
	 */
	private void initializeTreasure() {
		String[] values = MonkeyIsland.CONFIGURATION.getString("ISLAND_TRESURE").split("-");
		int column = Integer.valueOf(values[0]);
		int row = Integer.valueOf(values[1]);
		Cell cell = this.getCell(row, column);
		this.treasure = new Treasure(cell);
		this.treasure.getCell().setElement(this.treasure);
	}

	/**
	 * Initialize Crazy Monkeys.
	 */
	private void initializeCrazyMonkeys() {
		this.crazyMonkeys.clear();
		String[] values = MonkeyIsland.CONFIGURATION.getString("ISLAND_CRAZY_MONKEY").split("-");
		for (int i = 0; i < values.length; i += 2) {
			int column = Integer.valueOf(values[i]);
			int row = Integer.valueOf(values[i + 1]);
			Cell cell = this.getCell(row, column);

			Monkey monkey = new CrazyMonkey(cell);
			monkey.getCell().setCharacter(monkey);
			this.crazyMonkeys.add(monkey);
		}
	}

	/**
	 * Initialize Hunter Monkeys.
	 */
	private void initializeHunterMonkeys() {
		this.hunterMonkeys.clear();
		String[] values = MonkeyIsland.CONFIGURATION.getString("ISLAND_HUNTER_MONKEY").split("-");
		for (int i = 0; i < values.length; i += 2) {
			int column = Integer.valueOf(values[i]);
			int row = Integer.valueOf(values[i + 1]);
			Cell cell = this.getCell(row, column);

			Monkey monkey = new HunterMonkey(null, cell);
			monkey.getCell().setCharacter(monkey);
			this.hunterMonkeys.add(monkey);
		}
	}

	/**
	 * Initialize Rhums.
	 */
	private void initializeRhums() {
		int count = 0;
		this.rhums.clear();
		String[] values = MonkeyIsland.CONFIGURATION.getString("ISLAND_RHUM").split("-");
		for (int i = 0; i < values.length; i += 2) {
			int column = Integer.valueOf(values[i]);
			int row = Integer.valueOf(values[i + 1]);
			Cell cell = this.getCell(row, column);

			Rhum rhum = new Rhum(cell);
			rhum.setId(count++);
			rhum.getCell().setElement(rhum);
			this.rhums.add(rhum);
		}
	}

	/* ACCESSORS */
	/**
	 * getRows of the island.
	 * 
	 * @return number of rows.
	 */
	public Integer getRows() {
		return this.rows;
	}

	/**
	 * getColumns of the island.
	 *
	 * @return number of columns.
	 */
	public Integer getColumns() {
		return this.columns;
	}

	/**
	 * getCells of the island.
	 *
	 * @return a list of cell.
	 */
	public List<Cell> getCells() {
		return this.cells;
	}

	/**
	 * getTreasure of the island.
	 * 
	 * @return a Treasure object.
	 */
	public Treasure getTreasure() {
		return this.treasure;
	}

	/**
	 * setTreasure.
	 * 
	 * @param treasure
	 *            treasure of the island.
	 */
	public void setTreasure(Treasure treasure) {
		this.treasure = treasure;
	}

	/**
	 * getPirates Map.
	 * 
	 * @return map of pirates.
	 */
	public Map<Integer, Pirate> getPirates() {
		return this.pirates;
	}

	/**
	 * setPirates.
	 * 
	 * @param pirates
	 *            pirates of the map.
	 */
	public void setPirates(Map<Integer, Pirate> pirates) {
		this.pirates = pirates;
	}

	/**
	 * getCrazyMonkeys.
	 * 
	 * @return a list of crazyMonkeys.
	 */
	public List<Monkey> getCrazyMonkeys() {
		return this.crazyMonkeys;
	}

	/**
	 * setCrazyMonkeys.
	 * 
	 * @param crazyMonkeys
	 *            list of crazy monkeys.
	 */
	public void setCrazyMonkeys(List<Monkey> crazyMonkeys) {
		this.crazyMonkeys = crazyMonkeys;
	}

	/**
	 * getHunterMonkeys.
	 * 
	 * @return a list of hunterMonkeys.
	 */
	public List<Monkey> getHunterMonkeys() {
		return this.hunterMonkeys;
	}

	/**
	 * setHunterMonkeys.
	 * 
	 * @param hunterMonkeys
	 *            a list of hunterMonkeys.
	 */
	public void setHunterMonkeys(List<Monkey> hunterMonkeys) {
		this.hunterMonkeys = hunterMonkeys;
	}

	/**
	 * getRhums.
	 * 
	 * @return a list of rhum
	 */
	public List<Rhum> getRhums() {
		return this.rhums;
	}

	/**
	 * setRhums.
	 * 
	 * @param rhums
	 *            list of rhum.
	 */
	public void setRhums(List<Rhum> rhums) {
		this.rhums = rhums;
	}
}
