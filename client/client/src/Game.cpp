//
// Created by Jehan on 05/03/2016.
//

#include "Game.hpp"
Game::Game(bool debug, ManagerGroup * ptr_managerGroup):
        BasicInterface(debug, ptr_managerGroup),
        m_buttonEldoraInGame(),
        m_buttonRemingtonInGame(),
        m_buttonTristanInGame(),
        m_panelTableInGame(),
        m_buttonNumero8InGame(),
        m_buttonMdjInGame(),
        m_launchGameButton(),
        m_monsterButton(),
        m_ambianceButton(),
        m_beachButton(),
        m_castleButton(),
        m_forestButton(),
        m_landButton(),
        m_roomButton(),
        m_crapaudButton(),
        m_dragonButton(),
        m_yetiButton(),
        m_yetiPanel(),
        m_dragonPanel(),
        m_crapaudPanel(),
        m_panelCharateristics(),
        m_panelNameCharacter(),
        m_panelAttack(),
        m_panelDefense(),
        m_panelHealth(),
        m_labelNameCharacter(),
        m_labelAttack(),
        m_labelDefense(),
        m_labelHealth(),
        m_labelCharacteristics(),
        m_panelChat(),
        m_textFieldLogin(),
        m_bibouPanel2(),
        m_contentPaneBackground(),
        m_panelMJ(),
        m_panelAmbianceMJ(),
        m_panelMonstresMJ(),
        m_panelIconAttack(),
        m_panelIconDefense(),
        m_panelIconHealth(),
        m_buttonHit(),
        m_buttonSummon()


