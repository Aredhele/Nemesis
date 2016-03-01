/*!
 * Create by Jehan
 * Lobby
 */

#ifndef DEF_LOBBY_HPP
#define DEF_LOBBY_HPP

#include "BasicInterface.hpp"
#include <sstream>

class Lobby : public BasicInterface
{
private:
    NLabel m_monSuperLabel;
    sf::Font m_font;
    std::vector <NButton*> warmUpButton;
    std::vector <NLabel*> warmUpLabel;
    int nbWarmUp;
    sf::Texture *ptr_textureButton1;
    sf::Texture *ptr_textureButton2;

    void updateNewWarmUp();

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