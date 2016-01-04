#ifndef UPDATER_SERVERCONNECTION_H
#define UPDATER_SERVERCONNECTION_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "string"
#include "FileManager.hpp"
#include <vector>
#include <stdio.h>

class ServerConnection{
private:
    //Configuration m_conf;
    //Socket m_socket;

    sf::Socket::Status m_status;
    sf::TcpSocket m_socket;

public:
    //Constructor
    ServerConnection();
    //Destructor
    ~ServerConnection();

    bool connect();

    void sendSizeList(int size);

    void sendPathHash(std::vector<std::vector<std::string>> list);

    int getNumberFile();

    void receiveFiles(int nbFile, std::string path, FileManager *m_ptr_filemanager);

    int m_sizeList;
};



#endif //UPDATER_SERVERCONNECTION_H
