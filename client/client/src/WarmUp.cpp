//
// Created by Lucas on 01/03/2016.
//

#include "WarmUp.hpp"

WarmUp::WarmUp(bool debug, ManagerGroup * ptr_managerGroup) :
        BasicInterface(debug, ptr_managerGroup),
        m_numero8Button(),
        m_remingtonButton(),
        m_tristanButton(),
        m_eldoraButton(),
        m_selectCharacterPanel(),
        m_infoCharacterPanel(),
        m_infoCharacterLabel(),
        m_playButton(),
        m_returnButton()
{

    noError();
    int leftBorder = 100;

    if (!m_fontLabel.loadFromFile("../res/font/Quicksand.ttf"))
    {
        std::cout << "Probleme dans le chargement des textures" << std::endl;
    }

    m_playButton.create("playButton", 780, 700,
                        ptr_managerGroup->ptr_textureManager->getTexture("playButton_1"),
                        ptr_managerGroup->ptr_textureManager->getTexture("playButton_2"));

    m_numero8Button.create("numero8Button", leftBorder, 70,
                           ptr_managerGroup->ptr_textureManager->getTexture("perso0"),
                           ptr_managerGroup->ptr_textureManager->getTexture("perso0"));

    leftBorder+=220;
    m_remingtonButton.create("remingtonButton", leftBorder, 70,
                             ptr_managerGroup->ptr_textureManager->getTexture("perso1"),
                             ptr_managerGroup->ptr_textureManager->getTexture("perso1"));

    leftBorder+=220;
    m_eldoraButton.create("eldoraButton", leftBorder, 71,
                             ptr_managerGroup->ptr_textureManager->getTexture("perso3"),
                             ptr_managerGroup->ptr_textureManager->getTexture("perso3"));

    leftBorder+=220;
    m_tristanButton.create("tristanButton", leftBorder, 70,
                             ptr_managerGroup->ptr_textureManager->getTexture("perso2"),
                             ptr_managerGroup->ptr_textureManager->getTexture("perso2"));

m_returnButton.create("returnButton", 20, 700,
                           ptr_managerGroup->ptr_textureManager->getTexture("topBarExitButton_1"),
                           ptr_managerGroup->ptr_textureManager->getTexture("topBarExitButton_2"));


    m_selectCharacterPanel.create("selectCharacterPanel", 95,65,
                                  ptr_managerGroup->ptr_textureManager->getTexture("selectCharacterPanel"));

    m_infoCharacterPanel.create("infoCharacterPanel", 100,300,
                                  ptr_managerGroup->ptr_textureManager->getTexture("infoCharacterPanel"));

    m_infoCharacterLabel.create("infoCharacterLabel", 110, 310, 20, &m_fontLabel,
                                  L"", sf::Color::Black);


    m_playButton.setVisible(false);
    m_infoCharacterPanel.setVisible(false);
    m_selectCharacterPanel.setVisible(false);
    m_infoCharacterPanel.addComponent(&m_infoCharacterLabel);
    getContentPane()->addComponent(&m_infoCharacterPanel);
    getContentPane()->addComponent(&m_selectCharacterPanel);
    getContentPane()->addComponent(&m_numero8Button);
    getContentPane()->addComponent(&m_remingtonButton);
    getContentPane()->addComponent(&m_eldoraButton);
    getContentPane()->addComponent(&m_tristanButton);
    getContentPane()->addComponent(&m_playButton);
    getContentPane()->addComponent(&m_returnButton);


    //displayCharacters();

}

WarmUp::~WarmUp(){

}

/*!
* \brief Update current object
* \param window The pointer on the window
* \param frameTime The elpased time
*/
void WarmUp::update(sf::RenderWindow * window,
                       sf::Event * e, double frameTime) {

    if(!m_ptr_managerGroup->ptr_targetManager->isWarmUp())
        return;

    // Basic Interface updating
    basicInput(e, frameTime);

    //TODO : Afficher les info des personnages
    if(m_inputHandler.getComponentId() == "numero8Button") {
        displayInfoCharacters("numero8");
        m_selectCharacterPanel.setPosition(95, 65);
        m_ptr_managerGroup->ptr_gameManager->getPlayer()->setCharacter(3);
    }
    if(m_inputHandler.getComponentId() == "remingtonButton") {
        displayInfoCharacters("remington");
        m_selectCharacterPanel.setPosition(315, 65);
        m_ptr_managerGroup->ptr_gameManager->getPlayer()->setCharacter(1);
    }
    if(m_inputHandler.getComponentId() == "eldoraButton") {
        displayInfoCharacters("eldora");
        m_selectCharacterPanel.setPosition(535, 65);
        m_ptr_managerGroup->ptr_gameManager->getPlayer()->setCharacter(0);
    }
    if(m_inputHandler.getComponentId() == "tristanButton") {
        displayInfoCharacters("tristan");
        m_selectCharacterPanel.setPosition(755, 65);
        m_ptr_managerGroup->ptr_gameManager->getPlayer()->setCharacter(2);
    }
    if(m_inputHandler.getComponentId() == "returnButton") {
        m_playButton.setVisible(false);
        m_infoCharacterPanel.setVisible(false);
        m_selectCharacterPanel.setVisible(false);
        m_ptr_managerGroup->ptr_targetManager->isOnLobby();
    }
    if(m_inputHandler.getComponentId() == "playButton") {
        m_playButton.setVisible(false);
        m_infoCharacterPanel.setVisible(false);
        m_selectCharacterPanel.setVisible(false);
        m_ptr_managerGroup->ptr_targetManager->isOnGame();
    }


    // Drawing all content
    basicDraw(window);
}


void WarmUp::displayInfoCharacters(std::string characterName){


    m_selectCharacterPanel.setVisible(true);
    m_playButton.setVisible(true);
    m_infoCharacterPanel.setVisible(true);

    if (characterName == "numero8")
        m_infoCharacterLabel.setText(L"Bonjour ! \nJe m\'appelle Numero 8 !");
    else if (characterName == "remington")
        m_infoCharacterLabel.setText(L"Bonjour ! \nJe m\'appelle Remington !");
    else if (characterName == "eldora")
        m_infoCharacterLabel.setText(L"Bonjour ! \nJe m\'appelle Eldora Dragnir !");
    else if (characterName == "tristan")
        m_infoCharacterLabel.setText(L"Bonjour ! \nJe m\'appelle Tristan De la Mortifère !");

}