/*!
 * \file ClientThread.hpp
 * \brief Function object for client thread
 * \author Aredhele
 * \version 0.1
 * \date 2015-11-26
 */
 
#include "ClientThread.hpp"
#include <fstream> // TMP
/*!
 * \brief Constructor.
 * \param clientSocket The socket of the client
 */
ClientThread::ClientThread(sf::TcpSocket * clientSocket) :
m_thread(&ClientThread::client, this) {

	m_ptr_clientTime = nullptr;
	m_ptr_clientClock = nullptr;

	m_ptr_clientSocket = clientSocket;
	m_ptr_displayer = new ConsoleDisplayer();
	m_ptr_fileManager = new FileManager();
	m_ptr_hashTool = new HashTool();
}	

/*!
 * \brief Destructor.
 */
ClientThread::~ClientThread() {

	delete m_ptr_displayer;
	delete m_ptr_clientTime;
	delete m_ptr_clientClock;
	delete m_ptr_clientSocket;
	delete m_ptr_fileManager;

	m_ptr_displayer = nullptr;
	m_ptr_clientTime = nullptr;
	m_ptr_clientClock = nullptr;
	m_ptr_clientSocket = nullptr;
	m_ptr_fileManager = nullptr;
}

/*!
 * \brief Start the thread
 */
void ClientThread::start() {
	m_thread.launch();
}

/*!
 * \brief Stop the thread
 */
void ClientThread::stop() {
	m_thread.terminate();
}

/*!
 * \brief The client thread
 */
void ClientThread::client() {

	int nbLines;
	int nbFiles;

	std::size_t received;

	// Getting line number
	m_ptr_clientSocket->receive((void *)&nbLines, 4, received);

	std::cout << "Lines number : " << nbLines << std::endl;

	// Opening save
	FILE * f = fopen("result.txt", "w");
	int rep = 0;

	for(int i = 0; i < nbLines; ++i) {

		char lines[200];
		char hash[200];

		while(m_ptr_clientSocket->receive(lines, 200, received) == sf::Socket::Disconnected) {
			std::cerr << "Paquet re-wait" << std::endl;
			return;
		}

		while(m_ptr_clientSocket->receive(hash, 40, received) == sf::Socket::Disconnected) {
			std::cerr << "Paquet re-wait" << std::endl;
			return;
		}

		hash[40] = '\0';

		m_ptr_fileManager->addClientFileToList(lines);
		m_ptr_fileManager->addClientHashToList(hash);
	}

	// Closing descriptors
	fclose(f);

	// Une fois la boucle fini, on synchronise le client avec le serveur
	// Acknowlegde
	m_ptr_clientSocket->send((void*)&rep, 4);
	
	// Getting number of files to send
	nbFiles = m_ptr_fileManager->compare();
	m_ptr_clientSocket->send((void *)&nbFiles, 4, received);

	std::cout << "Files number to send : " << nbFiles << " files." << std::endl;
	if(nbFiles == 0) return;

	// Send loop
	for(int i = 0; i < nbFiles; i++) {

		char buffer[1024];
		char pathToFile[200];
		sf::sleep(sf::milliseconds(10));
		std::string tempPath = m_ptr_fileManager->getPath(i);
		m_ptr_fileManager->stringCopy(pathToFile, tempPath);

		std::cout << "\nServer sending : " << pathToFile << std::endl;

		m_ptr_clientSocket->send(pathToFile, 200);

		std::ifstream is("..\\res\\client\\" + tempPath, std::ifstream::binary);
		//std::ifstream f;
		//f.open("..\\res\\client\\" + tempPath, std::ifstream::binary | fstream::in); 

		std::cout << "File to send : " << "..\\res\\client\\" << tempPath << std::endl;

		if((is.rdstate() & std::ifstream::failbit) != 0) {
  			std::cerr << "Unable to open input stream !" << std::endl;
  			return;
  		}

  		int fileLen = m_ptr_fileManager->getFileLen("..\\res\\client\\" + tempPath);
  		// envoie taille
  		m_ptr_clientSocket->send((void *)&fileLen, 4);

  		std::cout << "File size : " << fileLen << " bytes." << std::endl;

  		bool check = false;
  		int nbEssai = 0;
  		int a = 0;

  		while(!check) 
  		{
  			
  			while(!is.eof()) 
  			{
		    	is.read(buffer, 1024);
		    	int byteRead = is.gcount();
		    	// m_ptr_clientSocket->send((void *)&byteRead, 4);

		    	if(byteRead > 0) {
		    		m_ptr_clientSocket->send(buffer, is.gcount());
		    	} else {
		    		m_ptr_clientSocket->send(buffer, is.gcount());
		    		break;
		    	}
		    	std::cout << "Paquet [" << a << "] -> Bytes send : " << is.gcount() << std::endl;
		    	a++;
	    	}
	    	int sortie;
	    	m_ptr_clientSocket->receive((void *)&sortie, 4, received);
 
    		// envoi du hash
    		char hashFile[200];
    		std::cout << "Envoie du hash" << std::endl;
    		m_ptr_hashTool->setPathToFile("..\\res\\client\\" + tempPath);
    		m_ptr_fileManager->stringCopy(hashFile, m_ptr_hashTool->getHash());
    		std::cout << "Hash to send : " << hashFile << std::endl;
    		m_ptr_clientSocket->send(hashFile, 200);

    		// Attente de la réponse
    		std::cout << "Confirmation : ";
    		int reponse = 1;
    		m_ptr_clientSocket->receive((void *)&reponse, 4, received);
    		if (reponse == 0) {
    			std::cout << "OK !" << std::endl;
    			check = true;
    		} 
    		else {
    			std::cout << "FAIL !" << std::endl;
    			nbEssai++;
    			check = false;
    			if(nbEssai == 3) check = true;
    		}
  		}

  		if(nbEssai == 3) {
			std::cout << "FAIL TO SEND FILES !!" << std::endl;
  			break;
  		}

  		is.close();
    	std::cout << "Server >> File sended\n" << std::endl;
	}

	m_ptr_displayer->displayMessage("Warn", "Client disconnected");
}