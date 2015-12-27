/*!
 * \file SplashScreen.hpp
 * \brief Handle display of splash screen
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-25 
 */

#ifndef DEF_SPLASH_SCREEN_HPP
#define DEF_SPLASH_SCREEN_HPP

#include <SFML/Audio.hpp>

#include "VideoPlayer.hpp"

class SplashScreen
{
	private:
		bool m_debug;
		VideoPlayer m_videoPlayer;

		unsigned int m_currentVideoIndex;
		std::vector < VideoParam * > m_videoList;

	public:
		// Constructor
		SplashScreen(bool debug);

		// Destructor
		~SplashScreen();

		// Methods
		void start(sf::RenderWindow * window);
};

#endif // DEF_SPLASH_SCREEN_HPP