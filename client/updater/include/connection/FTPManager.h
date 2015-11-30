#ifndef UPDATER_FTPMANAGER_H
#define UPDATER_FTPMANAGER_H

#include <iostream>
#include <string>
#include "ServerConnection.h"
#include "FileManager.h"

class FTPManager{
private:
    void startFTP();
    void launchFTPManager();

public:
    ServerConnection m_serveurConnection;
    FileManager m_fileManager;

    //Constructor
    FTPManager();

    //Destructor
    ~FTPManager();

};



#endif //UPDATER_FTPMANAGER_H
