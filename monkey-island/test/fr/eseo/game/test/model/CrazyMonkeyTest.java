package fr.eseo.game.test.model;

import fr.eseo.game.model.*;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotEquals;
import static org.junit.Assert.assertNull;

//import org.easymock.EasyMock;

/**
 * Class MonkeyTest.
 *
 * @author Kim Belassen
 *
 */
public class CrazyMonkeyTest {

	/**
	 * id of a pirate.
	 */
	private static final Integer PIRATE_ID = 20;

	/**
	 * New speed of a monkey.
	 */
	private static final Integer CRAZY_SPEED = 1;

	/**
	 * Row of the cell.
	 */
	private static final Integer ROW = 0;

	/**
	 * Column of the cell.
	 */
	private static final Integer COLUMN = 0;

	/**
	 * crazyMonkey.
	 */
	private Monkey crazyMonkey;

	/**
	 * pirate.
	 */
	protected Pirate pirate;

	/**
	 * Earth Cell where the pirate is.
	 */
	protected Cell pirateCell;

	/**
	 * Earth Cell where the pirate is.
	 */
	protected Cell monkeyCell;

	/**
	 * Island of the pirate.
	 */
	protected Island island;

	/**
	 * Method before launching the test.
	 *
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Before
	public void setUp() throws Exception {
		this.island = Island.getInstance();
		this.pirateCell = new Cell(ROW, COLUMN, Cell.EARTH, this.island);
		this.monkeyCell = new Cell(ROW + 1, COLUMN + 1, Cell.EARTH, this.island);

		this.pirate = new Pirate(PIRATE_ID, this.pirateCell);
		this.crazyMonkey = new CrazyMonkey(this.monkeyCell);

		this.pirateCell.setCharacter(this.pirate);
		this.monkeyCell.setCharacter(this.crazyMonkey);
		
	}

	/**
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testRun() throws Exception {
		this.crazyMonkey.setCell(this.monkeyCell);
		this.crazyMonkey.run();
		assertNotEquals(this.crazyMonkey.getCell(), this.monkeyCell);
	}

	/**
	 * Test if monkey move to a null cell.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanMove_cellNull() throws Exception {
		assertEquals(this.crazyMonkey.canMove(null), Boolean.FALSE);
	}

	/**
	 * Test if monkey cannot move to a water cell.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanMove_cellCanAccess_water() throws Exception {
		this.monkeyCell.setType(Cell.WATER);
		assertEquals(this.crazyMonkey.canMove(this.monkeyCell), Boolean.FALSE);
	}

	/**
	 * Test if monkey can move to an earth cell.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanMove_cellCanAccess_earth() throws Exception {
		this.monkeyCell.setType(Cell.EARTH);
		this.monkeyCell.setCharacter(null);
		assertEquals(this.crazyMonkey.canMove(this.monkeyCell), Boolean.TRUE);
	}

	/**
	 * Test if a monkey can move to a cell which contains null.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanMove_character_null() throws Exception {
		this.monkeyCell.setCharacter(null);
		assertEquals(this.crazyMonkey.canMove(this.monkeyCell), Boolean.TRUE);
	}

	/**
	 * Test if a monkey can move to cell which contains a pirate.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanMove_character_pirate() throws Exception {
		this.monkeyCell.setCharacter(this.pirate);
		assertEquals(this.crazyMonkey.canMove(this.monkeyCell), Boolean.TRUE);
	}

	/**
	 * Test if a monkey cannot move to cell which contains a monkey.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanMove_character_monkey() throws Exception {
		Monkey monkey2 = new CrazyMonkey(this.monkeyCell);
		this.monkeyCell.setCharacter(monkey2);
		assertEquals(this.crazyMonkey.canMove(this.monkeyCell), Boolean.FALSE);
	}

	/**
	 * Test if a monkey cannot move to a cell which is out of Bound.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanMove_cellColumnIndexOutOfBound() throws Exception {
		this.monkeyCell.setColumn(this.island.getColumns());
		assertEquals(this.pirate.canMove(this.monkeyCell), Boolean.FALSE);
	}

	/**
	 * Test if the cell that the monkey has left, has now a null character.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMoveTo_cellInitial_character_null() throws Exception {
		this.monkeyCell.setCharacter(this.crazyMonkey);
		Cell target = new Cell(ROW, COLUMN + 1, Cell.EARTH, this.island);
		this.crazyMonkey.moveTo(target);
		assertNull(this.monkeyCell.getCharacter());
	}

	/**
	 * Test if the cell the monkey is going to, contains now the character.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMoveTo_cellFinal_character_notNull() throws Exception {
		this.monkeyCell.setCharacter(this.crazyMonkey);
		Cell target = new Cell(ROW, COLUMN + 1, Cell.EARTH, this.island);
		this.crazyMonkey.moveTo(target);
		assertEquals(target.getCharacter(), this.crazyMonkey);

	}

	/**
	 * Test if a monkey meet a pirate.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMeetCharacter_character_pirate() throws Exception {
		this.crazyMonkey.meetCharacter(this.pirate);
		assertEquals(this.pirate.getEnergy(), Pirate.MIN_ENERGY);
	}

	/**
	 * Test if a pirate is deleted when he meets a monkey.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMeetCharacter_characterPirate_null() throws Exception {
		this.pirate.setCell(this.monkeyCell);
		this.crazyMonkey.meetCharacter(this.pirate);
		assertEquals(this.monkeyCell.getCharacter(), this.crazyMonkey);
	}

	/**
	 * Test method toString of monkey.
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testToString() throws Exception {
		String expected = this.crazyMonkey.getCell().getColumn() + "-" + this.crazyMonkey.getCell().getRow();
		assertEquals(this.crazyMonkey.toString(), expected);
	}

	/**
	 * Test getCell.
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetCell() throws Exception {
		assertEquals(this.crazyMonkey.getCell(), this.monkeyCell);
	}

	/**
	 * Test setCell.
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetCell() throws Exception {
		this.crazyMonkey.setCell(null);
		assertNull(this.crazyMonkey.getCell());
	}

	/**
	 * Test getSpeed.
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetSpeed() throws Exception {
		assertEquals(this.crazyMonkey.getSpeed(), CrazyMonkey.SPEED);
	}

	/**
	 * Test setSpeed.
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetSpeed() throws Exception {
		this.crazyMonkey.setSpeed(CRAZY_SPEED);
		assertEquals(this.crazyMonkey.getSpeed(), CRAZY_SPEED);
	}
}