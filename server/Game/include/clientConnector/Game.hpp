//
// Created by Jehan on 01/02/2016.
//

#ifndef SERVER_GAME_HPP
#define SERVER_GAME_HPP


#include <SFML/System/Thread.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Sleep.hpp>
#include <stdio.h>
#include <tool/tool.hpp>
#include <clientConnector/Player.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <string>
#include <vector>
#include <memory>
#include <iostream>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


class Game {
public:

    //Constructor
    Game(std::vector<bool>  * socketOccupe,
          std::string nom);
    //Destructor
    ~Game();

    // Etat
    enum Etat
    {
        Disponible,
        Indisponible
    };

    // Méthodes
    void init();
    int addPlayer(sf::TcpSocket * socket,
                      std::string nom, unsigned int indiceSocket);
    void delPlayer(int i);
    void launchThreadGame();




private:
    // Members
    Etat etatGame;
    sf::Thread thread;
    bool estEnMarche;

    // Sockets
    std::vector < bool > * socketOccupe;




    std::string nomHote;

    // Players list
    Player * tabPlayer[4];

    // Methods
    void threadGame();
    void broadcastRequest(sf::Packet packet);
};


#endif //GAME_WARMUP_HPP
