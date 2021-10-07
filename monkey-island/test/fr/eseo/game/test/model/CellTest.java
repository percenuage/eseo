package fr.eseo.game.test.model;

import fr.eseo.game.model.*;
import fr.eseo.game.model.Character;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Test for cell class.
 * 
 * @author Axel Gendillard
 */
public class CellTest {

	/**
	 * Row of the cell.
	 */
	private static final Integer ROW = 0;

	/**
	 * Column of the cell.
	 */
	private static final Integer COLUMN = 0;

	/**
	 * Island of the pirate.
	 */
	protected Island island;

	/**
	 * Cell on which the pirate is.
	 */
	protected Cell cell;

	/**
	 * Element of the cell.
	 */
	protected Element element;

	/**
	 * Character of the cell.
	 */
	protected Character character;

	/**
	 * setUp what is needed before the test.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Before
	public void setUp() throws Exception {
		this.island = Island.getInstance();
		this.cell = new Cell(ROW, COLUMN, Cell.EARTH, this.island);

		this.character = new Pirate(null, this.cell);
		this.element = new Treasure(this.cell);

		this.cell.setElement(this.element);
		this.cell.setCharacter(this.character);
	}

	/**
	 * Test to know if we can access to a earth cell.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanAccess_earth() throws Exception {
		assertEquals(this.cell.canAccess(), Boolean.TRUE);
	}

	/**
	 * Test cannot access to a water cell.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanAccess_water() throws Exception {
		this.cell.setType(Cell.WATER);
		assertEquals(this.cell.canAccess(), Boolean.FALSE);
	}

	/**
	 * Test getRow.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetRow() throws Exception {
		assertEquals(this.cell.getRow(), ROW);
	}

	/**
	 * Test setRow.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetRow() throws Exception {
		this.cell.setRow(ROW + 1);
		assertTrue(this.cell.getRow() == ROW + 1);
	}

	/**
	 * Test getColumn.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetColumn() throws Exception {
		assertEquals(this.cell.getColumn(), COLUMN);
	}

	/**
	 * Test setColumn.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetColumn() throws Exception {
		this.cell.setColumn(COLUMN + 1);
		assertTrue(this.cell.getColumn() == COLUMN + 1);

	}

	/**
	 * Test getType.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetType() throws Exception {
		assertEquals(this.cell.getType(), Cell.EARTH);
	}

	/**
	 * Test setType.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetType() throws Exception {
		this.cell.setType(Cell.WATER);
		assertEquals(this.cell.getType(), Cell.WATER);
	}

	/**
	 * Test getCharacter.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetCharacter() throws Exception {
		assertEquals(this.cell.getCharacter(), this.character);
	}

	/**
	 * Test setCharacter.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetCharacter() throws Exception {
		this.cell.setCharacter(null);
		assertNull(this.cell.getCharacter());
	}

	/**
	 * Test getElement.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetElement() throws Exception {
		assertEquals(this.cell.getElement(), this.element);
	}

	/**
	 * Test setElement.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetElement() throws Exception {
		this.cell.setElement(null);
		assertNull(this.cell.getElement());
	}

	/**
	 * Test getIsland.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetIsland() throws Exception {
		assertEquals(this.cell.getIsland(), this.island);
	}

	/**
	 * Test setIsland.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetIsland() throws Exception {
		this.cell.setIsland(null);
		assertNull(this.cell.getIsland());
	}
}