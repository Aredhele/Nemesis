/*!
 * \file NButton.hpp
 * \brief Button object
 * \author Aredhele
 * \version 0.2
 * \date 2015-12-28
 */

#ifndef DEF_NBUTTON_HPP
#define DEF_NBUTTON_HPP

#include "Surrounder.hpp"
#include "VisualObject.hpp"

#include <iostream>

class NButton : public VisualObject
{
	private:
		bool m_isEnabled;
		unsigned int m_actionId;
		TriggerableObject * m_ptr_trggObject;

		sf::Sprite m_secondSprite;
		Surrounder m_surrounder;

		std::vector < std::string > m_textList;

	public:
		// Constructor
		NButton();

		// Destructor
		virtual ~NButton();

		// Methods
		void create(std::string id, int x, int y, 
		sf::Texture * texture_1, sf::Texture * texture_2);

		virtual void draw(sf::RenderWindow * window);
		virtual std::string eventMousePressed(sf::Event * e);
		virtual std::string eventMouseMoved(sf::Event * e);
		virtual void eventTextEntered(sf::Event * e);
		virtual void update(double frameTime);
		virtual void bind(TriggerableObject * o);

		// Setters
		virtual void setSprite(sf::Texture * texture_1,
		sf::Texture * texture_2);
		virtual void setPosition(float x, float y);

		void setEnabled(bool enabled);
		void setActionId(unsigned int id);
};

#endif // DEF_NBUTTON_HPP