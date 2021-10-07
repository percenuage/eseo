import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Axel on 19/12/2015.
 */
public class Main {

    public static void main(String[] args) throws Exception {
        Player playerA = new Player("Axel", new Pawn('X'));
        Player playerB = new Player("Kim", new Pawn('O'));
        Plateau plateau = new Plateau(playerA, playerB);
        play(plateau);
    }

    private static void play(Plateau plateau) throws Exception {
        Integer column, playerNumber = 0;
        Player player;
        Scanner scanner = new Scanner(System.in);

        System.out.println("- - - - - - - - - -");
        System.out.println("-     NEW GAME    -");
        System.out.println("- - - - - - - - - -");

        System.out.println(plateau);
         do {
             player = plateau.getPlayers()[playerNumber];
             column = player.chooseColumn(scanner);
             player.putPawn(column);
             System.out.println(plateau);

             playerNumber++;
             if (playerNumber >= plateau.getPlayers().length) {
                playerNumber = 0;
             }
        } while(!plateau.isPawnsAligned(player.getPawn()) && player.getPawnNumber() > 0);

        if (player.getPawnNumber() == 0) {
            System.out.printf("There is no winner...");
        } else {
            System.out.printf("The winner is : " + player + " !");
        }
        scanner.close();
    }
}
