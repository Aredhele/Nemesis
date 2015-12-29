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

    std::vector<std::string> getHash(std::vector<std::string>  file);
    void createFile(std::vector<std::string> file);
    std::string getExePath();
    bool isFile(struct dirent* ent);
    void route(std::string path);
    void createFilesListInfo();

public:
    ServerConnection  * m_ptr_serveurConnection;
    FileManager * m_ptr_fileManager;
    std::vector<std::vector<std::string>> m_clientFilesInfoList;

    //Constructor
    FTPManager();

    //Destructor
    ~FTPManager();

    void startFTP();
};



#endif //UPDATER_FTPMANAGER_H
