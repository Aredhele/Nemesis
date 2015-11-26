/**
 * \brief Exception class of Parser
 * \file ParserException.hpp
 * \author Aredhele
 * \version 0.1
 * \date 19/11/2015
 * \class ParserException
 */

#ifndef DEF_PARSER_PARSER_EXCEPTION_HPP
#define DEF_PARSER_PARSER_EXCEPTION_HPP

#include <iostream>
#include <sstream>
#include <exception>

class ParserException : public std::exception
{
    private:
        std::string m_msg;

    public:
        ParserException(const char * Msg, int Line );

        virtual ~ParserException() throw() {
            // None
        }

        virtual const char * what() const throw() {
            return this->m_msg.c_str();
        }
};

#endif // DEF_PARSER_PARSER_EXCEPTION_HPP
