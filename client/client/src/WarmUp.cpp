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
        m_numero8LockLabel(),
        m_eldoraLockLabel(),
        m_remingtonLockLabel(),
        m_tristanLockLabel(),
        m_mdjLockLabel(),
        m_playButton(),
        m_returnButton(),
        m_characterLockPanel1(),
        m_characterLockPanel2(),
        m_characterLockPanel3(),
        m_characterLockPanel4(),
        m_numero8Lock(),
        m_eldoraLock(),
        m_tristanLock(),
        m_remingtonLock(),
        m_mdjLock(),
        m_loading()
{

    m_nbPlayer = 0;
    m_nbCharLocked = 0;
    m_charSelected = false;
    m_firstConnect = true;
    m_characterSelected = "";
    noError();
    int leftBorder = 15;


    if (!m_fontLabel.loadFromFile("../res/font/Roboto-Regular.ttf") ||
        !m_fontLabel2.loadFromFile("../res/font/ATypewriterForMe.ttf"))
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

    m_infoCharacterLabel.create("infoCharacterLabel", 120, 320, 20, &m_fontLabel2,
                                  L"", sf::Color::Black);

    m_characterLockPanel1.create("characterLock1", 100, 505,
                                 ptr_managerGroup->ptr_textureManager->getTexture("characterLock"));
    m_characterLockPanel2.create("characterLock2", 100, 575,
                                 ptr_managerGroup->ptr_textureManager->getTexture("characterLock"));
    m_characterLockPanel3.create("characterLock3", 450, 505,
                                 ptr_managerGroup->ptr_textureManager->getTexture("characterLock"));
    m_characterLockPanel4.create("characterLock4", 450, 575,
                                 ptr_managerGroup->ptr_textureManager->getTexture("characterLock"));

    m_numero8Lock.create("numero8Lock", 102, 507,
                         ptr_managerGroup->ptr_textureManager->getTexture("numero8Lock"));
    m_eldoraLock.create("eldoraLock", 452, 577,
                         ptr_managerGroup->ptr_textureManager->getTexture("eldoraLock"));
    m_tristanLock.create("tristanLock", 102, 577,
                         ptr_managerGroup->ptr_textureManager->getTexture("tristanLock"));
    m_remingtonLock.create("remingtonLock", 452, 507,
                         ptr_managerGroup->ptr_textureManager->getTexture("remingtonLock"));
    m_mdjLock.create("mdjLock", 452, 507,
                         ptr_managerGroup->ptr_textureManager->getTexture("mdjLock"));

    m_numero8LockLabel.create("numero8LockLabel", 175, 520, 15, &m_fontLabel,
                              L"Player 1", sf::Color(196,130,56));
    m_eldoraLockLabel.create("eldoraLockLabel", 175, 590, 15, &m_fontLabel,
                              L"Player 2", sf::Color(196,130,56));
    m_tristanLockLabel.create("tristanLockLabel", 525, 520, 15, &m_fontLabel,
                              L"Player 3", sf::Color(196,130,56));
    m_remingtonLockLabel.create("remingtonLockLabel", 525, 590, 15, &m_fontLabel,
                              L"", sf::Color(196,130,56));
    m_mdjLockLabel.create("mdjLockLabel", 525, 590, 15, &m_fontLabel,
                              L"Player 4", sf::Color(196,130,56));



    m_characterLockPanel1.setVisible(false);
    m_characterLockPanel2.setVisible(false);
    m_characterLockPanel3.setVisible(false);
    m_characterLockPanel4.setVisible(false);

    m_numero8Lock.setVisible(false);
    m_eldoraLock.setVisible(false);
    m_tristanLock.setVisible(false);
    m_remingtonLock.setVisible(false);
    m_mdjLock.setVisible(false);

    m_numero8LockLabel.setVisible(false);
    m_eldoraLockLabel.setVisible(false);
    m_tristanLockLabel.setVisible(false);
    m_remingtonLockLabel.setVisible(false);
    m_mdjLockLabel.setVisible(false);

    m_loading.create("loading", 964,708,
    				 ptr_managerGroup->ptr_textureManager->getTexture("loading"),
    			 true, 0.1, 49,  49, 8);

    m_loading.setVisible(false);
    getContentPane()->addComponent(&m_loading);



    m_validateCharacterButton.setVisible(false);
    m_playButton.setVisible(false);
    m_infoCharacterPanel.setVisible(false);
    m_selectCharacterPanel.setVisible(false);
    m_infoCharacterPanel.addComponent(&m_infoCharacterLabel);

    getContentPane()->addComponent(&m_numero8LockLabel);
    getContentPane()->addComponent(&m_eldoraLockLabel);
    getContentPane()->addComponent(&m_tristanLockLabel);
    getContentPane()->addComponent(&m_remingtonLockLabel);
    getContentPane()->addComponent(&m_mdjLockLabel);

    getContentPane()->addComponent(& m_numero8Lock);
    getContentPane()->addComponent(& m_eldoraLock);
    getContentPane()->addComponent(& m_tristanLock);
    getContentPane()->addComponent(& m_remingtonLock);
    getContentPane()->addComponent(& m_mdjLock);

    getContentPane()->addComponent(&m_characterLockPanel1);
    getContentPane()->addComponent(&m_characterLockPanel2);
    getContentPane()->addComponent(&m_characterLockPanel3);
    getContentPane()->addComponent(&m_characterLockPanel4);
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

    if(m_firstConnect){
        //Demande un update des perso déjà locked
        if (!m_ptr_managerGroup->ptr_networkManager->request(6, "","")){
            errorConnection();
        }
        m_firstConnect=false;
    }

    // Basic Interface updating
    basicInput(e, frameTime);
    
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

        std::string str = m_ptr_managerGroup->ptr_gameManager->getPlayer()->getCharacter()->getId();
        //Envoie notre choix de perso
        if (!m_ptr_managerGroup->ptr_networkManager->request(5, str,"")){
            errorConnection();
        }

    }

    //TODO : change condition to ==5
    if (m_nbPlayer==5){
        noError();
        m_loading.setVisible(false);
        m_playButton.setVisible(true);
    }

    if(m_inputHandler.getComponentId() == "playButton") {
        if (m_charSelected){
            m_playButton.setVisible(false);
            m_infoCharacterPanel.setVisible(false);
            m_selectCharacterPanel.setVisible(false);

            //Demande l'autorisation de rentrer en jeu
            if (!m_ptr_managerGroup->ptr_networkManager->request(4, "","")){
                errorConnection();
            }
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

    std::vector <sf::Packet> packet = m_ptr_managerGroup->ptr_networkManager->getPacket();

    for(unsigned int i = 0; i < packet.size(); i++) {

        sf::Int32 idRequest;
        packet.at(i) >> idRequest;
        std::string sRequest;
        std::string sRequest2;

        std::cout << "IdRequest recu " << idRequest << std::endl;
        std::cout << "sRequest recu " << sRequest << std::endl;

        switch (idRequest) {
            case 4:
                //On peut rentrer en jeu
                packet.at(i) >> sRequest;
                if (sRequest == "Ok") {
                    m_ptr_managerGroup->ptr_targetManager->isOnGame();
                }
                else {
                    errorGoInGame();
                }
                break;

            case 5:
                // Personnage sélectionné
                packet.at(i) >> sRequest;
                if (sRequest == "Ok") {
                    waitingPlayers();
                    m_loading.setVisible(true);
                    m_validateCharacterButton.setVisible(false);
                    blockCharacters();
                    m_charSelected = true;
                    std::cout << "Choix validé ! " << std::endl;

                }
                else {
                    errorCharacterSelection();
                }
                break;

            case 6:
                //Nom perso - nom joueur
                // ex : "eldora""Lucas"
                packet.at(i) >> sRequest >> sRequest2;
                m_nbPlayer++;

            std::cout << "perso locked " <<
                    m_ptr_managerGroup->ptr_gameManager->getPlayer()->getCharacter()->getId() << std::endl;
                if (sRequest!=m_ptr_managerGroup->ptr_gameManager->getPlayer()->getCharacter()->getId()) {
                    m_nbCharLocked++;
                    blockCharacter(sRequest, sRequest2);
                }
                break;
            default:
                std::cout << "WARM UP : IDRequete non conforme -> " << idRequest << std::endl;
                break;
        }
    }

}

void WarmUp::blockCharacters() {
    m_eldoraButton.setEnabled(false);
    m_numero8Button.setEnabled(false);
    m_remingtonButton.setEnabled(false);
    m_tristanButton.setEnabled(false);
    m_mdjButton.setEnabled(false);
}

void WarmUp::blockCharacter(std::string characterName, std::string playerName) {
    std::wstring wplayerName = s2ws(playerName);

    if (characterName=="eldora") {
        std::cout << "perso locked " << characterName << std::endl;
        m_eldoraButton.setEnabled(false);
        switch (m_nbCharLocked){
            case 1 :
                m_characterLockPanel1.setVisible(true);
                m_eldoraLock.setPosition(102, 507);
                m_eldoraLockLabel.setPosition(175, 520); //175,520
                std::cout << "position changed" << std::endl;
                break;
            case 2 :
                m_characterLockPanel2.setVisible(true);
                m_eldoraLock.setPosition(102, 577);
                m_eldoraLockLabel.setPosition(175, 590);
                break;
            case 3:
                m_characterLockPanel3.setVisible(true);
                m_eldoraLock.setPosition(452, 507);
                m_eldoraLockLabel.setPosition(525, 520);
                break;
            case 4:
                m_characterLockPanel4.setVisible(true);
                m_eldoraLock.setPosition(452, 577);
                m_eldoraLockLabel.setPosition(525, 590);
                break;
            default:
                std::cout << "position pas adaptée " << std::endl;
                break;
        }
        //adaptPosition(&m_eldoraLock, &m_eldoraLockLabel);
        m_eldoraLockLabel.setText(wplayerName);
        m_eldoraLockLabel.setVisible(true);
        m_eldoraLock.setVisible(true);

    }

    if (characterName=="remington"){
        std::cout << "perso locked " << characterName << std::endl;
        m_remingtonButton.setEnabled(false);
        switch (m_nbCharLocked){
            case 1 :
                m_characterLockPanel1.setVisible(true);
                m_remingtonLock.setPosition(102, 507);
                m_remingtonLockLabel.setPosition(175, 520); //175,520
                std::cout << "position changed" << std::endl;
                break;
            case 2 :
                m_characterLockPanel2.setVisible(true);
                m_remingtonLock.setPosition(102, 577);
                m_remingtonLockLabel.setPosition(175, 590);
                break;
            case 3:
                m_characterLockPanel3.setVisible(true);
                m_remingtonLock.setPosition(452, 507);
                m_remingtonLockLabel.setPosition(525, 520);
                break;
            case 4:
                m_characterLockPanel4.setVisible(true);
                m_remingtonLock.setPosition(452, 577);
                m_remingtonLockLabel.setPosition(525, 590);
                break;
            default:
                std::cout << "position pas adaptée " << std::endl;
                break;
        }
        //adaptPosition(&m_remingtonLock, &m_remingtonLockLabel);
        m_remingtonLockLabel.setText(wplayerName);
        m_remingtonLockLabel.setVisible(true);
        m_remingtonLock.setVisible(true);
    }

    if (characterName=="mdj"){
        std::cout << "perso locked " << characterName << std::endl;
        m_mdjButton.setEnabled(false);
        switch (m_nbCharLocked){
            case 1 :
                m_characterLockPanel1.setVisible(true);
                m_mdjLock.setPosition(102, 507);
                m_mdjLockLabel.setPosition(175, 520); //175,520
                std::cout << "position changed" << std::endl;
                break;
            case 2 :
                m_characterLockPanel2.setVisible(true);
                m_mdjLock.setPosition(102, 577);
                m_mdjLockLabel.setPosition(175, 590);
                break;
            case 3:
                m_characterLockPanel3.setVisible(true);
                m_mdjLock.setPosition(452, 507);
                m_mdjLockLabel.setPosition(525, 520);
                break;
            case 4:
                m_characterLockPanel4.setVisible(true);
                m_mdjLock.setPosition(452, 577);
                m_mdjLockLabel.setPosition(525, 590);
                break;
            default:
                std::cout << "position pas adaptée " << std::endl;
                break;
        }
        //adaptPosition(&m_mdjLock, &m_mdjLockLabel);
        m_mdjLockLabel.setText(wplayerName);
        m_mdjLockLabel.setVisible(true);
        m_mdjLock.setVisible(true);
    }

    if (characterName=="tristan"){
        std::cout << "perso locked " << characterName << std::endl;
        m_tristanButton.setEnabled(false);
        switch (m_nbCharLocked){
            case 1 :
                m_characterLockPanel1.setVisible(true);
                m_tristanLock.setPosition(102, 507);
                m_tristanLockLabel.setPosition(175, 520); //175,520
                std::cout << "position changed" << std::endl;
                break;
            case 2 :
                m_characterLockPanel2.setVisible(true);
                m_tristanLock.setPosition(102, 577);
                m_tristanLockLabel.setPosition(175, 590);
                break;
            case 3:
                m_characterLockPanel3.setVisible(true);
                m_tristanLock.setPosition(452, 507);
                m_tristanLockLabel.setPosition(525, 520);
                break;
            case 4:
                m_characterLockPanel4.setVisible(true);
                m_tristanLock.setPosition(452, 577);
                m_tristanLockLabel.setPosition(525, 590);
                break;
            default:
                std::cout << "position pas adaptée " << std::endl;
                break;
        }
        //adaptPosition(&m_tristanLock, &m_tristanLockLabel);
        m_tristanLockLabel.setText(wplayerName);
        m_tristanLockLabel.setVisible(true);
        m_tristanLock.setVisible(true);
    }

    if (characterName=="numero8"){
        std::cout << "perso locked " << characterName << std::endl;
        m_numero8Button.setEnabled(false);
        switch (m_nbCharLocked){
            case 1 :
                m_characterLockPanel1.setVisible(true);
                m_numero8Lock.setPosition(102, 507);
                m_numero8LockLabel.setPosition(175, 520); //175,520
                std::cout << "position changed" << std::endl;
                break;
            case 2 :
                m_characterLockPanel2.setVisible(true);
                m_numero8Lock.setPosition(102, 577);
                m_numero8LockLabel.setPosition(175, 590);
                break;
            case 3:
                m_characterLockPanel3.setVisible(true);
                m_numero8Lock.setPosition(452, 507);
                m_numero8LockLabel.setPosition(525, 520);
                break;
            case 4:
                m_characterLockPanel4.setVisible(true);
                m_numero8Lock.setPosition(452, 577);
                m_numero8LockLabel.setPosition(525, 590);
                break;
            default:
                std::cout << "position pas adaptée " << std::endl;
                break;
        }
        //adaptPosition(&m_numero8Lock, &m_numero8LockLabel);
        m_numero8LockLabel.setText(wplayerName);
        m_numero8LockLabel.setVisible(true);
        m_numero8Lock.setVisible(true);
    }


}

void WarmUp::adaptPosition(NPanel *panel, NLabel *label) {
    std::cout << "nb char locked " << m_nbCharLocked << std::endl;
    switch (m_nbCharLocked){
        case 1 :
            m_characterLockPanel1.setVisible(true);
            panel->setPosition(102, 507);
            label->setPosition(175, 520); //175,520
            break;
        case 2 :
            m_characterLockPanel2.setVisible(true);
            panel->setPosition(102, 577);
            label->setPosition(175, 590);
            break;
        case 3:
            m_characterLockPanel3.setVisible(true);
            panel->setPosition(452, 507);
            label->setPosition(525, 520);
            break;
        case 4:
            m_characterLockPanel4.setVisible(true);
            panel->setPosition(452, 577);
            label->setPosition(525, 590);
            break;
        default:break;
    }
}

std::wstring WarmUp::s2ws(std::string s) {
    std::wstring temp(s.length(),L' ');
    std::copy(s.begin(), s.end(), temp.begin());
    return temp;
}