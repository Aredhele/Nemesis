/*!
 * \file Configuration.hpp
 * \brief Store a configuration
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-20
 */

#ifndef DEF_CONFIGURATION_HPP
#define DEF_CONFIGURATION_HPP

#include <map>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tool.hpp"
#include "Constants.hpp"
#include "clientConnector/ConsoleDisplayer.hpp"

class Configuration
{
public:
    // Constructor
    Configuration(ConsoleDisplayer * ptr_displayer);

    // Destructor
    ~Configuration();

    // Methods
    int readConfiguration(std::string path);
    int readFileInfo(std::string path);
    int displayConfiguration();

    // Getters
    const std::string getParam(std::string key);
    const std::vector < std::string > getPathList();
    const std::vector < std::string > getHashList();

private:
    // Member
    ConsoleDisplayer * m_ptr_displayer;

    std::map < std::string, std::string > m_config;
    std::vector < std::string > m_pathList;
    std::vector < std::string > m_hashList;
};

#endif // DEF_CONFIGURATION_HPP