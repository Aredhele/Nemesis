//
// Created by Jehan on 29/11/2015.
//


#include "connection/FileManager.h"


FileManager::FileManager() {
    m_ptr_hashTool = new HashTool();
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

void FileManager::createFile(std::vector<std::string> *ptr_fileInfoList) {
    std::string path = ptr_fileInfoList->at(0);
    //std::string name = ptr_fileInfoList->at(1);
    std::string content = ptr_fileInfoList->at(2);

    std::ofstream outfile (path);

    outfile << content << std::endl;

    outfile.close();
}



void FileManager::insertContent() {

}

std::string FileManager::setFilesHash(std::string path) {
    m_ptr_hashTool->setPathToFile(path);
    return m_ptr_hashTool->getHash();
}

void FileManager::setFilesInfo() {

}
