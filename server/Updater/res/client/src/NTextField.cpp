/*!
 * \file NTextField.cpp
 * \brief A text field can contain at most one line
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#include "NTextField.hpp"

/*!
 * \brief Constructor
 * \param id The id of the object
 */
NTextField::NTextField() :
VisualObject() {
	//
}

/*!
 * \brief Destructor
 */
NTextField::~NTextField() {
	// None
}

/*!
 * \brief Draw the current state of the button
 * \param window The pointer on the window
 */
void NTextField::draw(sf::RenderWindow * window) {

	if(!m_hidden) return;

	if(m_isActive) {
		window->draw(m_secondSprite);
	} else {
		window->draw(m_mainSprite);
	}
}

/*!
 * \param texture_1 The pointer on the main texture
 * \param texture_2 The pointer on the second texture
 */
void NTextField::setSprite(sf::Texture * texture_1,
sf::Texture * texture_2) {
	m_mainSprite.setTexture(*texture_1);
	m_secondSprite.setTexture(*texture_2);
}

/*!
 * \param x The x position of the object
 * \param y The y position of the object
 */
void NTextField::setPosition(float x, float y) {
	m_position.x = x;
	m_position.y = y;
	m_mainSprite.setPosition(m_position);
	m_secondSprite.setPosition(m_position);
}


/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NTextField::eventMousePressed(sf::Event * e) {
	return "NULL";
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NTextField::eventMouseMoved(sf::Event * e) {
	return "NULL";
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
void NTextField::eventTextEntered(sf::Event * e) {
	// None
}

/*! 
 * \brief Update all component
 * \param frameTime The time elapsed since last frame
 */
void NTextField::update(double frameTime) {

}