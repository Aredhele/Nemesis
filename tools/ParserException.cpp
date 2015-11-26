/**
 * \brief Exception class of Parser
 * \file ParserException.cpp
 * \author Aredhele
 * \version 0.1
 * \date 19/11/2015
 * \class ParserException
 */

#include "exception/ParserException.hpp"

ParserException::ParserException(const char *Msg, int Line) {
    std::ostringstream oss;
    oss << "Error line  " << Line << " : " << Msg;
    this->m_msg = oss.str();
}