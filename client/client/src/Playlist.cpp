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
 * \param loop if true endless loop
 * \param pitch the frequency of the music
 */
Playlist::Playlist(bool debug, int volume, bool loop, 
float pitch) : m_music() {

    m_loop = loop;
    m_debug = debug;
    m_isFinished = true;
    m_isActive = false;
    m_currentIndex = 0;
    m_music.setPitch(pitch);
    m_music.setVolume(volume);
}

/*
 * \brief Destructor
 */
Playlist::~Playlist() {
    // None
}

/*!
 * \brief Add a music path to the list
 * \param path The path to the music
 */
void Playlist::addMusic(std::string path) {
    m_pathList.push_back(path);
}

/*!
 * \brief Check the state of the current music
 * \return None
 */
void Playlist::update() {

    if(!m_isActive) return;

    switch(m_music.getStatus()) 
    {
        case sf::Music::Status::Stopped:
            next();
            break;

        case sf::Music::Status::Playing:
            break;

        case sf::Music::Status::Paused:
            break;

        default:
            break;
    }
}

/*!
 * \brief Handle next music
 */
void Playlist::next() {

    if(m_currentIndex + 1 < m_pathList.size())
    {
        m_currentIndex++;
        load();
    } 
    else
    {
        if(m_loop) {
            m_currentIndex = 0;
            load();
        } else {
            m_isFinished = true;
        }
    }
}

/*!
 * \brief Open a music from a file
 */
void Playlist::load() {
    m_music.openFromFile(m_pathList[m_currentIndex]);
    play();
}

/*!
 * \brief Play the current song
 */
void Playlist::play() {
    if(m_debug) {
        std::cout << "- Playing : ";
        std::cout << m_pathList[m_currentIndex] << std::endl;
    }
    m_isFinished = false;
    m_isActive = true;
    m_music.play();
}

/*!
 * \brief Pause the current song
 */
void Playlist::pause() {
    m_music.pause();
}

/*!
 * \brief Stop the current song
 */
void Playlist::stop() {
    m_music.stop();
    m_isFinished = true;
    m_isActive = false;
}

/*!
 * \brief Change the volume
 * \param volume The volume to assign
 */
void Playlist::setVolume(int volume) {
    m_music.setVolume(volume);  
}

/*!
 * \brief Change the pitch of the current song
 * \param pitch The pitch to assign
 */
void Playlist::setPitch(float pitch) {
    m_music.setPitch(pitch);
}

/*!
 * \return true if the music is stopped
 */
bool Playlist::isFinished() {
    return m_isFinished;
}