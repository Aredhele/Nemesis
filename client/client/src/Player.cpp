//
// Created by Lucas on 02/03/2016.
//
#include "Player.hpp"

Player::Player(){

}

Player::~Player(){

}

void Player::setName(std::string name){
    m_name = name;
}

std::string Player::getName(){
    return m_name;
}

