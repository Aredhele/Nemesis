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
//id =0 pour Eldora, 1 pour Remington, 2 pour Tristan et 3 pour Numero8
void Player::setCharacter(int id){
	//m_ptr_character = m_ptr_managerGroup->ptr_gameManager->getCharacterById(id);


	switch (id){
		case 0:
			ptr_character->setName(L"Eldora");
			ptr_character->setCaracteristics(50,3000,30);
			ptr_character->setAbility(0,"Toto","toto");
			ptr_character->setAbility(01,"Toto","toto");
			ptr_character->setAbility(02,"Toto", "toto");
			ptr_character->setAbility(03, "Toto", "toto");
			std::cout << "Eldora's caracteristics and abilities have been set" << std::endl;
			break;
		case 1:
			ptr_character->setName(L"Remington");
			ptr_character->setCaracteristics(500,4000,35);
			ptr_character->setAbility(10, "Toto", "toto");
			ptr_character->setAbility(11, "Toto", "toto");
			ptr_character->setAbility(12, "Toto", "toto");
			ptr_character->setAbility(13, "Toto", "toto");
			std::cout << "Remington's caracteristics and abilities have been set" << std::endl;
			break;
		case 2:
			ptr_character->setName(L"Tristan");
			ptr_character->setCaracteristics(250,7000,40);
			ptr_character->setAbility(20, "Toto", "toto");
			ptr_character->setAbility(21, "Toto", "toto");
			ptr_character->setAbility(22, "Toto", "toto");
			ptr_character->setAbility(23, "Toto", "toto");
			std::cout << "Tristan's caracteristics and abilities have been set" << std::endl;
			break;
		case 3:
			ptr_character->setName(L"Numero8");
			ptr_character->setCaracteristics(100,15000,50);
			ptr_character->setAbility(30, "Toto", "toto");
			ptr_character->setAbility(31, "Toto", "toto");
			ptr_character->setAbility(32, "Toto", "toto");
			ptr_character->setAbility(33, "Toto", "toto");
			std::cout << "Numero8's caracteristics and abilities have been set" << std::endl;
			break;
		case 4:
			ptr_character->setName(L"MDJ");
			ptr_character->setCaracteristics(0,0,0);
			ptr_character->setAbility(40, "Toto", "toto");
			ptr_character->setAbility(41, "Toto", "toto");
			ptr_character->setAbility(42, "Toto", "toto");
			ptr_character->setAbility(43, "Toto", "toto");
			std::cout << "MDJ's caracteristics and abilities have been set" << std::endl;
			break;

	}



}

Character * Player::getCharacter(){
	return ptr_character;
}