/**
 * \brief Table of data
 * \file Table.cpp
 * \author Aredhele
 * \version 0.1
 * \date 15/11/2015
 * \class Table
 */

// Header
#include <stdarg.h>

#include "database/Table.hpp"

/**
 * \brief Constructor.
 * \param name name of the table
 */
Table::Table(std::string name) {
    m_name = name;
}

/**
 * \brief Constructor.
 * \param name name of the table
 * \param arg name of columns
 */
Table::Table(std::string name, const char *arg, ...) {
    m_name = name;

    // Creating columns
    va_list arguments;

    for (va_start(arguments, arg); arg != NULL; arg = va_arg(arguments, const char *)) {
        m_columnsName.push_back(arg);
    }

    va_end(arguments);
}

/**
 * \brief Destructor.
 */
Table::~Table() {
    // None
}

/**
 * Getters
 * \return m_name the name of the table
 */
std::string Table::getTableName() {
    return m_name;
}

/**
 * \return m_columnsName The name of all columns
 */
std::vector < std::string > *Table::getColumnsName() {
    return &m_columnsName;
}

/**
 * \return m_fieldArray the data of the table
 */
std::vector <std::vector < Field* > > *Table::getFieldArray() {
    return &m_fieldArray;
}
