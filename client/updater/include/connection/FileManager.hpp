//
// Created by Jehan on 29/11/2015.
//

#ifndef UPDATER_FILEMANAGER_H
#define UPDATER_FILEMANAGER_H


#include "../tools/HashTool.hpp"
#include <vector>
#include <iostream>
#include <fstream>

class FileManager{
private:
    std::vector<std::string> m_fileInfoList;
    HashTool * m_ptr_hashTool;
    int m_descriptor;

    void setFilesInfo();
    std::string setFilesHash(std::string path);
    void insertContent();
    void closeDescriptor();

public:
    FileManager();
    ~FileManager();
    std::vector<std::string>  getFileInfoList();
    void setFileInfoList(std::vector<std::string> fileInfoList);
    void createFile(std::vector<std::string> fileInfoList);

    std::string getHash(std::string path);
};

#endif //UPDATER_FILEMANAGER_H
