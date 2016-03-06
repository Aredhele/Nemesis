//
// Created by Jehan on 05/03/2016.
//

#include "Ability.hpp"

Ability::Ability(){
	int m_damage;
	int m_length;
}

Ability::~Ability() {}

void Ability::setAbilityEldora(int dmg, int lgth){
	m_damage = dmg;
	m_length = lgth;
}

void Ability::setAbilityTristan(int dmg, int lgth){
	m_damage = dmg;
	m_length = lgth;
}
void Ability::setAbilityRemington(int dmg, int lgth){
	m_damage = dmg;
	m_length = lgth;
}
void Ability::setAbilityNumero8(int dmg, int lgth){
	m_damage = dmg;
	m_length = lgth;
}
int Ability::getAbilityDamage(){
	return m_damage;
}
int Ability::getAbilityLength(){
	return m_length;
}