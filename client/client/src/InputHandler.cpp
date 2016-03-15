/*!
 * \file InputHandler.hpp
 * \brief Handle input
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-28
 */

#include "InputHandler.hpp"

/*!
 * \brief Constructor
 * \param debug The debug mode
 */
InputHandler::InputHandler(bool debug) {
	m_debug = false;
	m_mouseLock = true;
	m_textEntered = true;
	testBug = 2;
}

/*!
 * \brief Destructor
 */
InputHandler::~InputHandler() {
	// None
}

/*!
 * \brief Handle inputs
 * \param e The pointer on the event
 * \param objectList Vector of component
 */
void InputHandler::handleInput(sf::Event * e,
							   VisualObject * o, bool mouselock) {

	// Enable or disable mouse blocking
	m_mouseLock = mouselock;

	switch(e->type)
	{
		case sf::Event::MouseButtonPressed:
			mousePressedHandle(e, o);
			break;

		case sf::Event::MouseButtonReleased:
			mouseReleasedHandle(e);
			break;

		case sf::Event::MouseMoved:
			mouseMovedHandle(e, o);
			break;

		case sf::Event::TextEntered:
			if(e->text.unicode == 0){
				break;
			}
			if(testBug >= 0 || testBug <= -30){
				testBug --;
				textEnteredHandle(e, o);
			}
			else {
				testBug--;
			}
                break;

            case sf::Event::KeyReleased:
				testBug = 2;
                break;

		default:
			m_overId = "NULL";
			m_keyCode = -1;
			m_pressedId = "NULL";
			break;
	}
}

/*!
 * \brief Handle mouse pressed event
 * \param e The current event to handle
 * \param objectList Vector of component
 */
void InputHandler::mousePressedHandle(sf::Event * e,
									  VisualObject * o) {

	switch(e->mouseButton.button)
	{
		case sf::Mouse::Left:
			mouseLeftHandle(e, o);
			break;

		case sf::Mouse::Right:
			// None
			break;

		default:
			// None
			break;
	}
}

/*!
 * \brief Handle mouse released event
 * \param e The current event to handle
 */
void InputHandler::mouseReleasedHandle(sf::Event * e) {

	if (e->mouseButton.button == sf::Mouse::Left) {
		m_mouseState = false;
	}
}

/*!
 * \brief Handle mouse left event
 * \param e The current event to handle
 * \param objectList Vector of component
 */
void InputHandler::mouseLeftHandle(sf::Event * e,
								   VisualObject * o) {

	m_overId = "NULL";
	m_keyCode = -1;

	m_pressedId = "NULL";

	if(!m_mouseState) {

		if(m_mouseLock) m_mouseState = true;

		m_pressedId = o->eventMousePressed(e);

		if(m_debug) {
			std::cout << "- Event ID : mousePressed" << std::endl;
			std::cout << "- Compo ID : " << m_pressedId << std::endl;
			std::cout << "- Mouse x  : " << e->mouseButton.x << std::endl;
			std::cout << "- Mouse y  : " << e->mouseButton.y << std::endl;
		}
	}
}

/*!
 * \brief Handle mouse moved event
 * \param e The current event to handle
 * \param objectList Vector of component
 */
void InputHandler::mouseMovedHandle(sf::Event * e,
									VisualObject * o) {

	m_pressedId = "NULL";
	m_keyCode = -1;

	m_overId = "NULL";
	m_overId = o->eventMouseMoved(e);

	if(m_overId != "NULL" && false) { // TMP
		std::cout << "- Event ID : mouseMoved" << std::endl;
		std::cout << "- Compo ID : " << m_overId << std::endl;
		std::cout << "- Mouse x  : " << e->mouseMove.x << std::endl;
		std::cout << "- Mouse y  : " << e->mouseMove.y << std::endl;
	}
}

/*!
 * \brief Handle mouse textEntered event
 * \param e The current event to handle
 * \param objectList Vector of component
 */
void InputHandler::textEnteredHandle(sf::Event * e,
									 VisualObject * o) {

	m_overId = "NULL";
	m_pressedId = "NULL";

	m_keyCode = e->text.unicode;

	o->eventTextEntered(e);

	if(m_debug) {
		std::cout << "- Event ID : textEntered" << std::endl;
		std::cout << "- Key code : " << m_keyCode << std::endl;
	}
	//sf::sleep(sf::milliseconds(50));
}

/*!
 * \brief return the last id associated with the last pressed event
 * \return m_componentId The id of the component
 */
std::string InputHandler::getComponentId() {
	return m_pressedId;
}

/*!
 * \brief return the last id associated with the last over event
 * \return m_overId The id of the component
 */
std::string InputHandler::getOverId() {
	return m_overId;
}

/*!
 * \brief return the last keyCode
 * \return m_keyCode The key code
 */
int InputHandler::getKeyCode() {
	return m_keyCode;
}