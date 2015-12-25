/**
 * \brief Handle some musics
 * \file Playlist.hpp
 * \author Aredhele
 * \version 0.1
 * \date 13/12/2015
 * \class Playlist.cpp
 */

#ifndef DEF_PLAYLIST_HPP
#define DEF_PLAYLIST_HPP

#include <vector>
#include <iostream>

#include <SFML/Audio.hpp>

class Playlist
{
    private:
        // Member
        unsigned int m_nbLoop;
        unsigned int m_currentNbLoop;
        unsigned int m_volume;
        unsigned int m_currentIndex;
        bool m_isFinished;
        bool m_active;
        bool m_debug;
        float m_pitchValue;

        std::vector < sf::Music * > m_musicList;

    public:
        // Constructor
        Playlist(bool debug, int volume, int loop, float pitch);

        // Destructor
        ~Playlist();

        // Methods
        void addMusic(std::string path);
        void start();
        void play();
        void pause();
        void stop();
        void update();

        // Getters
        bool isFinished();
};

#endif // DEF_PLAYLIST_HPP
