//
// Created by Jehan on 29/11/2015.
//

#ifndef UPDATER_FILEMANAGER_H
#define UPDATER_FILEMANAGER_H

#include <SFML/System/Vector2.hpp>
#include "../tools/HashTool.hpp"

class FileManager{
private:
    sf::Vector2f * m_fileInfoList;
    HashTool * m_hashTool;
    int m_descriptor;

    void setFilesInfo();
    void setFilesHash();
    void createFile(std::string name, std::string path);
    void insertContent();
    void closeDescriptor();

public:
    FileManager();
    ~FileManager();
    sf::Vector2f getFileInfoList();
};

#endif //UPDATER_FILEMANAGER_H
