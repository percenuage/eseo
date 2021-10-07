package fr.eseo.game.test.command;

import fr.eseo.game.command.CommandEnum;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

/**
 * Test for CommandEnum.
 * @author Axel Gendillard
 */
public class CommandEnumTest {

    /**
     * Attribute static final INVALID_COMMAND.
     */
    public static final String INVALID_COMMAND = "INVALID";

    /**
     * Attribute static final NEW_GAME_COMMAND.
     */
    public static final String NEW_GAME_COMMAND = "/N";

    /**
     * Test fromString when valid.
	 * @throws java.lang.Exception
	 *             toute exception.
     */
    @Test
    public void testFromString_valid() throws Exception {
        assertEquals(CommandEnum.fromString(NEW_GAME_COMMAND), CommandEnum.NEW_GAME);
    }

    /**
     * Test fromString when invalid.
	 * @throws java.lang.Exception
	 *             toute exception.
     */
    @Test(expected = NullPointerException.class)
    public void testFromString_nullPointerException_invalid() throws Exception {
        CommandEnum.fromString(INVALID_COMMAND);
    }

    /**
     * Test fromString when NullPointerException.
	 * @throws java.lang.Exception
	 *             toute exception.
     */
    @Test(expected = NullPointerException.class)
    public void testFromString_nullPointerException_null() throws Exception {
        CommandEnum.fromString(null);
    }

    /**
     * Test toString.
	 * @throws java.lang.Exception
	 *             toute exception.
     */
    @Test
    public void testToString() throws Exception {
        assertEquals(CommandEnum.NEW_GAME.toString(), NEW_GAME_COMMAND);
    }
}