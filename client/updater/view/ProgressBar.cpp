//
// Created by Jehan on 07/01/2016.
//
#include "view/ProgressBar.hpp"

ProgressBar::ProgressBar(sf::Vector2f position, std::string pathToTexture):
        VisualObject(position, pathToTexture),
    m_spriteHead(),
    m_textureHead()
{
    if(!m_textureHead.loadFromFile("../res/img/PenHead.png")) {
        std::cerr << "Unable to load texture" << std::endl;
    }
    m_texture.setRepeated(true);
    m_spriteHead.setTexture(m_textureHead);
    m_spriteHead.setPosition(3,119);

    m_progression = 1;
    m_nbFileMax = 1;
}

ProgressBar::~ProgressBar() {

}

void ProgressBar::draw(sf::RenderWindow *window) {

    window->draw(m_sprite);
    window->draw(m_spriteHead);
}


void ProgressBar::setNbFileMax(int nbFileMax) {
    m_nbFileMax = nbFileMax;
}

void ProgressBar::incrementeProgression() {
    m_progression+=1;


    float percentProgress = (float)m_progression / (float)m_nbFileMax;


    std::cout << "--------------" <<545*percentProgress << std::endl;

    m_spriteHead.setPosition(558 * percentProgress +3 ,119);
    m_sprite.setTextureRect(sf::IntRect(3,120,(int)m_spriteHead.getPosition().x,54));

}

void ProgressBar::maxProgression(){
    m_spriteHead.setPosition(558,119);
    m_sprite.setTextureRect(sf::IntRect(3,120,(int)m_spriteHead.getPosition().x,54));

}
