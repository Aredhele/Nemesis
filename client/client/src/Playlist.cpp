/**
 * \brief Handle some musics
 * \file Playlist.cpp
 * \author Aredhele
 * \version 0.1
 * \date 13/12/2015
 * \class Playlist.hpp
 */

#include "Playlist.hpp"

/*
 * \brief Constructor
 * \param volume the volume of all music
 * \param loop number of loop in the playlist
 * \param pitch the frequency of the music
 */
Playlist::Playlist(bool debug, int volume, int loop, float pitch) {
    m_debug = debug;
    m_nbLoop = loop;
    m_volume = volume;
    m_active = false;
    m_currentIndex = 0;
    m_currentNbLoop = 1;
    m_isFinished = true;
    m_pitchValue = pitch;

    if(debug) {
        std::cout << "m_isFinished " << m_isFinished << std::endl;
        std::cout << "m_isActive " << m_active << std::endl;
    }
}

/*
 * \brief Destructor
 */
Playlist::~Playlist() {
    m_musicList.clear();
}

/*
 * \brief add a music to the vector
 * \param path the path of the music
 */
void Playlist::addMusic(std::string path) {
    sf::Music * ptr_music = nullptr;
	ptr_music = new sf::Music();

    // Opening music stream
    if(!ptr_music->openFromFile(path)) {
        if(m_debug)
            std::cerr << "Failed to open music stream" << std::endl;
    }

    ptr_music->setPitch(m_pitchValue);
    ptr_music->setVolume(m_volume);
    m_musicList.push_back(ptr_music);
}

/**
 * \brief Start the playlist
 */
void Playlist::start() {
    if(m_musicList.size() > 0) {
        m_active = true;
        m_isFinished = false;
        m_currentIndex = 0;
        m_musicList[m_currentIndex]->play();
    } else {
        if(m_debug)
            std::cerr << "No musics to play" << std::endl;
    }
}

/**
 * \brief Play the current song
 */
void Playlist::play() {
    m_active = true;
    m_musicList[m_currentIndex]->play();
    if(m_debug)
        std::cout << "Music played" << std::endl;
}

/**
 * \brief Pause the current song
 */
void Playlist::pause() {
    m_active = false;
    m_musicList[m_currentIndex]->pause();
    if(m_debug)
        std::cout << "Music paused" << std::endl;
}

/**
 * \brief Stop the playlist
 */
void Playlist::stop() {
    m_active = false;
    m_isFinished = true;
    m_musicList[m_currentIndex]->stop();
    m_currentIndex = 0;
    if(m_debug)
	   std::cout << "Music stopped" << std::endl;
}

/**
 * \brief Update the current music
 */
void Playlist::update() {
    if(m_active) {
        if(m_musicList[m_currentIndex]->getStatus() == sf::Music::Status::Stopped)
        {
            m_active = false;
            m_isFinished = true;
            if(m_currentIndex + 1 < m_musicList.size()) {
                m_currentIndex++;
                m_active = true;
                m_isFinished = false;
                m_musicList[m_currentIndex]->play();
                return;
            }
            else if(m_currentIndex + 1 >= m_musicList.size()) {
                if(m_currentNbLoop + 1 < m_nbLoop) {
                    m_currentIndex = 0;
                    m_active = true;
					m_isFinished = false;
                    m_musicList[m_currentIndex]->play();
                } else {
                    m_isFinished = true;
                    m_currentIndex = 0;
                    m_active = false;
                    return;
                }
            }
        }
    }
}

/*
 * \brief return the global state of the playlist
 */
bool Playlist::isFinished() {
    return m_isFinished;
}