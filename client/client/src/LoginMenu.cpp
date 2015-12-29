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
LoginMenu::LoginMenu(ManagerGroup * ptr_managerGroup) : 
BasicInterface(ptr_managerGroup) {
	// TODO
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
sf::Event e, double frameTime) {
	
	// Basic Interface updating
	basicInput(e);
	basicDraw(window);

	// LoginMenu updating
}