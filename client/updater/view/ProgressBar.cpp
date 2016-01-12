//
// Created by Jehan on 07/01/2016.
//
#include "view/ProgressBar.hpp"

ProgressBar::ProgressBar(sf::Vector2f position, std::string pathToTexture):
        VisualObject(position, pathToTexture)
{
    m_texture.setRepeated(true);
    m_progression = 1;
    m_nbFileMax = 1;
}

ProgressBar::~ProgressBar() {

}

void ProgressBar::draw(sf::RenderWindow *window) {

    window->draw(m_sprite);
}


void ProgressBar::setNbFileMax(int nbFileMax) {
    m_nbFileMax = nbFileMax;
}

void ProgressBar::incrementeProgression() {
    m_progression+=1;
    float percentProgress = (float)m_progression / (float)m_nbFileMax;

    std::cout << "--------------" <<650*percentProgress << std::endl;

    float x =650*percentProgress;
    m_sprite.setTextureRect(sf::IntRect(0,394,x,6));
}

void ProgressBar::maxProgression(){
    m_sprite.setTextureRect(sf::IntRect(0,394,650,6));

}
