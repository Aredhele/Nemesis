/**
 * \brief Handle all texture
 * \file TextureManager.hpp
 * \author Aredhele
 * \version 0.1
 * \date 12/12/2015
 * \class TextureManager.hpp
 */

#ifndef DEF_TEXTURE_MANAGER_HPP
#define DEF_TEXTURE_MANAGER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include <SFML/Graphics.hpp>

#include "Manager.hpp"

class TextureManager : public Manager
{
    private:
        std::map <std::string, sf::Texture *> m_textureMap;

    public:
        // Constructor
        TextureManager(bool debug);

        // Destructor
        ~TextureManager();

        // Methods
        void addTexture(std::string key, std::string path);

        // Getter
        sf::Texture * getTexture(std::string key);
};

#endif // DEF_TEXTURE_MANAGER_HPP
