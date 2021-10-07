package fr.eseo.game.test.model;

import fr.eseo.game.command.CommandEnum;
import fr.eseo.game.model.*;
import fr.eseo.game.network.Communication;
import fr.eseo.game.network.MonkeyIsland;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import java.util.*;

import static org.junit.Assert.*;

/**
 * Class IslandTest.
 *
 * @author Kim Belassen
 * @author Axel Gendillard
 *
 */
public class IslandTest {
	/**
	 * Rows of the island.
	 */
	private static final Integer ROWS = Integer.valueOf(MonkeyIsland.CONFIGURATION.getString("ISLAND_ROWS"));
	/**
	 * Columns of the Island.
	 */
	private static final Integer COLUMNS = Integer.valueOf(MonkeyIsland.CONFIGURATION.getString("ISLAND_COLUMNS"));
	/**
	 * Row of a cell.
	 */
	private static final Integer ROW_CELL = 0;
	/**
	 * Column of a cell.
	 */
	private static final Integer COLUMN_CELL = 0;
	/**
	 * Number of test for testing random methods.
	 */
	private static final Integer NB_RANDOM_TEST = 1000;
	/**
	 * Delta for testing random methods.
	 */
	private static final Integer DELTA_RANDOM_TEST = 50;

	/**
	 * Id of a pirate.
	 */
	private static final Integer PIRATE_ID = 1;

	/**
	 * Number of move possible.
	 */
	private static final Integer NB_MOVE_POSSIBILITIES = 4;

	/**
	 * Island attribute.
	 */
	protected Island island;

	/**
	 * Cell attribute.
	 */
	protected Cell cell;
	/**
	 * Pirate attribute.
	 */
	protected Pirate pirate;

