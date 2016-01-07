#include <connection/FTPManager.hpp>
#include <stdexcept>

//Constructor
FTPManager::FTPManager(RenderEngine *renderEngine)
{
    m_ptr_renderEngine = renderEngine;

    m_ptr_fileManager = new FileManager(m_ptr_renderEngine);
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

    m_ptr_renderEngine->getLog()->addText(L"Connexion au serveur...", sf::Color(255,254,206));
    while (!m_ptr_serveurConnection->connect()) {
        m_ptr_renderEngine->getLog()->addText(L"Erreur de connexion", sf::Color(255,20,24));

        m_ptr_renderEngine->getLog()->addText(L"Tentative de reconnexion...", sf::Color(255,254,206));
        sf::sleep(sf::seconds(2));
    }

    m_ptr_renderEngine->getLog()->addText(L"Connexion réussie", sf::Color(76,255,115));

    //Get the infoList with hash of our files
    createFilesListInfo();

    m_ptr_renderEngine->getLog()->addText(cast::towstring(m_clientFilesInfoList.size())+
            L" fichiers indexés", sf::Color(255,254,206));

    //Send size and content of the list
    m_ptr_serveurConnection->sendSizeList(m_clientFilesInfoList.size());
    m_ptr_serveurConnection->sendPathHash(m_clientFilesInfoList);

    //Receive number of file to update
    int numberFile = m_ptr_serveurConnection->getNumberFile();
    m_ptr_renderEngine->getProgressBar()->setNbFileMax(numberFile);
    m_ptr_renderEngine->getLog()->addText(
            cast::towstring(numberFile) + L" fichiers à recevoir", sf::Color(255,254,206));
    if (numberFile==0){
        m_ptr_renderEngine->getProgressBar()->maxProgression();
        m_ptr_renderEngine->getLog()->addText(L"Le jeu est à jour !", sf::Color(76,255,115));
        m_ptr_renderEngine->getButton()->enable(true);
        return 0;
    }

    //Reception of the files to update
    m_ptr_serveurConnection->receiveFiles(numberFile, m_path, m_ptr_fileManager);

    m_ptr_renderEngine->getProgressBar()->maxProgression();
    m_ptr_renderEngine->getLog()->addText(L"Le jeu est à jour !", sf::Color(76,255,115));
    m_ptr_renderEngine->getButton()->enable(true);
    return 0;
}


void FTPManager::createFilesListInfo() {

    m_path = getExePath();
    m_path+="client\\";
    m_ptr_renderEngine->getLog()->addText(L"Indexation des fichiers...", sf::Color(255,254,206));
    route(m_path);
}

std::string FTPManager::getExePath()
{
    const std::string ext("updater\\bin\\choucroute.exe");
    char result[ MAX_PATH ];
    std::string path =  std::string( result, GetModuleFileName( NULL, result, MAX_PATH ) );


    if (path != ext &&
        path.size() > ext.size() &&
        path.substr(path.size() - ext.size()) == "updater\\bin\\choucroute.exe") {
        // if so then strip them off
        path = path.substr(0, path.size() - ext.size());
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

                    fileC.push_back(m_ptr_fileManager->getHash(path + std::string(ent->d_name)));
                    fileC[0] = getRelativePath(path + std::string(ent->d_name));
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
            m_ptr_renderEngine->getLog()->addText(L"Problème lors de l'ouverture des fichiers", sf::Color(255,20,24));
        }
    } catch(std::out_of_range e) {
        m_ptr_renderEngine->getLog()->addText(L"Trop de fichiers", sf::Color(255,20,24));
    }
}

std::string FTPManager::getRelativePath(std::string absolutePath){

    int pos = absolutePath.rfind("client");
    std::string relativePath = absolutePath.substr(pos);
    return relativePath;
}