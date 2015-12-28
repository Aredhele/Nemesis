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
	m_managerGroup.ptr_musicManager = new MusicManager(m_debug, false);
	m_managerGroup.ptr_textureManager = new TextureManager(m_debug);
	m_managerGroup.ptr_musicManager->setState(false);
	m_managerGroup.ptr_textureManager->setState(false);
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

	// Loading ...
	m_managerGroup.ptr_textureManager->addTexture("topBarLogMenu", 
	"../res/texture/menu/login/topBarLogMenu.png");

	m_managerGroup.ptr_musicManager->setState(true);
	m_managerGroup.ptr_textureManager->setState(true);

	if(m_debug) {
		std::cout << "- Music Manager successfully loaded" << std::endl;
		std::cout << "- Texture Manager successfully loaded" << std::endl;
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
	m_managerGroup.ptr_textureManager->getState());
}

/*!
 * \brief Return all loaded resources
 * \return m_manager a pointer on all managers
 */
ManagerGroup * ResourceLoader::getManager() {
	return &m_managerGroup;
}