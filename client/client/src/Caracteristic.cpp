//
// Created by Jehan on 05/03/2016.
//

#include "Caracteristic.hpp"

Caracteristic::Caracteristic(){
	m_attackDamage = 0;
	m_health = 0;
	m_armor = 0;
}

Caracteristic::~Caracteristic(){ }


int Caracteristic::getHealth(){
	return m_health;
}


int Caracteristic::getArmor(){
	return m_armor;
}

int Caracteristic::getAttackDamage(){
	return m_attackDamage;
}

void Caracteristic::setCaracteristics(int atckDmg, int health, int armor){
	m_attackDamage = atckDmg;
	m_health = health;
	m_armor = armor;
}

