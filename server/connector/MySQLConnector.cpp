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
 * Destructor.
 * \brief delete m_ptr_mysql
 */
MySQLConnector::~MySQLConnector() {
    delete m_ptr_mysql;
    m_ptr_mysql = 0;
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
std::string bdname, unsigned int port, unsigned long flag) {

    strcpy(m_adr, adr.c_str());
    strcpy(m_id, id.c_str());
    strcpy(m_pass, pass.c_str());
    strcpy(m_bdName, bdname.c_str());
    m_socket = NULL;
    m_port = port;
    m_flag = flag;
}

/**
 * \brief Etablish a persistant connection with mysql server
 * \Deprecated Prefer use a temporary connection
 */
int MySQLConnector::connect() {
    if(mysql_real_connect(m_ptr_mysql, m_adr, m_id, m_pass,
    m_bdName, m_port, m_socket, m_flag)) {
        // TODO - ConsoleDisplayer
    } else {
        // Error
        // TODO - ConsoleDisplayer
        std::cout << "Error : " << m_ptr_mysql->server_status << std::endl;
        return EXIT_FAILURE;
    }

    return  EXIT_SUCCESS;
}

/**
 * \brief Disconnect server from the mysql server
 */
void MySQLConnector::disconnect() {
    mysql_close(m_ptr_mysql);
}
