/*!
 * \file ClientThreadException.cpp
 * \brief handle threadException
 * \author Aredhele
 * \version 0.1
 * \date 20015-12-02
 */

#include "ClientThreadException.hpp"

/*!
 * \brief Constructor.
 * \param msg The message to display
 * \param line The line number where exception has been thrown
 */
ClientThreadException::ClientThreadException(const char * msg, int line) {
	std::ostringstream oss;
	oss << "Error line  " << line << " : " << msg;
	this->m_msg = oss.str();
}