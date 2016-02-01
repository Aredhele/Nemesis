/**
 * \brief Sample class to store two strings
 * \file Vector2Str.hpp
 * \author Aredhele
 * \version 0.1
 * \date 19/11/2015
 * \class Vector2Str
 */

#ifndef DEF_PARSER_VECTOR2STR_HPP
#define DEF_PARSER_VECTOR2STR_HPP

// Header
#include <string>

class Vector2Str {

public:
    // Constructor
    Vector2Str();
    Vector2Str(std::string first, std::string second);

    // Destructor
    ~Vector2Str();

    // Member
    std::string x;
    std::string y;
};

#endif // DEF_PARSER_VECTOR2STR_HPP
