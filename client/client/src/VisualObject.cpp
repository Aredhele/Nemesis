/*!
 * \file VisualObject.cpp
 * \brief Super class for all drawableObject
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26 
 */

#include "VisualObject.hpp"

/*!
 * \brief Constructor
 * \return None
 */
VisualObject::VisualObject() :
m_mainSprite(),
m_position()
{
	m_hidden = false;
	m_isActive = false;
	m_isOver = false;
	m_isEnable = true;
	m_timeElapsed = 0;
}

/*!
 * \brief Constructor
 * \param id The id of the object
 * \param x The x abs position of the sprite
 * \param y The y abs position of the sprite
 * \param texture The texture of the main sprite
 */
void VisualObject::init(std::string id, int x, int y, 
sf::Texture * texture) {
	m_id = id;
	setPosition(x, y);

	if (texture != NULL) {
		m_mainSprite.setTexture(*texture);
	}

	m_mainSprite.setPosition(m_position);
}

/*!
 * \brief Destructor
 */
VisualObject::~VisualObject() {
	// TODO
}

/*!
 * \brief default code (must be redefined)
 * \param window the pointer on the drawing space
 */
void VisualObject::draw(sf::RenderWindow * window) {
	window->draw(m_mainSprite);
}

/*!
 * \brief default code (must be redefined)
 * \param o the pointer on the triggerObject
 */
void VisualObject::bind(TriggerableObject * o) {
	// If an visualObject has to trigger
	// an object, it must set an member
	// variable to o - Ex:
	// m_ptr_triggerableObject = o;
	(void)o;
}

/*!
 * \return m_id The id of the UI object
 */
std::string VisualObject::getId() {
	return m_id;
}

/*!
 * \return m_mainSprite The pointer on the sprite
 */
sf::Sprite * VisualObject::getSprite() {
	return &m_mainSprite;
}

/*!
 * \return m_position The pointer on the position
 */
sf::Vector2f * VisualObject::getPosition() {
	return &m_position;
}

/*!
 * \param id the id of the UI object
 */
void VisualObject::setId(const std::string & id) {
	m_id = id;
}

/*!
 * \param texture The pointer on the texture for the sprite
 */
void VisualObject::setSprite(sf::Texture * texture) {
	m_mainSprite.setTexture(*texture);
}


/*!
 * \param x The x position of the object
 * \param y The y position of the object
 */
void VisualObject::setPosition(float x, float y) {
	m_position.x = x;
	m_position.y = y;
	m_mainSprite.setPosition(m_position);
}

/*!
 * \brief If false, object will be hidden
 * \param state The display state of the object
 * \return None
 */
void VisualObject::setVisible(bool state) {
	m_hidden = !state;
}


