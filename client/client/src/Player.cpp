//
// Created by Lucas on 02/03/2016.
//
#include "Player.hpp"
#include <iostream>

Player::Player(){

	ptr_character = new Character();
}

Player::~Player(){

}

void Player::setName(std::string name){
    m_name = name;
}

std::string Player::getName(){
    return m_name;
}

void Player::setCharacter(int id){
	//m_ptr_character = m_ptr_managerGroup->ptr_gameManager->getCharacterById(id);
}

Character * Player::getCharacter(){
	return ptr_character;

}

