#include <connection/FTPManager.hpp>
#include <SFML/System/Clock.hpp>
#include <stdexcept>

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

int FTPManager::startFTP() {
    if (!m_ptr_serveurConnection->connect()) {
        std::cerr << "Error connection" << std::endl;
        return -1;
    }


    //Get the infoList with hash of our files
    createFilesListInfo();

    std::cout << std::endl;
    std::cout <<  m_clientFilesInfoList.size() << " files hashed" << std::endl;

    //Send size and content of the list
    m_ptr_serveurConnection->sendSizeList(m_clientFilesInfoList.size());
    m_ptr_serveurConnection->sendPathHash(m_clientFilesInfoList);

    //Receive number of file to update
    int numberFile = m_ptr_serveurConnection->getNumberFile();
    std::cout << "Number of file to receive : " << numberFile << std::endl;

    if (numberFile==0){
        std::cout << "The game is up to date ! Enjoy :)" << std::endl;
        return 0;
    }

    std::cout << "Waiting for the server ..." << std::endl;
    //Reception of the files to update
    m_ptr_serveurConnection->receiveFiles(numberFile, m_path, m_ptr_fileManager);


    std::cout << "The game is up to date ! Enjoy :)" << std::endl;
    return 0;
}


void FTPManager::createFilesListInfo() {

    m_path = getExePath();
    m_path+="client\\";

    std::cout  << std::endl << std::endl << "Searching all files in the directory : " << m_path << std::endl;
    std::cout << std::endl;

    route(m_path);
}

std::string FTPManager::getExePath()
{
    const std::string ext("updater\\bin\\choucroute.exe");
    char result[ MAX_PATH ];
    std::string path =  std::string( result, GetModuleFileName( NULL, result, MAX_PATH ) );

    // return "";
    try {
        if (path != ext &&
            path.size() > ext.size() &&
            path.substr(path.size() - ext.size()) == "updater\\bin\\choucroute.exe") {
            // if so then strip them off
            path = path.substr(0, path.size() - ext.size());
        }
    } catch(std::out_of_range e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Erreur getExePath" << std::endl;
    }

    return path;
}

void FTPManager::route(std::string path)
{
    DIR *dir = nullptr;
    DIR * dirBis = nullptr;
    struct dirent *ent = nullptr;

    std::vector<std::string> fileC;

    try {
        if ((dir = opendir(path.c_str())) != NULL) {
            /* print all the files and directories within directory */
            int fileNumero = 0;
            while ((ent = readdir(dir)) != NULL) {
                fileC.clear();
                std::string pathFile = path + std::string(ent->d_name);
                dirBis = opendir(pathFile.c_str());
                if (fileNumero >= 2 && dirBis == NULL) {

                    fileC.push_back(path + std::string(ent->d_name));
                    //std::cout << "path : " << fileC[0] << std::endl;

                    std::cout << path << " + " <<  std::string(ent->d_name) << std::endl;
                    fileC.push_back(m_ptr_fileManager->getHash(path + std::string(ent->d_name)));
                    std::cout << "hash : " << fileC[1] << std::endl;
                    int taillehash = strlen(fileC[1].c_str());
                    std::cout << "Taille hash : " << taillehash << std::endl;



                    fileC[0] = getRelativePath(path + std::string(ent->d_name));
                    std::cout << "relative path : " << fileC[0] << std::endl;
                    m_clientFilesInfoList.push_back(fileC);

                }
                else if (fileNumero >= 2) {
                    route(path + std::string(ent->d_name) + "\\");
                }
                fileNumero++;

            }
            closedir(dir);
        }
        else {
            std::cerr << "Problem while opening the directory " << path << std::endl;
        }
    } catch(std::out_of_range e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Erreur route " << std::endl;
    }
}

std::string FTPManager::getRelativePath(std::string absolutePath){

    int pos = absolutePath.rfind("client");
    std::string relativePath = absolutePath.substr(pos);
    return relativePath;
}