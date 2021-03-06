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

    NButton m_yetiMonsterButton;
    NButton m_dragonMonsterButton;
    NButton m_crapaudMonsterButton;
    NPanel m_feu;
    NPanel m_feu2;

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

    std::vector<NLabel*> m_labelChatVector;
    NPanel m_panelChat;
    NTextField m_textChat;
    NButton m_arrowUp;
    NButton m_arrowDown;

    AnimatableObject m_flammes;
    AnimatableObject m_flammes2;
    AnimatableObject m_mdjAnimation;
    AnimatableObject m_attackAnimation;
    AnimatableObject m_numero8Special;
    AnimatableObject m_eldoraSpecial;
    AnimatableObject m_remingtonSpecial;
    AnimatableObject m_tristanSpecial;


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

    NPanel m_numero8Mini;
    NPanel m_eldoraMini;
    NPanel m_tristanMini;
    NPanel m_remingtonMini;
    NPanel m_mdjMini;
    NPanel m_playerIcon;

    NButton m_buttonHit;
    NButton m_buttonSummon;

    bool m_isOnMonstrePanel = false;
    bool m_isOnAmbiancePanel= false;

    Player * m_player;
    std::string selectedMonster;
    std::string selectedChar;

    bool isSpecial;
    bool isHitting;
    bool isEldora = false;
    bool isRemington = false;
    bool isNumero8 = false;
    bool isTristan = false;
    bool isMdj = false;
    bool isOnCastle = true;
    bool hasCrapaud = false;
    bool hasDragon = false;
    bool hasYeti = false;

    void displayFeature(std::string);
    void characterAttack(std::string string, std::string idMonster);
    void monsterAttack(std::string idCharacter, std::string idMonster);
    void characterSpecialAttack(std::string idCharacter, std::string idMonster);
    void monsterSpecialAttack(std::string idCharacter, std::string idMonster);
    void eldoraHealing(std::string idCharacter);
    void checkStateAnimation();
    void specialAnimation(std::string cible, std::string attaquant);
    void attackAnimation(std::string id);
    void changeAmbiance(std::string ambiance);
    void displayMonster(int i, std::string monster);
public:
    // Constructor
    Game(bool debug, ManagerGroup * ptr_managerGroup);


    // Destructor
    ~Game();

    // Methods
    virtual void update(sf::RenderWindow * window,
                        sf::Event * e, double frameTime);

    void receiveRequest();
    void request(int idRequest, std::string sRequest, std::string sRequest2);
    void addTextToChat(std::string message, std::string perso);

    void initPlayerCharacter();
    Character * getCharacter(std::string id);
    Monster * getMonster(std::string id);
};






#endif //CLIENT_GAME_HPP
