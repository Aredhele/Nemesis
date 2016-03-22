/*!
 * \file BasicInterface.cpp
 * \brief Super class for interface
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#include "NLabel.hpp"

/*!
 * \brief Constructor
 * \return None
 */
NLabel::NLabel() :
VisualObject(), m_text() {
	// None
}

/*!
 * \brief Destructor
 */
NLabel::~NLabel() {
	// None
}

/*!
 * \brief Init methode
 * \param id The id of the object
 * \param x The x abs position of the sprite
 * \param y The y abs position of the sprite
 * \param texture The texture of the main sprite
 */
void NLabel::create(std::string id, int x, int y, int size, 
sf::Font * ptr_font, std::wstring text, sf::Color color) {

	m_ptr_font = ptr_font;
	m_id = id;
	m_position.x = x;
	m_position.y = y;
	m_Stext = text;
	m_text.setFont(*ptr_font);
	m_text.setString(text);
	m_text.setCharacterSize(size);
	m_text.setPosition(m_position);
	m_color = color;
	m_text.setColor(color);
}

/*!
 * \brief Draw all object in the panel
 * \param window The pointer on window
 */
void NLabel::draw(sf::RenderWindow * window) {

	if(m_hidden) return;
	window->draw(m_text);
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NLabel::eventMousePressed(sf::Event * e) {

	(void)e;
	return "NULL";
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string NLabel::eventMouseMoved(sf::Event * e) {

	(void)e;
	return "NULL";
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
void NLabel::eventTextEntered(sf::Event * e) {

	(void)e;
}

/*! 
 * \brief Update all component
 * \param frameTime The time elapsed since last frame
 */
void NLabel::update(double frameTime) {

	(void)frameTime;
}


void NLabel::setText(std::wstring text){
	m_text.setString(text);
	m_Stext = text;
}

void NLabel::setColor(sf::Color color){
	m_text.setColor(color);
	m_color = color;
}

std::wstring NLabel::getSText(){
	return m_Stext;
}
sf::Color NLabel::getColor(){
	return m_color;
}

void NLabel::setPosition(float x, float y) {

	m_text.setPosition(x, y);
}
