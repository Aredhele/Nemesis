//
// Created by Jehan on 29/11/2015.
//



#include <connection/FileManager.hpp>
#include <tools/Patch.hpp>


FileManager::FileManager(RenderEngine *renderEngine) {
    m_ptr_hashTool = new HashTool();
    m_ptr_renderEngine = renderEngine;;
}

FileManager::~FileManager() {
    delete(m_ptr_hashTool);
    m_ptr_hashTool = nullptr;
}

std::string FileManager::getHash(std::string path) {
    std::string hash = setFilesHash(path);
    return hash;
}


std::string FileManager::setFilesHash(std::string path) {
    m_ptr_hashTool->setPathToFile(path);
    std::string s = m_ptr_hashTool->getHash();
    return s;
}

bool FileManager::compareHash(std::string hashReceived, std::string hash)
{
    return !(hashReceived != hash);

}

void FileManager::createFile(int nbFile, std::string path, sf::TcpSocket* socket){

    std::size_t received;

    char buffer[1024], hashServer[200];
    int sizeOfFile, tries;

    bool check;

    std::string hashFile;

    m_nbReceived = 0;

    std::string pathBis = path;
    std::string pathTier = path;

    for(int i = 0; i < nbFile; i++) {
        path = pathBis;

        check = false;
        tries = 0;

        std::cout << "\n --- FILE[" << i + 1 << "] ---" << std::endl;
        //m_ptr_renderEngine->getLog()->addText(L"Réception du fichier "
         //       + cast::towstring(i) + L" / " + cast::towstring(nbFile), sf::Color::Blue);
        char fileToCreate[200];

        // Reception of the file's name
        socket->receive(fileToCreate, 200, received);
        //std::cout << "Received path (relativ) : "  << fileToCreate << std::endl;
        path += fileToCreate;
        //std::cout << "Absolute path \\ : " << path << std::endl;
        //path = backslashToSlash(path);
        //std::cout << "Absolute path / : " << path << std::endl;

        std::wstring s(L"");
        int tmp = cast::toString(i).size();

        for(int i = 4 - tmp; i > 0; i--) {
            s += L" ";
        }
        std::cout << 4 - tmp << std::endl;
        std::cout << "SIZE : " << s.size() << std::endl;

        m_ptr_renderEngine->getLog()->addText(L"Fichier : "
                                              + cast::towstring(fileToCreate), sf::Color::Blue);
        // Getting file's size
        socket->receive((void*)&sizeOfFile, 4, received);
        std::cerr << "3" << std::endl;
        //m_ptr_renderEngine->getLog()->addText(L"Taille du fichier :  " + cast::towstring(sizeOfFile), sf::Color::Blue);

        //Work only if a folder needs to be create

        std::cerr << "4" << std::endl;
        while(!check && tries != 3) {

            std::ofstream os (path, std::ofstream::binary | std::ofstream::trunc);

            if((os.rdstate() & std::ofstream::failbit) != 0) {
                std::cerr << "Unable to open ouput stream !" << std::endl;
                //pathTier = slashToBackSlash(path);
                createPathFile(path);
                os.close();
                sf::sleep(sf::seconds(10));
                continue;
            } else {
                std::cout << "The file is opened !" << std::endl;
            }

            int size = 0;
            int sortie = 0;


            int counter = 0;

            // Getting content
            std::cout << "Jump into the send loop !" << std::endl;
            sf::Clock clock;
            sf::Time time;
            int compt=0;
            sf::sleep(sf::seconds(0.01));
            while(1) {
                time = clock.getElapsedTime();
                if (time.asSeconds()>=1){
                    //m_ptr_renderEngine->getLog()->getLastText()->setString(L"Débit : "
                    //+ cast::towstring(compt/1000) + L" ko/s -- "
                    //+ cast::towstring(size/1000)
                    //+ L"/"+ cast::towstring(sizeOfFile/1000)
                    //+ L" ko");
                    compt=0;
                    clock.restart();
                }

                socket->receive(buffer, 1024, received);
                // std::cout << "Bytes received : " << received << " bytes." << std::endl;
                compt+=received;

                os.write(buffer, received);

                // Check if write is Ok
                if(os.bad()) {
                    std::cerr << "Fail to write " << received << " bytes." << std::endl;
                }

                size += received;
                counter++;
                if(size >= sizeOfFile) break;
            }
            os.close();
            // os.write(buffer, 1024);

            // Send ack
            socket->send((void*)&sortie, 4);

            // Getting server hash
            socket->receive(hashServer, 200, received);

            hashFile = getHash(path);



            //Comparaison between hash client/hash server and return answer
            int result = 0;
            if (compareHash(hashServer, hashFile)) {
                check = true;
                result = 0;
                m_nbReceived++;
            } else {
                tries++;
                result = 1;
            }

            socket->send((void*)&result, 4);
        }
    }
}

void FileManager::createPathFile(std::string path) {
    unsigned int pos = path.rfind("\\");
    path = path.substr(0, pos);
    std::string mkdir = "mkdir " + path;
    std::cout << mkdir << std::endl;
    system(mkdir.c_str());
    //CreateDirectory( path.c_str(), NULL );
    /*If not a recursive creation check that out :
     * #include <boost/filesystem.hpp>
     * boost::filesystem::create_directories("/tmp/a/b/c");
     */
}

std::string FileManager::backslashToSlash(std::string path) {
    for (int i = 0; i < path.size(); i++) {
        if ((path[i] ==  '\\')){
            path[i]=  '/';
        }
    }
    return path;
}

std::string FileManager::slashToBackSlash(std::string path) {
    for (int i = 0; i < path.size(); i++) {
        if ((path[i] ==  '/')){
            path[i]=  '\\';
        }
    }
    return path;
}