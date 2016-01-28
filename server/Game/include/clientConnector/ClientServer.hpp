/*!
 * \file SFMLServer.hpp
 * \brief Server
 * \author Aredhele
 * \version 0.1
 * \date 2015-11-26
 */

#ifndef DEF_SFML_SERVER_HPP
#define DEF_SFML_SERVER_HPP

// Const
#define _DFLT_SMCO_   10
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

#include <clientConnector/tool.hpp>
#include "ClientThread.hpp"
#include "Configuration.hpp"

class SFMLServer
{
private:
    // SFML
    sf::TcpListener * m_ptr_listener;

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

    // thread handling
    std::vector < std::unique_ptr < sf::TcpSocket > > m_socketList;
    std::vector < std::unique_ptr < ClientThread > > m_threadList;

public:
    // Constructor
    SFMLServer(ConsoleDisplayer * displayer);
    SFMLServer(ConsoleDisplayer * displayer, Configuration * config);

    // Destructor
    ~SFMLServer();

    // Methods
    int start();
};

#endif // DEF_SFML_SERVER_HPP