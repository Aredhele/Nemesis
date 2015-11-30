/*!
 * \file HashTool.cpp
 * \brief Hash a file
 * \author Aredhele
 * \version 0.1
 * \date 2015-11-29
 */


#include "tools/HashTool.hpp"

/*!
 * \brief Constructor.
 */
HashTool::HashTool() {
	// None
}

/*!
 * \brief Destructor.
 */
HashTool::~HashTool() {
	// None
}

/*!
 * \brief Hash a file and store
 * \brief result in m_out;
 */
int HashTool::SHA256() {
	
	FILE *f, *tmp;
	unsigned char buf[8192];
	unsigned char *out;
	SHA_CTX sc;
	int err;

	f = fopen(m_pathToFile.c_str(), "rb");

	if(f == NULL) {
		std::cerr << "Unable to open the file !" << std::endl;
		return -1;
	}

	SHA1_Init(&sc);
	for(;;) {
		size_t len;

		len = fread(buf, 1, sizeof buf, f);
        if (len == 0)
            break;
        SHA1_Update(&sc, buf, len); 
	}

	err = ferror(f);
	fclose(f);

	if (err) {
	    std::cerr << "An I/O error was encountered !" << std::endl;
	    return -1;
	}

	SHA1_Final(out, &sc);
	m_hash = "";

	tmp = fopen("hash", "w");

	for(int i = 0; i < 20; i++) {
		fprintf(tmp, "%x", out[i]);
	}

	fclose(tmp);

	std::string line;
	std::ifstream file("hash");

	while (getline(file, line)) {
	  	m_hash += line;
	}

	file.close();

    return 0;
}

/*!
 * \brief return the hash of the last file
 * \return m_hash
 */
std::string HashTool::getHash() {
	if(SHA256() < 0) {
		std::cerr << "Error while hashing files ..." << std::endl;
		return "NULL";
	}

	return m_hash;
}

/*!
 *
 */
void HashTool::setPathToFile(std::string pathToFile) {
	m_pathToFile = pathToFile;
}