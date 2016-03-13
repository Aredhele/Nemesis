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
    int nbMob = 3;


    for (int i = 0; i < nbChar; i++){
        m_characterList.push_back(new Character());
    }

    for (int j = 0; j < nbMob; j++){

        m_monsterList.push_back(new Monster());
    }

    initCharacters();
    initMonsters();
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

Monster * GameManager::getMonster(){
    return &m_monster;
}


/**
 * \brief Initialize de characters with a name and a description
 * \The id will serve to identify character to select one
 */
void GameManager::initCharacters(){

    m_characterList[0]->setName(L"Numero 8");
    m_characterList[0]->setId("numero8");
    m_characterList[0]->setDescription(L"Salut à toi !\n J’ai pour seul nom le chiffre 8.\nIl me vient de la prison dans laquelle je suis née.\nJ’y ai été entrainé pour devenir un guerrier puissant. Rien ne m’arrête !\nJe fonce dans la bataille tête baissée et je n’ai jamais été vaincu. ");
    m_characterList[0]->setCaracteristics(200,3000,30);
    m_characterList[0]->setAbility(0,"Toto","toto");

    m_characterList[1]->setName(L"Remington");
    m_characterList[1]->setId("remington");
    m_characterList[1]->setDescription(L"… Je suis né de la nuit.\nRelevé parmi les morts, j’aime les recoins sombres et discrets pour frapper\nmes ennemis dans le dos.");
    m_characterList[1]->setCaracteristics(300,1500,30);
    m_characterList[1]->setAbility(10, "Toto", "toto");

    m_characterList[2]->setName(L"Eldora Dragnir");
    m_characterList[2]->setId("eldora");
    m_characterList[2]->setDescription(L"Bonjour à vous !\nJe suis une elfe de la lumière.\nElevée dans le royaume de la Lorian, mes compétences en soin sont inégalées\ndans toutes les terres du nord.");
    m_characterList[2]->setCaracteristics(100,5000,40);
    m_characterList[2]->setAbility(20, "Toto", "toto");

    m_characterList[3]->setName(L"Tristan de la Mortifère");
    m_characterList[3]->setId("tristan");
    m_characterList[3]->setDescription(L"Je me nomme Tristan de la Mortifère.\nJe suis originaire du Royaume du Sud.\nMon père, le duc de Mortifère, m’a entrainé depuis mon enfance à tous\nles styles de combats.\nMa polyvalence fait de moi un chevalier redoutable.");
    m_characterList[3]->setCaracteristics(150,3000,35);
    m_characterList[3]->setAbility(30, "Toto", "toto");

    m_characterList[4]->setName(L"Maitre du jeu");
    m_characterList[4]->setId("mdj");
    m_characterList[4]->setDescription(L"Bienvenue voyageur ! \nJe suis le maître du jeu. \nVotre destin reposera entre mes mains…");
    m_characterList[4]->setCaracteristics(0,0,0);
    m_characterList[4]->setAbility(40, "Toto", "toto");

    /*for (int i = 0; i < 5; i++){
        m_characterList[i]->setDescription(L"Bonjour ! \nJe m\'appelle "
                                        + m_characterList[i]->getName()
                                           + L" !");
    }*/
}

void GameManager::initMonsters(){

    m_monsterList[0]->setName(L"Yeti des montagnes");
    m_monsterList[0]->setId("yeti");
    m_monsterList[0]->setCaracteristics(50,500,40);

    m_monsterList[1]->setName(L"Dragon du chateau");
    m_monsterList[1]->setId("dragon");
    m_monsterList[1]->setCaracteristics(300,5000,20);

    m_monsterList[2]->setName(L"Crapaux gluant");
    m_monsterList[2]->setId("crapaud");
    m_monsterList[2]->setCaracteristics(5,500,10);
}

Character* GameManager::getCharacterById(std::string id){
    for(int i = 0; i<m_characterList.size(); i++){
        if(m_characterList[i]->getId()==id){
            return m_characterList[i];
        }
    }
    return 0;

}

Monster* GameManager::getMonsterById(std::string id){

    for (int i = 0; i < m_monsterList.size(); i++){
        if (m_monsterList[i]->getId()==id){
            return m_monsterList[i];
        }
    }
}



