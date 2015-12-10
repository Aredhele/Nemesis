#ifndef UPDATER_FTPMANAGER_H
#define UPDATER_FTPMANAGER_H

#include <iostream>
#include <string>
#include <dirent.h>
#include <cstdlib>
#include <cstdarg>
#include <windef.h>
#include <winbase.h>
#include "ServerConnection.hpp"
#include "FileManager.hpp"

class FTPManager{
private:

    std::vector<std::string> getHash(std::vector<std::string>  file);
    void createFile(std::vector<std::string> file);
    std::string getExePath();

    void createFilesListInfo();

public:
    ServerConnection  * m_ptr_serveurConnection;
    FileManager * m_ptr_fileManager;
    std::vector<std::vector<std::string>> clientFilesInfoList;

    //Constructor
    FTPManager();

    //Destructor
    ~FTPManager();

    void startFTP();
};



#endif //UPDATER_FTPMANAGER_H
