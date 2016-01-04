#include <connection/ServerConnection.hpp>
#include <connection/FileManager.hpp>


//Constructor
ServerConnection::ServerConnection() {

}

//Destructor
ServerConnection::~ServerConnection() {

}

bool ServerConnection::connect() {

    std::cout << "Waiting for connection... " << std::endl;

    m_status = m_socket.connect("127.0.0.1", 6001);

    if (m_status != sf::Socket::Done) {
        std::cerr << "Unable to connect with server" << std::endl;
        return false;
    }

    std::cout << "Connection established !" << std::endl;
    std::cerr << "Socket status : " << m_status << std::endl;

    return true;
}

void ServerConnection::sendSizeList(int size){
    m_sizeList = size;
    std::cout << "Size : " << m_sizeList << std::endl;
    m_socket.send((void*)&m_sizeList, 4);
}

void ServerConnection::sendPathHash(std::vector<std::vector<std::string>> list) {
    FILE* f = fopen("result.txt", "w");
    int rep; size_t received;

    for (int i = 0; i < m_sizeList; i++){

        while(m_socket.send(list[i][0].c_str(), 200) == sf::Socket::Disconnected) {
            std::cerr << "Paquet re - send" << std::endl;
        }

        std::cout << "Path sent : [" << i << "] : " << list[i][0] << std::endl;

        // Saving to file
        fprintf(f, "[%d] %s\n", i, list[i][0].c_str());

        while(m_socket.send(list[i][1].c_str(), 40) == sf::Socket::Disconnected) {
            std::cerr << "Paquet re - send" << std::endl;
        }

        std::cout << "hash sent : [" << i << "] : " << list[i][1] << std::endl;

        // Saving to file
        fprintf(f, "[%d] %s\n", i, list[i][1].c_str());
    }
    fclose(f);

    // Synchronisation
    sf::sleep(sf::microseconds(500));
    std::cerr << "Waiting for synchronisation ..." << std::endl;
    m_socket.receive((void*)&rep, 4, received);

    std::cout << "Server and client synchronized" << std::endl;
}

int ServerConnection::getNumberFile(){

    int nbFile;
    std::size_t received;
    std::cout << "Waiting for the server..." << std::endl;
    m_socket.receive((void*)&nbFile, 4, received);

    return nbFile;
}

void ServerConnection::receiveFiles(int nbFile, std::string path, FileManager * m_ptr_filemanager){
    m_ptr_filemanager->createFile(nbFile, path, &m_socket);
}
