// Created by Rémi
// 10/03/2016
// ---------------

#include "Monster.hpp"


Monster::Monster(){

	ptr_caracteristic = new Caracteristic();
	m_choosed = false;
}

Monster::~Monster(){}

void Monster::selectMonster(){
	m_choosed = true;
}

void Monster::deselectMonster(){

	m_choosed = false;
}

bool Monster::isMonsterSelected(){

	return m_choosed;
}

std::wstring Monster::getName(){

	return m_name;
}

void Monster::setName(std::wstring name){

	m_name = name;

}

std::string Monster::getId(){

	return m_id;
}

void Monster::setId(std::string id){

	m_id = id;
}

void Monster::setCaracteristics(int atckDmg, int health, int armor){
	ptr_caracteristic->setCaracteristics(atckDmg, health, armor);
}

Caracteristic* Monster::getCaracteristic(){
    return ptr_caracteristic;
}

int Monster::hitDamage(int atckDmg, int pvEnemy){

    return pvEnemy - atckDmg;
}

int Monster::summonDamage(int atckDmg, int pvEnemy){

    return pvEnemy - 2 * atckDmg;
}



