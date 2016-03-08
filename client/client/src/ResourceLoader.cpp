/*!
 * \file resourceLoader.cpp
 * \brief Load all resources in a thread
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-25
 */

#include "ResourceLoader.hpp"

/*!
 * \brief Constructor
 * \param debug the debug mode
 */
ResourceLoader::ResourceLoader(bool debug) : m_managerGroup(),
											 m_thread(&ResourceLoader::load, this) {
	m_debug = debug;

	m_managerGroup.ptr_musicManager = new MusicManager(m_debug); //The default volume
	m_managerGroup.ptr_textureManager = new TextureManager(m_debug);
	m_managerGroup.ptr_targetManager = new TargetManager(m_debug);
	m_managerGroup.ptr_optionManager = new OptionManager(m_debug);
	m_managerGroup.ptr_networkManager = new NetworkManager(m_debug);
    m_managerGroup.ptr_gameManager = new GameManager(m_debug);

	m_managerGroup.ptr_musicManager->setState(false);
	m_managerGroup.ptr_textureManager->setState(false);
	m_managerGroup.ptr_targetManager->setState(false);
	m_managerGroup.ptr_optionManager->setState(false);
	m_managerGroup.ptr_networkManager->setState(false);
    m_managerGroup.ptr_gameManager->setState(false);
}

/*!
 * \brief Destructor
 */
ResourceLoader::~ResourceLoader() {
	// None
}

/*!
 * \brief Load all ressource in a thread
 * \brief to not lock the main thread
 */
