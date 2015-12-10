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
    std::vector<std::string> fileS = m_ptr_serveurConnection->getFileInfoList();
    std::vector<std::vector<std::string>> clientFilesInfoList;


    //Get the hash of the file :
    /*

    fileS = getHash(fileS);

    std::cout << "Voici les infos du fichier recu :" << std::endl;
    for(int i = 0; i < fileS.size(); i++)
        std::cout << fileS[i] << " ";
    */


    //Create the file  :
    /*
        createFile(fileS);
     */

    //Get the infoList with hash of our files (TODO !)
    /*
    createFilesListInfo();
    for(int i = 0; i < clientFilesInfoList.size(); i++)
    {
        for(int j = 0; j < clientFilesInfoList[i].size(); j++)
            std::cout << clientFilesInfoList[i][j] << " ";

        std::cout << std::endl;
    }*/

}

std::vector<std::string> FTPManager::getHash(std::vector<std::string> file) {
    m_ptr_fileManager->setFileInfoList(file);
    return m_ptr_fileManager->getFileInfoList();
}

void FTPManager::createFile(std::vector<std::string> file) {
    m_ptr_fileManager->createFile(file);
}

void FTPManager::createFilesListInfo() {
    DIR *dir;
    struct dirent *ent;
    const char* path = getExePath().c_str();
    std::vector<std::string> fileC;
    std::cout << "Here\'s the files of this directory path : " << path << std::endl;
    if ((dir = opendir (path)) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            fileC.clear();
            fileC.push_back(path + std::string(ent->d_name));
            std::cout <<  path + std::string(ent->d_name)<< std::endl;
            fileC.push_back(ent->d_name);
            fileC.push_back("Contents here soon...");
            fileC = getHash(fileC);
            clientFilesInfoList.push_back(fileC);
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

