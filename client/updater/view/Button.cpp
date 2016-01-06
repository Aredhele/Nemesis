#include "view/Button.hpp"

// Constructor
Button::Button(sf::Vector2f position, std::string pathToTexture, std::string p) :
VisualObject(position, pathToTexture),
m_secondeTexture(),
m_secondSprite(),
m_surrounder()
{
    m_surrounder.init(m_sprite.getPosition(),
                      sf::Vector2u(m_sprite.getTexture()->getSize()).x/2,
                      sf::Color(120,120,120,70));
    m_active = false;
    m_totalTime = 0;
    m_secondeTexture.loadFromFile(p);
    m_secondSprite.setTexture(m_secondeTexture);
    m_secondSprite.setPosition(position);
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
        window->draw(*getMainSprite());
        window->draw(*m_surrounder.getShape());
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
