/*!
 * \file HashTool.hpp
 * \brief Hash a file
 * \author Aredhele
 * \version 0.1
 * \date 2015-11-29
 */

#ifndef DEF_HAST_TOOL_HPP
#define DEF_HAST_TOOL_HPP

// Header
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>

#include <openssl/sha.h>

class HashTool {

	private:
		std::string m_pathToFile;
		std::string m_hash;
		
		// Methods
		int SHA256();

	public:
		// Constructor
		HashTool();

		// Destructor
		~HashTool();

		// Getters
		std::string getHash();

		// Setters
		void setPathToFile(std::string pathToFile);

};

#endif // DEF_HAST_TOOL_HPP
 