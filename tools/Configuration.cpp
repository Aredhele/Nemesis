/**
 * \brief Store configuration file
 * \file Configuration.cpp
 * \author Aredhele
 * \version 0.1
 * \date 19/11/2015
 * \class Configuration
 */

// Header
#include "Parser/Configuration.hpp"

/**
 * \brief Constructor.
 */
Configuration::Configuration() {
    // None
}

/**
 * \brief Constructor.
 * \brief Copy
 */
Configuration::Configuration(Configuration * configuration) {
    m_config = configuration.m_config;
}

/**
 * \brief Destructor.
 */
Configuration::~Configuration() {
    // None
}

/**
 * \brief Insert a new param to m_config
 * \param name The name of the parameter
 * \param value The value of the parameter
 */
void Configuration::addParam(std::string name, std::string value) {
    m_config.insert(std::pair <std::string, std::string>(name, value));
}

void Configuration::addParam(Vector2Str * param) {
    m_config.insert(std::pair <std::string, std::string>(param->x, param->y));
}

/**
 * \brief Display the configuration
 */
void Configuration::displayConfig() {
    // Declare iterator
    std::map <std::string, std::string>::iterator it = m_config.begin();

    // Checking content
    if(m_config.size() < 1) {
        std::cout << "NULL" << std::endl;
        return;
    }

    // Displaying content
    std::cout << "Configuration loaded : " << std::endl;
    for(it = m_config.begin(); it !=m_config.end(); ++it) {
        std::cout << "$" << it->first << " = " << it->second << std::endl;
    }
}

/**
 * \param paramName the Name of the param
 * \return param
 */
std::string Configuration::getParam(std::string paramName) {
    std::map <std::string, std::string>::iterator it = m_config.begin();

    for(it = m_config.begin(); it !=m_config.end(); ++it) {
        if(it->first == paramName)
            return it->second;
    }

    return NULL;
}
