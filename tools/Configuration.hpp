/**
 * \brief Store configuration file
 * \file Configuration.hpp
 * \author Aredhele
 * \version 0.1
 * \date 19/11/2015
 * \class Configuration
 */

#ifndef DEF_PARSER_CONFIGURATION_HPP
#define DEF_PARSER_CONFIGURATION_HPP

// Header
#include <map>
#include <string>
#include <iostream>

#include "Vector2Str.hpp"
#include "../tool/ConsoleDisplayer.hpp"

class Configuration {

    private:
        std::map < std::string, std::string > m_config;

    public:
        // Constructor
        Configuration();
        Configuration(Configuration * configuration);

        // Destructor
        ~Configuration();

        // Methods
        void addParam(Vector2Str * param);
        void addParam(std::string param, std::string value);
        void displayConfig();

        // Getter
        std::string getParam(std::string paramName);
};

#endif // DEF_PARSER_CONFIGURATION_HPP
