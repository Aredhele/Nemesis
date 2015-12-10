//
// Created by Jehan on 29/11/2015.
//



#include <connection/FileManager.hpp>


FileManager::FileManager() {
    m_ptr_hashTool = new HashTool();
}

FileManager::~FileManager() {
    delete(m_ptr_hashTool);
    m_ptr_hashTool = nullptr;
}

void FileManager::setFileInfoList(std::vector<std::string> fileInfoList) {
    std::string path;

    m_fileInfoList = fileInfoList;

    //Get info file
    path = fileInfoList.at(0);

    m_fileInfoList.push_back(setFilesHash(path));

}

std::vector<std::string>  FileManager::getFileInfoList() {
    return m_fileInfoList;
}




void FileManager::closeDescriptor() {

}

void FileManager::createFile(std::vector<std::string> fileInfoList) {
    std::string path = fileInfoList.at(0);
    //std::string name = ptr_fileInfoList->at(1);
    std::string content = fileInfoList.at(2);

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
