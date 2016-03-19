#include <SFML/Network/Packet.hpp>
#include "clientConnector/Game.hpp"

Game::Game(std::vector < bool > * socketOccupe,
                std::string nomHote) :
        thread(&Game::threadGame, this)
{
    this->etatGame = Etat::Disponible;
    this->nomHote = nomHote;
    estEnMarche = false;

    for(int i = 0; i < 5; i++) {
        tabPlayer[i] = new Player();
    }

    this->socketOccupe = socketOccupe;
}

/**
 * \brief initialise le Game
 */
void Game::init() {
    nomHote = "aucun";
    etatGame = Game::Disponible;
    estEnMarche = false;

    for(int i = 0; i < 5; i++)
        tabPlayer[i]->init();
}

/**
 * \brief // TODO
 * \param
 * \return
 */
void Game::threadGame() {

    sf::Socket::Status socketStatus;
    char octetsRecus[1024];
    std::size_t nbOctetsRecus;

    // Variables pour la gestion du temps
    sf::Clock horloge;

    estEnMarche = true;
    // Boucle principale du Game
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
                std::string sRequest2;
                //packet >>idRequest >> sRequest >> sRequest2;

                switch(socketStatus)
                {
                    case sf::Socket::NotReady:
                        // Aucune données à recevoir
                        break;

                    case sf::Socket::Done:
                        std::cout << "Reception d'une requete du player " << i <<
                                "[" << tabPlayer[i]->getNamePlayer() << std::endl;
                        broadcastRequest(packet);
                        /*
                        std::cout <<"game" <<  std::string(octetsRecus) + " - Player n " << i <<
                                " [" + tabPlayer[i]->getNamePlayer() + "]" << std::endl;


                        // Gestion de la requête
                        gererRequete(idRequest, sRequest, sRequest2, tabPlayer[i]->getSocket(),
                                     tabPlayer[i]->getNumeroPlayer());
                        */
                        break;

                    case sf::Socket::Error:
                        //delPlayer(i);
                        break;

                    case sf::Socket::Disconnected:
                        //delPlayer(i);
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

void Game::broadcastRequest(sf::Packet packet){
    for (int i = 0; i < 5; i++){
        tabPlayer[i]->getSocket()->send(packet);
    }
}
/*
void Game::gererRequete(sf::Int32 idRequest, std::string sRequest,std::string sRequest2,
                          sf::TcpSocket * socket, int numeroPlayer) {

    // Conversion de l'actionID en entier
    int actionID = cast::toInt(idRequest);

    std::string stringActionId = SSTR( actionID );
    puts( SSTR( actionID ).c_str() );

    std::cout <<"game info" << "ActionID = " + stringActionId +
                                      ", ARG = " + std::string(sRequest) << std::endl;
    sf::Packet packet;


    switch(actionID)
    {

        case 1:

            break;

        case 2:

            break;

        default:
            break;
    }

}*/

/**
 * \brief // TODO
 * \param
 * \return
 */
void Game::launchThreadGame() {

    thread.launch();

    std::cout <<"game" << "Le thread a demarre" << std::endl;
}

/**
 * \brief Ajouter un Player au Game
 */
int Game::addPlayer(sf::TcpSocket * socket,
                      std::string nom, unsigned int indiceSocket) {

    // TODO exception !
    // TODO retourner qqch si le Game est plein
    // (normalement impossible !)
    for(int i = 0; i < 5; i++) {
        if(!tabPlayer[i]->isHere()) {
            tabPlayer[i]->init(socket, nom, indiceSocket, i);

            sf::Int32 id = 2;
            std::string rep = "Ok";

            sf::Packet packet;
            packet << id << rep;
            socket->send(packet);

            return i;
        }
    }
    return -1;
}

/**
 * \brief Retire un Player du Game
 */
void Game::delPlayer(int i) {

    socketOccupe->at(tabPlayer[i]->getIndiceSocket()) = false;
    tabPlayer[i]->disconnect();
    etatGame = Etat::Disponible;
}



Game::~Game() {

}
