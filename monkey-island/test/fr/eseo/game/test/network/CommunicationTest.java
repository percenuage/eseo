package fr.eseo.game.test.network;

import fr.eseo.game.model.Island;
import fr.eseo.game.network.Communication;
import fr.eseo.game.network.MonkeyIsland;
import org.junit.*;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

import static fr.eseo.game.command.CommandEnum.*;
import static org.junit.Assert.*;

/**
 * Test Communication class.
 * 
 * @author Axel Gendillard
 */

public class CommunicationTest {
	/**
	 * Server address.
	 */
	private static final String SERVER_ADDRESS = "localhost";
	/**
	 * Attribute communication.
	 */
	protected Communication communication;
	/**
	 * Attribute socket.
	 */
	protected Socket socket;

	/**
	 * Launch this method before testing.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Before
	public void setUp() throws Exception {
		this.socket = new Socket(SERVER_ADDRESS, MonkeyIsland.PORT);
		this.communication = new Communication(this.socket);
	}

	/**
	 * Launch this method after each test.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@After
	public void tearDown() throws Exception {
		this.communication.close();
	}

	/**
	 * Test sendMessage.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSendMessage_string() throws Exception {
		this.communication.sendMessage(NEW_PIRATE_CLIENT.toString());
		String expected = ISLAND.toString() + " " + MonkeyIsland.CONFIGURATION.getString("ISLAND_COLUMNS") + " "
				+ MonkeyIsland.CONFIGURATION.getString("ISLAND_ROWS") + " "
				+ MonkeyIsland.CONFIGURATION.getString("ISLAND_SHAPE");
		assertEquals(expected, this.communication.receiveMessage());
	}

	/**
	 * Test sendMessage enum.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSendMessage_enum_string() throws Exception {
		this.communication.sendMessage(NEW_PIRATE_CLIENT, "");
		String expected = ISLAND.toString() + " " + MonkeyIsland.CONFIGURATION.getString("ISLAND_COLUMNS") + " "
				+ MonkeyIsland.CONFIGURATION.getString("ISLAND_ROWS") + " "
				+ MonkeyIsland.CONFIGURATION.getString("ISLAND_SHAPE");
		assertEquals(expected, this.communication.receiveMessage());
	}

	/**
	 * Test sendMessage enum list.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testSendMessage_enum_list() throws Exception {
		List<Object> list = new ArrayList<>();
		list.add(0);
		this.communication.sendMessage(NEW_PIRATE_CLIENT, list);
		String expected = ISLAND.toString() + " " + MonkeyIsland.CONFIGURATION.getString("ISLAND_COLUMNS") + " "
				+ MonkeyIsland.CONFIGURATION.getString("ISLAND_ROWS") + " "
				+ MonkeyIsland.CONFIGURATION.getString("ISLAND_SHAPE");
		assertEquals(expected, this.communication.receiveMessage());
	}

	/**
	 * Test receiveMessage valid.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testReceiveMessage_valid() throws Exception {
		String expected = ISLAND.toString() + " " + MonkeyIsland.CONFIGURATION.getString("ISLAND_COLUMNS") + " "
				+ MonkeyIsland.CONFIGURATION.getString("ISLAND_ROWS") + " "
				+ MonkeyIsland.CONFIGURATION.getString("ISLAND_SHAPE");
		assertEquals(expected, this.communication.receiveMessage());
	}

	/**
	 * Test receiveMessage invalid.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testReceiveMessage_invalid() throws Exception {
		this.communication.close();
		assertNull(this.communication.receiveMessage());
	}

	/**
	 * Test close communication.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testClose() throws Exception {
		this.communication.close();
		assertEquals(Boolean.TRUE, this.socket.isClosed());
	}

	/**
	 * Test getSocket.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetSocket() throws Exception {
		assertEquals(this.communication.getSocket(), this.socket);
	}

	/**
	 * Test getPort.
	 * 
	 * @throws java.lang.Exception
	 *             toute exception.
	 */
	@Test
	public void testGetPort() throws Exception {
		assertEquals(Integer.valueOf(this.socket.getPort()), this.communication.getPort());
	}
}