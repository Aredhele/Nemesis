#include <SFML/Network/Packet.hpp>
#include "clientConnector/WarmUp.hpp"

WarmUp::WarmUp(int i, ConsoleDisplayer * displayer, std::vector < bool > * socketOccupe,
             std::vector < Game * > * listePartie, std::string nomHote) :
        thread(&WarmUp::threadWarmUp, this)
{
    this->displayer = displayer;
    this->etatWarmUp = Etat::Disponible;
    this->numeroWarmUp = i;
    this->nomHote = nomHote;
    estEnMarche = false;
    this->listePartie = listePartie;

    for(i = 0; i < 5; i++) {
        tabPlayer[i] = new Player();
    }

    this->socketOccupe = socketOccupe;
}

/**
 * \brief initialise le WarmUp
 */
void WarmUp::init() {
    nomHote = "aucun";
    etatWarmUp = WarmUp::Disponible;
    estEnMarche = false;

    for(int i = 0; i < 5; i++)
        tabPlayer[i]->init();
}

/**
 * \brief // TODO
 * \param
 * \return
 */
void WarmUp::threadWarmUp() {

    sf::Socket::Status socketStatus;
    char octetsRecus[1024];
    std::size_t nbOctetsRecus;

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
                        displayer->displayMessage("th " + cast::toString(numeroWarmUp), " << "+
                                 std::string(octetsRecus) + " - Player n°" +
                                                          cast::toString(i) +
                                  " [" + tabPlayer[i]->getNamePlayer() + "]");


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

    displayer->displayMessage("sa " + cast::toString(numeroWarmUp) +
                       "info", "ActionID = " + stringActionId +
                               ", ARG = " + std::string(sRequest));
    sf::Packet packet;


    switch(actionID)
    {

        case 1: // Lancer la partie
            //launchGame();

            displayer->displayMessage("sa " + cast::toString(numeroWarmUp) +
                               " >> ", "Reponse a la requete n " + stringActionId);
            displayer->displayMessage("sa " + cast::toString(numeroWarmUp) +
                               "info", "La partie va commencer, le WarmUp va etre libere");
            break;

        case 2: //Lock un perso
            displayer->displayMessage("sa " + cast::toString(numeroWarmUp) +
                                      " >> ", "Reponse a la requete n " + stringActionId);
            if(lockCarac(sRequest, numeroPlayer)){
                displayer->displayMessage("info", "Requete de lock acceptee pour "+sRequest+
                        ", envoi de la requete");
                packet << actionID << "Ok";
                socket->send(packet);
                sendModifLockCarac(sRequest, numeroPlayer);
            }
            else{
                displayer->displayMessage("warn", "Le joueur n'a pas reussi a lock : " + sRequest);
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
    displayer->displayMessage("sa " + cast::toString(numeroWarmUp) +
                              " >> ", "Envoi du changement du WarmUp : perso lock ");
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

    std::string type = "sa " + cast::toString(numeroWarmUp);
    thread.launch();

    this->displayer->displayMessage(type, "Le thread n°" +
            cast::toString(numeroWarmUp) + " a démarré");
}

/**
 * \brief Ajouter un Player au WarmUp
 */
int WarmUp::addPlayer(sf::TcpSocket * socket,
                         std::string nom, unsigned int indiceSocket) {

    // TODO retourner qqch si le WarmUp est plein (Fait ? (bug ?))
    // (normalement impossible !)
    this->displayer->displayMessage("warn", "Le joueur est ajoute au thread !");
    for(int i = 0; i < 5; i++) {
        if(!tabPlayer[i]->isHere()) {
            tabPlayer[i]->init(socket, nom, indiceSocket, i);

            sf::Int32 id = 2;
            std::string rep = "Ok";

            sf::Packet packet;
            packet << id << rep;
            socket->send(packet);

            if(i == 4) {
                std::string type = "sa " + cast::toString(numeroWarmUp);
                this->displayer->displayMessage("warn", "Le WarmUp est complet !");
                etatWarmUp = Etat::Indisponible;
            }

            if(i == 0) {
                this->displayer->displayMessage("info", std::string("Le Player [") +
                                                 nom + "] est devenu l'hote du WarmUp n " +
                        cast::toString(numeroWarmUp));

                nomHote = nom;
                launchThreadWarmUp();
            }
            return i;
        }
    }
    return -1;
}

/**
 * \brief Retire un Player du WarmUp
 */
void WarmUp::delPlayer(int i) {

    socketOccupe->at(tabPlayer[i]->getIndiceSocket()) = false;
    tabPlayer[i]->disconnect();
    etatWarmUp = Etat::Disponible;
}

/**
 * \brief Retourne l'état du WarmUp
 * \return m_estDisponible Vraie si le WarmUp est vide
 */
WarmUp::Etat WarmUp::getStateWarmUp() {
    return this->etatWarmUp;
}

/**
 * \brief Retourne le numero du WarmUp de 0 à x
 * \return this->numeroWarmUp Le numero du WarmUp
 */
int WarmUp::getNbWarmUp() {
    return this->numeroWarmUp;
}


/**
 * \brief Retourne le nom de l'hôte courant, sinon "aucun"
 * \return this->nomHote le nom de l'hôte
 */
std::string WarmUp::getMDJName() {
    return this->nomHote;
}

/**
 * \brief Fixe le nom de l'hôte
 * \param hote Le nom de l'hôte
 */
void WarmUp::setMDJName(std::string hote) {
    this->nomHote = hote;
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
