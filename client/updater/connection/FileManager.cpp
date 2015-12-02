//
// Created by Jehan on 29/11/2015.
//

#include <vector>
#include "connection/FileManager.h"

FileManager::FileManager() {
    HashTool *hashtool = new HashTool();
}

FileManager::~FileManager() {
    m_ptr_fileInfoList = 0;
    delete(m_ptr_fileInfoList);

    m_ptr_hashTool = 0;
    delete(m_ptr_fileInfoList);
}

std::vector<std::string> * FileManager::getFileInfoList() {
    return m_ptr_fileInfoList;
}

void FileManager::setFileInfoList(std::vector<std::string>* ptr_fileInfoList) {
    std::string path;

    m_ptr_fileInfoList = ptr_fileInfoList;

    //Get info file
    path = ptr_fileInfoList->at(0);

    m_ptr_fileInfoList->push_back(setFilesHash(path));

}


void FileManager::closeDescriptor() {

}

void FileManager::createFile(std::string name, std::string path) {

}



void FileManager::insertContent() {

}

std::string FileManager::setFilesHash(std::string path) {
    m_ptr_hashTool->setPathToFile(path);
    return m_ptr_hashTool->getHash();
}

void FileManager::setFilesInfo() {

}
