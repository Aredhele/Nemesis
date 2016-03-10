//
// Created by Jehan on 05/03/2016.
//

#include "Game.hpp"
Game::Game(bool debug, ManagerGroup * ptr_managerGroup):
        BasicInterface(debug, ptr_managerGroup)

{
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
    m_buttonRemingtonInGame.create("remingtonInGame",730,160,ptr_remingtonInGame, ptr_remingtonInGame);
    getContentPane()->addComponent(&m_buttonRemingtonInGame);

	//Eldora
    ptr_eldoraInGame = ptr_managerGroup->ptr_textureManager->getTexture("eldoraInGame");
    ptr_eldoraInGame->setSmooth(true);
    m_buttonEldoraInGame.create("eldoraInGame",780,265,ptr_eldoraInGame, ptr_eldoraInGame);
    getContentPane()->addComponent(&m_buttonEldoraInGame);

    //Numero 8
    ptr_numero8InGame = ptr_managerGroup->ptr_textureManager->getTexture("numero8InGame");
    ptr_numero8InGame->setSmooth(true);
    m_buttonNumero8InGame.create("numero8InGame",250,170,ptr_numero8InGame, ptr_numero8InGame);
    getContentPane()->addComponent(&m_buttonNumero8InGame);

    //Tristan
    ptr_tristanInGame = ptr_managerGroup->ptr_textureManager->getTexture("tristanInGame");
    ptr_tristanInGame->setSmooth(true);
    m_buttonTristanInGame.create("tristanInGame",210,270,ptr_tristanInGame, ptr_tristanInGame);
    getContentPane()->addComponent(&m_buttonTristanInGame);

    //Text Box Chat

    m_textFieldLogin.create("textFieldLogin", 5, 690,
                            ptr_managerGroup->ptr_textureManager->getTexture("chatTextBox"),
                            ptr_managerGroup->ptr_textureManager->getTexture("textBoxCursorChat"),
                            &m_fontTextbox,
                            15, 0.5, "", 70, sf::Color(196,130,56));
    //Panel Chat
    m_panelChat.create("chatPanel", 5, 510,
                       ptr_managerGroup->ptr_textureManager->getTexture("chatPanel"));



    m_panelCharateristics.create("charateristicsPanel", 824, 518,
                                    ptr_managerGroup->ptr_textureManager->getTexture("charateristicsPanel"));
    m_panelNameCharacter.create("nameCharacterPanel",824, 518,
                                    ptr_managerGroup->ptr_textureManager->getTexture("statPanel"));
    m_panelAttack.create("attackPanel",824, 573,
                                    ptr_managerGroup->ptr_textureManager->getTexture("statPanel"));
    m_panelDefense.create("defensePanel", 824, 628,
                                    ptr_managerGroup->ptr_textureManager->getTexture("statPanel"));
    m_panelHealth.create("healthPanel", 824, 683,
                                    ptr_managerGroup->ptr_textureManager->getTexture("statPanel"));

    m_panelIconAttack.create("attackIcon", 824,573,
                                    ptr_managerGroup->ptr_textureManager->getTexture("IconAttack"));

    m_panelIconDefense.create("defenseIcon", 824,628,
                                    ptr_managerGroup->ptr_textureManager->getTexture("IconDefense"));

    m_panelIconHealth.create("healthIcon", 827,686,
                                    ptr_managerGroup->ptr_textureManager->getTexture("IconHealth"));


    m_labelNameCharacter.create("labelNameCharacter", 830, 535, 15, &m_fontLabel, L"", sf::Color::Black);
    m_labelAttack.create("labelAttack", 880, 590, 15, &m_fontLabel, L"", sf::Color::Black);
    m_labelDefense.create("labelDefense", 880, 645, 15, &m_fontLabel, L"", sf::Color::Black);
    m_labelHealth.create("labelHealth", 880, 700, 15, &m_fontLabel, L"", sf::Color::Black);

    std::wstring currentPlayerName = m_ptr_managerGroup->ptr_gameManager->getPlayer()->getCharacter()->getName();
    std::wstring currentPlayerAttack = m_ptr_managerGroup->ptr_gameManager->getPlayer()->getCharacter()->getCaracteristic()->getAttackDamage();
    std::wstring currentPlayerDefense = m_ptr_managerGroup->ptr_gameManager->getPlayer()->getCharacter()->getCaracteristic()->getArmor();
    std::wstring currentPlayerHealth = m_ptr_managerGroup->ptr_gameManager->getPlayer()->getCharacter()->getCaracteristic()->getHealth();


    m_labelNameCharacter.setText(currentPlayerName);
    m_labelAttack.setText(currentPlayerAttack);
    m_labelDefense.setText(currentPlayerDefense);
    m_labelHealth.setText(currentPlayerHealth);

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
    getContentPane()->addComponent(&m_panelCharateristics);
    getContentPane()->addComponent(&m_textFieldLogin);
    getContentPane()->addComponent(&m_panelChat);



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

    
    // Drawing all content
    basicDraw(window);

}

