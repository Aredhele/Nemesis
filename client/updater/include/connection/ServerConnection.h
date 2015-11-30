#ifndef UPDATER_SERVERCONNECTION_H
#define UPDATER_SERVERCONNECTION_H

#include <iostream>
#include "string"

class ServerConnection{
private:
    //Configuration m_conf;
    //Socket m_socket;
public:
    //Constructor
    ServerConnection();
    //Destructor
    ~ServerConnection();

    bool connect();
    bool disconnect();
    bool sendHashFile(std::string hash);
    bool sendNameFile(std::string name);
    bool sendPathFile(std::string path);
    std::string receiveFileName(std::string name);
    std::string receiveFilePath(std::string name);
    std::string receiveFileContent(std::string name);
};



#endif //UPDATER_SERVERCONNECTION_H
