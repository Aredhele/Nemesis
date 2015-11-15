/**
 * \brief Connector with MySQL server
 * \file MySQL.cpp
 * \author Aredhele
 * \version 0.1
 * \date 15/11/2015
 * \class MySQL
 */

// Header
#include "connector/MySQLConnector.hpp"

/**
 * \brief Constructor.
 * \brief Initialize connection with default value
 */
MySQLConnector::MySQLConnector() {
    // Init MySQL Object
    m_ptr_mysql = new MYSQL();
    mysql_init(m_ptr_mysql);

    // Set up option
    mysql_options(m_ptr_mysql, MYSQL_READ_DEFAULT_GROUP, "option");

    // Setting connection var
    init("127.0.0.1", "root", "", "nemesis", 0, 0);
}

/**
 * \brief Constructor.
 * \param conf The config for db connection
 */
MySQLConnector::MySQLConnector(Config conf) {
    // TODO
}

/**
 * \brief Configure the connection data
 * \param adr Adress of mysql server
 * \param id Login to access the mysql server
 * \param pass Password to access the mysql server
 * \param bdname Name of the database
 * \param port Port of the connection
 * \param flag options
 */
void MySQLConnector::init(std::string adr, std::string id, std::string pass,
std::string bdname, int port, int flag) {

    strcpy(m_adr, adr.c_str());
    strcpy(m_id, id.c_str());
    strcpy(m_pass, pass.c_str());
    strcpy(m_bdName, bdname.c_str());
    m_socket = NULL;
    m_port = port;
    m_flag = flag;
}
