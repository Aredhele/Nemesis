#include <SFML/Network/Packet.hpp>
#include "clientConnector/WarmUp.hpp"

WarmUp::WarmUp(int i, std::vector < bool > * socketOccupe,
             std::vector < Game * > * listePartie, std::string nomHote) :
        thread(&WarmUp::threadWarmUp, this)
{
    etatWarmUp = Etat::Disponible;
    numeroWarmUp = i;
    nomHote = nomHote;
    estEnMarche = false;
    listePartie = listePartie;
    nbJoueur = 0;

    for(i = 0; i < 5; i++) {
        tabPlayer[i] = new Player();
    }

    m_socketOccupe = socketOccupe;
}

/**
 * \brief initialise le WarmUp
 */
void WarmUp::init() {
    nomHote = "aucun";
    etatWarmUp = WarmUp::Disponible;
    estEnMarche = false;
}

/**
 * \brief // TODO
 * \param
 * \return
 */
void WarmUp::threadWarmUp() {

    sf::Socket::Status socketStatus;
    char octetsRecus[1024];

    // Variables pour la gestion du temps
    sf::Clock horloge;

    estEnMarche = true;
    // Boucle principale du WarmUp
    while(estEnMarche)
    {
        // TODO faire toutes les vérifications
        for(int i = 0; i < 5; i++) {

            if(tabPlayer[i]->isHere()) {
                sf::Packet packet;
                socketStatus = tabPlayer[i]->getSocket()->receive(
                        packet);
                sf::Int32 idRequest;
                std::string sRequest;
                packet >>idRequest >> sRequest;

                switch(socketStatus)
                {
                    case sf::Socket::NotReady:
                        // Aucune données à recevoir
                        break;

                    case sf::Socket::Done:
                        std::cout << "th " + cast::toString(numeroWarmUp) << " << "+
                                 std::string(octetsRecus) + " - Player n " +
                                                          cast::toString(i) +
                                  " [" + tabPlayer[i]->getNamePlayer() + "]" << std::endl;


                        // Gestion de la requête
                        gererRequete(idRequest, sRequest, tabPlayer[i]->getSocket(),
                                     tabPlayer[i]->getNumeroPlayer());
                        break;

                    case sf::Socket::Error:
                        delPlayer(i);
                        break;

                    case sf::Socket::Disconnected:
                        delPlayer(i);
                        break;

                    default:
                        break;
                }
            }
        }

        // 240 Hz
        if(horloge.getElapsedTime().asMilliseconds() < 4.17) {
            sf::sleep(sf::milliseconds((sf::Int32) (4.17 - horloge.getElapsedTime().asMilliseconds())));
        }

        // RAZ horloge
        horloge.restart();
    }
}
void WarmUp::gererRequete(sf::Int32 idRequest, std::string sRequest,
                         sf::TcpSocket * socket, int numeroPlayer) {

    // Conversion de l'actionID en entier
    int actionID = cast::toInt(idRequest);

    std::string stringActionId = SSTR( actionID );
    puts( SSTR( actionID ).c_str() );

    std::cout << cast::toString(numeroWarmUp) +
                       "info" << "ActionID = " + stringActionId +
                               ", ARG = " + std::string(sRequest) << std::endl;
    sf::Packet packet;


    switch(actionID)
    {

        case 1: // Lancer la partie
            //launchGame();

            std::cout << "Reponse a la requete n " + stringActionId << std::endl;
            std::cout << "La partie va commencer, le WarmUp va etre libere" << std::endl;
            break;

        case 2: //Lock un perso
            std::cout <<  "Reponse a la requete n " + stringActionId << std::endl;
            if(lockCarac(sRequest, numeroPlayer)){

                std::cout << "Requete de lock acceptee pour "+sRequest+
                        ", envoi de la requete" << std::endl;
                packet << actionID << "Ok";
                socket->send(packet);
                sendModifLockCarac(sRequest, numeroPlayer);
            }
            else{
                std::cout << "Le joueur n'a pas reussi a lock : " + sRequest << std::endl;
                packet << actionID << "False";
                socket->send(packet);
            }


            break;

        default:
            break;
    }

}

//Send to a thread listening
void WarmUp::sendModifLockCarac(std::string sRequest, int numeroPlayer){
    std::cout << "Envoi du changement du WarmUp : perso lock " << std::endl;
    for(int i = 0; i < 5; i++) {
        if (tabPlayer[i]->isHere()) {
            sf::Packet packet;
            sf::Int32 idRequest;
            std::string nomPlayer = tabPlayer[numeroPlayer]->getNamePlayer();
            idRequest = 3;

            //Renvoie 3-NomPerso-NomJoueur
            packet << idRequest << sRequest << nomPlayer;
            tabPlayer[i]->getSocket()->send(packet);
        }
    }
}

