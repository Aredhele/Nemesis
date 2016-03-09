//
// Created by Jehan on 05/03/2016.
//

#ifndef CLIENT_GAME_HPP
#define CLIENT_GAME_HPP

#include "BasicInterface.hpp"
#include <sstream>




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
    NButton m_buttonEldoraInGame;
    NButton m_buttonRemingtonInGame;
    NButton m_buttonTristanInGame;
    NPanel m_panelTableInGame;
    NButton m_buttonNumero8InGame;
    NButton m_buttonMdjInGame;
    NPanel m_panelCharateristics;
    NPanel m_panelNameCharacter;
    NPanel m_panelAttack;
    NPanel m_panelDefense;
    NPanel m_panelHealth;
    NLabel m_labelNameCharacter;
    NLabel m_labelAttack;
    NLabel m_labelDefense;
    NLabel m_labelHealth;

    NPanel m_panelChat;
    NTextField m_textFieldLogin;

    sf::Font m_fontLabel;
    sf::Font m_fontTextbox;


    NPanel m_panelYeti;
    NPanel m_bibouPanel;
    NPanel m_panelDragon;
    NPanel m_panelCrapaud;
    NPanel m_contentPaneBackground;

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
