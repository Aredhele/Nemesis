/*!
 * \file Configuration.cpp
 * \brief Store the configuration
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-20
 */

#include <bits/stringfwd.h>
#include "tool/Configuration.hpp"

/*!
 * \brief Constructor
 * \param ptr_displayer The pointeur on the displayer
 * \return None
 */
Configuration::Configuration(ConsoleDisplayer * ptr_displayer) {

    m_ptr_displayer = ptr_displayer;
}

/*!
 * \brief Destructor
 * \return None
 */
Configuration::~Configuration() {
    // None
}

/*!
 * \brief Read and load the entire conf file
 * \param path The path to the conf file
 * \return -1 on failure, 0 on success
 */
int Configuration::readConfiguration(std::string path) {

    char line[CONF_BUFFER_SIZE];
    char key[CONF_BUFFER_SIZE];
    char value[CONF_BUFFER_SIZE];

    FILE * config;
    int i = 0;

    if((config = fopen(path.c_str(), "r")) == NULL) {
        m_ptr_displayer->displayMessage("fail", "Unable to open the file");
        return FAILURE;
    }

    while((fgets(line, CONF_BUFFER_SIZE, config) != NULL)
          && (i < CONF_MAX_P)) {

        if(line[0] == '#' || strlen(line) < 5) continue;

        if(sscanf(line, "%s = %s", key, value) != 2) {
            m_ptr_displayer->displayMessage("fail",
                                     "Error while reading conf");
            m_ptr_displayer->displayMessage("fail",
                                     "sscanf return bad number of arguments");
            return FAILURE;
        }

        m_config.insert(std::pair <std::string, std::string>(key, value));
        i++;
    }

    m_ptr_displayer->displayMessage("scss", "Number of param loaded : " + cast::toString(i));
    fclose(config);

    return SUCCESS;
}

/*!
 * \brief To use for a game updater
 * \brief Read and load file path and hash
 * \param path The path to the info list
 * \return -1 on failure, 0 on success
 */
int Configuration::readFileInfo(std::string path) {

    // Opening stream
    std::ifstream is;
    is.open(path);

    if(is.fail()) {
        m_ptr_displayer->displayMessage("erro", "Unable to open the file");
        return FAILURE;
    }

    m_ptr_displayer->displayMessage("info", "File opened, parsing ...");

    // Counting line numer
    // If count if not pair
    // Return failure
    int count = 0;
    bool level = false;
    for(std::string line; getline(is, line); ) {
        if(!level) {
            m_pathList.push_back(line);
            level = true;
        } else {
            m_hashList.push_back(line);
            level = false;
        }
        count++;
    }

    // Checking count
    if(count % 2 != 0 || count == 0) {
        m_ptr_displayer->displayMessage("erro", "Some lines are missing");
        return FAILURE;
    }

    m_ptr_displayer->displayMessage("scss", "File successfully loaded");
    m_ptr_displayer->displayMessage("info", cast::toString(count) + " lines loaded");

    // Closing stream
    is.close();

    return SUCCESS;
}

/*!
 * \brief Display the entire configuration map
 * \return -1 if the configuration is empty, 0 on success
 */
int Configuration::displayConfiguration() {

    // Declaring iterator
    std::map <std::string, std::string>::iterator it = m_config.begin();

    // Checking content
    if(m_config.size() < 1) {
        m_ptr_displayer->displayMessage("Warn", "Configuration empty");
        return FAILURE;
    }

    // Displaying content
    m_ptr_displayer->displayMessage("scss", "Configuration loaded : \n");
    for(it = m_config.begin(); it != m_config.end(); ++it) {
        m_ptr_displayer->displayMessage("info",
                                 "$" + it->first + " = " + it->second);
    }

    std::cout << std::endl;
    return SUCCESS;
}

/*!
 * \brief Return the param associated to the given key
 * \param key The key to find the param
 * \return the param referenced by key NULL is not found
 */
const std::string Configuration::getParam(std::string key) {

    // Declaring iterator
    std::map <std::string, std::string>::iterator it = m_config.begin();

    for(it = m_config.begin(); it !=m_config.end(); ++it) {
        if(it->first == key) return it->second;
    }

    return "NULL";
}

/*!
 * \return m_pathList The list of path
 */
const std::vector < std::string > Configuration::getPathList() {
    return m_pathList;
}

/*!
 * \return m_pathList The list of path
 */
const std::vector < std::string > Configuration::getHashList() {
    return m_hashList;
}