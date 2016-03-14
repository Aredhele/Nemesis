/**
 * \brief Display message in colors
 * \file ConsoleDisplayer.hpp
 * \author Aredhele
 * \version 0.1
 * \date 19/11/2015
 * \class ConsoleDisplayer
 */

#ifndef DEF_CONSOLED_ISPLAYER_HPP
#define DEF_CONSOLE_DISPLAYER_HPP

// HEADER
#include <iostream>
#include <sstream>
#include <ctime>
#include <string>

class ConsoleDisplayer
{
private:
    // Method
    std::string getTime();

public:
    // Constructor
    ConsoleDisplayer();

    // Destructor
    ~ConsoleDisplayer();

    // Methods
    void displayMessage(std::string type, std::string message);
    void displayStartMessage();
    void displaySimple(std::string type, std::string message);
    void displayRecv();
    void displaySend();
};

#endif // DEF_CONSOLE_DISPLAYER_HPP
