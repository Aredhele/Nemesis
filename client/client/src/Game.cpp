//
// Created by Jehan on 05/03/2016.
//

#include "Game.hpp"
Game::Game(bool debug, ManagerGroup * ptr_managerGroup):
        BasicInterface(debug, ptr_managerGroup)

{
    //Background
    setBackground(ptr_managerGroup->ptr_textureManager->getTexture("background_Landscape"));

    //MDJ
    ptr_mdjInGame = ptr_managerGroup->ptr_textureManager->getTexture("mdjInGame");
    ptr_mdjInGame->setSmooth(true);
    m_panelMdjInGame.create("mdjInGame",430,50,ptr_mdjInGame);
    getContentPane()->addComponent(&m_panelMdjInGame);

    //Table
    ptr_tableInGame = ptr_managerGroup->ptr_textureManager->getTexture("tableInGame");
    ptr_tableInGame->setSmooth(true);
    m_panelTableInGame.create("tableInGame",190,170,ptr_tableInGame);
    getContentPane()->addComponent(&m_panelTableInGame);

	//Remington
    ptr_remingtonInGame = ptr_managerGroup->ptr_textureManager->getTexture("remingtonInGame");
    ptr_remingtonInGame->setSmooth(true);
    m_panelRemingtonInGame.create("remingtonInGame",700,170,ptr_remingtonInGame);
    getContentPane()->addComponent(&m_panelRemingtonInGame);

	//Eldora
    ptr_eldoraInGame = ptr_managerGroup->ptr_textureManager->getTexture("eldoraInGame");
    ptr_eldoraInGame->setSmooth(true);
    m_panelEldoraInGame.create("eldoraInGame",710,270,ptr_eldoraInGame);
    getContentPane()->addComponent(&m_panelEldoraInGame);

    //Numero 8
    ptr_numero8InGame = ptr_managerGroup->ptr_textureManager->getTexture("numero8InGame");
    ptr_numero8InGame->setSmooth(true);
    m_panelNumero8InGame.create("numero8InGame",250,170,ptr_numero8InGame);
    getContentPane()->addComponent(&m_panelNumero8InGame);

    //Tristan
    ptr_tristanInGame = ptr_managerGroup->ptr_textureManager->getTexture("tristanInGame");
    ptr_tristanInGame->setSmooth(true);
    m_panelTristanInGame.create("tristanInGame",250,280,ptr_tristanInGame);
    getContentPane()->addComponent(&m_panelTristanInGame);

    //Panel interface
    m_bibouPanel.create("bibouPanel", 0, 485,
                        ptr_managerGroup->ptr_textureManager->getTexture("bibouPanel"));
    getContentPane()->addComponent(&m_bibouPanel);

    //Crapaud
    /*ptr_crapaud = ptr_managerGroup->ptr_textureManager->getTexture("Crapaud");
    ptr_crapaud->setSmooth(true);
    m_panelCrapaud.create("Crapaud",300,300,ptr_crapaud);
    getContentPane()->addComponent(&m_panelCrapaud);
    */

    //Yeti
    /*ptr_yeti = ptr_managerGroup->ptr_textureManager->getTexture("Dragon");
    ptr_yeti->setSmooth(true);
    m_panelYeti.create("Dragon",450,175,ptr_yeti);
    getContentPane()->addComponent(&m_panelYeti);*/

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

