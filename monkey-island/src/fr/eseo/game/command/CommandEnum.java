package fr.eseo.game.command;

/**
 * CommandEnum enum.
 *
 * @author Axel Gendillard
 */
public enum CommandEnum {

	/* COMMANDE CLIENT VERS SERVEUR */
	/**
	 * Inscription Client-Pirate [/I] {1}.
	 */
	NEW_PIRATE_CLIENT("/I"),
	/**
	 * Deplacement Pirate [/D X Y] (entre -1 et 1 avec au moins un 0) {1}.
	 */
	MOVE_PIRATE_CLIENT("/D"),

	/* COMMANDE SERVEUR VERS CLIENT */
	/**
	 * Identifiant pirate [/i id-X-Y-energy] (id == socket) {1}.
	 */
	PIRATE("/i"),
	/**
	 * Refus de déplacement [/A X-Y-energy] {1}.
	 */
	CORRECT_MOVE("/A"),
	/**
	 * Refus de déplacement [/R] {1}.
	 */
	INCORRECT_MOVE("/R"),
	/**
	 * Indication autres pirates [/P id1-X1-Y1-...] {1}.
	 */
	PIRATES("/P"),
	/**
	 * Indication nouveau pirate [/n id-X-Y] {*}.
	 */
	NEW_PIRATE_SERVER("/n"),
	/**
	 * Suppression pirate [/s id] {*} {1}.
	 */
	REMOVE_PIRATE("/s"),
	/**
	 * Deplacement pirate identifié [/p id-X-Y] {*}.
	 */
	MOVE_PIRATE_SERVER("/p"),
	/**
	 * Indication carte [/C l h c1l-...-ch1-...-chl] {1}.
	 */
	ISLAND("/C"),
	/**
	 * Indication position singes erratiques [/e X1-Y1-...]{*} {1}.
	 */
	CRAZY_MONKEYS("/e"),
	/**
	 * Indication position singes chasseurs [/c X2-Y2-...]{*} {1}.
	 */
	HUNTER_MONKEYS("/c"),
	/**
	 * Indication position rhum et visibilité [/B X1-Y1-vis1-...](vis1 == 0 ou
	 * 1) {*} {1}.
	 */
	RHUMS("/B"),
	/**
	 * Indication visibilité rhum [/b id-visible] {*} {1}.
	 */
	RHUM("/b"),
	/**
	 * Indication position tresor [/T X-Y] (si decouvert) {*}{1}.
	 */
	TREASURE("/T"),
	/**
	 * Indication nouvelle partie [/N] {*} {1}.
	 */
	NEW_GAME("/N");

	/**
	 * Command string attribute.
	 */
	private String command;

	/**
	 * Constructor.
	 * 
	 * @param command
	 *            String of the command.
	 */
	CommandEnum(String command) {
		this.command = command;
	}

	/**
	 * Parse the command string to the enum command.
	 * 
	 * @param command
	 *            String command.
	 * @return commandEnum The enum command.
	 * @throws NullPointerException
	 *             NullPointerException.
	 */
	public static CommandEnum fromString(String command) throws NullPointerException {
		if (command != null) {
			for (CommandEnum cmd : CommandEnum.values()) {
				if (cmd.toString().equals(command)) {
					return cmd;
				}
			}
		}
		throw new NullPointerException("This command does not exist : " + command);
	}

	/**
	 * ToString.
	 * 
	 * @return string String of the command class.
	 */
	@Override
	public String toString() {
		return this.command;
	}
}
