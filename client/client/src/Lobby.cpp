//
// Created by Jehan on 08/02/2016.
//

#include "Lobby.hpp"
/*!
 * \brief Constructor
 */
Lobby::Lobby(bool debug, ManagerGroup * ptr_managerGroup) :
        BasicInterface(debug, ptr_managerGroup),
        m_monSuperLabel()
{

    ptr_textureButton1 = ptr_managerGroup->ptr_textureManager->getTexture("connectButton1");
    ptr_textureButton2 = ptr_managerGroup->ptr_textureManager->getTexture("connectButton2");

    if (!m_font.loadFromFile("../res/font/Quicksand.ttf"))
    {
        std::cout << "Probleme dans le chargement des textures" << std::endl;
    }

    m_monSuperLabel.create("monSuperLabel", 450, 100, 20, &m_font, L"Parties en cours...", sf::Color::Black);


    getContentPane()->addComponent(&m_monSuperLabel);

}

/*!
 * \brief Constructor
 */
Lobby::~Lobby() {
    // TODO
}

/*!
 * \brief Update current object
 * \param window The pointer on the window
 * \param frameTime The elpased time
 */
void Lobby::update(sf::RenderWindow * window,
                       sf::Event * e, double frameTime) {


    if(!m_ptr_managerGroup->ptr_targetManager->isLobby())
        return;

    nbWarmUp = 4;
    updateNewWarmUp();

    // Basic Interface updating
    basicInput(e, frameTime);

    // Drawing all content
    basicDraw(window);
}

void Lobby::updateNewWarmUp(){

    for(int i = 0; i < nbWarmUp; ++i){
        warmUpButton.push_back(new NButton());
        warmUpButton[i]->create("connectButton"+i, 550, 250 + i *75,
                               ptr_textureButton1, ptr_textureButton2);
        getContentPane()->addComponent(warmUpButton[i]);
    }

    for(int i = 0; i < nbWarmUp; ++i){
        //Convert i to wString
        std::wostringstream ws;
        ws << i+1;
        const std::wstring s(ws.str());

        warmUpLabel.push_back(new NLabel());
        warmUpLabel[i]->create("monSuperLabel"+i, 200, 255 + i *75,
                              30, &m_font, L"Partie  " +s, sf::Color::Black);
        getContentPane()->addComponent(warmUpLabel[i]);
    }
}