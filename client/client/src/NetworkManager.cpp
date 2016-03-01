/*!
 * \file NetworkManager.cpp
 * \brief Handle Network queries
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#include "NetworkManager.hpp"

//Constructor
NetworkManager::NetworkManager(bool debug) :
        Manager(),
        TriggerableObject()
{

	m_debug = debug;
	m_serverAddress = "127.0.0.1";
	m_serverPort = 6001;

	//TODO : Régler le problème avec fichier de Configuration
	/*
	m_serverAddress = m_ptr_config->getParam(SERVER_IP);
	m_serverPort = cast::toInt(m_ptr_config->getParam(SERVER_PORT));
	*/
	if(m_debug) {
		std::cout << "Server Address : " << m_serverAddress << std::endl;
		std::cout << "Server Port : " << m_serverPort << std::endl;
	}
}


//Destructor
NetworkManager::~NetworkManager(){

}



//Methods
bool NetworkManager::connect(){
	std::cout << "Waiting for connection... " << std::endl;

    m_status = m_socket.connect(m_serverAddress, m_serverPort);

    if (m_status != sf::Socket::Done) {
        std::cerr << "Unable to connect with server" << std::endl;
        return false;
    }

    std::cout << "Connection established !" << std::endl;
    std::cerr << "Socket status : " << m_status << std::endl;

    return true;
}

void NetworkManager::trigger(uint id){
    return;
}

void NetworkManager::trigger(uint id, std::vector< std::string> v){
    return;
}