/**
 * \brief Display message in colors
 * \file ConsoleDisplayer.cpp
 * \author Aredhele
 * \version 0.1
 * \date 19/11/2015
 * \class ConsoleDisplayer
 */

#include "../include/tool/ConsoleDisplayer.hpp"

/**
 * \brief Constructor.
 */
ConsoleDisplayer::ConsoleDisplayer() {
    m_colors = 15;
    m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(m_hConsole, m_colors);
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
    setConsoleColor("blue");
    std::cout << "  _   _                          _          " << std::endl;
    std::cout << " | \\ | |                        (_)         " << std::endl;
    std::cout << " |  \\| | ___ _ __ ___   ___  ___ _ ___      " << std::endl;
    std::cout << " | . ` |/ _ \\ '_ ` _ \\ / _ \\/ __| / __|   " << "\t Version : 0.1" << std::endl;
    std::cout << " | |\\  |  __/ | | | | |  __/\\__ \\ \\__ \\ " << "\t Author : Aredhele" << std::endl;
    std::cout << " |_| \\_|\\___|_| |_| |_|\\___||___/_|___/   " << "\t Nemesis Server : FTP" << std::endl;
    std::cout << std::endl;
    setConsoleColor("white");
}

/**
 * \brief Change he color of the output text
 * \param color The color of output text
 */
void ConsoleDisplayer::setConsoleColor(std::string color) {
    if(color == "white") m_colors = 15;
    else if(color == "red") m_colors = 4;
    else if(color == "green") m_colors = 10;
    else if(color == "blue") m_colors = 9;
    else m_colors = 15;
}

/**
 * \brief Display a little message when something is a success
 */
void ConsoleDisplayer::displayMessage(std::string message) {
    std::cout << ("[" + getTime() + "][Msge]") << " - " << message << std::endl;
}

/**
 * \brief Display a little message when something is a success
 */
void ConsoleDisplayer::displaySuccess(std::string message) {
    std::cout << ("[" + getTime() + "][Scss]") << " - " << message << " : ";
    setConsoleColor("green");
    std::cout << "OK !" << std::endl;
    setConsoleColor("white");
}

/*!
 * \brief Display a little message when something is a failure
 */
void ConsoleDisplayer::displayFailure(std::string message) {
    std::cout << ("[" + getTime() + "][Fail]") << " - " << message << " : ";
    setConsoleColor("red");
    std::cout << "Failure !" << std::endl;
    setConsoleColor("white");
}

void ConsoleDisplayer::displayInfo(std::string message) {
    setConsoleColor("green");
    std::cout << ("[" + getTime() + "][Info]") << " - " << message << std::endl;
    setConsoleColor("white");
}

void ConsoleDisplayer::displaySimple(std::string message) {
    std::cout << ("[" + getTime() + "][Msge]") << " - " << message;
}

void ConsoleDisplayer::displayRecv() {
    std::cout << ("[" + getTime() + "][Recv]") << " - ";
}

void ConsoleDisplayer::displaySend() {
    std::cout << ("[" + getTime() + "][Send]") << " - ";
}

void ConsoleDisplayer::displayWarn(std::string message) {
    setConsoleColor("red");
    std::cout << ("[" + getTime() + "][Warn]") << " - " << message << std::endl;
    setConsoleColor("white");
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

    if(ss2.str().size() < 2) seconds += "0";
    seconds += ss2.str();

    return (ss.str() + seconds);
}

