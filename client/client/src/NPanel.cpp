/*!
 * \file NPanel.cpp
 * \brief Panel container
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#include "NPanel.hpp"

/*!
 * \brief Constructor
 * \return None
 */
NPanel::NPanel() :
VisualObject() {
	// None
}

/*!
 * \brief Destructor
 */
NPanel::~NPanel() {
	// None
}

/*!
 * \brief Init methode
 * \param id The id of the object
 * \param x The x abs position of the sprite
 * \param y The y abs position of the sprite
 * \param texture The texture of the main sprite
 */
void NPanel::create(std::string id, int x, int y, 
sf::Texture * texture) {

	// Call super method
	init(id, x, y, texture);
}

/*!
 * \brief Draw all object in the panel
 * \param window The pointer on window
 */
void NPanel::draw(sf::RenderWindow * window) {
	
	if(m_hidden) return;

	window->draw(m_mainSprite);

	for(unsigned int i = 0; i < m_vObjectList.size(); i++)
		m_vObjectList[i]->draw(window);
}

/*!
 * \brief Add a visual object the to panel
 * \param component The pointer on the object
 */
void NPanel::addComponent(VisualObject * component) {
	m_vObjectList.push_back(component);
}

/*!
 * \brief Remove the last component
 */
void NPanel::removeLastComponent() {
	m_vObjectList.pop_back();
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NPanel::eventMousePressed(sf::Event * e) {

	std::string id = "NULL";

	if(m_hidden) return id;

	for(unsigned int i = 0; i < m_vObjectList.size(); i++) {
		id = m_vObjectList[i]->eventMousePressed(e);
		if(id != "NULL")
			break;
	}

	return id;

}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NPanel::eventMouseMoved(sf::Event * e) {

	std::string id = "NULL";

	if(m_hidden) return id;

	for(unsigned int i = 0; i < m_vObjectList.size(); i++) {
		id = m_vObjectList[i]->eventMouseMoved(e);
		if(id != "NULL")
			break;
	}

	return id;

}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
void NPanel::eventTextEntered(sf::Event * e) {

	if(m_hidden) return;

	for(unsigned int i = 0; i < m_vObjectList.size(); i++)
		m_vObjectList[i]->eventTextEntered(e);
}

/*! 
 * \brief Update all component
 * \param frameTime The time elapsed since last frame
 */
void NPanel::update(double frameTime) {

	for(unsigned int i = 0; i < m_vObjectList.size(); i++)
		m_vObjectList[i]->update(frameTime);
}