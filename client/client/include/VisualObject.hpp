/*!
 * \file VisualObject.hpp
 * \brief Super class for all drawableObject
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26 
 */

#ifndef DEF_VISUAL_OBJECT_HPP
#define DEF_VISUAL_OBJECT_HPP

#include <string>
#include <SFML/Graphics.hpp>

class VisualObject
{
	protected:
		std::string m_id;
		sf::Sprite m_mainSprite;
		sf::Vector2f m_position;

	public:
		// Constructors
		VisualObject(std::string id);
		VisualObject(std::string id, int x, int y,
		sf::Texture * texture);

		// Destructor
		virtual ~VisualObject();

		// Methods
		virtual void draw(sf::RenderWindow * window);

		// Getters
		std::string getId();
		sf::Sprite * getSprite();
		sf::Vector2f * getPosition();

		// Setters
		void setId(const std::string & id);
		void setSprite(sf::Texture * texture);
		void setPosition(float x, float y);
};

#endif // DEF_VISUAL_OBJECT_HPP