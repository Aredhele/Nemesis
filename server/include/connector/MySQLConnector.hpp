/**
 * \brief Connector with MySQL server
 * \file MySQL.cpp
 * \author Aredhele
 * \version 0.1
 * \date 15/11/2015
 * \class MySQL
 */

#ifndef DEF_SERVER_MYSQL_CONNECTOR_HPP
#define DEF_SERVER_MYSQL_CONNECTOR_HPP

// Header
#include <string>
#include <iostream>
#include <winsock2.h>
#include "mysql/mysql.h"

#include <tool/Config.hpp>

class MySQLConnector {

    private:
        MYSQL * m_ptr_mysql;

        char m_adr[255];
        char m_id[255];
        char m_pass[255];
        char m_bdName[255];
        char *m_socket;
        unsigned int m_port;
        unsigned long m_flag;

        // Method
        void init(std::string adr, std::string id, std::string pass,
                  std::string bdname, unsigned int port, unsigned long flag);

    public:
        // Constructor
        MySQLConnector();
        MySQLConnector(Config conf);

        // Destructor
        ~MySQLConnector();

        // Methods
        int connect();
        void disconnect();

        // Getter
        // TODO

        // Setters
        void setId(std::string id);

};

#endif // DEF_SERVER_MYSQL_CONNECTOR_HPP
