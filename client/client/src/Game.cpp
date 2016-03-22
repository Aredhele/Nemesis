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
        m_labelChatVector(),
        m_yetiButton(),
        m_yetiMonsterButton(),
        m_dragonMonsterButton(),
        m_crapaudMonsterButton(),
        m_panelCharateristics(),
        m_panelNameCharacter(),
        m_panelAttack(),
        m_panelDefense(),
        m_panelHealth(),
        m_labelNameCharacter(),
        m_labelAttack(),
        m_labelDefense(),
        m_labelHealth(),
        m_numero8Mini(),
        m_eldoraMini(),
        m_tristanMini(),
        m_remingtonMini(),
        m_mdjMini(),
        m_playerIcon(),
        m_labelCharacteristics(),
        m_panelChat(),
        m_textChat(),
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
    noError();
    firstConnect = true;
    m_isOnMonstrePanel = false;
    m_isOnAmbiancePanel = false;
    isSpecial = false;
    isHitting = false;
    selectedChar = "NULL";
    selectedMonster = "NULL";

    //Background
    setBackground(ptr_managerGroup->ptr_textureManager->getTexture("Background_Castle"));

    if (!m_fontLabel.loadFromFile("../res/font/Roboto-Regular.ttf") ||
        !m_fontTextbox.loadFromFile("../res/font/LucidaTypewriterRegular.ttf"))
    {
        std::cout << "Probleme dans le chargement des textures" << std::endl;
    }

    //Panel Interface
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
    m_textChat.create("textFieldLogin", 5, 675,
                      ptr_managerGroup->ptr_textureManager->getTexture("chatTextBox"),
                      ptr_managerGroup->ptr_textureManager->getTexture("textBoxCursorChat"),
                      &m_fontTextbox,
                      15, 0.5, "", 101, sf::Color(196,130,56));
    m_textChat.setTextPosition(7, 678);
    m_textChat.setCursorPosition(7, 680);

    //Panel Chat
    m_panelChat.create("chatPanel", 5, 495,
                       ptr_managerGroup->ptr_textureManager->getTexture("chatPanel"));

    for(int i = 0; i < 11; i++){
        NLabel* label = new NLabel();
        m_labelChatVector.push_back(label);
    }
    for(int i = 0; i < m_labelChatVector.size(); i++){
        m_labelChatVector.at(i)->create("labelChat"+i, 7, 495+15*i, 15, &m_fontLabel, L"", sf::Color::Black );
    }

    //Panel UI du MJ
    m_panelMJ.create("MJPanel", 2000, 2000,ptr_managerGroup->ptr_textureManager->getTexture("IconHealth"));
    m_panelAmbianceMJ.create("panelAmbianceMJ", 2000, 2000,ptr_managerGroup->ptr_textureManager->getTexture("IconDefense"));
    m_panelMonstresMJ.create("panelMonstresMJ", 2000, 2000,ptr_managerGroup->ptr_textureManager->getTexture("IconAttack"));

    //Button for MJ
    m_monsterButton.create("monsterButton", 440, 595,
                           ptr_managerGroup->ptr_textureManager->getTexture("monsterButton_1"),
                           ptr_managerGroup->ptr_textureManager->getTexture("monsterButton_2"));
    m_panelMJ.addComponent(&m_monsterButton);

    m_ambianceButton.create("ambianceButton", 440, 650,
                            ptr_managerGroup->ptr_textureManager->getTexture("ambianceButton_1"),
                            ptr_managerGroup->ptr_textureManager->getTexture("ambianceButton_2"));
    m_panelMJ.addComponent(&m_ambianceButton);

    //---AMBIANCES
    ///////////
    m_beachButton.create("beachButton", 560, 540,
                         ptr_managerGroup->ptr_textureManager->getTexture("beachButton_1"),
                         ptr_managerGroup->ptr_textureManager->getTexture("beachButton_2"));
    m_panelAmbianceMJ.addComponent(&m_beachButton);
    ////////////
    m_castleButton.create("castleButton", 560, 580,
                          ptr_managerGroup->ptr_textureManager->getTexture("castleButton_1"),
                          ptr_managerGroup->ptr_textureManager->getTexture("castleButton_2"));
    m_panelAmbianceMJ.addComponent(&m_castleButton);
    ///////////
    m_forestButton.create("forestButton", 560, 620,
                          ptr_managerGroup->ptr_textureManager->getTexture("forestButton_1"),
                          ptr_managerGroup->ptr_textureManager->getTexture("forestButton_2"));
    m_panelAmbianceMJ.addComponent(&m_forestButton);
    ///////////
    m_landButton.create("landButton", 560, 660,
                        ptr_managerGroup->ptr_textureManager->getTexture("landButton_1"),
                        ptr_managerGroup->ptr_textureManager->getTexture("landButton_2"));
    m_panelAmbianceMJ.addComponent(&m_landButton);
    ///////////
    m_roomButton.create("roomButton", 560, 700,
                        ptr_managerGroup->ptr_textureManager->getTexture("roomButton_1"),
                        ptr_managerGroup->ptr_textureManager->getTexture("roomButton_2"));
    m_panelAmbianceMJ.addComponent(&m_roomButton);

    //---MONSTRES
    ///////////
    m_crapaudButton.create("crapaudButton", 560, 560,
                           ptr_managerGroup->ptr_textureManager->getTexture("crapaudButton_1"),
                           ptr_managerGroup->ptr_textureManager->getTexture("crapaudButton_2"));
    m_panelMonstresMJ.addComponent(&m_crapaudButton);
    ///////////
    m_dragonButton.create("dragonButton", 560, 620,
                          ptr_managerGroup->ptr_textureManager->getTexture("dragonButton_1"),
                          ptr_managerGroup->ptr_textureManager->getTexture("dragonButton_2"));
    m_panelMonstresMJ.addComponent(&m_dragonButton);
    ///////////
    m_yetiButton.create("yetiButton", 560, 680,
                        ptr_managerGroup->ptr_textureManager->getTexture("yetiButton_1"),
                        ptr_managerGroup->ptr_textureManager->getTexture("yetiButton_2"));
    m_panelMonstresMJ.addComponent(&m_yetiButton);



    m_yetiMonsterButton.create("yetiPanel", 650,190,
                               ptr_managerGroup->ptr_textureManager->getTexture("Yeti"),
                               ptr_managerGroup->ptr_textureManager->getTexture("Yeti"));
    m_yetiMonsterButton.setVisible(false);
    getContentPane()->addComponent(&m_yetiMonsterButton);

    m_dragonMonsterButton.create("dragonPanel", 350,210,
                                 ptr_managerGroup->ptr_textureManager->getTexture("Dragon"),
                                 ptr_managerGroup->ptr_textureManager->getTexture("Dragon"));
    m_dragonMonsterButton.setVisible(false);
    getContentPane()->addComponent(&m_dragonMonsterButton);

    m_crapaudMonsterButton.create("crapaudPanel", 520,200,
                                  ptr_managerGroup->ptr_textureManager->getTexture("Crapaud"),
                                  ptr_managerGroup->ptr_textureManager->getTexture("Crapaud"));
    m_crapaudMonsterButton.setVisible(false);
    getContentPane()->addComponent(&m_crapaudMonsterButton);

    //Animations
    m_feu.create("feu", 350,110,  ptr_managerGroup->ptr_textureManager->getTexture("feu"));
    getContentPane()->addComponent(&m_feu);

    m_feu2.create("feu", 635,110,  ptr_managerGroup->ptr_textureManager->getTexture("feu"));
    getContentPane()->addComponent(&m_feu2);

    m_flammes.create("flammes", 350, 65,
                     ptr_managerGroup->ptr_textureManager->getTexture("flammes"),
                     true, 0.1, 121, 70, 5);
    getContentPane()->addComponent(&m_flammes);

    m_flammes2.create("flammes", 635, 65,
                      ptr_managerGroup->ptr_textureManager->getTexture("flammes"),
                      true, 0.12, 121, 70, 5);
    getContentPane()->addComponent(&m_flammes2);

    m_mdjAnimation.create("mdjAnimation", 538, 179,
                          ptr_managerGroup->ptr_textureManager->getTexture("mdjAnimation"),
                          true, 0.1, 19, 19, 22);
    getContentPane()->addComponent(&m_mdjAnimation);

    m_attackAnimation.create("attackAnimation", 500,350,
                             ptr_managerGroup->ptr_textureManager->getTexture("attackAnimation"),
                             false, 0.05, 192,192,6);
    getContentPane()->addComponent(&m_attackAnimation);
    m_attackAnimation.setVisible(false);

    m_numero8Special.create("numero8Special", 500,350,
                             ptr_managerGroup->ptr_textureManager->getTexture("numero8Special"),
                             false, 0.07, 192,192,7);
    getContentPane()->addComponent(&m_numero8Special);
    m_numero8Special.setVisible(false);

    m_eldoraSpecial.create("eldoraSpecial", 500,350,
                            ptr_managerGroup->ptr_textureManager->getTexture("eldoraSpecial"),
                            false, 0.07, 192,192,13);
    getContentPane()->addComponent(&m_eldoraSpecial);
    m_eldoraSpecial.setVisible(false);

    m_remingtonSpecial.create("remingtonSpecial", 500,350,
                           ptr_managerGroup->ptr_textureManager->getTexture("remingtonSpecial"),
                           false, 0.05, 192,192,8);
    getContentPane()->addComponent(&m_remingtonSpecial);
    m_remingtonSpecial.setVisible(false);

    m_tristanSpecial.create("tristanSpecial", 500,350,
                              ptr_managerGroup->ptr_textureManager->getTexture("tristanSpecial"),
                              false, 0.08, 192,192,7);
    getContentPane()->addComponent(&m_tristanSpecial);
    m_tristanSpecial.setVisible(false);

    //Characteristiques
    m_panelCharateristics.create("charateristicsPanel", 675, 495,
                                 ptr_managerGroup->ptr_textureManager->getTexture("charateristicsPanel"));
    getContentPane()->addComponent(&m_panelCharateristics);

    m_panelIconAttack.create("attackIcon", 764,547,
                             ptr_managerGroup->ptr_textureManager->getTexture("IconAttack"));
    getContentPane()->addComponent(&m_panelIconAttack);

    m_panelIconDefense.create("defenseIcon", 764,597,
                              ptr_managerGroup->ptr_textureManager->getTexture("IconDefense"));
    getContentPane()->addComponent(&m_panelIconDefense);

    m_panelIconHealth.create("healthIcon", 767,650,
                             ptr_managerGroup->ptr_textureManager->getTexture("IconHealth"));
    getContentPane()->addComponent(&m_panelIconHealth);


    m_labelNameCharacter.create("labelNameCharacter", 840, 509, 15, &m_fontLabel, L"", sf::Color::Black);
    getContentPane()->addComponent(&m_labelNameCharacter);

    m_labelAttack.create("labelAttack", 840, 564, 15, &m_fontLabel, L"Attaque : ", sf::Color::Black);
    getContentPane()->addComponent(&m_labelAttack);

    m_labelDefense.create("labelDefense", 840, 614, 15, &m_fontLabel, L"Défense : ", sf::Color::Black);
    getContentPane()->addComponent(&m_labelDefense);

    m_labelHealth.create("labelHealth", 840, 665, 15, &m_fontLabel, L"Santé : ", sf::Color::Black);
    getContentPane()->addComponent(&m_labelHealth);





    m_numero8Mini.create("numero8Mini", 767,497,
                         ptr_managerGroup->ptr_textureManager->getTexture("numero8Lock"));
    getContentPane()->addComponent(&m_numero8Mini);
    m_eldoraMini.create("eldoraMini", 767,497,
                        ptr_managerGroup->ptr_textureManager->getTexture("eldoraLock"));
    getContentPane()->addComponent(&m_eldoraMini);
    m_tristanMini.create("tristanMini", 767,497,
                         ptr_managerGroup->ptr_textureManager->getTexture("tristanLock"));
    getContentPane()->addComponent(&m_tristanMini);
    m_remingtonMini.create("remingtonMini", 767,497,
                           ptr_managerGroup->ptr_textureManager->getTexture("remingtonLock"));
    getContentPane()->addComponent(&m_remingtonMini);
    m_mdjMini.create("mdjMini", 767,497,
                     ptr_managerGroup->ptr_textureManager->getTexture("mdjLock"));
    getContentPane()->addComponent(&m_mdjMini);

    m_playerIcon.create("playerIcon", 825,699,
                     ptr_managerGroup->ptr_textureManager->getTexture("mdjLock"));
    getContentPane()->addComponent(&m_playerIcon);


    m_numero8Mini.setVisible(false);
    m_eldoraMini.setVisible(false);
    m_tristanMini.setVisible(false);
    m_remingtonMini.setVisible(false);
    m_mdjMini.setVisible(false);


    m_panelMJ.addComponent(&m_launchGameButton);
    m_panelMJ.setVisible(false);
    m_panelMonstresMJ.setVisible(false);
    m_panelAmbianceMJ.setVisible(false);

    getContentPane()->addComponent(&m_textChat);
    getContentPane()->addComponent(&m_panelChat);
    for(unsigned int i = 0; i < m_labelChatVector.size(); i++){
        getContentPane()->addComponent(m_labelChatVector.at(i));
    }
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
}

