/**
 * \brief Display message in colors
 * \file ConsoleDisplayer.cpp
 * \author Aredhele
 * \version 0.1
 * \date 19/11/2015
 * \class ConsoleDisplayer
 */

#include "ConsoleDisplayer.hpp"

/**
 * \brief Constructor.
 */
ConsoleDisplayer::ConsoleDisplayer() {
    // None
}

/**
 * \brief Destructor.
 */
ConsoleDisplayer::~ConsoleDisplayer() {
    // None
}

/**
 * \brief Display a wonderful start message :o
 */
void ConsoleDisplayer::displayStartMessage() {
    std::cout << "  _   _                          _           " << std::endl;
    std::cout << " | \\ | |                        (_)         " << std::endl;
    std::cout << " |  \\| | ___ _ __ ___   ___  ___ _ ___      " << std::endl;
    std::cout << " | . ` |/ _ \\ '_ ` _ \\ / _ \\/ __| / __|   " << "\t Version : 0.1" << std::endl;
    std::cout << " | |\\  |  __/ | | | | |  __/\\__ \\ \\__ \\ " << "\t Author : Aredhele" << std::endl;
    std::cout << " |_| \\_|\\___|_| |_| |_|\\___||___/_|___/   " << "\t Nemesis Server : FTP" << std::endl;
    std::cout << std::endl;
}

/**
 * \brief Display a little message when something is a success
 */
void ConsoleDisplayer::displayMessage(std::string type, std::string message) {
    std::cout << "[" << getTime() << "][" << type << "]" << " - " << message << std::endl;
}


void ConsoleDisplayer::displaySimple(std::string type, std::string message) {
    std::cout << "[" << getTime() << "][" << type << "]" << " - " << message;
}

void ConsoleDisplayer::displayRecv() {
    std::cout << "[" << getTime() << "][Recv]" << " << ";
}

void ConsoleDisplayer::displaySend() {
    std::cout << "[" << getTime() << "][Send]" << " >> ";
}

/**
 * \return ss.str() The current Time
 * \brief Example : 22:20:45
 */
std::string ConsoleDisplayer::getTime() {
    time_t currentTime;
    struct tm *localTime;
    int hour, min, sec;

    time(&currentTime);
    localTime = localtime(&currentTime);

    hour = localTime->tm_hour;
    min = localTime->tm_min;
    sec = localTime->tm_sec;

    std::stringstream ss, ss2;
    std::string seconds = "";
    ss << hour << ":" << min << ":";
    ss2 << sec;

    if(ss2.str().size() < 2) 
        seconds += '0';
    seconds += ss2.str();

    return (ss.str() + seconds);
}

