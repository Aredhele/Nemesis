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
    firstConnect = true;
    m_isOnMonstrePanel = false;
    m_isOnAmbiancePanel = false;
    isSpecial = false;
    isHitting = false;
    //Background
    setBackground(ptr_managerGroup->ptr_textureManager->getTexture("background_Castle"));

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
                      15, 0.5, "", 104, sf::Color(196,130,56));
    m_textChat.setTextPosition(7, 678);
    m_textChat.setCursorPosition(7, 680);

    //Panel Chat
    m_panelChat.create("chatPanel", 5, 495,
                       ptr_managerGroup->ptr_textureManager->getTexture("chatPanel"));

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



    m_yetiPanel.create("yetiPanel", 650,190,  ptr_managerGroup->ptr_textureManager->getTexture("Yeti"));
    m_yetiPanel.setVisible(false);
    getContentPane()->addComponent(&m_yetiPanel);

    m_dragonPanel.create("dragonPanel", 350,210,  ptr_managerGroup->ptr_textureManager->getTexture("Dragon"));
    m_dragonPanel.setVisible(false);
    getContentPane()->addComponent(&m_dragonPanel);

    m_crapaudPanel.create("crapaudPanel", 520,200,  ptr_managerGroup->ptr_textureManager->getTexture("Crapaud"));
    m_crapaudPanel.setVisible(false);
    getContentPane()->addComponent(&m_crapaudPanel);

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

        initPlayerCharacter();
        //TODO : régler ce problème de Label qui ne s'affiche pas


        std::wstring name = m_player->getCharacter()->getName();
        int attack = m_player->getCharacter()->getCaracteristic()->getAttackDamage();
        int defense = m_player->getCharacter()->getCaracteristic()->getArmor();
        int health = m_player->getCharacter()->getCaracteristic()->getHealth();

        //Convert to wstring to display
        std::wstring sAttack = cast::intToWstring(attack);
        std::wstring sDefense = cast::intToWstring(defense);
        std::wstring sHealth = cast::intToWstring(health);

        //std::cout << cast::toString(currentPlayerName) << std::endl;

        m_labelNameCharacter.setText(name);
        m_labelAttack.setText(L"Attaque : " + sAttack);
        m_labelDefense.setText(L"Défense : " + sDefense);
        m_labelHealth.setText(L"Santé : " + sHealth);


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

    // Basic Interface updating
    basicInput(e, frameTime);

    //Evenement sur les panneaux des joueurs
    if(m_inputHandler.getComponentId() == "remingtonInGame") {

        if (isSpecial && isEldora)
        {
            summonEldoraHealing("remington", 1500);
            isSpecial = false;
        }
        else if(isSpecial && isMdj){

            monsterSummons("remington", selectedMonster);
            isSpecial = false;
        }
        else if(isHitting
                && isMdj
                && getMonster(selectedMonster)->isMonsterSelected()){

            monsterHits("remington" , selectedMonster);
            isHitting = false;

        }else{

            displayFeature("remington");
        }

    }
    if(m_inputHandler.getComponentId() == "eldoraInGame"){

        if (isSpecial && isEldora)
        {
            summonEldoraHealing("eldora", 5000);
            isSpecial = false;
        }
        else if(isSpecial && isMdj){

            monsterSummons("eldora", selectedMonster);
            isSpecial = false;
        }
        else if(isHitting
                && isMdj
                && getMonster(selectedMonster)->isMonsterSelected()){

            monsterHits("eldora" , selectedMonster);
            isHitting = false;

        }else{

            displayFeature("eldora");
        }

    }
    if(m_inputHandler.getComponentId() == "numero8InGame"){

        if (isSpecial && isEldora)
        {
            summonEldoraHealing("numero8", 3000);
            isSpecial = false;
        }
        else if(isSpecial && isMdj){

            monsterSummons("numero8", selectedMonster);
            isSpecial = false;
        }
        else if(isHitting
                && isMdj
                && getMonster(selectedMonster)->isMonsterSelected()){

            monsterHits("numero8" , selectedMonster);
            isHitting = false;

        }else{

            displayFeature("numero8");
        }
    }
    if(m_inputHandler.getComponentId() == "tristanInGame"){

        if (isSpecial && isEldora)
        {
            summonEldoraHealing("tristan", 3000);
            isSpecial = false;
        }
        else if(isSpecial && isMdj){

            monsterSummons("tristan", selectedMonster);
            isSpecial = false;
        }
        else if(isHitting
                && isMdj
                && getMonster(selectedMonster)->isMonsterSelected()){

            monsterHits("tristan" , selectedMonster);
            isHitting = false;

        }else{

            displayFeature("tristan");
        }
    }
    if(m_inputHandler.getComponentId() == "mdjInGame"){

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
        setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Beach"));
        isOnCastle = false;
        m_panelAmbianceMJ.setVisible(false);
        m_monsterButton.setVisible(true);
        m_isOnAmbiancePanel = false;
    }
    if(m_inputHandler.getComponentId() == "castleButton"){
        setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("background_Castle"));
        isOnCastle = true;
        m_panelAmbianceMJ.setVisible(false);
        m_monsterButton.setVisible(true);
        m_isOnAmbiancePanel = false;
    }
    if(m_inputHandler.getComponentId() == "forestButton"){
        setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Forest"));
        isOnCastle = false;
        m_panelAmbianceMJ.setVisible(false);
        m_monsterButton.setVisible(true);
        m_isOnAmbiancePanel = false;
    }
    if(m_inputHandler.getComponentId() == "landButton"){
        setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Landscape"));
        isOnCastle = false;
        m_panelAmbianceMJ.setVisible(false);
        m_monsterButton.setVisible(true);
        m_isOnAmbiancePanel = false;
    }
    if(m_inputHandler.getComponentId() == "roomButton"){
        setBackground(m_ptr_managerGroup->ptr_textureManager->getTexture("Background_Room"));
        isOnCastle = false;
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


    if(m_inputHandler.getComponentId() == "crapaudButton"){
        //TODO : Envoyer une requete et afficher seulement à la réponse
        if (hasCrapaud){
            m_crapaudPanel.setVisible(false);
            hasCrapaud = false;
        }else{
            m_crapaudPanel.setVisible(true);
            hasCrapaud = true;

        }

        m_isOnMonstrePanel = false;
        m_ambianceButton.setVisible(true);
        m_panelMonstresMJ.setVisible(false);

        selectedMonster = "crapaud"; //a Monster is selected
        getMonster(selectedMonster)->selectMonster();

    }
    if(m_inputHandler.getComponentId() == "dragonButton"){
        //TODO : Envoyer une requete et afficher seulement à la réponse

        if (hasDragon){
            m_dragonPanel.setVisible(false);
            hasDragon = false;
        }else{
            m_dragonPanel.setVisible(true);
            hasDragon = true;

        }
        m_isOnMonstrePanel = false;
        m_ambianceButton.setVisible(true);
        m_panelMonstresMJ.setVisible(false);

        selectedMonster = "dragon"; //a Monster is selected
        getMonster(selectedMonster)->selectMonster();

    }
    if(m_inputHandler.getComponentId() == "yetiButton"){
        //TODO : Envoyer une requete et afficher seulement à la réponse

        if (hasYeti){
            m_yetiPanel.setVisible(false);
            hasYeti = false;
        }else{
            m_yetiPanel.setVisible(true);
            hasYeti = true;
        }
        m_isOnMonstrePanel = false;
        m_ambianceButton.setVisible(true);
        m_panelMonstresMJ.setVisible(false);

        selectedMonster = "yeti"; //a Monster is selected
        getMonster(selectedMonster)->selectMonster();
    }


    //we can hit with normal or special attack
    if (m_inputHandler.getComponentId() == "buttonHit"){

        isSpecial = false;
        isHitting = true;

    }else if(m_inputHandler.getComponentId() == "buttonSummon"){

        isHitting = false;
        isSpecial = true;
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        std::string text = m_textChat.getString();
        std::cout << text << std::endl;
        //TODO : vider le m_textChat
        m_textChat.empty();
        //TODO : envoyer le texte saisie au serveur
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
    //std::string i = m_ptr_managerGroup->ptr_gameManager->getCharacterById(id)->getId();
    std::wstring name = getCharacter(id)->getName();
    int attack = getCharacter(id)->getCaracteristic()->getAttackDamage();
    int defense = getCharacter(id)->getCaracteristic()->getArmor();
    int health = getCharacter(id)->getCaracteristic()->getHealth();

    //Convert to wstring to display
    std::wstring sAttack = cast::intToWstring(attack);
    std::wstring sDefense = cast::intToWstring(defense);
    std::wstring sHealth = cast::intToWstring(health);

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
            case 8:

                break;
            case 9:

                break;
            case 10:

                break;
            case 11:

                break;
            case 12:

                break;
            default:
                std::cout << "GAME : IDRequete non conforme -> " << idRequest << std::endl;
                break;
        }
    }

}

