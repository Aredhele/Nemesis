#ifndef UPDATER_SERVERCONNECTION_H
#define UPDATER_SERVERCONNECTION_H

#include <iostream>
#include "string"
#include <rpcndr.h>

class ServerConnection{
private:
    //Configuration m_conf;
    //Socket m_socket;
public:
    //Constructor
    ServerConnection();
    //Destructor
    ~ServerConnection();

    boolean connect();
    boolean disconnect();
    boolean sendHashFile(std::string hash);
    boolean sendNameFile(std::string name);
    boolean sendPathFile(std::string path);
    std::string receiveFileName(std::string name);
    std::string receiveFilePath(std::string name);
    std::string receiveFileContent(std::string name);
};



#endif //UPDATER_SERVERCONNECTION_H
