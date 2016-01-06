/**
 * \brief Handle all texture
 * \file TextureManager.hpp
 * \author Aredhele
 * \version 0.1
 * \date 12/12/2015
 * \class TextureManager.hpp
 */

#include "TextureManager.hpp"

/**
 *  \brief Constructor
 */
TextureManager::TextureManager(bool debug) : Manager() {
	m_debug = debug;
    m_state = false;
}

/**
 * \brief Destructor
 */
TextureManager::~TextureManager() {
    // None
}

/**
 * \brief Add a texture to the specified vector by the key
 * \param key the key to access the vector
 * \param texture a pointer on the texture
 */
void TextureManager::addTexture(std::string key, std::string path) {

    sf::Texture * texture = new sf::Texture();
    if(!texture->loadFromFile(path)) {
    	if(m_debug) {
        	std::cerr << "Unable to open the file" << std::endl;
    	}
    }

    m_textureMap.insert(std::pair <std::string, sf::Texture *> (key, texture));
}

/**
 * \brief return the specified texture
 * \param key the key to access the vector
 */
sf::Texture * TextureManager::getTexture(std::string key) {
    return m_textureMap[key];
}