#include "connection/FTPManager.h"

//Constructor
FTPManager::FTPManager() {

}

//Destructor
FTPManager::~FTPManager() {

}

void FTPManager::startFTP() {

}

std::vector<std::string>* FTPManager::launchFTPManager(std::vector<std::string> * ptr_file) {
    m_fileManager.setFileInfoList(ptr_file);
    return m_fileManager.getFileInfoList();
}