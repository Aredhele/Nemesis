/*!
 * \file OptionManager.cpp
 * \brief Contains all game options
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-28
 */

#include "OptionManager.hpp"

/*!
 * \brief Constructor
 * \param debug The debug mode
 */
OptionManager::OptionManager(bool debug) : Manager() {
	m_debug = debug;
}

/*!
 * \brief Destructor
 */
OptionManager::~OptionManager() {
	// None
}