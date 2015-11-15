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
#include <winsock2.h>
#include "mysql/mysql.h"

class MySQLConnector {

    private:
        MYSQL * m_ptr_mysql;
    
    public:
        MySQLConnector();
};

#endif // DEF_SERVER_MYSQL_CONNECTOR_HPP
