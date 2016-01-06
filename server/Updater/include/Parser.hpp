/**
 * \brief Parse a configuration file and store it
 * \file Parser.hpp
 * \author Aredhele
 * \version 0.1
 * \date 19/11/2015
 * \class Parser
 */

#ifndef DEF_UPDATER_UPDATER_HPP
#define DEF_UPDATER_UPDATER_HPP

// Header
#include <fstream>
#include <string.h>

#include "Configuration.hpp"
#include "ParserException.hpp"

class Parser {

    private:
        Configuration * m_ptr_configuration;
        ConsoleDisplayer * m_ptr_displayer;
        std::string m_configurationFilePath;


        // Methods
        Vector2Str * getParameters(std::string line);
        std::string getWord(std::string line, int n);
        bool checkChar(char toCheck);

    public:
        // Constructor
        Parser(ConsoleDisplayer * displayer);
        Parser(std::string configurationFilePath, ConsoleDisplayer * displayer);

        // Destructor
        ~Parser();

        // Methods
        Configuration * parse();
};

#endif // DEF_UPDATER_UPDATER_HPP