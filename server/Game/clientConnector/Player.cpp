//
// Created by Jehan on 03/02/2016.
//

#include "clientConnector/Player.hpp"

Player::Player() {

    isPlayerHere = false;
    socketPlayer = nullptr;
    namePlayer = "Joueur fantome";
    indiceSocket = 0;
    numberPlayer = 0;
}

/**
 * \brief Destructeur
 * \param
 * \return
 */
Player::~Player() {
    // None
}
/**
 * \brief // TODO
 * \param
 * \return
 */
void Player::init() {
    isPlayerHere = false;
    socketPlayer = nullptr;
    namePlayer = "Joueur fantome";
    indiceSocket = 0;
    numberPlayer = 0;
}

/**
 * \brief // TODO
 * \param
 * \return
 */
void Player::init(sf::TcpSocket * socket, std::string nom,
                  unsigned int indiceSocket, int numPlayer) {
    isPlayerHere = true;
    socketPlayer = socket;
    namePlayer = nom;
    this->indiceSocket = indiceSocket;
    numberPlayer = numPlayer;
}

/**
 * \brief // TODO
 * \param
 * \return
 */
void Player::disconnect() {
    isPlayerHere = false;
    delete socketPlayer;
    namePlayer = "NaN";
    numberPlayer = -1;
    indiceSocket = 0;
}

/**
 * \return estPresent vrai si l'objet est initialisé
 */
bool Player::isHere() {
    return isPlayerHere;
}

/**
 * \brief // TODO
 * \param
 * \return
 */
unsigned int Player::getIndiceSocket() {
    return indiceSocket;
}

/**
 * \brief // TODO
 * \param
 * \return
 */
int Player::getNumeroPlayer() {
    return numberPlayer;
}

/**
 * \brief // TODO
 * \param
 * \return
 */
std::string Player::getNamePlayer() {
    return namePlayer;
}

/**
 * \brief
 * \param
 * \return
 */
sf::TcpSocket * Player::getSocket() {
    return socketPlayer;
}
