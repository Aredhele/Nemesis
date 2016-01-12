//
// Created by Jehan on 04/01/2016.
//

#include "view/Log.hpp"


Log::Log(sf::Vector2f position, std::string pathToTexture):
VisualObject(position, pathToTexture),
m_font()
{
    m_cursor = 0;
    m_font.loadFromFile("../res/font/Quicksand.ttf");
}

Log::Log(sf::Vector2f position):
        VisualObject(position),
        m_font()
{
    m_cursor = 0;
    m_font.loadFromFile("../res/font/Quicksand.ttf");
}



Log::~Log() {

}

void Log::draw(sf::RenderWindow *window) {
    window->draw(m_sprite);
    for(int i = m_cursor, index = 0; i < m_textList.size() && i < m_cursor + 13; i++, index++){

        m_textList[i]->setPosition(310, 100 + index * 13);

        window->draw(*m_textList[i]);
    }
}

void Log::addText(const std::wstring & text, sf::Color color) {
    std::wstring tmp(L"");
    std::wstring tmp2(L"Transfert de ");

    for(int i = text.size()-1;text[i] != '\\' && i > -1;i--){
        tmp+=text[i];
    }
    std::reverse(std::begin(tmp), std::end(tmp));
    if(text.size() != tmp.size()) tmp2+=tmp;
    else tmp2=tmp;

    m_textList.push_back(new sf::Text(tmp2, m_font, 13));

    m_textList[m_textList.size()-1]->setStyle(sf::Text::Bold);
    m_textList[m_textList.size()-1]->setColor(color);
    if(m_textList.size() > 13){
        m_cursor++;
    }
}

void Log::cursorDown() {
    if(m_cursor < m_textList.size() -1)
        m_cursor++;
}

void Log::cursorUp() {
    if(m_cursor>0)
        m_cursor--;
}

sf::Text* Log::getLastText() {
    return m_textList[m_textList.size()-1];
}
