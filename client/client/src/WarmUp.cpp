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
        m_mdjButton(),
        m_validateCharacterButton(),
        m_selectCharacterPanel(),
        m_infoCharacterPanel(),
        m_infoCharacterLabel(),
        m_playButton(),
        m_returnButton()
{

    m_charSelected = false;
    noError();
    int leftBorder = 15;

    if (!m_fontLabel.loadFromFile("../res/font/Roboto-Regular.ttf"))
    {
        std::cout << "Probleme dans le chargement des textures" << std::endl;
    }

    m_validateCharacterButton.create("validateCharButton", 888, 310,
                                     ptr_managerGroup->ptr_textureManager->getTexture("arrowButton_1"),
                                     ptr_managerGroup->ptr_textureManager->getTexture("arrowButton_2"));

    m_playButton.create("playButton", 780, 700,
                        ptr_managerGroup->ptr_textureManager->getTexture("playButton_1"),
                        ptr_managerGroup->ptr_textureManager->getTexture("playButton_2"));

    m_numero8Button.create("numero8Button", leftBorder, 70,
                           ptr_managerGroup->ptr_textureManager->getTexture("numero8InWarmUp"),
                           ptr_managerGroup->ptr_textureManager->getTexture("numero8InWarmUp"));

    leftBorder+=195;
    m_remingtonButton.create("remingtonButton", leftBorder, 70,
                             ptr_managerGroup->ptr_textureManager->getTexture("remingtonInWarmUp"),
                             ptr_managerGroup->ptr_textureManager->getTexture("remingtonInWarmUp"));

    leftBorder+=195;
    m_eldoraButton.create("eldoraButton", leftBorder, 70,
                             ptr_managerGroup->ptr_textureManager->getTexture("eldoraInWarmUp"),
                             ptr_managerGroup->ptr_textureManager->getTexture("eldoraInWarmUp"));

    leftBorder+=195;
    m_tristanButton.create("tristanButton", leftBorder, 70,
                           ptr_managerGroup->ptr_textureManager->getTexture("tristanInWarmUp"),
                           ptr_managerGroup->ptr_textureManager->getTexture("tristanInWarmUp"));

    leftBorder+=195;
    m_mdjButton.create("mdjButton", leftBorder, 70,
                       ptr_managerGroup->ptr_textureManager->getTexture("mdjInWarmUp"),
                       ptr_managerGroup->ptr_textureManager->getTexture("mdjInWarmUp"));


    m_returnButton.create("returnButton", 20, 700,
                           ptr_managerGroup->ptr_textureManager->getTexture("backButton_1"),
                           ptr_managerGroup->ptr_textureManager->getTexture("backButton_2"));


    m_selectCharacterPanel.create("selectCharacterPanel", 95,65,
                                  ptr_managerGroup->ptr_textureManager->getTexture("selectCharacterPanel"));

    m_infoCharacterPanel.create("infoCharacterPanel", 100,300,
                                  ptr_managerGroup->ptr_textureManager->getTexture("infoCharacterPanel"));

    m_infoCharacterLabel.create("infoCharacterLabel", 110, 310, 20, &m_fontLabel,
                                  L"", sf::Color::Black);

    m_validateCharacterButton.setVisible(false);
    m_playButton.setVisible(true);
    m_playButton.setEnabled(false);
    //m_playButton.setVisible(false);
    m_infoCharacterPanel.setVisible(false);
    m_selectCharacterPanel.setVisible(false);
    m_infoCharacterPanel.addComponent(&m_infoCharacterLabel);

    getContentPane()->addComponent(&m_infoCharacterPanel);
    getContentPane()->addComponent(&m_selectCharacterPanel);
    getContentPane()->addComponent(&m_numero8Button);
    getContentPane()->addComponent(&m_remingtonButton);
    getContentPane()->addComponent(&m_eldoraButton);
    getContentPane()->addComponent(&m_tristanButton);
    getContentPane()->addComponent(&m_mdjButton);
    getContentPane()->addComponent(&m_playButton);
    getContentPane()->addComponent(&m_validateCharacterButton);
    //getContentPane()->addComponent(&m_returnButton);


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

    if(m_ptr_managerGroup->ptr_networkManager->getHasPacket()){
        receiveRequest();
    }

    // Basic Interface updating
    basicInput(e, frameTime);

    //TODO : Afficher les info des personnages
    if(m_inputHandler.getComponentId() == "numero8Button") {
        if(!m_charSelected){
            //m_ptr_managerGroup->ptr_gameManager->getPlayer->setCharacter(3);
            displayInfoCharacters("numero8");
            m_selectCharacterPanel.setPosition(10, 65);
            //m_validateCharacterButton.setPosition(195,211);
            m_ptr_managerGroup->ptr_gameManager->getPlayer()->setCharacter(
                    m_ptr_managerGroup->ptr_gameManager->getCharacterById("numero8"));;
        }

    }
    if(m_inputHandler.getComponentId() == "remingtonButton") {
        if(!m_charSelected) {
            //m_ptr_managerGroup->ptr_gameManager->getPlayer->setCharacter(1);
            displayInfoCharacters("remington");
            m_selectCharacterPanel.setPosition(205, 65);
            //m_validateCharacterButton.setPosition(400, 211);
            m_ptr_managerGroup->ptr_gameManager->getPlayer()->setCharacter(
                    m_ptr_managerGroup->ptr_gameManager->getCharacterById("remington"));;
        }
    }
    if(m_inputHandler.getComponentId() == "eldoraButton") {
        if(!m_charSelected){
            //m_ptr_managerGroup->ptr_gameManager->getPlayer->setCharacter(0);
            displayInfoCharacters("eldora");
            m_selectCharacterPanel.setPosition(400, 65);
            //m_validateCharacterButton.setPosition(566,211);
            m_ptr_managerGroup->ptr_gameManager->getPlayer()->setCharacter(
                    m_ptr_managerGroup->ptr_gameManager->getCharacterById("eldora"));;
        }
    }
    if(m_inputHandler.getComponentId() == "tristanButton") {
        if(!m_charSelected) {
            //m_ptr_managerGroup->ptr_gameManager->getPlayer->setCharacter(2);
            displayInfoCharacters("tristan");
            m_selectCharacterPanel.setPosition(595, 65);
            //m_validateCharacterButton.setPosition(771, 211);
            m_ptr_managerGroup->ptr_gameManager->getPlayer()->setCharacter(
                    m_ptr_managerGroup->ptr_gameManager->getCharacterById("tristan"));;
        }
    }
    if(m_inputHandler.getComponentId() == "mdjButton") {
        if(!m_charSelected) {
            //m_ptr_managerGroup->ptr_gameManager->getPlayer->setCharacter(4);
            displayInfoCharacters("mdj");
            m_selectCharacterPanel.setPosition(790, 65);
            //m_validateCharacterButton.setPosition(976, 211);
            m_ptr_managerGroup->ptr_gameManager->getPlayer()->setCharacter(
                    m_ptr_managerGroup->ptr_gameManager->getCharacterById("mdj"));
        }
    }
    if(m_inputHandler.getComponentId() == "validateCharButton"){
        //TODO : Envoyer la requete de choix au serveur
        std::wstring wstr = m_ptr_managerGroup->ptr_gameManager->getPlayer()->getCharacter()->getName();
        //std::cout << "NOM PERSO SELECTIONNE WS : " << wstr << std::endl;

        std::string str;
        for(std::wstring::const_iterator it = wstr.begin();
            it != wstr.end();
            ++it)
        {
            str.push_back(static_cast<char>(*it));
        }

        std::cout << "NOM PERSO SELECTIONNE S : " << str << std::endl;
        if (!m_ptr_managerGroup->ptr_networkManager->request(2, str)){
            errorConnection();
        }
        //TODO : Afficher la roue de chargement

    }


    /*if(m_inputHandler.getComponentId() == "returnButton") {
        m_playButton.setVisible(false);
        m_infoCharacterPanel.setVisible(false);
        m_selectCharacterPanel.setVisible(false);
        m_ptr_managerGroup->ptr_targetManager->isOnLobby();
    }*/
    if(m_inputHandler.getComponentId() == "playButton") {
        if (m_charSelected){
            m_playButton.setVisible(false);
            m_infoCharacterPanel.setVisible(false);
            m_selectCharacterPanel.setVisible(false);
            m_ptr_managerGroup->ptr_targetManager->isOnGame();
        }
    }

    //

    // Drawing all content
    basicDraw(window);
}


