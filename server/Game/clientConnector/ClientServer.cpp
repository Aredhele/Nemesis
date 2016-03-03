#include "clientConnector/ClientServer.hpp"

/*!
 * \brief Contructor
 */
ClientServer::ClientServer(ConsoleDisplayer * displayer) {
    m_running = false;
    m_multiIp = _DFLT_SMIP_;
    m_serverPort = _DFLT_SPORT_;
    m_serverAddress = _DFLT_SADDR_;
    m_serverMaxConnection = _DFLT_SMCO_;

    m_masterPort = _DFLT_MPORT_;
    m_masterCheck = _DFLT_MCHECK_;
    m_masterAddress = _DFLT_MADDR_;

    m_ptr_displayer = displayer;
}

/*!
 * \brief Contructor
 * \param serverPort the port of the server
 * \param serverAddress the address of the server
 */
ClientServer::ClientServer(ConsoleDisplayer * displayer, Configuration * config) {
    m_running = false;
    m_serverAddress = config->getParam(_SERVER_IP_);
    m_multiIp = cast::toBool(config->getParam(_SERVER_MIP_));
    m_serverPort = cast::toInt(config->getParam(_SERVER_PORT_));
    m_serverMaxConnection = cast::toInt(config->getParam(_SERVER_MCO_));

    m_masterAddress = config->getParam(_MSERV_IP_);
    m_masterPort = cast::toInt(config->getParam(_MSERV_PORT_));
    m_masterCheck = cast::toBool(config->getParam(_MSERV_CHECK_));

    m_ptr_configuration = config;
    m_ptr_displayer = displayer;
    initialiser();
}

/*!
 * \brief Destructor
 */
ClientServer::~ClientServer() {
    delete m_ptr_displayer;

    m_ptr_displayer = nullptr;
}



/*!
 * \brief Start the server
 */
void ClientServer::initialiser() {

    this->m_ptr_displayer->displayMessage("info", "Initialisation des variables ...");

    //Threads Launch
    for(unsigned int i = 0; i < listeWarmUp.size(); i++) {
        listeWarmUp[i]->launchThreadWarmUp();
    }
    this->m_ptr_displayer->displayMessage("info", cast::toString(this->listeWarmUp.size()) +
                                     " warmUp(s) ont étées créées !");


    this->listeSocket.push_back(std::unique_ptr < sf::TcpSocket > (new sf::TcpSocket));
    this->listeVerifSocket.push_back(false);
    this->listeVerifSocketHelper.push_back(false);
    this->listeSocketOccupee.push_back(false);
    this->indiceClient = 0;

    // Socket non bloquante
    this->listeSocket[this->indiceClient].get()->setBlocking(false);

    this->m_ptr_displayer->displayMessage("info", "1 socket client créée !");


    /*
    m_socketList.push_back(std::unique_ptr < sf::TcpSocket > (new sf::TcpSocket));

    if(m_ptr_listener->accept(
            *m_socketList[m_socketList.size() - 1].get()) == sf::Socket::Done) {

        m_ptr_displayer->displaySimple("Info", "Client connected with ip ");
        std::cout << m_socketList[m_socketList.size() - 1].get()->getRemoteAddress();
        std::cout << " on port ";
        std::cout << m_socketList[m_socketList.size() - 1].get()->getRemotePort();
        std::cout << std::endl;

        m_threadList.push_back(std::unique_ptr < ClientThread >
                                       (new ClientThread(m_socketList[m_socketList.size() - 1].get())));

        m_ptr_displayer->displayMessage("Info", "Client thread created");
        m_threadList[m_threadList.size() - 1].get()->start();
        m_ptr_displayer->displayMessage("Info", "Client thread started");

    } else {
        m_ptr_displayer->displayMessage("Fail", "Unable to accept client !");
        return -1;
    }*/

}

