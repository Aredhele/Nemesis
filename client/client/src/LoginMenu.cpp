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
m_monSuperPanel(),
m_maSuperAnimation(),
m_monSuperBouton(),
m_monSuperLabel()
{
	ptr_managerGroup->ptr_musicManager->
		createPlaylist("playlistMenu", 50, true, 1.2);
	ptr_managerGroup->ptr_musicManager->
		getPlaylist("playlistMenu")->addMusic("../res/music/menu/Epipath.ogg");
	ptr_managerGroup->ptr_musicManager->
		getPlaylist("playlistMenu")->play();

	if (!m_font.loadFromFile("../res/font/Quicksand.ttf"))
	{
		std::cout << "Probleme dans le chargement des textures" << std::endl;
	}
    

	m_monSuperPanel.create("monSuperPanel", 100, 100, 
		ptr_managerGroup->ptr_textureManager->getTexture("simplePanel"));

	m_maSuperAnimation.create("maSuperAnimation", 110, 110, 
		ptr_managerGroup->ptr_textureManager->getTexture("altimitLoad"),
		true, 0.05, 30, 35, 7);

	m_monSuperBouton.create("monSuperBouton", 300, 300, 
		ptr_managerGroup->ptr_textureManager->getTexture("topBarOptButton_3"),
		ptr_managerGroup->ptr_textureManager->getTexture("topBarOptButton_4"));



	m_monSuperLabel.create("monSuperLabel", 10, 10, 20, &m_font, L"Paper Sword : Online", sf::Color::Black);


	m_monSuperPanel.addComponent(&m_maSuperAnimation);
	m_monSuperPanel.addComponent(&m_monSuperBouton);
	m_monSuperPanel.addComponent(&m_monSuperLabel);
	getContentPane()->addComponent(&m_monSuperPanel);
	
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


	if(m_inputHandler.getComponentId() == "monSuperBouton")
		std::cout << "BOUTONNN EVENTTT" << std::endl;
	

	// Drawing all content
	basicDraw(window);
}
