//
// Created by Lucas on 02/03/2016.
//

#ifndef DEF_PLAYER_HPP
#define DEF_PLAYER_HPP

#include "Character.hpp"

class Player{

private:
    std::wstring m_name;
    Character m_character;

public:
    //Constructor
    Player();

    //Deconstructor
    ~Player();

    //Methods
    void setName(std::wstring name);
    std::wstring getName();
};

#endif //DEF_PLAYER_HPP

