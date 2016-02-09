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
    /*ptr_managerGroup->ptr_musicManager->
            createPlaylist("playlistMenu", 50, true, 1.2);
    ptr_managerGroup->ptr_musicManager->
            getPlaylist("playlistMenu")->addMusic("../res/music/menu/Epipath.ogg");
    ptr_managerGroup->ptr_musicManager->
            getPlaylist("playlistMenu")->play();*/

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

    // Basic Interface updating
    basicInput(e, frameTime);

    // Drawing all content
    basicDraw(window);
}