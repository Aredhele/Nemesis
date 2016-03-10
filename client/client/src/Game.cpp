//
// Created by Jehan on 05/03/2016.
//

#include "Game.hpp"
Game::Game(bool debug, ManagerGroup * ptr_managerGroup):
        BasicInterface(debug, ptr_managerGroup)

{
    firstConnect = true;
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


    //Panel UI du MJ
    ptr_launchGame = ptr_managerGroup->ptr_textureManager->getTexture("playButton_1");
    ptr_launchGame->setSmooth(true);
    m_launchGameButton.create("playButton_1", 450, 500, ptr_launchGame, ptr_launchGame);

    m_panelMJ.create("MJPanel", 2000, 2000,ptr_managerGroup->ptr_textureManager->getTexture("IconHealth"));

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
    getContentPane()->addComponent(&m_panelCharateristics);
    getContentPane()->addComponent(&m_textFieldLogin);
    getContentPane()->addComponent(&m_panelChat);
    getContentPane()->addComponent(&m_panelMJ);  




    ptr_buttonHit = ptr_managerGroup->ptr_textureManager->getTexture("buttonHit");
    ptr_buttonHit->setSmooth(true);
    m_buttonHit.create("buttonHit", 487, 620, ptr_buttonHit, ptr_buttonHit);
    getContentPane()->addComponent(&m_buttonHit);

    ptr_buttonSummon = ptr_managerGroup->ptr_textureManager->getTexture("buttonSummon");
    ptr_buttonSummon->setSmooth(true);
    m_buttonSummon.create("buttonSummon", 487, 550, ptr_buttonSummon, ptr_buttonSummon);
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
        }
       firstConnect = false;
    }

    // Basic Interface updating
    basicInput(e, frameTime);

    //Evenement sur les panneaux des joueurs
    if(m_inputHandler.getComponentId() == "remingtonInGame") {

        std::wstring remingtonName = m_ptr_managerGroup->ptr_gameManager->getCharacterById("remington")->getName();
        std::wstring remingtonAttack = m_ptr_managerGroup->ptr_gameManager->getCharacterById("remington")->getCaracteristic()->getAttackDamage();
        std::wstring remingtonDefense = m_ptr_managerGroup->ptr_gameManager->getCharacterById("remington")->getCaracteristic()->getArmor();
        std::wstring remingtonHealth = m_ptr_managerGroup->ptr_gameManager->getCharacterById("remington")->getCaracteristic()->getHealth();

        m_labelNameCharacter.setText(remingtonName);
        m_labelAttack.setText(remingtonAttack);
        m_labelDefense.setText(remingtonDefense);
        m_labelHealth.setText(remingtonHealth);

    }else if(m_inputHandler.getComponentId() == "eldoraInGame"){


        std::wstring eldoraName = m_ptr_managerGroup->ptr_gameManager->getCharacterById("eldora")->getName();
        std::wstring eldoraAttack = m_ptr_managerGroup->ptr_gameManager->getCharacterById("eldora")->getCaracteristic()->getAttackDamage();
        std::wstring eldoraDefense = m_ptr_managerGroup->ptr_gameManager->getCharacterById("eldora")->getCaracteristic()->getArmor();
        std::wstring eldoraHealth = m_ptr_managerGroup->ptr_gameManager->getCharacterById("eldora")->getCaracteristic()->getHealth();

        m_labelNameCharacter.setText(eldoraName);
        m_labelAttack.setText(eldoraAttack);
        m_labelDefense.setText(eldoraDefense);
        m_labelHealth.setText(eldoraHealth);

    }else if(m_inputHandler.getComponentId() == "numero8InGame"){


        std::wstring numero8Name = m_ptr_managerGroup->ptr_gameManager->getCharacterById("numero8")->getName();
        std::wstring numero8Attack = m_ptr_managerGroup->ptr_gameManager->getCharacterById("numero8")->getCaracteristic()->getAttackDamage();
        std::wstring numero8Defense = m_ptr_managerGroup->ptr_gameManager->getCharacterById("numero8")->getCaracteristic()->getArmor();
        std::wstring numero8Health = m_ptr_managerGroup->ptr_gameManager->getCharacterById("numero8")->getCaracteristic()->getHealth();

        m_labelNameCharacter.setText(numero8Name);
        m_labelAttack.setText(numero8Attack);
        m_labelDefense.setText(numero8Defense);
        m_labelHealth.setText(numero8Health);

    }else if(m_inputHandler.getComponentId() == "tristanInGame"){

        std::wstring tristanName = m_ptr_managerGroup->ptr_gameManager->getCharacterById("tristan")->getName();
        std::wstring tristanAttack = m_ptr_managerGroup->ptr_gameManager->getCharacterById("tristan")->getCaracteristic()->getAttackDamage();
        std::wstring tristanDefense = m_ptr_managerGroup->ptr_gameManager->getCharacterById("tristan")->getCaracteristic()->getArmor();
        std::wstring tristanHealth = m_ptr_managerGroup->ptr_gameManager->getCharacterById("tristan")->getCaracteristic()->getHealth();

        m_labelNameCharacter.setText(tristanName);
        m_labelAttack.setText(tristanAttack);
        m_labelDefense.setText(tristanDefense);
        m_labelHealth.setText(tristanHealth);
    }

    //if (e->type == sf::TextE)
    // Drawing all content
    basicDraw(window);

}