void Game::addTextToChat(std::string message){
    //TODO
}


void Game::summonEldoraHealing(std::string character, int maxPV){

    int attackDamage = getCharacter(character)->getCaracteristic()->getAttackDamage();
    int armor = getCharacter(character)->getCaracteristic()->getArmor();
    int health = getCharacter(character)->getCaracteristic()->getHealth();

    getCharacter(character)->setCaracteristics(
            attackDamage,
            health + 200,
            armor);

    health = getCharacter(character)->getCaracteristic()->getHealth();
    attackDamage = getCharacter(character)->getCaracteristic()->getAttackDamage();
    armor = getCharacter(character)->getCaracteristic()->getArmor();

    if (health > maxPV)
    {
        std::cout << "MAX PV" << std::endl;
        m_ptr_managerGroup->ptr_gameManager->getCharacterById(character)->setCaracteristics(
                attackDamage,
                1500,
                armor);
    }

    displayFeature(character);

    isSpecial = false;
}

void Game::characterHits(std::string monster){

    int monsterHealth = getMonster(monster)->getCaracteristic()->getHealth();
    int monsterArmor = getMonster(monster)->getCaracteristic()->getArmor();
    int monsterAttack = getMonster(monster)->getCaracteristic()->getAttackDamage();
    int attack = m_player->getCharacter()->getCaracteristic()->getAttackDamage();

    getMonster(monster)->setCaracteristics(
            monsterAttack,
            m_player->getCharacter()->hitDamage(attack, monsterHealth),
            monsterArmor);
}

