/**
 * \brief Manage all musics & sounds
 * \file MusicManager.hpp
 * \author Aredhele
 * \version 0.1
 * \date 13/12/2015
 * \class MusicManager.cpp
 */

#ifndef DEF_MUSIC_MANAGER_HPP
#define DEF_MUSIC_MANAGER_HPP

#include <map>
#include <vector>
#include <string>

#include "Playlist.hpp"

class MusicManager
{
    private:
        std::vector < std::string > m_keyList;
        std::map < std::string, Playlist * > m_playlistMap;
        std::vector < sf::SoundBuffer * > m_soundBufferList;
        std::map < std::string, sf::Sound * > m_soundMap;

        unsigned int m_currentPlaylist;
        bool m_playListLoop;
        bool m_debug;

    public:
        // Constructor
        MusicManager(bool debug, bool ploop);

        // Destructor
        ~MusicManager();

        // Methods
        void update();
        void startPlaylist(std::string key);
        void playPlaylist();
        void pausePlaylist();
        void stopPlaylist();
        void createPlaylist(std::string key, int volume, int loop, float pitch);
        void createSound(std::string path, std::string key, int volume, float pitch);

        // Getters
        Playlist * getPlaylist(std::string key);
        void playSound(std::string key);
};

#endif // DEF_MUSIC_MANAGER_HPP
