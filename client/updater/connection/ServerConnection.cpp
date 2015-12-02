
#include "connection/ServerConnection.h"

//Constructor
ServerConnection::ServerConnection() {

}

//Destructor
ServerConnection::~ServerConnection() {

}

bool ServerConnection::connect() {
    return true;
}

bool ServerConnection::disconnect() {
    return true;
}

std::string ServerConnection::receiveFileContent() {
    return "Hey it\'s working !";
}

std::string ServerConnection::receiveFileName() {
    return "testEnvoi.txt";
}

std::string ServerConnection::receiveFilePath() {
    return "E:/testEnvoi.txt";
}

std::vector<std::string> ServerConnection::getFileInfoList() {
    std::vector<std::string> v;
    v.push_back(receiveFilePath());
    v.push_back(receiveFileName());
    v.push_back(receiveFileContent());
    return v;
}


bool ServerConnection::sendHashFile(std::string hash) {

}

bool ServerConnection::sendNameFile(std::string name) {

}

bool ServerConnection::sendPathFile(std::string path) {

}
