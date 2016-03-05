/*!
 * \file TargetManager.cpp
 * \brief Handle target choice
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-28
 */

#include "TargetManager.hpp"

/*!
 * \brief Constructor
 */
TargetManager::TargetManager(bool debug) : Manager() {
	m_debug = debug;

	m_onLoginMenu = false;
	m_onMainMenu = false;
	m_onLobby = false;
	m_onWarmUp = false;
}

/*!
 * \brief Destructor
 */
TargetManager::~TargetManager() {
	// None
}

/*!
 * \brief Set all targets to false
 */
void TargetManager::exit() {
	handleTarget();
}

/*!
 * \brief Set all target to false
 */
void TargetManager::handleTarget() {
	m_onLoginMenu = false;
	m_onMainMenu = false;
	m_onLobby = false;
	m_onWarmUp = false;
	m_onGame = false;
}

/*!
 * \return true if all target are on false
 */
bool TargetManager::isExit() {
	return (m_onLoginMenu || m_onMainMenu
			|| m_onLobby || m_onWarmUp || m_onGame);
}

/*!
 * \return m_onLoginMenu target state
 */
bool TargetManager::isLoginMenu() {
	return m_onLoginMenu;
}

/*!
 * \return m_onLobby target state
 */
bool TargetManager::isLobby() {
	return m_onLobby;
}

/*!
 * \return m_onMainMenu target state
 */
bool TargetManager::isMainMenu() {
	return m_onMainMenu;
}

/*!
 * \return m_onWarmUp target state
 */
bool TargetManager::isWarmUp() {
	return m_onWarmUp;
}

/*!
 * \return m_game target state
 */
bool TargetManager::isGame() {
	return m_onGame;
}


/*!
 * \set m_onLobby target state to true
 */
void TargetManager::isOnLobby() {
	handleTarget();
	m_onLobby = true;
}



/*!
 * \return m_onLoginMenu target state
 */
void TargetManager::isOnLoginMenu() {
	handleTarget();
	m_onLoginMenu = true;
}



/*!
 * \return m_onMainMenu target state
 */
void TargetManager::isOnMainMenu() {
	handleTarget();
	m_onMainMenu = true;
}

/*!
 * \return m_onWarmUp target state
 */
void TargetManager::isOnWarmUp() {
	handleTarget();
	m_onWarmUp = true;
}

/*!
 * \return m_onGame target state
 */
void TargetManager::isOnGame() {
	handleTarget();
	m_onGame = true;
}