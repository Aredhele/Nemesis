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
		NLabel m_titleLabel;
		NLabel m_connectionErrorLabel;
		NLabel m_pseudoErrorLabel;
		NTextField m_textFieldLogin;
		NPanel m_nemesisLogo;
		NPanel m_errorPanel;

		sf::Font m_fontLabel;
        sf::Font m_fontTextbox;


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