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
		bool m_hidden;
		double m_timeElapsed;
		sf::Sprite m_sprite;
		sf::Texture m_texture;


		
	public:
		// Constructor
		VisualObject(sf::Vector2f position, std::string pathToTexture);
	    VisualObject(sf::Vector2f position);

		// Destructor
		virtual ~VisualObject();

		// Methods
		virtual void draw(sf::RenderWindow *window) = 0;

		// Getters
		sf::Sprite * getMainSprite();
		sf::Vector2f getPosition();

		// Setters
		void setMainSprite(std::string pathToTexture);
		void setPosition(sf::Vector2f position);
};

#endif // DEF_VISUAL_OBJECT_HPP
 