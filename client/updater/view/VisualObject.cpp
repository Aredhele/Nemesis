/*!
 * \file VisualObject.cpp
 * \brief Super class of UI objects
 * \author Aredhele
 * \version 0.1
 * \date 2015-11-26
 */

// Header
#include "../include/view/VisualObject.hpp"

/*!
 * \brief Constructor.
 * \brief Initialize with default values
 */
VisualObject::VisualObject() {
	m_ptr_sprite = new sf::Sprite();
	m_ptr_texture = new sf::Texture();
	m_ptr_position = new sf::Vector2f(0, 0);
}

/*!
 * \brief Constructor.
 * \brief Intialize with parameters
 */
VisualObject::VisualObject(sf::Vector2f position, std::string pathToTexture) {
	m_ptr_sprite = new sf::Sprite();
	m_ptr_texture = new sf::Texture();
	m_ptr_position = new sf::Vector2f(position);
	
	if(!m_ptr_texture->loadFromFile(pathToTexture)) {
		std::cerr << "Unable to load texture" << std::endl;
	}

	m_ptr_sprite->setTexture(*m_ptr_texture);
	m_ptr_sprite->setPosition(*m_ptr_position);
}

/*!
 * \brief Destructor.
 * \brief Delete properly ptrs
 */
VisualObject::~VisualObject() {
	delete m_ptr_sprite;
	delete m_ptr_texture;
	delete m_ptr_position;

	m_ptr_sprite = nullptr;
	m_ptr_texture = nullptr;
	m_ptr_position = nullptr;
}

/*!
 * \return m_ptr_sprite a pointer on the sprite
 */
sf::Sprite * VisualObject::getMainSprite() {
	return m_ptr_sprite;
}

/*!
 * \return m_ptr_position a pointer on the position
 */
sf::Vector2f * VisualObject::getPosition() {
	return m_ptr_position;
}

/*!
 * \param pathToTexture The path to the file
 */
void VisualObject::setMainSprite(std::string pathToTexture) {
	if(!m_ptr_texture->loadFromFile(pathToTexture)) {
		std::cerr << "Unable to load texture" << std::endl;
	}

	// Useless ?
	m_ptr_sprite->setTexture(*m_ptr_texture);
}

/*!
 * \param position The position of the sprite
 */
void VisualObject::setPosition(sf::Vector2f position) {
	m_ptr_position->x = position.x;
	m_ptr_position->y = position.y;

	// Useless ?
	m_ptr_sprite->setPosition(*m_ptr_position);
}