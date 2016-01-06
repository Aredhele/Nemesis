/*!
 * \file Manager.hpp
 * \brief Super class of managers
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-25
 */

#ifndef DEF_MANAGER_HPP
#define DEF_MANAGER_HPP

class Manager
{
	protected:
		bool m_state;
		bool m_debug;

	public:
		// Constructor
		Manager();

		// Destructor
		~Manager();

		// Getter
		bool getState();

        // Setter
        void setState(bool state);
};

#endif // DEF_MANAGER_HPP