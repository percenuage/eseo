package fr.eseo.game.test.model;

import org.junit.After;
import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

import fr.eseo.game.model.Cell;
import fr.eseo.game.model.HunterMonkey;
import fr.eseo.game.model.Island;
import fr.eseo.game.model.Monkey;
import fr.eseo.game.model.Pirate;

import static org.junit.Assert.*;

/**
 * Test HunterMonkey.
 * 
 * @author Kim Belassen
 */

public class HunterMonkeyTest {

	/**
	 * pirate.
	 */
	protected Pirate pirate;

	/**
	 * Island of the pirate.
	 */
	protected Island island;

	/**
	 * Earth Cell where the pirate is.
	 */
	protected Cell pirateCell;

	/**
	 * Earth Cell where the pirate is.
	 */
	protected Cell monkeyCell;

	/**
	 * crazyMonkey.
	 */
	private Monkey hunterMonkey;

	/**
	 * Row of the cell.
	 */
	private static final Integer ROW = 0;

	/**
	 * Column of the cell.
	 */
	private static final Integer COLUMN = 0;

	/**
	 * id of a pirate.
	 */
	private static final Integer PIRATE_ID = 20;

	/**
	 * Before tests.
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
		this.hunterMonkey = new HunterMonkey(this.pirate, this.monkeyCell);

		this.pirateCell.setCharacter(this.pirate);
		this.monkeyCell.setCharacter(this.hunterMonkey);
		this.island.getPirates().put(PIRATE_ID, this.pirate);
	}

	/**
	 * After tests.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@After
	public void tearDown() throws Exception {

	}

	/**
	 * Test.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testRun_target() throws Exception {
		this.hunterMonkey.run();
		assertEquals(((HunterMonkey) this.hunterMonkey).getTarget(), this.pirate);
		assertEquals(this.hunterMonkey.getCell().getColumn(), COLUMN);
	}

	/**
	 * Test.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetTarget() throws Exception {
		assertEquals(((HunterMonkey) this.hunterMonkey).getTarget(), this.pirate);
	}

	/**
	 * Test.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetTarget() throws Exception {
		((HunterMonkey) this.hunterMonkey).setTarget(null);
		assertNull(((HunterMonkey) this.hunterMonkey).getTarget());
	}
}