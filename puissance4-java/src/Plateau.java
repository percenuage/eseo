import java.util.Arrays;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Axel on 19/12/2015.
 */
public class Plateau {

    public static final int PLATEAU_COLUMNS = 7;
    public static final int PLATEAU_ROWS = 6;
    public static final int PLATEAU_CELLS = PLATEAU_COLUMNS * PLATEAU_ROWS;

    private Pawn[] grid;
    private Player[] players;

    public Plateau(Player... players) {
        this.players = players;
        for (Player p : this.players){
            p.setPlateau(this);
        }
        this.grid = new Pawn[PLATEAU_CELLS];
        Arrays.fill(this.grid, new Pawn());
    }

    public Boolean isColumnAvailable(Integer column) throws Exception {
        return this.isCellAvailable(column, 0);
    }

    public Boolean isCellAvailable(Integer column, Integer row) throws Exception {
        if (column < 0  || column >= PLATEAU_COLUMNS) {
            throw new Exception("The column number must be between 0 and " + PLATEAU_COLUMNS);
        }
        if (row < 0 || row >= PLATEAU_ROWS) {
            throw new Exception("The row number must be between 0 and " + PLATEAU_ROWS);
        }
        return grid[row * PLATEAU_COLUMNS + column].isDefaultShape();
    }

    public void setPawnInCell(Pawn pawn, Integer column, Integer row) throws Exception {
        if (column < 0  || column >= 7) {
            throw new Exception("The column number must be between 0 and 6");
        }
        if (row < 0 || row >= 6) {
            throw new Exception("The row number must be between 0 and 5");
        }
        grid[row * PLATEAU_COLUMNS + column] = pawn;
    }

    public Boolean isPawnsAligned(Pawn pawn) {
        String sGrid = Arrays.toString(this.grid);
        sGrid = sGrid.replace(",", "").replace(" ", "").replace("[", "").replace("]", "");
        StringBuilder sb = new StringBuilder("|");
        for (int i = 0; i < PLATEAU_CELLS; i += PLATEAU_COLUMNS) {
            sb.append(sGrid.substring(i, i + PLATEAU_COLUMNS)).append("|");
        }
        String regexp = "(X.{6}){3}X|(X.{7}){3}X|(X.{8}){3}X|X{4}".replace("X", pawn.getShape().toString());
        Pattern pattern = Pattern.compile(regexp);
        Matcher matcher = pattern.matcher(sb.toString());
        return matcher.find();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("║1║2║3║4║5║6║7║\n");
        for (int i = 0; i < PLATEAU_CELLS; i++) {
            sb.append("║").append(grid[i]);
            if ((i + 1) % 7 == 0 && i <= 35) {
                sb.append("║\n").append("╠ ╬ ╬ ╬ ╬ ╬ ╬ ╣\n");
            }
        }
        sb.append("║\n").append("╚ ╩ ╩ ╩ ╩ ╩ ╩ ╝");
        return sb.toString();
    }

    public Player[] getPlayers() {
        return players;
    }
}
