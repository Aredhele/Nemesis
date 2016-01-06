/*!
 * \file Surrounder.hpp
 * \brief Surround a object with lines
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#include "Surrounder.hpp" 

/*!
 * \brief Constructor
 * \return None
 */
Surrounder::Surrounder() : 
m_position(sf::Vector2f(0, 0)),
m_size(sf::Vector2u(0, 0)),
m_rectShape(m_size)
{
	// None
}

/*!
 * \brief Destructor
 * \return None
 */
Surrounder::~Surrounder() {
	// None
}

/*!
 * \brief Initialize the surrounder
 * \param pos The position of the rectangle
 * \param size The size of the rectangle
 * \return None
 */
void Surrounder::init(const sf::Vector2f & pos,
const sf::Vector2u & size, const sf::Color & color) {

	m_position.x = pos.x;
	m_position.y = pos.y;

	m_size.x = (float)size.x;
	m_size.y = (float)size.y;

	m_rectShape.setPosition(m_position);
	m_rectShape.setSize(m_size);

	m_rectShape.setFillColor(sf::Color::Transparent);
	m_rectShape.setOutlineColor(color);
	m_rectShape.setOutlineThickness(1);
}

/*!
 * \brief Return the shape to surround an object
 * \return m_rectShape The shape
 */
sf::RectangleShape * Surrounder::getShape() {
	return &m_rectShape;
}