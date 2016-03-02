/*!
 * \file BasicInterface.cpp
 * \brief Super class for interface
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#include "BasicInterface.hpp"

/*!
 * \brief Constructor
 * \param ptr_managerGroup
 */
BasicInterface::BasicInterface(bool debug,
							   ManagerGroup * ptr_managerGroup) : Updatable(),
																  m_contentPane(),
																  m_topBar(),
																  m_optionPanel(),
																  m_optButton(),
																  m_exitButton(),
																  m_musicButton(),
																  m_soundButton(),
																  m_volumeLabel(),
																  m_soundLabel(),
                                                                  m_titleLabel(),
																  m_inputHandler(debug)
{
	m_debug = debug;
	m_optionActive = false;
	m_ptr_managerGroup = ptr_managerGroup;

	// Setting up aliases
	TextureManager& a_tm = *m_ptr_managerGroup->ptr_textureManager;

	if (!m_fontLabel.loadFromFile("../res/font/Quicksand.ttf"))
	{
		std::cout << "Probleme dans le chargement des textures" << std::endl;
	}


	// Creating m_contentPane
	m_contentPane.create("mainPanel", 0, 0,
						 a_tm.getTexture("loginBackground"));

	// Adding top-bar
	m_topBar.create("topBar", 0, 0,
					a_tm.getTexture("topBarLogMenu"));

	// Adding buttons
	m_optButton.create("optButton", 805, 5,
					   a_tm.getTexture("topBarOptButton_1"),
					   a_tm.getTexture("topBarOptButton_2"));

	m_musicButton.create("volumeButton", 600,300,
						 a_tm.getTexture("volume_1"),
						 a_tm.getTexture("volume_2"));

	m_soundButton.create("soundButton", 600,436,
						 a_tm.getTexture("volume_1"),
						 a_tm.getTexture("volume_2"));


	m_exitButton.create("exitButton", 913, 5,
						a_tm.getTexture("topBarExitButton_1"),
						a_tm.getTexture("topBarExitButton_2"));

	//Adding labels
	m_volumeLabel.create("volumeLabel", 370, 314, 20, &m_fontLabel,
						 L"Volume de la musique",
						 sf::Color::White);

	m_soundLabel.create("soundLabel", 370, 450, 20, &m_fontLabel,
						 L"Volume des effets",
						 sf::Color::White);

	m_titleLabel.create("monSuperLabel", 10, 10, 20, &m_fontLabel,
						L"Paper Sword : Online",
						sf::Color(232,200,20));

	// Creating optionPanel
	m_optionPanel.create("optionPanel", 0, 50,
						 a_tm.getTexture("optionPane"));


    getContentPane()->addComponent(&m_titleLabel);
	m_optionPanel.addComponent(&m_volumeLabel);
	m_optionPanel.addComponent(&m_soundLabel);
	m_optionPanel.addComponent(&m_musicButton);
	m_optionPanel.addComponent(&m_soundButton);

	m_topBar.addComponent(&m_optButton);
	m_topBar.addComponent(&m_exitButton);

	m_interface.push_back(&m_contentPane);
	m_interface.push_back(&m_topBar);
}

/*!
 * \brief Destructor
 */
BasicInterface::~BasicInterface() {
	// None
}

/*!
 * \brief Draw all object on the window
 * \param window The surface to draw
 * \param visualObjectList The list of object to draw
 */
void BasicInterface::basicDraw(sf::RenderWindow * window) {

	// Polymorphisme !
	for(unsigned int i = 0; i < m_interface.size(); i++)
		m_interface[i]->draw(window);
}

/*!
 * \brief Update all component
 * \param frameTime Time elapsed since last frame
 */
void BasicInterface::updateInterface(double frameTime) {

	// Polymorphisme !
	for(unsigned int i = 0; i < m_interface.size(); i++)
		m_interface[i]->update(frameTime);
}

/*!
 * \brief Handle inputs of the basics interface
 * \param e The current event to handle
 * \param frameTime TimeElapsed since last iteration
 */
void BasicInterface::basicInput(sf::Event * e, double frameTime) {

	// Updating components
	updateInterface(frameTime);

	// Check for interface event
	// Check for contentPane event
	// m_inputHandler.handleInput(e, &m_contentPane);

	// Check for topBar event
	m_inputHandler.handleInput(e, &m_topBar, false);

	if(m_inputHandler.getComponentId() != "NULL") {

		// Exiting game !
		if(m_inputHandler.getComponentId() == "exitButton") {
			m_ptr_managerGroup->ptr_targetManager->exit();
		}
			// Option menu
		else if(m_inputHandler.getComponentId() == "optButton") {
			if(!m_optionActive)
			{
				m_optionActive = true;
				m_interface.push_back(&m_optionPanel);
			}
			else
			{
				m_optionActive = false;
				m_interface.pop_back();
			}
		}
	}

	// Check for optionPane event
	if(m_optionActive) {
		m_inputHandler.handleInput(e, &m_optionPanel, false);

		if(m_inputHandler.getComponentId() != "NULL") {
			if(m_inputHandler.getComponentId() == "volumeButton")
			{
				TextureManager& a_tm = *m_ptr_managerGroup->ptr_textureManager;

				if(m_ptr_managerGroup->ptr_musicManager->getMusicVolume()>0)
				{
					m_ptr_managerGroup->ptr_musicManager->setMusicVolume(0);
					m_musicButton.setSprite(a_tm.getTexture("volumeOff_1"),
											a_tm.getTexture("volumeOff_2"));

					std::cout << "Music volume : On" << std::endl;
				}
				else
				{
					m_ptr_managerGroup->ptr_musicManager->setMusicVolume(50);
					m_musicButton.setSprite(a_tm.getTexture("volume_1"),
											a_tm.getTexture("volume_2"));

					std::cout << "Music volume : Off" << std::endl;
				}


			}
			else if(m_inputHandler.getComponentId() == "soundButton"){

				TextureManager& a_tm = *m_ptr_managerGroup->ptr_textureManager;


				if(m_ptr_managerGroup->ptr_musicManager->getSoundVolume()>0)
				{
					m_ptr_managerGroup->ptr_musicManager->setSoundVolume(0);
					m_soundButton.setSprite(a_tm.getTexture("volumeOff_1"),
											a_tm.getTexture("volumeOff_2"));

					std::cout << "Sound volume : On" << std::endl;
				}
				else
				{
					m_ptr_managerGroup->ptr_musicManager->setSoundVolume(50);
					m_soundButton.setSprite(a_tm.getTexture("volume_1"),
											a_tm.getTexture("volume_2"));

					std::cout << "Sound volume : Off" << std::endl;
				}

			}
		}
	}

	//Check for contentPane Event
	m_inputHandler.handleInput(e, &m_contentPane, true);
}

/*!
 * \brief Allow the acces on the main panel
 * \return m_contentPane The reference on the main panel
 */
NPanel * BasicInterface::getContentPane() {
	return &m_contentPane;
}

/*!
 * \brief Allow the acces on the top bar
 * \return m_topBar The reference on the top bar
 */
NPanel * BasicInterface::getTopBar() {
	return &m_topBar;
}

/*!
 * \brief Replace the current main panel
 * \param pane The pointeur on the panel
 * \return None
 */
void BasicInterface::setContentPane(NPanel * pane) {
	m_contentPane = *pane;
}