	/**
	 * create an island object for testing.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Before
	public void setUp() throws Exception {
		this.island = Island.getInstance();
		this.cell = new Cell(ROW_CELL, COLUMN_CELL, Cell.EARTH, this.island);
		this.pirate = new Pirate(PIRATE_ID, this.cell);
		this.cell.setCharacter(this.pirate);
	}

	/**
	 * Is launch after each test.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@After
	public void tearDown() throws Exception {
		this.island.getPirates().clear();
		this.island.deleteObservers();
	}

	/**
	 * Testing getInstance of an Island.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetInstance() throws Exception {
		assertEquals(Island.getInstance(), this.island);
	}

	/**
	 * Test if a cell is not null for getCell.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetCell_notNull() throws Exception {
		int index = ROW_CELL * this.island.getColumns() + COLUMN_CELL;
		Cell expected = this.island.getCells().get(index);
		assertEquals(this.island.getCell(ROW_CELL, COLUMN_CELL), expected);
	}

	/**
	 * Test if a cell is null.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetCell_null() throws Exception {
		// IndexOutOfBoundsException
		assertNull(this.island.getCell(ROWS, COLUMNS));
	}

	/**
	 * Test the occurrence of cells for getRandomAdjacentCell.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetRandomAdjacentCell() throws Exception {
		List<Cell> cells = new ArrayList<>();

		Cell center = this.island.getCell(ROW_CELL + 1, COLUMN_CELL + 1);
		Cell up = this.island.getCell(ROW_CELL, COLUMN_CELL + 1);
		Cell right = this.island.getCell(ROW_CELL + 1, COLUMN_CELL + 2);
		Cell down = this.island.getCell(ROW_CELL + 2, COLUMN_CELL + 1);
		Cell left = this.island.getCell(ROW_CELL + 1, COLUMN_CELL);

		for (int i = 0; i < NB_RANDOM_TEST; i++) {
			cells.add(this.island.getRandomAdjacentCell(center));
		}

		assertEquals(Collections.frequency(cells, up), NB_RANDOM_TEST / NB_MOVE_POSSIBILITIES, DELTA_RANDOM_TEST);
		assertEquals(Collections.frequency(cells, right), NB_RANDOM_TEST / NB_MOVE_POSSIBILITIES, DELTA_RANDOM_TEST);
		assertEquals(Collections.frequency(cells, down), NB_RANDOM_TEST / NB_MOVE_POSSIBILITIES, DELTA_RANDOM_TEST);
		assertEquals(Collections.frequency(cells, left), NB_RANDOM_TEST / NB_MOVE_POSSIBILITIES, DELTA_RANDOM_TEST);
	}

	/**
	 * Test initializeIsland cells.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testInitializeIsland_cell() throws Exception {
		this.island.getCells().removeAll(this.island.getCells());
		this.island.initializeIsland();
		assertNotNull(this.island.getTreasure());
	}

	/**
	 * Test the position of treasure on the island.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testInitializeIsland_treasure() throws Exception {
		this.island.setTreasure(null);
		this.island.initializeIsland();
		assertNotNull(this.island.getTreasure());
	}

	/**
	 * Test the position of crazy Monkeys.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testInitializeIsland_crazies() throws Exception {
		this.island.setCrazyMonkeys(new ArrayList<>());
		this.island.initializeIsland();
		assertTrue(this.island.getCrazyMonkeys().size() > 0);
	}

	/**
	 * Test the position of hunter Monkeys.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testInitializeIsland_hunters() throws Exception {
		this.island.setHunterMonkeys(new ArrayList<>());
		this.island.initializeIsland();
		assertTrue(this.island.getHunterMonkeys().size() > 0);
	}

	/**
	 * Test the position of the rhum.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testInitializeIsland_rhums() throws Exception {
		this.island.setRhums(new ArrayList<>());
		this.island.initializeIsland();
		assertTrue(this.island.getRhums().size() > 0);
	}

	/**
	 * Test to add a pirate that already exist.
	 *
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testAddPirate_pirate_null() throws Exception {
		this.island.getPirates().put(PIRATE_ID, this.pirate);
		assertNull(this.island.addPirate(PIRATE_ID));
	}

	/**
	 * Test to add a new pirate in the island's map of pirates.
	 *
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testAddPirate_pirate_notNull() throws Exception {
		this.island.addPirate(PIRATE_ID);
		assertEquals(this.island.getPirates().containsKey(PIRATE_ID), Boolean.TRUE);
	}

	/**
	 * Test to check if the cell of the created pirate is in the island.
	 *
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testAddPirate_island_pirateCell() throws Exception {
		Pirate pirate = this.island.addPirate(PIRATE_ID);
		assertEquals(Boolean.TRUE, this.island.getCells().contains(pirate.getCell()));
	}

	/**
	 * Test to check if the cell of pirate has the character pirate inside
	 * itself.
	 *
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testAddPirate_cell_pirate() throws Exception {
		Pirate pirate = this.island.addPirate(PIRATE_ID);
		assertEquals(pirate.getCell().getCharacter(), pirate);
	}

	/**
	 * Test notify when adding a pirate.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testAddPirate_notify() throws Exception {
		this.island.addPirate(PIRATE_ID);
		assertEquals(CommandEnum.NEW_PIRATE_SERVER, Communication.pendingCommand);
	}

	/**
	 * Test observer when adding a pirate.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testAddPirate_observer() throws Exception {
		this.island.addPirate(PIRATE_ID);
		assertTrue(this.island.countObservers() == 1);
	}

	/**
	 * Test removePirate on an existing pirate.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testRemovePirate_existed() throws Exception {
		this.island.getPirates().put(PIRATE_ID, this.pirate);
		Pirate pirate = this.island.removePirate(PIRATE_ID);
		assertEquals(this.pirate, pirate);
	}

	/**
	 * Test to check when removePirate if the cell is null.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testRemovePirate_existed_voidCell() throws Exception {
		this.island.getPirates().put(PIRATE_ID, this.pirate);
		this.island.removePirate(PIRATE_ID);
		assertNull(this.cell.getCharacter());
	}

	/**
	 * Test notify when removePirate.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testRemovePirate_existed_notify() throws Exception {
		this.island.getPirates().put(PIRATE_ID, this.pirate);
		this.island.removePirate(PIRATE_ID);
		assertEquals(CommandEnum.REMOVE_PIRATE, Communication.pendingCommand);
	}

	/**
	 * Test removePirate.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testRemovePirate_notExisted() throws Exception {
		Pirate pirate = this.island.removePirate(PIRATE_ID);
		assertNull(pirate);
	}

	/**
	 * Test movePirate.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMovePirate_null() throws Exception {
		assertNull(this.island.movePirate(PIRATE_ID, ROW_CELL, COLUMN_CELL));
	}

	/**
	 * Test movePirate and canMove.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMovePirate_existed_canMove() throws Exception {
		this.island.getPirates().put(PIRATE_ID, this.pirate);
		Cell cell = this.island.getCell(ROW_CELL, COLUMN_CELL + 1);
		cell.setType(Cell.EARTH);
		assertEquals(this.pirate, this.island.movePirate(PIRATE_ID, 1, 0));
	}

	/**
	 * Test movePirate, canMove and notify.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMovePirate_existed_canMove_notify() throws Exception {
		this.island.getPirates().put(PIRATE_ID, this.pirate);
		Cell cell = this.island.getCell(ROW_CELL, COLUMN_CELL + 1);
		cell.setType(Cell.EARTH);
		this.island.movePirate(PIRATE_ID, 1, 0);
		assertEquals(CommandEnum.MOVE_PIRATE_SERVER, Communication.pendingCommand);
	}

	/**
	 * Test cannot Move for a pirate.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMovePirate_existed_canNotMove() throws Exception {
		this.island.getPirates().put(PIRATE_ID, this.pirate);
		Cell cell = this.island.getCell(ROW_CELL, COLUMN_CELL + 1);
		cell.setType(Cell.WATER);
		assertNull(this.island.movePirate(PIRATE_ID, 1, 0));
	}

	/**
	 * Test method toString for island.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testToString() throws Exception {
		String expected = MonkeyIsland.CONFIGURATION.getString("ISLAND_COLUMNS") + " "
				+ MonkeyIsland.CONFIGURATION.getString("ISLAND_ROWS") + " "
				+ MonkeyIsland.CONFIGURATION.getString("ISLAND_SHAPE");
		assertEquals(this.island.toString(), expected);
	}

	/**
	 * Test to check if a cell a earth cell.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetRandomVoidEarthCell_cell_earth() throws Exception {
		Cell cell;
		for (int i = 0; i < NB_RANDOM_TEST; i++) {
			cell = this.island.getRandomVoidEarthCell();
			assertEquals(cell.getType(), Cell.EARTH);
		}
	}

	/**
	 * Test to check if a cell is empty of character.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetRandomVoidEarthCell_cell_earthNullCharacter() throws Exception {
		Cell cell;
		for (int i = 0; i < NB_RANDOM_TEST; i++) {
			cell = this.island.getRandomVoidEarthCell();
			assertNull(cell.getCharacter());
		}
	}

	/**
	 * Test to check if a cell is empty of element.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetRandomVoidEarthCell_cell_earthNullElement() throws Exception {
		Cell cell;
		for (int i = 0; i < NB_RANDOM_TEST; i++) {
			cell = this.island.getRandomVoidEarthCell();
			assertNull(cell.getElement());
		}
	}

	/**
	 * Test notifyClient.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testNotifyClients() throws Exception {
		this.island.addObserver(this.pirate);
		this.island.notifyClients(CommandEnum.INCORRECT_MOVE, null);
		assertEquals(CommandEnum.INCORRECT_MOVE, Communication.pendingCommand);
	}

	/**
	 * Test new Game.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testNewGame() throws Exception {
		// TODO: 19/01/16 Add more for NewGame
		this.island.newGame();
		assertEquals(CommandEnum.NEW_GAME, Communication.pendingCommand);

	}

	/**
	 * Test getRows.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetRows() throws Exception {
		assertEquals(this.island.getRows(), ROWS);
	}

	/**
	 * Test GetColumns.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetColumns() throws Exception {
		assertEquals(this.island.getColumns(), COLUMNS);
	}

	/**
	 * Test getCells.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetCells() throws Exception {
		assertEquals(this.island.getCells().size(), ROWS * COLUMNS);
	}

	/**
	 * Test getTreasure.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetTreasure() throws Exception {
		assertNotNull(this.island.getTreasure());
	}

	/**
	 * Test setTreasure.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetTreasure() throws Exception {
		Treasure treasure = new Treasure(null);
		this.island.setTreasure(treasure);
		assertEquals(this.island.getTreasure(), treasure);
	}

	/**
	 * Test GetPirate.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetPirates() throws Exception {
		assertTrue(this.island.getPirates().size() >= 0);
	}

	/**
	 * Test setPirate.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetPirates() throws Exception {
		this.island.getPirates().clear();
		assertTrue(this.island.getPirates().size() == 0);
	}

	/**
	 * Test getCrazyMonkeys.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetCrazyMonkeys() throws Exception {
		assertTrue(this.island.getCrazyMonkeys().size() > 0);
	}

	/**
	 * Test setCrazyMonkeys.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetCrazyMonkeys() throws Exception {
		this.island.setCrazyMonkeys(new ArrayList<>());
		assertTrue(this.island.getCrazyMonkeys().size() == 0);
	}

	/**
	 * Test getHunterMonkeys.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetHunterMonkeys() throws Exception {
		assertTrue(this.island.getHunterMonkeys().size() > 0);
	}

	/**
	 * Test setHunterMonkeys.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetHunterMonkeys() throws Exception {
		this.island.setHunterMonkeys(new ArrayList<>());
		assertTrue(this.island.getHunterMonkeys().size() == 0);
	}

	/**
	 * Test getRhums.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetRhums() throws Exception {
		assertTrue(this.island.getRhums().size() > 0);
	}

	/**
	 * Test setRhums.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetRhums() throws Exception {
		this.island.setRhums(new ArrayList<>());
		assertTrue(this.island.getRhums().size() == 0);
	}
}