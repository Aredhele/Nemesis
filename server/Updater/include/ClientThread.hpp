/*!
 * \file ClientThread.hpp
 * \brief Function object for client thread
 * \author Aredhele
 * \version 0.1
 * \date 2015-11-26
 */

#ifndef DEF_CLIENT_THREAD_HPP
#define DEF_CLIENT_THREAD_HPP

#define _MAX_CLIENT_TIMEOUT_ 30

// Header
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "tool.hpp"
#include "FileManager.hpp"
#include "Parser.hpp"
#include "ClientThreadException.hpp"

class ClientThread
{
	private:
		// Members
		HashTool * m_ptr_hashTool;
		sf::Thread m_thread;	
		sf::Time * m_ptr_clientTime;
		sf::Clock * m_ptr_clientClock;
		sf::Socket::Status m_statusSocket;
		sf::TcpSocket * m_ptr_clientSocket;
		FileManager * m_ptr_fileManager;
		ConsoleDisplayer * m_ptr_displayer;

		// Methods
		void client();

	public:
		// Constructor
		ClientThread(sf::TcpSocket *  clientSocket);

		// Destructor
		~ClientThread();

		// Methods
		void start();
		void stop();
}; 

#endif // DEF_CLIENT_THREAD_HPP