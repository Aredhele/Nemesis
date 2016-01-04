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

class FileManager{
private:

    HashTool * m_ptr_hashTool;
    std::string setFilesHash(std::string path);
    bool compareHash(std::string hashReceived, std::string hash);
    int m_nbReceived;

public:
    FileManager();
    ~FileManager();

    std::string getHash(std::string path);

    void createFile(int nbFile, std::string path, sf::TcpSocket* socket);


    std::string backslashToSlash(std::string path);

    void createPathFile(std::string path);
};

#endif //UPDATER_FILEMANAGER_H
