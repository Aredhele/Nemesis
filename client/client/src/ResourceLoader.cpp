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
	const std::string pathBackground = "../res/backgrounds/";
	const std::string pathAnimation = "../res/animation/";

	// Loading ...
	a_tm.addTexture("topBarLogMenu", pathLogin + "topBarLogMenu.png");
	a_tm.addTexture("topBarOptButton_1", pathLogin + "topBarOptionButton_1.png");
	a_tm.addTexture("topBarOptButton_2", pathLogin + "topBarOptionButton_2.png");

	a_tm.addTexture("topBarOptButton_3", pathLogin + "topBarOptionButton_1.png");
	a_tm.addTexture("topBarOptButton_4", pathLogin + "topBarOptionButton_2.png");
	a_tm.addTexture("exitPanel", pathLogin + "exitPanel.png");

	a_tm.addTexture("ouiButton_1", pathLogin + "OuiButton_1.png");
	a_tm.addTexture("ouiButton_2", pathLogin + "OuiButton_2.png");
	a_tm.addTexture("nonButton_1", pathLogin + "NonButton_1.png");
	a_tm.addTexture("nonButton_2", pathLogin + "NonButton_2.png");
	a_tm.addTexture("topBarExitButton_1", pathLogin + "topBarExitButton_1.png");
	a_tm.addTexture("topBarExitButton_2", pathLogin + "topBarExitButton_2.png");
	a_tm.addTexture("loginBackground", pathLogin + "background.png");
	a_tm.addTexture("optionPane", pathLogin + "optionPane.png");
	a_tm.addTexture("optionPanel", pathLogin + "optionPanel.png");
	a_tm.addTexture("altimitLoad", pathLogin + "altimitFull.png");
	a_tm.addTexture("simplePanel", pathLogin + "simplePanel.png");
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
	a_tm.addTexture("bibouPanel2", pathLogin + "bibouPanel_2.png");
	a_tm.addTexture("paperSwordTitlePanel", pathLogin + "paperSwordTitleFull.png");
	a_tm.addTexture("backButton_1", pathLogin + "backButton_1.png");
	a_tm.addTexture("backButton_2", pathLogin + "backButton_2.png");
	a_tm.addTexture("popup", pathLogin + "popUpCo.png");
	a_tm.addTexture("logoSmall", pathLogin + "paperSwordTitleSmall.png");
	a_tm.addTexture("arrowButton_1", pathLogin + "arrowButton_1.png");
	a_tm.addTexture("arrowButton_2", pathLogin + "arrowButton_2.png");
    a_tm.addTexture("arrowUp_1", pathLogin + "arrowUp_1.png");
    a_tm.addTexture("arrowUp_2", pathLogin + "arrowUp_2.png");
    a_tm.addTexture("arrowDown_1", pathLogin + "arrowDown_1.png");
    a_tm.addTexture("arrowDown_2", pathLogin + "arrowDown_2.png");

	//in warmUp
	a_tm.addTexture("numero8InWarmUp", pathChar +  "Numero_8_inWarmUp.png");
	a_tm.addTexture("remingtonInWarmUp", pathChar + "Remington_inWarmUp.png");
	a_tm.addTexture("tristanInWarmUp", pathChar + "Tristan_De_La_Mortifere_inWarmUp.png");
	a_tm.addTexture("eldoraInWarmUp", pathChar +  "Eldora_Dragnir_inWarmUp.png");
	a_tm.addTexture("mdjInWarmUp",pathChar + "Mdj_175.png");

	//in game
	a_tm.addTexture("eldoraInGame",pathChar + "Eldora_Dragnir_inGame.png");
	a_tm.addTexture("numero8InGame",pathChar + "Numero_8_inGame.PNG");
	a_tm.addTexture("remingtonInGame",pathChar + "Remington_inGame.PNG");
	a_tm.addTexture("tableInGame",pathChar + "Table_2.png");
	a_tm.addTexture("tristanInGame",pathChar + "Tristan_De_La_Mortifere_inGame.png");
	a_tm.addTexture("mdjInGame",pathChar + "Mdj_inGame.PNG");
	a_tm.addTexture("statPanel", pathLogin + "panel_200-50.png");
	a_tm.addTexture("charateristicsPanel", pathLogin + "panel_200-250.png");

	a_tm.addTexture("Crapaud",pathChar + "Crapaud.png");
	a_tm.addTexture("Dragon", pathChar + "Dragon.png");
	a_tm.addTexture("Yeti",pathChar + "Yeti.png");

	a_tm.addTexture("IconAttack", pathLogin + "attackIcon.png");
	a_tm.addTexture("IconDefense", pathLogin + "defenseIcon.png");
	a_tm.addTexture("IconHealth", pathLogin + "healthIcon.png");

	a_tm.addTexture("chatPanel", pathLogin + "chatPanel.png");
	a_tm.addTexture("chatTextBox", pathLogin + "chatTextBox.png");
	a_tm.addTexture("textBoxCursorChat", pathLogin + "curseurChatTextBox.png");
	a_tm.addTexture("loading", pathLogin + "loading.png");

	a_tm.addTexture("buttonHit", pathLogin + "buttonHit.png");
	a_tm.addTexture("buttonSummon", pathLogin + "buttonSummon.png");

	a_tm.addTexture("feu", pathLogin + "feu.png");
	a_tm.addTexture("ambianceButton_1", pathLogin + "ambianceButton_1.png");
	a_tm.addTexture("ambianceButton_2", pathLogin + "ambianceButton_2.png");
	a_tm.addTexture("beachButton_1", pathLogin + "beachButton_1.png");
	a_tm.addTexture("beachButton_2", pathLogin + "beachButton_1.png");
	a_tm.addTexture("castleButton_1", pathLogin + "castleButton_1.png");
	a_tm.addTexture("castleButton_2", pathLogin + "castleButton_2.png");
	a_tm.addTexture("crapaudButton_1", pathLogin + "crapaudButton_1.png");
	a_tm.addTexture("crapaudButton_2", pathLogin + "crapaudButton_2.png");
	a_tm.addTexture("forestButton_1", pathLogin + "forestButton_1.png");
	a_tm.addTexture("forestButton_2", pathLogin + "forestButton_2.png");
	a_tm.addTexture("landButton_1", pathLogin + "landButton_1.png");
	a_tm.addTexture("landButton_2", pathLogin + "landButton_2.png");
	a_tm.addTexture("monsterButton_1", pathLogin + "monsterButton_1.png");
	a_tm.addTexture("monsterButton_2", pathLogin + "monsterButton_2.png");
	a_tm.addTexture("roomButton_1", pathLogin + "roomButton_1.png");
	a_tm.addTexture("roomButton_2", pathLogin + "roomButton_2.png");
	a_tm.addTexture("yetiButton_1", pathLogin + "yetiButton_1.png");
	a_tm.addTexture("yetiButton_2", pathLogin + "yetiButton_2.png");
	a_tm.addTexture("dragonButton_1", pathLogin + "dragonButton_1.png");
	a_tm.addTexture("dragonButton_2", pathLogin + "dragonButton_2.png");

	//Backgrounds
	a_tm.addTexture("background_Castle_2",pathBackground + "Background_Castle_2.png");
	a_tm.addTexture("Background_Beach",pathBackground + "Background_Beach.png");
	a_tm.addTexture("background_Castle",pathBackground + "Background_Castle.png");
	a_tm.addTexture("Background_Forest",pathBackground + "Background_Forest.png");
	a_tm.addTexture("Background_Landscape",pathBackground + "Background_Landscape.png");
	a_tm.addTexture("Background_Room",pathBackground + "Background_Room.png");
	a_tm.addTexture("Background_Room_2",pathBackground + "Background_Room_2.png");


	//Animations
	a_tm.addTexture("flammes", pathAnimation + "animationFlamme.png");

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
			m_managerGroup.ptr_gameManager->getState() &&
            m_managerGroup.ptr_networkManager->getState());
}

/*!
 * \brief Return all loaded resources
 * \return m_manager a pointer on all managers
 */
ManagerGroup * ResourceLoader::getManager() {
	return &m_managerGroup;
}