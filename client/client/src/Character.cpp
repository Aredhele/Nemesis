//
// Created by Lucas on 02/03/2016.
//

#include "Character.hpp"

Character::Character(){

    m_choosed = false;

}

Character::~Character(){

}

void Character::selectCharacter(){
    m_choosed = true;
}

void Character::deselectCharacter(){
    m_choosed = false;
}

std::wstring Character::getDescription(){
    return m_description;
}

std::wstring Character::getName(){
    return m_name;
}

void Character::setName(std::wstring name){
    m_name = name;
}

void Character::setDescription(std::wstring description){
    m_description = description;
}

void Character::setId(std::wstring id){
    m_id = id;
}

