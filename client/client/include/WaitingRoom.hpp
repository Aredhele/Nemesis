/*!
 * \file LoginMenu.hpp
 * \brief Handle connection
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#ifndef DEF_WAITING_ROOM_HPP
#define DEF_WAITING_ROOM_HPP

#include "AnimatableObject.hpp"
#include "BasicInterface.hpp"

class WaitingRoom : public BasicInterface
{
	private:

		NButton m_button;
		NPanel m_panel;
		NLabel m_label;

		AnimatableObject m_ao;
		
	public:
		// Constructor
		WaitingRoom(bool debug, ManagerGroup * ptr_managerGroup);

		// Destructor
		~WaitingRoom();

		// Methods
		virtual void update(sf::RenderWindow * window, 
		sf::Event * e, double frameTime);
};

#endif // DEF_WAITING_ROOM_HPP