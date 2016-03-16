/*!
 * \file AnimatableObject.cpp
 * \brief Anime an sprite
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#include "AnimatableObject.hpp"
#include <iostream>
/*!
 * \brief Constructor
 * \return None
 */
AnimatableObject::AnimatableObject() :
VisualObject() {
	// None
}

/*!
 * \brief Destructor
 */
AnimatableObject::~AnimatableObject() {
	// None
}

/*!
 * \brief Init methode
 * \param id The id of the object
 * \param x The x abs position of the sprite
 * \param y The y abs position of the sprite
 * \param texture The texture of the main sprite
 */
void AnimatableObject::create(std::string id, int x, int y, 
sf::Texture * texture, bool repeat, float duration, int h,
int w, int step) {

	// Call super method
	init(id, x, y, texture);

	m_animduration = duration;
	m_repeat = repeat;
	m_frameHeight = h;
	m_frameWidth = w;
	m_lenght = step;
	m_currentStep = 0;

	m_state = AnimationState::PLAY;

	m_mainSprite.setTextureRect(sf::IntRect(
	0, 0, 
	m_frameWidth, m_frameHeight));
}

/*!
 * \brief Draw all object in the panel
 * \param window The pointer on window
 */
void AnimatableObject::draw(sf::RenderWindow * window) {
	
	if(m_hidden) return;
	window->draw(m_mainSprite);
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string AnimatableObject::eventMousePressed(sf::Event * e) {

	(void)e;
	return "NULL";
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
std::string AnimatableObject::eventMouseMoved(sf::Event * e) {

	(void)e;
	return "NULL";
}

/*!
 * \brief Check event
 * \param e The pointer on the event
 * \return id NULL if not found
 */
void AnimatableObject::eventTextEntered(sf::Event * e) {

	(void)e;
}

/*! 
 * \brief Update all component
 * \param frameTime The time elapsed since last frame
 */
void AnimatableObject::update(double frameTime) {
	
	if(m_state == AnimationState::PLAY) {
		m_timeElapsed += frameTime;

		if(m_timeElapsed >= m_animduration) {
			m_timeElapsed = 0;
			if(m_currentStep + 1 >= m_lenght) {
				if(m_repeat) m_currentStep = 0;
				else m_state = AnimationState::STOP;
			}
			else
				m_currentStep++;
			
			m_mainSprite.setTextureRect(sf::IntRect(
			m_currentStep * m_frameWidth, 0, 
			m_frameWidth, m_frameHeight));
		}
	}
}

void AnimatableObject::play(){
	m_state = AnimationState::PLAY;
	m_currentStep = 0;
	m_mainSprite.setTextureRect(sf::IntRect(
			0, 0,
			m_frameWidth, m_frameHeight));

}

bool AnimatableObject::isStopped(){
	return m_state == AnimationState::STOP;
}