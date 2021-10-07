package fr.eseo.game.model;

/**
 * Treasure class.
 *
 * @author Valentin Cosson
 */
public class Treasure extends Element {

    /* ATTRIBUTES */

    /* CONSTRUCTORS */

    /**
     * Constructor of the treasure.
     * @param cell Cell of the treasure.
     */
    public Treasure(Cell cell) {
        super(true, false, cell);
    }

    /* METHODS */

    @Override
    public String toString() {
        return this.getCell().getColumn() + "-" + this.getCell().getRow();
    }

    /* ACCESSORS */

}
