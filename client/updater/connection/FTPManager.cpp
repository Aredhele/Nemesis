#include "connection/FTPManager.h"

//Constructor
FTPManager::FTPManager() {
    m_ptr_fileManager = new FileManager;
    m_ptr_serveurConnection = new ServerConnection;
}

//Destructor
FTPManager::~FTPManager() {
    m_ptr_fileManager->~FileManager();
    m_ptr_fileManager = 0;
    delete(m_ptr_fileManager);

    m_ptr_serveurConnection->~ServerConnection();
    m_ptr_serveurConnection = 0;
    delete(m_ptr_serveurConnection);
}

void FTPManager::startFTP() {
    m_ptr_serveurConnection->connect();
    std::vector<std::string> v = m_ptr_serveurConnection->getFileInfoList();
    getHash(&v);
    createFile(&v);

    //Test du Hash
    /*
    const char* args[] = {"E:/testHash.txt", "02", "03", "04"};
    std::vector<std::string> v(args, args + 4);
    launchFTPManager(&v);

    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";*/
}

std::vector<std::string>* FTPManager::getHash(std::vector<std::string> * ptr_file) {
    m_ptr_fileManager->setFileInfoList(ptr_file);
    return m_ptr_fileManager->getFileInfoList();
}

bool FTPManager::createFile(std::vector<std::string> *ptr_file) {
    m_ptr_fileManager->createFile(ptr_file);
}

