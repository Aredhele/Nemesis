

#ifndef DEF_SFML_SERVER_HPP
#define DEF_SFML_SERVER_HPP


#include <iostream>
#include "ClientThread.hpp"
#include "WarmUp.hpp"

class ClientServer
{
private:

    // Members
    bool m_running;

    int m_serverPort;


    //Gestion des sockets
    sf::TcpListener socketTCP;
    std::vector < std::unique_ptr < sf::TcpSocket > > listeSocket;
    std::vector < bool > listeVerifSocket;
    std::vector < bool > listeVerifSocketHelper;

    // Socket à ne plus écouter (En warmUp / Game)
    std::vector < bool > listeSocketOccupee;

    //Gestion des WarmUps
    std::vector < WarmUp * > listeWarmUp;
    // Gestion des parties
    std::vector < Game * > listeGame;

    int indiceClient;

    //Methods
    void listSocketManager();
    void requestManager( sf::Int32 idRequest, std::string sRequest,
                        sf::TcpSocket * socket, int indiceSocket);
    std::string getWarmUpList();
    bool joinWarmUp(sf::TcpSocket * socket, std::string param,
                    int indiceSocket);

public:
    // Constructor
    ClientServer();

    // Destructor
    ~ClientServer();

    // Methods
    int start();
    void initialiser();

};

#endif // DEF_SFML_SERVER_HPP