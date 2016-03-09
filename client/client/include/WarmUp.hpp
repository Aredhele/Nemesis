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
        NButton m_numero8Button;
        NButton m_remingtonButton;
        NButton m_tristanButton;
        NButton m_eldoraButton;
        NButton m_mdjButton;
        NButton m_validateCharacterButton;

        NPanel m_selectCharacterPanel;
        NPanel m_infoCharacterPanel;
        NLabel m_infoCharacterLabel;

        NButton m_playButton;
        NButton m_returnButton;

        sf::Font m_fontLabel;


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
};

#endif //CLIENT_WARMUP_HPP
