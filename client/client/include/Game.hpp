//
// Created by Jehan on 05/03/2016.
//

#ifndef CLIENT_GAME_HPP
#define CLIENT_GAME_HPP

#include "BasicInterface.hpp"


class Game : public BasicInterface {
private:
    sf::Texture *ptr_eldoraInGame;
    sf::Texture *ptr_remingtonInGame;
    sf::Texture *ptr_tristanInGame;
    sf::Texture *ptr_tableInGame;
    sf::Texture *ptr_numero8InGame;
    sf::Texture *ptr_crapaud;
    sf::Texture *ptr_dragon;
    sf::Texture *ptr_yeti;
    sf::Texture *ptr_mdjInGame;
    NPanel m_panelEldoraInGame;
    NPanel m_panelRemingtonInGame;
    NPanel m_panelTristanInGame;
    NPanel m_panelTableInGame;
    NPanel m_panelNumero8InGame;
    NPanel m_panelMdjInGame;
    NPanel m_panelYeti;
    NPanel m_panelDragon;
    NPanel m_panelCrapaud;

public:
    // Constructor
    Game(bool debug, ManagerGroup * ptr_managerGroup);


    // Destructor
    ~Game();

    // Methods
    virtual void update(sf::RenderWindow * window,
                        sf::Event * e, double frameTime);
};






#endif //CLIENT_GAME_HPP
