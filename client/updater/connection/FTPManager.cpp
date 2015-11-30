#include "connection/FTPManager.h"

//Constructor
FTPManager::FTPManager() {

}

//Destructor
FTPManager::~FTPManager() {

}

void FTPManager::startFTP() {

}

std::vector* FTPManager::launchFTPManager(std::vector * ptr_file) {
    m_fileManager.setFileInfoList(ptr_file);
    return m_fileManager.getFileInfoList();
}