//
// Created by Lucas on 02/03/2016.
//

#include "Character.hpp"

Character::Character(){

	ptr_caracteristic = new Caracteristic();
	ptr_ability = new Ability();
    m_choosed = false;

}

Character::~Character(){}

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

void Character::setId(std::string id){
    m_id = id;
}

std::string Character::getId(){
    return m_id;
}

void Character::setCaracteristics(int atckDmg, int health, int armor){
	ptr_caracteristic->setCaracteristics(atckDmg, health, armor);
}

Caracteristic* Character::getCaracteristic(){
    return ptr_caracteristic;
}

void Character::setAbility(int id,std::string name,std::string type){
	ptr_ability->setAbility(id,name,type);
}

