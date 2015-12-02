#include "connection/FTPManager.h"

//Constructor
FTPManager::FTPManager() {
    m_fileManager = new FileManager;
    m_serveurConnection = new ServerConnection;
}

//Destructor
FTPManager::~FTPManager() {

}

void FTPManager::startFTP() {
    const char* args[] = {"E:/testHash.txt", "02", "03", "04"};
    std::vector<std::string> v(args, args + 4);
    launchFTPManager(&v);

    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
}

std::vector<std::string>* FTPManager::launchFTPManager(std::vector<std::string> * ptr_file) {
    m_fileManager->setFileInfoList(ptr_file);
    return m_fileManager->getFileInfoList();
}