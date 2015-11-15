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
#include <stdio.h>
#include <iostream>
#include <winsock2.h>
#include "mysql/mysql.h"

#include "tool/Config.hpp"
#include "database/Table.hpp"

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
        void setId(std::string id);

};

#endif // DEF_SERVER_MYSQL_CONNECTOR_HPP
