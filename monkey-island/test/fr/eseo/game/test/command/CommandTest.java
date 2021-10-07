package fr.eseo.game.test.command;

import fr.eseo.game.command.Command;
import fr.eseo.game.command.CommandEnum;
import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertEquals;

/**
 * Test CommandTest.
 * @author Axel Gendillard
 */
public class CommandTest {

    /**
     * Attribute static final MOVE_COMMAND.
     */
    public static final String MOVE_COMMAND = "/D 0 -1";

    /**
     * Attribute static final PIRATE_COMMAND.
     */
    public static final String PIRATE_COMMAND = "/i 1-0-0-100";

    /**
     * Attribute static final NOT_FOUND_COMMAND.
     */
    public static final String NOT_FOUND_COMMAND = "/Z";

    /**
     * Attribute static final NOT_INTEGER_COMMAND.
     */
    public static final String NOT_INTEGER_COMMAND = "/T 2-u";

    /**
     * Attribute moveCommand.
     */
    protected Command moveCommand;

    /**
     * Attribute pirateCommand.
     */
    protected Command pirateCommand;

    /**
     * Before each test.
 	 * @throws java.lang.Exception
	 *             toute exception.
     */
    @Before
    public void setUp() throws Exception {
        this.moveCommand = new Command(MOVE_COMMAND);
        this.pirateCommand = new Command(PIRATE_COMMAND);
    }

    /**
     * Test.
	 * @throws java.lang.Exception
	 *             toute exception.
     */
    @Test
    public void testGetCommandEnum_move() throws Exception {
        assertEquals(this.moveCommand.getCommandEnum(), CommandEnum.MOVE_PIRATE_CLIENT);
    }

    /**
     * Test.
	 * @throws java.lang.Exception
	 *             toute exception.
     */
    @Test
    public void testGetCommandEnum_pirate() throws Exception {
        assertEquals(this.pirateCommand.getCommandEnum(), CommandEnum.PIRATE);
    }

    /**
     * Test.
	 * @throws java.lang.Exception
	 *             toute exception.
     */
    @Test
    public void testGetValues_move() throws Exception {
        List<Integer> list = new ArrayList<>();
        list.add(0);
        list.add(-1);
        assertEquals(this.moveCommand.getValues(), list);
    }

    /**
     * Test.
	 * @throws java.lang.Exception
	 *             toute exception.
     */
    @Test
    public void testGetValues_pirate() throws Exception {
        List<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(0);
        list.add(0);
        list.add(100);
        assertEquals(this.pirateCommand.getValues(), list);
    }

    /**
     * Test.
	 * @throws java.lang.Exception
	 *             toute exception.
     */
    @Test(expected = NullPointerException.class)
    public void testCommand_nullPointerException() throws Exception {
        new Command(NOT_FOUND_COMMAND);
    }

    /**
     * Test.
	 * @throws java.lang.Exception
	 *             toute exception.
     */
    @Test(expected = NumberFormatException.class)
    public void testCommand_numberFormatException() throws Exception {
        new Command(NOT_INTEGER_COMMAND);
    }
}