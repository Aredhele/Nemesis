//
// Created by Jehan on 29/11/2015.
//



#include <connection/FileManager.hpp>


FileManager::FileManager() {
    m_ptr_hashTool = new HashTool();
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

    for(int i = 0; i < nbFile; i++) {
        path = pathBis;

        check = false;
        tries = 0;

        std::cout << "\n --- FILE[" << i + 1 << "] ---" << std::endl;
        char fileToCreate[200];

        // Reception of the file's name
        socket->receive(fileToCreate, 200, received);

        std::cout << "Received path (relativ) : "  << fileToCreate << std::endl;
        path += fileToCreate;
        std::cout << "Absolute path \\ : " << path << std::endl;
        path = backslashToSlash(path);
        std::cout << "Absolute path / : " << path << std::endl;

        std::cout << "File name [" << received << "] : " << fileToCreate << std::endl;

        // Getting file's size
        socket->receive((void*)&sizeOfFile, 4, received);

        std::cout << "Size of the file : " << sizeOfFile << " bytes" << std::endl;

        //Work only if a folder needs to be create


        while(!check && tries != 3) {


            std::ofstream os (path, std::ofstream::binary | std::ofstream::trunc);

            if((os.rdstate() & std::ofstream::failbit) != 0) {
                std::cerr << "Unable to open ouput stream !" << std::endl;
                createPathFile(path);
                continue;
            } else {
                std::cout << "The file is opened !" << std::endl;
            }

            int size = 0;
            int sortie = 0;


            int counter = 0;

            // Getting content
            std::cout << "Jump into the send loop !" << std::endl;
            while(1) {

                socket->receive(buffer, 1024, received);
                // std::cout << "Bytes received : " << received << " bytes." << std::endl;


                os.write(buffer, received);

                // Check if write is Ok
                if(os.bad()) {
                    std::cerr << "Fail to write " << received << " bytes." << std::endl;
                }

                size += received;
                counter++;
                std::cout << "Paquet [" << counter << "] : " << size << " on ";
                std::cout << sizeOfFile << " bytes. (received : " << received << ")" << std::endl;
                if(size >= sizeOfFile) break;
            }
            os.close();
            // os.write(buffer, 1024);

            // Send ack
            socket->send((void*)&sortie, 4);
            std::cout << "Out of the send loop" << std::endl;

            // Getting server hash
            socket->receive(hashServer, 200, received);

            // Get hash of the new file
            std::cout << "Path to hash : " << path << std::endl;
            hashFile = getHash(path);

            // Seems to be OK up to here !
            std::cout << "Hash file : " << hashFile << std::endl;
            std::cout << "Hash serv : " << hashServer << std::endl;


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
    unsigned int pos = path.rfind("/");
    path = path.substr(0, pos);
    CreateDirectory( path.c_str(), NULL );
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
