/**
 * \brief Connector with MySQL server
 * \file MySQLConnector.hpp
 * \author Aredhele
 * \version 0.1
 * \date 15/11/2015
 * \class MySQL
 */

#ifndef DEF_SERVER_MYSQL_CONNECTOR_HPP
#define DEF_SERVER_MYSQL_CONNECTOR_HPP

// Header
#include <string>
#include <limits>
#include <stdio.h>
#include <iostream>
#include <winsock.h>

#include "mysql/mysql.h"

#include "tool/Config.hpp"
#include "database/Table.hpp"

class MySQLConnector {

    private:
        MYSQL * m_ptr_mysql;

        char m_adress[32];
        char m_blogin[32];
        char m_passwd[32];
        char m_bdName[32];
        char *m_socket = NULL;
        unsigned int m_port;
        unsigned long m_flag;

        // Method
        void init(std::string adress, std::string blogin, std::string passwd,
                  std::string bdName, unsigned int port, unsigned long flag);

        void buildQuery(std::string *query);
        void buildQuery(std::string *query, std::string tableName);

    public:
        // Constructor
        MySQLConnector();
        MySQLConnector(Config conf);

        // Destructor
        ~MySQLConnector();

        // Methods
        int connect();
        void disconnect();

        // Querie
        std::vector < Table* > getTablesName();
        void getColumnsFromTable(Table *table);
        void getFieldFromTable(Table *table);

        // Getter
        // TODO

        // Setters
        void setId(std::string login);
};

#endif // DEF_SERVER_MYSQL_CONNECTOR_HPP
