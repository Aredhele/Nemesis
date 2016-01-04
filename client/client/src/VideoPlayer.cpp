/*!
 * \file VideoPlayer.cpp
 * \brief Play a video from a stream
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-23
 */

#include "VideoPlayer.hpp"

/*!
* \brief Constructor
* \param debug 1 debug mode - 0 none
*/
VideoPlayer::VideoPlayer(bool debug) : 
m_sprite(),
m_texture()
{
	m_debug = debug;
	m_enum_state = videoState::STOP;
}

/*!
 * \brief Default destructor
 */
VideoPlayer::~VideoPlayer() {
	// None
}

/*!
 * \brief Intitialize a new video player
 * \param param all parameters
 */
int VideoPlayer::init(VideoParam * param) {

	m_enum_state = videoState::STOP;
	m_frameHeight = param->fHeight;
	m_frameNumber = param->fNumber;
	m_frameWidht = param->fWidth;
	m_frameRate = param->fRate;
	m_fileName = param->path;
	m_isFinished = false;

	if(m_debug) {
		std::cout << "- Stream name  : " << m_fileName << std::endl;
		std::cout << "- Frame height : " << m_frameHeight << std::endl;
		std::cout << "- Frame widht  : " << m_frameWidht << std::endl;
		std::cout << "- Frame rate   : " << m_frameRate << std::endl;
		std::cout << "- Frame number : " << m_frameNumber << std::endl;
  	}

 	// Initialize member with default values
 	m_currentIndex = 0;
	m_totalFrameTime = 0;

 	m_texture.create(m_frameWidht, m_frameHeight);
 	m_sprite.setTexture(m_texture);

 	if(m_debug) {
 		std::cout << "- Texture height : " << m_texture.getSize().y << std::endl;
		std::cout << "- Texture widht  : " << m_texture.getSize().x << std::endl;
 	}

 	// Building vector
 	m_pathList.clear();
 	std::string part = "";
 	for(uint i = 1; i <= m_frameNumber; ++i) {
 		std::string str_i = cast::toString(i);

 		if(i < 10) part = "000" + str_i;
		else if(i < 100) part = "00" + str_i;
		else if(i < 1000) part = "0" + str_i;

		m_pathList.push_back(m_fileName + part + EXTENSION);
		part = "";
 	}

	return SUCCESS;
}

/*!
 * \brief Used to draw drawable object
 * \param window The window to draw frame
 * \param frameTime The time elapsed since clock restart
 */
void VideoPlayer::draw(sf::RenderWindow * window, double frameTime) {

	m_totalFrameTime += frameTime;
	if(m_enum_state == videoState::PLAY) {
		if(m_totalFrameTime >= 1 / (double)m_frameRate) {
			m_totalFrameTime = 0;
			if(m_currentIndex == m_frameNumber) {
				m_currentIndex = 1;
				m_isFinished = true;
				return;
			}
			else m_currentIndex++;
			m_texture.loadFromFile(m_pathList[m_currentIndex - 1]);
		}
	}

	window->draw(m_sprite);
}

/*!
 * \brief State the current state of the video
 * \param state a constant reference on a enum member
 */
void VideoPlayer::setVideoState(const videoState & state) {
	m_enum_state = state;
}

/*!
 * \brief
 * \return true if the current video is finished
 */
bool VideoPlayer::isFinished() {
	return m_isFinished;
}