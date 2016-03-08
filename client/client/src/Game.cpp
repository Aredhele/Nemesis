//
// Created by Jehan on 05/03/2016.
//

#include "Game.hpp"
Game::Game(bool debug, ManagerGroup * ptr_managerGroup):
        BasicInterface(debug, ptr_managerGroup)

{

	//Remington
    ptr_remingtonInGame = ptr_managerGroup->ptr_textureManager->getTexture("remingtonInGame");
    ptr_remingtonInGame->setSmooth(true);
    m_panelRemingtonInGame.create("remingtonInGame",765,170,ptr_remingtonInGame);
    getContentPane()->addComponent(&m_panelRemingtonInGame);

	//Eldora
    ptr_eldoraInGame = ptr_managerGroup->ptr_textureManager->getTexture("eldoraInGame");
    ptr_eldoraInGame->setSmooth(true);
    m_panelEldoraInGame.create("eldoraInGame",780,292,ptr_eldoraInGame);
    getContentPane()->addComponent(&m_panelEldoraInGame);

    //Numero 8
    ptr_numero8InGame = ptr_managerGroup->ptr_textureManager->getTexture("numero8InGame");
    ptr_numero8InGame->setSmooth(true);
    m_panelNumero8InGame.create("numero8InGame",100,170,ptr_numero8InGame);
    getContentPane()->addComponent(&m_panelNumero8InGame);

    //MDJ
    ptr_mdjInGame = ptr_managerGroup->ptr_textureManager->getTexture("mdjInGame");
    ptr_mdjInGame->setSmooth(true);
    m_panelMdjInGame.create("mdjInGame",430,50,ptr_mdjInGame);
    getContentPane()->addComponent(&m_panelMdjInGame);

    //Tristan
    ptr_tristanInGame = ptr_managerGroup->ptr_textureManager->getTexture("tristanInGame");
    ptr_tristanInGame->setSmooth(true);
    m_panelTristanInGame.create("tristanInGame",95,312,ptr_tristanInGame);
    getContentPane()->addComponent(&m_panelTristanInGame);

    //Table
    ptr_tableInGame = ptr_managerGroup->ptr_textureManager->getTexture("tableInGame");
    ptr_tableInGame->setSmooth(true);
    m_panelTableInGame.create("tableInGame",190,170,ptr_tableInGame);
    getContentPane()->addComponent(&m_panelTableInGame);
}

/*!
 * \brief Constructor
 */
Game::~Game() {
    // TODO
}

/*!
 * \brief Update current object
 * \param window The pointer on the window
 * \param frameTime The elpased time
 */
void Game::update(sf::RenderWindow * window,
                   sf::Event * e, double frameTime) {

    if(!m_ptr_managerGroup->ptr_targetManager->isGame()) //TODO
        return;

    // Basic Interface updating
    basicInput(e, frameTime);

    // Drawing all content
    basicDraw(window);

}

