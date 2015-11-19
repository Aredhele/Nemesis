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
#include <windows.h>
#include <iostream>
#include <sstream>
#include <ctime>
#include <string>

class ConsoleDisplayer
{
    private:
        // Member
        HANDLE m_hConsole;
        WORD m_colors;

        // Method
        std::string getTime();

    public:
        // Constructor
        ConsoleDisplayer();

        // Destructor
        ~ConsoleDisplayer();

        // Methods
        void setConsoleColor(std::string color);
        void displayMessage(std::string message);
        void displaySuccess(std::string message);
        void displayFailure(std::string message);
        void displayInfo(std::string message);
        void displayStartMessage();
        void displaySimple(std::string message);
        void displayWarn(std::string message);
        void displayRecv();
        void displaySend();
};

#endif // DEF_CONSOLE_DISPLAYER_HPP
