
#include "clientConnector/WarmUp.hpp"


//TODO Creer le WarmUp, en thread
WarmUp::WarmUp(int i, ConsoleDisplayer * displayer, std::vector < bool > * socketOccupe,
             std::vector < Game * > * listePartie) :
        thread(&WarmUp::threadWarmUp, this)
{
    this->displayer = displayer;
    this->etatWarmUp = Etat::Disponible;
    this->numeroWarmUp = i;
    this->nomHote = "Aucun";
    estEnMarche = false;
    this->listePartie = listePartie;

    for(int i = 0; i < 4; i++) {
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

    for(int i = 0; i < 4; i++)
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
        for(int i = 0; i < 4; i++) {

            if(tabPlayer[i]->isHere()) {

                socketStatus = tabPlayer[i]->getSocket()->receive(
                        octetsRecus, 1024, nbOctetsRecus);
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
                        gererRequete(octetsRecus, nbOctetsRecus, tabPlayer[i]->getSocket(),
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
void WarmUp::gererRequete(char requete[1024], std::size_t recu,
                         sf::TcpSocket * socket, int numeroPlayer) {


    (void)recu;
    // Exemple de trame réseau :
    // Action Paramètre(s)
    // 1 rejoindre un WarmUp - numéro du WarmUp
    // 2 créer un WarmUp - aucun
    char actionID_C[4];
    char actionParam_C[1020];

    // Parcourt de la chaîne
    if(sscanf(requete, "%s | %s", actionID_C, actionParam_C) != 2) {
        displayer->displayMessage("sa " + cast::toString(numeroWarmUp)+
                           "warn", "Erreur de lecture du paquet");
        displayer->displayMessage("sa " + cast::toString(numeroWarmUp)+
                           "fail", "sscanf n'a pas lu les bons arguments");
        return;
    }


    displayer->displayMessage("sa " + cast::toString(numeroWarmUp) +
                       "info", "ActionID = " + std::string(actionID_C) +
                               ", ARG = " + std::string(actionParam_C));

    // Conversion de l'actionID en entier
    int actionID = cast::toInt(actionID_C);


    std::size_t donneeEnvoyee;


    switch(actionID)
    {

        case 1: // Lancer la partie
            //launchGame();

            displayer->displayMessage("sa " + cast::toString(numeroWarmUp) +
                               " >> ", "Réponse à la requête n°" + cast::toString(actionID_C));
            displayer->displayMessage("sa " + cast::toString(numeroWarmUp) +
                               "info", "La partie va commencer, la WarmUp va être libéré");
            break;
        //TODO Case pour donner son nom, perso etc...
        default:
            break;
    }

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

    // TODO exception !
    // TODO retourner qqch si le WarmUp est plein
    // (normalement impossible !)
    for(int i = 0; i < 4; i++) {
        if(!tabPlayer[i]->isHere()) {
            tabPlayer[i]->init(socket, nom, indiceSocket, i);

            if(i == 3) {
                std::string type = "sa " + cast::toString(numeroWarmUp);
                this->displayer->displayMessage("warn", "Le WarmUp est complet !");
                etatWarmUp = Etat::Indisponible;
            }

            if(i == 0) {
                this->displayer->displayMessage("info", std::string("Le Player [") +
                                                 nom + "] est devenu l'hôte du WarmUp n°" +
                        cast::toString(numeroWarmUp));

                nomHote = nom;
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

    // On initialise la partie
    // On regarde si les parties sont disponibles
    for(unsigned int i = 0; i < listePartie->size(); i++) {
        if(listePartie->at(i)->estPartieDisponible()) {

            // On réinitialise la partie
            listePartie->at(i)->init();

            // On insère les Players dans la partie
            for(int j = 0; j < 4; j++) {

                // On vérifie si le Player est présent
                if(tabPlayer[j]->isHere()) {

                    // On l'ajoute à la partie
                    listePartie->at(i)->ajouterPlayer();
                    listePartie->at(i)->obtenirPlayer(j)->init(
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
            listePartie->at(i)->demarrerPartie();

            // On quitte la fonction
            return;
        }
    }

    // Aucunes parties disponibles, on crée une nouvelle partie
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
