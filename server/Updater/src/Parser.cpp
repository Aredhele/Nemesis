/**
 * \brief Parse a configuration file and store it
 * \file Parser.cpp
 * \author Aredhele
 * \version 0.1
 * \date 19/11/2015
 * \class Parser
 */

// Header
#include "Parser.hpp"

/**
 * \brief Constructor.
 */
Parser::Parser(ConsoleDisplayer * displayer) {
    m_ptr_displayer = displayer;
    m_configurationFilePath = "../res/conf/config.conf";
    m_ptr_configuration = new Configuration(displayer);
}

/**
 * \brief Constructor.
 * \param configurationFilePath Path to file
 */
Parser::Parser(std::string configurationFilePath, ConsoleDisplayer * displayer) {
    m_ptr_displayer = displayer;
    m_configurationFilePath = configurationFilePath;
    m_ptr_configuration = new Configuration(displayer);
}

/**
 * \brief Destructor.
 */
Parser::~Parser() {
    delete(m_ptr_configuration);
    delete(m_ptr_displayer);
    m_ptr_configuration = nullptr;
    m_ptr_displayer = nullptr;
}

/**
 * \brief Parse the configuration File
 * \brief and return the configuration
 * \return config The configuration
 */
Configuration * Parser::parse() {
    std::ifstream file;
    Vector2Str *parameter = nullptr;

    try {
        file.open(m_configurationFilePath);
        if(file.fail()) throw ParserException("Unable to open the file, bad path", __LINE__);
    } catch (const ParserException &e) {
        m_ptr_displayer->displayMessage("Fail", "Opening configuration file");
        std::cerr << e.what() << std::endl;
        return nullptr;
    }

    m_ptr_displayer->displayMessage("Info", "Configuration file opened");
    for(std::string line; getline(file, line); ) {
        if (line[0] != '#' && line.size() > 5) {
            parameter = getParameters(line);
            if(parameter != nullptr)
                m_ptr_configuration->addParam(parameter);
        }
    }

    m_ptr_displayer->displayMessage("Info", "Configuration fully loaded");
    delete(parameter);
    parameter = nullptr;
    file.close();
    return m_ptr_configuration;
}

/**
 * \param line The line to analyze
 * \return new Vector2Str
 */
Vector2Str * Parser::getParameters(std::string line) {

    std::string name, value = "";
    try {
        name = getWord(line, 0);
        if (name.size() + 3 > line.size())
            throw ParserException("Error while parsing configuration file, nullptr", __LINE__);
        value = getWord(line, name.size() + 3);
    }
    catch (const ParserException &e) {
        m_ptr_displayer->displayMessage("Fail", "Error while parsing configuration file");
        std::cerr << e.what() << std::endl;
        return nullptr;
    }
    return new Vector2Str(name, value);
}

/**
 * \param line The line to analyze
 * \param n Where the loop begin to search
 * \return ret
 */
std::string Parser::getWord(std::string line, int n) {
    std::string ret = "";
    for(unsigned int i = n; i < line.size(); ++i) {
        if(checkChar(line[i]))  ret += line[i];
        else break;
    }
    return ret;
}

/**
 * \param toCheck The char to check
 */
bool Parser::checkChar(char toCheck) {
    if (toCheck >= 'A' && toCheck <= 'Z') return true;
    if (toCheck >= '0' && toCheck <= '9') return true;
    return toCheck == '.' || toCheck == '_';
}
