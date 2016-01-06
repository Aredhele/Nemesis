/*!
 * \file FileManager.cpp
 * \brief Manage files
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-05
 */

#include "FileManager.hpp"

/*!
 * \brief Constructor
 */
FileManager::FileManager() {
	m_ptr_hashTool = new HashTool();
	loadFilesList();
}

/*!
 * \brief Destructor
 */
FileManager::~FileManager() {
	// TODO
}

/*!
 * \brief load into a vector all files path
 */
int FileManager::loadFilesList() {
	std::ifstream file;

    file.open(_PATH_FILES_LIST_);
    if(file.fail()) {
    	return -1;
    }
    
    for(std::string line; getline(file, line); ) {
        m_filesList.push_back(line);
    }

    return 0;
}

/*!
 * \brief Store the path of a file from client
 */
void FileManager::addClientFileToList(std::string path) {
	m_clientFilesList.push_back(path);
}

/*!
 * \brief Store the path of a file from client
 */
void FileManager::addClientHashToList(std::string hash) {
	m_hashList.push_back(hash);
}

/*!
 * \brief Compare server files with client files
 */
int FileManager::compare() {
	using uint = unsigned int;
	bool isFound;

	for(uint i = 0; i < m_filesList.size(); ++i) {

		isFound = false;

		for(uint j = 0; j < m_clientFilesList.size(); ++j) {

			//std::cout << m_clientFilesList[j] << std::endl;
			//m_ptr_hashTool->setPathToFile(_PATH_TO_RES_ + m_filesList[i]);
			//std::string tmp_hash = m_ptr_hashTool->getHash();
			//std::cout << tmp_hash << std::endl;

			// std::cout << m_filesList[i] << " + " << m_clientFilesList[j] << std::endl;
			if(("client\\" + m_filesList[i]) == m_clientFilesList[j]) {
				//std::cout << "aarz" << std::endl;
				//std::cin.ignore();
				m_ptr_hashTool->setPathToFile("..\\res\\client\\" + m_filesList[i]);
				std::string tmp_hash = m_ptr_hashTool->getHash();

				if(tmp_hash == m_hashList[j]) {
					//std::cout << tmp_hash << " + " << m_hashList[j] << std::endl;
					isFound = true;
					break;
				} else {
					std::cout << tmp_hash << " + " << m_hashList[j] << "C" << std::endl;
					
				}
			}
		}

		if(!isFound) m_filesToUpload.push_back(m_filesList[i]);
	}

	std::cout << m_filesToUpload.size() << std::endl;

	return m_filesToUpload.size();
}

/*!
 * \brief return the path of the given elt
 */
std::string FileManager::getPath(int index) {
	return m_filesToUpload[index];
}

/*!
 * \brief Copy char from a string into a char array
 */
void FileManager::stringCopy(char * array, std::string data) {
	unsigned int j;
	for(j = 0; j < data.size(); ++j) {
		array[j] = data[j];
	}
	array[j] = '\0';
}

/*!
 * \brief return the len of the file
 */
int FileManager::getFileLen(std::string path) {
    FILE * file;
    int size;

    file = fopen(path.c_str(), "rb");
 
    if(file)
    {
        fseek (file, 0, SEEK_END);
        size = ftell (file);
        fclose (file);          
    } else {
    	std::cerr << "Unable to open the file" << std::endl;
    }

    return size;
}