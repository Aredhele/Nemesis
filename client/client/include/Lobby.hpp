/*!
 * Create by Jehan
 * Lobby
 */

#ifndef DEF_LOBBY_HPP
#define DEF_LOGING_MENU_HPP

#include "BasicInterface.hpp"

class Lobby : public BasicInterface
{
private:
    NLabel m_monSuperLabel;
    sf::Font m_font;


public:
    // Constructor
    Lobby(bool debug, ManagerGroup * ptr_managerGroup);

    // Destructor
    ~Lobby();

    // Methods
    virtual void update(sf::RenderWindow * window,
                        sf::Event * e, double frameTime);
};

#endif // DEF_LOGING_MENU_HPP