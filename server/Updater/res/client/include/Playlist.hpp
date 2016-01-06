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
        bool m_loop;
        bool m_debug;
        bool m_isFinished;
        bool m_isActive;
        unsigned int m_currentIndex;

        sf::Music m_music;
        std::vector < std::string > m_pathList;

    public:
        // Constructor
        Playlist(bool debug, int volume, bool loop, float pitch);

        // Destructor
        ~Playlist();

        // Methods
        void addMusic(std::string path);
        void update();
        void next();
        void load();
        void play();
        void stop();
        void pause();
        void setVolume(int volume);
        void setPitch(float pitch);

        // Getters
        bool isFinished();
};

#endif // DEF_PLAYLIST_HPP
