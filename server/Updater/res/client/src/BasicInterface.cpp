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
m_inputHandler(debug)
{
	m_debug = debug;
	m_optionActive = false;
	m_ptr_managerGroup = ptr_managerGroup;

	// Setting up aliases
	TextureManager& a_tm = *m_ptr_managerGroup->ptr_textureManager;

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

	m_exitButton.create("exitButton", 913, 5,
	a_tm.getTexture("topBarExitButton_1"), 
	a_tm.getTexture("topBarExitButton_2"));

	// Creating optionPanel
	m_optionPanel.create("optionPanel", 0, 50,
	a_tm.getTexture("optionPane"));

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
	m_inputHandler.handleInput(e, &m_topBar);

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
		m_inputHandler.handleInput(e, &m_optionPanel);

		if(m_inputHandler.getComponentId() != "NULL") {
			// TODO
		}
	}
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