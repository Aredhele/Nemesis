/*!
 * Create by Jehan
 * Lobby
 */

#ifndef DEF_LOBBY_HPP
#define DEF_LOBBY_HPP

#include "BasicInterface.hpp"
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include "Patch.hpp"

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
    NButton m_refreshButton;
    NButton m_createButton;

    bool firstConnect;

    void requestJoinWarmUp(int id);
    void requestUpdateWarmUp();
    void requestCreateNewWarmUp();
    void updateNewWarmUp(std::string sRequest);

public:
    // Constructor
    Lobby(bool debug, ManagerGroup * ptr_managerGroup);

    // Destructor
    ~Lobby();

    // Methods
    virtual void update(sf::RenderWindow * window,
                        sf::Event * e, double frameTime);
    void receiveRequest();
};

#endif // DEF_LOGING_MENU_HPP