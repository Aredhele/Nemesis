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
m_monSuperBouton()
{
	ptr_managerGroup->ptr_musicManager->
		createPlaylist("playlistMenu", 50, true, 1.2);
	ptr_managerGroup->ptr_musicManager->
		getPlaylist("playlistMenu")->addMusic("../res/music/menu/LifeWater.ogg");
	ptr_managerGroup->ptr_musicManager->
		getPlaylist("playlistMenu")->play();

    

	m_monSuperPanel.create("monSuperPanel", 100, 100, 
		ptr_managerGroup->ptr_textureManager->getTexture("simplePanel"));

	m_maSuperAnimation.create("maSuperAnimation", 110, 110, 
		ptr_managerGroup->ptr_textureManager->getTexture("altimitLoad"),
		true, 0.05, 30, 35, 7);

	m_monSuperBouton.create("monSuperBouton", 300, 300, 
		ptr_managerGroup->ptr_textureManager->getTexture("topBarOptButton_3"),
		ptr_managerGroup->ptr_textureManager->getTexture("topBarOptButton_4"));

	m_monSuperPanel.addComponent(&m_maSuperAnimation);
	m_monSuperPanel.addComponent(&m_monSuperBouton);
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

	// LoginMenu updating
	m_inputHandler.handleInput(e, getContentPane());

	if(m_inputHandler.getComponentId() == "monSuperBouton")
		std::cout << "BOUTONNN EVENTTT" << std::endl;
	

	// Drawing all content
	basicDraw(window);
}
