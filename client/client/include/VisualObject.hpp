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

#include "Constant.hpp"
#include "TriggerableObject.hpp"

class VisualObject
{
	protected:
		bool m_hidden;
		bool m_isActive;
		bool m_isOver;
		bool m_isEnable;
		double m_timeElapsed;

		std::string m_id;
		sf::Sprite m_mainSprite;
		sf::Vector2f m_position;

	public:
		// Constructors
		VisualObject();

		// Destructor
		virtual ~VisualObject();

		// Methods
		virtual void draw(sf::RenderWindow * window);
		virtual void bind(TriggerableObject * o);
	 	virtual void init(std::string id, int x, int y, 
		sf::Texture * texture);
		virtual std::string eventMousePressed(sf::Event * e) = 0;
		virtual std::string eventMouseMoved(sf::Event * e) = 0;
		virtual void eventTextEntered(sf::Event * e) = 0;
		virtual void update(double frameTime) = 0;

		// Getters
		std::string getId();
		sf::Sprite * getSprite();
		sf::Vector2f * getPosition();

		// Setters
		void setId(const std::string & id);
		void setSprite(sf::Texture * texture);
		void setPosition(float x, float y);
		void setVisible(bool state);
};

#endif // DEF_VISUAL_OBJECT_HPP