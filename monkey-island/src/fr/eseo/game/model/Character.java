package fr.eseo.game.model;

/**
 * Character interface.
 *
 * @author Valentin Cosson
 */
public interface Character {

    /* METHODS */

    /**
     * Check whether the character can move to a cell.
     * @param cell Target cell.
     * @return boolean
     */
    Boolean canMove(Cell cell);

    /**
     * Proceed to the movement of the character.
     * @param cell Target cell.
     */
    void moveTo(Cell cell);

    /**
     * Add action when a character meet another character in the same cell.
     * @param character Target character.
     */
    void meetCharacter(Character character);

}
