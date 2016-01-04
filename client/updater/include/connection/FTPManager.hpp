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
#include <windows.h>

class FTPManager{
private:

    std::string getExePath();

    void route(std::string path);
    void createFilesListInfo();
    std::string getRelativePath(std::string absolutePath);
    std::string m_path;

public:
    ServerConnection  * m_ptr_serveurConnection;
    FileManager * m_ptr_fileManager;
    std::vector<std::vector<std::string>> m_clientFilesInfoList;

    //Constructor
    FTPManager();

    //Destructor
    ~FTPManager();

    int startFTP();
};



#endif //UPDATER_FTPMANAGER_H
