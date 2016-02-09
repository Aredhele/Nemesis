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

	m_managerGroup.ptr_musicManager = new MusicManager(m_debug);
	m_managerGroup.ptr_textureManager = new TextureManager(m_debug);
	m_managerGroup.ptr_targetManager = new TargetManager(m_debug);
	m_managerGroup.ptr_optionManager = new OptionManager(m_debug);
	m_managerGroup.ptr_networkManager = new NetworkManager(m_debug);

	m_managerGroup.ptr_musicManager->setState(false);
	m_managerGroup.ptr_textureManager->setState(false);
	m_managerGroup.ptr_targetManager->setState(false);
	m_managerGroup.ptr_optionManager->setState(false);
    m_managerGroup.ptr_networkManager->setState(false);
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


	// Path
	const std::string pathLogin = "../res/texture/menu/login/";

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
	a_tm.addTexture("connectButton1", pathLogin + "connectButton_1.png");
	a_tm.addTexture("connectButton2", pathLogin + "connectButton_2.png");

	a_mm.setState(true);
	a_tm.setState(true);
	a_tarm.setState(true);
	a_optm.setState(true);
    a_ntwm.setState(true);


	if(m_debug) {
		std::cout << "- Texture Manager successfully loaded" << std::endl;
		std::cout << "- Target Manager successfully loaded" << std::endl;
		std::cout << "- Option Manager successfully loaded" << std::endl;
        std::cout << "- Network Manager successfully loaded" << std::endl;
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
    m_managerGroup.ptr_networkManager->getState());
}

/*!
 * \brief Return all loaded resources
 * \return m_manager a pointer on all managers
 */
ManagerGroup * ResourceLoader::getManager() {
	return &m_managerGroup;
}