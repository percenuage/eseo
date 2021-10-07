/**
 * Created by Axel on 19/12/2015.
 */
public class Pawn {

    public static final char DEFAULT_PAWN_SHAPE = '.';

    private Character shape;

    public Pawn(char shape) {
        this.shape = new Character(shape);
    }

    public Pawn() {
        this(DEFAULT_PAWN_SHAPE);
    }

    public Boolean isDefaultShape() {
        return this.shape.equals(DEFAULT_PAWN_SHAPE);
    }

    @Override
    public String toString() {
        return shape.toString();
    }

    public Character getShape() {
        return shape;
    }
}
