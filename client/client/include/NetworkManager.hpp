/*!
 * \file NetworkManager.hpp
 * \brief Handle Network queries
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#ifndef DEF_NETWORK_MANAGER_HPP
#define DEF_NETWORK_MANAGER_HPP

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "Manager.hpp"
#include "TriggerableObject.hpp"

class NetworkManager : 
public Manager,
public TriggerableObject
{
	private:

        bool m_debug;
        std::string m_serverAddress;
        int m_serverPort;

        sf::Socket::Status m_status;
        sf::TcpSocket m_socket;


	public:

        NetworkManager(bool debug);
        ~NetworkManager();

        bool connect();
		void trigger(uint id);
		void trigger(uint id, std::vector < std::string> v);
};

#endif // DEF_NETWORK_MANAGER_HPP