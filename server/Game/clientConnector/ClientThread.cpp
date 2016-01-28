//
// Created by Jehan on 28/01/2016.
//

#include "clientConnector/ClientThread.hpp"

ClientThread::ClientThread(sf::TcpSocket * clientSocket) :
        m_thread(&ClientThread::client, this) {

    m_ptr_clientTime = nullptr;
    m_ptr_clientClock = nullptr;
}

void ClientThread::client() {

}
