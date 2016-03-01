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
#include "SFML/System.hpp"

class LoginMenu : public BasicInterface
{
	private:
		NButton m_monSuperBouton;
		NLabel m_monSuperLabel;
		NLabel m_connectionErrorLabel;
		NTextField m_textFieldLogin;
		NPanel m_nemesisLogo;

		sf::Font m_font;


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