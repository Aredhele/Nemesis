/**
 * \brief C++ Queries like to extract data from object
 * \file Querie.cpp
 * \author Aredhele
 * \version 0.1
 * \date 14/11/2015
 */

// Headers
#include <stdarg.h>
#include <stddef.h>
#include <iostream>

#include "database/Querie.hpp"

/**
 * \brief return all the data from a table
 * \param table the data
 * \return TODO
 */
std::string Querie::select(Table *table) {

}

/**
 * \brief return specific columns from a table
 * \param table the data
 * \param arg argument number
 * \param ... columns
 * \return TODO
 */
std::string Querie::select(Table *table, const char *arg,  ...) {
    va_list arguments;

    for (va_start(arguments, arg); arg != NULL; arg = va_arg(arguments, const char *)) {
        std::cout << arg << std::endl;
    }

    table->getTableName();

    va_end(arguments);

    return "";
}
