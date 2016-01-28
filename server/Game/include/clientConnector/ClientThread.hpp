//
// Created by Jehan on 28/01/2016.
//

#ifndef SERVER_CLIENTTHREAD_HPP
#define SERVER_CLIENTTHREAD_HPP

#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class ClientThread {
private:
    //Members
    sf::Thread m_thread;
    sf::Time * m_ptr_clientTime;
    sf::Clock * m_ptr_clientClock;

    //Methods
    void client();

public:

    ClientThread(sf::TcpSocket *  clientSocket);
};


#endif //SERVER_CLIENTTHREAD_HPP
