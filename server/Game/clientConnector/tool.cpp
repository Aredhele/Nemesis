/*!
 * \file Cast.hpp
 * \brief All utility
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-04
 */

#include "clientConnector/tool.hpp"

/*!
 * \param s the string to convert
 * \return the converted int
 */
int cast::toInt(const std::string& v) {
    return atoi(v.c_str());
}

/*!
 * \param v a int
 * \return the parameter
 */
int cast::toInt(const int& v) {
    return v;
}

/*!
 * \param v a string to convert
 * \return the string converted
 */
bool cast::toBool(const std::string& v) {
    return (v == "TRUE") ? true : false;
}

/*!
 * \param v a boolean
 * \return the parameter
 */
bool cast::toBool(const bool& v) {
    return v;
}

/*!
 * \brief Convert a value into a string
 */
template <typename T> std::string cast::toString(const T& t) {
    std::ostringstream os;
    os << t;
    return os.str();
}