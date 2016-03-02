//
// Created by Lucas on 02/03/2016.
//

Player::Player(){

}

Player::~Player(){

}

void Player::setName(std::wstring name){
    m_name = name;
}

std::wstring Player::getName(){
    return m_name;
}

