/*!
 * \file Cast.hpp
 * \brief All utility
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-04
 */

#ifndef DEF_TOOL_HPP
#define DEF_TOOL_HPP

#include <string>
#include <sstream>
#include <stdlib.h>

namespace cast
{
    int toInt(const std::string& v);
    int toInt(const int& v);

    bool toBool(const std::string& v);
    bool toBool(const bool& v);

    /*!
     * \brief Convert a value into a std::string
 	 */
    template <typename T> std::string toString(const T& t) {
        std::ostringstream os;
        os << t;
        return os.str();
    }
}

#endif // DEF_TOOL_HPP