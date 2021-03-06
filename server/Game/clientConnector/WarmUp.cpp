#include <SFML/Network/Packet.hpp>
#include "clientConnector/WarmUp.hpp"

WarmUp::WarmUp(int i, std::vector < bool > * socketOccupe,
             std::vector < Game * > listePartie, std::string nomHote) :
        thread(&WarmUp::threadWarmUp, this)
{
    etatWarmUp = Etat::Disponible;
    numeroWarmUp = i;
    nomHote = nomHote;
    estEnMarche = false;
    listePartie = listePartie;
    nbJoueur = 0;
    askForPlay=0;
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

    std::cout << "Reponse a la requete n " + stringActionId << std::endl;
    switch(actionID)
    {

        case 4: // Lancer la partie
            askForPlay++;
            std::cout << "Demande pour jouer : " << askForPlay << std::endl;
            if(askForPlay==5){
                launchGame();
                std::cout << "La partie va commencer, le WarmUp va etre libere" << std::endl;
            }
            break;

        case 5: //Lock un perso
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

        case 6: //Update tous les locks déjà passés quand on arrive
            std::cout << "On envoi les locks deja realises" << std::endl;
            sendModifLockCaracIni(numeroPlayer);
            break;

        default:
            std::cout << "MDR LE CLIENT EST UN BOUFFON (ID-Niveau WarmUp : "<< actionID <<")" << std::endl;
            break;
    }
}

void WarmUp::sendModifLockCaracIni(int numeroPlayer) {
    for(int i = 0; i < 5; i++) {
        if (tabPlayer[i]->isHere() && tabPlayer[i]->getNameChar() != "Nan") {
            sf::Packet packet;
            sf::Int32 idRequest = 6;
            std::string nomChar = tabPlayer[i]->getNameChar();
            std::string nomPlayer = tabPlayer[i]->getNamePlayer();

            //Renvoie 6-NomPerso-NomJoueur
            packet << idRequest << nomChar << nomPlayer;
            tabPlayer[numeroPlayer]->getSocket()->send(packet);
        }
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
            idRequest = 6;

            //Renvoie 6-NomPerso-NomJoueur
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

void WarmUp::launchGame() {

    listePartie.push_back(new Game(m_socketOccupe, nomHote));

    unsigned int index = listePartie.size() - 1;
    std::cout << "INDEX : " << index << std::endl;

    // On insère les Players dans la partie
    for(int j = 0; j < 5; j++) {
        sf::Int32 id = 4;
        std::string rep = "Ok";

        sf::Packet packet;
        packet << id << rep;

        // On vérifie si le Player est présent
        if(tabPlayer[j]->isHere()) {
            tabPlayer[j]->getSocket()->send(packet);
            // On l'ajoute à la partie
            listePartie.at(index)->addPlayer(tabPlayer[j]->getSocket(),
                                             tabPlayer[j]->getNamePlayer(),
                                             tabPlayer[j]->getIndiceSocket());
        }
    }


   // On lance le thread
   listePartie.at(index)->launchThreadGame();

    // On doit maintenant détruire le WarmUp
    // On le rend disponible
    init();

}



WarmUp::~WarmUp() {

}
