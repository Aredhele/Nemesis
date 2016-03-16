#include "clientConnector/ClientServer.hpp"

/*!
 * \brief Contructor
 */

ClientServer::ClientServer() {
    m_running = false;
    m_serverPort = 6002;

    initialiser();
}

/*!
 * \brief Destructor
 */
ClientServer::~ClientServer() {

}


/*!
 * \brief Start the server
 */
void ClientServer::initialiser() {

    std::cout <<"info " << "Initialisation des variables ..." << std::endl;

    //Premier socket pour empecher la fermeture du serveur
    listeSocket.push_back(std::unique_ptr < sf::TcpSocket > (new sf::TcpSocket));
    listeVerifSocket.push_back(false);
    listeVerifSocketHelper.push_back(false);
    listeSocketOccupee.push_back(false);
    indiceClient = 0;

    // Socket non bloquante
    //listeSocket[indiceClient].get()->setBlocking(false);


}

int ClientServer::start() {
    m_running = true;

    if(socketTCP.listen(m_serverPort) != sf::Socket::Done) {
        std::cout <<"/!\\Fail " << "Unable to start server"<< std::endl;
        return -1;
    }

    std::cout <<"Info " << "Server started on port : "  << m_serverPort << std::endl;
    std::cout <<"Info " << "Server is listening TCP connection !" << std::endl;


    // Time management
    sf::Clock clock;

    // client connexion
    sf::Socket::Status socketStatus;

    //Socket non bloquante
    socketTCP.setBlocking(false);

    std::cout << std::endl;
    std::cout <<"Info " << "En attente de la connection d'un joueur... " << std::endl;

    while(m_running) {
// On accepte les clients
        // TODO gérer le cas où le nombre maximum de clients est atteint
        if(socketTCP.accept(
                *listeSocket[indiceClient].get()) == sf::Socket::Done) {
            listeVerifSocket[indiceClient] = true;
            listeVerifSocketHelper[indiceClient] = true;


            // On affiche les traces
            std::cout <<" << " << "Client connecte sur la socket n " <<
                cast::toString(indiceClient) << ", adresse : " <<
                listeSocket[indiceClient].get()->getRemoteAddress().toString() <<
                "::" << cast::toString(listeSocket[indiceClient].get()->getRemotePort())
                << std::endl;
        }

        // On regarde si des données sont arrivées
        // On gère aussi les sockets dans le std::vector
        for(unsigned int i = 0; i < listeSocket.size(); i++) {

            sf::Packet packet;
            if(!listeSocketOccupee[i]) {
                socketStatus = listeSocket[i].get()->receive(packet);
                sf::Int32 idRequest;
                std::string sRequest;
                packet >>idRequest >> sRequest;

                switch(socketStatus)
                {
                    case sf::Socket::NotReady:
                        // Aucune données à recevoir
                        break;

                    case sf::Socket::Done:
                        // Gestion de la requête
                        requestManager(idRequest, sRequest, listeSocket[i].get(), i);
                        break;

                    case sf::Socket::Error:
                        listeVerifSocket[i] = false;
                        break;

                    case sf::Socket::Disconnected:
                        listeVerifSocket[i] = false;
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

    return 0;
}
/**
 * \brief Gère la liste des sockets pour éviter de fragmenter le vector
 */
void ClientServer::listSocketManager() {

    bool ajouterSocket = true;

    for(unsigned int i = 0; i < listeVerifSocket.size(); i++) {
        if(!listeVerifSocket[i]) {
            indiceClient = i;

            // Il y a eu un changement d'état
            if(listeVerifSocket[i] != listeVerifSocketHelper[i]) {
                listeVerifSocketHelper[i] = listeVerifSocket[i];
                std::cout <<"info " << std::string("Socket n ") +
                                                 cast::toString(i) + " liberee" << std::endl;
            }
        }

        // Construction du booléen final
        ajouterSocket = listeVerifSocket[i];
    }

    if(!ajouterSocket) return;

    listeSocket.push_back(std::unique_ptr < sf::TcpSocket > (new sf::TcpSocket));
    listeSocketOccupee.push_back(false);
    listeVerifSocket.push_back(false);
    listeVerifSocketHelper.push_back(false);

    indiceClient = listeSocket.size() - 1;
    listeSocket[indiceClient].get()->setBlocking(false);
    std::cout <<"info " << std::string("Socket n ") +
         cast::toString(indiceClient) +
             " ajoutee a la liste des sockets, en attente d'une nouvelle connection"<< std::endl;
}

/**
 * \brief Décide de la méthode à appeler en fonction de la requête
 * \param requete le tableau d'octets contenant le requête
 */
void ClientServer::requestManager( sf::Int32 idRequest, std::string sRequest,
                                   sf::TcpSocket * socket, int indiceSocket) {


    // Exemple de trame réseau :
    // Action Paramètre(s)
    // 1 créer un salon - aucun
    // 2 rejoindre un salon - numéro du salon
    // 3 Recupérer la liste des salons


    int actionID;

    actionID = idRequest;

    std::cout <<" >> " << "Reponse a la requete n " << actionID <<
          " de " + socket->getRemoteAddress().toString() << std::endl;
    sf::Int32 id;
    std::string rep;
    std::string listeSalonClient;
    sf::Packet packet;

    //Traitement de la requete
    switch(actionID)
    {
        case 1: // Le client veut créer un salon
            listeWarmUp.push_back(new WarmUp(listeWarmUp.size()+1,
                         &listeSocketOccupee, &listeGame, sRequest));
            break;

        case 2: // Le client veut rejoindre un salon
            id = 2;
            rep = "False";

            //socket->setBlocking(true);

            if(!joinWarmUp(socket, sRequest, indiceSocket)){
                packet << id << rep;
                socket->send(packet);
                std::cout << "/!\\warn Impossible de rejoindre le warmUp" << std::endl;
                //socket->setBlocking(false);
            }
            else{
                std::cout << "Autorise a rejoindre le warmUp" << std::endl;
                //socket->setBlocking(false);
            }

            break;
            //TODO Envoyer au moins une partie de la BDD à ce moment (Persos mini)

        case 3: // Le client veut récupérer la liste des salons
            // Obtention de la liste des salons et de l'id de la requete
            id = 3;
            listeSalonClient = getWarmUpList();

            socket->setBlocking(true);
            packet << id << listeSalonClient;
            socket->send(packet);
            socket->setBlocking(false);

            // Trace d'éxécution
            std::cout << "Recupere la liste des WarmUps" << std::endl;
            break;
        default:
            std::cout << "MDR LE CLIENT EST UN BOUFFON" << std::endl;
            break;
    }
}
/**
 * \brief Retourne la liste de tout les salons dans un std::string
 * \return
 */
std::string ClientServer::getWarmUpList() {

    std::string listeSalonTmp = "";
    for(unsigned int i = 0; i < listeWarmUp.size(); i++) {

        // Vérification de l'état du salon
        if(listeWarmUp[i]->getStateWarmUp() == WarmUp::Disponible) {
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
bool ClientServer::joinWarmUp(sf::TcpSocket * socket, std::string param,
                             int indiceSocket) {

    char idSalon_C[2] = {0};
    char nomJoueur_C[1018] = {0};

    // Parcourt de la chaîne
    std::cout <<"info parcours de la chaine :  " + param << std::endl;
    if(sscanf(param.c_str(), "%[^&]&%s", idSalon_C, nomJoueur_C) != 2) {
        std::cout <<"/!\\warn " << "Erreur de lecture des arguments" << std::endl;
        std::cout <<"/!\\fail " << "sscanf n'a pas lu les bons arguments" << std::endl;
        return false;
    }

    //if(listeWarmUp[cast::toInt(idSalon_C)]->getStateWarmUp()== WarmUp::Indisponible) return false;

    std::cout <<"info " << "ARG_1 = " + std::string(idSalon_C) +
                                     ", ARG_2 = " + std::string(nomJoueur_C) << std::endl;




    listeWarmUp[cast::toInt(idSalon_C +1)]->addPlayer(socket, nomJoueur_C,
                                                                 (unsigned int) indiceSocket);
    std::cout <<"info "<< "Le joueur [" + std::string(nomJoueur_C) +
                                                  "] a rejoint le salon n " + std::string(idSalon_C) << std::endl;

    listeSocketOccupee[indiceSocket] = true;
    
    return true;
}