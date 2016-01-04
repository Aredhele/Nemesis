/*!
 * \file BasicInterface.hpp
 * \brief Super class for interface
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#ifndef DEF_BASIC_INTERFACE_HPP
#define DEF_BASIC_INTERFACE_HPP

#include <vector>

#include "Updatable.hpp"
#include "NPanel.hpp"
#include "ManagerGroup.hpp"

class BasicInterface : public Updatable
{
	private:
		NPanel m_topBar;

	protected:
		ManagerGroup * m_ptr_managerGroup;
		std::vector < VisualObject * > m_vObjectList;

	public:
		// Constructor
		BasicInterface(ManagerGroup * ptr_managerGroup);

		// Destructor
		~BasicInterface();

		// Main Methods
		void basicDraw(sf::RenderWindow * window);
		void basicInput(sf::Event e);
};

#endif // DEF_BASIC_INTERFACE_HPP