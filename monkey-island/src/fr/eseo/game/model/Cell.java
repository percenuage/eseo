package fr.eseo.game.model;

/**
 * Class Cell.
 *
 * @author Axel Gendillard
 */
public class Cell {

    /* ATTRIBUTES */

    /**
     * Attribute row.
     */
    private Integer row;

    /**
     * Attribute column.
     */
    private Integer column;

    /**
     * Attribute type.
     */
    private Integer type;

    /**
     * Attribute character.
     */
    private Character character;

    /**
     * Attribute element.
     */
    private Element element;

    /**
     * Attribute element.
     */
    private Island island;

    /**
     * Attribute static final WATER.
     */
    public static final Integer WATER = 0;

    /**
     * Attribute static final EARTH.
     */
    public static final Integer EARTH = 1;

    /* CONSTRUCTORS */

    /**
     * Contructor Cell.
     * @param row Row (Y).
     * @param column Column (X).
     * @param type Type (Water or Earth).
     * @param island Island.
     */
    public Cell(Integer row, Integer column, Integer type, Island island) {
        this.row = row;
        this.column = column;
        this.type = type;
        this.island = island;
    }

    /* METHODS */

    /**
     * Check if the cell is accessible (only on earth).
     * @return boolean Whether the cell is accessible or not.
     */
    public Boolean canAccess() {
        return this.type.equals(EARTH);
    }

    /* ACCESSORS */

    /**
     * Getter row.
     * @return integer
     */
    public Integer getRow() {
        return this.row;
    }

    /**
     * Setter row.
     * @param row Row.
     */
    public void setRow(Integer row) {
        this.row = row;
    }

    /**
     * Getter column.
     * @return integer
     */
    public Integer getColumn() {
        return this.column;
    }

    /**
     * Setter column.
     * @param column Column.
     */
    public void setColumn(Integer column) {
        this.column = column;
    }

    /**
     * Getter type.
     * @return integer
     */
    public Integer getType() {
        return this.type;
    }

    /**
     * Setter type.
     * @param type Type.
     */
    public void setType(Integer type) {
        this.type = type;
    }

    /**
     * Getter character.
     * @return character
     */
    public Character getCharacter() {
        return this.character;
    }

    /**
     * Setter character.
     * @param character Character.
     */
    public void setCharacter(Character character) {
        this.character = character;
    }

    /**
     * Getter element.
     * @return element
     */
    public Element getElement() {
        return this.element;
    }

    /**
     * Setter element.
     * @param element Element.
     */
    public void setElement(Element element) {
        this.element = element;
    }

    /**
     * Getter island.
     * @return island
     */
    public Island getIsland() {
        return this.island;
    }

    /**
     * Setter island.
     * @param island Island.
     */
    public void setIsland(Island island) {
        this.island = island;
    }
}
