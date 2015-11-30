/*!
 * \file VisualObject.hpp
 * \brief Super class of UI objects
 * \author Aredhele
 * \version 0.1
 * \date 2015-11-26
 */

#ifndef DEF_VISUAL_OBJECT_HPP
#define DEF_VISUAL_OBJECT_HPP

// Headers
#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

class VisualObject
{
	protected:
		// Members
		sf::Sprite * m_ptr_sprite;
		sf::Texture * m_ptr_texture;
		sf::Vector2f * m_ptr_position;
		
	public:
		// Constructor
		VisualObject();
		VisualObject(sf::Vector2f position, std::string pathToTexture);

		// Destructor
		virtual ~VisualObject();

		// Methods
		// Getters
		sf::Sprite * getMainSprite();
		sf::Vector2f * getPosition();

		// Setters
		void setMainSprite(std::string pathToTexture);
		void setPosition(sf::Vector2f position);
};

#endif // DEF_VISUAL_OBJECT_HPP
 