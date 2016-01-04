/*!
 * \file SplashScreen.hpp
 * \brief Handle display of splash screen
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-25 
 */

#include "SplashScreen.hpp"

/*!
 * \brief Constructor
 * \param debug the debug mode
 */
SplashScreen::SplashScreen(bool debug) : m_videoPlayer(debug) {
	m_debug = debug;
	m_currentVideoIndex = 0;

	m_videoList.push_back(new VideoParam(WINDOW_WIDTH, WINDOW_HEIGHT,
		35, 190, "../res/animation/splash/splash_0/"));

	m_videoList.push_back(new VideoParam(WINDOW_WIDTH, WINDOW_HEIGHT,
		35, 200, "../res/animation/splash/splash_1/"));

	if(m_debug) {
		std::cout << "- " << m_videoList.size() 
		<< " video(s) added ! " << std::endl;
	}
}

/*!
 * \brief Destructor
 */
SplashScreen::~SplashScreen() {
	// None
}

/*!
 * \brief Start video
 */
void SplashScreen::start(sf::RenderWindow * window) {

	bool isPlaying = true;

	m_videoPlayer.init(m_videoList[m_currentVideoIndex]);
	m_videoPlayer.setVideoState(videoState::PLAY);

	sf::Music music;
	if(!music.openFromFile("../res/music/splash/Opening.ogg")) {
		if(m_debug)
			std::cerr << "Unable to open the file" << std::endl;
		return;
	}

	music.play();

	sf::Clock clock;
    while (isPlaying)
    {
        double elapsedTime = clock.getElapsedTime().asSeconds();
        clock.restart().asMilliseconds();
        window->clear();

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window->close();
                music.stop();
                isPlaying = false;
            }
        }

        m_videoPlayer.draw(window, elapsedTime);

        if(m_videoPlayer.isFinished()) {
  			if(m_currentVideoIndex + 1 < m_videoList.size()) {
  				m_currentVideoIndex++;
	        	m_videoPlayer.init(m_videoList[m_currentVideoIndex]);
	        	m_videoPlayer.setVideoState(videoState::PLAY);
	       	} else {
	       		break;
	       	}
        }

        window->display();
    }
}