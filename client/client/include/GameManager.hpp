//
// Created by Lucas on 02/03/2016.
//

#ifndef DEF_GAME_MANAGER_HPP
#define DEF_GAME_MANAGER_HPP

#include "Manager.hpp"
#include "Player.hpp"
#include "Character.hpp"
#include <vector>

#include <string>

class GameManager : public Manager {

    private:
        bool m_debug;
        Player  m_player;
        std::vector < Character* > m_characterList;

    public:
        // Constructor
        GameManager(bool debug);

        // Destructor
        ~GameManager();
        void initCharacters();
        Player *  getPlayer();

};


#endif // DEF_GAME_MANAGER_HPP
