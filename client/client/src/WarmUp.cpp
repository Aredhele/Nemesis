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
        m_mdjLock()
{

    m_nbPlayer = 0;
    m_nbCharLocked = 0;
    m_charSelected = false;
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
    m_characterLockPanel2.create("characterLock2", 450, 575,
                                 ptr_managerGroup->ptr_textureManager->getTexture("characterLock"));
    m_characterLockPanel3.create("characterLock3", 100, 575,
                                 ptr_managerGroup->ptr_textureManager->getTexture("characterLock"));
    m_characterLockPanel4.create("characterLock4", 450, 505,
                                 ptr_managerGroup->ptr_textureManager->getTexture("characterLock"));

    m_numero8Lock.create("numero8Lock", 102, 507,
                         ptr_managerGroup->ptr_textureManager->getTexture("numero8Lock"));
    m_eldoraLock.create("eldoraLock", 452, 577,
                         ptr_managerGroup->ptr_textureManager->getTexture("eldoraLock"));
    m_tristanLock.create("remingtonLock", 102, 577,
                         ptr_managerGroup->ptr_textureManager->getTexture("remingtonLock"));
    m_remingtonLock.create("tristanLock", 452, 507,
                         ptr_managerGroup->ptr_textureManager->getTexture("tristanLock"));
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
        std::wstring wstr = m_ptr_managerGroup->ptr_gameManager->getPlayer()->getCharacter()->getName();

        std::string str;
        for(std::wstring::const_iterator it = wstr.begin();
            it != wstr.end();
            ++it)
        {
            str.push_back(static_cast<char>(*it));
        }

        if (!m_ptr_managerGroup->ptr_networkManager->request(2, str)){
            errorConnection();
        }

    }


    /*if(m_inputHandler.getComponentId() == "returnButton") {
        m_playButton.setVisible(false);
        m_infoCharacterPanel.setVisible(false);
        m_selectCharacterPanel.setVisible(false);
        m_ptr_managerGroup->ptr_targetManager->isOnLobby();
    }*/

    /*if (m_nbPlayer==5){
        m_playButton.setVisible(true);
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
            //On peut rentrer en jeu
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
                m_validateCharacterButton.setEnabled(false);
                blockCharacters();
                m_charSelected = true;
                m_playButton.setVisible(true);
                std::cout << "Choix validé ! " << std::endl;

            }
            else{
                errorCharacterSelection();
            }
            break;

        case 3:
            //Nom perso - nom joueur
            // ex : "eldora""Lucas"
            *packet >> sRequest >> sRequest2;
            m_nbPlayer++;
            m_nbCharLocked++;
            //TODO : Désactiver le personnage
            //TODO : Afficher le nom du joueur avec l'image du personnage sélectionné
            blockCharacter(sRequest, sRequest2);

            break;
    }

}

void WarmUp::blockCharacters() {
    m_eldoraButton.setEnabled(false);
    m_numero8Button.setEnabled(false);
    m_remingtonButton.setEnabled(false);
    m_tristanButton.setEnabled(false);
    m_mdjButton.setEnabled(false);
    m_nbPlayer++;
}

void WarmUp::blockCharacter(std::string characterName, std::string playerName) {
    std::wstring wplayerName = s2ws(playerName);

    if (characterName=="eldora") {
        m_eldoraButton.setEnabled(false);
        adaptPosition(m_eldoraLock, m_eldoraLockLabel);
        m_eldoraLockLabel.setText(wplayerName);
        m_eldoraLockLabel.setVisible(true);
        m_eldoraLock.setVisible(true);
    }

    if (characterName=="remington"){
        m_remingtonButton.setEnabled(false);
        adaptPosition(m_remingtonLock, m_remingtonLockLabel);
        m_remingtonLockLabel.setText(wplayerName);
        m_remingtonLockLabel.setVisible(true);
        m_remingtonLock.setVisible(true);
    }

    if (characterName=="mdj"){
        m_mdjButton.setEnabled(false);
        adaptPosition(m_mdjLock, m_mdjLockLabel);
        m_mdjLockLabel.setText(wplayerName);
        m_mdjLockLabel.setVisible(true);
        m_mdjLock.setVisible(true);
    }

    if (characterName=="tristan"){
        m_tristanButton.setEnabled(false);
        adaptPosition(m_tristanLock, m_tristanLockLabel);
        m_tristanLockLabel.setText(wplayerName);
        m_tristanLockLabel.setVisible(true);
        m_tristanLock.setVisible(true);
    }

    if (characterName=="numero8"){
        m_numero8Button.setEnabled(false);
        adaptPosition(m_numero8Lock, m_numero8LockLabel);
        m_numero8LockLabel.setText(wplayerName);
        m_numero8LockLabel.setVisible(true);
        m_numero8Lock.setVisible(true);
    }


}

void WarmUp::adaptPosition(NPanel panel, NLabel label) {
    switch (m_nbCharLocked){
        case 1 :
            m_characterLockPanel1.setVisible(true);
            panel.setPosition(102, 507);
            label.setPosition(175, 520);
            break;
        case 2 :
            m_characterLockPanel2.setVisible(true);
            panel.setPosition(102, 577);
            label.setPosition(175, 590);
            break;
        case 3:
            m_characterLockPanel3.setVisible(true);
            panel.setPosition(452, 507);
            label.setPosition(525, 520);
            break;
        case 4:
            m_characterLockPanel4.setVisible(true);
            panel.setPosition(452, 577);
            label.setPosition(525, 590);
            break;
        default:break;
    }
}

std::wstring WarmUp::s2ws(std::string s) {
    std::wstring temp(s.length(),L' ');
    std::copy(s.begin(), s.end(), temp.begin());
    return temp;
}