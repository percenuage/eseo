import java.util.Scanner;

/**
 * Created by Axel on 19/12/2015.
 */
public class Player {

    public static final int INITIAL_PAWN_NUMBER = 21;

    private String name;
    private Pawn pawn;
    private Integer pawnNumber;
    private Plateau plateau;

    public Player(String name, Pawn pawn) {
        this.name = name;
        this.pawn = pawn;
        this.pawnNumber = new Integer(INITIAL_PAWN_NUMBER);
    }

    public void putPawn(Integer column) throws Exception {
        if (plateau.isColumnAvailable(column)) {
            int row = Plateau.PLATEAU_ROWS;
            while(row-- >= 0) {
                if (plateau.isCellAvailable(column, row)) {
                    plateau.setPawnInCell(pawn, column, row);
                    pawnNumber--;
                    break;
                }
            }
        }
    }

    public Integer chooseColumn(Scanner scanner) throws Exception {
        Integer column;
        do {
            System.out.println("Player " + this + ". Enter column number [1-" + Plateau.PLATEAU_COLUMNS + "] : ");
            try {
                column = Integer.valueOf(scanner.next());
            } catch (NumberFormatException e) {
                column = -1;
            }
        } while (column < 1 || column > Plateau.PLATEAU_COLUMNS || !plateau.isColumnAvailable(column - 1));
        return column - 1;
    }

    @Override
    public String toString() {
        return this.name + " (" + this.pawnNumber + ")";
    }

    public Pawn getPawn() {
        return pawn;
    }

    public Integer getPawnNumber() {
        return pawnNumber;
    }

    public void setPlateau(Plateau plateau) {
        this.plateau = plateau;
    }

    public Plateau getPlateau() {
        return plateau;
    }
}
