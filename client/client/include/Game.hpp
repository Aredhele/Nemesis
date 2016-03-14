//
// Created by Jehan on 05/03/2016.
//

#ifndef CLIENT_GAME_HPP
#define CLIENT_GAME_HPP

#include "BasicInterface.hpp"
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include "Patch.hpp"



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
    sf::Texture *ptr_buttonHit;
    sf::Texture *ptr_buttonSummon;
    sf::Texture *ptr_launchGame;
    sf::Texture *ptr_buttonEldoraHealing;
    sf::Texture *ptr_buttonHittingRemington;

    NButton m_buttonEldoraInGame;
    NButton m_buttonRemingtonInGame;
    NButton m_buttonTristanInGame;
    NPanel m_panelTableInGame;
    bool firstConnect;

    NButton m_buttonNumero8InGame;
    NButton m_buttonMdjInGame;
    NButton m_launchGameButton;
    NButton m_monsterButton;
    NButton m_ambianceButton;
    NButton m_beachButton;
    NButton m_castleButton;
    NButton m_forestButton;
    NButton m_landButton;
    NButton m_roomButton;
    NButton m_crapaudButton;
    NButton m_dragonButton;
    NButton m_yetiButton;

    NPanel m_yetiPanel;
    NPanel m_dragonPanel;
    NPanel m_crapaudPanel;

    NPanel m_panelCharateristics;
    NPanel m_panelNameCharacter;
    NPanel m_panelAttack;
    NPanel m_panelDefense;
    NPanel m_panelHealth;
    NLabel m_labelNameCharacter;
    NLabel m_labelAttack;
    NLabel m_labelDefense;
    NLabel m_labelHealth;
    NLabel m_labelCharacteristics;

    NPanel m_panelChat;
    NTextField m_textChat;
    NButton m_arrowUp;
    NButton m_arrowDown;

    sf::Font m_fontLabel;
    sf::Font m_fontTextbox;


    //NPanel m_panelYeti;
    NPanel m_bibouPanel2;
    //NPanel m_panelDragon;
    //NPanel m_panelCrapaud;
    NPanel m_contentPaneBackground;
    NPanel m_panelMJ;
    NPanel m_panelAmbianceMJ;
    NPanel m_panelMonstresMJ;

    NPanel m_panelIconAttack;
    NPanel m_panelIconDefense;
    NPanel m_panelIconHealth;

    NButton m_buttonHit;
    NButton m_buttonSummon;

    bool m_isOnMonstrePanel;
    bool m_isOnAmbiancePanel;

    std::string selectedMonster;

    bool isSpecial;
    bool isHitting;

    void displayFeature(std::string);
    void characterHits(std::string monster);
    void monsterHits(std::string character, std::string monster);
    void characterSummons(std::string monster);
    void monsterSummons(std::string character, std::string monster);
    void summonEldoraHealing(std::string character, int maxPv);


public:
    // Constructor
    Game(bool debug, ManagerGroup * ptr_managerGroup);


    // Destructor
    ~Game();

    // Methods
    virtual void update(sf::RenderWindow * window,
                        sf::Event * e, double frameTime);

    void receiveRequest();
};






#endif //CLIENT_GAME_HPP
