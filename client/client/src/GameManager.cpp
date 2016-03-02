//
// Created by Lucas on 02/03/2016.
//

#include <MusicManager.hpp>

/*!
 * \brief Constructor
 * \param debug The debug mode
 */
GameManager::GameManager(bool debug) : Manager() {
    m_debug = debug;

    //create a player
    m_player = new Player();


    //Create characters
    int nbChar = 4;

    for (int i = 0; i < nbChar; i++){
        characterList.push_back(new Character());
    }

    initCharacters();
}

/**
 * \brief Destructor
 */
GameManager::~GameManager() {

}


//Getters
Player * GameManager::getPlayer(){
    return &m_player;
}


/**
 * \brief Initialize de characters with a name and a description
 * \The id will serve to identify character to select one
 */
void GameManager::initCharacters(){
    characterList[0].setName(L"Numero 8");
    characterList[0].setId(L"numero8");
    characterList[1].setName(L"Remington");
    characterList[1].setId(L"remington");
    characterList[2].setName(L"Eldora Dragnir");
    characterList[2].setId(L"eldora");
    characterList[3].setName(L"Tristan de la Mortifère");
    characterList[3].setId(L"tristan");

    for (int i = 0; i < 4; i++){
        characterList[i].setDescription(L"Bonjour ! \nJe m\'appelle "
                                        + characterList[i].getName() + " !");
    }
}



