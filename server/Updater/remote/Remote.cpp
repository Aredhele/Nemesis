/**
 * \brief Remote to send files to client
 * \file Remote.hpp
 * \author Aredhele
 * \version 0.1
 * \date 20/11/2015
 * \class Remote
 */

#include "Remote/Remote.hpp"

/**
 * \brief namespace function
 */
unsigned short utility::toShortInt(std::string value) {
    unsigned short ret;
    if(!(std::istringstream(value) >> ret)) return  ret;
    else return NULL;
}

/**
 * \brief Constructor.
 * \param config The configuration File
 */
Remote::Remote(Configuration * config, ConsoleDisplayer * displayer) {
    m_ptr_configuration = config;
    m_ptr_displayer = displayer;
    m_running = false;
}

/**
 * \brief Destructor.
 */
Remote::~Remote() {
    delete m_ptr_configuration;
    delete m_ptr_displayer;
    m_ptr_configuration = 0;
    m_ptr_displayer = 0;
}

/**
 * \brief Initialize the server
 */
int Remote::init() {
    struct in_addr remoteAddress;
    struct hostent * host;
    char hostName[_MAX_HOST_LENGHT_];
    WSADATA wsaData;

    if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        m_ptr_displayer->displayWarn("Launching WSAStartup");
        return EXIT_FAILURE;
    }

    if(gethostname(hostName, _MAX_HOST_LENGHT_) == SOCKET_ERROR) {
        m_ptr_displayer->displayWarn("Calling getHostName : " + WSAGetLastError());
        return EXIT_FAILURE;
    }

    if((host = gethostbyname(hostName)) == NULL){
        m_ptr_displayer->displayWarn("Calling getHostName : " + WSAGetLastError());
        return EXIT_FAILURE;
    }

    std::cout << "h_lenght : " << host->h_length << std::endl;
    std::cout << "h_addrtype : " << host->h_addrtype << std::endl;
    std::cout << "h_name : " << host->h_name << std::endl;
    // std::cout << "h_addr_list[0] : " << host->h_addr_list[0] << std::endl;

    memcpy(&remoteAddress.s_addr, host->h_addr_list[0], sizeof(remoteAddress.s_addr));
    m_serverAddr.sin_family = AF_INET;
    m_serverAddr.sin_port = htons(utility::toShortInt(m_ptr_configuration->getParam("SERVER_PORT")));
    m_serverAddr.sin_addr.s_addr = inet_addr(inet_ntoa(remoteAddress));
    // m_serverAddr.sin_addr.s_addr = inet_addr(m_ptr_configuration->getParam("SERVER_IP").c_str());

    m_ptr_displayer->displaySimple("Remote IP : ");
    std::cout << inet_ntoa(remoteAddress) << std::endl;
    m_ptr_displayer->displaySuccess("Remote correctly initialized");

    return EXIT_SUCCESS;
}

/**
 * \brief start the server
 */
int Remote::start() {
    struct thread_param param;
    SOCKADDR_IN clientAddr;
    HANDLE hProcessThread;
    SOCKET newConnection;
    int clientAddrLen;

    if((m_listeningSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET){
        m_ptr_displayer->displayWarn("Creating remote socket : " + WSAGetLastError());
        WSACleanup();
        return EXIT_FAILURE;
    }

    if( bind( m_listeningSocket, (SOCKADDR *)&m_serverAddr, sizeof(m_serverAddr)) == SOCKET_ERROR ){
        m_ptr_displayer->displayFailure("Bind Failed with error : " + WSAGetLastError());
        m_ptr_displayer->displayInfo("The port is maybe already used ?");
        closesocket(m_listeningSocket);
        WSACleanup();
        return EXIT_FAILURE;
    }

    if( listen(m_listeningSocket, 5) == SOCKET_ERROR ) {
        m_ptr_displayer->displayFailure("Listen Failed with error : " + WSAGetLastError());
        closesocket(m_listeningSocket);
        WSACleanup();
        return EXIT_FAILURE;
    }

    m_ptr_displayer->displaySuccess("Remote started : Listening port : " + m_ptr_configuration->getParam("SERVER_PORT"));
    m_running = true;
    clientAddrLen = sizeof(clientAddr);

    while(m_running){

        if((newConnection = accept(m_listeningSocket, (SOCKADDR *) &clientAddr, &clientAddrLen)) == INVALID_SOCKET){
            m_ptr_displayer->displayFailure("Accept Failed with error : " + WSAGetLastError());
            closesocket(m_listeningSocket);
            WSACleanup();
            return EXIT_FAILURE;
        }

        param.strt_remote = this;
        param.strt_socket = newConnection;

        m_ptr_displayer->displaySimple("Client connected, Address : ");
        std::cout << ntohs(clientAddr.sin_port ) << " - Port : " << inet_ntoa(clientAddr.sin_addr ) << std::endl;

        hProcessThread = CreateThread(NULL, 0,&Remote::threadLaucnher, &param,0,NULL);
        if (hProcessThread == NULL){
            m_ptr_displayer->displayFailure("creatThread Failed with error : " + WSAGetLastError());
        }
    }

    return EXIT_SUCCESS;
}

/**
 * \brief Pause the game
 */
int Remote::pause (){
    m_running = false;
    m_ptr_displayer->displayInfo("Server paused");
    closesocket(m_listeningSocket);
    return EXIT_SUCCESS;
}

DWORD Remote::m_clientThread(SOCKET soc) {

    m_ptr_displayer->displayInfo("Client thread started");
    char buffer[255];

    recv(soc, buffer, sizeof(buffer), 0);
    std::cout << buffer << std::endl;

    return 0;
}