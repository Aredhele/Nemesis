/*!
 * \file Surrounder.hpp
 * \brief Surround a object with lines
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#ifndef DEF_SURROUNDER_HPP
#define DEF_SURROUNDER_HPP

#include <SFML/Graphics.hpp>

class Surrounder
{
private:
    sf::Vector2f m_position;
    float m_size;

    sf::CircleShape m_rectShape;

public:
    // Constructor
    Surrounder();

    // Destructor
    ~Surrounder();

    // Methods
    void init(const sf::Vector2f & pos,
              const float & size, const sf::Color & color);

    // Getters
    sf::CircleShape * getShape();
};

#endif // DEF_SURROUNDER_HPP