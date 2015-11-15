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
        std::cout << "CONNECTED" << std::endl;
    } else {
        // Error
        // TODO - ConsoleDisplayer
        // TODO - Exception
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
    // TODO - ConsoleDisplayer
    // FIXME - nullptr
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
 * \return
 */
std::vector<Table *> MySQLConnector::getTablesName() {

    // Building query
    std::string query = "SELECT TABLE_NAME "
            "FROM INFORMATION_SCHEMA.TABLES "
            "WHERE TABLE_SCHEMA = '";

    buildQuery(&query);

    // Querie
    mysql_query(m_ptr_mysql, query.c_str());

    MYSQL_RES *result = NULL;
    MYSQL_ROW row;

    unsigned int fieldNum = 0;

    // Getting result
    // Getting field number
    result = mysql_store_result(m_ptr_mysql);
    fieldNum = mysql_num_fields(result);

    // Declaring vector of tables to return
    std::vector < Table* > tables;

    while((row = mysql_fetch_row(result))) {

        // Getting lenghts of row
        mysql_fetch_lengths(result);

        for(int i = 0; i < fieldNum; i++) {
            tables.push_back(new Table(row[i]));
        }
    }

    // Releasing result game
    mysql_free_result(result);


    return tables;
}

/**
 * \brief Set the columns of the table from the database
 * \param table a pointer on the table to fill with columns
 */
void MySQLConnector::getColumnsFromTable(Table *table) {
    // Connection to the mysql server
    // connect();

    // Building query
    std::string query = "SELECT COLUMN_NAME "
            "FROM INFORMATION_SCHEMA.COLUMNS "
            "WHERE TABLE_SCHEMA = '";

    buildQuery(&query, table->getTableName());

    // Querie
    mysql_query(m_ptr_mysql, query.c_str());

    MYSQL_RES *result = NULL;
    MYSQL_ROW row;

    unsigned int fieldNum = 0;

    // Getting result
    // Getting field number
    result = mysql_store_result(m_ptr_mysql);
    fieldNum = mysql_num_fields(result);

    while((row = mysql_fetch_row(result))) {

        // Getting lenghts of row
        mysql_fetch_lengths(result);

        for(int i = 0; i < fieldNum; i++) {
            table->addColumns(row[i]);
        }
    }

    // Releasing result game
    mysql_free_result(result);

    // Disconnection from the server
    // disconnect();
    // FIXME
}

/**
 * \brief Load all field in columns
 * \param table the pointer on the table to fill
 */
void MySQLConnector::getFieldFromTable(Table *table) {

    // Building query
    std::string query = "SELECT * FROM ";
    query += table->getTableName();
    //std::cout << query << std::endl;
    // Querie
    mysql_query(m_ptr_mysql, query.c_str());
    //std::cout << "THAT BUGGGGG" << std::endl;
    MYSQL_RES *result = NULL;
    MYSQL_ROW row; // = char **

    unsigned int fieldNum = 0;

    // Getting result
    // Getting field number
    result = mysql_store_result(m_ptr_mysql);
    //std::cout << "I'am HERREEEEEEE !" << std::endl;

    try {
        fieldNum = mysql_num_fields(result); // Hum ... What are you doing against try catch ?
        throw std::string("Erreur de mysql_num_fields(result)...");
    } catch (std::string e) {
        std::cout << "";
    }

    int k = 0;
    //std::cout << "AND HERE !" << std::endl;
    //std::cout << "ohehehe" << std::endl;
    while((row = mysql_fetch_row(result))) {
        // Getting lenghts of row
        mysql_fetch_lengths(result);
        //std::cout << "+ 1" << std::endl; // push two dimension
        table->addRow();

        // Pushing data
        for(int i = 0; i < fieldNum; i++) {
            std::string str(row[i]);
            (*table->getFieldArray())[k].push_back(new Field(str));
        }
        k++;
    }
    //std::cout << "ouffff !" << std::endl;
    // Releasing result game
    mysql_free_result(result);
}

/**
 * Setters
 * \param id The login of the mysql server
 */
void MySQLConnector::setId(std::string id) {
    strcpy(m_id, id.c_str());
}
