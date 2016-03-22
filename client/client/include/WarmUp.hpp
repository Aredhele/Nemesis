//
// Created by Lucas on 01/03/2016.
//

#ifndef DEF_WARM_UP_HPP
#define DEF_WARM_UP_HPP

#include "BasicInterface.hpp"
#include "Patch.hpp"
#include "SFML/System.hpp"

class WarmUp : public BasicInterface
{
    private:

        bool m_charSelected;
        bool m_firstConnect;

        NButton m_numero8Button;
        NButton m_remingtonButton;
        NButton m_tristanButton;
        NButton m_eldoraButton;
        NButton m_mdjButton;
        NButton m_validateCharacterButton;

        NPanel m_selectCharacterPanel;
        NPanel m_infoCharacterPanel;
        NLabel m_infoCharacterLabel;

        NLabel m_numero8LockLabel;
        NLabel m_eldoraLockLabel;
        NLabel m_remingtonLockLabel;
        NLabel m_tristanLockLabel;
        NLabel m_mdjLockLabel;


        NButton m_playButton;
        NButton m_returnButton;

        NPanel m_characterLockPanel1;
        NPanel m_characterLockPanel2;
        NPanel m_characterLockPanel3;
        NPanel m_characterLockPanel4;

        NPanel m_numero8Lock;
        NPanel m_eldoraLock;
        NPanel m_tristanLock;
        NPanel m_remingtonLock;
        NPanel m_mdjLock;

        AnimatableObject m_loading;


        sf::Font m_fontLabel;
        sf::Font m_fontLabel2;

        int m_nbPlayer;
        int m_nbCharLocked;
        bool m_waiting;
        std::string m_characterSelected;


public:
        // Constructor
        WarmUp(bool debug, ManagerGroup * ptr_managerGroup);

        // Destructor
        ~WarmUp();

        // Methods
        virtual void update(sf::RenderWindow * window,
                            sf::Event * e, double frameTime);

        void displayInfoCharacters(std::string characterName);

        void receiveRequest();

        void blockCharacters();

    void blockCharacter(std::string characterName, std::string playerName );

    void adaptPosition(NPanel *panel, NLabel *label);

    std::wstring s2ws(std::string string);
};

#endif //CLIENT_WARMUP_HPP
