//
// Created by Lucas on 02/03/2016.
//
#include "Player.hpp"
#include <iostream>

Player::Player(){

    //m_ptr_managerGroup = ptr_managerGroup;
	m_ptr_character = new Character();
}

Player::~Player(){

}

void Player::setName(std::string name){
    m_name = name;
}

std::string Player::getName(){
    return m_name;
}

void Player::setCharacter(Character * ptr_character){
	m_ptr_character = ptr_character;
}

Character * Player::getCharacter(){
	return m_ptr_character;

}

