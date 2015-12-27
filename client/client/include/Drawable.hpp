/*!
 * \file Drawable.hpp
 * \brief Super class for all drawable object
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-23
 */

#ifndef DEF_DRAWABLE_HPP
#define DEF_DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class Drawable
{
	protected:
		double m_totalFrameTime;

	public:
		// Constructor
		Drawable();

		// Destructor
		virtual ~Drawable();

		// Methods
		virtual void draw(sf::RenderWindow * window, double frameTime) = 0;

		// Getters
};

#endif // DEF_DRAWABLE_HPP