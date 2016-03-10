//
// Created by Lucas on 02/03/2016.
//

#ifndef DEF_PLAYER_HPP
#define DEF_PLAYER_HPP

#include <string>
#include "Character.hpp"

class Player{

private:
    std::string m_name;
    Character * m_ptr_character;
    //ManagerGroup * m_ptr_managerGroup;

public:
    //Constructor
    Player();

    //Deconstructor
    ~Player();

    //Methods
    void setName(std::string name);
    std::string getName();
    void setCharacter(Character * ptr_character);

    //Getters
    Character * getCharacter();
};

#endif //DEF_PLAYER_HPP