bool WarmUp::lockCarac(std::string sRequest, int nbPLayer ) {
    for(int i =0; i < 5; i++ ){
        if(tabPlayer[i]->getNameChar() == sRequest){
            return false;
        }
    }
    tabPlayer[nbPLayer]->setNameChar(sRequest);
    return true;
}

/**
 * \brief // TODO
 * \param
 * \return
 */
void WarmUp::launchThreadWarmUp() {
    thread.launch();

    std::cout <<  "Le thread n " +
            cast::toString(numeroWarmUp) + " a demarre" << std::endl;
}

/**
 * \brief Ajouter un Player au WarmUp
 */
int WarmUp::addPlayer(sf::TcpSocket * socket,
                         std::string nom, unsigned int indiceSocket) {

    // TODO retourner qqch si le WarmUp est plein (Fait ? (bug ?))
    // (normalement impossible !)
    std::cout << "Le joueur est ajoute au thread !" << std::endl;
    for(int i = 0; i < 5; i++) {
        if(!tabPlayer[i]->isHere()) {
            tabPlayer[i]->init(socket, nom, indiceSocket, i);

            sf::Int32 id = 2;
            std::string rep = "Ok";

            sf::Packet packet;
            packet << id << rep;
            socket->send(packet);

            if(i == 4) {
                std::cout << "Le WarmUp est complet !" << std::endl;
                etatWarmUp = Etat::Indisponible;
            }

            if(i == 0) {
                std::cout << std::string("Le Player [") +
                                                 nom + "] est devenu l'hote du WarmUp n " +
                        cast::toString(numeroWarmUp) << std::endl;

                nomHote = nom;
                launchThreadWarmUp();
            }
            nbJoueur = nbJoueur +1;
            return i;
        }
    }
    return -1;
}

/**
 * \brief Retire un Player du WarmUp
 */
void WarmUp::delPlayer(int i) {
    nbJoueur = nbJoueur -1;
    m_socketOccupe->at(tabPlayer[i]->getIndiceSocket()) = NULL;
    tabPlayer[i]->disconnect();
    etatWarmUp = Etat::Disponible;
    if(nbJoueur == 0) {
        etatWarmUp = Etat::Indisponible;
    }
}

/**
 * \brief Retourne l'état du WarmUp
 * \return m_estDisponible Vraie si le WarmUp est vide
 */
WarmUp::Etat WarmUp::getStateWarmUp() {
    return etatWarmUp;
}

/**
 * \brief Retourne le numero du WarmUp de 0 à x
 * \return numeroWarmUp Le numero du WarmUp
 */
int WarmUp::getNbWarmUp() {
    return numeroWarmUp;
}


/**
 * \brief Retourne le nom de l'hôte courant, sinon "aucun"
 * \return nomHote le nom de l'hôte
 */
std::string WarmUp::getMDJName() {
    return nomHote;
}

/**
 * \brief Fixe le nom de l'hôte
 * \param hote Le nom de l'hôte
 */
void WarmUp::setMDJName(std::string hote) {
    nomHote = hote;
}


/**
 * \brief
 * \param
 * \return
 */
/*
void WarmUp::launchGame() {

    // TODO - Faire les vérifications de début de partie
    // TODO - Creer toutes les méthodes dans Game


    //TODO Créer la partie

    //listePartie->push_back(new Game(socketOccupe, displayer));

    unsigned int index = listePartie->size() - 1;

    // On insère les Players dans la partie
    for(int j = 0; j < 4; j++) {

        // On vérifie si le Player est présent
        if(tabPlayer[j]->isHere()) {

            // On l'ajoute à la partie
            listePartie->at(index)->ajouterPlayer();
            listePartie->at(index)->obtenirPlayer(j)->init(
                    tabPlayer[j]->getSocket(),
                    tabPlayer[j]->getNamePlayer(),
                    tabPlayer[j]->getIndiceSocket(),
                    tabPlayer[j]->getNumeroPlayer()
            );
        }
    }
    // On doit maintenant détruire le WarmUp
    // On le rend disponible
    init();

    // On lance le thread
    listePartie->at(index)->demarrerPartie();
}*/
WarmUp::~WarmUp() {

}