void ResourceLoader::load() {

	// Aliases
	MusicManager& a_mm = *m_managerGroup.ptr_musicManager;
	TextureManager& a_tm = *m_managerGroup.ptr_textureManager;
	TargetManager& a_tarm = *m_managerGroup.ptr_targetManager;
	OptionManager& a_optm = *m_managerGroup.ptr_optionManager;
	NetworkManager& a_ntwm = *m_managerGroup.ptr_networkManager;
    GameManager& a_gm = *m_managerGroup.ptr_gameManager;


	// Path
	const std::string pathLogin = "../res/texture/menu/login/";
	const std::string pathChar = "../res/characters/";

	// Loading ...
	a_tm.addTexture("topBarLogMenu", pathLogin + "topBarLogMenu.png");
	a_tm.addTexture("topBarOptButton_1", pathLogin + "topBarOptionButton_1.png");
	a_tm.addTexture("topBarOptButton_2", pathLogin + "topBarOptionButton_2.png");

	a_tm.addTexture("topBarOptButton_3", pathLogin + "topBarOptionButton_1.png");
	a_tm.addTexture("topBarOptButton_4", pathLogin + "topBarOptionButton_2.png");

	a_tm.addTexture("topBarExitButton_1", pathLogin + "topBarExitButton_1.png");
	a_tm.addTexture("topBarExitButton_2", pathLogin + "topBarExitButton_2.png");
	a_tm.addTexture("loginBackground", pathLogin + "background.png");
	a_tm.addTexture("optionPane", pathLogin + "optionPane.png");
	a_tm.addTexture("altimitLoad", pathLogin + "altimitFull.png");
	a_tm.addTexture("simplePanel", pathLogin + "simplePanel.png");
	a_tm.addTexture("connexion_1", pathLogin + "connexion_1.png");
	a_tm.addTexture("connectButton1", pathLogin + "connect_1.png");
	a_tm.addTexture("connectButton2", pathLogin + "connect_2.png");
	a_tm.addTexture("volume_1", pathLogin + "volume_1.png");
	a_tm.addTexture("volume_2", pathLogin + "volume_2.png");
	a_tm.addTexture("volumeOff_1", pathLogin + "volumeOff_1.png");
	a_tm.addTexture("volumeOff_2", pathLogin + "volumeOff_2.png");
	a_tm.addTexture("textBox", pathLogin + "textBox.png");
    a_tm.addTexture("textBoxCursor", pathLogin + "curseurTextBox.png");
	a_tm.addTexture("nemesis", pathLogin + "background_login.png");
	a_tm.addTexture("errorPanel", pathLogin + "ErrorPanel.png");
	a_tm.addTexture("selectCharacterPanel", pathLogin + "selectCharacterPanel.png");
    a_tm.addTexture("infoCharacterPanel", pathLogin + "infoCharacterPanel.png");
    a_tm.addTexture("playButton_1", pathLogin + "playButton_1.png");
    a_tm.addTexture("playButton_2", pathLogin + "playButton_2.png");
    a_tm.addTexture("refreshButton_1", pathLogin + "refreshButton_1.png");
    a_tm.addTexture("refreshButton_2", pathLogin + "refreshButton_2.png");
    a_tm.addTexture("createButton_1", pathLogin + "createButton_1.png");
    a_tm.addTexture("createButton_2", pathLogin + "createButton_2.png");
    a_tm.addTexture("rejoindreButton_1", pathLogin + "rejoindreButton_1.png");
    a_tm.addTexture("rejoindreButton_2", pathLogin + "rejoindreButton_2.png");
	a_tm.addTexture("bibouPanel", pathLogin + "bibouPanel.png");
	a_tm.addTexture("paperSwordTitlePanel", pathLogin + "paperSwordTitleFull.png");
	a_tm.addTexture("backButton_1", pathLogin + "backButton_1.png");
	a_tm.addTexture("backButton_2", pathLogin + "backButton_2.png");
	a_tm.addTexture("popup", pathLogin + "popUpCo.png");
	a_tm.addTexture("logoSmall", pathLogin + "paperSwordTitleSmall.png");

	a_tm.addTexture("perso0", pathChar +  "Numero_8.png");
	a_tm.addTexture("perso1", pathChar + "Remington.png");
	a_tm.addTexture("perso2", pathChar + "Tristan_De_La_Mortifere.png");
	a_tm.addTexture("perso3", pathChar +  "Eldora_Dragnir.png");

	//in game
	a_tm.addTexture("eldoraInGame",pathChar + "Eldora_Dragnir_inGame.png");
	a_tm.addTexture("mdj",pathChar + "Mdj.png");
	a_tm.addTexture("numero8InGame",pathChar + "Numero_8_inGame.PNG");
	a_tm.addTexture("remingtonInGame",pathChar + "Remington_inGame.PNG");
	a_tm.addTexture("tableInGame",pathChar + "Table_Jeu_inGame.png");
	a_tm.addTexture("tristanInGame",pathChar + "Tristan_De_La_Mortifere_inGame.png");
	a_tm.addTexture("mdjInGame",pathChar + "Mdj_inGame.PNG");

	a_mm.setState(true);
	a_tm.setState(true);
	a_tarm.setState(true);
	a_optm.setState(true);
	a_ntwm.setState(true);
    a_gm.setState(true);


	if(m_debug) {
		std::cout << "- Texture Manager successfully loaded" << std::endl;
		std::cout << "- Target Manager successfully loaded" << std::endl;
		std::cout << "- Option Manager successfully loaded" << std::endl;
		std::cout << "- Network Manager successfully loaded" << std::endl;
        std::cout << "- Game Manager successfully loaded" << std::endl;
	}
}

/*!
 * \brief Launch the loading thread
 */
void ResourceLoader::start() {
	m_thread.launch();
}

/*!
 * \brief Stop the loading thead
 * \deprecated Please do not use this function
 */
void ResourceLoader::stop() {
	m_thread.terminate();
}

/*!
 * \brief Check if the load is up
 * \return True if all resources are loaded
 */
bool ResourceLoader::getLoadState() {
	return (
			m_managerGroup.ptr_musicManager->getState() &&
			m_managerGroup.ptr_textureManager->getState() &&
			m_managerGroup.ptr_targetManager->getState() &&
			m_managerGroup.ptr_optionManager->getState() &&
			m_managerGroup.ptr_networkManager->getState() &&
            m_managerGroup.ptr_networkManager->getState());
}

/*!
 * \brief Return all loaded resources
 * \return m_manager a pointer on all managers
 */
ManagerGroup * ResourceLoader::getManager() {
	return &m_managerGroup;
}