/*!
 * \file FileManager.hpp
 * \brief Manage files
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-05
 */
 
#ifndef DEF_FILE_MANAGER_HPP
#define DEF_FILE_MANAGER_HPP

// Const
#define _PATH_FILES_LIST_ "../res/files/filesInfo.txt"
#define _PATH_TO_RES_ "../res"

// Header
#include <vector>
#include <fcntl.h>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <iostream>

#include "HashTool.hpp"

class FileManager
{
	private:
		std::vector < std::string > m_filesList;
		std::vector < std::string > m_hashList;
		std::vector < std::string > m_clientFilesList;
		std::vector < std::string > m_filesToUpload;
		HashTool * m_ptr_hashTool;
		int loadFilesList();

	public:
		// Constructor
		FileManager();

		// Destructor
		~FileManager();

		// Methods
		void addClientFileToList(std::string path);
		void addClientHashToList(std::string hash);
		void stringCopy(char * array, std::string data);
		int compare();

		// Gettters
		std::string getPath(int index);
		int getFileLen(std::string path);
};

#endif // DEF_FILE_MANAGER_HPP