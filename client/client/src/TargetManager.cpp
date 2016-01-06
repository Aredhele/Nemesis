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
}

/*!
 * \return true if all target are on false
 */
bool TargetManager::isExit() {
	return (m_onLoginMenu || m_onMainMenu);
}

/*!
 * \return m_onLoginMenu target state
 */
bool TargetManager::isLoginMenu() {
	return m_onLoginMenu;
}

/*!
 * \return m_onLoginMenu target state
 */
bool TargetManager::isMainMenu() {
	return m_onMainMenu;
}

/*!
 * \return m_onLoginMenu target state
 */
void TargetManager::isOnLoginMenu() {
	handleTarget();
	m_onLoginMenu = true;
}

/*!
 * \return m_onLoginMenu target state
 */
void TargetManager::isOnMainMenu() {
	handleTarget();
	m_onMainMenu = true;
}