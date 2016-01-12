#include "view/Button.hpp"

// Constructor
Button::Button(sf::Vector2f position, std::string pathToTexture, std::string pathSecondTexture) :
VisualObject(position, pathToTexture),
m_secondTexture(),
m_secondSprite()
{

    m_active = false;
    m_totalTime = 0;
    m_secondTexture.loadFromFile(pathSecondTexture);
    m_secondSprite.setTexture(m_secondTexture);
    m_secondSprite.setPosition(position);
    m_enable = true;
}

// Constructor
Button::Button(sf::Vector2f position, std::string pathToTexture, std::string pathSecondTexture, std::string oldTexture) :
        VisualObject(position, pathToTexture),
        m_secondTexture(),
        m_oldTexture(),
        m_secondSprite()
{

    m_active = false;
    m_totalTime = 0;
    m_secondTexture.loadFromFile(pathSecondTexture);
    m_oldTexture.loadFromFile(oldTexture);
    m_secondSprite.setTexture(m_secondTexture);
    m_secondSprite.setPosition(position);
    m_oldSprite.setTexture(m_oldTexture);
    m_oldSprite.setPosition(position);
    m_enable = true;
}

// Destructor
Button::~Button() {

}

void Button::update(double frameTime) {

    if(m_active) m_totalTime += frameTime;

    if(m_totalTime > 0.02) {
        m_active = false;
        m_isPress = true;
        m_totalTime = 0;
    }
    else{
        m_isPress = false;
    }
}

void Button::handle(sf::Event *e) {

    if (!m_enable) return;

    sf::FloatRect mousePosition(e->mouseButton.x,
     e->mouseButton.y, 1, 1);

    if(m_sprite.getGlobalBounds().
    intersects(mousePosition)) {
        if(e->type == sf::Event::MouseButtonPressed &&
          e->mouseButton.button == sf::Mouse::Left) {
            m_totalTime = 0;
            m_active = true;
        }
    }

}

void Button::draw(sf::RenderWindow *window) {

    if (!m_enable) {
        window->draw(m_oldSprite);

        return;
    }
    if(m_active) window->draw(m_secondSprite);
    else window->draw(m_sprite);
}

bool Button::isPress() {
    return m_isPress;
}

void Button::enable(bool enable)
{
    m_enable=enable;
}
