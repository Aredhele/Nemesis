//
// Created by Jehan on 07/01/2016.
//

#ifndef CHOUCROUTE_PROGRESSBAR_HPP
#define CHOUCROUTE_PROGRESSBAR_HPP

#include "VisualObject.hpp"

class ProgressBar : public VisualObject {
private:
    int m_progression;
    int m_nbFileMax;
    sf::Sprite m_spriteHead;
    sf::Texture m_textureHead;

public:
    ProgressBar(sf::Vector2f position, std::string pathToTexture);
    ~ProgressBar();
    void draw(sf::RenderWindow *window);

    //Setters
    void setNbFileMax(int nbFileMax);
    void incrementeProgression();


    void maxProgression();
};


#endif //CHOUCROUTE_PROGRESSBAR_HPP
