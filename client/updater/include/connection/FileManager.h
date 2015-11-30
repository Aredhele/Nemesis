//
// Created by Jehan on 29/11/2015.
//

#ifndef UPDATER_FILEMANAGER_H
#define UPDATER_FILEMANAGER_H

#include <SFML/System/Vector2.hpp>
#include "../tools/HashTool.hpp"

class FileManager{
private:
    std::vector * m_ptr_fileInfoList;
    HashTool * m_ptr_hashTool;
    int m_descriptor;

    void setFilesInfo();
    std::string setFilesHash(std::string path);
    void createFile(std::string name, std::string path);
    void insertContent();
    void closeDescriptor();

public:
    FileManager();
    ~FileManager();
    std::vector * getFileInfoList();
    void setFileInfoList(std::vector * ptr_fileInfoList);
};

#endif //UPDATER_FILEMANAGER_H
