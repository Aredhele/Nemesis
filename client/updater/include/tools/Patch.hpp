/*!
 * \file Patch.hpp
 * \brief Allow to use some missing functions
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-23
 */

#ifndef DEF_PATCH_HPP
#define DEF_PATCH_HPP

#include <string>
#include <sstream>

namespace cast
{
	/*!
	 * \brief Convert a value into a string
	 */
	template <typename T> std::string toString(const T& t) {
		std::ostringstream os;
		os << t;
		return os.str();
	}

	template <typename T> std::wstring towstring(const T& t){
		std::wostringstream ws;
		ws << t;
		return std::wstring(ws.str());
	}
}

#endif // DEF_PATCH_HPP