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
        TriggerableObject(),
        m_threadReceiveRequest(&NetworkManager::requestReceive, this)
{

	m_debug = debug;
    //m_serverAddress = "25.76.184.229";
    m_serverAddress = "127.0.0.1";
	m_serverPort = 6002;
    m_hasPacket = 0;

	//TODO : Régler le problème avec fichier de Configuration
	/*
	m_serverAddress = m_ptr_config->getParam(SERVER_IP);
	m_serverPort = cast::toInt(m_ptr_config->getParam(SERVER_PORT));
	*/
	if(m_debug) {
		std::cout << "Server Address : " << m_serverAddress << std::endl;
		std::cout << "Server Port : " << m_serverPort << std::endl;
	}

    //sf::Thread thread(&requestReceive);

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

    m_socket.setBlocking(true);


    return true;
}

/**
 *  Request sent to the server
 *  id 1 : get list of WarmUp
 *  id 1 : create WarmUp
 */
bool NetworkManager::request(int idRequest, std::string sRequest, std::string sRequest2) {

    sf::Packet packet;
    if(sRequest2!="")
        packet << idRequest << sRequest;
    else
        packet << idRequest << sRequest << sRequest2;

    m_status = m_socket.send(packet);

    if (m_status != sf::Socket::Done) {
        std::cerr << "Unable to connect with server" << std::endl;
        return false;
    }

    std::cout << "Request send : " << idRequest <<", argument : "<< sRequest << " ; " << sRequest2 << std::endl;
    return true;
}
/**
 *  Request receive from the server
 *  id 3 : get list of WarmUp
 *  id 1 : create WarmUp
 */

void NetworkManager::requestReceive(){
    //sf::Packet  * packet = new sf::Packet();
    while(true){

        sf::Packet newPacket;
        m_status = m_socket.receive(newPacket);
        if (m_status == sf::Socket::Done) {
            m_packet.push_back(newPacket);
            //m_packet = &packet;
            //std::cout << "Request receive !" << std::endl;
            m_hasPacket = m_hasPacket + 1;
            //return packet;
        }
        else if(m_status == sf::Socket::Disconnected){
            std::cerr << "Déconnecte du serveur " << std::endl;
            break;
        }
        else{
            std::cerr << "Unable to receive from server" << std::endl;
            m_hasPacket = 0;
            //return NULL;
        }
    }
}

void NetworkManager::trigger(uint id){
    return;
}

void NetworkManager::trigger(uint id, std::vector< std::string> v){
    return;
}


void NetworkManager::setPacket(sf::Packet packet){
    m_packet.push_back(packet);
}

std::vector <sf::Packet>  NetworkManager::getPacket(){
    /*m_hasPacket = m_hasPacket -1;
    sf::Packet* tmp = &m_packet.at(0);
    m_packet.erase(m_packet.begin());*/
    m_hasPacket = 0;
    std::vector <sf::Packet> tmp = m_packet;
    m_packet.clear();
    return tmp;
}

void NetworkManager::setHasPacket(bool hasPacket){
    m_hasPacket = hasPacket;
}

bool NetworkManager::getHasPacket(){
    return (m_hasPacket>0);
}

void NetworkManager::startThread(){
    m_threadReceiveRequest.launch();
}

void NetworkManager::stopThread(){
    m_threadReceiveRequest.terminate();
}


