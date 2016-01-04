/*!
 * \file BasicInterface.cpp
 * \brief Super class for interface
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#include "BasicInterface.hpp"

/*!
 * \brief Constructor
 * \param ptr_managerGroup
 */
BasicInterface::BasicInterface(ManagerGroup * ptr_managerGroup) : 
Updatable(),
m_topBar("topBar")
{
	m_ptr_managerGroup = ptr_managerGroup;

	// Setting up aliases
	TextureManager& a_tm = *ptr_managerGroup->ptr_textureManager;
	MusicManager& a_mm = *ptr_managerGroup->ptr_musicManager;

	// Adding top-bar
	m_topBar.setSprite(a_tm.getTexture("topBarLogMenu"));
	m_topBar.setPosition(0, 0);
	m_vObjectList.push_back(&m_topBar);
}

/*!
 * \brief Destructor
 */
BasicInterface::~BasicInterface() {
	// None
}

/*!
 * \brief Draw all object on the window
 * \param window The surface to draw
 * \param visualObjectList The list of object to draw
 */
void BasicInterface::basicDraw(sf::RenderWindow * window) {

	// Polymorphisme !
	for(unsigned int i = 0; i < m_vObjectList.size(); i++)
		m_vObjectList[i]->draw(window);
}

/*!
 * \brief Handle inputs of the basics interface
 * \param e The current event to handle
 */
void BasicInterface::basicInput(sf::Event e) {
	// TODO
}