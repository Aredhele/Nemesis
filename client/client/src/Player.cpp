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
			m_character.setAbility(0,"Toto","toto");
			m_character.setAbility(01,"Toto","toto");
			m_character.setAbility(02,"Toto", "toto");
			m_character.setAbility(03, "Toto", "toto");
			std::cout << "Eldora's caracteristics and abilities have been set" << std::endl;
			break;
		case 1:
			m_character.setCaracteristics(500,4000,35);
			m_character.setAbility(10, "Toto", "toto");
			m_character.setAbility(11, "Toto", "toto");
			m_character.setAbility(12, "Toto", "toto");
			m_character.setAbility(13, "Toto", "toto");
			std::cout << "Remington's caracteristics and abilities have been set" << std::endl;
			break;
		case 2:
			m_character.setCaracteristics(250,7000,40);
			m_character.setAbility(20, "Toto", "toto");
			m_character.setAbility(21, "Toto", "toto");
			m_character.setAbility(22, "Toto", "toto");
			m_character.setAbility(23, "Toto", "toto");
			std::cout << "Tristan's caracteristics and abilities have been set" << std::endl;
			break;
		case 3:
			m_character.setCaracteristics(100,15000,50);
			m_character.setAbility(30, "Toto", "toto");
			m_character.setAbility(31, "Toto", "toto");
			m_character.setAbility(32, "Toto", "toto");
			m_character.setAbility(33, "Toto", "toto");
			std::cout << "Numero8's caracteristics and abilities have been set" << std::endl;
			break;

	}
}