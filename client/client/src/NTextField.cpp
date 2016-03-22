/*!
 * \file NTextField.cpp
 * \brief A text field can contain at most one line
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#include "NTextField.hpp"
#include <iostream>
#include <unistd.h>
/*!
 * \brief Constructor
 * \param id The id of the object
 */
NTextField::NTextField() :
	VisualObject(),
	m_cursorPosition(0, 0) 
{
	m_flashingDelay = 1.0;
	m_isFlashed = true;
	m_maxSize = 20;
	m_fontSize = 10;
}

/*!
 * \brief Destructor
 */
NTextField::~NTextField() {
	// None
}

/*!
 * \brief Constructor
 * \param id The id of the object
 * \param x The x abs position of the sprite
 * \param y The y abs position of the sprite
 * \param texture_1 The texture of the main sprite
 * \param texture_2 The texture of the second sprite
 * \param ptr_font A pointer on the font
 * \param fontSize The size of the displayed text
 * \param flashingDelay The time between two flahses
 */


void NTextField::create(std::string id, int x, int y, 
	sf::Texture * texture_1, sf::Texture * texture_2,
	sf::Font * ptr_font, int fontSize, 
	float flashingDelay, std::string const& text,
	int maxSize, sf::Color color) {

	// Call super method
	init(id, x, y, texture_1);


	m_cursorPosition.x = x + 10;
	m_cursorPosition.y = y + 7;
	//std::cout << "Cursur position x " << m_cursorPosition.x << std::endl;
	//std::cout << "Cursur position y " << m_cursorPosition.y << std::endl;

	m_secondSprite.setTexture(*texture_2);
	m_secondSprite.setPosition(m_cursorPosition);

	m_textPosition.x = m_cursorPosition.x + 1;
	m_textPosition.y = m_cursorPosition.y + 7;

	// Init sf::texte
	m_text.setFont(*ptr_font);
	m_text.setString(text);
	m_text.setCharacterSize(fontSize);
	m_text.setPosition(m_textPosition);
	m_text.setColor(color);
	m_maxSize = maxSize;
	m_fontSize = fontSize;
}


void NTextField::setTextPosition(int x, int y){
	m_textPosition.x = x;
	m_textPosition.y = y;
	m_text.setPosition(m_textPosition);
}

void NTextField::setCursorPosition(int x, int y){
	m_cursorPosition.x = x;
	m_cursorPosition.y = y;
	m_secondSprite.setPosition(m_cursorPosition);
}


/*!
 * \brief Draw the current state of the button
 * \param window The pointer on the window
 */
void NTextField::draw(sf::RenderWindow * window) {

	if(m_hidden || !m_isEnable) return;

	window->draw(m_mainSprite);
	window->draw(m_text);

	if(m_isActive) {
		if(m_isFlashed) window->draw(m_secondSprite);
	}
}

/*!
 * \param texture_1 The pointer on the main texture
 * \param texture_2 The pointer on the second texture
 */
void NTextField::setSprite(sf::Texture * texture_1,
sf::Texture * texture_2) {
	m_mainSprite.setTexture(*texture_1);
	m_secondSprite.setTexture(*texture_2);
}

/*!
 * \param x The x position of the object
 * \param y The y position of the object
 */
void NTextField::setPosition(float x, float y) {
	m_position.x = x;
	m_position.y = y;
	m_mainSprite.setPosition(m_position);
	m_secondSprite.setPosition(m_position);
}


