//
// Created by Jehan on 03/02/2016.
//

#ifndef SERVER_PLAYER_HPP
#define SERVER_PLAYER_HPP


#include <SFML/Network/TcpSocket.hpp>
#include <string>

class Player {

public:
    //Constructor
    Player();

    //Destructor
    ~Player();

    // Méthodes
    void init();
    void init(sf::TcpSocket * socket,
              std::string nom,
              unsigned int indiceSocket,
              int numPlayer);

    void disconnect();

    // Accesseurs
    bool isHere();

    unsigned int getIndiceSocket();
    int getNumeroPlayer();

    sf::TcpSocket * getSocket();
    std::string getNamePlayer();

private:
    // Membres
    sf::TcpSocket * socketPlayer;
    unsigned int indiceSocket;
    int numberPlayer;

    bool isPlayerHere;

    std::string namePlayer;

};


#endif //SERVER_PLAYER_HPP
