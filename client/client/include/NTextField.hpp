/*!
 * \file NTextField.hpp
 * \brief A text field can contain at most one line
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#ifndef DEF_NTEXT_FIELD_HPP
#define DEF_NTEXT_FIELD_HPP

#include <vector>
#include "VisualObject.hpp"

class NTextField : public VisualObject
{
	private:
		sf::Sprite m_secondSprite;
		sf::Text m_text;
		float m_flashingDelay;
		bool m_isFlashed;
		int m_maxSize;
		int m_fontSize;
		sf::Vector2f m_cursorPosition;
		sf::Vector2f m_textPosition;
		std::string m_charList;

	public:
		// Constructor
		NTextField();

		// Destructor
		virtual ~NTextField();

		// Methods
		void create(std::string id, int x, int y, 
			sf::Texture * texture_1, sf::Texture * texture_2,
			sf::Font * ptr_font, int fontSize, 
			float flashingDelay, std::string const& text,
			int maxSize, sf::Color color);

		virtual void draw(sf::RenderWindow * window);
		virtual std::string eventMousePressed(sf::Event * e);
		virtual std::string eventMouseMoved(sf::Event * e);
		virtual void eventTextEntered(sf::Event * e);
		virtual void update(double frameTime);

		virtual void setSprite(sf::Texture * texture_1,
		sf::Texture * texture_2);

		virtual void setPosition(float x, float y);

		// Getters
		std::string const& getString();

		void empty();

		void setTextPosition(int x, int y);
		void setCursorPosition(int x, int y);
};

#endif // DEF_NTEXT_FIELD_HPP