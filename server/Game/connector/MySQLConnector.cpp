/**
 * \brief Connector with MySQL server
 * \file MySQLConnector.cpp
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
    m_ptr_mysql = new MYSQL();
    m_ptr_mysql = mysql_init(NULL);

    mysql_options(m_ptr_mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    init("127.0.0.1", "root", "", "Nemesis", 0, 0);
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

    // TODO - Pointers
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
void MySQLConnector::init(std::string adress, std::string blogin, std::string passwd,
                          std::string bdName, unsigned int port, unsigned long flag) {

    strcpy(m_adress, adress.c_str());
    strcpy(m_blogin, blogin.c_str());
    strcpy(m_passwd, passwd.c_str());
    strcpy(m_bdName, bdName.c_str());
    m_socket = NULL;
    m_port = port;
    m_flag = flag;
}

/**
 * \brief Etablish a persistant connection with mysql server
 */
int MySQLConnector::connect() {

    if(mysql_real_connect(m_ptr_mysql, m_adress, m_blogin,
                          m_passwd, m_bdName, m_port, m_socket, m_flag))
    {
        // TODO - ConsoleDisplayer
        std::cout << "CONNECTED" << std::endl;
    }
    else
    {
        // TODO - ConsoleDisplayer
        std::cout << "ERROR CONNECTOR" << std::endl;
        std::cout << "ERROR : " << mysql_error(m_ptr_mysql) << std::endl;

        return EXIT_FAILURE;
    }

    return  EXIT_SUCCESS;
}

/**
 * \brief Disconnect server from the mysql server
 */
void MySQLConnector::disconnect() {
    mysql_close(m_ptr_mysql);
    std::cout << "DISCONNECTED" << std::endl;
}

/**
 * \brief Build the query with the database name
 * \parma query a pointer on a string
 */
void MySQLConnector::buildQuery(std::string *query) {
    *query += m_bdName;
    *query += "'";
}

/**
 * \brief Build the query with the database name and the table name
 * \param query a pointer on a string
 * \param tableName the name of the table
 */
void MySQLConnector::buildQuery(std::string *query, std::string tableName) {
    *query += m_bdName;
    *query += "'";
    *query += "AND TABLE_NAME = '";
    *query += tableName;
    *query += "'";
}

/**
 * \brief return all the table name from the current database
 * \return tables A vector of pointer on tables
 */
std::vector<Table *> MySQLConnector::getTablesName() {

    std::string query = "SELECT TABLE_NAME "
            "FROM INFORMATION_SCHEMA.TABLES "
            "WHERE TABLE_SCHEMA = '";

    buildQuery(&query);
    mysql_query(m_ptr_mysql, query.c_str());

    MYSQL_RES *result = NULL;
    MYSQL_ROW row;

    unsigned int fieldNum = 0;

    result = mysql_store_result(m_ptr_mysql);
    fieldNum = mysql_num_fields(result);

    std::vector < Table* > tables;

    while((row = mysql_fetch_row(result))) {
        mysql_fetch_lengths(result);

        for(int i = 0; i < fieldNum; i++) {
            tables.push_back(new Table(row[i]));
        }
    }

    mysql_free_result(result);
    result = NULL;

    return tables;
}

/**
 * \brief Set the columns of the table from the database
 * \param table a pointer on the table to fill with columns
 */
void MySQLConnector::getColumnsFromTable(Table *table) {

    std::string query = "SELECT COLUMN_NAME "
            "FROM INFORMATION_SCHEMA.COLUMNS "
            "WHERE TABLE_SCHEMA = '";

    buildQuery(&query, table->getTableName());
    mysql_query(m_ptr_mysql, query.c_str());

    MYSQL_RES *result = NULL;
    MYSQL_ROW row;

    unsigned int fieldNum = 0;

    result = mysql_store_result(m_ptr_mysql);
    fieldNum = mysql_num_fields(result);

    while((row = mysql_fetch_row(result))) {
        mysql_fetch_lengths(result);

        for(int i = 0; i < fieldNum; i++) {
            table->addColumns(row[i]);
        }
    }

    mysql_free_result(result);
    result = NULL;
}

/**
 * \brief Load all field in columns
 * \param table the pointer on the table to fill
 */
void MySQLConnector::getFieldFromTable(Table *table) {

    std::string query = "SELECT * FROM ";
    query += table->getTableName();
    mysql_query(m_ptr_mysql, query.c_str());

    MYSQL_RES *result = NULL;
    MYSQL_ROW row;

    unsigned int fieldNum = 0;
    int k = 0;

    result = mysql_store_result(m_ptr_mysql);
    fieldNum = mysql_num_fields(result);

    while((row = mysql_fetch_row(result))) {
        mysql_fetch_lengths(result);
        table->addRow();

        for(int i = 0; i < fieldNum; i++) {
            std::string str(row[i]);
            (*table->getFieldArray())[k].push_back(new Field(str));
        }
        k++;
    }

    mysql_free_result(result);
    result = NULL;
}

/**
 * Setters
 * \param id The login of the mysql server
 */
void MySQLConnector::setId(std::string login) {
    strcpy(m_blogin, login.c_str());
}