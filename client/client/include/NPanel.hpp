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
		NPanel(std::string id);
		NPanel(std::string id, int x, int y, 
		sf::Texture * texture);

		// Destructor
		virtual ~NPanel();
};

#endif // DEF_NPANEL_HPP