int ClientServer::start() {
    m_running = true;

    if(this->socketTCP.listen(m_serverPort) != sf::Socket::Done) {
        m_ptr_displayer->displayMessage("Fail", "Unable to start server");
        return -1;
    }

    m_ptr_displayer->displaySimple("Info", "Server started on port : ");
    std::cout << m_serverPort << std::endl;
    m_ptr_displayer->displayMessage("Info", "Server is listening TCP connection !");
    m_ptr_displayer->displaySimple("Warn", "Server multi-ip (Disable by default) : ");
    if(m_multiIp) std::cout << "TRUE" << std::endl;
    else std::cout << "FALSE" << std::endl;

    m_ptr_displayer->displaySimple("Warn", "Server master check (Enable by default) : ");
    if(m_masterCheck) std::cout << "TRUE" << std::endl;
    else std::cout << "FALSE" << std::endl;

    // Time management
    sf::Clock clock;

    // client connexion
    sf::Socket::Status socketStatus;
    char octetsRecus[SERVER_PACKET_SIZE];
    std::size_t nbOctetsRecus;

    //Socket non bloquante
    this->socketTCP.setBlocking(false);

    std::cout << std::endl;
    m_ptr_displayer->displaySimple("Info", "En attente de la connection d'un joueur... ");

    while(m_running) {
// On accepte les clients
        // TODO gérer le cas où le nombre maximum de clients est atteint
        if(this->socketTCP.accept(
                *this->listeSocket[this->indiceClient].get()) == sf::Socket::Done) {
            this->listeVerifSocket[this->indiceClient] = true;
            this->listeVerifSocketHelper[this->indiceClient] = true;


            // On affiche les traces
            this->m_ptr_displayer->displayMessage(" << ", "Client connecté sur la socket n°" +
                                             cast::toString(this->indiceClient) + " - " +
                                             this->listeSocket[this->indiceClient].get()->getRemoteAddress().toString() +
                                             " - " + cast::toString(this->listeSocket[this->indiceClient].get()->getRemotePort()));
        }

        // On regarde si des données sont arrivées
        // On gère aussi les sockets dans le std::vector
        for(unsigned int i = 0; i < this->listeSocket.size(); i++) {

            sf::Packet packet;
            if(!listeSocketOccupee[i]) {
                socketStatus = this->listeSocket[i].get()->receive(packet);
                sf::Int32 idRequest;
                std::string sRequest;
                packet >>idRequest >> sRequest;

                switch(socketStatus)
                {
                    case sf::Socket::NotReady:
                        // Aucune données à recevoir
                        break;

                    case sf::Socket::Done:
                        this->m_ptr_displayer->displayMessage(" << ", std::string(octetsRecus) +
                                                         " - " + this->listeSocket[i].get()->getRemoteAddress().toString());

                        // Gestion de la requête
                        requestManager(idRequest, sRequest, this->listeSocket[i].get(), i);
                        break;

                    case sf::Socket::Error:
                        this->listeVerifSocket[i] = false;
                        break;

                    case sf::Socket::Disconnected:
                        this->listeVerifSocket[i] = false;
                        break;

                    default:
                        break;
                }
            }
        }

        // On gère le prochain indice d'insertion de la socket
        listSocketManager();

        // 240 Hz
        if(clock.getElapsedTime().asMilliseconds() < 4.17) {
            sf::sleep(sf::milliseconds((sf::Int32) (4.17 - clock.getElapsedTime().asMilliseconds())));
        }

        // RAZ horloge
        clock.restart();
    }

    return SUCCESS;
}
/**
 * \brief Gère la liste des sockets pour éviter de fragmenter le vector
 */
void ClientServer::listSocketManager() {

    bool ajouterSocket = true;

    for(unsigned int i = 0; i < this->listeVerifSocket.size(); i++) {
        if(!this->listeVerifSocket[i]) {
            this->indiceClient = i;

            // Il y a eu un changement d'état
            if(this->listeVerifSocket[i] != this->listeVerifSocketHelper[i]) {
                this->listeVerifSocketHelper[i] = this->listeVerifSocket[i];
                this->m_ptr_displayer->displayMessage("info", std::string("Socket n°") +
                                                 cast::toString(i) + " libérée");
            }
        }

        // Construction du booléen final
        ajouterSocket = ajouterSocket && this->listeVerifSocket[i];
    }

    if(!ajouterSocket) return;

    listeSocket.push_back(std::unique_ptr < sf::TcpSocket > (new sf::TcpSocket));
    listeSocketOccupee.push_back(false);
    listeVerifSocket.push_back(false);
    this->listeVerifSocketHelper.push_back(false);

    indiceClient = this->listeSocket.size() - 1;
    listeSocket[this->indiceClient].get()->setBlocking(false);
    m_ptr_displayer->displayMessage("info", std::string("Socket n°") +
                               cast::toString(this->indiceClient) + " ajoutée à la liste");
}

/**
 * \brief Décide de la méthode à appeler en fonction de la requête
 * \param requete le tableau d'octets contenant le requête
 */
