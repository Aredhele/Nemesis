/*!
 * \file InputHandler.hpp
 * \brief Handle input
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-28
 */

#ifndef DEF_INPUT_HANDLER_HPP
#define DEF_INPUT_HANDLER_HPP

#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "VisualObject.hpp"

class InputHandler
{
private:
	bool m_textEntered;
	bool m_debug;
	bool m_mouseState;
	bool m_mouseLock;

	std::string m_pressedId;
	std::string m_overId;
	int m_keyCode;
	int oldKeyCode;
	int testBug;

	// Game logic
	void mouseReleasedHandle(sf::Event * e);
	void mousePressedHandle(sf::Event * e, VisualObject * o);
	void mouseLeftHandle(sf::Event * e, VisualObject * o);
	void mouseMovedHandle(sf::Event * e, VisualObject * o);
	void textEnteredHandle(sf::Event * e, VisualObject * o);

public:
	// Constructor
	InputHandler(bool debug);

	// Destructor
	~InputHandler();

	// Methods
	void handleInput(sf::Event * e, VisualObject * o,
					 bool mouselock);

	// Getters
	std::string getComponentId();
	std::string getOverId();
	int getKeyCode();
};

#endif // DEF_INPUT_HANDLER_HPP