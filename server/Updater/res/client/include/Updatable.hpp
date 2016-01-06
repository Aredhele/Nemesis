/*!
 * \file Updatable.hpp
 * \brief Super class for updatable object
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#ifndef DEF_UPDATABLE_HPP
#define DEF_UPDATABLE_HPP

#include <SFML/Graphics.hpp>

class Updatable
{
	protected:
		double m_totalFrameTime;

	public:
		// Constructor
		Updatable();

		// Destructor
		virtual ~Updatable();

		// Methods
		virtual void update(sf::RenderWindow * window, 
		sf::Event * e, double frameTime) = 0;
};

#endif // DEF_UPDATABLE_HPP