void ClientServer::requestManager( sf::Int32 idRequest, std::string sRequest,  sf::TcpSocket * socket, int indiceSocket) {

    std::string s;
    std::string ss;

    std::cout << "ID REQUETE : " << idRequest << std::endl;

    // Exemple de trame réseau :
    // Action Paramètre(s)
    // 1 créer un salon - aucun
    // 2 rejoindre un salon - numéro du salon
    // 3 Recupérer la liste des salons


    int actionID;

    actionID = idRequest;


    std::cout << "ID REQUETE : " << actionID << std::endl;


    sf::Packet packet;

    //Traitement de la requete
    switch(actionID)
    {
        case 1: // Le client veut créer un salon
            this->listeWarmUp.push_back(new WarmUp(listeWarmUp.size()+1, m_ptr_displayer,
                                                   &listeSocketOccupee, &listeGame, sRequest));
            break;

        case 2: // Le client veut rejoindre un salon
            joinWarmUp(socket, sRequest, indiceSocket);

            s =  "Réponse à la requête n°" + actionID;
            ss = "- " + socket->getRemoteAddress().toString();
            this->m_ptr_displayer->displayMessage(" >> ", "" + s+ss);

            break;
            //TODO Envoyer au moins une partie de la BDD à ce moment (Persos mini)

        case 3: // Le client veut récupérer la liste des salons
        {
            std::cout << "CASE 3  " << std::endl;
            // Obtention de la liste des salons et de l'id de la requete
            sf::Int32 id = 3;
            std::string listeSalonClient = getWarmUpList();


            socket->setBlocking(true);

            packet << id << listeSalonClient;

            socket->send(packet);

            socket->setBlocking(false);

            // Trace d'éxécution
            s = "Réponse à la requête n°" + actionID;
            ss = " - " + socket->getRemoteAddress().toString();
            this->m_ptr_displayer->displayMessage(" >> ", "" + s + ss);

            break;
        }
        default:
            break;
    }


}
/**
 * \brief Retourne la liste de tout les salons dans un std::string
 * \return
 */
std::string ClientServer::getWarmUpList() {

    std::string listeSalonTmp = "";
    for(unsigned int i = 0; i < this->listeWarmUp.size(); i++) {

        // Vérification de l'état du salon
        if(this->listeWarmUp[i]->getStateWarmUp() == WarmUp::Disponible) {
            listeSalonTmp += cast::toString(listeWarmUp[i]->getNbWarmUp())
                             + "&" + listeWarmUp[i]->getMDJName() + ";" ;
        }
    }

    return listeSalonTmp;
}


/**
 * \brief Ajoute un joueur au salon
 * \param socket Un pointeur sur la socket du client
 * \param
 * \return TODO
 */
void ClientServer::joinWarmUp(sf::TcpSocket * socket, std::string param,
                             int indiceSocket) {

    char idSalon_C[2] = {0};
    char nomJoueur_C[1018] = {0};

    // Parcourt de la chaîne
    if(sscanf(param.c_str(), "%[^&]&%s", idSalon_C, nomJoueur_C) != 2) {
        this->m_ptr_displayer->displayMessage("warn", "Erreur de lecture des arguments");
        this->m_ptr_displayer->displayMessage("fail", "sscanf n'a pas lu les bons arguments");
        return;
    }

    if(cast::toInt(idSalon_C) > 9 || cast::toInt(idSalon_C) < 0) return;

    this->m_ptr_displayer->displayMessage("info", "ARG_1 = " + std::string(idSalon_C) +
                                     ", ARG_2 = " + std::string(nomJoueur_C));

    this->m_ptr_displayer->displayMessage("info", "Le joueur [" + std::string(nomJoueur_C) +
                                     "] a rejoint le salon n°" + std::string(idSalon_C));

    int nJoueur = listeWarmUp[cast::toInt(idSalon_C)]->addPlayer(socket, nomJoueur_C,
                                                                 (unsigned int) indiceSocket);

    listeSocketOccupee[indiceSocket] = true;

    // Envoie de la réponse
    std::size_t donneeEnvoyee;
    // 2 | idSalon & numeroJoueur & nomHote
    std::string reponse = "2 | " + std::string(idSalon_C) + "&" + cast::toString(nJoueur) +
                          "&" + listeWarmUp[cast::toInt(idSalon_C)]->getMDJName();
    socket->send(reponse.c_str(), 1024, donneeEnvoyee);
}