void Game::monsterHits(std::string character, std::string monster){

    int attackDamage = getCharacter(character)->getCaracteristic()->getAttackDamage();
    int armor = getCharacter(character)->getCaracteristic()->getArmor();
    int health = getCharacter(character)->getCaracteristic()->getHealth();
    int monsterAttack = getMonster(monster)->getCaracteristic()->getAttackDamage();


    getCharacter(character)->setCaracteristics(
            attackDamage,
            getCharacter(character)->hitDamage(monsterAttack, health),
            armor);

    displayFeature(character);
}

void Game::characterSummons(std::string monster){

    int monsterHealth = getMonster(monster)->getCaracteristic()->getHealth();
    int monsterArmor = getMonster(monster)->getCaracteristic()->getArmor();
    int monsterAttack = getMonster(monster)->getCaracteristic()->getAttackDamage();
    int attack = m_player->getCharacter()->getCaracteristic()->getAttackDamage();

    getMonster(monster)->setCaracteristics(
            monsterAttack,
            m_player->getCharacter()->summonDamage(attack, monsterHealth),
            monsterArmor);

}

void Game::monsterSummons(std::string character, std::string monster){

    int attackDamage = getCharacter(character)->getCaracteristic()->getAttackDamage();
    int armor = getCharacter(character)->getCaracteristic()->getArmor();
    int health = getCharacter(character)->getCaracteristic()->getHealth();
    int monsterAttack = getMonster(monster)->getCaracteristic()->getAttackDamage();

    getCharacter(character)->setCaracteristics(
            attackDamage,
            getCharacter(character)->summonDamage(monsterAttack, health),
            armor);

    displayFeature(character);
}

void Game::initPlayerCharacter() {
    m_player = m_ptr_managerGroup->ptr_gameManager->getPlayer();

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

    isMdj=true;
}

Character * Game::getCharacter(std::string id){
    return m_ptr_managerGroup->ptr_gameManager->getCharacterById(id);
}

Monster * Game::getMonster(std::string id){
    return m_ptr_managerGroup->ptr_gameManager->getMonsterById(id);
}
