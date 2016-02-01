/**
 * \brief Sample class to store two strings
 * \file Vector2Str.cpp
 * \author Aredhele
 * \version 0.1
 * \date 19/11/2015
 * \class Vector2Str
 */

// Header
#include "tool/Vector2Str.hpp"

/**
 * \brief Constructor.
 */
Vector2Str::Vector2Str() {
    x = "NONE";
    y = "NONE";
}

/**
 * \brief Constructor.
 * \param first The value of x
 * \param second The value of y
 */
Vector2Str::Vector2Str(std::string first, std::string second) {
    x = first;
    y = second;
}

/**
 * \brief Destructor.
 */
Vector2Str::~Vector2Str() {
    // None
}
