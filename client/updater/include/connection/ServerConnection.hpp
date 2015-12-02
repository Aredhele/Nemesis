#ifndef UPDATER_SERVERCONNECTION_H
#define UPDATER_SERVERCONNECTION_H

#include <iostream>
#include "string"
#include <vector>

class ServerConnection{
private:
    //Configuration m_conf;
    //Socket m_socket;

    std::string receiveFileName();
    std::string receiveFilePath();
    std::string receiveFileContent();

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
    std::vector<std::string> getFileInfoList();

};



#endif //UPDATER_SERVERCONNECTION_H
