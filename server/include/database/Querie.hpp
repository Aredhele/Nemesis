/**
 * \brief C++ Queries Prototype
 * \file Querie.hpp
 * \author Aredhele
 * \version 0.1
 * \date 14/11/2015
 */

#ifndef DEF_SERVER_QUERIE_HPP
#define DEF_SERVER_QUERIE_HPP

// Headers
#include "Table.hpp"

/**
 * \brief Static functions
 * \namespace Querie
 */
namespace Querie
{
    std::string select(Table *table);
    std::string select(Table *table, const char *arg, ...);
}

#endif // DEF_SERVER_QUERIE_HPP