/*!
 * \file VideoPlayer.hpp
 * \brief Play a video from a stream
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-23
 */
 
#ifndef DEF_VIDEO_PLAYER_HPP
#define DEF_VIDEO_PLAYER_HPP

#define EXTENSION ".jpg"

#include <string>
#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "VideoParam.hpp"
#include "Constant.hpp"
#include "Patch.hpp"

enum videoState {
	PLAY,
	PAUSE,
	STOP
};

class VideoPlayer
{
	using ushort = unsigned short;
	using uint = unsigned int;

	private:
		// Member
		bool m_debug;
		bool m_isFinished;
		videoState m_enum_state;

		std::string m_fileName;
		std::vector < std::string > m_pathList;

		ushort m_frameHeight;
		ushort m_frameWidht;
		ushort m_frameRate;
		ushort m_frameNumber;
		ushort m_currentIndex;

		double m_totalFrameTime;

		sf::Sprite m_sprite;
		sf::Texture m_texture;
		
	public:
		// Constructor
		VideoPlayer(bool debug);

		// Destructor
		virtual ~VideoPlayer();

		// Methods
		int init(VideoParam * param);

		void draw(sf::RenderWindow * window, double frameTime);

		// Getters
		videoState getVideoState();
		bool isFinished();

		// Setters
		void setVideoState(const videoState & state);
};

#endif // DEF_VIDEO_PLAYER_HPP