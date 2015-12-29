#include <connection/FTPManager.hpp>
#include <SFML/System/Clock.hpp>

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


    fileS = getHash(fileS);

    std::cout << "Voici les infos du fichier recu :" << std::endl;
    for(int i = 0; i < fileS.size(); i++)
        std::cout << fileS[i] << " ";



    //Create the file  :

    createFile(fileS);


    //Get the infoList with hash of our files (TODO !)
    sf::Clock clock;
    createFilesListInfo();
    sf::Time time = clock.getElapsedTime();

    /*
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "clientFilesInfoList : " << std::endl;

    for(int i = 0; i < m_clientFilesInfoList.size(); i++)
    {
        std::cout << std::endl << "ClientFileInfoList[" << i+1 <<"] : " << std::endl;
        for(int j = 0; j < m_clientFilesInfoList[i].size(); j++) {
            std::cout << m_clientFilesInfoList[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */
    std::cout << std::endl;
    std::cout <<  m_clientFilesInfoList.size() << " files hashed in " << time.asMilliseconds() << " ms" << std::endl;

}

std::vector<std::string> FTPManager::getHash(std::vector<std::string> file) {
    m_ptr_fileManager->setFileInfoList(file);
    return m_ptr_fileManager->getFileInfoList();
}

void FTPManager::createFile(std::vector<std::string> file) {
    m_ptr_fileManager->createFile(file);
}

void FTPManager::createFilesListInfo() {

    std::string path = getExePath();
    std::cout  << std::endl << std::endl << "Here\'s the files of this directory path : " << path << std::endl;
    std::cout << std::endl;

    route(path);

}

std::string FTPManager::getExePath()
{
    const std::string ext("bin\\updater.exe");
    char result[ MAX_PATH ];
    std::string path =  std::string( result, GetModuleFileName( NULL, result, MAX_PATH ) );

    if ( path != ext &&
         path.size() > ext.size() &&
         path.substr(path.size() - ext.size()) == "bin\\updater.exe" )
    {
        // if so then strip them off
        path = path.substr(0, path.size() - ext.size());
    }
    return path;
}


bool FTPManager::isFile(struct dirent* ent)
{
    if ((strchr(ent->d_name, '.'))!=NULL)
        return true;

    return false;
}


void FTPManager::route(std::string path)
{
    DIR *dir;
    DIR * dirBis;
    struct dirent *ent = nullptr;

    std::vector<std::string> fileC;


    if((dir=opendir(path.c_str()))!=NULL)
    {
        /* print all the files and directories within directory */
        int fileNumero=0;
        while ((ent = readdir (dir)) != NULL) {
            fileC.clear();
            std::string pathFile = path + std::string(ent->d_name);
            dirBis = opendir(pathFile.c_str());
            if (fileNumero >=2 && dirBis==NULL) {

                fileC.push_back(path + std::string(ent->d_name));
                //std::cout << "path : " << fileC[0] << std::endl;
                fileC.push_back(ent->d_name);
                //std::cout << "name : " << fileC[1] << std::endl;

                fileC.push_back("Contents here soon...");
                //std::cout << "content : " << fileC[2] << std::endl;
                //fileC = getHash(fileC);
                fileC.push_back(m_ptr_fileManager->getHash(path + std::string(ent->d_name)));
                //std::cout << "hash : " << fileC[3] << std::endl;

                //std::cout << std::endl << "File : " << std::endl;

                //for(int i = 0; i < fileC.size(); i++)
                  //  std::cout << fileC[i] << std::endl;

                m_clientFilesInfoList.push_back(fileC);
                //std::cout << "Size of ClientFilesInfoList : " << m_clientFilesInfoList.size() << std::endl;


                //std::cout << "----------------------------" << std::endl;
                //Sleep(1000);


                //std::cout << std::endl;
            }
            else if (fileNumero>=2){
                route(path + std::string(ent->d_name) + "\\");
            }
            fileNumero++;

        }
        closedir (dir);
    }
    else
    {
        std::cerr << "Problem while opening the directory " << path << std::endl;
    }
}