void WarmUp::displayInfoCharacters(std::string characterName){


    m_selectCharacterPanel.setVisible(true);
    //m_playButton.setVisible(true);
    m_infoCharacterPanel.setVisible(true);
    m_validateCharacterButton.setVisible(true);

    m_infoCharacterLabel.setText(m_ptr_managerGroup->ptr_gameManager->getCharacterById(characterName)->getDescription());



}

void WarmUp::receiveRequest(){
    m_ptr_managerGroup->ptr_networkManager->setHasPacket(false);
    sf::Packet *packet = m_ptr_managerGroup->ptr_networkManager->getPacket();

    sf::Int32 idRequest;
    *packet >> idRequest;
    std::string sRequest;
    std::string sRequest2;

    std::cout << "IdRequest " << idRequest << std::endl;
    std::cout << "sRequest " << sRequest << std::endl;

    switch (idRequest){
        case 1:
            //On peut rentre en jeu
            *packet >> sRequest;
            if (sRequest=="Ok"){
                m_ptr_managerGroup->ptr_targetManager->isOnGame();
            }
            else{
                errorGoInGame();
            }
            break;

        case 2:
            // Personnage sélectionné
            *packet >> sRequest;
            if (sRequest=="Ok"){
                //TODO bloquer les autres personnages
                m_charSelected = true;
                //TODO rendre disponible le bouton de lancement du jeu
                m_playButton.setEnabled(true);
                //m_playButton.setVisible(true);
                std::cout << "Choix validé ! " << std::endl;

            }
            else{
                errorCharacterSelection();
            }
            break;

        case 3:
            //
            *packet >> sRequest >> sRequest2;
            //TODO : Désactiver le personnage (idRequest)
            //TODO : Afficher le nom du joueur avec l'image du personnage sélectionné

            break;
    }

}