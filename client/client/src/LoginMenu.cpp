/*!
 * \file LoginMenu.cpp
 * \brief Handle connection
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#include "LoginMenu.hpp"

/*!
 * \brief Constructor
 */
LoginMenu::LoginMenu(bool debug, ManagerGroup * ptr_managerGroup) :
		BasicInterface(debug, ptr_managerGroup),
		m_connectButton(),
		m_titleLabel(),
		m_textFieldLogin(),
		m_nemesisLogo(),
		m_bibouPanel(),
		m_loading(),
		m_paperSwordTitlePanel()
{
	noError();
	m_smallTitleLogo.setVisible(false);
	ptr_managerGroup->ptr_musicManager->
			createPlaylist("playlistMenu", true, 1.2);
	ptr_managerGroup->ptr_musicManager->
			getPlaylist("playlistMenu")->addMusic("../res/music/menu/Epipath.ogg");
	ptr_managerGroup->ptr_musicManager->
			getPlaylist("playlistMenu")->play();

	if (!m_fontLabel.loadFromFile("../res/font/Quicksand.ttf") || !m_fontTextbox.loadFromFile("../res/font/LucidaTypewriterRegular.ttf"))
	{
		std::cerr << "Probleme dans le chargement des fonts" << std::endl;
	}

	m_connectButton.create("connectButton", 442, 570,
							ptr_managerGroup->ptr_textureManager->getTexture("connectButton1"),
							ptr_managerGroup->ptr_textureManager->getTexture("connectButton2"));



	//m_loading.create("loading", 488,695,
	//				 ptr_managerGroup->ptr_textureManager->getTexture("loading"),
	//			 true, 0.1, 49,  49, 8);

	//m_loading.setVisible(false);
	//getContentPane()->addComponent(&m_loading);
	//m_loading.start();

	m_bibouPanel.create("bibouPanel", 0, 400,
						ptr_managerGroup->ptr_textureManager->getTexture("bibouPanel"));


    m_textFieldLogin.create("textFieldLogin", 412, 500,
                            ptr_managerGroup->ptr_textureManager->getTexture("textBox"),
                            ptr_managerGroup->ptr_textureManager->getTexture("textBoxCursor"),
                            &m_fontTextbox,
                       15, 0.5, "Votre pseudo", 15, sf::Color(196,130,56));

	m_paperSwordTitlePanel.create("paperSwordTitlePanel", 309, 50,
						 ptr_managerGroup->ptr_textureManager->getTexture("paperSwordTitlePanel"));

    getContentPane()->addComponent(&m_bibouPanel);
	getContentPane()->addComponent(&m_paperSwordTitlePanel);
	getContentPane()->addComponent(&m_textFieldLogin);

	getContentPane()->addComponent(&m_connectButton);

}

/*!
 * \brief Constructor
 */
LoginMenu::~LoginMenu() {
	// TODO
}

/*!
 * \brief Update current object
 * \param window The pointer on the window
 * \param frameTime The elpased time
 */
void LoginMenu::update(sf::RenderWindow * window,
					   sf::Event * e, double frameTime) {

	if(!m_ptr_managerGroup->ptr_targetManager->isLoginMenu())
		return;

	// Basic Interface updating
	basicInput(e, frameTime);

	if(m_inputHandler.getComponentId() == "connectButton" || sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        //m_loading.setVisible(true);
		tryConnection();
	}


	// Drawing all content
	basicDraw(window);
}

void LoginMenu::tryConnection(){
	//;
	//m_errorPanel.setVisible(false);
	if(m_textFieldLogin.getString() != "") {

		if (m_ptr_managerGroup->ptr_networkManager->connect()) {
			m_ptr_managerGroup->ptr_networkManager->startThread();
			m_ptr_managerGroup->ptr_gameManager->getPlayer()->setName(m_textFieldLogin.getString());
			//m_loading.setVisible(false);
			m_smallTitleLogo.setVisible(true);
			m_ptr_managerGroup->ptr_targetManager->isOnLobby();
		}
		else{
			//m_loading.setVisible(false);
			errorConnection();
		}
	}
	else {
		errorPseudo();
	}
}
