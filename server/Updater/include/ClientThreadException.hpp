/*!
 * \file ClientThreadException.hpp
 * \brief handle threadException
 * \author Aredhele
 * \version 0.1
 * \date 20015-12-02
 */

#ifndef DEF_CLIENT_THREAD_EXCEPTION_HPP
#define DEF_CLIENT_THREAD_EXCEPTION_HPP

#include <iostream>
#include <sstream>
#include <exception>

class ClientThreadException : public std::exception
{
    private:
    	// Member
        std::string m_msg;

    public:
    	// Constructor
        ClientThreadException(const char * msg, int line);

        // Destructor
        virtual ~ClientThreadException() throw() {}

        // Method
        virtual const char * what() const throw() {
            return this->m_msg.c_str();
        }
};

#endif // DEF_CLIENT_THREAD_EXCEPTION_HPP