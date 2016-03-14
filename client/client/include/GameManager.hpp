//
// Created by Lucas on 02/03/2016.
//

#ifndef DEF_GAME_MANAGER_HPP
#define DEF_GAME_MANAGER_HPP

#include "Manager.hpp"
#include "Player.hpp"
#include "Monster.hpp"
#include <vector>

#include <string>

class GameManager : public Manager {

    private:
        bool m_debug;
        Player m_player;
        Monster m_monster;
        std::vector < Character* > m_characterList;
        std::vector < Monster* > m_monsterList;

    public:
        // Constructor
        GameManager(bool debug);

        // Destructor
        ~GameManager();
        void initCharacters();
        void initMonsters();
        Player *  getPlayer();
        Monster * getMonster();
        Character* getCharacterById(std::string id);
        Monster* getMonsterById(std::string id);
};


#endif // DEF_GAME_MANAGER_HPP