{
    firstConnect = true;
    m_isOnMonstrePanel = false;
    m_isOnAmbiancePanel = false;
    //Background
    setBackground(ptr_managerGroup->ptr_textureManager->getTexture("background_Castle"));

    if (!m_fontLabel.loadFromFile("../res/font/Quicksand.ttf") || !m_fontTextbox.loadFromFile("../res/font/LucidaTypewriterRegular.ttf"))
    {
        std::cout << "Probleme dans le chargement des textures" << std::endl;
    }

    //Panel interface
    m_bibouPanel2.create("bibouPanel2", 0, 490,
                         ptr_managerGroup->ptr_textureManager->getTexture("bibouPanel2"));
    getContentPane()->addComponent(&m_bibouPanel2);


    //Table
    ptr_tableInGame = ptr_managerGroup->ptr_textureManager->getTexture("tableInGame");
    ptr_tableInGame->setSmooth(true);
    m_panelTableInGame.create("tableInGame",160,190,ptr_tableInGame);
    getContentPane()->addComponent(&m_panelTableInGame);

    //MDJ
    ptr_mdjInGame = ptr_managerGroup->ptr_textureManager->getTexture("mdjInGame");
    ptr_mdjInGame->setSmooth(true);
    m_buttonMdjInGame.create("mdjInGame",430,60,ptr_mdjInGame, ptr_mdjInGame);
    getContentPane()->addComponent(&m_buttonMdjInGame);

    //Remington
    ptr_remingtonInGame = ptr_managerGroup->ptr_textureManager->getTexture("remingtonInGame");
    ptr_remingtonInGame->setSmooth(true);
    m_buttonRemingtonInGame.create("remingtonInGame",730,87,ptr_remingtonInGame, ptr_remingtonInGame);
    getContentPane()->addComponent(&m_buttonRemingtonInGame);

    //Eldora
    ptr_eldoraInGame = ptr_managerGroup->ptr_textureManager->getTexture("eldoraInGame");
    ptr_eldoraInGame->setSmooth(true);
    m_buttonEldoraInGame.create("eldoraInGame",765,200,ptr_eldoraInGame, ptr_eldoraInGame);
    getContentPane()->addComponent(&m_buttonEldoraInGame);

    //Numero 8
    ptr_numero8InGame = ptr_managerGroup->ptr_textureManager->getTexture("numero8InGame");
    ptr_numero8InGame->setSmooth(true);
    m_buttonNumero8InGame.create("numero8InGame",230,87,ptr_numero8InGame, ptr_numero8InGame);
    getContentPane()->addComponent(&m_buttonNumero8InGame);

    //Tristan
    ptr_tristanInGame = ptr_managerGroup->ptr_textureManager->getTexture("tristanInGame");
    ptr_tristanInGame->setSmooth(true);
    m_buttonTristanInGame.create("tristanInGame",215,200,ptr_tristanInGame, ptr_tristanInGame);
    getContentPane()->addComponent(&m_buttonTristanInGame);

    //Text Box Chat
    m_textFieldLogin.create("textFieldLogin", 5, 690,
                            ptr_managerGroup->ptr_textureManager->getTexture("chatTextBox"),
                            ptr_managerGroup->ptr_textureManager->getTexture("textBoxCursorChat"),
                            &m_fontTextbox,
                            15, 0.5, "", 104, sf::Color(196,130,56));
    //Panel Chat
    m_panelChat.create("chatPanel", 5, 510,
                       ptr_managerGroup->ptr_textureManager->getTexture("chatPanel"));

    /*m_arrowUp.create("arrowUp", 290, 520,
                     ptr_managerGroup->ptr_textureManager->getTexture("chatPanel"),
                    ptr_managerGroup->ptr_textureManager->getTexture("chatPanel"));
*/
    //Panel UI du MJ
    m_panelMJ.create("MJPanel", 2000, 2000,ptr_managerGroup->ptr_textureManager->getTexture("IconHealth"));
    m_panelAmbianceMJ.create("panelAmbianceMJ", 2000, 2000,ptr_managerGroup->ptr_textureManager->getTexture("IconDefense"));
    m_panelMonstresMJ.create("panelMonstresMJ", 2000, 2000,ptr_managerGroup->ptr_textureManager->getTexture("IconAttack"));

    //Button for MJ
    m_monsterButton.create("monsterButton", 450, 595,
                           ptr_managerGroup->ptr_textureManager->getTexture("monsterButton_1"),
                           ptr_managerGroup->ptr_textureManager->getTexture("monsterButton_2"));
    m_panelMJ.addComponent(&m_monsterButton);
    //////////////
    m_ambianceButton.create("ambianceButton", 450, 650,
                            ptr_managerGroup->ptr_textureManager->getTexture("ambianceButton_1"),
                            ptr_managerGroup->ptr_textureManager->getTexture("ambianceButton_2"));
    m_panelMJ.addComponent(&m_ambianceButton);

    //---AMBIANCES
    ///////////
    m_beachButton.create("beachButton", 580, 540,
                         ptr_managerGroup->ptr_textureManager->getTexture("beachButton_1"),
                         ptr_managerGroup->ptr_textureManager->getTexture("beachButton_2"));
    m_panelAmbianceMJ.addComponent(&m_beachButton);
    ////////////
    m_castleButton.create("castleButton", 580, 580,
                          ptr_managerGroup->ptr_textureManager->getTexture("castleButton_1"),
                          ptr_managerGroup->ptr_textureManager->getTexture("castleButton_2"));
    m_panelAmbianceMJ.addComponent(&m_castleButton);
    ///////////
    m_forestButton.create("forestButton", 580, 620,
                          ptr_managerGroup->ptr_textureManager->getTexture("forestButton_1"),
                          ptr_managerGroup->ptr_textureManager->getTexture("forestButton_2"));
    m_panelAmbianceMJ.addComponent(&m_forestButton);
    ///////////
    m_landButton.create("landButton", 580, 660,
                        ptr_managerGroup->ptr_textureManager->getTexture("landButton_1"),
                        ptr_managerGroup->ptr_textureManager->getTexture("landButton_2"));
    m_panelAmbianceMJ.addComponent(&m_landButton);
    ///////////
    m_roomButton.create("roomButton", 580, 700,
                        ptr_managerGroup->ptr_textureManager->getTexture("roomButton_1"),
                        ptr_managerGroup->ptr_textureManager->getTexture("roomButton_2"));
    m_panelAmbianceMJ.addComponent(&m_roomButton);

    //---MONSTRES
    ///////////
    m_crapaudButton.create("crapaudButton", 580, 560,
                           ptr_managerGroup->ptr_textureManager->getTexture("crapaudButton_1"),
                           ptr_managerGroup->ptr_textureManager->getTexture("crapaudButton_2"));
    m_panelMonstresMJ.addComponent(&m_crapaudButton);
    ///////////
    m_dragonButton.create("dragonButton", 580, 620,
                          ptr_managerGroup->ptr_textureManager->getTexture("dragonButton_1"),
                          ptr_managerGroup->ptr_textureManager->getTexture("dragonButton_2"));
    m_panelMonstresMJ.addComponent(&m_dragonButton);
    ///////////
    m_yetiButton.create("yetiButton", 580, 680,
                        ptr_managerGroup->ptr_textureManager->getTexture("yetiButton_1"),
                        ptr_managerGroup->ptr_textureManager->getTexture("yetiButton_2"));
    m_panelMonstresMJ.addComponent(&m_yetiButton);

    m_yetiPanel.create("yetiPanel", 650,190,  ptr_managerGroup->ptr_textureManager->getTexture("Yeti"));
    m_yetiPanel.setVisible(false);
    getContentPane()->addComponent(&m_yetiPanel);

    m_dragonPanel.create("dragonPanel", 350,210,  ptr_managerGroup->ptr_textureManager->getTexture("Dragon"));
    m_dragonPanel.setVisible(false);
    getContentPane()->addComponent(&m_dragonPanel);

    m_crapaudPanel.create("crapaudPanel", 520,200,  ptr_managerGroup->ptr_textureManager->getTexture("Crapaud"));
    m_crapaudPanel.setVisible(false);
    getContentPane()->addComponent(&m_crapaudPanel);



    m_panelCharateristics.create("charateristicsPanel", 704, 512,
                                 ptr_managerGroup->ptr_textureManager->getTexture("charateristicsPanel"));
    /*m_panelNameCharacter.create("nameCharacterPanel",704, 512,
                                    ptr_managerGroup->ptr_textureManager->getTexture("statPanel"));*/
    m_panelAttack.create("attackPanel",704, 567,
                         ptr_managerGroup->ptr_textureManager->getTexture("statPanel"));
    m_panelDefense.create("defensePanel", 704, 622,
                          ptr_managerGroup->ptr_textureManager->getTexture("statPanel"));
    m_panelHealth.create("healthPanel", 704, 677,
                         ptr_managerGroup->ptr_textureManager->getTexture("statPanel"));

    m_panelIconAttack.create("attackIcon", 704,567,
                             ptr_managerGroup->ptr_textureManager->getTexture("IconAttack"));

    m_panelIconDefense.create("defenseIcon", 704,622,
                              ptr_managerGroup->ptr_textureManager->getTexture("IconDefense"));

    m_panelIconHealth.create("healthIcon", 707,680,
                             ptr_managerGroup->ptr_textureManager->getTexture("IconHealth"));


    m_labelNameCharacter.create("labelNameCharacter", 750, 529, 15, &m_fontLabel, L"", sf::Color::Black);
    m_labelAttack.create("labelAttack", 780, 584, 15, &m_fontLabel, L"", sf::Color::Black);
    m_labelDefense.create("labelDefense", 780, 639, 15, &m_fontLabel, L"", sf::Color::Black);
    m_labelHealth.create("labelHealth", 780, 696, 15, &m_fontLabel, L"", sf::Color::Black);


    m_panelNameCharacter.addComponent(&m_labelNameCharacter);

    m_panelAttack.addComponent(&m_panelIconAttack);
    m_panelAttack.addComponent(&m_labelAttack);

    m_panelDefense.addComponent(&m_labelDefense);
    m_panelDefense.addComponent(&m_panelIconDefense);

    m_panelHealth.addComponent(&m_labelHealth);
    m_panelHealth.addComponent(&m_panelIconHealth);

    m_panelCharateristics.addComponent(&m_panelNameCharacter);
    m_panelCharateristics.addComponent(&m_panelAttack);
    m_panelCharateristics.addComponent(&m_panelDefense);
    m_panelCharateristics.addComponent(&m_panelHealth);


    m_panelMJ.addComponent(&m_launchGameButton);
    m_panelMJ.setVisible(false);
    m_panelMonstresMJ.setVisible(false);
    m_panelAmbianceMJ.setVisible(false);
    getContentPane()->addComponent(&m_panelCharateristics);
    getContentPane()->addComponent(&m_textFieldLogin);
    getContentPane()->addComponent(&m_panelChat);
    getContentPane()->addComponent(&m_panelMJ);
    getContentPane()->addComponent(&m_panelMJ);
    getContentPane()->addComponent(&m_panelMonstresMJ);
    getContentPane()->addComponent(&m_panelAmbianceMJ);






    ptr_buttonHit = ptr_managerGroup->ptr_textureManager->getTexture("buttonHit");
    ptr_buttonHit->setSmooth(true);
    m_buttonHit.create("buttonHit", 490, 620, ptr_buttonHit, ptr_buttonHit);
    getContentPane()->addComponent(&m_buttonHit);

    ptr_buttonSummon = ptr_managerGroup->ptr_textureManager->getTexture("buttonSummon");
    ptr_buttonSummon->setSmooth(true);
    m_buttonSummon.create("buttonSummon", 490, 550, ptr_buttonSummon, ptr_buttonSummon);
    getContentPane()->addComponent(&m_buttonSummon);

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

    if(firstConnect){

        //TODO : régler ce problème de Label qui ne s'affiche pas
        std::wstring currentPlayerName = m_ptr_managerGroup->ptr_gameManager->getPlayer()->getCharacter()->getName();
        std::wstring currentPlayerAttack = m_ptr_managerGroup->ptr_gameManager->getPlayer()->getCharacter()->getCaracteristic()->getAttackDamage();
        std::wstring currentPlayerDefense = m_ptr_managerGroup->ptr_gameManager->getPlayer()->getCharacter()->getCaracteristic()->getArmor();
        std::wstring currentPlayerHealth = m_ptr_managerGroup->ptr_gameManager->getPlayer()->getCharacter()->getCaracteristic()->getHealth();

        m_labelNameCharacter.setText(currentPlayerName);
        m_labelAttack.setText(currentPlayerAttack);
        m_labelDefense.setText(currentPlayerDefense);
        m_labelHealth.setText(currentPlayerHealth);


        if(m_ptr_managerGroup->ptr_gameManager->getPlayer()->getCharacter()->getId() == "mdj"){
            m_panelMJ.setVisible(true);
            //m_panelAmbianceMJ.setVisible(true);
            // m_panelMonstresMJ.setVisible(true);
            m_buttonHit.setPosition(375, 620);
            m_buttonSummon.setPosition(375, 550);


        }
        firstConnect = false;
    }

    // Basic Interface updating
    basicInput(e, frameTime);

    //Evenement sur les panneaux des joueurs
    if(m_inputHandler.getComponentId() == "remingtonInGame") {
        displayFeature("remington");

    }
    if(m_inputHandler.getComponentId() == "eldoraInGame"){
        displayFeature("eldora");

    }
    if(m_inputHandler.getComponentId() == "numero8InGame"){
        displayFeature("numero8");

    }
    if(m_inputHandler.getComponentId() == "tristanInGame"){
        displayFeature("tristan");
    }

    if(m_inputHandler.getComponentId() == "monsterButton"){
        std::cout << "CLIC MONSTRE" << std::endl;

        m_isOnMonstrePanel = true;
        m_isOnAmbiancePanel = false;
        m_ambianceButton.setVisible(false);
        m_panelAmbianceMJ.setVisible(false);
        m_panelMonstresMJ.setVisible(true);
    }

    if(m_inputHandler.getComponentId() == "ambianceButton"){
        m_isOnMonstrePanel = true;
        m_isOnAmbiancePanel = false;
        m_monsterButton.setVisible(false);
        m_panelMonstresMJ.setVisible(false);
        m_panelAmbianceMJ.setVisible(true);
    }


    /*if(m_isOnAmbiancePanel){*/
        if(m_inputHandler.getComponentId() == "beachButton"){
            setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Beach"));
            m_panelAmbianceMJ.setVisible(false);
            m_monsterButton.setVisible(true);
            m_isOnAmbiancePanel = false;
        }
        if(m_inputHandler.getComponentId() == "castleButton"){
            setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("background_Castle"));
            m_panelAmbianceMJ.setVisible(false);
            m_monsterButton.setVisible(true);
            m_isOnAmbiancePanel = false;
        }
        if(m_inputHandler.getComponentId() == "forestButton"){
            setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Forest"));
            m_panelAmbianceMJ.setVisible(false);
            m_monsterButton.setVisible(true);
            m_isOnAmbiancePanel = false;
        }
        if(m_inputHandler.getComponentId() == "landButton"){
            setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Landscape"));
            m_panelAmbianceMJ.setVisible(false);
            m_monsterButton.setVisible(true);
            m_isOnAmbiancePanel = false;
        }
        if(m_inputHandler.getComponentId() == "roomButton"){
            setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Room"));
            m_panelAmbianceMJ.setVisible(false);
            m_monsterButton.setVisible(true);
            m_isOnAmbiancePanel = false;
        }
    /*}*/
    if(m_isOnMonstrePanel){
        if(m_inputHandler.getComponentId() == "crapaudButton"){
            //TODO : afficher une image de crapaud
            m_crapaudPanel.setVisible(true);
            m_yetiPanel.setVisible(false);
            m_dragonPanel.setVisible(false);

            m_isOnMonstrePanel = false;
            m_ambianceButton.setVisible(true);
            m_panelMonstresMJ.setVisible(false);
        }
        if(m_inputHandler.getComponentId() == "dragonButton"){
            //TODO : afficher une image de dragon
            m_crapaudPanel.setVisible(false);
            m_yetiPanel.setVisible(false);
            m_dragonPanel.setVisible(true);

            m_isOnMonstrePanel = false;
            m_ambianceButton.setVisible(true);
            m_panelMonstresMJ.setVisible(false);
        }
        if(m_inputHandler.getComponentId() == "yetiButton"){
            //TODO : afficher une image de yeti
            m_crapaudPanel.setVisible(false);
            m_yetiPanel.setVisible(true);
            m_dragonPanel.setVisible(false);

            m_isOnMonstrePanel = false;
            m_ambianceButton.setVisible(true);
            m_panelMonstresMJ.setVisible(false);
        }
    }



    sf::Event ev = *e;
    if(ev.key.code == 13) {
        std::cout << m_textFieldLogin.getString() << std::endl;
        //TODO : vider le m_textFieldLogin
        //TODO : envoyer le texte saisie au serveur
    }



    //if (e->type == sf::TextE)
    // Drawing all content
    basicDraw(window);

}


void Game::displayFeature(std::string id){
    std::wstring name = m_ptr_managerGroup->ptr_gameManager->getCharacterById(id)->getName();
    std::wstring attack = m_ptr_managerGroup->ptr_gameManager->getCharacterById(id)->getCaracteristic()->getAttackDamage();
    std::wstring defense = m_ptr_managerGroup->ptr_gameManager->getCharacterById(id)->getCaracteristic()->getArmor();
    std::wstring health = m_ptr_managerGroup->ptr_gameManager->getCharacterById(id)->getCaracteristic()->getHealth();

    m_labelNameCharacter.setText(name);
    m_labelAttack.setText(attack);
    m_labelDefense.setText(defense);
    m_labelHealth.setText(health);
}

