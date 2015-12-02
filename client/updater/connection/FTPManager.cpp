#include <connection/FTPManager.hpp>



//Constructor
FTPManager::FTPManager() {
    m_ptr_fileManager = new FileManager;
    m_ptr_serveurConnection = new ServerConnection;
}

//Destructor
FTPManager::~FTPManager() {
    delete(m_ptr_fileManager);
    m_ptr_fileManager = nullptr;

    delete(m_ptr_serveurConnection);
    m_ptr_serveurConnection = nullptr;
}

void FTPManager::startFTP() {
    m_ptr_serveurConnection->connect();
    std::vector<std::string> v = m_ptr_serveurConnection->getFileInfoList();
    //getHash(v);
    createFile(v);
    createFileListInfo();



    //Test du Hash
    /*
    const char* args[] = {"E:/testHash.txt", "02", "03", "04"};
    std::vector<std::string> v(args, args + 4);
    launchFTPManager(&v);

    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";*/
}

std::vector<std::string> FTPManager::getHash(std::vector<std::string> file) {
    m_ptr_fileManager->setFileInfoList(file);
    return m_ptr_fileManager->getFileInfoList();
}

void FTPManager::createFile(std::vector<std::string> file) {
    m_ptr_fileManager->createFile(file);
}

std::vector<std::string> FTPManager::createFileListInfo() {
    DIR *dir;
    struct dirent *ent;
    const char* path = getExePath().c_str();
    std::cout << "Here\'s the files of this directory path : " << path << std::endl;
    if ((dir = opendir (path)) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            std::cout << ent->d_name << std::endl;
        }
        closedir (dir);
    }
    else{
        std::cout << "Hum, the path is not going well..." << std::endl;
    }
}

std::string FTPManager::getExePath()
{
    const std::string ext("updater.exe");
    char result[ MAX_PATH ];
    std::string path =  std::string( result, GetModuleFileName( NULL, result, MAX_PATH ) );

    if ( path != ext &&
            path.size() > ext.size() &&
            path.substr(path.size() - ext.size()) == "updater.exe" )
    {
        // if so then strip them off
        path = path.substr(0, path.size() - ext.size());
    }
    return path;


}