/*!
 * \brief Update current object
 * \param window The pointer on the window
 * \param frameTime The elpased time
 */
void Game::update(sf::RenderWindow * window,
                  sf::Event * e, double frameTime) {


    if(!m_ptr_managerGroup->ptr_targetManager->isGame())
        return;

    if(firstConnect){

        initPlayerCharacter();

        displayFeature(m_player->getCharacter()->getId());

        if(isMdj){
            m_panelMJ.setVisible(true);
            m_buttonHit.setPosition(375, 620);
            m_buttonSummon.setPosition(375, 550);
        }
        firstConnect = false;
    }

    if(m_ptr_managerGroup->ptr_networkManager->getHasPacket()){
        receiveRequest();
    }

    checkStateAnimation();

    // Basic Interface updating
    basicInput(e, frameTime);

    //Evenement sur les panneaux des joueurs
    if(m_inputHandler.getComponentId() == "remingtonInGame") {
        if(!isMdj) selectedMonster="NULL";
        if(selectedChar!="remington") selectedMonster="NULL";
        selectedChar = "remington";
        displayFeature("remington");
    }
    if(m_inputHandler.getComponentId() == "eldoraInGame"){
        if(!isMdj) selectedMonster="NULL";
        if(selectedChar!="eldora") selectedMonster="NULL";
        selectedChar = "eldora";
        displayFeature("eldora");
    }
    if(m_inputHandler.getComponentId() == "numero8InGame"){
        if(!isMdj) selectedMonster="NULL";
        if(selectedChar!="numero8") selectedMonster="NULL";
        selectedChar = "numero8";
        displayFeature("numero8");
    }
    if(m_inputHandler.getComponentId() == "tristanInGame"){
        if(!isMdj) selectedMonster="NULL";
        if(selectedChar!="tristan") selectedMonster="NULL";
        selectedChar = "tristan";
        displayFeature("tristan");
    }
    if(m_inputHandler.getComponentId() == "mdjInGame"){
        if(!isMdj) selectedMonster="NULL";
        if(selectedChar!="mdj") selectedMonster="NULL";
        selectedMonster="NULL";
        displayFeature("mdj");
    }

    if(m_inputHandler.getComponentId() == "monsterButton"){
        if (!m_isOnMonstrePanel){
            m_isOnMonstrePanel = true;
            m_isOnAmbiancePanel = false;
            m_panelMonstresMJ.setVisible(true);
            m_ambianceButton.setVisible(false);

        }else{
            m_isOnMonstrePanel = false;
            m_panelMonstresMJ.setVisible(false);
            m_ambianceButton.setVisible(true);
        }
        m_panelAmbianceMJ.setVisible(false);
    }

    if(m_inputHandler.getComponentId() == "ambianceButton"){
        if (!m_isOnAmbiancePanel){
            m_isOnAmbiancePanel = true;
            m_panelAmbianceMJ.setVisible(true);
            m_monsterButton.setVisible(false);

        }else{
            m_isOnAmbiancePanel = false;
            m_panelAmbianceMJ.setVisible(false);
            m_monsterButton.setVisible(true);
        }
        m_panelMonstresMJ.setVisible(false);
    }

    if(m_inputHandler.getComponentId() == "beachButton"){
        request(8, "beach", "");
        /*changeAmbiance("beach");
        /*setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Beach"));
        isOnCastle = false;*/


        m_panelAmbianceMJ.setVisible(false);
        m_monsterButton.setVisible(true);
        m_isOnAmbiancePanel = false;
    }
    if(m_inputHandler.getComponentId() == "castleButton"){
        request(8, "castle", "");
        /*changeAmbiance("castle");
        setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("background_Castle"));
        isOnCastle = true;*/


        m_panelAmbianceMJ.setVisible(false);
        m_monsterButton.setVisible(true);
        m_isOnAmbiancePanel = false;
    }
    if(m_inputHandler.getComponentId() == "forestButton"){
        request(8, "forest", "");
        /*changeAmbiance("forest");
        /*setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Forest"));
        isOnCastle = false;*/


        m_panelAmbianceMJ.setVisible(false);
        m_monsterButton.setVisible(true);
        m_isOnAmbiancePanel = false;
    }
    if(m_inputHandler.getComponentId() == "landButton"){
        request(8, "landscape", "");
        /*changeAmbiance("landscape");
        setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Landscape"));
        isOnCastle = false;*/


        m_panelAmbianceMJ.setVisible(false);
        m_monsterButton.setVisible(true);
        m_isOnAmbiancePanel = false;
    }
    if(m_inputHandler.getComponentId() == "roomButton"){
        request(8, "room", "");
        /*changeAmbiance("room");
        setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Room"));
        isOnCastle = false;*/


        m_panelAmbianceMJ.setVisible(false);
        m_monsterButton.setVisible(true);
        m_isOnAmbiancePanel = false;
    }

    //On regarde si on est dans la pièce Chateau pour afficher les flammes
    if(isOnCastle){
        m_feu.setVisible(true);
        m_feu2.setVisible(true);
        m_flammes.setVisible(true);
        m_flammes2.setVisible(true);
    }else{
        m_feu.setVisible(false);
        m_feu2.setVisible(false);
        m_flammes.setVisible(false);
        m_flammes2.setVisible(false);
    }


    if(m_inputHandler.getComponentId()=="yetiPanel"){
        if(!isMdj) selectedChar="NULL";
        if(selectedMonster=="yeti") selectedChar="NULL";
        selectedMonster = "yeti";
        displayFeature(selectedMonster);
    }
    if(m_inputHandler.getComponentId()=="crapaudPanel"){
        if(!isMdj) selectedChar="NULL";
        if(selectedMonster=="crapaud") selectedChar="NULL";
        selectedMonster = "crapaud";
        displayFeature(selectedMonster);
    }
    if(m_inputHandler.getComponentId()=="dragonPanel"){
        if(!isMdj) selectedChar="NULL";
        if(selectedMonster=="dragon") selectedChar="NULL";
        selectedMonster = "dragon";
        displayFeature(selectedMonster);
    }


    if(m_inputHandler.getComponentId() == "crapaudButton"){
        if (hasCrapaud){
            request(9, "crapaud", "");
            //displayMonster(9, "crapaud");
        }else{
            request(10, "crapaud", "");
            //displayMonster(10, "crapaud");
        }

        m_isOnMonstrePanel = false;
        m_ambianceButton.setVisible(true);
        m_panelMonstresMJ.setVisible(false);

    }
    if(m_inputHandler.getComponentId() == "dragonButton"){
        if (hasDragon){
            request(9, "dragon", "");
            //displayMonster(9, "dragon");
        }else{
            request(10, "dragon", "");
            //displayMonster(10, "dragon");
        }
        m_isOnMonstrePanel = false;
        m_ambianceButton.setVisible(true);
        m_panelMonstresMJ.setVisible(false);

        //getMonster(selectedMonster)->selectMonster();

    }
    if(m_inputHandler.getComponentId() == "yetiButton"){
        if (hasYeti){
            request(9, "yeti", "");
            //displayMonster(9, "yeti");
        }else{
            request(10, "yeti", "");
            //displayMonster(10, "yeti");
        }
        m_isOnMonstrePanel = false;
        m_ambianceButton.setVisible(true);
        m_panelMonstresMJ.setVisible(false);
    }


    //we can hit with normal or special attack
    if (m_inputHandler.getComponentId() == "buttonHit"){
        if(isMdj){
            if(selectedChar!="NULL" && selectedMonster!="NULL"){
                std::cout << "id monstre : " << selectedMonster << std::endl;
                //Le monstre sélectionné attaque le personnage sélectionné
                request(11, selectedChar, selectedMonster);
                //monsterAttack(selectedChar, selectedMonster);

            }
        }else{
            if(selectedMonster!="NULL"){
                request(12, m_player->getCharacter()->getId(), selectedMonster);
                //characterAttack(m_player->getCharacter()->getId(), selectedMonster);

            }
        }

    }else if(m_inputHandler.getComponentId() == "buttonSummon"){

        if(isMdj){
            if(selectedChar!="NULL" && selectedMonster!="NULL"){
                //Le monstre sélectionné attaque le personnage sélectionné
                request(13, selectedChar, selectedMonster);
                //monsterSpecialAttack(selectedChar, selectedMonster);
            }
        }
        else if (isEldora){
            if(selectedChar!="NULL" && selectedMonster=="NULL"){
                request(15, selectedChar, "");
                //eldoraHealing(selectedChar);
            }
        }
        else{
            if(selectedMonster!="NULL"){
                request(14, m_player->getCharacter()->getId(), selectedMonster);
                //characterSpecialAttack(m_player->getCharacter()->getId(), selectedMonster);
            }
        }
        //specialAnimation(selectedChar);
        //isHitting = false;
        //isSpecial = true;
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){

        std::string text = m_textChat.getString();
        if(text != ""){
            text = text + "\n";
            //std::cout << text << std::endl;
            request(7, text, m_player->getCharacter()->getId());
            //m_textChat.empty();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        std::cout << "up" << std::endl;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        std::cout << "down" << std::endl;
    }

    //if (e->type == sf::TextE)
    // Drawing all content
    basicDraw(window);
}


void Game::displayFeature(std::string id){
    std::wstring name;
    int attack;
    int defense;
    int health;

    if(id!="yeti" && id!="crapaud" && id!="dragon"){
        name = getCharacter(id)->getName();
        attack = getCharacter(id)->getCaracteristic()->getAttackDamage();
        defense = getCharacter(id)->getCaracteristic()->getArmor();
        health = getCharacter(id)->getCaracteristic()->getHealth();
    }
    else{
        name = getMonster(id)->getName();
        attack = getMonster(id)->getCaracteristic()->getAttackDamage();
        defense = getMonster(id)->getCaracteristic()->getArmor();
        health = getMonster(id)->getCaracteristic()->getHealth();
    }


    //Convert to wstring to display
    std::wstring sAttack = cast::toWstring(attack);
    std::wstring sDefense = cast::toWstring(defense);
    std::wstring sHealth = cast::toWstring(health);

    m_labelNameCharacter.setText(name);
    m_labelAttack.setText(L"Attaque : " + sAttack);
    m_labelDefense.setText(L"Défense : " + sDefense);
    m_labelHealth.setText(L"Santé : " + sHealth);

    m_numero8Mini.setVisible(false);
    m_eldoraMini.setVisible(false);
    m_tristanMini.setVisible(false);
    m_remingtonMini.setVisible(false);
    m_mdjMini.setVisible(false);

    //std::cout << cast::toString(name) << std::endl;

    if (id=="remington")
        m_remingtonMini.setVisible(true);
    if (id=="eldora")
        m_eldoraMini.setVisible(true);
    if (id=="tristan")
        m_tristanMini.setVisible(true);
    if (id=="numero8")
        m_numero8Mini.setVisible(true);
    if (id=="mdj")
        m_mdjMini.setVisible(true);
}

void Game::request(int idRequest, std::string sRequest, std::string sRequest2){
    if (!m_ptr_managerGroup->ptr_networkManager->request(idRequest, sRequest,
                                                         sRequest2)) {
        errorConnection();
    }
}

void Game::receiveRequest() {
    std::vector <sf::Packet> packet = m_ptr_managerGroup->ptr_networkManager->getPacket();

    for(unsigned int i = 0; i < packet.size(); i++) {

        sf::Int32 idRequest;
        packet.at(i) >> idRequest;
        std::string sRequest;
        std::string sRequest2;

        std::cout << "IdRequest " << idRequest << std::endl;
        std::cout << "sRequest " << sRequest << std::endl;

        switch (idRequest) {
            case 7:
                packet.at(i) >> sRequest >> sRequest2;
                m_textChat.empty();
                addTextToChat(sRequest, sRequest2);
            case 8:
                //On change d'ambiance
                //sRequest = nom de l'ambiance (ex : "castle")
                packet.at(i) >> sRequest;
                changeAmbiance(sRequest);
                break;
            case 9:
                packet.at(i) >> sRequest;
                displayMonster(9, sRequest);
                break;
            case 10:
                packet.at(i) >> sRequest;
                displayMonster(10, sRequest);
                break;
            case 11:
                packet.at(i) >> sRequest >> sRequest2;
                monsterAttack(sRequest, sRequest2);
                break;
            case 12:
                packet.at(i) >> sRequest >> sRequest2;
                characterAttack(sRequest, sRequest2);
                break;
            case 13:
                packet.at(i) >> sRequest >> sRequest2;
                monsterSpecialAttack(sRequest, sRequest2);
                break;
            case 14:
                packet.at(i) >> sRequest >> sRequest2;
                characterSpecialAttack(sRequest, sRequest2);
                break;
            case 15:
                packet.at(i) >> sRequest;
                eldoraHealing(sRequest);
                break;
            default:
                std::cout << "GAME : IDRequete non conforme -> " << idRequest << std::endl;
                break;
        }
    }

}

void Game::displayMonster(int i, std::string monster) {
    if(monster=="crapaud"){
        if(i==9){   //cache un monstre
            m_crapaudMonsterButton.setVisible(false);
            hasCrapaud = false;
        }
        if(i==10){     //cache un monstre
            if(selectedMonster=="crapaud")
                selectedMonster="NULL";
            hasCrapaud = true;
            m_crapaudMonsterButton.setVisible(true);
        }
    }
    if(monster=="yeti"){
        if(i==9){   //cache un monstre
            m_yetiMonsterButton.setVisible(false);
            hasYeti = false;
        }
        if(i==10){     //cache un monstre
            if(selectedMonster=="yeti")
                selectedMonster="NULL";
            m_yetiMonsterButton.setVisible(true);
            hasYeti = true;
        }
    }
    if(monster=="dragon"){
        if(i==9){   //cache un monstre
            m_dragonMonsterButton.setVisible(false);
            hasDragon = false;
        }
        if(i==10){     //cache un monstre
            if(selectedMonster=="dragon")
                selectedMonster="NULL";
            m_dragonMonsterButton.setVisible(true);
            hasDragon = true;
        }
    }
}
void Game::changeAmbiance(std::string ambiance){
    if (ambiance=="room"){
        setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Room"));
        isOnCastle=false;
    }
    if(ambiance=="castle"){
        setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Castle"));
        isOnCastle=true;
    }
    if(ambiance=="forest"){
        setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Forest"));
        isOnCastle=false;
    }
    if(ambiance=="landscape"){
        setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Landscape"));
        isOnCastle=false;
    }
    if(ambiance=="beach"){
        setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Beach"));
        isOnCastle=false;
    }


}


void Game::addTextToChat(std::string message, std::string perso){
    std::cout << message << std::endl;
    std::string tmp;
    std::istringstream isstringstream(message);

    while(std::getline(isstringstream, tmp)){
        std::wstring ws(tmp.size(), L' '); // Overestimate number of code points.
        ws.resize(std::mbstowcs(&ws[0], tmp.c_str(), tmp.size()));

        for(unsigned int i = 0; i < m_labelChatVector.size()-1; i++){
            m_labelChatVector.at(i)->setText(m_labelChatVector.at(i+1)->getSText());
            m_labelChatVector.at(i)->setColor(m_labelChatVector.at(i+1)->getColor());
        }
        m_labelChatVector.at(m_labelChatVector.size()-1)->setText(ws);
        if(perso=="eldora")
            m_labelChatVector.at(m_labelChatVector.size()-1)->setColor(sf::Color(218,74,44,255));
        if(perso=="numero8")
            m_labelChatVector.at(m_labelChatVector.size()-1)->setColor(sf::Color(22,134,190,255));
        if(perso=="mdj")
            m_labelChatVector.at(m_labelChatVector.size()-1)->setColor(sf::Color(114,113,113,255));
        if(perso=="remington")
            m_labelChatVector.at(m_labelChatVector.size()-1)->setColor(sf::Color(198,157,103,255));
        if(perso=="tristan")
            m_labelChatVector.at(m_labelChatVector.size()-1)->setColor(sf::Color(55,143,86,255));
    }
}


void Game::eldoraHealing(std::string idCharacter){

    int attackDamage = getCharacter(idCharacter)->getCaracteristic()->getAttackDamage();
    int armor = getCharacter(idCharacter)->getCaracteristic()->getArmor();
    int health = getCharacter(idCharacter)->getCaracteristic()->getHealth();

    getCharacter(idCharacter)->setCaracteristics(
            attackDamage,
            health + 200,
            armor);

    specialAnimation(idCharacter, "eldora");
    displayFeature(idCharacter);
}

//Le perso attaque un monstre
void Game::characterAttack(std::string idCharacter, std::string idMonster) {
    int monsterHealth = getMonster(idMonster)->getCaracteristic()->getHealth();
    int monsterArmor = getMonster(idMonster)->getCaracteristic()->getArmor();
    int monsterAttack = getMonster(idMonster)->getCaracteristic()->getAttackDamage();
    int attack = getCharacter(idCharacter)->getCaracteristic()->getAttackDamage();

    getMonster(idMonster)->setCaracteristics(
            monsterAttack,
            getMonster(idMonster)->hitDamage(attack, monsterHealth),
            monsterArmor);


    attackAnimation(idMonster);
    displayFeature(idMonster);
    monsterHealth = getMonster(idMonster)->getCaracteristic()->getHealth();
    if (monsterHealth<=0){
        displayFeature(m_player->getCharacter()->getId());
        selectedMonster="NULL";
        if (idMonster == "dragon"){
            m_ptr_managerGroup->ptr_gameManager->initDragon();
            m_dragonMonsterButton.setVisible(false);
        }
        if (idMonster == "yeti"){
            m_ptr_managerGroup->ptr_gameManager->initYeti();
            m_yetiMonsterButton.setVisible(false);
        }
        if (idMonster == "crapaud"){
            m_ptr_managerGroup->ptr_gameManager->initCrapaud();
            m_crapaudMonsterButton.setVisible(false);
        }
    }

}

//Le monstre attaque un perso
void Game::monsterAttack(std::string idCharacter, std::string idMonster){

    int attackDamage = getCharacter(idCharacter)->getCaracteristic()->getAttackDamage();
    int armor = getCharacter(idCharacter)->getCaracteristic()->getArmor();
    int health = getCharacter(idCharacter)->getCaracteristic()->getHealth();
    int monsterAttack = getMonster(idMonster)->getCaracteristic()->getAttackDamage();

    getCharacter(idCharacter)->setCaracteristics(
            attackDamage,
            getCharacter(idCharacter)->hitDamage(monsterAttack, health),
            armor);
    attackAnimation(idCharacter);
    displayFeature(idCharacter);
}

void Game::characterSpecialAttack(std::string idCharacter, std::string idMonster) {

    int monsterHealth = getMonster(idMonster)->getCaracteristic()->getHealth();
    int monsterArmor = getMonster(idMonster)->getCaracteristic()->getArmor();
    int monsterAttack = getMonster(idMonster)->getCaracteristic()->getAttackDamage();
    int attack = getCharacter(idCharacter)->getCaracteristic()->getAttackDamage();

    getMonster(idMonster)->setCaracteristics(
            monsterAttack,
            getCharacter(idCharacter)->summonDamage(attack, monsterHealth),
            monsterArmor);

    specialAnimation(idMonster, idCharacter);
    displayFeature(idMonster);
    monsterHealth = getMonster(idMonster)->getCaracteristic()->getHealth();
    if (monsterHealth<=0){
        displayFeature(m_player->getCharacter()->getId());
        selectedMonster="NULL";
        if (idMonster == "dragon"){
            m_ptr_managerGroup->ptr_gameManager->initDragon();
            m_dragonMonsterButton.setVisible(false);
        }
        if (idMonster == "yeti"){
            m_ptr_managerGroup->ptr_gameManager->initYeti();
            m_yetiMonsterButton.setVisible(false);
        }
        if (idMonster == "crapaud"){
            m_ptr_managerGroup->ptr_gameManager->initCrapaud();
            m_crapaudMonsterButton.setVisible(false);
        }
    }
}

void Game::monsterSpecialAttack(std::string idCharacter, std::string idMonster){

    int attackDamage = getCharacter(idCharacter)->getCaracteristic()->getAttackDamage();
    int armor = getCharacter(idCharacter)->getCaracteristic()->getArmor();
    int health = getCharacter(idCharacter)->getCaracteristic()->getHealth();
    int monsterAttack = getMonster(idMonster)->getCaracteristic()->getAttackDamage();

    getCharacter(idCharacter)->setCaracteristics(
            attackDamage,
            getCharacter(idCharacter)->summonDamage(monsterAttack, health),
            armor);

    specialAnimation(idCharacter, "mdj");
    displayFeature(idCharacter);
}

void Game::initPlayerCharacter() {

    //m_ptr_managerGroup->ptr_gameManager->getPlayer()->setCharacter(
    //       m_ptr_managerGroup->ptr_gameManager->getCharacterById("eldora"));


    m_player = m_ptr_managerGroup->ptr_gameManager->getPlayer();
    //addTextToChat("Bonjour meusieur","eldora");

    if(m_player->getCharacter()->getId()=="mdj"){
        isMdj=true;
        m_playerIcon.setSprite(
                m_ptr_managerGroup->ptr_textureManager->getTexture("mdjLock"));
    }
    if(m_player->getCharacter()->getId()=="eldora"){
        isEldora=true;
        m_playerIcon.setSprite(
                m_ptr_managerGroup->ptr_textureManager->getTexture("eldoraLock"));
    }
    if(m_player->getCharacter()->getId()=="tristan"){
        isTristan=true;
        m_playerIcon.setSprite(
                m_ptr_managerGroup->ptr_textureManager->getTexture("tristanLock"));
    }
    if(m_player->getCharacter()->getId()=="numero8"){
        isNumero8=true;
        m_playerIcon.setSprite(
                m_ptr_managerGroup->ptr_textureManager->getTexture("numero8Lock"));
    }
    if(m_player->getCharacter()->getId()=="remington"){
        isRemington=true;
        m_playerIcon.setSprite(
                m_ptr_managerGroup->ptr_textureManager->getTexture("remingtonLock"));
    }
}

void Game::attackAnimation(std::string cible){
    std::cout << "Attaque ! Cible : " << cible << std::endl;
    int x;
    int y;
    if (cible=="eldora"){
        x=720;
        y=210;
    }
    if (cible=="numero8"){
        x=190;
        y=70;
    }
    if (cible=="remington"){
        x=690;
        y=70;
    }
    if (cible=="tristan"){
        x=185;
        y=210;
    }
    if (cible=="yeti"){
        x=625;
        y=175;
    }
    if (cible=="crapaud"){
        x=500;
        y=180;
    }
    if (cible=="dragon"){
        x=335;
        y=200;
    }

    m_attackAnimation.setPosition(x, y);
    m_attackAnimation.setVisible(true);
    m_attackAnimation.play();

}

void Game::specialAnimation(std::string cible, std::string attaquant){
    int x;
    int y;
    if (cible=="eldora"){
        x=720;
        y=210;
    }
    if (cible=="numero8"){
        x=190;
        y=70;
    }
    if (cible=="remington"){
        x=690;
        y=70;
    }
    if (cible=="tristan"){
        x=185;
        y=210;
    }
    if (cible=="yeti"){
        x=625;
        y=175;
    }
    if (cible=="crapaud"){
        x=500;
        y=180;
    }
    if (cible=="dragon"){
        x=335;
        y=200;
    }

    if(attaquant=="eldora"){
        m_eldoraSpecial.setPosition(x, y);
        m_eldoraSpecial.setVisible(true);
        m_eldoraSpecial.play();
    }
    if(attaquant=="tristan"){
        m_tristanSpecial.setPosition(x, y);
        m_tristanSpecial.setVisible(true);
        m_tristanSpecial.play();
    }
    if(attaquant=="remington"){
        m_remingtonSpecial.setPosition(x, y);
        m_remingtonSpecial.setVisible(true);
        m_remingtonSpecial.play();
    }
    if(attaquant=="numero8"){
        m_numero8Special.setPosition(x, y);
        m_numero8Special.setVisible(true);
        m_numero8Special.play();
    }
    if(attaquant=="mdj"){
        m_attackAnimation.setPosition(x, y);
        m_attackAnimation.setVisible(true);
        m_attackAnimation.play();
    }

}

void Game::checkStateAnimation(){
    if(m_attackAnimation.isStopped()){
        m_attackAnimation.setVisible(false);
    }
    if(m_eldoraSpecial.isStopped()){
        m_eldoraSpecial.setVisible(false);
    }
    if(m_remingtonSpecial.isStopped()){
        m_remingtonSpecial.setVisible(false);
    }
    if(m_tristanSpecial.isStopped()){
        m_tristanSpecial.setVisible(false);
    }
    if(m_numero8Special.isStopped()){
        m_numero8Special.setVisible(false);
    }
}

Character * Game::getCharacter(std::string id){
    return m_ptr_managerGroup->ptr_gameManager->getCharacterById(id);
}

Monster * Game::getMonster(std::string id){
    return m_ptr_managerGroup->ptr_gameManager->getMonsterById(id);
}
