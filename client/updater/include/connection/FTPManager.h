#ifndef UPDATER_FTPMANAGER_H
#define UPDATER_FTPMANAGER_H

#include <iostream>
#include <string>
#include <bits/stl_vector.h>
#include "ServerConnection.h"
#include "FileManager.h"

class FTPManager{
private:
    void startFTP();
    std::vector* launchFTPManager(std::vector * ptr_file);

public:
    ServerConnection m_serveurConnection;
    FileManager m_fileManager;

    //Constructor
    FTPManager();

    //Destructor
    ~FTPManager();

};



#endif //UPDATER_FTPMANAGER_H
