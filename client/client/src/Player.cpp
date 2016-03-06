//
// Created by Lucas on 02/03/2016.
//
#include "Player.hpp"
#include <iostream>

Player::Player(): m_character(){

}

Player::~Player(){

}

void Player::setName(std::string name){
    m_name = name;
}

std::string Player::getName(){
    return m_name;
}
//id =0 pour Eldora, 1 pour Remington, 2 pour Tristan et 3 pour Numero8
void Player::setCharacter(int id){
	switch (id){
		case 0:
			m_character.setCaracteristics(50,3000,30);
			std::cout << "Eldora's caracteristics have been set" << std::endl;
			break;
		case 1:
			m_character.setCaracteristics(500,4000,35);
			std::cout << "Remington's caracteristics have been set" << std::endl;
			break;
		case 2:
			m_character.setCaracteristics(250,7000,40);
			std::cout << "Tristan's caracteristics have been set" << std::endl;
			break;
		case 3:
			m_character.setCaracteristics(100,15000,50);
			std::cout << "Numero8's caracteristics have been set" << std::endl;
			break;

	}
}