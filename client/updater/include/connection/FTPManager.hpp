#ifndef UPDATER_FTPMANAGER_H
#define UPDATER_FTPMANAGER_H

#include <iostream>
#include <string>
#include <dirent.h>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <cstdarg>
#include <windef.h>
#include <winbase.h>
#include "ServerConnection.hpp"
#include "FileManager.hpp"
#include <windows.h>
#include <view/RenderEngine.hpp>
#include "tools/Patch.hpp"

class FTPManager{
private:
    std::string m_path;
    RenderEngine *m_ptr_renderEngine;


    std::string getExePath();
    void route(std::string path);
    void createFilesListInfo();
    std::string getRelativePath(std::string absolutePath);


public:
    ServerConnection  * m_ptr_serveurConnection;
    FileManager * m_ptr_fileManager;
    std::vector<std::vector<std::string>> m_clientFilesInfoList;

    //Constructor
    FTPManager(RenderEngine *renderEngine);

    //Destructor
    ~FTPManager();

    int startFTP();
};



#endif //UPDATER_FTPMANAGER_H
