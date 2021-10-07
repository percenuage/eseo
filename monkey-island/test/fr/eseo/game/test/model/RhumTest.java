package fr.eseo.game.test.model;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import fr.eseo.game.model.Cell;
import fr.eseo.game.model.Island;
import fr.eseo.game.model.Rhum;

import static org.junit.Assert.*;

/**
 * Test Rhum class.
 * @author Valentin Cosson
 */
public class RhumTest {

	/**
	 * Atribute ROW.
	 */
	private static final Integer ROW = 0;

	/**
	 * Atribute COLUMN.
	 */
	private static final Integer COLUMN = 0;

	/**
	 * Attribute island.
	 */
	protected Island island;

	/**
	 * Attribute rhum.
	 */
	protected Rhum rhum;

	/**
	 * Attribute cell.
	 */
	protected Cell cell;
	/**
	 * Attribute id.
	 */
	protected Integer id;

	/**
	 * Before tests.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Before
	public void setUp() throws Exception {
		this.island = Island.getInstance();
		this.cell = new Cell(ROW, COLUMN, Cell.EARTH, this.island);
		this.rhum = new Rhum(this.cell);

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
	public void testToString() throws Exception {
		String expected = this.rhum.getCell().getColumn() + "-" + this.rhum.getCell().getRow() + "-"
				+ this.rhum.getVisibility();
		assertEquals(this.rhum.toString(), expected);
	}

	/**
	 * Test.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetId() throws Exception {
		assertNull(this.rhum.getId());
	}

	/**
	 * Test.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetId() throws Exception {
		this.rhum.setId(null);
		assertNull(this.rhum.getId());
	}

	/**
	 * Test.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testIsHidden() throws Exception {
		assertEquals(this.rhum.isHidden(), Boolean.TRUE);
	}

	/**
	 * Test.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetHidden() throws Exception {
		this.rhum.setHidden(Boolean.TRUE);
		assertTrue(this.rhum.isHidden());
	}

	/**
	 * Test.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testIsFound() throws Exception {
		assertEquals(this.rhum.isFound(), Boolean.FALSE);
	}

	/**
	 * Test.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetFound() throws Exception {
		assertEquals(this.rhum.isFound(), Boolean.FALSE);
	}

	/**
	 * Test.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetCell() throws Exception {
		assertEquals(this.rhum.getCell(), this.cell);
	}

	/**
	 * Test.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetCell() throws Exception {
		this.rhum.setCell(null);
		assertNull(this.rhum.getCell());
	}
}