/*!
 * \file TargetManager.hpp
 * \brief Handle target choice
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-28
 */

#ifndef DEF_TARGER_MANAGER_HPP
#define DEF_TARGER_MANAGER_HPP

#include "Manager.hpp"

class TargetManager : public Manager
{
	private:
		bool m_onLoginMenu;
		bool m_onMainMenu;
		bool m_onLobby;
		bool m_onWarmUp;
        bool m_onGame;

		// Method
		void handleTarget();
		
	public:
		// Constructor
		TargetManager(bool debug);

		// Destructor
		~TargetManager();

		// Method
		void exit();

		// Getters
		bool isExit();
		bool isLoginMenu();
		bool isLobby();
		bool isMainMenu();
		bool isWarmUp();
	    bool isGame();

		// Setters
		void isOnLoginMenu();
		void isOnLobby();
		void isOnMainMenu();
		void isOnWarmUp();
        void isOnGame();
};

#endif // DEF_TARGER_MANAGER_HPP