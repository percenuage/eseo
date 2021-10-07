package fr.eseo.game.test.model;

import fr.eseo.game.command.CommandEnum;
import fr.eseo.game.model.*;
import fr.eseo.game.network.Communication;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Test for a Pirate.
 * 
 * @author Axel Gendillard
 * @author Kim Belassen
 */
public class PirateTest {

	/**
	 * Id of a pirate.
	 */
	private static final Integer PIRATE_ID = 1;

	/**
	 * Energy of a pirate.
	 */
	private static final Integer PIRATE_ENERGY = 30;

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
	 * Pirate for which the test will validate methods.
	 */
	protected Pirate pirate;

	/**
	 * Cell on which the pirate is.
	 */
	protected Cell cell;

	/**
	 * Element rhum.
	 */
	protected Rhum rhum;

	/**
	 * Element treasure.
	 */
	protected Treasure treasure;

	/**
	 * Element monkey.
	 */
	protected Monkey monkey;

	/**
	 * Method before launching the test.
	 *
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Before
	public void setUp() throws Exception {
		this.island = Island.getInstance();
		this.cell = new Cell(ROW, COLUMN, Cell.EARTH, this.island);

		this.pirate = new Pirate(PIRATE_ID, this.cell);
		this.rhum = new Rhum(this.cell);
		this.treasure = new Treasure(this.cell);
		this.monkey = new CrazyMonkey(this.cell);
	}

	/**
	 * Test isDead false for a pirate.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testIsDead_false() throws Exception {
		assertEquals(this.pirate.isDead(), Boolean.FALSE);
	}

	/**
	 * Test isDead true for a pirate.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testIsDead_true() throws Exception {
		this.pirate.setEnergy(Pirate.MIN_ENERGY);
		assertEquals(this.pirate.isDead(), Boolean.TRUE);
	}

	/**
	 * Test foundElement null.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testFoundElement_noElement() throws Exception {
		this.pirate.foundElement(null);
		assertNull(this.pirate.getCell().getElement());
	}

	/**
	 * Test foundElement rhum and increase pirate energy.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testFoundElement_rhum_pirateEnergy() throws Exception {
		this.pirate.setEnergy(PIRATE_ENERGY);
		this.pirate.foundElement(this.rhum);
		assertTrue(this.pirate.getEnergy() == PIRATE_ENERGY + Rhum.ENERGY_RECOVER);
	}

	/**
	 * Test isFound rhum.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testFoundElement_rhum_isFound() throws Exception {
		this.pirate.foundElement(this.rhum);
		assertEquals(this.rhum.isFound(), Boolean.TRUE);
	}

	/**
	 * Test rhum isHidden when it's found.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testFoundElement_rhum_isHidden() throws Exception {
		this.pirate.foundElement(this.rhum);
		assertEquals(this.rhum.isHidden(), Boolean.TRUE);
	}

	/**
	 * Test treasure isFound.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testFoundElement_treasure_isFound() throws Exception {
		this.pirate.foundElement(this.treasure);
		assertEquals(this.treasure.isFound(), Boolean.TRUE);
	}

	/**
	 * Test foundRhum notify.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testFoundElement_rhum_notify() throws Exception {
		this.pirate.foundElement(this.rhum);
		assertEquals(CommandEnum.RHUM, Communication.pendingCommand);

	}

	/**
	 * Test foundTreasure notify.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testFoundElement_treasure_notify() throws Exception {
		this.pirate.foundElement(this.treasure);
		assertEquals(CommandEnum.NEW_GAME, Communication.pendingCommand);
		//TODO: fix this test
	}

	/**
	 * Test foundTreasure isHidden.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testFoundElement_treasure_isHidden() throws Exception {
		this.pirate.foundElement(this.treasure);
		assertEquals(this.treasure.isHidden(), Boolean.FALSE);
	}

	/**
	 * Test canMove to a null cell.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanMove_cellNull() throws Exception {
		assertEquals(this.pirate.canMove(null), Boolean.FALSE);
	}

	/**
	 * Test canMove to a water cell.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanMove_cellCanAccess_water() throws Exception {
		this.cell.setType(Cell.WATER);
		assertEquals(this.pirate.canMove(this.cell), Boolean.FALSE);
	}

	/**
	 * Test canMove canAccess earth cell.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanMove_cellCanAccess_earth() throws Exception {
		this.cell.setType(Cell.EARTH);
		assertEquals(this.pirate.canMove(this.cell), Boolean.TRUE);
	}

	/**
	 * Test canMove when character is null.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanMove_character_null() throws Exception {
		this.cell.setCharacter(null);
		assertEquals(this.pirate.canMove(this.cell), Boolean.TRUE);
	}

	/**
	 * Test canMove when character is not null.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanMove_character_notNull() throws Exception {
		this.cell.setCharacter(this.pirate);
		assertEquals(this.pirate.canMove(this.cell), Boolean.FALSE);
	}

	/**
	 * Test if a pirate cannot move to cell which contains a pirate.
	 *
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanMove_character_pirate() throws Exception {
		this.cell.setCharacter(this.pirate);
		assertEquals(this.pirate.canMove(this.cell), Boolean.FALSE);
	}

	/**
	 * Test canMove to a cell not is the island.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testCanMove_cellColumnIndexOutOfBound() throws Exception {
		this.cell.setColumn(this.island.getColumns());
		assertEquals(this.pirate.canMove(this.cell), Boolean.FALSE);
	}

	/**
	 * Test moveTo initial cell set with a character null.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMoveTo_cellInitial_character_null() throws Exception {
		this.cell.setCharacter(this.pirate);
		Cell target = new Cell(ROW, COLUMN + 1, Cell.EARTH, this.island);
		this.pirate.moveTo(target);
		assertNull(this.cell.getCharacter());
	}

	/**
	 * Test moveTo cellFinal.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMoveTo_cellFinal_character_notNull() throws Exception {
		this.cell.setCharacter(this.pirate);
		Cell target = new Cell(ROW, COLUMN + 1, Cell.EARTH, this.island);
		this.pirate.moveTo(target);
		assertEquals(target.getCharacter(), this.pirate);
	}

	/**
	 * Test when moveTo pirate energy decrease.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMoveTo_pirateEnergy_decrease() throws Exception {
		this.cell.setCharacter(this.pirate);
		Cell target = new Cell(ROW, COLUMN + 1, Cell.EARTH, this.island);
		this.pirate.moveTo(target);
		assertTrue(this.pirate.getEnergy() == Pirate.MAX_ENERGY - 1);
	}

	/**
	 * Test moveTo pirate is alive.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMoveTo_pirateEnergy_alive() throws Exception {
		this.cell.setCharacter(this.pirate);
		Cell target = new Cell(ROW, COLUMN + 1, Cell.EARTH, this.island);
		this.pirate.moveTo(target);
		assertEquals(this.pirate.isDead(), Boolean.FALSE);
	}

	/**
	 * Test moveTo pirate dead.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMoveTo_pirateEnergy_dead() throws Exception {
		this.cell.setCharacter(this.pirate);
		Cell target = new Cell(ROW, COLUMN + 1, Cell.EARTH, this.island);
		this.pirate.setEnergy(Pirate.MIN_ENERGY + 1);
		this.pirate.moveTo(target);
		assertEquals(this.pirate.isDead(), Boolean.TRUE);
	}

	/**
	 * Test when pirate dead by motving, is removed.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMoveTo_pirateEnergy_dead_isRemoved() throws Exception {
		this.cell.setCharacter(this.pirate);
		Cell target = new Cell(ROW, COLUMN + 1, Cell.EARTH, this.island);
		this.pirate.setEnergy(Pirate.MIN_ENERGY + 1);
		this.pirate.moveTo(target);
		assertNull(this.cell.getCharacter());
	}

	/**
	 * Test meetCharacter.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMeetCharacter() throws Exception {
		this.pirate.meetCharacter(null);
		assertNotNull(this.pirate);
	}

	/**
	 * Test if a pirate meet a monkey.
	 *
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testMeetCharacter_character_monkey() throws Exception {
		this.pirate.meetCharacter(this.monkey);
		assertEquals(this.pirate.getEnergy(), Pirate.MIN_ENERGY);
		assertEquals(Boolean.FALSE, this.island.getPirates().containsKey(this.pirate.getId()));
	}

	/**
	 * Test toString.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testToString() throws Exception {
		String expected = this.pirate.getId() + "-" + this.pirate.getCell().getColumn() + "-"
				+ this.pirate.getCell().getRow();
		assertEquals(this.pirate.toString(), expected);
	}

	/**
	 * Test toString withEnergy.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testToStringWithEnergy() throws Exception {
		String expected = this.pirate.getCell().getColumn() + "-"
				+ this.pirate.getCell().getRow() + "-" + this.pirate.getEnergy();
		assertEquals(this.pirate.toStringWithEnergy(), expected);
	}

	/**
	 * Test toString withEnergy.
	 *
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testToStringWithEnergyAndId() throws Exception {
		String expected = this.pirate.getId() + "-" + this.pirate.getCell().getColumn() + "-"
				+ this.pirate.getCell().getRow() + "-" + this.pirate.getEnergy();
		assertEquals(this.pirate.toStringWithEnergyAndId(), expected);
	}

	/**
	 * Test getCell.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetCell() throws Exception {
		assertEquals(this.pirate.getCell(), this.cell);
	}

	/**
	 * Test setCell.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetCell() throws Exception {
		this.pirate.setCell(null);
		assertNull(this.pirate.getCell());
	}

	/**
	 * Test getEnergy.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetEnergy() throws Exception {
		assertEquals(this.pirate.getEnergy(), Pirate.MAX_ENERGY);
	}

	/**
	 * Test setEnergy.
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetEnergy() throws Exception {
		this.pirate.setEnergy(Pirate.MAX_ENERGY + 1);
		assertEquals(this.pirate.getEnergy(), Pirate.MAX_ENERGY);
	}

	/**
	 * Test getId.
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetId() throws Exception {
		assertEquals(this.pirate.getId(), PIRATE_ID);
	}
	/**
	 * Test setId.
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSetId() throws Exception {
		this.pirate.setId(null);
		assertNull(this.pirate.getId());
	}

}