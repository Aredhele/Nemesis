/*!
 * \file NTextField.hpp
 * \brief A text field can contain at most one line
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#ifndef DEF_NTEXT_FIELD_HPP
#define DEF_NTEXT_FIELD_HPP

#include "VisualObject.hpp"

class NTextField : public VisualObject
{
	private:
		sf::Sprite m_secondSprite;

	public:
		// Constructor
		NTextField();

		// Destructor
		virtual ~NTextField();

		// Methods
		virtual void draw(sf::RenderWindow * window);
		virtual std::string eventMousePressed(sf::Event * e);
		virtual std::string eventMouseMoved(sf::Event * e);
		virtual void eventTextEntered(sf::Event * e);
		virtual void update(double frameTime);

		virtual void setSprite(sf::Texture * texture_1,
		sf::Texture * texture_2);

		virtual void setPosition(float x, float y);
};

#endif // DEF_NTEXT_FIELD_HPP