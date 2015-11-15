/**
 * \brief Contains db data
 * \file Table.hpp
 * \author Aredhele
 * \version 0.1
 * \date 14/11/2015
 * \class Table
 */

#ifndef DEF_SERVER_TABLE_HPP
#define DEF_SERVER_TABLE_HPP

// Header
#include <string>
#include <vector>

#include "Field.hpp"

class Table
{
    private:
        std::string m_name;
        std::vector < std::string > m_columnsName;
        std::vector < std::vector < Field* > > m_fieldArray;

    public:
        // Constructors
        Table(std::string name);
        Table(std::string name, const char *arg, ...);

        // Destructor
        ~Table();

        // Getters
        std::string getTableName();
        std::vector < std::string > * getColumnsName();
        std::vector < std::vector < Field* > > * getFieldArray();
};

#endif // DEF_SERVER_TABLE_HPP
