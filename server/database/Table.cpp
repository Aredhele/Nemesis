/**
 * \brief Table of data
 * \file Table.cpp
 * \author Aredhele
 * \version 0.1
 * \date 15/11/2015
 * \class Table
 */

// Header
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
 * \brief Add a column to the table
 * \param columnName The name of the table
 */
void Table::addColumns(std::string columnName) {
    m_columnsName.push_back(columnName);
}

/**
 * \brief Add a row to the field array
 */
void Table::addRow() {
    m_fieldArray.push_back(std::vector < Field* > ());
}

/**
 * \brief display the exact number of dash
 */
void Table::displayDash() {

    // Counting dash
    int dash = 0;
    for(int i = 0; i < m_columnsName.size(); i++) dash += m_columnsName[i].size();

    dash += m_columnsName.size() - 1;
    dash += m_columnsName.size() * 2;

    std::cout << "+";
    for(int i = 0; i < dash; i++) std::cout << "-";
    std::cout << "+" << std::endl;
}

/**
 * \brief Display columns name
 */
void Table::displayColumns() {
    displayDash();

    std::cout << "| ";
    for(int i = 0; i < m_columnsName.size(); i++) {
        std::cout << m_columnsName[i] << " | ";
    }
    std::cout << std::endl;
    displayDash();
}

void Table::displayFields() {

    for(int i = 0; i < m_fieldArray.size(); i++) {
        std::cout << "|";
        for(int j = 0; j < m_fieldArray[i].size(); j++) {
            std::cout << " " << m_fieldArray[i][j]->getFieldData();

            for(int k = 0; k < m_columnsName[j].size() + 2 - m_fieldArray[i][j]->getFieldData().size() - 1; k++)
                std::cout << " ";

            std::cout << "|";
        }
        std::cout << std::endl;
        displayDash();
    }
    /*std::cout << "Size : " << m_fieldArray.size() << std::endl;
    std::cout << "Size : " << m_fieldArray[0].size() << std::endl;
    std::cout << "Size : " << m_fieldArray[1].size() << std::endl;*/
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
