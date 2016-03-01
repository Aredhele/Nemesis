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
		m_monSuperBouton(),
		m_titleLabel(),
		m_connectionErrorLabel(),
		m_pseudoErrorLabel(),
		m_textFieldLogin(),
		m_nemesisLogo(),
		m_errorPanel()
{
	ptr_managerGroup->ptr_musicManager->
			createPlaylist("playlistMenu", true, 1.2);
	ptr_managerGroup->ptr_musicManager->
			getPlaylist("playlistMenu")->addMusic("../res/music/menu/Epipath.ogg");
	ptr_managerGroup->ptr_musicManager->
			getPlaylist("playlistMenu")->play();

	if (!m_fontLabel.loadFromFile("../res/font/Quicksand.ttf") || !m_fontTextbox.loadFromFile("../res/font/LucidaTypewriterRegular.ttf"))
	{
		std::cout << "Probleme dans le chargement des textures" << std::endl;
	}

	m_monSuperBouton.create("connectButton", 421, 605,
							ptr_managerGroup->ptr_textureManager->getTexture("connectButton1"),
							ptr_managerGroup->ptr_textureManager->getTexture("connectButton2"));



	m_titleLabel.create("monSuperLabel", 10, 10, 20, &m_fontLabel, L"Paper Sword : Online", sf::Color::Black);

	m_connectionErrorLabel.create("connectionErrorLabel", 330, 665, 20, &m_fontLabel,
								  L"Un problème de connexion est survenue.\n"
										    "  Vérifiez votre connnexion et réessayez.",
								  sf::Color(181, 51, 0));

	m_pseudoErrorLabel.create("pseudoErrorLabel", 345, 665, 20, &m_fontLabel,
							  L"  Vous n'avez pas saisi votre pseudo.\n"
									  "Saississiez votre pseudo et réessayez.",
								  sf::Color(181, 51, 0));

    m_textFieldLogin.create("textFieldLogin", 420, 555,
                            ptr_managerGroup->ptr_textureManager->getTexture("textBox"),
                            ptr_managerGroup->ptr_textureManager->getTexture("textBoxCursor"),
                            &m_fontTextbox,
                       15, 0.5, "Votre pseudo", 15, sf::Color::Black);

	m_nemesisLogo.create("nemesisLogo", 367, 59,
						 ptr_managerGroup->ptr_textureManager->getTexture("nemesis"));

	m_errorPanel.create("ErrorPanel", 303, 660,
						ptr_managerGroup->ptr_textureManager->getTexture("errorPanel"));

	m_errorPanel.addComponent(&m_pseudoErrorLabel);
	m_errorPanel.addComponent(&m_connectionErrorLabel);

	m_pseudoErrorLabel.setVisible(false);
	m_connectionErrorLabel.setVisible(false);
	m_errorPanel.setVisible(false);

	getContentPane()->addComponent(&m_nemesisLogo);
	getContentPane()->addComponent(&m_textFieldLogin);
	getContentPane()->addComponent(&m_titleLabel);
	getContentPane()->addComponent(&m_errorPanel);
	getContentPane()->addComponent(&m_monSuperBouton);

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


	if(m_inputHandler.getComponentId() == "connectButton") {
		if(m_textFieldLogin.getString() != ""){
			if(m_ptr_managerGroup->ptr_networkManager->connect())
				m_ptr_managerGroup->ptr_targetManager->isOnLobby();
			else{
				m_pseudoErrorLabel.setVisible(false);
				m_connectionErrorLabel.setVisible(true);
				m_errorPanel.setVisible(true);
				std::cout << "Error connection" << std::endl;
			}
		}
		else {
			m_pseudoErrorLabel.setVisible(true);
			m_connectionErrorLabel.setVisible(false);
			m_errorPanel.setVisible(true);
			std::cout << "Saisir pseudo !" << std::endl;
		}



	}



	// Drawing all content
	basicDraw(window);
}