/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NTextField::eventMousePressed(sf::Event * e) {

	std::string id = "NULL";
	if(!m_isEnable) return id;

	sf::FloatRect mousePosition(e->mouseButton.x, 
	e->mouseButton.y, 1, 1);

	if(m_mainSprite.getGlobalBounds().
	intersects(mousePosition)) {

		id = m_id;
		m_isActive = true;
	}
	else {
		m_isActive = false;
	}

	return id;
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NTextField::eventMouseMoved(sf::Event * e) {
	return "NULL";
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
void NTextField::eventTextEntered(sf::Event * e) {

	//std::cout << "TextEntered detected" << std::endl;
	float coefFont = 1.65;

	if(!m_isEnable || !m_isActive) return;
	if(m_text.getString().getSize() < m_maxSize) {

		if(e->text.unicode == 8)  { // BackSpace
			if(m_charList.size() > 0) {
				m_charList.pop_back();
				m_cursorPosition.x -= m_fontSize / coefFont;
				m_secondSprite.setPosition(m_cursorPosition);
                if(m_charList.size()==67){
                    m_cursorPosition.x = 304;
                    m_cursorPosition.y = 698;
                }
                else if(m_charList.size()==33){
                    m_cursorPosition.x = 304;
                    m_cursorPosition.y = 680;
                }
                m_secondSprite.setPosition(m_cursorPosition);
			}
		}
		else if(e->text.unicode == 32) { // Space
			m_charList.push_back(' ');
            if(m_charList.size()==33){
                m_charList.push_back('\n');
                m_cursorPosition.x = 0;
                m_cursorPosition.y = 698;
            }
            else if(m_charList.size()==67){
                m_charList.push_back('\n');
                m_cursorPosition.x = 0;
                m_cursorPosition.y = 715;
            }
            //m_cursorPosition.x += m_fontSize / 1.5;
            m_cursorPosition.x += m_fontSize / coefFont;
            m_secondSprite.setPosition(m_cursorPosition);
        }
        else if(e->text.unicode == 13) { // Carriage Return
            m_isActive = false;
        }
        else if (e->text.unicode == 9){ //Tabulation
            return;
        }
		else {
			m_charList.push_back(
					static_cast < char >(e->text.unicode));
			if(m_charList.size()==33){
				m_charList.push_back('\n');
				m_cursorPosition.x = 0;
				m_cursorPosition.y = 698;
			}
			else if(m_charList.size()==67){
				m_charList.push_back('\n');
				m_cursorPosition.x = 0;
				m_cursorPosition.y = 715;
			}
			if(e->text.unicode > 96 || e->text.unicode < 123) {
				m_cursorPosition.x += m_fontSize / coefFont;
				//m_cursorPosition.x += m_fontSize;
			} else if(e->text.unicode > 64 || e->text.unicode < 91) {
				//m_cursorPosition.x += m_fontSize * 2;
				m_cursorPosition.x += m_fontSize / coefFont;
			}
			m_secondSprite.setPosition(m_cursorPosition);
		}

		// Updating string
		m_text.setString(m_charList);

	}
	else {
		if(m_text.getString().getSize() > 0) {
			if(e->text.unicode == 8)  { // BackSpace
				if(m_charList.size() > 0) {
					m_charList.pop_back();
					m_cursorPosition.x -= m_fontSize / coefFont;

                    if(m_charList.size()==67){
                        m_cursorPosition.x = 304;
                        m_cursorPosition.y = 698;
                    }
                    else if(m_charList.size()==33){
                        m_charList.push_back('\n');
                        m_cursorPosition.x = 304;
                        m_cursorPosition.y = 680;
                    }
                    m_secondSprite.setPosition(m_cursorPosition);
					// Updating string
					m_text.setString(m_charList);
				}
			}
		}
		return;
	}

	/*if(e->text.unicode == 13){
		if(m_charList.size()!=0){
			m_charList.clear();
			m_text.setString("");
			m_cursorPosition.x = 14;
			m_cursorPosition.y = 695;
		}
	}*/
}

/*! 
 * \brief Update all component
 * \param frameTime The time elapsed since last frame
 */
void NTextField::update(double frameTime) {

	if(m_isActive) m_timeElapsed += frameTime;

	if(m_timeElapsed > m_flashingDelay) {
		m_isFlashed = !m_isFlashed;
		m_timeElapsed = 0;
	}
}

/*! 
 * \brief Return the text
 * \return m_charList The string of the textfield
 */
std::string const& NTextField::getString() {
	return m_charList;
}

void NTextField::empty(){
	m_charList = "";
	m_text.setString(m_charList);
	setCursorPosition(7, 680);
	m_isActive = true;
}