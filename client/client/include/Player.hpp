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
    Character m_character;

public:
    //Constructor
    Player();

    //Deconstructor
    ~Player();

    //Methods
    void setName(std::string name);
    std::string getName();
};

#endif //DEF_PLAYER_HPP

