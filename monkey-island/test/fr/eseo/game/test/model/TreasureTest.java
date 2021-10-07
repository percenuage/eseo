package fr.eseo.game.test.model;

import fr.eseo.game.model.*;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Test for Treasure test.
 * 
 * @author Valentin Cosson
 */
public class TreasureTest {

	/**
	 * Row of a cell.
	 */
	private static final Integer ROW = 0;
	/**
	 * Column of a cell.
	 */
	private static final Integer COLUMN = 0;
	/**
	 * Attribute island.
	 */
	protected Island island;
	/**
	 * Attribute treasure.
	 */
	protected Treasure treasure;
	/**
	 * Attribute cell.
	 */
	protected Cell cell;

	/**
	 * To do before the test.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Before
	public void setUp() throws Exception {
		this.island = Island.getInstance();
		this.cell = new Cell(ROW, COLUMN, Cell.EARTH, this.island);
		this.treasure = new Treasure(this.cell);
	}

	/**
	 * Test toString.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testToString() throws Exception {
		String expected = this.treasure.getCell().getColumn() + "-" + this.treasure.getCell().getRow();
		assertEquals(this.treasure.toString(), expected);
	}

	/**
	 * Test treasure is not found.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testIsHidden() throws Exception {
		assertEquals(this.treasure.isHidden(), Boolean.TRUE);
	}

	/**
	 * Test setHidden.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetHidden() throws Exception {
		this.treasure.setHidden(Boolean.TRUE);
		assertTrue(this.treasure.isHidden());
	}

	/**
	 * Test the treasure is found by the pirate.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testIsFound() throws Exception {
		assertEquals(this.treasure.isFound(), Boolean.FALSE);
	}

	/**
	 * Test treasure is not found.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetFound() throws Exception {
		assertEquals(this.treasure.isFound(), Boolean.FALSE);
	}

	/**
	 * Test getCell.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetCell() throws Exception {
		assertEquals(this.treasure.getCell(), this.cell);
	}

	/**
	 * Test set cell.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetCell() throws Exception {
		this.treasure.setCell(null);
		assertNull(this.treasure.getCell());
	}

}