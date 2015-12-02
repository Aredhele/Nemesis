#ifndef UPDATER_FTPMANAGER_H
#define UPDATER_FTPMANAGER_H

#include <iostream>
#include <string>
#include "ServerConnection.h"
#include "FileManager.h"

class FTPManager{
private:
    void startFTP();
    std::vector<std::string>* launchFTPManager(std::vector<std::string> * ptr_file);

public:
    ServerConnection m_serveurConnection;
    FileManager m_fileManager;

    //Constructor
    FTPManager();

    //Destructor
    ~FTPManager();

};



#endif //UPDATER_FTPMANAGER_H
