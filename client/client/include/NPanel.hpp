/*!
 * \file NPanel.hpp
 * \brief Panel container
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#ifndef DEF_NPANEL_HPP
#define DEF_NPANEL_HPP

#include <vector>

#include "VisualObject.hpp"

class NPanel : public VisualObject
{
	private:
		std::vector < VisualObject * > m_vObjectList;

	public:
		// Constructor
		NPanel();

		// Destructor
		virtual ~NPanel();

		// Methods
		void create(std::string id, int x, int y, 
		sf::Texture * texture);
		
		virtual void draw(sf::RenderWindow * window);
		virtual std::string eventMousePressed(sf::Event * e);
		virtual std::string eventMouseMoved(sf::Event * e);
		virtual void eventTextEntered(sf::Event * e);
		virtual void update(double frameTime);
		void addComponent(VisualObject * component);
		void removeLastComponent();

};

#endif // DEF_NPANEL_HPP