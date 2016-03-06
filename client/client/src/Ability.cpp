//
// Created by Jehan on 05/03/2016.
//

#include "Ability.hpp"
/**
*TYPE: 1er caractère: s pour soi meme, e pour ennemi, a pour allié
*2eme caractère: un int avec les dmg
*3eme car: une chaine avec un type de dégat "spécial", altération etc
**/
Ability::Ability(){
	m_id = 0;
	m_name = "";
	m_type =""; 
}

Ability::~Ability() {}

std::string Ability::getType(){
	return m_type;
}
int Ability::getId(){
	return m_id;
}
std::string Ability::getName(){
	return m_name;
}
void Ability::setAbility(int id, std::string name,std::string type){
	m_type = type;
	m_name = name;
	m_id = id;
}