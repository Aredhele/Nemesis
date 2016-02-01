/*!
 * \file SFMLServer.cpp
 * \brief Server
 * \author Aredhele
 * \version 0.1
 * \date 2015-11-26
 */

// Header

#include "clientConnector/ClientServer.hpp"

/*!
 * \brief Contructor
 */
ClientServer::ClientServer(ConsoleDisplayer * displayer) {
    m_running = false;
    m_multiIp = _DFLT_SMIP_;
    m_serverPort = _DFLT_SPORT_;
    m_serverAddress = _DFLT_SADDR_;
    m_serverMaxConnection = _DFLT_SMCO_;

    m_masterPort = _DFLT_MPORT_;
    m_masterCheck = _DFLT_MCHECK_;
    m_masterAddress = _DFLT_MADDR_;

    m_ptr_displayer = displayer;
}

/*!
 * \brief Contructor
 * \param serverPort the port of the server
 * \param serverAddress the address of the server
 */
ClientServer::ClientServer(ConsoleDisplayer * displayer, Configuration * config) {
    m_running = false;
    m_serverAddress = config->getParam(_SERVER_IP_);
    m_multiIp = cast::toBool(config->getParam(_SERVER_MIP_));
    m_serverPort = cast::toInt(config->getParam(_SERVER_PORT_));
    m_serverMaxConnection = cast::toInt(config->getParam(_SERVER_MCO_));

    m_masterAddress = config->getParam(_MSERV_IP_);
    m_masterPort = cast::toInt(config->getParam(_MSERV_PORT_));
    m_masterCheck = cast::toBool(config->getParam(_MSERV_CHECK_));

    m_ptr_displayer = displayer;
}

/*!
 * \brief Destructor
 */
ClientServer::~ClientServer() {
    delete m_ptr_listener;
    delete m_ptr_displayer;

    m_ptr_listener = nullptr;
    m_ptr_displayer = nullptr;
}

/*!
 * \brief Start the server
 */
int ClientServer::start() {
    m_running = true;
    m_ptr_listener = new sf::TcpListener();

    if(m_ptr_listener->listen(m_serverPort) != sf::Socket::Done) {
        m_ptr_displayer->displayMessage("Fail", "Unable to start server");
        return -1;
    }

    m_ptr_displayer->displaySimple("Info", "Server started on port : ");
    std::cout << m_serverPort << std::endl;
    m_ptr_displayer->displayMessage("Info", "Server is listening TCP connection !");
    m_ptr_displayer->displaySimple("Warn", "Server multi-ip (Disable by default) : ");
    if(m_multiIp) std::cout << "TRUE" << std::endl;
    else std::cout << "FALSE" << std::endl;

    m_ptr_displayer->displaySimple("Warn", "Server master check (Enable by default) : ");
    if(m_masterCheck) std::cout << "TRUE" << std::endl;
    else std::cout << "FALSE" << std::endl;

    std::cout << std::endl;
    while(m_running) {

        //TODO Creation du salon

        /*
        m_socketList.push_back(std::unique_ptr < sf::TcpSocket > (new sf::TcpSocket));

        if(m_ptr_listener->accept(
                *m_socketList[m_socketList.size() - 1].get()) == sf::Socket::Done) {

            m_ptr_displayer->displaySimple("Info", "Client connected with ip ");
            std::cout << m_socketList[m_socketList.size() - 1].get()->getRemoteAddress();
            std::cout << " on port ";
            std::cout << m_socketList[m_socketList.size() - 1].get()->getRemotePort();
            std::cout << std::endl;

            m_threadList.push_back(std::unique_ptr < ClientThread >
                                           (new ClientThread(m_socketList[m_socketList.size() - 1].get())));

            m_ptr_displayer->displayMessage("Info", "Client thread created");
            m_threadList[m_threadList.size() - 1].get()->start();
            m_ptr_displayer->displayMessage("Info", "Client thread started");

        } else {
            m_ptr_displayer->displayMessage("Fail", "Unable to accept client !");
            return -1;
        }*/
    }

    return 0;
}