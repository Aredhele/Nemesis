/*!
 * \file LoginMenu.hpp
 * \brief Handle connection
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#ifndef DEF_LOGING_MENU_HPP
#define DEF_LOGING_MENU_HPP

#include "BasicInterface.hpp"

class LoginMenu : public BasicInterface
{
	private:
		NPanel m_monSuperPanel;
		AnimatableObject m_maSuperAnimation;
		NButton m_monSuperBouton;

	public:
		// Constructor
		LoginMenu(bool debug, ManagerGroup * ptr_managerGroup);

		// Destructor
		~LoginMenu();

		// Methods
		virtual void update(sf::RenderWindow * window, 
		sf::Event * e, double frameTime);
};

#endif // DEF_LOGING_MENU_HPP