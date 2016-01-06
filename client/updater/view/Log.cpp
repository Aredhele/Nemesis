//
// Created by Jehan on 04/01/2016.
//

#include "view/Log.hpp"


Log::Log(sf::Vector2f position, std::string pathToTexture):
VisualObject(position, pathToTexture),
m_font()
{
    m_cursor = 0;
    m_font.loadFromFile("../res/font/arial.ttf");
}

Log::~Log() {

}

void Log::draw(sf::RenderWindow *window) {
    window->draw(m_sprite);
    int a;
    for(int i = m_cursor, index = 0; i < m_textList.size() && i < m_cursor + 14; i++, index++){
        m_textList[i]->setPosition(13, 200 + index * 12);
        a = m_textList.size();
        window->draw(*m_textList[i]);
    }
}

void Log::addText(const std::wstring & text, sf::Color color) {
    m_textList.push_back(new sf::Text(text, m_font, 12));
    m_textList[m_textList.size()-1]->setColor(color);
    if(m_textList.size() > 14){
        m_cursor++;
    }
}

void Log::cursorDown() {
    if(m_cursor < m_textList.size() -1)
        m_cursor++;
    std::cout << m_cursor << std::endl;
}

void Log::cursorUp() {
    if(m_cursor>0)
        m_cursor--;
    std::cout << m_cursor << std::endl;
}

sf::Text* Log::getLastText() {
    return m_textList[m_textList.size()-1];
}
