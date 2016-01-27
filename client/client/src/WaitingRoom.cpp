/*!
 * \file LoginMenu.cpp
 * \brief Handle connection
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#include "WaitingRoom.hpp"


/*!
 * \brief Constructor
 */
WaitingRoom::WaitingRoom(bool debug, ManagerGroup * ptr_managerGroup) : 
BasicInterface(debug, ptr_managerGroup), 
m_button(), 
m_panel(),
m_label(), 
m_ao()
{
	TextureManager& a_tm = *m_ptr_managerGroup->ptr_textureManager;

	m_button.create("button1", 5, 20,
		a_tm.getTexture("topBarExitButton_1"), 
		a_tm.getTexture("topBarExitButton_2"));

	m_panel.create("panel1", 200,100, a_tm.getTexture("popUp"));

	m_ao.create("animation", 100, 200, a_tm.getTexture("altimitLoad"), true, 0.2, 30, 35, 7);

	m_panel.addComponent(&m_ao);
	getContentPane()->addComponent(&m_panel);
	getTopBar()->addComponent(&m_button);

	m_button.bind(m_ptr_managerGroup->ptr_networkManager);
	m_button.setActionId(1);
}

/*!
 * \brief Constructor
 */
WaitingRoom::~WaitingRoom() {
	// TODO
}

/*!
 * \brief Update current object
 * \param window The pointer on the window
 * \param frameTime The elpased time
 */
void WaitingRoom::update(sf::RenderWindow * window,
sf::Event * e, double frameTime) {

	if(!m_ptr_managerGroup->ptr_targetManager->isWaitingRoom())
		return;

	// Basic Interface updating
	basicInput(e, frameTime);

	m_inputHandler.handleInput(e, getContentPane());

	if (m_inputHandler.getComponentId() == "button1")
		std::cout << "CLIC" << std::endl;

	m_inputHandler.handleInput(e, getTopBar());
	std::cout << "ID COMPO ++++> " << m_inputHandler.getComponentId()  << std::endl;
		if (m_inputHandler.getComponentId() == "button1")
			std::cout << "CLIC" << std::endl;

	// Drawing all content
	basicDraw(window);
}
