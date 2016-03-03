

#ifndef DEF_SFML_SERVER_HPP
#define DEF_SFML_SERVER_HPP

// Const
#define _DFLT_SMCO_   10
//TODO : Recompiler le server avec le port 6002
#define _DFLT_SPORT_  6001
#define _DFLT_MPORT_  6000
#define _DFLT_SMIP_   false
#define _DFLT_MCHECK_ false
#define _DFLT_SADDR_  "127.0.0.1"
#define _DFLT_MADDR_  "127.0.0.1"

#define _SERVER_MIP_  "SERVER_ALLOW_MULTI_IP"
#define _SERVER_PORT_ "SERVER_PORT"
#define _SERVER_MCO_  "SERVER_MAX_CONNECTION"
#define _SERVER_IP_   "SERVER_IP"

#define _MSERV_CHECK_ "SERVER_MASTER_CHECK"
#define _MSERV_PORT_  "SERVER_MASTER_PORT"
#define _MSERV_IP_    "SERVER_MASTER_IP"

// Header
#include <string>
#include <vector>
#include <memory>


#include "ClientThread.hpp"
#include "tool/Configuration.hpp"
#include "WarmUp.hpp"

class ClientServer
{
private:

    // Members
    bool m_running;
    bool m_multiIp;
    bool m_masterCheck;

    int m_serverPort;
    int m_masterPort;
    int m_serverMaxConnection;

    std::string m_masterAddress;
    std::string m_serverAddress;

    ConsoleDisplayer * m_ptr_displayer;
    Configuration * m_ptr_configuration;

    // Gestion des thread
    std::vector < std::unique_ptr < sf::TcpSocket > > m_socketList;
    std::vector < std::unique_ptr < ClientThread > > m_threadList;

    //Gestion des sockets
    sf::TcpListener socketTCP;
    std::vector < std::unique_ptr < sf::TcpSocket > > listeSocket;
    std::vector < bool > listeVerifSocket;
    std::vector < bool > listeVerifSocketHelper;

    // Socket à ne plus écouter
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
    void joinWarmUp(sf::TcpSocket * socket, std::string param,
                    int indiceSocket);

public:
    // Constructor
    ClientServer(ConsoleDisplayer * displayer);
    ClientServer(ConsoleDisplayer * displayer, Configuration * config);

    // Destructor
    ~ClientServer();

    // Methods
    int start();
    void initialiser();

};

#endif // DEF_SFML_SERVER_HPP