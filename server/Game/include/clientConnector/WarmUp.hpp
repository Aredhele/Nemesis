//
// Created by Jehan on 01/02/2016.
//

#ifndef SERVER_WARMUP_HPP
#define SERVER_WARMUP_HPP


#include <SFML/System/Thread.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Sleep.hpp>
#include <stdio.h>
#include <tool/tool.hpp>
#include <clientConnector/Player.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include "tool/Configuration.hpp"
#include <string>
#include <vector>
#include <memory>
#include "Game.hpp"
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


class WarmUp {
public:

    //Constructor
    WarmUp(int i, ConsoleDisplayer * displayer,
          std::vector<bool>  * socketOccupe,
          std::vector < Game * > * listePartie,
          std::string nom);
    //Destructor
    ~WarmUp();

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
    void launchThreadWarmUp();

    // Getters
    Etat getStateWarmUp();
    int getNbWarmUp();
    std::string getMDJName();

    void setMDJName(std::string hote);


private:
    // Members
    Etat etatWarmUp;
    ConsoleDisplayer * displayer;
    sf::Thread thread;
    bool estEnMarche;

    // Sockets
    std::vector < bool > * socketOccupe;

    // game list
    std::vector < Game * > * listePartie;

    int numeroWarmUp;
    std::string nomHote;

    // Players list
    Player * tabPlayer[4];

    // Methods
    void threadWarmUp();
    void gererRequete(sf::Int32 idRequest, std::string sRequest,
                      sf::TcpSocket * socket, int numeroPlayer);
    void launchGame(); //TODO Creer Game
    bool lockCarac(std::string sRequest, int nbPLayer);
    void sendModifLockCarac(std::string sRequest1, int numeroPlayer);
};


#endif //SERVER_WARMUP_HPP
