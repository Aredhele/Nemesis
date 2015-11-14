/**
 * \brief Table of data
 * \file Table.cpp
 * \author Aredhele
 * \version 0.1
 * \date 15/11/2015
 * \class Table
 */

#include "database/Table.hpp"

/**
 * \brief Constructor.
 * \param field a field of a row
 */
Table::Table() {
    m_name = "unknow";
}

/**
 * \brief Constructor.
 * \param field a field of a row
 */
Table::Table(std::string name) {
    m_name = name;
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
 * \return m_fieldArray the data of the table
 */
std::vector <std::vector < Field > > *Table::getFieldArray() {
    return &m_fieldArray;
}
