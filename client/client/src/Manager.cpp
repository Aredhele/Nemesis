/*!
 * \file Manager.cpp
 * \brief Super class of managers
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-25
 */

#include "Manager.hpp"

/*!
 * \brief Constructor
 */
Manager::Manager() {
	// None
}

/*!
 * \brief Destructor
 */
Manager::~Manager() {
 	// None
}

/*!
 * \brief m_state is the current state of resources
 * \return true if all is loaded
 */
bool Manager::getState() {
    return m_state;
}

/*!
 * \brief m_state is the current state of resources
 * \param state the state
 */
void Manager::setState(bool state) {
    m_state = state;
}