/*!
 * \file VisualObject.cpp
 * \brief Super class of UI objects
 * \author Aredhele
 * \version 0.1
 * \date 2015-11-26
 */

// Header
#include "view/VisualObject.hpp"

/*!
 * \brief Constructor.
 * \brief Initialize with default values
 */
VisualObject::VisualObject(sf::Vector2f position, 
std::string pathToTexture) : 
m_sprite(),
m_texture()
{
	if(!m_texture.loadFromFile(pathToTexture)) {
		std::cerr << "Unable to load texture" << std::endl;
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(position);
}

/*!
 * \brief Destructor.
 */
VisualObject::~VisualObject() {
	// None
}

/*!
 * \return m_ptr_sprite a pointer on the sprite
 */
sf::Sprite * VisualObject::getMainSprite() {
	return &m_sprite;
}

/*!
 * \return m_ptr_position a pointer on the position
 */
sf::Vector2f VisualObject::getPosition() {
	return m_sprite.getPosition();
}

/*!
 * \param pathToTexture The path to the file
 */
void VisualObject::setMainSprite(std::string pathToTexture) {

	if(m_texture.loadFromFile(pathToTexture)) {
		std::cerr << "Unable to load texture" << std::endl;
	}
}

/*!
 * \param position The position of the sprite
 */
void VisualObject::setPosition(sf::Vector2f position) {

	m_sprite.setPosition(position);
}