//
// Created by Jehan on 05/03/2016.
//

#ifndef CLIENT_GAME_HPP
#define CLIENT_GAME_HPP

#include "BasicInterface.hpp"


class Game : public BasicInterface {
private:


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
