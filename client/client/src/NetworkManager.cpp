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
    //TODO : Changer le port en 6002
	m_serverPort = 6002;

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
/**
 *  Request sent to the server
 *  id 1 : get list of WarmUp
 *  id 1 : create WarmUp
 */
bool NetworkManager::request(sf::Int32 idRequest, std::string sRequest){

    sf::Packet packet;
    packet << idRequest << sRequest;

    m_status = m_socket.send(packet);

    if (m_status != sf::Socket::Done) {
        std::cerr << "Unable to connect with server" << std::endl;
        return false;
    }
    std::cout << "Request send !" << std::endl;
    std::cerr << "Socket status : " << m_status << std::endl;
    return true;
}
/**
 *  Request receive from the server
 *  id 3 : get list of WarmUp
 *  id 1 : create WarmUp
 */
sf::Packet *  NetworkManager::requestReceive(){
    sf::Packet  * packet = new sf::Packet();
    m_status = m_socket.receive(*packet);

    if (m_status == sf::Socket::Done) {
        std::cout << "Request receive !" << std::endl;
        std::cerr << "Socket status : " << m_status << std::endl;
        return packet;
    }
    else{
        std::cerr << "Unable to receive from server" << std::endl;
        return NULL;
    }
}


void NetworkManager::trigger(uint id){
    return;
}

void NetworkManager::trigger(uint id, std::vector< std::string> v){
    return;
}