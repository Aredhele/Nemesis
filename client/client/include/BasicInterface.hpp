/*!
 * \file BasicInterface.hpp
 * \brief Super class for interface
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#ifndef DEF_BASIC_INTERFACE_HPP
#define DEF_BASIC_INTERFACE_HPP

#include "AnimatableObject.hpp"
#include "InputHandler.hpp"
#include "ManagerGroup.hpp"
#include "Updatable.hpp"
#include "NButton.hpp"
#include "NPanel.hpp"
#include "NLabel.hpp"
#include "NTextField.hpp"

class BasicInterface : public Updatable
{
private:
	NPanel m_contentPane;
	NPanel m_topBar;
	NPanel m_optionPanel;
	NPanel m_optionPanel_2;
	NButton m_optButton;
	NButton m_exitButton;
	NButton m_musicButton;
	NButton m_soundButton;
	NLabel m_volumeLabel;
	NLabel m_soundLabel;
	NLabel m_titleLabel;
	NPanel m_smallTitleLogo;
	NLabel m_connectionErrorLabel;
	NPanel m_errorPanel;
	NPanel m_exitPanel;
	NLabel m_confirmExitLabel;
	NButton m_nonButton;
	NButton m_ouiButton;


	sf::Font m_fontLabel;


	std::vector < VisualObject * > m_interface;

	// Methods
	void updateInterface(double frameTime);

protected:
	bool m_debug;
	bool m_optionActive;
	bool m_exitActive;
	InputHandler m_inputHandler;
	ManagerGroup * m_ptr_managerGroup;

	void errorWarmUpFull();
	void errorConnection();
	void errorPseudo();
	void errorGoInGame();
	void errorCharacterSelection();
	void noError();
	void setBackground(sf::Texture* backgroundImg);

public:
	// Constructor
	BasicInterface(bool debug, ManagerGroup * ptr_managerGroup);

	// Destructor
	~BasicInterface();

	// Main Methods
	// Game logic
	void basicDraw(sf::RenderWindow * window);
	void basicInput(sf::Event * e, double frameTime);

	// Getters
	NPanel * getContentPane();
	NPanel * getTopBar();

	// Setters
	void setContentPane(NPanel * pane);
};

#endif // DEF_BASIC_INTERFACE_HPP