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
    int nbChar = 5;

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
    m_characterList[0]->setId("numero8");
    m_characterList[1]->setName(L"Remington");
    m_characterList[1]->setId("remington");
    m_characterList[2]->setName(L"Eldora Dragnir");
    m_characterList[2]->setId("eldora");
    m_characterList[3]->setName(L"Tristan de la Mortifère");
    m_characterList[3]->setId("tristan");
    m_characterList[4]->setName(L"Maitre du jeu");
    m_characterList[4]->setId("mdj");

    for (int i = 0; i < 5; i++){
        m_characterList[i]->setDescription(L"Bonjour ! \nJe m\'appelle "
                                        + m_characterList[i]->getName()
                                           + L" !");
    }
}

Character* GameManager::getCharacterById(std::string id){
    for(int i = 0; i<m_characterList.size(); i++){
        if(m_characterList[i]->getId()==id){
            return m_characterList[i];
        }
    }
    return 0;

}



