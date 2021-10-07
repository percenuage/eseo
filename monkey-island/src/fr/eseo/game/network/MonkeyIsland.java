package fr.eseo.game.network;

import fr.eseo.game.command.Command;
import fr.eseo.game.model.Island;
import fr.eseo.game.model.Monkey;
import fr.eseo.game.model.Pirate;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.ResourceBundle;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

import static fr.eseo.game.command.CommandEnum.*;

/**
 * MonkeyIsland class.
 *
 * @author Axel Gendillard
 */
public final class MonkeyIsland {

    /* ATTRIBUTES */

    /**
     * Configuration attribute.
     */
    public static final ResourceBundle CONFIGURATION = ResourceBundle.getBundle("Configuration");

    /**
     * Port attribute.
     */
    public static final Integer PORT = Integer.valueOf(CONFIGURATION.getString("SERVER_PORT"));

    /**
     * The island of a thousand perils.
     */
    public static Island island = Island.getInstance();

    /**
     * A set of all the clients.
     */
    public static Map<Integer, Communication> coms = new HashMap<>();

    /* CONSTRUCTORS */

    /**
     * Constructor private attribute.
     */
    private MonkeyIsland() {  }

    /* METHODS */

    /**
     * The appplication main method, which just listens on a port and
     * spawns client threads.
     * @param args The args of the main.
     */
    public static void main(String[] args) {

        try {

            // Start the monkey island game and open the socket.
            System.out.println("MonkeyIsland server is running.");
            ServerSocket listener = new ServerSocket(PORT);

            // Call a timeout to make each monkey move every time.
            ScheduledExecutorService execCrazy = Executors.newSingleThreadScheduledExecutor();
            for (Monkey monkey : island.getCrazyMonkeys()) {
            	execCrazy.scheduleAtFixedRate(monkey, 0, monkey.getSpeed(), TimeUnit.SECONDS);
            }
            ScheduledExecutorService execHunter = Executors.newSingleThreadScheduledExecutor();
            for (Monkey monkey : island.getHunterMonkeys()) {
            	execHunter.scheduleAtFixedRate(monkey, 0, monkey.getSpeed(), TimeUnit.SECONDS);
            }

            // Wait on new client connection.
            try {

                while (true) {
                    new Client(listener.accept()).start();
                }

            } finally {
                listener.close();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    /**
     * A client thread class.  Clients are spawned from the listening loop.
     */
    private static class Client extends Thread {

        /* ATTRIBUTES */

        /**
         * Communication attribute.
         */
        private Communication com;

        /* CONSTRUCTORS */

        /**
         * Constructs a client thread, squirreling away the socket.
         * All the interesting work is done in the run method.
         * @param socket The socket of the communication.
         */
        Client(Socket socket) {
            this.com = new Communication(socket);
        }

        /* METHODS */

        /**
         * ToString of Client class.
         * @return string The port of the communication.
         */
        @Override
        public String toString() {
            return "[" + this.com.getPort() + "] ";
        }

        /**
         * Run the client thread on connection to the server.
         */
        @Override
        public void run() {

            this.onConnection();

            try {
                // Accept and treat command from this client.
                while (true) {

                    String cmd = this.com.receiveMessage();

                    if (cmd == null) {
                        break;
                    }

                    try {
                        Command command = new Command(cmd);

                        this.switchCommand(command);

                    } catch (Exception e) {
                        System.err.println(this + e.getMessage());
                    }
                }

            } finally {

                this.onDisconnection();
            }
        }

        /**
         * Switch command on receiving a message.
         * @param command Command param.
         * @throws IndexOutOfBoundsException For index bound exception.
         */
        private void switchCommand(Command command) throws IndexOutOfBoundsException {
            Pirate pirate = null;
            switch (command.getCommandEnum()) {

                case NEW_PIRATE_CLIENT:
                    pirate = island.addPirate(this.com.getPort());
                    if (pirate != null) {
                        this.com.sendMessage(PIRATE, pirate.toStringWithEnergyAndId());
                        System.out.println(this + "Pirate has been created.");
                    } else {
                        System.err.println(this + "Pirate has already been created.");
                    }
                    break;

                case MOVE_PIRATE_CLIENT:
                    List<Integer> list = command.getValues();
                    pirate = island.movePirate(this.com.getPort(), list.get(0), list.get(1));
                    if (pirate != null) {
                        this.com.sendMessage(CORRECT_MOVE, pirate.toStringWithEnergy());
                        System.out.println(this + "Pirate has been moved.");
                    } else {
                        this.com.sendMessage(INCORRECT_MOVE.toString());
                        System.err.println(this + "Can't move your pirate.");
                    }
                    break;

                default:
                    System.err.println("Not implemented yet");
                    break;
            }
        }

        /**
         * On the connection of the new client.
         * Add the com's client to the map.
         * Send a message to notify the shape of the island.
         */
        private void onConnection() {
            System.out.println(this + "Connected");
            coms.put(this.com.getPort(), this.com);

            this.com.sendMessage(ISLAND, island.toString());
            this.com.sendMessage(PIRATES, island.getPirates().values());
            this.com.sendMessage(CRAZY_MONKEYS, island.getCrazyMonkeys());
            this.com.sendMessage(HUNTER_MONKEYS, island.getHunterMonkeys());
            this.com.sendMessage(RHUMS, island.getRhums());
        }

        /**
         * On the disconnection of the client.
         * Remove Pirate and client's com from the map.
         * Then, close client's socket.
         */
        private void onDisconnection() {
            System.err.println(this + "Disconnected");
            Pirate pirate = island.removePirate(this.com.getPort());
            try {
                island.getPirates().remove(pirate.getId());
                island.deleteObserver(pirate);
            } catch (NullPointerException e){
                System.err.println(this + "Pirate is null");
            }
            coms.remove(this.com.getPort());

            try {
                this.com.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        /* ACCESSORS */

    }

}
