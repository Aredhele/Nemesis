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
Configuration::Configuration(ConsoleDisplayer * displayer) {
    m_ptr_displayer = displayer;
}

/**
 * \brief Destructor.
 */
Configuration::~Configuration() {

}

/**
 * \brief Insert a new param to m_config
 * \param name The name of the parameter
 * \param value The value of the parameter
 */
void Configuration::addParam(std::string name, std::string value) {
    m_config.insert (std::pair <std::string, std::string>(name, value) );
}

void Configuration::addParam(Vector2Str * param) {
    m_config.insert (std::pair <std::string, std::string>(param->x, param->y) );
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
    m_ptr_displayer->displayMessage("Configuration loaded : ");
    for(it = m_config.begin(); it !=m_config.end(); ++it) {
        m_ptr_displayer->displayMessage("$" + it->first + " = " + it->second);
    }
}
