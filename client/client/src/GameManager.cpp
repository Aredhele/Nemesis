//
// Created by Lucas on 02/03/2016.
//

#include <GameManager.hpp>

/*!
 * \brief Constructor
 * \param debug The debug mode
 */
GameManager::GameManager(bool debug) : Manager(),
                                       m_player()
                                               {

    m_debug = debug;

    //Create characters
    int nbChar = 4;

    for (int i = 0; i < nbChar; i++){
        m_characterList.push_back(new Character());
    }

    initCharacters();
}

/**
 * \brief Destructor
 */
GameManager::~GameManager() {

}


//Getters
Player *  GameManager::getPlayer(){
    return &m_player;
}


/**
 * \brief Initialize de characters with a name and a description
 * \The id will serve to identify character to select one
 */
void GameManager::initCharacters(){
    m_characterList[0]->setName(L"Numero 8");
    m_characterList[0]->setId(L"numero8");
    m_characterList[1]->setName(L"Remington");
    m_characterList[1]->setId(L"remington");
    m_characterList[2]->setName(L"Eldora Dragnir");
    m_characterList[2]->setId(L"eldora");
    m_characterList[3]->setName(L"Tristan de la Mortifère");
    m_characterList[3]->setId(L"tristan");

    for (int i = 0; i < 4; i++){
        m_characterList[i]->setDescription(L"Bonjour ! \nJe m\'appelle "
                                        + m_characterList[i]->getName()
                                           + L" !");
    }
}



