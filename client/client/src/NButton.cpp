/*!
 * \file NButton.cpp
 * \brief Button object
 * \author Aredhele
 * \version 0.2
 * \date 2015-12-28
 */

#include "NButton.hpp"
#include <iostream>
/*!
 * \brief Constructor
 * \return None
 */
NButton::NButton() :
VisualObject(),
m_surrounder()
{
	m_actionId = -1;
	m_ptr_trggObject = nullptr;
}

/*!
 * \brief Destructor
 */
NButton::~NButton() {
	// None
}

/*!
 * \brief Constructor
 * \param id The id of the object
 * \param x The x abs position of the sprite
 * \param y The y abs position of the sprite
 * \param texture_1 The texture of the main sprite
 * \param texture_2 The texture of the second sprite
 */
void NButton::create(std::string id, int x, int y, 
sf::Texture * texture_1, sf::Texture * texture_2) {

	m_actionId = -1;
	m_ptr_trggObject = nullptr;
	m_isEnabled = true;

	// Call super method
	init(id, x, y, texture_1);

	m_secondSprite.setTexture(*texture_2);
	m_secondSprite.setPosition(m_position);

	m_surrounder.init(m_mainSprite.getPosition(),
	m_mainSprite.getTexture()->getSize(),
	sf::Color(196,130,56));
}

/*!
 * \brief Draw the current state of the button
 * \param window The pointer on the window
 */
void NButton::draw(sf::RenderWindow * window) {

	if(m_hidden) return;

	if(m_isActive) {
		window->draw(m_secondSprite);
	} else if (m_isOver) {
		window->draw(m_mainSprite);
		window->draw(*m_surrounder.getShape());
	} else {
		window->draw(m_mainSprite);
	}
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NButton::eventMousePressed(sf::Event * e) {

	std::string id = "NULL";
	if(m_hidden) return id;
	if(!m_isEnabled) return id;

	sf::FloatRect mousePosition(e->mouseButton.x, 
	e->mouseButton.y, 1, 1);

	//std::cout << m_mainSprite.getGlobalBounds().top << std::endl;
	//std::cout << m_mainSprite.getGlobalBounds().left << std::endl;

	if(m_mainSprite.getGlobalBounds().
	intersects(mousePosition)) {

		id = m_id;
		m_isActive = true;

		// Triggering
		if((int)m_actionId != -1 && m_ptr_trggObject != nullptr) {
			m_ptr_trggObject->trigger(m_actionId, m_textList);
		}
	}

	return id;
}

/*!
 * \brief Check event, if the mouse is over the button
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NButton::eventMouseMoved(sf::Event * e) {


	std::string id = "NULL";
	if(m_hidden) return id;
	if(!m_isEnabled) return id;

	sf::FloatRect mousePosition(e->mouseMove.x, 
	e->mouseMove.y, 1, 1);

	if(m_mainSprite.getGlobalBounds().
	intersects(mousePosition)) {
		id = m_id;
		m_isOver = true;
	} else {
		m_isOver = false;
	}
	return id;
}

/*!
 * \brief Check event, if the mouse is over the button
 * \param e The pointer on the event
 * \return id NULL if not found
 */
void NButton::eventTextEntered(sf::Event * e) {

	if(m_hidden) return;
	(void)e;
}

/*! 
 * \brief Update all component
 * \param frameTime The time elapsed since last frame
 */
void NButton::update(double frameTime) {

	if(m_isActive) m_timeElapsed += frameTime;

	if(m_timeElapsed > BUTTON_DELAY) {
		m_isActive = false;
		m_timeElapsed = 0;
	}
}

void NButton::bind(TriggerableObject * o) {

	// Binding
	m_ptr_trggObject = o;
}

/*!
 * \param texture_1 The pointer on the main texture
 * \param texture_2 The pointer on the second texture
 */
void NButton::setSprite(sf::Texture * texture_1,
sf::Texture * texture_2) {
	m_mainSprite.setTexture(*texture_1);
	m_secondSprite.setTexture(*texture_2);
}

/*!
 * \param x The x position of the object
 * \param y The y position of the object
 */
void NButton::setPosition(float x, float y) {
	m_position.x = x;
	m_position.y = y;
	m_mainSprite.setPosition(m_position);
	m_secondSprite.setPosition(m_position);

	m_surrounder.init(m_mainSprite.getPosition(),
					  m_mainSprite.getTexture()->getSize(),
					  sf::Color(196,130,56));

}

/*!
 * \param id The id of the action for triggering
 * \return None
 */
void NButton::setActionId(unsigned int id) {
	m_actionId = id;
}

void NButton::setEnabled(bool enabled){
	m_isEnabled = enabled;
}