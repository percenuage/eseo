package fr.eseo.game.network;

import fr.eseo.game.command.CommandEnum;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Collection;

/**
 * Communication class.
 *
 * @author Axel Gendillard
 */
public class Communication {

    /* ATTRIBUTES */

    /**
     * Static attribute pending command enum.
     */
    public static CommandEnum pendingCommand = null;

    /**
     * Attribute socket.
     */
    private Socket socket;

    /**
     * Attribute PrintWritter.
     */
    private PrintWriter out;

    /**
     * Attribute BufferedReader.
     */
    private BufferedReader in;

    /* CONSTRUCTORS */

    /**
     * Constructor Communication.
     * @param socket Client's socket.
     */
    public Communication(Socket socket) {
        this.socket = socket;
        try {
            this.out = new PrintWriter(this.socket.getOutputStream(), true);
            this.in = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /* METHODS */

    /**
     * Send a message with PrintWritter class.
     * @param message A message string.
     */
    public void sendMessage(String message) {
        this.out.println(message);
        System.out.println(this + message);
    }

    /**
     * Send a message with a commandEnum and a string.
     * @param commandEnum The enum command.
     * @param values The string values.
     */
    public void sendMessage(CommandEnum commandEnum, String values) {
        this.sendMessage(commandEnum + " " + values);
    }

    /**
     * Send a message with a commandEnum and a collection of object.
     * @param commandEnum The enum command.
     * @param list The collection of object.
     */
    public void sendMessage(CommandEnum commandEnum, Collection< ? > list) {
        this.sendMessage(commandEnum, this.getStringFromList(list));
    }

    /**
     * Receive the message from the client's socket.
     * @return message. The received message.
     */
    public String receiveMessage() {
        String message = "";
        try {
            message = this.in.readLine();
        } catch (IOException e) {
            message = null;
        }
        System.out.println(this + message);
        return message;
    }

    /**
     * Close the socket of the communication.
     * @throws IOException IOException.
     */
    public void close() throws IOException {
        this.socket.close();
    }

    @Override
    public String toString() {
        return "[" + this.socket.getPort() + "] ";
    }

    /**
     * Parse a collection of object to a standard string message.
     * @param list A collection of object.
     * @return string A standard message.
     */
    private String getStringFromList(Collection< ? > list) {
        StringBuilder sb = new StringBuilder();
        for (Object o : list) {
            sb.append(o.toString()).append("-");
        }
        if (sb.length() > 0) {
            sb.deleteCharAt(sb.length() - 1);
        }
        return sb.toString();
    }

    /* ACCESSORS */

    /**
     * Getter of the port attribute.
     * @return port The socket's port.
     */
    public Integer getPort() {
        return this.socket.getPort();
    }

    /**
     * Getter of the socket attribute.
     * @return socket The socket of the communication.
     */
    public Socket getSocket() {
        return this.socket;
    }
}
