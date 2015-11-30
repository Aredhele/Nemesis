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

#include "Vector2Str.hpp"
#include "Configuration.hpp"
#include "ParserException.hpp"

class Parser {

    private:
        Configuration * m_ptr_configuration;
        std::string m_configurationFilePath;


        // Methods
        Vector2Str * getParameters(std::string line);
        std::string getWord(std::string line, int n);
        bool checkChar(char toCheck);

    public:
        // Constructor
        Parser();
        Parser(std::string configurationFilePath);


        // Destructor
        ~Parser();

        // Methods
        Configuration * parse();
};

#endif // DEF_UPDATER_UPDATER_HPP