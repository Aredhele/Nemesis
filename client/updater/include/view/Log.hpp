#ifndef DEF_LOG_HPP
#define DEF_LOG_HPP

#include "VisualObject.hpp"
#include <algorithm>

class Log : public VisualObject
{
    private:
        std::vector < sf::Text * > m_textList;
        sf::Font m_font;
        int m_cursor;

    public:
        // Constructor
        Log(sf::Vector2f position, std::string pathToTexture);
        Log(sf::Vector2f position);

        // Destructor
        ~Log();

        void cursorUp();
        void cursorDown();
        void addText(const std::wstring & text, sf::Color color);
        void draw(sf::RenderWindow *window);
        sf::Text* getLastText();
};

#endif //DEF_LOG_HPP
