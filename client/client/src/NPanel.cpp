/*!
 * \file NPanel.cpp
 * \brief Panel container
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#include "NPanel.hpp"

/*!
 * \brief Constructor
 * \param id The id of the object
 */
NPanel::NPanel(std::string id) :
VisualObject(id) {
	// None
}

/*!
 * \brief Constructor
 * \param id The id of the object
 * \param x The x abs position of the sprite
 * \param y The y abs position of the sprite
 * \param texture The texture of the main sprite
 */
NPanel::NPanel(std::string id, int x, int y, 
sf::Texture * texture) : 
VisualObject(id, x, y, texture) {
	// None
}

/*!
 * \brief Destructor
 */
NPanel::~NPanel() {
	// None
}