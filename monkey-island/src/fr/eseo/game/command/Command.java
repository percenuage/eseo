package fr.eseo.game.command;

import java.util.ArrayList;
import java.util.List;

/**
 * Command class.
 *
 * @author Axel Gendillard
 */
public class Command {

    /* ATTRIBUTES */

    /**
     * CommandEnum attribute.
     */
    private CommandEnum commandEnum;

    /**
     * List of the values.
     */
    private List<Integer> values;

    /* CONSTRUCTORS */

    /**
     * Constructor Command. Create an object command from a String
     * (ex. "/D -1 0" or "/C 2 2 1-0-1-1").
     * @param command Command string.
     * @throws NullPointerException NullPointerException.
     * @throws NumberFormatException NumberFormatException.
     */
    public Command(String command) throws NullPointerException, NumberFormatException {
        String[] list = command.replace("-", " ").split(" ");

        this.commandEnum = CommandEnum.fromString(list[0]);
        this.values = new ArrayList<>();

        if (this.commandEnum.equals(CommandEnum.MOVE_PIRATE_CLIENT)) {
            list = command.split(" ");
        }

        // Remove command (ex. "/D") from list.
        list[0] = null;

        this.fillValues(list);
    }

    /* METHODS */

    /**
     * Parse the string array to an integer list.
     * @param list Array of string.
     */
    private void fillValues(String[] list) {
        for (String s : list) {
            // All array except first element (it's not a number)
            if (s != null) {
                try {
                    this.values.add(Integer.valueOf(s));
                } catch (NumberFormatException e) {
                    throw new NumberFormatException("It's not an integer : " + s);
                }
            }
        }
    }

    /* ACCESSORS */

    /**
     * Getter of commandEnum.
     * @return commandEnum
     */
    public CommandEnum getCommandEnum() {
        return this.commandEnum;
    }

    /**
     * Getter of values.
     * @return list
     */
    public List<Integer> getValues() {
        return this.values;
    }

}
