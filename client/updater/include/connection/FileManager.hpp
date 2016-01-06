//
// Created by Jehan on 29/11/2015.
//

#ifndef UPDATER_FILEMANAGER_H
#define UPDATER_FILEMANAGER_H


#include "../tools/HashTool.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <SFML/Network.hpp>
#include <windows.h>
#include <dirent.h>
#include <view/RenderEngine.hpp>

class FileManager{
private:
    int m_nbReceived;
    HashTool * m_ptr_hashTool;
    RenderEngine * m_ptr_renderEngine;
    std::string setFilesHash(std::string path);
    bool compareHash(std::string hashReceived, std::string hash);
    std::string backslashToSlash(std::string path);
    std::string slashToBackSlash(std::string path);

public:
    FileManager(RenderEngine * renderEngine);
    ~FileManager();

    std::string getHash(std::string path);

    void createFile(int nbFile, std::string path, sf::TcpSocket* socket);




    void createPathFile(std::string path);
};

#endif //UPDATER_FILEMANAGER_H
