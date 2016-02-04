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
#include "Game.hpp"

class WarmUp {
public:

    //Constructor
    WarmUp(int i, ConsoleDisplayer * displayer,
          std::vector<bool>  * socketOccupe,
          std::vector < Game * > * listePartie);
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
    void gererRequete(char requete[1024], std::size_t, sf::TcpSocket *, int);
    //void launchGame(); //TODO Creer Game
};


#endif //SERVER_WARMUP_HPP
