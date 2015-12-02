#ifndef UPDATER_FTPMANAGER_H
#define UPDATER_FTPMANAGER_H

#include <iostream>
#include <string>
#include "ServerConnection.hpp"
#include "FileManager.hpp"

class FTPManager{
private:

    std::vector<std::string> getHash(std::vector<std::string>  file);
    bool createFile(std::vector<std::string> ptr_file);

public:
    ServerConnection  * m_ptr_serveurConnection;
    FileManager * m_ptr_fileManager;

    //Constructor
    FTPManager();

    //Destructor
    ~FTPManager();

    void startFTP();
};



#endif //UPDATER_FTPMANAGER_H
